TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += \
        appearingtext.cpp \
        errorandexit.cpp \
        gamescroll.cpp \
        main.cpp

HEADERS += \
    appearingtext.h \
    errorandexit.h \
    gamescroll.h \
    screenobject.h
