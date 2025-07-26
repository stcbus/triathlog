#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "BikeEZWorkout.h"


CBikeEZWorkout::CBikeEZWorkout(void)
{
}


CBikeEZWorkout::~CBikeEZWorkout(void)
{
}


void CBikeEZWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    CWorkoutBike::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CBikeEZWorkout::GetType(void) const
{
    return BIKETYPE_EZ;
}


int CBikeEZWorkout::GetWind(void) const
{
    return m_nWind;
}


double CBikeEZWorkout::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CBikeEZWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CBikeEZWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CBikeEZWorkout::IsCountedOnShoes(void) const
{
    return true;
}


bool CBikeEZWorkout::IsCountedOnBike(void) const
{
    return true;
}


void CBikeEZWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeEZWorkout::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CBikeEZWorkout::SetSpecialSeconds called");
}


void CBikeEZWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CBikeEZWorkout::SetSpecialMiles called");
}


void CBikeEZWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CBikeEZWorkout::SetSpecialShoesBike called");
}


void CBikeEZWorkout::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CBikeEZWorkout::SetCountedOnShoes called");
}


void CBikeEZWorkout::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CBikeEZWorkout::SetCountedOnBike called");
}