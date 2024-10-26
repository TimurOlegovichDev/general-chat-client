#include "udpsendservice.h"
#include <QNetworkDatagram>

UdpSendService::UdpSendService() : QObject(){
    QObject::connect(udpSocket, &QUdpSocket::readyRead, this, &UdpSendService::listen);
}

bool UdpSendService::send(UdpRequest* req) {
    int byteSended = udpSocket->writeDatagram(
                req->getBody().toUtf8(),
                ServerProperties::IP_ADDRESS,
                ServerProperties::PORT
    );
    return byteSended == req->getBody().toUtf8().size();
}

int UdpSendService::getLocalPort(){
    return this->udpSocket->localPort();
}


void UdpSendService::listen() {
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        if (datagram.senderPort() != ServerProperties::PORT) {
            qDebug() << "Сообщение не от сервера " + QString::number(datagram.senderPort());
            continue;
        }
        emit receivedServerResponse(
            UdpResponse::fromJson(QString::fromUtf8(datagram.data()))
        );
    }
}
