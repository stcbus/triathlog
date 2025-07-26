#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimEZWorkout.h"


CSwimEZWorkout::CSwimEZWorkout(void)
{
}


CSwimEZWorkout::~CSwimEZWorkout(void)
{
}


void CSwimEZWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimEZWorkout::GetType(void) const
{
    return SWIMTYPE_EZ;
}


double CSwimEZWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimEZWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimEZWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimEZWorkout::SetSpecialSeconds called");
}


void CSwimEZWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimEZWorkout::SetSpecialMiles called");
}