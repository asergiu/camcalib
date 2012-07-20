#include "testcalibrationdialog.h"
#include "ui_testcalibrationdialog.h"


TestCalibrationDialog::TestCalibrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestCalibrationDialog)
{
    ui->setupUi(this);
    this->imageExtension = "";
    this->imagePath = "";
    this->leftImage = "";
    this->rightImage = "";

    this->stereoCamera = 0;
    this->left_image = 0;
    this->right_image = 0;
    this->disparity =0 ;

}

TestCalibrationDialog::~TestCalibrationDialog()
{
    delete ui;

}

void TestCalibrationDialog::browseImagesPath(){

    FileUtils* fileUtils = new FileUtils();

    QString dirName = fileUtils->openDirectory();

    this->imagePath = dirName;

    this->ui->images_path->setText(dirName);

    delete fileUtils;

}

void TestCalibrationDialog::loadRightImage(){

    FileUtils *fileUtils = new FileUtils();

    QString fileName = fileUtils->loadFile(FileUtils::imageExtension);

    this->rightImage = fileName;

    this->ui->right_image_name->setText(fileName);

    delete fileUtils;

}

void TestCalibrationDialog::loadLeftImage(){

    FileUtils *fileUtils = new FileUtils();

    QString fileName = fileUtils->loadFile(FileUtils::imageExtension);

    this->leftImage = fileName;

    this->ui->left_image_name->setText(fileName);

    delete fileUtils;

}

void TestCalibrationDialog::startCalib(){

    int ok = true;
    this->numberOfImages = this->ui->no_imagesSpinBox->value();
    this->imageExtension = this->ui->image_extension->text();
    this->leftImage = this->ui->left_image_name->text();
    this->rightImage = this->ui->right_image_name->text();
    this->imagePath = this->ui->images_path->text();

    if(this->leftImage.compare("")==0)
        ok = false;

    if(this->rightImage.compare("")==0)
        ok = false;

    if(this->imageExtension.compare("")==0)
        ok = false;

    if(this->imagePath.compare("")==0)
        ok = false;

    if(ok){

        IplImage* sampleImage = cvLoadImage(this->leftImage.toLocal8Bit().data());
        stereoCalibration.initialize(this->ui->board_widthSpinBox->value(), this->ui->board_heightSpinBox->value(), cvGetSize(sampleImage));
        cvReleaseImage(&sampleImage);

        for(int i = 1; i <= this->numberOfImages;i++){

            QString left_image_name = imagePath;
            QString right_image_name = imagePath;

            left_image_name.replace(QString("\\"), QString("/") );
            left_image_name.append(tr("/left"));
            left_image_name.append(QString("%1").arg(i));
            left_image_name.append(this->imageExtension);

            right_image_name.replace(QString("\\"), QString("/") );
            right_image_name.append(tr("/right"));
            right_image_name.append(QString("%1").arg(i));
            right_image_name.append(this->imageExtension);


            IplImage *leftImage = 0, *rightImage = 0;

            leftImage = cvLoadImage(left_image_name.toLocal8Bit().data(), 1);
            if(leftImage==NULL){
                fprintf(stderr,"ERROR: Could not load left image!\n");
                exit(1);
            }

            rightImage = cvLoadImage(right_image_name.toLocal8Bit().data(),1);
            if(rightImage==NULL){
                fprintf(stderr,"ERROR: Could not load right image!\n");
                exit(1);
            }

            int corners_ok;

            corners_ok = stereoCalibration.addImages(leftImage, rightImage);

            if(corners_ok==2){

                stereoCalibration.getInfoFromImages();

            }

            cvReleaseImage(&leftImage);
            cvReleaseImage(&rightImage);
        }


        StereoCameraParameters* stereoCameraParameters = stereoCalibration.calibrateCameras();
        stereoCalibration.rectifyBouguet(stereoCameraParameters);

        leftImage.replace(QString("\\"), QString("/"));
        rightImage.replace(QString("\\"), QString("/"));

        IplImage* left_image_rectified = cvLoadImage(this->leftImage.toLocal8Bit().data(),0);
        IplImage* right_image_rectified = cvLoadImage(this->rightImage.toLocal8Bit().data(),0);


        AdjustBMParam* adjustParam = new AdjustBMParam(this);
        adjustParam->setStereoCalibration(&stereoCalibration);
        adjustParam->setLeftImage(left_image_rectified);
        adjustParam->setRightImage(right_image_rectified);

        adjustParam->show();

        //  this->ui->realTimeDisp->setEnabled(true);


    }
    else{

        fprintf(stderr,"ERROR: Please fill in all the mandatory fields!!!\n");
        exit(2);

    }



}


void TestCalibrationDialog::viewDisparityMap(){

    //   this->ui->realTimeDisp->setEnabled(false);

    RTDisparityMapDialog *rtDisparityMapDialog;
    rtDisparityMapDialog =  new RTDisparityMapDialog(this);
    rtDisparityMapDialog->startTimer();

    rtDisparityMapDialog->setStereocalibration(&this->stereoCalibration);

    CvStereoBMState* bmState = cvCreateStereoBMState(0, 64);
    rtDisparityMapDialog->setBMState(bmState);
    rtDisparityMapDialog->setImageSize(this->stereoCalibration.getImageSize());
    rtDisparityMapDialog->show();



}



