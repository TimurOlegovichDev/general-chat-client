#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <ChatMessage.h>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <messagedto.h>
#include <QJsonObject>

ChatWindow::ChatWindow(QWidget *parent, UdpSendService* sendService) :
    QWidget(parent),
    ui(new Ui::ChatWindow){
    ui->setupUi(this);

    QObject::connect(sendService,
                     &UdpSendService::receivedServerResponse,
                     this,
                     &ChatWindow::handle);
    this->sendService = sendService;
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    mainLayout = new QVBoxLayout(ui->widget);
}

ChatWindow::~ChatWindow(){
    delete ui;
}

void ChatWindow::on_sendButton_clicked(){
    sendService->send(
                new UdpRequest(
                    UdpMethod::POST_MESSAGE,
                    MessageDto(
                        ui->messageEdit->toPlainText(),
                        senderName
                        ).toJson()
                    )
                );
    ui->messageEdit->clear();
}

void ChatWindow::handle(UdpResponse response){
    if(response.getCode() == UdpResponseCode::HAS_MESSAGE){
        QString jsonString = response.getBody();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        QJsonObject jsonObject = jsonDoc.object();
        MessageDto msgDto = MessageDto::fromJson(jsonObject);
        if(!msgDto.isValid()){
            qDebug() << "Невалидное сообщение: " + msgDto.getSenderName() + msgDto.getSenderPort();
            return;
        }
        scrollLayout->addWidget(new ChatMessage(
                                    msgDto.getSenderName(),
                                    msgDto.getText(),
                                    "не указано",
                                    msgDto.getSenderName() == this->senderName
                                    ));
        scrollContent->setLayout(scrollLayout);
        scrollArea->setWidget(scrollContent);
        mainLayout->addWidget(scrollArea);
        ui->widget->setLayout(mainLayout);
        qDebug() << "Сообщение выведено";
    } else if (response.getCode() == UdpResponseCode::BAD){

    } else if (response.getCode() == UdpResponseCode::CLOSE_CONNECTION){
        emit openAuthWindow();
    }
}

const QString& ChatWindow::getSenderName() const
{
    return senderName;
}

void ChatWindow::setSenderName(const QString& newSenderName)
{
    senderName = newSenderName;
}
