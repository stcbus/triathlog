#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeHillWorkout.h"


CBikeHillWorkout::CBikeHillWorkout(void)
{
}


CBikeHillWorkout::~CBikeHillWorkout(void)
{
}


void CBikeHillWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetSpecialMiles(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetSpecialMiles()));

    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}

int CBikeHillWorkout::GetType(void) const
{
    return BIKETYPE_HILLS;
}


int CBikeHillWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeHillWorkout::GetSpecialSeconds(void) const
{
    return m_dHillSeconds;
}


double CBikeHillWorkout::GetSpecialMiles(void) const
{
    return m_dHillMiles;
}


CShoesBike* CBikeHillWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeHillWorkout::IsCountedOnBike(void) const
{
    return true;
}


bool CBikeHillWorkout::IsCountedOnShoes(void) const
{
    return true;
}


void CBikeHillWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeHillWorkout::SetSpecialSeconds(double dSec)
{
    m_dHillSeconds = dSec;
}


void CBikeHillWorkout::SetSpecialMiles(double dMiles)
{
    m_dHillMiles = dMiles;
}


void CBikeHillWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeHillWorkout::SetSpecialShoesBike called");
}


void CBikeHillWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeHillWorkout::SetCountedOnShoes called");
}


void CBikeHillWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeHillWorkout::SetCountedOnBike called");
}