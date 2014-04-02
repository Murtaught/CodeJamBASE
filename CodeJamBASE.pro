#-------------------------------------------------
#
# Project created by QtCreator 2014-04-01T19:34:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = CodeJamBASE
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += casemanager.cpp main.cpp

HEADERS += case.hpp casemanager.hpp reader.hpp writer.hpp dispatcher.hpp \
    solution.hpp

OTHER_FILES += \
    input.txt \
    output.txt
