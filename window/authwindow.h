#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QWidget>
#include <udpsendservice.h>
#include <QMessageBox>
#include <UdpMethod.h>
#include <udprequest.h>
#include <client.h>
#include <QNetworkDatagram>
#include <udpresponse.h>

namespace Ui
{
    class AuthWindow;
}

class AuthWindow : public QWidget
{
        Q_OBJECT

    public:
        explicit AuthWindow(QWidget *parent = nullptr,
                            UdpSendService* udpService = new UdpSendService());
        ~AuthWindow();

    private slots:
        void on_showPassButton_clicked(bool checked);

        void on_buttonLogin_clicked();

        void on_buttonRegister_clicked();

    signals:
        void openChatWindow();
        void exit();

    private:
        Ui::AuthWindow* ui;
        UdpSendService* udpService;
        bool isConnected = false;
        QTimer *timer;

        void handle(UdpResponse response);
        bool isValidLineEdit();
        void sendConnectRequest();
        void onConnectTimeout();
};

#endif // AUTHWINDOW_H
