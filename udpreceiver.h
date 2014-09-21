#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QDataStream>
#include <QTime>

#include "OutGauge.h"

class UDPReceiver : public QObject
{
    Q_OBJECT

public:
    UDPReceiver(QObject* parent = 0);


    OutGaugePacket packet;

    bool connected;

private:

    QUdpSocket* m_pSocket;

private slots:

    void readPendingDatagrams();

public slots:    void connect(QString ip, QString port);

    void disconnect();

private:

    void processData(const QByteArray& data);

};

#endif // UDPRECEIVER_H
