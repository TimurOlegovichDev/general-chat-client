#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QUdpSocket>
#include <QDebug>
#include "udpservice.h"
#include "serverproperties.h"
#include "udprequest.h"
#include <udpresponse.h>

class UdpSendService : public QObject {

        Q_OBJECT

    public:
        UdpSendService();
        bool send(UdpRequest* req);

    signals:
        void receivedServerResponse(UdpResponse response);

    private:
        void listen();
        QUdpSocket* udpSocket = new QUdpSocket();
};

#endif // UDPSENDER_H
