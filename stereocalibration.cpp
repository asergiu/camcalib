#include "stereocalibration.h"
#include"stdio.h"

StereoCalibration::StereoCalibration()
{
}

bool StereoCalibration::initialize(int board_width, int board_height, CvSize image_size){

    //dimensiunea tablei de sah (colturi interioare)
    this->mInt_board_height = board_height;
    this->mInt_board_width = board_width;

    //dimensiunea imaginii
    this->mS_image_size = image_size;

    //numarul de table de sah care vor fi folosite in calibrarea
    this->mInt_n_boards = 0;

    //colturile gasite pe o imagine
    mVect_image_corners[0].resize(mInt_board_width*mInt_board_height);
    mVect_image_corners[1].resize(mInt_board_width*mInt_board_height);

    //imaginea stanga si dreapta rectificata
    leftImageRectified = 0;
    rightImageRectified = 0;
    //matricea cu valorile pentru adancime
    image3D = 0;

    //disparitatea pentru imaginile leftImageRectified si rightImageRectified
    imageDisparity = 0;
    //disparitatea normalizata
    imageDisparityNormalized = 0;

    //mapruile pentru remap
    mx1 = my1 = 0;
    mx2 = my2 = 0;

    m_bmState = 0;

    return true;
}

/**
  Se adauga doua imagini pentru a fi folosite in pasul de calibrare.
   -  se cauta colturile tablei de sah pentru fiecare dintre cele doua imagini date ca param
  @param leftImage: imaginea de la camera stanga
  @param  rightImage: imaginea de la camera dreapta
  @return numarul de imagini pentru care s-au gasit toate colturile tablei de sah

  */
int StereoCalibration::addImages(IplImage* left_image, IplImage*right_image){

    IplImage* image[2] = {left_image, right_image};

    int images_detected = 0;
    for(int i = 0; i < 2; i++){

        int corner_count = 0;
        IplImage* grayImage = cvCreateImage(cvGetSize(image[i]), 8, 1);
        cvCvtColor( image[i], grayImage, CV_BGR2GRAY );
        CvSize imageSize =  cvGetSize(image[i]);

        if(imageSize.width != this->mS_image_size.width || imageSize.height != this->mS_image_size.height)
            return -1;

        int found = cvFindChessboardCorners(image[i], cvSize(mInt_board_width, mInt_board_height),&mVect_image_corners[i][0], &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

        if(found && corner_count==mInt_board_width*mInt_board_height){

            cvFindCornerSubPix(grayImage, &mVect_image_corners[i][0], corner_count, cvSize(5,5),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
            // cvDrawChessboardCorners(image[i],  cvSize(mInt_board_width, mInt_board_height),&mVect_image_corners[i][0], corner_count, found);
            images_detected++;

            //cvShowImage("image corners ",image[i]);

            //cvWaitKey(0);
        }

        cvReleaseImage(&grayImage);
    }

    return images_detected;
}

int StereoCalibration::addImages(const char* left_image_name, const char* right_image_name){

    IplImage* left_image = cvLoadImage(left_image_name);
    IplImage* right_image = cvLoadImage(right_image_name);

    return this->addImages(left_image, right_image);

}

/**
  Aceasta metoda se apleaza in cazul in care metoda addImages  (@see addImages(IplImage* left_image, IplImage*right_image)) returneaza valoarea 2 (s-au gasit toate colturile tablei de sah in ambele imagini)
  Se retin informatiile despre coltuilegasit in imagini pentru a fi folosite in pasul de calibrare
  */
void StereoCalibration::getInfoFromImages(){

    for(int i = 0;i < 2; i++){

        mVect_points_final[i].resize((mInt_n_boards+1)*mInt_board_width*mInt_board_height);
        copy( mVect_image_corners[i].begin(), mVect_image_corners[i].end(),  mVect_points_final[i].begin() + mInt_n_boards*mInt_board_width*mInt_board_height);

    }

    mInt_n_boards++;

}

/**
  Aceasta metoda efectueaza procesul de calibrare stereo
  @return  informatiile obtinute in urma pasului de calibrare

  */
StereoCameraParameters* StereoCalibration::calibrateCameras(){

    // M1 camera matrix 1, M2 camera matrix 2, D1 distorsiuni cam 1, D2 distorsiuni cam 2
    // R rotation matrix, T translation vector, E matricea esentiala, F matricea fundamentala
    double M1[3][3], M2[3][3], D1[5], D2[5];
    double R[3][3], T[3], E[3][3], F[3][3];
    CvMat _M1,_M2,_D1,_D2,_R,_T,_E,_F;

    StereoCameraParameters *cameraParameters = new StereoCameraParameters();


    _M1 = cvMat(3, 3, CV_64F, M1 );
    _M2 = cvMat(3, 3, CV_64F, M2 );
    _D1 = cvMat(1, 5, CV_64F, D1 );
    _D2 = cvMat(1, 5, CV_64F, D2 );
    _R = cvMat(3, 3, CV_64F, R );
    _T = cvMat(3, 1, CV_64F, T );
    _E = cvMat(3, 3, CV_64F, E );
    _F = cvMat(3, 3, CV_64F, F );

    npoints.resize(mInt_n_boards, mInt_board_width*mInt_board_height);

    int N = mInt_n_boards*mInt_board_width*mInt_board_height;
    int squareSize = 20;

    mVect_object_points.resize(N);
    for(int i = 0; i < mInt_board_height; i++ )
        for(int j = 0; j < mInt_board_width; j++ )   mVect_object_points[i*mInt_board_width + j] = cvPoint3D32f(i*squareSize, j*squareSize, 0);
    for(int i = 1; i < mInt_n_boards; i++ ) copy( mVect_object_points.begin(), mVect_object_points.begin() + mInt_board_width*mInt_board_height, mVect_object_points.begin() + i*mInt_board_width*mInt_board_height );

    CvMat _objectPoints = cvMat(1, mInt_n_boards*mInt_board_width*mInt_board_height, CV_32FC3, &mVect_object_points[0] );

    CvMat _imagePointsCam1 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[0][0] );
    CvMat _imagePointsCam2 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[1][0] );

    CvMat _npoints = cvMat(1, npoints.size(), CV_32S, &npoints[0] );


    cvSetIdentity(&_M1);
    cvSetIdentity(&_M2);
    cvZero(&_D1);
    cvZero(&_D2);


    double repr  =cvStereoCalibrate( &_objectPoints, &_imagePointsCam1, &_imagePointsCam2, &_npoints,&_M1, &_D1, &_M2, &_D2, mS_image_size, &_R, &_T, NULL, NULL,
                                     cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 100, 1e-5),
                                     CV_CALIB_FIX_K3+CV_CALIB_FIX_ASPECT_RATIO + CV_CALIB_ZERO_TANGENT_DIST /*+ CV_CALIB_SAME_FOCAL_LENGTH*/);

    printf("%f ", repr);

    cvSave("intr.xml", &_M1);

    CameraParameters* camera1Parameters = new CameraParameters();
    CameraParameters* camera2Parameters = new CameraParameters();

    camera1Parameters->setCameraMatrix(&_M1);
    camera1Parameters->setDistortionVector(&_D1);

    camera2Parameters->setCameraMatrix(&_M2);
    camera2Parameters->setDistortionVector(&_D2);

    cameraParameters->setEssentialMatrix(&_E);
    cameraParameters->setFundamentalMat(&_F);
    cameraParameters->setRotationMat(&_R);
    cameraParameters->setTransaltionVect(&_T);

    cameraParameters->setCameraParamaters1(camera1Parameters);
    cameraParameters->setCameraParamaters2(camera2Parameters);


    return cameraParameters;

}

/**
  Aceasta metoda efectueaza rectificarea prin metoda Bouguet.
  @param: stereoCameraParameters informatiile despre sistemul stereo: matricea de rotatie si de translatie dintre camere (obtinute in urma pasului de calibrare stereo)
  */
void StereoCalibration::rectifyBouguet(StereoCameraParameters* stereoCameraParameters){

    CameraParameters* camera1Parameters;
    CameraParameters* camera2Parameters;

    camera1Parameters = stereoCameraParameters->getCamera1Parameters();
    camera2Parameters = stereoCameraParameters->getCamera2Parameters();

    CvMat _imagePointsCam1 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[0][0] );
    CvMat _imagePointsCam2 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[1][0] );

    CvMat* M1 = cvCloneMat(camera1Parameters->getCameraMatrix());
    CvMat* M2 = cvCloneMat(camera2Parameters->getCameraMatrix());

    CvMat* D1 = cvCloneMat(camera1Parameters->getDistortionCoef());
    CvMat* D2 = cvCloneMat(camera2Parameters->getDistortionCoef());


    cvUndistortPoints( &_imagePointsCam1, &_imagePointsCam1, M1 , D1, 0, M1);
    cvUndistortPoints( &_imagePointsCam2, &_imagePointsCam2, M2, D2, 0, M2);

    double R1[3][3], R2[3][3];
    CvMat _R1 = cvMat(3, 3, CV_64F, R1);
    CvMat _R2 = cvMat(3, 3, CV_64F, R2);

    double P1[3][4], P2[3][4];
    CvMat _P1 = cvMat(3, 4, CV_64F, P1);
    CvMat _P2 = cvMat(3, 4, CV_64F, P2);

    double Q[4][4];

    _Q = cvMat(4,4, CV_64F, Q);

    cvStereoRectify( M1, M2, D1, D2, mS_image_size, stereoCameraParameters->getRotationMatrix(), stereoCameraParameters->getTranslationVector(),&_R1, &_R2, &_P1, &_P2, &_Q,0/*CV_CALIB_ZERO_DISPARITY*/ );

    cvSave("qmatrix.xml", &_Q);

    cvReleaseMat(&mx1);
    cvReleaseMat(&my1);
    cvReleaseMat(&mx2);
    cvReleaseMat(&my2);

    mx1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    mx2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );


    cvInitUndistortRectifyMap(M1,D1,&_R1,&_P1,mx1,my1);
    cvInitUndistortRectifyMap(M2,D2,&_R2,&_P2,mx2,my2);

}


/**
  Aceasta metoda determina harta cu disparitatile (disparity map) si harta de adancime (depth map) pentru o pereche de imagini de la sistemul stereo
  @param leftImage: imaginea de la camera stanga
  @param rightImage: imaginea de la camera dreapta
  @param BMState: param. utilizati in algoritmul de block matching
  */

int StereoCalibration::computeDisparity(CvArr* leftImage, CvArr* rightImage){

    if(!leftImageRectified)
        leftImageRectified =  cvCreateMat(mS_image_size.height, mS_image_size.width, CV_8U );
    if(!rightImageRectified)
        rightImageRectified =  cvCreateMat(mS_image_size.height, mS_image_size.width, CV_8U );

    if(!imageDisparity) imageDisparity = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_16S );
    if(!imageDisparityNormalized) imageDisparityNormalized = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_8U );
    if(!image3D) image3D = cvCreateMat(mS_image_size.height, mS_image_size.width, CV_32FC3);

    cvRemap(leftImage, leftImageRectified, mx1, my1);
    cvRemap(rightImage, rightImageRectified, mx2, my2);


   // cvFindStereoCorrespondenceBM( leftImageRectified, rightImageRectified, imageDisparity, bmState);

     cvFindStereoCorrespondenceBM( leftImageRectified, rightImageRectified, imageDisparity, m_bmState);

    cvShowImage("image rectififed", leftImageRectified);

    cvNormalize( imageDisparity, imageDisparityNormalized, 0, 256, CV_MINMAX );
    cvShowImage("disparity normalized",imageDisparityNormalized);

    return 0;

}



void StereoCalibration::printMatrix(CvMat* mat){


    for(int row=0; row<mat->rows; row++ ) {
        const float* ptr = (const float*)(mat->data.ptr + row * mat->step);
        for(int col=0; col<mat->cols; col++ ) {
            printf("%f ",*ptr);
        }
        printf("\n");
    }


}


CvSize StereoCalibration::getImageSize(){

    return this->mS_image_size;
}

void StereoCalibration::setBMState(CvStereoBMState* bmState){

    this->m_bmState = bmState;

}

