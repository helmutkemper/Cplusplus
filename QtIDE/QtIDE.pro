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
    ../StateMachine/RingMemory.cpp \
    ../SendToDevice/SendToDevice.cpp \
    FileSystem.cpp

HEADERS  += MainWindow.h \
    ../AtModem/state_machine_at_modem_event_list.h \
    ../StateMachine/copy.h \
    ../StateMachine/stackenum.h \
    ../StateMachine/statemachine.h \
    ../typesKemper.h \
    ../StateMachine/RingMemory.h \
    ../SendToDevice/SendToDevice.h \
    FileSystem.h

FORMS    += MainWindow.ui
