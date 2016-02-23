TEMPLATE = lib
TARGET = Welcome
QT += network qml quick
CONFIG += plugin

include(../../gcsplugin.pri)
include(welcome_dependencies.pri)

HEADERS += welcomeplugin.h \
    welcomemode.h \
    welcome_global.h
SOURCES += welcomeplugin.cpp \
    welcomemode.cpp \

DEFINES += WELCOME_LIBRARY
OTHER_FILES += Welcome.pluginspec \
    welcome.json
