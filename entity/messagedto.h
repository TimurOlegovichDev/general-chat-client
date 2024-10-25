#ifndef MESSAGEDTO_H
#define MESSAGEDTO_H

#include <QString>



class MessageDto
{
    public:
        MessageDto();

        int getSenderPort() const;

        const QString& getSenderName() const;

        const QString& getText() const;

        const QString& getTime() const;

    private:
        QString senderName;
        QString text;
        QString time;
        int senderPort;
};

#endif // MESSAGEDTO_H
