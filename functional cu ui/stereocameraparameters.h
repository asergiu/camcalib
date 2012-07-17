#ifndef STEREOCAMERAPARAMETERS_H
#define STEREOCAMERAPARAMETERS_H

#include "cameraparameters.h"
#include "opencv_headers.h"

class StereoCameraParameters
{
public:
    StereoCameraParameters();
    ~StereoCameraParameters();

    void setFundamentalMat(CvMat* fundametal_mat);
    void setEssentialMatrix(CvMat* essential_mat);
    void setRotationMat(CvMat* rotation_vect);
    void setTransaltionVect(CvMat* transaltion_vect);

    void setCameraParamaters1(CameraParameters* cam1_param);
    void setCameraParamaters2(CameraParameters* cam2_param);

    CameraParameters* getCamera1Parameters();
    CameraParameters* getCamera2Parameters();

    bool saveParameters(const char* filename);
    bool loadParameters(char* fileName);

    CvMat* getFundamentalMatrix();
    CvMat* getRotationMatrix();
    CvMat* getTranslationVector();

private:
    CvMat* fundametal_matrix;
    CvMat* essential_matrix;

    CvMat* rotation_matrix;
    CvMat* transaltion_vector;

    CvMat* imageDepth;

    CameraParameters *cameraParameters1;
    CameraParameters *cameraParameters2;



};

#endif // STEREOCAMERAPARAMETERS_H
