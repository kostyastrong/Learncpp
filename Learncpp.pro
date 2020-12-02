QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    func.cpp \
    main.cpp \
    mainwindow.cpp \
    onlynumber.cpp \
    string2int.cpp \
    tedit1int.cpp \
    twostring2int.cpp

HEADERS += \
    func.h \
    mainwindow.h \
    onlynumber.h \
    string2int.h \
    tedit1int.h \
    twostring2int.h

FORMS += \
    mainwindow.ui \
    onlynumber.ui \
    string2int.ui \
    tedit1int.ui \
    twostring2int.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
