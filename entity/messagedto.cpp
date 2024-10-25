#include "messagedto.h"

MessageDto::MessageDto(){

}

int MessageDto::getSenderPort() const{
    return senderPort;
}

const QString& MessageDto::getSenderName() const{
    return senderName;
}

const QString& MessageDto::getText() const{
    return text;
}

const QString& MessageDto::getTime() const{
    return time;
}
