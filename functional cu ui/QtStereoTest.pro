#-------------------------------------------------
#
# Project created by QtCreator 2012-07-04T13:43:49
#
#-------------------------------------------------

QT       += core gui

TARGET = QtStereoTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stereocameraparameters.cpp \
    stereocamera.cpp \
    stereocalibration.cpp \
    cameraparameters.cpp \
    calibration.cpp \
    stereocalibrationform.cpp \
    adjustbmparam.cpp \
    fileutils.cpp \
    testcalibrationdialog.cpp \
    stereocorrespondenceparameters.cpp

HEADERS  += mainwindow.h \
    stereocameraparameters.h \
    stereocamera.h \
    stereocalibration.h \
    cameraparameters.h \
    calibration.h \
    stereocalibrationform.h \
    adjustbmparam.h \
    mainwindow.h \
    fileutils.h \
    testcalibrationdialog.h \
    correspondenceparameters.h

FORMS    += \
    stereocalibrationform.ui \
    adjustbmparam.ui \
    mainwindow.ui \
    testcalibrationdialog.ui
INCLUDEPATH += C:\OpenCV2.1\include

LIBS += -LC:\OpenCV2.1\lib -lcv210 -lhighgui210 -lcxcore210
