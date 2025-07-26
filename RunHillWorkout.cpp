#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunHillWorkout.h"


CRunHillWorkout::CRunHillWorkout(void)
{
}


CRunHillWorkout::~CRunHillWorkout(void)
{
}


void CRunHillWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
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


int CRunHillWorkout::GetType(void) const
{
    return RUNTYPE_HILLS;
}


int CRunHillWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunHillWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunHillWorkout::GetSpecialSeconds(void) const
{
    return m_dHillSeconds;
}


double CRunHillWorkout::GetSpecialMiles(void) const
{
    return m_dHillMiles;
}


CShoesRun* CRunHillWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunHillWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunHillWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunHillWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunHillWorkout::SetSpecialSeconds(double dSec)
{
    m_dHillSeconds = dSec;
}


void CRunHillWorkout::SetSpecialMiles(double dMiles)
{
    m_dHillMiles = dMiles;
}


void CRunHillWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunHillWorkout::SetSpecialShoesRun called");
}


void CRunHillWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunHillWorkout::SetCountedOnShoes called");
}