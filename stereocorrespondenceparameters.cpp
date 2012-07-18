#include "correspondenceparameters.h"


CorrespondenceParameters::CorrespondenceParameters()
{
    m_BMState = 0;
}

void CorrespondenceParameters::setBMState(CvStereoBMState* BMState){

    this->m_BMState = BMState;

}
