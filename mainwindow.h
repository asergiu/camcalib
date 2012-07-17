#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "stereocamera.h"
#include <QTimer>


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
    Ui::MainWindow *ui;

private:
    int image_index;
    StereoCamera stereoCamera;
    QTimer timer;
    int sampleTimeout;
    bool camera_ready;
    CvCapture *leftCapture, *rightCapture;


private slots:
    void startCapture();
    void update_time();

};

#endif // MAINWINDOW_H
