#-------------------------------------------------
#
# Project created by QtCreator 2012-06-12T10:50:31
#
#-------------------------------------------------

QT       += core gui

TARGET = Calibration
TEMPLATE = app


SOURCES += main.cpp\
    undistort.cpp \
    calibrationwizard.cpp \
    intropage.cpp \
    patterninfopage.cpp \
    chessboardcornerspage.cpp \
    resultpage.cpp \
    loadimagespage.cpp

HEADERS  += \
    undistort.h \
    calibrationwizard.h \
    intropage.h \
    patterninfopage.h \
    chessboardcornerspage.h \
    resultpage.h \
    loadimagespage.h

FORMS    += \
    undistort.ui \
    calibrationwizard.ui \
    intropage.ui \
    patterninfopage.ui \
    chessboardcornerspage.ui \
    resultpage.ui \
    loadimagespage.ui

OTHER_FILES +=
