#include "authwindow.h"

#include <QApplication>
#include <chatwindow.h>
#include <windowcontroller.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    UdpSendService* service = new UdpSendService();
    WindowController* controller = new WindowController(
                new AuthWindow(nullptr, service),
                new ChatWindow(nullptr, service)
                );
    controller->auth();
    return a.exec();
}
