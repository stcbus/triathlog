#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunIntervalWorkout.h"


CRunIntervalWorkout::CRunIntervalWorkout(void)
{
}


CRunIntervalWorkout::~CRunIntervalWorkout(void)
{
}


void CRunIntervalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetSpecialMiles(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetSpecialMiles()));
    
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunIntervalWorkout::GetType(void) const
{
    return RUNTYPE_INTERVALS;
}


int CRunIntervalWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunIntervalWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunIntervalWorkout::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CRunIntervalWorkout::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


CShoesRun* CRunIntervalWorkout::GetSpecialShoesRun(void) const
{
    return m_pSpikes;
}


bool CRunIntervalWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunIntervalWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunIntervalWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunIntervalWorkout::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CRunIntervalWorkout::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}


void CRunIntervalWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    m_pSpikes = pShoes;
}


void CRunIntervalWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunIntervalWorkout::SetCountedOnShoes called");
}