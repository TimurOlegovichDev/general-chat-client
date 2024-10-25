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

    // Подключаем сигнал получения ответа от сервера
    QObject::connect(udpService,
                     &UdpSendService::receivedServerResponse,
                     this,
                     &AuthWindow::handle);

    // Отправляем запрос на подключение
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
    // Запускаем таймер на 3 секунды для ожидания ответа
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AuthWindow::onConnectTimeout);
    timer->start(3000); // 3000 миллисекунд = 3 секунды
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
    udpService->send(new UdpRequest(UdpMethod::LOGIN, Client(ui->lineEditUsername->text(), ui->lineEditPassword->text().toUtf8()).toJson()));
}

void AuthWindow::on_buttonRegister_clicked() {
    if (!isValidLineEdit()) {
        return;
    }
    udpService->send(new UdpRequest(UdpMethod::REGISTER, Client(ui->lineEditUsername->text(), ui->lineEditPassword->text().toUtf8()).toJson()));
}

void AuthWindow::handle(UdpResponse response) {
    qDebug() << "Получен ответ от сервера: " + response.toString();

    if (!isConnected) {
        if (response.getCode() == UdpResponseCode::OK) {
            isConnected = true;
            timer->stop();
            return;
        } else {
            QMessageBox::critical(this, "Ошибка подключения", response.getBody(), QMessageBox::Ok);
            return; // Выходим из функции, если не удалось подключиться
        }
    }

    if (response.getCode() == UdpResponseCode::OK) {
        QMessageBox::information(this, "Положительный ответ", response.getBody());
        emit openChatWindow();
    } else if (response.getCode() == UdpResponseCode::BAD) {
        QMessageBox::warning(this, "Отрицательный ответ", response.getBody());
    } else {
        QMessageBox::warning(this, "Ошибка", response.getBody());
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
