#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeTimeTrialWorkout.h"


CBikeTimeTrialWorkout::CBikeTimeTrialWorkout(void)
{
}


CBikeTimeTrialWorkout::~CBikeTimeTrialWorkout(void)
{
}


void CBikeTimeTrialWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
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


int CBikeTimeTrialWorkout::GetType(void) const
{
    return BIKETYPE_TIMETRIAL;
}


int CBikeTimeTrialWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeTimeTrialWorkout::GetSpecialSeconds(void) const
{
    return m_dTimeTrialSeconds;
}


double CBikeTimeTrialWorkout::GetSpecialMiles(void) const
{
    return m_dTimeTrialMiles;
}


CShoesBike* CBikeTimeTrialWorkout::GetSpecialShoesBike(void) const
{
    return m_pSpikes;
}


bool CBikeTimeTrialWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeTimeTrialWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeTimeTrialWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeTimeTrialWorkout::SetSpecialSeconds(double dSec)
{
    m_dTimeTrialSeconds = dSec;
}


void CBikeTimeTrialWorkout::SetSpecialMiles(double dMiles)
{
    m_dTimeTrialMiles = dMiles;
}


void CBikeTimeTrialWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    m_pSpikes = pShoes;
}


void CBikeTimeTrialWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeTimeTrialWorkout::SetCountedOnShoes called");
}


void CBikeTimeTrialWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeTimeTrialWorkout::SetCountedOnBike called");
}