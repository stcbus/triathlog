#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeNormalWorkout.h"


CBikeNormalWorkout::CBikeNormalWorkout(void)
{
}


CBikeNormalWorkout::~CBikeNormalWorkout(void)
{
}


void CBikeNormalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeNormalWorkout::GetType(void) const
{
    return BIKETYPE_NORMAL;
}


int CBikeNormalWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeNormalWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeNormalWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeNormalWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeNormalWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeNormalWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeNormalWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeNormalWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeNormalWorkout::SetSpecialSeconds called");
}


void CBikeNormalWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeNormalWorkout::SetSpecialMiles called");
}


void CBikeNormalWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeNormalWorkout::SetSpecialShoesBike called");
}


void CBikeNormalWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeNormalWorkout::SetCountedOnShoes called");
}


void CBikeNormalWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeNormalWorkout::SetCountedOnBike called");
}