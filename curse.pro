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
        abstractfightlocation.cpp \
        abstractlocation.cpp \
        abstractlocwithpalm.cpp \
        abstractshoplocat.cpp \
        appearingbutton.cpp \
        appearingobject.cpp \
        appearingtext.cpp \
        casinolocat.cpp \
        citygatelocat.cpp \
        errorandexit.cpp \
        fieldlocat.cpp \
        game.cpp \
        gamescroll.cpp \
        hilllocat.cpp \
        homelocat.cpp \
        inventory.cpp \
        main.cpp \
        player.cpp \
        toolsshoplocat.cpp \
        zdrasshoplocat.cpp

HEADERS += \
    abstractfightlocation.h \
    abstractlocation.h \
    abstractlocwithpalm.h \
    abstractshoplocat.h \
    appearingbutton.h \
    appearingobject.h \
    appearingtext.h \
    casinolocat.h \
    citygatelocat.h \
    errorandexit.h \
    fieldlocat.h \
    game.h \
    gamescroll.h \
    hilllocat.h \
    homelocat.h \
    inventory.h \
    iobserver.h \
    isubject.h \
    player.h \
    screenobject.h \
    toolsshoplocat.h \
    zdrasshoplocat.h
