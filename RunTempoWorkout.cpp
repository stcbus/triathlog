#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunTempoWorkout.h"


CRunTempoWorkout::CRunTempoWorkout(void)
{
}


CRunTempoWorkout::~CRunTempoWorkout(void)
{
}


void CRunTempoWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
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


int CRunTempoWorkout::GetType(void) const
{
    return RUNTYPE_TEMPO;
}


int CRunTempoWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunTempoWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunTempoWorkout::GetSpecialSeconds(void) const
{
    return m_dTempoSeconds;
}


double CRunTempoWorkout::GetSpecialMiles(void) const
{
    return m_dTempoMiles;
}


CShoesRun* CRunTempoWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunTempoWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunTempoWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunTempoWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunTempoWorkout::SetSpecialSeconds(double dSec)
{
    m_dTempoSeconds = dSec;
}


void CRunTempoWorkout::SetSpecialMiles(double dMiles)
{
    m_dTempoMiles = dMiles;
}


void CRunTempoWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunTempoWorkout::SetSpecialShoesRun called");
}


void CRunTempoWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunTempoWorkout::SetCountedOnShoes called");
}