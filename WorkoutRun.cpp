#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "WorkoutRun.h"


CWorkoutRun::CWorkoutRun(void)
{
}


CWorkoutRun::~CWorkoutRun(void)
{
}


void CWorkoutRun::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetMiles()));
    
    CWorkout::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CWorkoutRun::GetActivityType(void) const
{
    return ACTIVITY_RUNNING;
}


double CWorkoutRun::GetMiles(void) const
{
    return m_dMiles;
}


CLocationSwim* CWorkoutRun::GetLocationSwim(void) const
{
    return NULL;
}


CLocationRun* CWorkoutRun::GetLocationRun(void) const
{
    return m_pLocRun;
}


CLocationBike* CWorkoutRun::GetLocationBike(void) const
{
    return NULL;
}


CLocationStrength* CWorkoutRun::GetLocationStrength(void) const
{
    return NULL;
}


CCourseSwim* CWorkoutRun::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CWorkoutRun::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CWorkoutRun::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CWorkoutRun::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CWorkoutRun::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesBike* CWorkoutRun::GetShoesBike(void) const
{
    return NULL;
}


int CWorkoutRun::GetRacePosition(void) const
{
    return 0;
}


int CWorkoutRun::GetRaceNumber(void) const
{
    return 0;
}


CShoesBike* CWorkoutRun::GetSpecialShoesBike(void) const
{
    return NULL;
}


bool CWorkoutRun::IsCountedOnBike(void) const
{
    return false;
}


CBike* CWorkoutRun::GetBike(void) const
{
    return NULL;
}


int CWorkoutRun::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CWorkoutRun::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg1Miles(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg2Miles(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg3Miles(void) const
{
    return 0.0;
}


int CWorkoutRun::GetLeg1Temperature(void) const
{
    return 0;
}


int CWorkoutRun::GetLeg2Temperature(void) const
{
    return 0;
}


int CWorkoutRun::GetLeg3Temperature(void) const
{
    return 0;
}


int CWorkoutRun::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutRun::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutRun::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutRun::GetLeg1HR(void) const
{
    return 0;
}


int CWorkoutRun::GetLeg2HR(void) const
{
    return 0;
}


int CWorkoutRun::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CWorkoutRun::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutRun::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutRun::GetLeg3Shoes(void) const
{
    return NULL;
}


double CWorkoutRun::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutRun::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CWorkoutRun::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutRun::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutRun::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CWorkoutRun::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CWorkoutRun::SetLocationSwim(CLocationSwim* pLoc)
{
    CUtil::Fatal("CWorkoutRun::SetLocationSwim called");
}


void CWorkoutRun::SetLocationBike(CLocationBike* pLoc)
{
    CUtil::Fatal("CWorkoutRun::SetLocationBike called");
}


void CWorkoutRun::SetLocationRun(CLocationRun* pLoc)
{
    m_pLocRun = pLoc;
}


void CWorkoutRun::SetLocationStrength(CLocationStrength* pLoc)
{
    CUtil::Fatal("CWorkoutRun::SetLocationStrength called");
}


void CWorkoutRun::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CWorkoutRun::SetCourseSwim called");
}


void CWorkoutRun::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CWorkoutRun::SetCourseRun called");
}


void CWorkoutRun::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CWorkoutRun::SetCourseBike called");
}


void CWorkoutRun::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CWorkoutRun::SetCourseDuathlon called");
}


void CWorkoutRun::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CWorkoutRun::SetCourseTriathlon called");
}


void CWorkoutRun::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetShoesBike called");
}


void CWorkoutRun::SetRacePosition(int nPlace)
{
    CUtil::Fatal("CWorkoutRun::SetRacePosition called");
}


void CWorkoutRun::SetRaceNumber(int nNum)
{
    CUtil::Fatal("CWorkoutRun::SetRaceNumber called");
}


void CWorkoutRun::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetSpecialShoesBike called");
}


void CWorkoutRun::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CWorkoutRun::SetCountedOnBike called");
}


void CWorkoutRun::SetBike(CBike* pBike)
{
    CUtil::Fatal("CWorkoutRun::SetBike called");
}


void CWorkoutRun::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CWorkoutRun::SetChoppiness called");
}


void CWorkoutRun::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::Transition1Seconds called");
}


void CWorkoutRun::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::Transition2Seconds called");
}


void CWorkoutRun::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1Seconds called");
}


void CWorkoutRun::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2Seconds called");
}


void CWorkoutRun::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3Seconds called");
}


void CWorkoutRun::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1Miles called");
}


void CWorkoutRun::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2Miles called");
}


void CWorkoutRun::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3Miles called");
}


void CWorkoutRun::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1Temperature called");
}


void CWorkoutRun::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2Temperature called");
}


void CWorkoutRun::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3Temperature called");
}


void CWorkoutRun::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1Wind called");
}


void CWorkoutRun::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2Wind called");
}


void CWorkoutRun::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3Wind called");
}


void CWorkoutRun::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1HR called");
}


void CWorkoutRun::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2HR called");
}


void CWorkoutRun::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3HR called");
}


void CWorkoutRun::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1Shoes called");
}


void CWorkoutRun::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2Shoes called");
}


void CWorkoutRun::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3Shoes called");
}


void CWorkoutRun::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1RaceSeconds called");
}


void CWorkoutRun::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2RaceSeconds called");
}


void CWorkoutRun::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3RaceSeconds called");
}


void CWorkoutRun::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1RaceMiles called");
}


void CWorkoutRun::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2RaceMiles called");
}


void CWorkoutRun::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3RaceMiles called");
}


void CWorkoutRun::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg1RaceShoes called");
}


void CWorkoutRun::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg2RaceShoes called");
}


void CWorkoutRun::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutRun::SetLeg3RaceShoes called");
}