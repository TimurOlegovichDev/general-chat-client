#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QLineEdit>
#include <QWidget>
#include <QTextBrowser>

namespace Ui {
    class ChatWindow;
}

class ChatWindow : public QWidget{
        Q_OBJECT

    public:
        explicit ChatWindow(QWidget *parent = nullptr);
        ~ChatWindow();

    private slots:
        void sendMessage() {
            QString message = messageInput->text();
            if (!message.isEmpty()) {
                messagesArea->append("<b>Вы:</b> " + message);
                messageInput->clear();
            }
        }

    private:
        Ui::ChatWindow *ui;

        QTextBrowser *messagesArea;
        QLineEdit *messageInput;
};

#endif // CHATWINDOW_H
