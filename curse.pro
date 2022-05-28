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
        casinolocat.cpp \
        errorandexit.cpp \
        game.cpp \
        gamescroll.cpp \
        homelocat.cpp \
        inventory.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    abstractlocation.h \
    appearingbutton.h \
    appearingobject.h \
    appearingtext.h \
    casinolocat.h \
    errorandexit.h \
    game.h \
    gamescroll.h \
    homelocat.h \
    inventory.h \
    iobserver.h \
    isubject.h \
    player.h \
    screenobject.h
