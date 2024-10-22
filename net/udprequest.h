#ifndef UDPREQUEST_H
#define UDPREQUEST_H

#include <QString>

class UdpRequest{
    public:
        UdpRequest(QString json);
        QString getJsonString();

    private:
        QString json;
};

#endif // UDPREQUEST_H
