#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "fileutils.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void updateSmallImage();
    ~MainWindow();

public slots:

    virtual void undistort();
    virtual void calibrate();

    virtual void browseParam();
    virtual void saveResults();
    virtual void  loadImage();

    virtual void cornersOk();
    virtual void cornersNotOk();
    virtual void removeImage();
    virtual void loadPatternImages();
    virtual void calibrationAction();
    virtual void undistortionAction();

    virtual void openFindCornersWnd();
    virtual void openUndistortionWnd();

    
private:
    Ui::MainWindow *ui;
    QList<QMdiSubWindow *> wnd;

    QStringList patternImages;

    QGraphicsScene smallImageScene;
    QGraphicsScene imageCornersScene;

    int boardWidth;
    int boardHeight;


};

#endif // MAINWINDOW_H
