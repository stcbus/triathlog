#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeHardWorkout.h"


CBikeHardWorkout::CBikeHardWorkout(void)
{
}


CBikeHardWorkout::~CBikeHardWorkout(void)
{
}


void CBikeHardWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeHardWorkout::GetType(void) const
{
    return BIKETYPE_HARD;
}


int CBikeHardWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeHardWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeHardWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeHardWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeHardWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeHardWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeHardWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeHardWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeHardWorkout::SetSpecialSeconds called");
}


void CBikeHardWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeHardWorkout::SetSpecialMiles called");
}


void CBikeHardWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeHardWorkout::SetSpecialShoesBike called");
}


void CBikeHardWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeHardWorkout::SetCountedOnShoes called");
}


void CBikeHardWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeHardWorkout::SetCountedOnBike called");
}