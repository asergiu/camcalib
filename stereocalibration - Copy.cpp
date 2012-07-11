#include "stereocalibration.h"
#include"stdio.h"

StereoCalibration::StereoCalibration()
{
}

bool StereoCalibration::initialize(int board_width, int board_height, CvSize image_size){

    this->mInt_board_height = board_height;
    this->mInt_board_width = board_width;

    this->mS_image_size = image_size;

    this->mInt_n_boards = 0;

    mVect_image_corners[0].resize(mInt_board_width*mInt_board_height);
    mVect_image_corners[1].resize(mInt_board_width*mInt_board_height);

    leftImageRectified = 0;
    rightImageRectified = 0;

    imageDepth = 0;
    imageDepthNormalized = 0;

    mx1 = my1 = 0;
    mx2 = my2 = 0;

    return true;
}

int StereoCalibration::addImages(IplImage* left_image, IplImage*right_image){

    IplImage* image[2] = {left_image, right_image};

    int images_detected = 0;
    for(int i = 0; i < 2; i++){

        int corner_count = 0;
        CvSize imageSize =  cvGetSize(image[i]);

        if(imageSize.width != this->mS_image_size.width || imageSize.height != this->mS_image_size.height)
            return -1;

        int found = cvFindChessboardCorners(image[i], cvSize(mInt_board_width, mInt_board_height),&mVect_image_corners[i][0], &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS | CV_CALIB_CB_NORMALIZE_IMAGE );

        if(found == mInt_board_width*mInt_board_height)

            cvFindCornerSubPix(image[i], &mVect_image_corners[i][0], corner_count, cvSize(5,5),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

        images_detected++;
    }

    return images_detected;
}

int StereoCalibration::addImages(const char* left_image_name, const char* right_image_name){

    IplImage* left_image = cvLoadImage(left_image_name);
    IplImage* right_image = cvLoadImage(right_image_name);

    return this->addImages(left_image, right_image);

}

void StereoCalibration::getInfoFromImages(){

    for(int i = 0;i < 2; i++){

        mVect_points_final[i].resize((mInt_n_boards+1)*mInt_board_width*mInt_board_height);
        copy( mVect_image_corners[i].begin(), mVect_image_corners[i].end(),  mVect_points_final[i].begin() + mInt_n_boards*mInt_board_width*mInt_board_height);



    }

    mInt_n_boards++;

}

StereoCameraParameters* StereoCalibration::calibrateCameras(/*, CvMat* _M1, CvMat* _M2, CvMat* _D1, CvMat* _D2*/){

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


    // cream structura cu punctele din coord lumii reale

    mVect_object_points.resize(mInt_n_boards*mInt_board_width*mInt_board_height);

    //    for(int k = 0; k < mInt_n_boards; k++)
    //        for(int i = 0; i < mInt_board_height; i++)
    //            for(int j = 0; j < mInt_board_height; j++)

    //                mVect_object_points[k*mInt_board_width*mInt_board_height+i*mInt_board_height+j] = cvPoint3D32f(i, j, 0);


    for(int i = 0; i < mInt_board_height; i++)
        for(int j = 0; j < mInt_board_height; j++)
            mVect_object_points[i*mInt_board_height+j] = cvPoint3D32f(i, j, 0);

    for(int i = 0; i < mInt_n_boards; i++)
        copy(mVect_object_points.begin(), mVect_object_points.begin()+mInt_board_width*mInt_board_height,
             mVect_object_points.begin()+i*mInt_board_width*mInt_board_height);

    CvMat _objectPoints = cvMat(1, mInt_n_boards*mInt_board_width*mInt_board_height, CV_32FC3, &mVect_object_points[0] );

    // cream structura cu punctele din spatiul imagine


    CvMat _imagePointsCam1 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[0][0] );
    CvMat _imagePointsCam2 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[1][0] );


    CvMat _npoints = cvMat(1, npoints.size(), CV_32S, &npoints[0] );

    //TODO doar daca M1, D1, M2, D2 data ca param sunt 0

    CvFileStorage* readMatrix1 = cvOpenFileStorage("C:/d.xml", NULL,  CV_STORAGE_READ);
    CvMat* d1 = (CvMat*) cvReadByName(readMatrix1, 0, "distorsion1");
    cvReleaseFileStorage(&readMatrix1);

    readMatrix1 = cvOpenFileStorage("C:/i.xml", NULL,  CV_STORAGE_READ);
    CvMat* i1 = (CvMat*) cvReadByName(readMatrix1, 0, "intrinsics1");
    cvReleaseFileStorage(&readMatrix1);

    for(int i = 0; i < d1->rows; i++) {
        const float* ptr = (const float*)(d1->data.ptr + i * d1->step);
        for(int j=0; j < d1->cols; j++) {
            printf("%f ", *ptr++);
        }
        printf("\n");
    }

    for(int i = 0; i < i1->rows; i++) {
        const float* ptr = (const float*)(i1->data.ptr + i * i1->step);
        for(int j=0; j < i1->cols; j++) {
            printf("%f ", *ptr++);
        }
        printf("\n");
    }

    CvFileStorage* readMatrix2 = cvOpenFileStorage("C:/da.xml", NULL,  CV_STORAGE_READ);
    CvMat* d2 = (CvMat*) cvReadByName(readMatrix2, 0, "distorsion2");
    cvReleaseFileStorage(&readMatrix2);

    readMatrix2 = cvOpenFileStorage("C:/ia.xml", NULL,  CV_STORAGE_READ);
    CvMat* i2 = (CvMat*) cvReadByName(readMatrix2, 0, "intrinsics2");
    cvReleaseFileStorage(&readMatrix2);

    for(int i = 0; i < d2->rows; i++) {
        const float* ptr = (const float*)(d2->data.ptr + i * d2->step);
        for(int j=0; j < d2->cols; j++) {
            printf("%f ", *ptr++);
        }
        printf("\n");
    }

    for(int i = 0; i < i2->rows; i++) {
        const float* ptr = (const float*)(i2->data.ptr + i * i2->step);
        for(int j=0; j < i2->cols; j++) {
            printf("%f ", *ptr++);
        }
        printf("\n");
    }


    cvSetIdentity(&_M1);
    cvSetIdentity(&_M2);
    cvZero(&_D1);
    cvZero(&_D2);


    double reprojError = cvStereoCalibrate( &_objectPoints, &_imagePointsCam1,
                                            &_imagePointsCam2, &_npoints,
                                            // &_M1, &_D1, &_M2, &_D2,
                                            i1, d1, i2, d2,
                                            this->mS_image_size, &_R, &_T, &_E, &_F,
                                            cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 100, 1e-5),
                                            CV_CALIB_FIX_INTRINSIC
                                            );

    CameraParameters* camera1Parameters = new CameraParameters();
    CameraParameters* camera2Parameters = new CameraParameters();

    camera1Parameters->setCameraMatrix(&_M1);
    camera1Parameters->setDistortionVector(&_D1);

    camera2Parameters->setCameraMatrix(&_M2);
    camera2Parameters->setDistortionVector(&_D2);

    camera1Parameters->saveParameters("C:/Users/diana/Desktop/paramCam1.xml");
    camera2Parameters->saveParameters("C:/Users/diana/Desktop/paramCam2.xml");


    cameraParameters->setEssentialMatrix(&_E);
    cameraParameters->setFundamentalMat(&_F);
    cameraParameters->setRotationMat(&_R);
    cameraParameters->setTransaltionVect(&_T);
    cameraParameters->setCameraParamaters1(camera1Parameters);
    cameraParameters->setCameraParamaters2(camera2Parameters);

    cameraParameters->saveParameters("C:/Users/diana/Desktop/paramCameras.xml");

    printf("done. \n");

    return cameraParameters;

}



void StereoCalibration::initRectifyHarley(StereoCameraParameters* stereoCameraParameters){

    //undistort

    CameraParameters* camera1Parameters;
    CameraParameters* camera2Parameters;

    camera1Parameters = stereoCameraParameters->getCamera1Parameters();
    camera2Parameters = stereoCameraParameters->getCamera2Parameters();

    CvMat _imagePointsCam1 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[0][0] );
    CvMat _imagePointsCam2 = cvMat(1, mInt_board_width*mInt_board_height*mInt_n_boards, CV_32FC2, &mVect_points_final[1][0] );

    //    double M1R[3][3], M2R[3][3];

    //    CvMat _M1R = cvMat(3, 3, CV_64F, M1R);
    //    CvMat _M2R = cvMat(3, 3, CV_64F, M2R);

    CvMat* M1 = cvCloneMat(camera1Parameters->getCameraMatrix());
    CvMat* M2 = cvCloneMat(camera2Parameters->getCameraMatrix());

    //    void cvUndistortPoints(const CvMat* src,
    //          CvMat* dst, const CvMat* cameraMatrix,
    //          const CvMat* distCoeffs,
    //          const CvMat* R=NULL,
    //          const CvMat* P=NULL)
    // P – The new camera matrix (3x3) or the new projection matrix (3x4). P1 or P2 , computed by StereoRectify() can be passed here. If the matrix is empty, the identity new camera matrix is used


    cvUndistortPoints( &_imagePointsCam1, &_imagePointsCam1, M1 , camera1Parameters->getDistortionCoef(), 0, M1);
    cvUndistortPoints( &_imagePointsCam2, &_imagePointsCam2, M2, camera2Parameters->getDistortionCoef(), 0, M2);


    double R1[3][3], R2[3][3];
    CvMat _R1 = cvMat(3, 3, CV_64F, R1);
    CvMat _R2 = cvMat(3, 3, CV_64F, R2);


    //rectificare Hartley

    double H1[3][3], H2[3][3], iM[3][3];
    CvMat _H1 = cvMat(3, 3, CV_64F, H1);
    CvMat _H2 = cvMat(3, 3, CV_64F, H2);
    CvMat _iM = cvMat(3, 3, CV_64F, iM);



    cvStereoRectifyUncalibrated(
                &_imagePointsCam1,&_imagePointsCam2, stereoCameraParameters->getFundamentalMatrix(),
                mS_image_size,
                &_H1, &_H2, 5
                );

    //    void cvStereoRectifyUncalibrated(const CvMat* points1,
    //                                     const CvMat* points2,
    //                                     const CvMat* F,
    //                                     CvSize imageSize,
    //                                     CvMat* H1,
    //                                     CvMat* H2,
    //                                     double threshold=5)¶


    cvInvert(M1, &_iM);
    cvMatMul(&_H1, M1, &_R1);
    cvMatMul(&_iM, &_R1, &_R1);
    cvInvert(M2, &_iM);
    cvMatMul(&_H2, M2, &_R2);
    cvMatMul(&_iM, &_R2, &_R2);


    // map pentreu cvRemap
    cvReleaseMat(&mx1);
    cvReleaseMat(&my1);
    cvReleaseMat(&mx2);
    cvReleaseMat(&my2);

    mx1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    mx2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );

    cvInitUndistortRectifyMap(M1,camera1Parameters->getDistortionCoef(),&_R1, M1, mx1, my1);
    cvInitUndistortRectifyMap(M2,camera2Parameters->getDistortionCoef(),&_R2, M2, mx2, my2);

}

void StereoCalibration::initRectifyBouguet(StereoCameraParameters* stereoCameraParameters){

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
    CvMat _Q = cvMat(4,4, CV_64F, Q);

    cvStereoRectify(M1, M2, D1, D2, mS_image_size, stereoCameraParameters->getRotationMatrix(), stereoCameraParameters->getTranslationVector(), &_R1, &_R2, &_P1, &_P2,&_Q,0);

    cvReleaseMat(&mx1);
    cvReleaseMat(&my1);
    cvReleaseMat(&mx2);
    cvReleaseMat(&my2);

    mx1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my1 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    mx2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );
    my2 = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_32F );


    cvInitUndistortRectifyMap(M1, D1, &_R1, &_P1, mx1, my1);
    cvInitUndistortRectifyMap(M2, D2, &_R2, &_P2, mx2, my2);

}

int StereoCalibration::rectifyImages(IplImage* leftImage, IplImage* rightImage, int rectify_mode){

    if(!leftImageRectified)
        leftImageRectified =  cvCreateMat(mS_image_size.height, mS_image_size.width, CV_8U );
    if(!rightImageRectified)
        rightImageRectified =  cvCreateMat(mS_image_size.height, mS_image_size.width, CV_8U );

    if(!imageDepth) imageDepth = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_16S );
    if(!imageDepthNormalized) imageDepthNormalized = cvCreateMat( mS_image_size.height, mS_image_size.width, CV_8U );

    cvRemap(leftImage, leftImageRectified, mx1, my1);
    cvRemap(rightImage, rightImageRectified, mx2, my2);

    CvStereoBMState *BMState = cvCreateStereoBMState();
    BMState->preFilterSize = 41;
    BMState->preFilterCap=31;
    BMState->SADWindowSize=41;
    BMState->minDisparity=-64;
    BMState->numberOfDisparities=128;
    BMState->textureThreshold=10;
    BMState->uniquenessRatio=15;

    cvFindStereoCorrespondenceBM( leftImageRectified, rightImageRectified, imageDepth, BMState);
    cvNormalize( imageDepth, imageDepthNormalized, 0, 256, CV_MINMAX );

    cvReleaseStereoBMState(&BMState);

    return 0;

}


