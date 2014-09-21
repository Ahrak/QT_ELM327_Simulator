#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(new QSerialPort())
{
    ui->setupUi(this);
    updateSerialPorts();

    ui->btnSerialDisconnect->setEnabled(false);
    connect(ui->btnSerialConnect, SIGNAL(pressed()), this, SLOT(connectPort()));
    connect(ui->btnSerialDisconnect, SIGNAL(pressed()), this, SLOT(disconnectPort()));
    connect(ui->btnUDP, SIGNAL(pressed()), this, SLOT(connectUDP()));
    connect(ui->editCmd, SIGNAL(returnPressed()), this, SLOT(execCmd()));
    connect(&uiTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    uiTimer.setInterval(200);
    uiTimer.start();

    //
    connect(ui->actionClearConsole, SIGNAL(triggered()), this, SLOT(clearConsole()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI()
{
    OutGaugePacket packet = m_receiver.packet;
    ui->displaySpeed->setText(QString::number(packet.Speed * 3.6f, 'f', 2));
    ui->displayRPM->setText(QString::number(int(packet.RPM )));
    ui->displayTemp->setText(QString::number(int(packet.EngTemp)) + "°C");
    ui->displayThrottle->setText(QString::number(int(packet.Throttle * 100 )) + "%");
}

void MainWindow::clearConsole()
{
    ui->terminal->clear();
}

void MainWindow::execCmd()
{
    QString cmd = ui->editCmd->text();
    cmd = cmd.replace(" ", "");
    ui->editCmd->clear();
    if(cmd.startsWith("AT")) processATCommand(cmd);
}

void MainWindow::connectPort()
{
    QItemSelectionModel* select = ui->portWidget->selectionModel();
    if(!select->hasSelection()) return;

    int idx = select->selectedRows(0)[0].row();
    QString portName = ui->portWidget->item(idx,0)->text();
    m_port = new QSerialPort(portName, this);
    m_port->open(QIODevice::ReadWrite);
    m_port->setBaudRate(9600);
    m_port->setReadBufferSize(1024);

    if(m_port->isOpen())
    {
        ui->btnSerialDisconnect->setEnabled(true);
        ui->btnSerialConnect->setEnabled(false);
        connect(m_port, SIGNAL(readyRead()), this, SLOT(readMessageFromPort()), Qt::DirectConnection);
        ui->terminal->append("!! CONNECTED " + m_port->portName());
    }
    updateSerialPorts();
}

void MainWindow::disconnectPort()
{
    if(m_port != NULL)
    {
        if(m_port->isOpen())
        {
            m_port->flush();
            m_port->clear();
            m_port->close();
            ui->terminal->append("!! DISCONNECTED " + m_port->portName());
            m_port->setPortName("");
        }
    }
    ui->btnSerialDisconnect->setEnabled(false);
    ui->btnSerialConnect->setEnabled(true);
    updateSerialPorts();
}

void MainWindow::connectUDP()
{
    if(!m_receiver.connected)
    {
        m_receiver.connect(ui->editUDP_IP->text(), ui->editUDP_Port->text());
        ui->btnUDP->setText("Disconnect");
    }
    else
    {
        m_receiver.disconnect();
        ui->btnUDP->setText("Connect");
    }
}

void MainWindow::updateSerialPorts()
{
    ui->portWidget->clear();
    ui->portWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->portWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Beschreibung"));
    ui->portWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Hersteller"));
    ui->portWidget->setRowCount(QSerialPortInfo::availablePorts().size());
    ui->portWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->portWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->portWidget->setSelectionMode(QAbstractItemView::SingleSelection);


    int i = 0;
    int selection = 0;
    //qDebug() << "\nSERIAL PORTS:";
    //qDebug() << "-------------------------------";
    foreach (const QSerialPortInfo& info, QSerialPortInfo::availablePorts())
    {
        //qDebug() << "Name           :" << info.portName();
        //qDebug() << "Descr.         :" << info.description();
        //qDebug() << "Manufactor     :" << info.manufacturer();
        //qDebug() << "\n";
        ui->portWidget->setItem(i, 0, new QTableWidgetItem(info.portName()));
        ui->portWidget->setItem(i, 1, new QTableWidgetItem(info.description()));
        ui->portWidget->setItem(i, 2, new QTableWidgetItem(info.manufacturer()));

        if(info.portName() == m_port->portName())
        {
            selection = i;
            ui->portWidget->item(i,0)->setTextColor(Qt::white);
            ui->portWidget->item(i,1)->setTextColor(Qt::white);
            ui->portWidget->item(i,2)->setTextColor(Qt::white);
            ui->portWidget->item(i,0)->setBackgroundColor(Qt::gray);
            ui->portWidget->item(i,1)->setBackgroundColor(Qt::gray);
            ui->portWidget->item(i,2)->setBackgroundColor(Qt::gray);
        }
        ++i;
    }
    ui->portWidget->selectRow(selection);
}

void MainWindow::readMessageFromPort()
{

    //while (!m_port->atEnd())
    {
       QByteArray data = m_port->read(100);
       QString inMsg(data);
       inMsg = inMsg.toUpper().replace("\r", "");
       if(inMsg.isEmpty()) return;
       //qDebug() << "IN:" << inMsg;
       //
       if(inMsg.startsWith("AT")) processATCommand(inMsg);
       else if(inMsg.startsWith("01")) valueResponse(inMsg);
    }
}

void MainWindow::writeMessage(const QString &msg)
{
    QByteArray out;
    out.append(msg);
    out.append("\r\n>");
    m_port->write(out);
    //qDebug() << "OUT:" << msg;
}

void MainWindow::processATCommand(const QString &in)
{
    QString cmd = in;
    cmd = cmd.replace(0,2, "");
    ui->terminal->append("> AT " + cmd);
    QString response = "?";

    if(cmd == "Z") response = "ELM327 v1.5";
    else if(cmd == "@1")  response = "OK";
    else if(cmd == "@2")  response = "?";
    else if(cmd == "E0")  response = "OK";
    else if(cmd == "E1")  response = "OK";
    else if(cmd == "H0")  response = "OK";
    else if(cmd == "H1")  response = "OK";
    else if(cmd == "L0")  response = "OK";
    else if(cmd == "L1")  response = "OK";
    else if(cmd == "SP0") response = "AUTO";
    else if(cmd == "DP")  response = "AUTO";
    else if(cmd == "I")  response = "ELM327 v1.5";
    else
    {
        qDebug() << "Unknown Command: " << cmd;
    }
    ui->terminal->append(response);
    writeMessage(response);

}

void MainWindow::valueResponse(const QString &cmd)
{
    OutGaugePacket data = m_receiver.packet;
    QString response = "4" + cmd.mid(1,3);
    //
    QString pid = cmd.mid(2,2);
    if(false) ;
    else if(pid == "")   response.append("0000");
    // ?                                                  1   C  1   F   8   0   0   0
    else if(pid == "00" || pid == "0")  response.append("00011110000111111000000000000000");    // PIDs supported [01 - 20]
    else if(pid == "03") response.append("0000000000000001");                                   // Fuel system status
    else if(pid == "04") response.append(QString::number(int(75 * 2.55f), 16));                 // engine load
    else if(pid == "05") response.append(QString::number(int(data.EngTemp + 40), 16));          // engine cooler temp
    else if(pid == "06") response.append(QString::number(int(132 * 2.55f), 16));                // Short term fuel %
    else if(pid == "07") response.append(QString::number(int(132 * 2.55f), 16));                // long term fuel %
    else if(pid == "0B") response.append(QString::number(int(128), 16));                        // Intake manifold absolute pressure (kpA)
    else if(pid == "0C") response.append(QString::number(int(data.RPM * 4), 16));               // rpm
    else if(pid == "0D") response.append(QString::number(int(data.Speed * 3.6f), 16));          // speed
    else if(pid == "0E") response.append(QString::number(int(128), 16));                        // Timing advance [-64;64] --> (A-128)/2
    else if(pid == "0F") response.append(QString::number(int(28 + 40), 16));                    // Intake air temperature
    else if(pid == "10") response.append(QString::number(int(2048), 16));                       // MAF air flow rate
    else if(pid == "11") response.append(QString::number(int(data.Throttle * 100 * 2.55f), 16));// throttle pos
    else if(pid == "2F") response.append(QString::number(int(data.Fuel * 100 * 2.55f), 16));    // fuel level %
    else if(pid == "45") response.append(QString::number(int(data.Throttle * 100 * 2.55f), 16));// throttle pos
    else
    {
        qDebug() << "Unknown PID: " << pid;
        response.append("0000");
        writeMessage("NODATA");
        return;
    };
    while(response.length() < 12) response += "0";
    writeMessage(response);

    qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << response;

}
