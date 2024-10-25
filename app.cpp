#include "authwindow.h"

#include <QApplication>
#include <chatwindow.h>
#include <windowcontroller.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    WindowController* controller = new WindowController(
                new AuthWindow(),
                new ChatWindow()
                );
    controller->auth();
    return a.exec();
}
