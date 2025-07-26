#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "SwimIntervalWorkout.h"


CSwimIntervalWorkout::CSwimIntervalWorkout(void)
{
}


CSwimIntervalWorkout::~CSwimIntervalWorkout(void)
{
}


void CSwimIntervalWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetSpecialMiles(CUtil::ConvertDistance(nOldDistSwimUnits, nNewDistSwimUnits, GetSpecialMiles()));
    
    CWorkoutSwim::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CSwimIntervalWorkout::GetType(void) const
{
    return SWIMTYPE_INTERVALS;
}


double CSwimIntervalWorkout::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CSwimIntervalWorkout::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


void CSwimIntervalWorkout::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CSwimIntervalWorkout::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}