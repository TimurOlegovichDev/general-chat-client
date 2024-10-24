#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QLineEdit>
#include <QWidget>
#include <QTextBrowser>
#include <udpsendservice.h>

namespace Ui {
    class ChatWindow;
}

class ChatWindow : public QWidget{
        Q_OBJECT

    public:
        explicit ChatWindow(QWidget *parent = nullptr,
                            UdpSendService* sendService = new UdpSendService());
        ~ChatWindow();

    private slots:

        void on_sendButton_clicked();

    private:
        Ui::ChatWindow* ui;
        UdpSendService* sendService;

        void handle(UdpResponse response);
};

#endif // CHATWINDOW_H
