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
    if(sendService->send(new UdpRequest(ui->messageEdit->toPlainText()))){
        qDebug() << "Сообщение отправлено";
    } else {
        qDebug() << "Сообщение не отправлено";
    }
}
