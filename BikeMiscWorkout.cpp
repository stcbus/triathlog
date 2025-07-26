#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeMiscWorkout.h"


CBikeMiscWorkout::CBikeMiscWorkout(void)
{
}


CBikeMiscWorkout::~CBikeMiscWorkout(void)
{
}


void CBikeMiscWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeMiscWorkout::GetType(void) const
{
    return BIKETYPE_OTHER;
}


int CBikeMiscWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeMiscWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeMiscWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeMiscWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeMiscWorkout::IsCountedOnShoes(void) const
{
    return m_fCountOnShoes;
}


bool CBikeMiscWorkout::IsCountedOnBike(void) const
{
    return m_fCountOnBike;
}


void CBikeMiscWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeMiscWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeMiscWorkout::SetSpecialSeconds called");
}


void CBikeMiscWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeMiscWorkout::SetSpecialMiles called");
}


void CBikeMiscWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeMiscWorkout::SetSpecialShoesBike called");
}


void CBikeMiscWorkout::SetCountedOnShoes(bool fCount)
{
    m_fCountOnShoes = fCount;
}


void CBikeMiscWorkout::SetCountedOnBike(bool fCount)
{
    m_fCountOnBike = fCount;
}