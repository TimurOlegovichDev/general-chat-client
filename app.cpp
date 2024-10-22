#include "authwindow.h"

#include <QApplication>
#include <chatwindow.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    ChatWindow w;
    AuthWindow w1;
    w.show();
    w1.show();
    return a.exec();
}
