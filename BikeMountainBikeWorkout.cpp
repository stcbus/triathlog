#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeMountainBikeWorkout.h"


CBikeMountainBikeWorkout::CBikeMountainBikeWorkout(void)
{
}


CBikeMountainBikeWorkout::~CBikeMountainBikeWorkout(void)
{
}


void CBikeMountainBikeWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeMountainBikeWorkout::GetType(void) const
{
    return BIKETYPE_MOUNTAINBIKE;
}


int CBikeMountainBikeWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeMountainBikeWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeMountainBikeWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeMountainBikeWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeMountainBikeWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeMountainBikeWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeMountainBikeWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeMountainBikeWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeMountainBikeWorkout::SetSpecialSeconds called");
}


void CBikeMountainBikeWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeMountainBikeWorkout::SetSpecialMiles called");
}


void CBikeMountainBikeWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeMountainBikeWorkout::SetSpecialShoesBike called");
}


void CBikeMountainBikeWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeMountainBikeWorkout::SetCountedOnShoes called");
}


void CBikeMountainBikeWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeMountainBikeWorkout::SetCountedOnBike called");
}