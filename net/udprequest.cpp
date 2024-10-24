#include "udprequest.h"

UdpRequest::UdpRequest(QString method, QJsonDocument  json){
    this->body = method + "%" + json.toJson();
}

QString UdpRequest::getBody(){
    return this->body;
}
