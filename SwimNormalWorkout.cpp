#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimNormalWorkout.h"


CSwimNormalWorkout::CSwimNormalWorkout(void)
{
}


CSwimNormalWorkout::~CSwimNormalWorkout(void)
{
}


void CSwimNormalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimNormalWorkout::GetType(void) const
{
    return SWIMTYPE_NORMAL;
}


double CSwimNormalWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimNormalWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimNormalWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimNormalWorkout::SetSpecialSeconds called");
}


void CSwimNormalWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimNormalWorkout::SetSpecialMiles called");
}