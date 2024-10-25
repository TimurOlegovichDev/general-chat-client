#ifndef UDPSERVICE_H
#define UDPSERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QRandomGenerator>
#include <udprequest.h>

class UdpService : public QObject {
    Q_OBJECT

public:
    UdpService() : QObject() {
        udpSocket = new QUdpSocket(this);
    }

protected:
    QUdpSocket *udpSocket;
};

#endif // UDPSERVICE_H
