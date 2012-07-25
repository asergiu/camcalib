#include "tabbedmenudialog.h"
#include "ui_tabbedmenudialog.h"

TabbedMenuDialog::TabbedMenuDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::TabbedMenuDialog)
{
    m_ui->setupUi(this);
    m_fileUtils = new FileUtils();
    m_imageExtension = "";
    m_imagePath = "";
    m_leftImage = "";
    m_rightImage = "";
    m_left_image = 0;
    m_right_image = 0;
    m_disparity =0 ;
}

TabbedMenuDialog::~TabbedMenuDialog()
{
    delete m_ui;
    delete m_fileUtils;
}

void TabbedMenuDialog::loadCalibParams()
{
    QString path = m_fileUtils->loadFile(FileUtils::xmlExtension);
    m_ui->PathField->setText(path);

    QFile file(path);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

         while (!file.atEnd()) {
             QByteArray line = file.readLine();
             m_ui->textBrowser->append(line);
         }
}

void TabbedMenuDialog::browseImagesPath()
{
    FileUtils* fileUtils = new FileUtils();

    QString dirName = fileUtils->openDirectory();

    m_imagePath = dirName;

    m_ui->images_path->setText(dirName);

    delete fileUtils;
}

void TabbedMenuDialog::loadLeftImage()
{
    FileUtils *fileUtils = new FileUtils();

    QString fileName = fileUtils->loadFile(FileUtils::imageExtension);

    m_leftImage = fileName;

    m_ui->left_image_name->setText(fileName);

    delete fileUtils;
}

void TabbedMenuDialog::loadRightImage()
{
    FileUtils *fileUtils = new FileUtils();

    QString fileName = fileUtils->loadFile(FileUtils::imageExtension);

    m_rightImage = fileName;

    m_ui->right_image_name->setText(fileName);

    delete fileUtils;
}

void TabbedMenuDialog::startCalib()
{
    int ok = true;
    m_numberOfImages = m_ui->no_imagesSpinBox->value();
    m_imageExtension = m_ui->image_extension->text();
    m_leftImage = m_ui->left_image_name->text();
    m_rightImage = m_ui->right_image_name->text();
    m_imagePath = m_ui->images_path->text();

    if(m_leftImage.compare("")==0)
        ok = false;

    if(m_rightImage.compare("")==0)
        ok = false;

    if(m_imageExtension.compare("")==0)
        ok = false;

    if(m_imagePath.compare("")==0)
        ok = false;

    if(ok) {

        IplImage* sampleImage = cvLoadImage(m_leftImage.toLocal8Bit().data());
        m_stereoCalibration.initialize(m_ui->board_widthSpinBox->value(), m_ui->board_heightSpinBox->value(), cvGetSize(sampleImage));
        cvReleaseImage(&sampleImage);

        for(int i = 1; i <= m_numberOfImages;i++) {

            QString left_image_name = m_imagePath;
            QString right_image_name = m_imagePath;

            left_image_name.replace(QString("\\"), QString("/") );
            left_image_name.append(tr("/left"));
            left_image_name.append(QString("%1").arg(i));
            left_image_name.append(m_imageExtension);

            right_image_name.replace(QString("\\"), QString("/") );
            right_image_name.append(tr("/right"));
            right_image_name.append(QString("%1").arg(i));
            right_image_name.append(m_imageExtension);


            IplImage *leftImage = 0, *rightImage = 0;

            leftImage = cvLoadImage(left_image_name.toLocal8Bit().data(), 1);
            if(leftImage==NULL) {
                fprintf(stderr,"ERROR: Could not load left image!\n");
                exit(1);
            }

            rightImage = cvLoadImage(right_image_name.toLocal8Bit().data(),1);
            if(rightImage==NULL) {
                fprintf(stderr,"ERROR: Could not load right image!\n");
                exit(1);
            }

            int corners_ok;

            corners_ok = m_stereoCalibration.addImages(leftImage, rightImage);

            if(corners_ok==2) {

                m_stereoCalibration.getInfoFromImages();

            }

            cvReleaseImage(&leftImage);
            cvReleaseImage(&rightImage);
        }


        StereoCameraParameters* stereoCameraParameters = m_stereoCalibration.calibrateCameras();
        m_stereoCalibration.rectifyBouguet(stereoCameraParameters);

        m_leftImage.replace(QString("\\"), QString("/"));
        m_rightImage.replace(QString("\\"), QString("/"));

        IplImage* left_image_rectified = cvLoadImage(m_leftImage.toLocal8Bit().data(),0);
        IplImage* right_image_rectified = cvLoadImage(m_rightImage.toLocal8Bit().data(),0);


        AdjustBMParam* adjustParam = new AdjustBMParam(this);
        adjustParam->setStereoCalibration(&m_stereoCalibration);
        adjustParam->setLeftImage(left_image_rectified);
        adjustParam->setRightImage(right_image_rectified);

        adjustParam->show();

        m_ui->real_time_disp->setEnabled(true);
    }
    else {

        fprintf(stderr,"ERROR: Please fill in all the mandatory fields!!!\n");
        exit(2);

    }
}

void TabbedMenuDialog::viewDisparityMap()
{
    m_ui->real_time_disp->setEnabled(false);

    RTDisparityMapDialog *rtDisparityMapDialog;
    rtDisparityMapDialog =  new RTDisparityMapDialog(this, this->m_ui->left_camera_index_spinbox->value(), this->m_ui->right_camera_index_spinbox->value());
    rtDisparityMapDialog->startTimer();

    rtDisparityMapDialog->setStereocalibration(&m_stereoCalibration);

    CvStereoBMState* bmState = cvCreateStereoBMState(0, 64);
    rtDisparityMapDialog->setBMState(bmState);
    rtDisparityMapDialog->setImageSize(m_stereoCalibration.getImageSize());
    rtDisparityMapDialog->show();
}
