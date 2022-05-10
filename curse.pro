TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += \
        errorandexit.cpp \
        gamescroll.cpp \
        main.cpp

HEADERS += \
    errorandexit.h \
    gamescroll.h
