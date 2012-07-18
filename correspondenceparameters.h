#ifndef CORRESPONDENCEPARAMETERS_H
#define CORRESPONDENCEPARAMETERS_H

#include "fileutils.h"
#include "opencv_headers.h"

class CorrespondenceParameters
{
public:
    CorrespondenceParameters();
    void setBMState(CvStereoBMState* BMState);

private:
    CvStereoBMState* m_BMState;
};

#endif // CORRESPONDENCEPARAMETERS_H
