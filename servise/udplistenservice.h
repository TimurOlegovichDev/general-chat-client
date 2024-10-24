#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include "udpservice.h"
#include "serverproperties.h"
#include <udpresponse.h>

class UdpListenService : public UdpService {
        Q_OBJECT

    public:
        UdpListenService();

    signals:
        void receivedServerResponse(UdpResponse response);

        private slots:
            void listen();
};

#endif // UDPLISTENER_H
