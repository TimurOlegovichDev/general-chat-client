#ifndef MESSAGEDTO_H
#define MESSAGEDTO_H

#include <QJsonDocument>
#include <QString>

class QJsonObject;


class MessageDto {

    public:
        MessageDto(QString text, QString senderName);

        MessageDto();

        int getSenderPort() const;

        const QString& getSenderName() const;

        const QString& getText() const;

        const QString& getTime() const;

        static MessageDto fromJson(QJsonObject& json);
        bool isValid() const;

        QJsonDocument toJson() const;

    private:
        QString senderName;
        QString text;
        QString time;
        int senderPort;
};

#endif // MESSAGEDTO_H
