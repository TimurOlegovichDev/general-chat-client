#include "udprequest.h"

UdpRequest::UdpRequest(QString json){
    this->json = json;
}

QString UdpRequest::getJsonString(){
    return this->json;
}
