#include "windowcontroller.h"

#include <QThread>

WindowController::WindowController(AuthWindow* authWindow,
                                   ChatWindow* chatWindow) : QObject(){
    this->authWindow = authWindow;
    this->chatWindow = chatWindow;
    QObject::connect(authWindow,
                     &AuthWindow::openChatWindow,
                     this,
                     &WindowController::chat);
    QObject::connect(authWindow,
                     &AuthWindow::exit,
                     this,
                     &WindowController::closeAll);
}

void WindowController::auth(){
    authWindow->show();
    chatWindow->close();
}

void WindowController::chat(){
    authWindow->close();
    chatWindow->show();
}

void WindowController::closeAll(){
    qDebug() << "Закрытие всех окон приложения";
    chatWindow->close();
    authWindow->close();
}


