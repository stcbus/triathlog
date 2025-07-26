#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimOpenWaterWorkout.h"


CSwimOpenWaterWorkout::CSwimOpenWaterWorkout(void)
{
}


CSwimOpenWaterWorkout::~CSwimOpenWaterWorkout(void)
{
}


void CSwimOpenWaterWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimOpenWaterWorkout::GetType(void) const
{
    return SWIMTYPE_OPENWATER;
}


double CSwimOpenWaterWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CSwimOpenWaterWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


void CSwimOpenWaterWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CSwimOpenWaterWorkout::SetSpecialSeconds called");
}


void CSwimOpenWaterWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CSwimOpenWaterWorkout::SetSpecialMiles called");
}