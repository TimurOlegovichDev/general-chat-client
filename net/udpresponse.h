#ifndef UDPRESPONSE_H
#define UDPRESPONSE_H

#include <QString>
#include <QJsonDocument>

enum class UdpResponseCode {

    HAS_MESSAGE = 1,
    OK = 200,
    BAD = 400,
    CLOSE_CONNECTION = 450,
    INTERNAL_SERVER_ERROR = 500
};

class UdpResponse {
public:
    UdpResponse(UdpResponseCode code, const QString &body);

    static UdpResponse fromJson(const QString &jsonString);

    UdpResponseCode getCode();

    QString getBody();

    QString toString() const;

private:
    UdpResponseCode code;
    QString body;
};

#endif // UDPRESPONSE_H
