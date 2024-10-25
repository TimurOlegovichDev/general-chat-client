#ifndef UDPMETHOD_H
#define UDPMETHOD_H

#include <QString>

class UdpMethod {
    public:
        static const QString REGISTER;
        static const QString LOGIN;
        static const QString POST_MESSAGE;
        static const QString GET_MESSAGE;
        static const QString CONNECT;
};

#endif // UDPMETHOD_H
