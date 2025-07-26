#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimHardWorkout.h"


CSwimHardWorkout::CSwimHardWorkout(void)
{
}


CSwimHardWorkout::~CSwimHardWorkout(void)
{
}


void CSwimHardWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimHardWorkout::GetType(void) const
{
    return SWIMTYPE_HARD;
}


double CSwimHardWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimHardWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimHardWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimHardWorkout::SetSpecialSeconds called");
}


void CSwimHardWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimHardWorkout::SetSpecialMiles called");
}