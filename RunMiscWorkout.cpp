#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunMiscWorkout.h"


CRunMiscWorkout::CRunMiscWorkout(void)
{
}


CRunMiscWorkout::~CRunMiscWorkout(void)
{
}


void CRunMiscWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunMiscWorkout::GetType(void) const
{
    return RUNTYPE_OTHER;
}


int CRunMiscWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunMiscWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunMiscWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunMiscWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunMiscWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunMiscWorkout::IsCountedOnShoes(void) const
{
    return m_fCountOnShoes;
}


void CRunMiscWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunMiscWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunMiscWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunMiscWorkout::SetSpecialSeconds called");
}


void CRunMiscWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunMiscWorkout::SetSpecialMiles called");
}


void CRunMiscWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunMiscWorkout::SetSpecialShoesRun called");
}


void CRunMiscWorkout::SetCountedOnShoes(bool fCount)
{
    m_fCountOnShoes = fCount;
}