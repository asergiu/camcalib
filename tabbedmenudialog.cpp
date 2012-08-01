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
//        m_stereoCalibration.rectifyBouguet(stereoCameraParameters);
        m_stereoCalibration.rectifyHartley(stereoCameraParameters);

        m_leftImage.replace(QString("\\"), QString("/"));
        m_rightImage.replace(QString("\\"), QString("/"));

        initBMStateTab();

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


/* Methods used for the tab that allows the user to adjust bmstates. */
void TabbedMenuDialog::initBMStateTab() {
    enableBMStateGUIComponents();

    disparityMapColor = new ColouredDisparityMap();

    g2cd_data = (ColouredDisparityMap::g2cd_data_t *) malloc(sizeof(ColouredDisparityMap::g2cd_data_t));

    if (!disparityMapColor->g2cd_calculate_look_up_table (g2cd_data)) {
        fprintf(stderr,"ERROR: Could not precalculate color lookup table.\n");
    }

    disparityImageColor = NULL;
}


void TabbedMenuDialog::enableBMStateGUIComponents() {
    /* labels */
    m_ui->label_19->setEnabled(true);
    m_ui->label_20->setEnabled(true);
    m_ui->label_21->setEnabled(true);
    m_ui->label_22->setEnabled(true);
    m_ui->label_23->setEnabled(true);
    m_ui->label_24->setEnabled(true);
    m_ui->label_25->setEnabled(true);
    m_ui->label_26->setEnabled(true);
    m_ui->label_27->setEnabled(true);

    /* sliders */
    m_ui->preFilterSz->setEnabled(true);
    m_ui->preFilterCap->setEnabled(true);
    m_ui->SADWndSz->setEnabled(true);
    m_ui->textureth->setEnabled(true);
    m_ui->minDisp->setEnabled(true);
    m_ui->numDisp->setEnabled(true);
    m_ui->uniq->setEnabled(true);
    m_ui->speckleWndSz->setEnabled(true);
    m_ui->specklerange->setEnabled(true);

    /* line edits */
    m_ui->pSz->setEnabled(true);
    m_ui->pCap->setEnabled(true);
    m_ui->sadSz->setEnabled(true);
    m_ui->textTh->setEnabled(true);
    m_ui->minDisp_2->setEnabled(true);
    m_ui->numDisp_2->setEnabled(true);
    m_ui->uniqRatio->setEnabled(true);
    m_ui->spkSz->setEnabled(true);
    m_ui->spkRag->setEnabled(true);

    /* button */
    m_ui->saveParamsBtn->setEnabled(true);
}


void TabbedMenuDialog::tryParam(){

    IplImage* leftImageRectified = cvLoadImage(m_leftImage.toLocal8Bit().data(),0);
    IplImage* rightImageRectified = cvLoadImage(m_rightImage.toLocal8Bit().data(),0);

    int preFilterSz = this->m_ui->preFilterSz->value();
    int preFilterCap = this->m_ui->preFilterCap->value();
    int sadWndSz = this->m_ui->SADWndSz->value();
    int minDisp = this->m_ui->minDisp->value();
    int numDisp = 16*(this->m_ui->numDisp->value());
    int texture = this->m_ui->textureth->value();
    int uniquness = this->m_ui->uniq->value();
    int spkWndSz = this->m_ui->speckleWndSz->value();
    int spkRange = this->m_ui->specklerange->value();

    if(sadWndSz%2==0)
        sadWndSz++;
    if(sadWndSz<5)
        sadWndSz = 5;

    if(preFilterSz%2==0)
        preFilterSz++;
    if(preFilterSz<5)
        preFilterSz = 5;



    CvStereoBMState *BMState = cvCreateStereoBMState();
    assert(BMState != 0);
    BMState->preFilterSize=preFilterSz;
    BMState->preFilterCap=preFilterCap;
    BMState->SADWindowSize=sadWndSz;
    BMState->minDisparity= minDisp;
    BMState->numberOfDisparities=numDisp;
    BMState->textureThreshold=texture;		//reduce noise
    BMState->uniquenessRatio=uniquness;
    BMState->speckleWindowSize = spkWndSz;
    BMState->speckleRange = spkRange;

    m_stereoCalibration.setBMState(BMState);
    m_stereoCalibration.computeDisparity(leftImageRectified, rightImageRectified);

    CvMat* pair = cvCreateMat(leftImageRectified->height, rightImageRectified->width*2, CV_8UC3 );
    CvMat part;


    cvGetCols( pair, &part, 0, leftImageRectified->width );
    cvCvtColor( m_stereoCalibration.leftImageRectified, &part, CV_GRAY2BGR );

    cvGetCols( pair, &part, leftImageRectified->width, leftImageRectified->width*2 );
    cvCvtColor( m_stereoCalibration.rightImageRectified, &part, CV_GRAY2BGR);

    for(int j = 0; j < leftImageRectified->height; j += 25 )
        cvLine( pair, cvPoint(0,j), cvPoint(leftImageRectified->width*2,j), CV_RGB(255,0,0));

    cvReleaseImage(&disparityImageColor);
    disparityImageColor = cvCreateImage (cvGetSize(leftImageRectified), IPL_DEPTH_8U, 3);
    if (disparityImageColor == NULL)
    {
        fprintf(stderr,"ERROR: Could not create pseudocolor image.\n");
        exit(2);
    }

    IplImage *img, img_header;
    img = cvGetImage(m_stereoCalibration.imageDisparityNormalized, &img_header);

    disparityMapColor->g2cd_gray_to_chromadepth(img, this->disparityImageColor, this->g2cd_data);

    cvShowImage("disparity coloured", disparityImageColor);

    cvNamedWindow( "rectified", 1 );
    cvShowImage( "rectified", pair );

    cvReleaseImage(&leftImageRectified);
    cvReleaseImage(&rightImageRectified);
    cvReleaseImage(&img);

   // cvReleaseStereoBMState(&BMState);
}


void TabbedMenuDialog::updateFilterSize(){
    int preFilterSz = this->m_ui->preFilterSz->value();
    if(preFilterSz%2==0)
        preFilterSz++;

    this->m_ui->pSz->setText(QString("%1").arg(preFilterSz));
}


void TabbedMenuDialog::updateFilterCap(){
    int preFilterCap = this->m_ui->preFilterCap->value();
    this->m_ui->pCap->setText(QString("%1").arg(preFilterCap));
}


void TabbedMenuDialog::updateSADWinSz(){
    int sadWndSz = this->m_ui->SADWndSz->value();

    if(sadWndSz%2==0)
        sadWndSz++;

    this->m_ui->sadSz->setText(QString("%1").arg(sadWndSz));
}


void TabbedMenuDialog::updateTexture(){
    int texture = this->m_ui->textureth->value();
    this->m_ui->textTh->setText(QString("%1").arg(texture));
}


void TabbedMenuDialog::updateSpeckSz(){
    int spkWndSz = this->m_ui->speckleWndSz->value();
    this->m_ui->spkSz->setText(QString("%1").arg(spkWndSz));
}


void TabbedMenuDialog::updateSpeckRange(){
    int spkRange = this->m_ui->specklerange->value();
    this->m_ui->spkRag->setText(QString("%1").arg(spkRange));
}


void TabbedMenuDialog::updateUniq(){
    int uniquness = this->m_ui->uniq->value();
    this->m_ui->uniqRatio->setText(QString("%1").arg(uniquness));
}


void  TabbedMenuDialog::updateMinDisp(){
    int minDisp = this->m_ui->minDisp->value();
    this->m_ui->minDisp_2->setText(QString("%1").arg(minDisp));
}


void TabbedMenuDialog::updateMaxDisp(){
    int numDisp = 16* this->m_ui->numDisp->value();
    this->m_ui->numDisp_2->setText(QString("%1").arg(numDisp));
}
