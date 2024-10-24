#include "authwindow.h"
#include "ui_authwindow.h"
#include <serverproperties.h>

AuthWindow::AuthWindow(QWidget *parent,
                       UdpSendService* udpService ) :
    QWidget(parent),
    ui(new Ui::AuthWindow){
    ui->setupUi(this);
    this->udpService = udpService;
    QObject::connect(udpService,
                     &UdpSendService::receivedServerResponse,
                     this,
                     &AuthWindow::handle);
}

AuthWindow::~AuthWindow(){
    delete ui;
}

void AuthWindow::on_showPassButton_clicked(bool checked){
    if(checked) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}


void AuthWindow::on_buttonLogin_clicked(){
    if (ui->lineEditPassword->text().length() < 10 || ui->lineEditUsername->text().length() < 10) {
        QMessageBox::warning(this,
                             "Некорректное заполнение",
                             "Длина имени пользователя и пароля должна быть более 10 символов."
                             );
        return;
    }
    udpService->send(
                new UdpRequest(
                    UdpMethod::LOGIN,
                    Client(
                        ui->lineEditUsername->text(),
                        ui->lineEditPassword->text().toUtf8()
                        )
                    .toJson()
                    )
                );
}

void AuthWindow::on_buttonRegister_clicked(){
    if (ui->lineEditPassword->text().length() < 10 || ui->lineEditUsername->text().length() < 10) {
        QMessageBox::warning(this,
                             "Некорректное заполнение",
                             "Длина имени пользователя и пароля должна быть более 10 символов."
                             );
        return;
    }
    udpService->send(
                new UdpRequest(
                    UdpMethod::REGISTER,
                    Client(
                        ui->lineEditUsername->text(),
                        ui->lineEditPassword->text().toUtf8()
                        )
                    .toJson()
                    )
                );
}

void AuthWindow::handle(UdpResponse response){
    if(response.getCode() == UdpResponseCode::OK){
        QMessageBox::information(this,
                             "Положительнрый ответ",
                             response.getBody()
                             );
        emit openChatWindow();
    } else if (response.getCode() == UdpResponseCode::BAD){
        QMessageBox::warning(this,
                             "Отрицательный ответ",
                             response.getBody()
                             );
    } else {
        QMessageBox::warning(this,
                             "Ошибка",
                             response.getBody()
                             );
    }
}


