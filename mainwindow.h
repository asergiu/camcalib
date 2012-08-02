#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "stereocamera.h"
#include <QTimer>
#include "stdio.h"


#define LEFT_CAM 0
#define RIGHT_CAM 1
#define BOTH_CAMS 2


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void trace(QString str);
    void linuxV4L2Command();
    Ui::MainWindow *ui;

private:
    int image_index;
    StereoCamera stereoCamera;
    QTimer timer;
    int sampleTimeout;
    int camera_index;
    bool camera_ready;
    bool capture_frames;
    CvCapture *leftCapture, *rightCapture;


private slots:
    void initialize();
    void startCapture();
    void update_time();
    void update_time_alternatively();
    void captureFrame();
    void captureFramesAlternatively();

};

#endif // MAINWINDOW_H
