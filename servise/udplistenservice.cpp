#include "udplistenservice.h"

UdpListenService::UdpListenService() : UdpService() {
    udpSocket = new QUdpSocket();
    qDebug() << udpSocket->localPort();
    QObject::connect(udpSocket, &QUdpSocket::readyRead, this, &UdpListenService::listen);
}

void UdpListenService::listen() {
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        qDebug() << "Имеется сообщение от:" << datagram.senderAddress().toString() << "порт:" << datagram.senderPort();

        if (datagram.senderPort() != ServerProperties::PORT) {
            qDebug() << "Было получено сообщение не от сервера " + QString::number(datagram.senderPort());
            continue;
        }

        emit receivedServerResponse(
            UdpResponse::fromJson(QString::fromUtf8(datagram.data()))
        );
    }
}
