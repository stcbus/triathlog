#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunEZWorkout.h"


CRunEZWorkout::CRunEZWorkout(void)
{
}


CRunEZWorkout::~CRunEZWorkout(void)
{
}


void CRunEZWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunEZWorkout::GetType(void) const
{
    return RUNTYPE_EZ;
}


int CRunEZWorkout::GetWind(void) const
{
    return m_nWind;
}


CShoesRun* CRunEZWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunEZWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunEZWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunEZWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunEZWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunEZWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunEZWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunEZWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunEZWorkout::SetSpecialSeconds called");
}


void CRunEZWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunEZWorkout::SetSpecialMiles called");
}


void CRunEZWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunEZWorkout::SetSpecialShoesRun called");
}


void CRunEZWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunEZWorkout::SetCountedOnShoes called");
}