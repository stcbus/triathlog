#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunTreadmillWorkout.h"


CRunTreadmillWorkout::CRunTreadmillWorkout(void)
{
}


CRunTreadmillWorkout::~CRunTreadmillWorkout(void)
{
}


void CRunTreadmillWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunTreadmillWorkout::GetType(void) const
{
    return RUNTYPE_TREADMILL;
}


int CRunTreadmillWorkout::GetWind(void) const
{
    return WIND_NONE;
}


CShoesRun* CRunTreadmillWorkout::GetShoesRun(void) const
{
    return m_pShoesRun;
}


double CRunTreadmillWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunTreadmillWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunTreadmillWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunTreadmillWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunTreadmillWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoesRun = pShoes;
}


void CRunTreadmillWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CRunTreadmillWorkout::SetWind called");
}


void CRunTreadmillWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunTreadmillWorkout::SetSpecialSeconds called");
}


void CRunTreadmillWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunTreadmillWorkout::SetSpecialMiles called");
}


void CRunTreadmillWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunTreadmillWorkout::SetSpecialShoesRun called");
}


void CRunTreadmillWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunTreadmillWorkout::SetCountedOnShoes called");
}