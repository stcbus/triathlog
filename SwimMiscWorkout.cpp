#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimMiscWorkout.h"


CSwimMiscWorkout::CSwimMiscWorkout(void)
{
}


CSwimMiscWorkout::~CSwimMiscWorkout(void)
{
}


void CSwimMiscWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimMiscWorkout::GetType(void) const
{
    return SWIMTYPE_OTHER;
}


double CSwimMiscWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimMiscWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimMiscWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimMiscWorkout::SetSpecialSeconds called");
}


void CSwimMiscWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimMiscWorkout::SetSpecialMiles called");
}