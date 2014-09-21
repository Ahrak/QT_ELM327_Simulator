#include "udpreceiver.h"


UDPReceiver::UDPReceiver(QObject *parent) : QObject(parent)
  , m_pSocket(new QUdpSocket(this))
{
    //
    connected = false;
}

void UDPReceiver::readPendingDatagrams()
{
    while (m_pSocket->hasPendingDatagrams())
    {
            QByteArray datagram;
            datagram.resize(m_pSocket->pendingDatagramSize());
            QHostAddress sender;
            quint16 senderPort;
            m_pSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
            processData(datagram);
    }
}

void UDPReceiver::connect(QString ip, QString port)
{
    m_pSocket->bind(QHostAddress(ip), port.toInt());
    QObject::connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    connected = true;
}

void UDPReceiver::disconnect()
{
    m_pSocket->close();
    //QObject::disconnect(m_pSocket);
    connected = false;
}

void UDPReceiver::processData(const QByteArray &data)
{
    QDataStream stream(data);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream.setFloatingPointPrecision(QDataStream::SinglePrecision);

    stream >> packet.Time;
    QByteArray buffer(4, Qt::Uninitialized);
    stream.readRawData(buffer.data(), buffer.length());
    strcpy(packet.Car, buffer.constData());
    stream >> packet.Flags;
    stream >> packet.Gear;
    stream >> packet.PLID;
    stream >> packet.Speed;
    stream >> packet.RPM;
    stream >> packet.Turbo;
    stream >> packet.EngTemp;
    stream >> packet.Fuel;
    stream >> packet.OilPressure;
    stream >> packet.OilTemp;
    stream >> packet.DashLights;
    stream >> packet.ShowLights;
    stream >> packet.Throttle;

    /*
    qDebug() << QTime(0,0,0).addMSecs(packet.Time).toString("hh:mm:ss.zzz");
    qDebug() << QString::number(packet.Flags, 2);
    qDebug() << QString::number(packet.Gear-1);
    qDebug() << float(packet.Speed * 3.6f);
    qDebug() << float(packet.RPM);
    qDebug() << "---";
    */


}
