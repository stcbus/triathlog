#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RunPoolWorkout.h"


CRunPoolWorkout::CRunPoolWorkout(void)
{
}


CRunPoolWorkout::~CRunPoolWorkout(void)
{
}


void CRunPoolWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutRun::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRunPoolWorkout::GetType(void) const
{
    return RUNTYPE_POOL;
}


int CRunPoolWorkout::GetWind(void) const
{
    return WIND_NONE;
}


CShoesRun* CRunPoolWorkout::GetShoesRun(void) const
{
    return NULL;
}


double CRunPoolWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CRunPoolWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesRun* CRunPoolWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CRunPoolWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CRunPoolWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CRunPoolWorkout::SetWind called");
}


void CRunPoolWorkout::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunPoolWorkout::SetShoesRun called");
}


void CRunPoolWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CRunPoolWorkout::SetSpecialSeconds called");
}


void CRunPoolWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRunPoolWorkout::SetSpecialMiles called");
}


void CRunPoolWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRunPoolWorkout::SetSpecialShoesRun called");
}


void CRunPoolWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CRunPoolWorkout::SetCountedOnShoes called");
}