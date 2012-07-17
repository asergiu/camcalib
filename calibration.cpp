#include "calibration.h"

Calibration::Calibration()
{
    object_points = 0;
    image_points = 0;
    point_counts = 0;

    successes = 0;
}

void Calibration::initialize(){

    cvReleaseMat(&object_points);
    cvReleaseMat(&image_points);
    cvReleaseMat(&point_counts);

    image_points = cvCreateMat(n_boards* board_w * board_h,2,CV_32FC1);
    object_points = cvCreateMat(n_boards* board_w * board_h,3,CV_32FC1);
    point_counts = cvCreateMat(n_boards ,1,CV_32SC1);

}

int Calibration::findCorners(IplImage *image){


    IplImage *gray_image = cvCreateImage(cvGetSize(image), 8, 1);

    cvCvtColor(image, gray_image, CV_BGR2GRAY);


    CvPoint2D32f* corners = new CvPoint2D32f[board_w*board_h];
    int corner_count;

    int found = cvFindChessboardCorners(gray_image, cvSize(board_w, board_h), corners, &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS | CV_CALIB_CB_NORMALIZE_IMAGE );

    cvFindCornerSubPix(gray_image, corners, corner_count, cvSize(5,5),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

    cvDrawChessboardCorners(image, cvSize(board_w, board_h), corners, corner_count, found);

    cvNamedWindow("Calibration",1);
    cvShowImage("Calibration", image);

    cvWaitKey(0);

    return found;

}

int Calibration::findCorners(const char* filename){

    IplImage* image = cvLoadImage(filename, 1);

    return findCorners(image);
}

void Calibration::getInfoForCalibration(CvPoint2D32f* corners){

    int step = successes*(board_h*board_w);

    for(int i = step,j = 0; j<board_h*board_w; i++, j++){

        CV_MAT_ELEM(*image_points, float,i,0) = corners[j].x;
        CV_MAT_ELEM(*image_points, float,i,1) = corners[j].y;
        CV_MAT_ELEM(*object_points,float,i,0) = j/board_w;

        CV_MAT_ELEM(*object_points,float,i,1) = j%board_w;
        CV_MAT_ELEM(*object_points,float,i,2) = 0.0f;
    }

    CV_MAT_ELEM(*point_counts, int,successes,0) = (board_h*board_w);

    successes++;

    delete corners;

}

CameraParameters* Calibration::calibrateCamera(){

    CvMat* intrinsic_matrix;
    // coef. de distorsiune - matrice 5/1
    CvMat* distorsion_coef;

    // fx = fy = 1
    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;

    // PAS 5 calibrarea propriu zisa

    // se aloca matricile in functie de numarul de board-uri gasite cu success
    CvMat* object_points2 = cvCreateMat( successes*board_w*board_h, 3, CV_32FC1 );
    CvMat* image_points2 = cvCreateMat( successes*board_w*board_h, 2, CV_32FC1 );
    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

    // se transfera punctele in matricile de dimensiunile corespunzatoare
    for( int i = 0; i < successes*board_w*board_h; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
    }

    for( int i=0; i < successes; ++i ){
        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
    }



    double reprojectionError =  cvCalibrateCamera2( object_points2, image_points2, point_counts2, imageSize,
                                                    intrinsic_matrix, distorsion_coef, NULL, NULL,  CV_CALIB_FIX_K3);


    CameraParameters* cameraParameters = new CameraParameters();
    cameraParameters->setCameraMatrix(intrinsic_matrix);
    cameraParameters->setDistortionVector(distorsion_coef);

    cvReleaseMat(&object_points2);
    cvReleaseMat(&point_counts2);
    cvReleaseMat(&image_points2);

    cvReleaseMat(&intrinsic_matrix);
    cvReleaseMat(&distorsion_coef);

    return cameraParameters;

}

IplImage* Calibration::undistortImage(IplImage* image, CameraParameters* cameraParameters){


    IplImage *t = cvCloneImage(image);

    cvUndistort2(t, image, cameraParameters->getCameraMatrix(), cameraParameters->getDistortionCoef());

    cvReleaseImage(&t);

    return image;

}

bool Calibration::validateCornersHorizontally(CvPoint2D32f* corners){

    bool ok = true;
    int x, y;

    for( y = 0; y < board_h; y++ )
    {

        float start_pt = corners[y*board_h].x;

        float direction = start_pt - corners[y*board_h+1].x;


        for( x = 0; x < board_w -1; x++ ){

            if(((corners[board_h*y+x].x-corners[board_h*y+x+1].x)<0)==(direction<0))

                ok = false;
        }
    }

    return ok;
}

bool Calibration::validateCornersVertically(CvPoint2D32f* corners){

    bool ok = true;
    int x, y;

    for( x = 0; x < board_w; x++ )
    {

        float start_pt = corners[x*board_w].y;

        float direction = start_pt - corners[x*board_w+1].y;

        for( y = 0; y < board_h - 1; y++ ){

            if(((corners[board_w*x+y].x-corners[board_w*x+y+1].x)<0)==(direction<0))

                ok = false;
        }
    }

    return ok;
}

bool Calibration::validateCorners(CvPoint2D32f* corners){

    return (validateCornersHorizontally(corners)&validateCornersVertically(corners));
}
