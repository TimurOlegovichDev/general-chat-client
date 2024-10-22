#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

ChatWindow::ChatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWindow){
    ui->setupUi(this);
}

ChatWindow::~ChatWindow(){
    delete ui;
}
