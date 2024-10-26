#include "messagedto.h"
#include <QJsonDocument>
#include <QJsonObject>

MessageDto::MessageDto(QString text, QString senderName){
    this->text = text;
    this->senderName = senderName;
}

MessageDto::MessageDto(){}

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

MessageDto MessageDto::fromJson(QJsonObject& json){
    MessageDto message;

    if (json.contains("senderName") && json["senderName"].isString()) {
        message.senderName = json["senderName"].toString();
    }

    if (json.contains("text") && json["text"].isString()) {
        message.text = json["text"].toString();
    }

    return message;
}

bool MessageDto::isValid() const{
    return !senderName.isEmpty() && !text.isEmpty();
}

QJsonDocument MessageDto::toJson() const {
    QJsonObject json;
    json["text"] = text;
    json["senderName"] = senderName;
    return QJsonDocument(json);
}

