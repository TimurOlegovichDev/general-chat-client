#ifndef CLIENTDTO_H
#define CLIENTDTO_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>



class ClientDto {
    public:
        ClientDto(const QString& username,
               const QByteArray& password);

        QString getUserName();
        QByteArray getPassword();
        QJsonDocument toJson() const;

    private:
        QString username;
        QByteArray password;

};

#endif // CLIENTDTO_H
