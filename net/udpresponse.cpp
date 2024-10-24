#include <udpresponse.h>
#include <QJsonObject>
#include <stdexcept>

UdpResponse::UdpResponse(UdpResponseCode code, const QString &body)
    : code(code), body(body) {}

UdpResponse UdpResponse::fromJson(const QString &jsonString) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (!doc.isObject()) {
        throw std::runtime_error("Invalid JSON format");
    }

    QJsonObject jsonObj = doc.object();
    UdpResponseCode code = static_cast<UdpResponseCode>(jsonObj["code"].toInt());
    QString body = jsonObj["body"].toString();

    return UdpResponse(code, body);
}

UdpResponseCode UdpResponse::getCode(){
    return this->code;
}

QString UdpResponse::getBody(){
    return this->body;
}

QString UdpResponse::toString() const {
    return QString("UdpResponse{ code=%1, body='%2' }")
        .arg(static_cast<int>(code))
        .arg(body);
}
