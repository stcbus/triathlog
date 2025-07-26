#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "StrengthAbsWorkout.h"


CStrengthAbsWorkout::CStrengthAbsWorkout(void)
{
}


CStrengthAbsWorkout::~CStrengthAbsWorkout(void)
{
}


void CStrengthAbsWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutStrength::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CStrengthAbsWorkout::GetType(void) const
{
    return STRENGTHTYPE_ABS;
}