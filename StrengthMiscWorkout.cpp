#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "StrengthMiscWorkout.h"


CStrengthMiscWorkout::CStrengthMiscWorkout(void)
{
}


CStrengthMiscWorkout::~CStrengthMiscWorkout(void)
{
}


void CStrengthMiscWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutStrength::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CStrengthMiscWorkout::GetType(void) const
{
    return STRENGTHTYPE_OTHER;
}