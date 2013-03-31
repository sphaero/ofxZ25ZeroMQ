TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    example/src/testc.cpp

HEADERS += \
    src/ofxZ25ZeroMQReqRepClient.h


unix:!macx:!symbian: LIBS += -L$$PWD/libs/libzmq-3.2.2/lib/linux64/ -lzmq

LIBS += -lrt

INCLUDEPATH += $$PWD/libs/libzmq-3.2.2/includes
INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/libs/libzmq-3.2.2/includes

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/libs/libzmq-3.2.2/lib/linux64/libzmq.a
