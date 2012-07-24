#ifndef CORRESPONDENCEPARAMETERS_H
#define CORRESPONDENCEPARAMETERS_H

#include "fileutils.h"
#include "opencv_headers.h"

class CorrespondenceParameters
{
public:

    static const char* PRE_FILTER_CAP_TAG;
    static const char*  PRE_FILTER_SIZE_TAG;
    static const char* SAD_WND_SZ_TAG;
    static const char* NUM_DISP_TAG;
    static const char* MIN_DISP_TAG;
    static const char* UNIQ_TAG;
    static const char* TEXTURE_TAG;
    static const char* SPKL_WND_SZ;
    static const char* SPKL_RANGE;


    CorrespondenceParameters();

    bool saveBMState(const char *filename);
    bool loadBMState(const char* filename);

    void setBMState(CvStereoBMState* BMState);

private:
    CvStereoBMState* m_BMState;
};

#endif // CORRESPONDENCEPARAMETERS_H
