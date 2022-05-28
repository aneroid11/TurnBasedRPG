TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"./libs/thor/bin/"

LIBS += -lpthread
LIBS += -lsfml-system -lsfml-graphics -lsfml-window
LIBS += -lthor

INCLUDEPATH += ./libs/thor/include/
INCLUDEPATH += ./libs/aurora/include/

SOURCES += \
        abstractlocation.cpp \
        appearingbutton.cpp \
        appearingobject.cpp \
        appearingtext.cpp \
        errorandexit.cpp \
        game.cpp \
        gamescroll.cpp \
        main.cpp

HEADERS += \
    abstractlocation.h \
    appearingbutton.h \
    appearingobject.h \
    appearingtext.h \
    errorandexit.h \
    game.h \
    gamescroll.h \
    iobserver.h \
    isubject.h \
    screenobject.h
