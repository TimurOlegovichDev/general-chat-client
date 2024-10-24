#include "windowcontroller.h"

WindowController::WindowController(AuthWindow* authWindow,
                                   ChatWindow* chatWindow) : QObject(){
    this->authWindow = authWindow;
    this->chatWindow = chatWindow;
    QObject::connect(authWindow,
                     &AuthWindow::openChatWindow,
                     this,
                     &WindowController::chat);
}

void WindowController::auth(){
    chatWindow->close();
    authWindow->show();
}

void WindowController::chat(){
    authWindow->close();
    chatWindow->show();
}


