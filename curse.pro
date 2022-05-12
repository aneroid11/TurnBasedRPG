TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += \
        appearingbutton.cpp \
        appearingobject.cpp \
        appearingtext.cpp \
        errorandexit.cpp \
        gamescroll.cpp \
        main.cpp

HEADERS += \
    appearingbutton.h \
    appearingobject.h \
    appearingtext.h \
    errorandexit.h \
    gamescroll.h \
    screenobject.h
