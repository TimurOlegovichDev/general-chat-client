#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <authwindow.h>
#include <chatwindow.h>

class WindowController : public QObject {

    Q_OBJECT

    public:
        WindowController(AuthWindow* authWindow,
                         ChatWindow* chatWindow);
        void auth();
        void chat();
    private:
        AuthWindow* authWindow;
        ChatWindow* chatWindow;
};

#endif // WINDOWCONTROLLER_H
