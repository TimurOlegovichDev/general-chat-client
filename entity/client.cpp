#include "client.h"

Client::Client(const QString& username, const QByteArray& password) :
    username(username),
    password(password)
{}

QString Client::getUserName(){
    return this->username;
}

QByteArray Client::getPassword(){
    return this->password;
}

QJsonDocument Client::toJson() const{
    QJsonObject json;
    json["username"] = username;
    json["password"] = QString::fromUtf8(password);
    return QJsonDocument(json);
}


