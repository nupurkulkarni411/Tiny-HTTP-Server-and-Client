#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T22:35:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp

HEADERS += \
        mainwindow.h \
    dialog.h

FORMS += \
        mainwindow.ui \
    dialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../HttpCommCore/release/ -lHttpCommCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../HttpCommCore/debug/ -lHttpCommCore
else:unix: LIBS += -L$$PWD/../HttpCommCore/ -lHttpCommCore

INCLUDEPATH += $$PWD/../HttpCommCore
DEPENDPATH += $$PWD/../HttpCommCore

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Sockets/release/ -lsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Sockets/debug/ -lsocket
else:unix: LIBS += -L$$PWD/../Sockets/ -lsocket

INCLUDEPATH += $$PWD/../Sockets
DEPENDPATH += $$PWD/../Sockets

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Utilities/release/ -lutils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Utilities/debug/ -lutils
else:unix: LIBS += -L$$PWD/../Utilities/ -lutils

INCLUDEPATH += $$PWD/../Utilities
DEPENDPATH += $$PWD/../Utilities

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Logger/release/ -llogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Logger/debug/ -llogger
else:unix: LIBS += -L$$PWD/../Logger/ -llogger

INCLUDEPATH += $$PWD/../Logger
DEPENDPATH += $$PWD/../Logger

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../blockingQueue/release/ -lblockingq
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../blockingQueue/debug/ -lblockingq
else:unix: LIBS += -L$$PWD/../blockingQueue/ -lblockingq

INCLUDEPATH += $$PWD/../blockingQueue
DEPENDPATH += $$PWD/../blockingQueue

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Message/release/ -lMessage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Message/debug/ -lMessage
else:unix: LIBS += -L$$PWD/../Message/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message
