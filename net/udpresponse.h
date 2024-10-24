#ifndef UDPRESPONSE_H
#define UDPRESPONSE_H

#include <QString>
#include <QJsonDocument>

enum class UdpResponseCode {
    OK = 200,
    BAD = 400,
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
