#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "WorkoutRace.h"


CWorkoutRace::CWorkoutRace(void)
{
}


CWorkoutRace::~CWorkoutRace(void)
{
}


void CWorkoutRace::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{  
    CWorkout::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CWorkoutRace::GetActivityType(void) const
{
    return ACTIVITY_RACE;
}


CLocationSwim* CWorkoutRace::GetLocationSwim(void) const
{
    return NULL;
}


CLocationRun* CWorkoutRace::GetLocationRun(void) const
{
    return NULL;
}


CLocationBike* CWorkoutRace::GetLocationBike(void) const
{
    return NULL;
}


CLocationStrength* CWorkoutRace::GetLocationStrength(void) const
{
    return NULL;
}


int CWorkoutRace::GetRacePosition(void) const
{
    return m_nPlace;
}


int CWorkoutRace::GetRaceNumber(void) const
{
    return m_nRaceNum;
}


double CWorkoutRace::GetSpecialSeconds(void) const
{
    return m_dRaceSeconds;
}


bool CWorkoutRace::IsCountedOnShoes(void) const
{
    return false;
}


bool CWorkoutRace::IsCountedOnBike(void) const
{
    return false;
}


void CWorkoutRace::SetLocationSwim(CLocationSwim* pLoc)
{
    CUtil::Fatal("CWorkoutRace::SetLocationSwim called");
}


void CWorkoutRace::SetLocationBike(CLocationBike* pLoc)
{
    CUtil::Fatal("CWorkoutRace::SetLocationBike called");
}


void CWorkoutRace::SetLocationRun(CLocationRun* pLoc)
{
    CUtil::Fatal("CWorkoutRace::SetLocationRun called");
}


void CWorkoutRace::SetLocationStrength(CLocationStrength* pLoc)
{
    CUtil::Fatal("CWorkoutRace::SetLocationStrength called");
}


void CWorkoutRace::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CWorkoutRace::SetRaceNumber(int nNum)
{
    m_nRaceNum = nNum;
}


void CWorkoutRace::SetSpecialSeconds(double dSec)
{
    m_dRaceSeconds = dSec;
}


void CWorkoutRace::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CWorkoutRace::SetCountedOnShoes called");
}


void CWorkoutRace::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CWorkoutRace::SetCountedOnBike called");
}