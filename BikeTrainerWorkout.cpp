#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeTrainerWorkout.h"


CBikeTrainerWorkout::CBikeTrainerWorkout(void)
{
}


CBikeTrainerWorkout::~CBikeTrainerWorkout(void)
{
}


void CBikeTrainerWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeTrainerWorkout::GetType(void) const
{
    return BIKETYPE_TRAINER;
}


int CBikeTrainerWorkout::GetWind(void) const
{
    return WIND_NONE;
}


double CBikeTrainerWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeTrainerWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeTrainerWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeTrainerWorkout::IsCountedOnShoes(void) const
{
    return m_fCountOnShoes;
}


bool CBikeTrainerWorkout::IsCountedOnBike(void) const
{
    return m_fCountOnBike;
}


void CBikeTrainerWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CBikeTrainerWorkout::SetWind called");
}


void CBikeTrainerWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeTrainerWorkout::SetSpecialSeconds called");
}


void CBikeTrainerWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeTrainerWorkout::SetSpecialMiles called");
}


void CBikeTrainerWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeTrainerWorkout::SetSpecialShoesBike called");
}


void CBikeTrainerWorkout::SetCountedOnShoes(bool fCount)
{
    m_fCountOnShoes = fCount;
}


void CBikeTrainerWorkout::SetCountedOnBike(bool fCount)
{
    m_fCountOnBike = fCount;
}