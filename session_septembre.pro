QT       += core gui
QT       += sql
QT       += multimedia
QT       += printsupport
QT       += multimediawidgets charts printsupport widgets axcontainer network
QT       +=network
QT       += core gui \
    quick
QT+=sql
QT       += core gui printsupport
QT       += core gui charts
QT       += core  gui axcontainer
QT       += core gui  serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS+= -std=gnu++14
CONFIG += console
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NotificationLayout.cpp \
    NotificationWidget.cpp \
    Operation.cpp \
    QrCode.cpp \
    Result.cpp \
    activite.cpp \
    connection.cpp \
    eleve.cpp \
    gestion_activite.cpp \
    gestion_eleve.cpp \
    gpsvalise.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    smtp.cpp

HEADERS += \
    NotificationLayout.h \
    NotificationWidget.h \
    Operation.h \
    QrCode.hpp \
    Result.h \
    activite.h \
    connection.h \
    eleve.h \
    gestion_activite.h \
    gestion_eleve.h \
    gpsvalise.h \
    historique.h \
    mainwindow.h \
    menu.h \
    smtp.h \
    webaxwidget.h

FORMS += \
    gestion_activite.ui \
    gestion_eleve.ui \
    mainwindow.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
