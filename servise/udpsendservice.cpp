#include "udpsendservice.h"

#include <serverproperties.h>

UdpSendService::UdpSendService(){

}

bool UdpSendService::send(UdpRequest* req){
    int byteSended = udpSocket->writeDatagram(
                req->getJsonString().toUtf8(),
                ServerProperties::IP_ADDRESS,
                ServerProperties::PORT
    );
    return byteSended == req->getJsonString().toUtf8().size();
}
