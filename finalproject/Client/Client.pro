# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Client
DESTDIR = ./debug
QT += core gui widgets
CONFIG += debug
DEFINES += _WINDOWS _UNICODE WIN64 QT_DEPRECATED_WARNINGS QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles/$(ConfigurationName) \
    ./GeneratedFiles \
    . \
    ./debug \
    ../../../../../../../include \
    $(QTDIR)/mkspecs/win32-msvc
LIBS += -L"../../../../../../../openssl/lib" \
    -L"../../../../../../../Utils/my_sql/my_sql/lib" \
    -L"../../../../../../../Utils/postgresql/pgsql/lib" \
    -lshell32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Client.pri)