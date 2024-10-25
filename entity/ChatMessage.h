#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QDateTime>

class ChatMessage : public QFrame {
public:
    ChatMessage(const QString &username, const QString &message, const QString &time, bool isSender, QWidget *parent = nullptr)
        : QFrame(parent) {
        // Создание макета для сообщения
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *usernameLabel = new QLabel(username);
        usernameLabel->setStyleSheet("font-weight: bold; font-size: 22px;");

        QLabel *messageLabel = new QLabel(message);
        messageLabel->setWordWrap(true);
        messageLabel->setMinimumHeight(100);
        messageLabel->setMaximumWidth(600);
        messageLabel->setStyleSheet(isSender ?
            "QLabel { background-color: #2ea1ff; color: white; padding: 10px; border-radius: 15px; font-size: 28px; }" :
            "QLabel { background-color: #abe4ff; color: black; padding: 10px; border-radius: 15px; font-size: 28px; }");

        // Добавляем метку для времени
        QLabel *timeLabel = new QLabel(time); // Используем переданное время
        timeLabel->setStyleSheet("font-size: 18px; color: gray;"); // Стиль для времени

        layout->addWidget(usernameLabel);
        layout->addWidget(messageLabel);
        layout->addWidget(timeLabel); // Добавляем метку времени

        messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Изменено на Expanding для ширины

        // Установка выравнивания в зависимости от отправителя
        if (isSender) {
            usernameLabel->setAlignment(Qt::AlignRight);
            messageLabel->setAlignment(Qt::AlignVCenter);
            timeLabel->setAlignment(Qt::AlignRight); // Выравнивание времени для отправителя
            layout->setAlignment(Qt::AlignRight); // Выравнивание для отправителя
        } else {
            usernameLabel->setAlignment(Qt::AlignLeft);
            messageLabel->setAlignment(Qt::AlignVCenter);
            timeLabel->setAlignment(Qt::AlignLeft); // Выравнивание времени для получателя
            layout->setAlignment(Qt::AlignLeft);
        }

        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    }
};

#endif // CHATMESSAGE_H
