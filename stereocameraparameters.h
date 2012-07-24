#ifndef STEREOCAMERAPARAMETERS_H
#define STEREOCAMERAPARAMETERS_H

#include "cameraparameters.h"
#include "opencv_headers.h"

class StereoCameraParameters
{
public:

    static const char* FUNDAMENTAL_MAT_TAG;
    static const char* ESSENTIAL_MAT_TAG;
    static const char* TRANSALTION_VECT_TAG;
    static const char* ROTATION_MAT_TAG;
    static const char* CAM1_PARM_TAG;
    static const char* CAM2_PARAM_TAG;

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
    bool loadParameters(const char* fileName);

    CvMat* getFundamentalMatrix();
    CvMat* getRotationMatrix();
    CvMat* getTranslationVector();

private:
    CvMat* fundametal_matrix;
    CvMat* essential_matrix;

    CvMat* rotation_matrix;
    CvMat* transaltion_vector;

    CameraParameters *cameraParameters1;
    CameraParameters *cameraParameters2;



};

#endif // STEREOCAMERAPARAMETERS_H
