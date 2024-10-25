#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <ChatMessage.h>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>

ChatWindow::ChatWindow(QWidget *parent, UdpSendService* sendService) :
    QWidget(parent),
    ui(new Ui::ChatWindow){
    ui->setupUi(this);
    this->sendService = sendService;
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    mainLayout = new QVBoxLayout(ui->widget);

}

ChatWindow::~ChatWindow(){
    delete ui;
}

void ChatWindow::on_sendButton_clicked(){
    scrollLayout->addWidget(new ChatMessage("qwerty123", "I check Delegate and I think this isn't what I want. Of course I can add QLabel to QTableView, but when I click on QLabel I see the QTableView's cell. I setShowGrid to false but this isn't what I need.", "12:46", true));
    scrollLayout->addWidget(new ChatMessage("Niggalas", "Did you read about Delegates ? The Editor is only active when editing, rest of the time its not shown. Then its paint job to show the data.", "12:46", false));
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);
    ui->widget->setLayout(mainLayout);
}

void ChatWindow::handle(UdpResponse response){
    if(response.getCode() == UdpResponseCode::OK){

    } else if (response.getCode() == UdpResponseCode::BAD){

    } else {
        qDebug() << "Получено хз что";
    }
}
