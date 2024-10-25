#include "authwindow.h"
#include "ui_authwindow.h"
#include <QThread>
#include <serverproperties.h>
#include <QTimer>
#include <QMessageBox>

AuthWindow::AuthWindow(QWidget *parent, UdpSendService* udpService) :
    QWidget(parent),
    ui(new Ui::AuthWindow),
    isConnected(false) {
    ui->setupUi(this);
    this->udpService = udpService;

    QObject::connect(udpService,
                     &UdpSendService::receivedServerResponse,
                     this,
                     &AuthWindow::handle);

    timerToWaitServerAnswer = new QTimer(this);
    timerToWaitServerAnswer->setSingleShot(true);
    timerToWaitServerAnswer->setInterval(TIME_IN_MS_TO_WAIT_ANSWER);
    QObject::connect(timerToWaitServerAnswer,
            &QTimer::timeout,
            this,
            &AuthWindow::onConnectTimeout);
    sendConnectRequest();
}

AuthWindow::~AuthWindow() {
    delete ui;
}

void AuthWindow::sendConnectRequest() {
    udpService->send(
                new UdpRequest(
                    UdpMethod::CONNECT,
                    QJsonDocument()
                    )
                );
    timerToWaitServerAnswer->start();
}

void AuthWindow::onConnectTimeout() {
    // Если таймер сработал, значит ответа не было
    QMessageBox::critical(this, "Ошибка подключения",
                          "Не удалось подключиться к серверу. Пожалуйста, проверьте соединение.");
    emit exit();
}

void AuthWindow::on_showPassButton_clicked(bool checked) {
    if (checked) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}

void AuthWindow::on_buttonLogin_clicked() {
    if (!isValidLineEdit()) {
        return;
    }
    udpService->send(
                new UdpRequest(
                    UdpMethod::LOGIN,
                    ClientDto(ui->lineEditUsername->text(),
                           ui->lineEditPassword->text().toUtf8()
                           ).toJson()
                    )
                );
    timerToWaitServerAnswer->start();
}

void AuthWindow::on_buttonRegister_clicked() {
    if (!isValidLineEdit()) {
        return;
    }
    udpService->send(
                new UdpRequest(
                    UdpMethod::REGISTER,
                    ClientDto(ui->lineEditUsername->text(),
                           ui->lineEditPassword->text().toUtf8()
                           ).toJson()
                    )
                );
    timerToWaitServerAnswer->start();
}

void AuthWindow::handle(UdpResponse response) {
    qDebug() << "Получен ответ от сервера: " + response.toString();
    timerToWaitServerAnswer->stop();
    if (response.getCode() == UdpResponseCode::OK) {
        QMessageBox::information(this, "General chat", response.getBody());
        emit openChatWindow();
    } else if (response.getCode() == UdpResponseCode::BAD) {
        QMessageBox::warning(this, "General chat", response.getBody());
    } else {
        QMessageBox::warning(this, "General chat", response.getBody());
    }
}

bool AuthWindow::isValidLineEdit() {
    if (ui->lineEditPassword->text().length() < 10 || ui->lineEditUsername->text().length() < 10) {
        QMessageBox::warning(this, "Некорректное заполнение",
                             "Длина имени пользователя и пароля должна быть более 10 символов.");
        return false;
    }
    return true;
}
