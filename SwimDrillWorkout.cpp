#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimDrillWorkout.h"


CSwimDrillWorkout::CSwimDrillWorkout(void)
{
}


CSwimDrillWorkout::~CSwimDrillWorkout(void)
{
}


void CSwimDrillWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimDrillWorkout::GetType(void) const
{
    return SWIMTYPE_DRILLS;
}


double CSwimDrillWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimDrillWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimDrillWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimDrillWorkout::SetSpecialSeconds called");
}


void CSwimDrillWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimDrillWorkout::SetSpecialMiles called");
}