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

INCLUDEPATH += /usr/local/include/
#LIBS+= -L/usr/local/lib/ -lopencv_core -lopencv_legacy -lopencv_imgproc -lopencv_objdetect -lopencv_ml -lopencv_highgui -lopencv_calib3d
LIBS+= /usr/local/lib/libopencv_core.so.2.4.1
LIBS+= /usr/local/lib/libopencv_legacy.so.2.4.1
LIBS+= /usr/local/lib/libopencv_highgui.so.2.4.1

