#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "StrengthWeightsWorkout.h"


CStrengthWeightsWorkout::CStrengthWeightsWorkout(void)
{
}


CStrengthWeightsWorkout::~CStrengthWeightsWorkout(void)
{
}


void CStrengthWeightsWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutStrength::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CStrengthWeightsWorkout::GetType(void) const
{
    return STRENGTHTYPE_WEIGHTS;
}