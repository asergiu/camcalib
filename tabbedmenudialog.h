#ifndef TABBEDMENUDIALOG_H
#define TABBEDMENUDIALOG_H

#include <QDialog>
#include "fileutils.h"
#include "stereocalibration.h"
#include "adjustbmparam.h"
#include"stereocamera.h"
#include "rtdisparitymapdialog.h"

namespace Ui {
    class TabbedMenuDialog;
}

class TabbedMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabbedMenuDialog(QWidget *parent = 0);
    ~TabbedMenuDialog();

private:
    Ui::TabbedMenuDialog *m_ui;
    FileUtils *m_fileUtils;
    QString m_imagePath;
    QString m_imageExtension;
    int m_numberOfImages;
    QString m_leftImage;
    QString m_rightImage;
    StereoCalibration m_stereoCalibration;
    IplImage* m_left_image;
    IplImage* m_right_image;
    CvMat* m_disparity;


private slots:
    void loadCalibParams();
    void browseImagesPath();
    void loadLeftImage();
    void loadRightImage();
    void startCalib();
    void viewDisparityMap();
};

#endif // TABBEDMENUDIALOG_H
