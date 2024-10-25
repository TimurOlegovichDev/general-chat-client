QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
            window/ \
            net/ \
            service/ \
            entity/ \
            handler/ \
            controller/

SOURCES += \
    app.cpp \
    controller/windowcontroller.cpp \
    entity/clientdto.cpp \
    entity/messagedto.cpp \
    net/ServerProperties.cpp \
    net/udpmethod.cpp \
    net/udprequest.cpp \
    net/udpresponse.cpp \
    service/udpsendservice.cpp \
    window/authwindow.cpp \
    window/chatwindow.cpp

HEADERS += \
    controller/windowcontroller.h \
    entity/ChatMessage.h \
    entity/clientdto.h \
    entity/messagedto.h \
    net/UdpMethod.h \
    net/serverproperties.h \
    net/udprequest.h \
    net/udpresponse.h \
    service/udpsendservice.h \
    service/udpservice.h\
    window/authwindow.h \
    window/chatwindow.h

FORMS += \
    window/authwindow.ui \
    window/chatwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
            icons.qrc
