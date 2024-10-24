#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QUdpSocket>
#include <QDebug>
#include "udpservice.h"
#include "serverproperties.h"
#include "udprequest.h"
#include <udpresponse.h>

class UdpSendService : public UdpService {
        Q_OBJECT

    public:
        UdpSendService();
        bool send(UdpRequest* req);

    signals:
        void receivedServerResponse(UdpResponse response);

    private:
        QUdpSocket* udpSocket;
        void listen();
};

#endif // UDPSENDER_H
