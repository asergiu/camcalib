#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stereocamera.h"
#include "stereocalibration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    StereoCamera* stereoCamera;
    StereoCalibration *stereoCalibration;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void capture();
    void scaptureForCalibration();
    void calibration();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
