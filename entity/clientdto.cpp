#include "clientdto.h"

ClientDto::ClientDto(const QString& username, const QByteArray& password) :
    username(username),
    password(password)
{}

QString ClientDto::getUserName(){
    return this->username;
}

QByteArray ClientDto::getPassword(){
    return this->password;
}

QJsonDocument ClientDto::toJson() const{
    QJsonObject json;
    json["username"] = username;
    json["password"] = QString::fromUtf8(password);
    return QJsonDocument(json);
}


