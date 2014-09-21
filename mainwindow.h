#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>

#include "udpreceiver.h"
#include "OutGauge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort* m_port;

    UDPReceiver m_receiver;
    QTimer uiTimer;

private slots:

    void execCmd();

    void connectPort();

    void disconnectPort();

    void connectUDP();

    void updateSerialPorts();

    void readMessageFromPort();

    void writeMessage(const QString& msg);

    void processATCommand(const QString& cmd);

    void valueResponse(const QString& cmd);

    void updateUI();

    void clearConsole();
};

#endif // MAINWINDOW_H
