#ifndef CLIENT_H
#define CLIENT_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>



class Client {
    public:
        Client(const QString& username,
               const QByteArray& password);

        QString getUserName();
        QByteArray getPassword();
        QJsonDocument toJson() const;

    private:
        QString username;
        QByteArray password;

};

#endif // CLIENT_H
