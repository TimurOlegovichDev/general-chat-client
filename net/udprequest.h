#ifndef UDPREQUEST_H
#define UDPREQUEST_H

#include <QString>
#include <UdpMethod.h>
#include <QJsonDocument>

class UdpRequest{
    public:
        UdpRequest(QString method,
                   QJsonDocument json);

        QString getBody();

    private:
        QString body;
};

#endif // UDPREQUEST_H
