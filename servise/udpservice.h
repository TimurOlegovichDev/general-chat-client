#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QRandomGenerator>
#include <udprequest.h>

class UdpService {
    public:
        UdpService() {
            udpSocket = new QUdpSocket();

            if (!udpSocket->bind(QHostAddress::Any, getRandomPort())) {
                qDebug() << "Не удалось привязать сокет:" << udpSocket->errorString();
            } else {
                qDebug() << "Удачная привязка сокета";
            }
        }

    protected:
        QUdpSocket *udpSocket;

        quint16 getRandomPort() {
            const int minPort = 1024;
            const int maxPort = 65535;
            return QRandomGenerator::global()->bounded(minPort, maxPort + 1);
        }
};
