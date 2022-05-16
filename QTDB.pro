QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addrab.cpp \
    izmenenieo.cpp \
    izmenenieprikaz.cpp \
    izmenenierab.cpp \
    izmens.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    selecter.cpp

HEADERS += \
    addrab.h \
    izmenenieo.h \
    izmenenieprikaz.h \
    izmenenierab.h \
    izmens.h \
    login.h \
    mainwindow.h \
    selecter.h

FORMS += \
    addrab.ui \
    izmenenieo.ui \
    izmenenieprikaz.ui \
    izmenenierab.ui \
    izmens.ui \
    login.ui \
    mainwindow.ui \
    selecter.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
