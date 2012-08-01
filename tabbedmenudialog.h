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
    void initBMStateTab();
    void enableBMStateGUIComponents();

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
    IplImage *disparityImageColor;
    CvMat* m_disparity;

    ColouredDisparityMap *disparityMapColor;
    ColouredDisparityMap::g2cd_data_t *g2cd_data;


private slots:
    virtual void loadCalibParams();
    virtual void browseImagesPath();
    virtual void loadLeftImage();
    virtual void loadRightImage();
    virtual void startCalib();
    virtual void viewDisparityMap();
    virtual void tryParam();
    virtual void updateFilterSize();
    virtual void updateFilterCap();
    virtual void updateSADWinSz();
    virtual void updateTexture();
    virtual void updateSpeckSz();
    virtual void updateSpeckRange();
    virtual void updateUniq();
    virtual void updateMinDisp();
    virtual void updateMaxDisp();
};

#endif // TABBEDMENUDIALOG_H
