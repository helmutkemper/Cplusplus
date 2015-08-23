#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T13:32:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtIDE
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ../StateMachine/copy.cpp \
    ../StateMachine/stackenum.cpp \
    ../StateMachine/statemachine.cpp \
    ../StateMachine/SendToDevice.cpp \
    ../StateMachine/RingMemory.cpp

HEADERS  += MainWindow.h \
    ../AtModem/state_machine_at_modem_event_list.h \
    ../StateMachine/copy.h \
    ../StateMachine/stackenum.h \
    ../StateMachine/statemachine.h \
    ../StateMachine/SendToDevice.h \
    ../typesKemper.h \
    ../StateMachine/RingMemory.h

FORMS    += MainWindow.ui
