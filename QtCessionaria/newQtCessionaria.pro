QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    GUI/alimtipebox.cpp \
    GUI/insertveicolo.cpp \
    GUI/segmentotipebox.cpp \
    GUI/tipomotobox.cpp \
    GUI/usermenu.cpp \
    container/container.cpp \
    controller/controller.cpp \
    hierarchy/auto.cpp \
    hierarchy/camion.cpp \
    hierarchy/carrozzeria.cpp \
    hierarchy/mezzo.cpp \
    hierarchy/moto.cpp \
    hierarchy/motore.cpp \
    hierarchy/veicolo.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp

HEADERS += \
    GUI/alimtipebox.h \
    GUI/insertveicolo.h \
    GUI/segmentotipebox.h \
    GUI/tipomotobox.h \
    GUI/usermenu.h \
    container/container.h \
    controller/controller.h \
    exceptions/exceptions.h \
    hierarchy/auto.h \
    hierarchy/camion.h \
    hierarchy/carrozzeria.h \
    hierarchy/mezzo.h \
    hierarchy/moto.h \
    hierarchy/motore.h \
    hierarchy/veicolo.h \
    mainwindow.h \
    model.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target