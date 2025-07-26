#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunNormalWorkout.h"


CRunNormalWorkout::CRunNormalWorkout(void)
{
}


CRunNormalWorkout::~CRunNormalWorkout(void)
{
}


void CRunNormalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunNormalWorkout::GetType(void) const
{
    return RUNTYPE_NORMAL;
}


int CRunNormalWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunNormalWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunNormalWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunNormalWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunNormalWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunNormalWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunNormalWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunNormalWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunNormalWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunNormalWorkout::SetSpecialSeconds called");
}


void CRunNormalWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunNormalWorkout::SetSpecialMiles called");
}


void CRunNormalWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunNormalWorkout::SetSpecialShoesRun called");
}


void CRunNormalWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunNormalWorkout::SetCountedOnShoes called");
}