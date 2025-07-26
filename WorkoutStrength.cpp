#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "WorkoutStrength.h"


CWorkoutStrength::CWorkoutStrength(void)
{
}


CWorkoutStrength::~CWorkoutStrength(void)
{
}


void CWorkoutStrength::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{ 
    CWorkout::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CWorkoutStrength::GetActivityType(void) const
{
    return ACTIVITY_STRENGTH;
}


double CWorkoutStrength::GetMiles(void) const
{
    return 0.0;
}


CLocationSwim* CWorkoutStrength::GetLocationSwim(void) const
{
    return NULL;
}


CLocationRun* CWorkoutStrength::GetLocationRun(void) const
{
    return NULL;
}


CLocationBike* CWorkoutStrength::GetLocationBike(void) const
{
    return NULL;
}


CLocationStrength* CWorkoutStrength::GetLocationStrength(void) const
{
    return m_pLocStrength;
}


CCourseSwim* CWorkoutStrength::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CWorkoutStrength::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CWorkoutStrength::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CWorkoutStrength::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CWorkoutStrength::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CWorkoutStrength::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CWorkoutStrength::GetShoesBike(void) const
{
    return NULL;
}


int CWorkoutStrength::GetWind(void) const
{
    return WIND_NONE;
}


int CWorkoutStrength::GetRacePosition(void) const
{
    return 0;
}


int CWorkoutStrength::GetRaceNumber(void) const
{
    return 0;
}


double CWorkoutStrength::GetSpecialSeconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CWorkoutStrength::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CWorkoutStrength::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CWorkoutStrength::IsCountedOnShoes(void) const
{
    return false;
}


bool CWorkoutStrength::IsCountedOnBike(void) const
{
    return false;
}


CBike* CWorkoutStrength::GetBike(void) const
{
    return NULL;
}


int CWorkoutStrength::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CWorkoutStrength::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg1Miles(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg2Miles(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg3Miles(void) const
{
    return 0.0;
}


int CWorkoutStrength::GetLeg1Temperature(void) const
{
    return 0;
}


int CWorkoutStrength::GetLeg2Temperature(void) const
{
    return 0;
}


int CWorkoutStrength::GetLeg3Temperature(void) const
{
    return 0;
}


int CWorkoutStrength::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutStrength::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutStrength::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutStrength::GetLeg1HR(void) const
{
    return 0;
}


int CWorkoutStrength::GetLeg2HR(void) const
{
    return 0;
}


int CWorkoutStrength::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CWorkoutStrength::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutStrength::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutStrength::GetLeg3Shoes(void) const
{
    return NULL;
}


double CWorkoutStrength::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutStrength::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CWorkoutStrength::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutStrength::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutStrength::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CWorkoutStrength::SetMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetMiles called");
}


void CWorkoutStrength::SetLocationSwim(CLocationSwim* pLoc)
{
    CUtil::Fatal("CWorkoutStrength::SetLocationSwim called");
}


void CWorkoutStrength::SetLocationBike(CLocationBike* pLoc)
{
    CUtil::Fatal("CWorkoutStrength::SetLocationBike called");
}


void CWorkoutStrength::SetLocationRun(CLocationRun* pLoc)
{
    CUtil::Fatal("CWorkoutStrength::SetLocationRun called");
}


void CWorkoutStrength::SetLocationStrength(CLocationStrength* pLoc)
{
    m_pLocStrength = pLoc;
}


void CWorkoutStrength::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CWorkoutStrength::SetCourseSwim called");
}


void CWorkoutStrength::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CWorkoutStrength::SetCourseRun called");
}


void CWorkoutStrength::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CWorkoutStrength::SetCourseBike called");
}


void CWorkoutStrength::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CWorkoutStrength::SetCourseDuathlon called");
}


void CWorkoutStrength::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CWorkoutStrength::SetCourseTriathlon called");
}


void CWorkoutStrength::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetShoesRun called");
}


void CWorkoutStrength::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetShoesBike called");
}


void CWorkoutStrength::SetWind(int nWind)
{
    CUtil::Fatal("CWorkoutStrength::SetWind called");
}


void CWorkoutStrength::SetRacePosition(int nPlace)
{
    CUtil::Fatal("CWorkoutStrength::SetRacePosition called");
}


void CWorkoutStrength::SetRaceNumber(int nNum)
{
    CUtil::Fatal("CWorkoutStrength::SetRaceNumber called");
}


void CWorkoutStrength::SetSpecialSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetSpecialSeconds called");
}


void CWorkoutStrength::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetSpecialMiles called");
}


void CWorkoutStrength::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetSpecialShoesRun called");
}


void CWorkoutStrength::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetSpecialShoesBike called");
}



void CWorkoutStrength::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CWorkoutStrength::SetCountedOnShoes called");
}


void CWorkoutStrength::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CWorkoutStrength::SetCountedOnBike called");
}


void CWorkoutStrength::SetBike(CBike* pBike)
{
    CUtil::Fatal("CWorkoutStrength::SetBike called");
}



void CWorkoutStrength::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CWorkoutStrength::SetChoppiness called");
}



void CWorkoutStrength::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::Transition1Seconds called");
}


void CWorkoutStrength::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::Transition2Seconds called");
}


void CWorkoutStrength::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1Seconds called");
}


void CWorkoutStrength::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2Seconds called");
}


void CWorkoutStrength::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3Seconds called");
}


void CWorkoutStrength::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1Miles called");
}


void CWorkoutStrength::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2Miles called");
}


void CWorkoutStrength::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3Miles called");
}


void CWorkoutStrength::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1Temperature called");
}


void CWorkoutStrength::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2Temperature called");
}


void CWorkoutStrength::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3Temperature called");
}


void CWorkoutStrength::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1Wind called");
}


void CWorkoutStrength::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2Wind called");
}


void CWorkoutStrength::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3Wind called");
}


void CWorkoutStrength::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1HR called");
}


void CWorkoutStrength::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2HR called");
}


void CWorkoutStrength::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3HR called");
}


void CWorkoutStrength::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1Shoes called");
}


void CWorkoutStrength::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2Shoes called");
}


void CWorkoutStrength::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3Shoes called");
}


void CWorkoutStrength::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1RaceSeconds called");
}


void CWorkoutStrength::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2RaceSeconds called");
}


void CWorkoutStrength::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3RaceSeconds called");
}


void CWorkoutStrength::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1RaceMiles called");
}


void CWorkoutStrength::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2RaceMiles called");
}


void CWorkoutStrength::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3RaceMiles called");
}


void CWorkoutStrength::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg1RaceShoes called");
}


void CWorkoutStrength::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg2RaceShoes called");
}


void CWorkoutStrength::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutStrength::SetLeg3RaceShoes called");
}