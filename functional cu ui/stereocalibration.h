#ifndef STEREOCALIBRATION_H
#define STEREOCALIBRATION_H

#include "stereocameraparameters.h"

#include "opencv_headers.h"

class StereoCalibration
{
public:
    StereoCalibration();

    bool initialize(int board_width, int board_height, CvSize image_size);
    int addImages(IplImage* left_image, IplImage*right_image);
    int addImages(const char* left_image, const char* right_image);
    StereoCameraParameters* calibrateCameras( /*, CvMat* _M1 = 0, CvMat* _M2 = 0, CvMat* _D1 = 0, CvMat* _D2 = 0*/);
    void getInfoFromImages();
    void initRectifyBouguet(StereoCameraParameters* stereoCameraParameters);
    // rectify_mode 1 = Harley, 2 = Bouguet

    int rectifyImages(CvArr* leftImage, CvArr* rightImage, CvStereoBMState* BMState);

    void printMatrix(CvMat* i2);

    //TODO getter si setter si variabilele sa fie private
    CvMat* rightImageRectified;
    CvMat* leftImageRectified;

    CvMat  *imageDisparity, *imageDisparityNormalized;
    CvMat* image3D;

private:

    // punctele obiect
    vector<CvPoint3D32f> mVect_object_points;
    // punctele imagine finale
    vector<CvPoint2D32f> mVect_points_final[2];
    // coluturile gasite la un moment dat intr-o pereche de imagini
    vector<CvPoint2D32f> mVect_image_corners[2];
    vector<int> npoints;

    // mapurile de cautare
    CvMat *mx1,*my1,*mx2,*my2;
    CvMat _Q;



    CvSize mS_image_size;

    //latimea patternului in colturi
    int mInt_board_width;
    //inaltimea patternului in colturi
    int mInt_board_height;
    // numarul de patternuri ok pentru calibrare
    int mInt_n_boards;


};

#endif // STEREOCALIBRATION_H
