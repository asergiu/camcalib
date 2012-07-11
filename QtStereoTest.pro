#-------------------------------------------------
#
# Project created by QtCreator 2012-07-04T13:43:49
#
#-------------------------------------------------

QT       += core gui

TARGET = QtStereoTest
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp
QMAKE_CFLAGS_DEBUG += -fopenmp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stereocameraparameters.cpp \
    stereocamera.cpp \
    stereocalibration.cpp \
    cameraparameters.cpp \
    calibration.cpp \
    stereocalibrationform.cpp \
    adjustbmparam.cpp

HEADERS  += mainwindow.h \
    stereocameraparameters.h \
    stereocamera.h \
    stereocalibration.h \
    cameraparameters.h \
    calibration.h \
    stereocalibrationform.h \
    adjustbmparam.h

FORMS    += mainwindow.ui \
    stereocalibrationform.ui \
    adjustbmparam.ui
INCLUDEPATH += C:\OpenCV2.1\include

LIBS += -LC:\OpenCV2.1\lib -lcv210 -lhighgui210 -lcxcore210
