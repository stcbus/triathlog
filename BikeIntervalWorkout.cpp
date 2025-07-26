#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeIntervalWorkout.h"


CBikeIntervalWorkout::CBikeIntervalWorkout(void)
{
}


CBikeIntervalWorkout::~CBikeIntervalWorkout(void)
{
}


void CBikeIntervalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetSpecialMiles(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetSpecialMiles()));

    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeIntervalWorkout::GetType(void) const
{
    return BIKETYPE_INTERVALS;
}


int CBikeIntervalWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeIntervalWorkout::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CBikeIntervalWorkout::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


CShoesBike* CBikeIntervalWorkout::GetSpecialShoesBike(void) const
{
    return m_pSpikes;
}


bool CBikeIntervalWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeIntervalWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeIntervalWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeIntervalWorkout::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CBikeIntervalWorkout::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}


void CBikeIntervalWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    m_pSpikes = pShoes;
}


void CBikeIntervalWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeIntervalWorkout::SetCountedOnShoes called");
}


void CBikeIntervalWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeIntervalWorkout::SetCountedOnBike called");
}