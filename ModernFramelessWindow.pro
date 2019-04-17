QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ModernFramelessWindow
TEMPLATE = app

SOURCES += src/main.cpp \
            src/FramelessWindow.cpp

HEADERS += src/FramelessWindow.h