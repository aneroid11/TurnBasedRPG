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
        baywithboatlocat.cpp \
        casinolocat.cpp \
        citygatelocat.cpp \
        errorandexit.cpp \
        fieldlocat.cpp \
        fishingpier.cpp \
        forestlocat.cpp \
        game.cpp \
        gamescroll.cpp \
        hilllocat.cpp \
        homelocat.cpp \
        inventory.cpp \
        main.cpp \
        pierwithangryfisherman.cpp \
        pierwithenglishman.cpp \
        pierwithgoodfisherman.cpp \
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
    baywithboatlocat.h \
    casinolocat.h \
    citygatelocat.h \
    errorandexit.h \
    fieldlocat.h \
    fishingpier.h \
    forestlocat.h \
    game.h \
    gamescroll.h \
    hilllocat.h \
    homelocat.h \
    inventory.h \
    iobserver.h \
    isubject.h \
    pierwithangryfisherman.h \
    pierwithenglishman.h \
    pierwithgoodfisherman.h \
    player.h \
    screenobject.h \
    toolsshoplocat.h \
    zdrasshoplocat.h
