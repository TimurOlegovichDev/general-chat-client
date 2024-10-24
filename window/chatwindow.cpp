#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

ChatWindow::ChatWindow(QWidget *parent, UdpSendService* sendService) :
    QWidget(parent),
    ui(new Ui::ChatWindow){
    ui->setupUi(this);
    this->sendService = sendService;
}

ChatWindow::~ChatWindow(){
    delete ui;
}

void ChatWindow::on_sendButton_clicked(){
    if(ui->messageEdit->toPlainText().isEmpty()){
        return;
    }
    //    if(sendService->send(
    //                new UdpRequest(
    //                    ui->messageEdit->toPlainText().toUtf8()
    //                    )
    //                )){
    //        qDebug() << "Сообщение отправлено";
    //    } else {
    //        qDebug() << "Сообщение не отправлено";
    //    }
}

void ChatWindow::handle(UdpResponse response){
    if(response.getCode() == UdpResponseCode::OK){

    } else if (response.getCode() == UdpResponseCode::BAD){

    } else {
        qDebug() << "Получено хз что";
    }
}
