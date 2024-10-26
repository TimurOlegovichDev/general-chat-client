#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QUdpSocket>
#include <QDebug>
#include "serverproperties.h"
#include "udprequest.h"
#include <udpresponse.h>

class UdpSendService : public QObject {

        Q_OBJECT

    public:
        UdpSendService();
        bool send(UdpRequest* req);
        int getLocalPort();

    signals:
        void receivedServerResponse(UdpResponse response);

    private:
        void listen();
        QUdpSocket* udpSocket = new QUdpSocket();
};

#endif // UDPSENDER_H
