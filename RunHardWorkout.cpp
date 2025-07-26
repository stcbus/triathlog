#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunHardWorkout.h"


CRunHardWorkout::CRunHardWorkout(void)
{
}


CRunHardWorkout::~CRunHardWorkout(void)
{
}


void CRunHardWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunHardWorkout::GetType(void) const
{
    return RUNTYPE_HARD;
}


int CRunHardWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunHardWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunHardWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunHardWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunHardWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunHardWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunHardWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunHardWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunHardWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunHardWorkout::SetSpecialSeconds called");
}


void CRunHardWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunHardWorkout::SetSpecialMiles called");
}


void CRunHardWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunHardWorkout::SetSpecialShoesRun called");
}


void CRunHardWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunHardWorkout::SetCountedOnShoes called");
}