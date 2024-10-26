#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QLineEdit>
#include <QWidget>
#include <QTextBrowser>
#include <udpsendservice.h>
#include <QHBoxLayout>
#include <QScrollArea>
#include <clientdto.h>

namespace Ui {
    class ChatWindow;
}

class ChatWindow : public QWidget{
        Q_OBJECT

    public:
        explicit ChatWindow(QWidget *parent = nullptr,
                            UdpSendService* sendService = new UdpSendService());
        ~ChatWindow();

        const QString& getSenderName() const;
        void setSenderName(const QString& newSenderName);

    private slots:

        void on_sendButton_clicked();
    signals:
        void openAuthWindow();
        void exit();

    private:
        Ui::ChatWindow* ui;
        UdpSendService* sendService;

        void handle(UdpResponse response);
        void onConnectTimeout();

        QVBoxLayout *mainLayout;
        QScrollArea *scrollArea;
        QWidget *scrollContent = new QWidget();
        QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);

        QString senderName;

};

#endif // CHATWINDOW_H
