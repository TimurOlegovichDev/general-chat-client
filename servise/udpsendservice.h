#ifndef UDPSENDSERVICE_H
#define UDPSENDSERVICE_H

#include "udpservice.h"


class UdpSendService : UdpService{
    public:
        UdpSendService();

        bool send(UdpRequest* req);
};

#endif // UDPSENDSERVICE_H
