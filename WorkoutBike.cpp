#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "WorkoutBike.h"


CWorkoutBike::CWorkoutBike(void)
{
}


CWorkoutBike::~CWorkoutBike(void)
{
}


void CWorkoutBike::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetMiles()));
    
    CWorkout::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CWorkoutBike::GetActivityType(void) const
{
    return ACTIVITY_BIKING;
}


double CWorkoutBike::GetMiles(void) const
{
    return m_dMiles;
}


CLocationSwim* CWorkoutBike::GetLocationSwim(void) const
{
    return NULL;
}


CLocationRun* CWorkoutBike::GetLocationRun(void) const
{
    return NULL;
}


CLocationBike* CWorkoutBike::GetLocationBike(void) const
{
    return m_pLocBike;
}


CLocationStrength* CWorkoutBike::GetLocationStrength(void) const
{
    return NULL;
}


CCourseSwim* CWorkoutBike::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CWorkoutBike::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CWorkoutBike::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CWorkoutBike::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CWorkoutBike::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CWorkoutBike::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CWorkoutBike::GetShoesBike(void) const
{
    return m_pShoesBike;
}


int CWorkoutBike::GetRacePosition(void) const
{
    return 0;
}


int CWorkoutBike::GetRaceNumber(void) const
{
    return 0;
}


CShoesRun* CWorkoutBike::GetSpecialShoesRun(void) const
{
    return NULL;
}


CBike* CWorkoutBike::GetBike(void) const
{
    return m_pBike;
}


int CWorkoutBike::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CWorkoutBike::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg1Miles(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg2Miles(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg3Miles(void) const
{
    return 0.0;
}


int CWorkoutBike::GetLeg1Temperature(void) const
{
    return 0;
}


int CWorkoutBike::GetLeg2Temperature(void) const
{
    return 0;
}


int CWorkoutBike::GetLeg3Temperature(void) const
{
    return 0;
}


int CWorkoutBike::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutBike::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutBike::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutBike::GetLeg1HR(void) const
{
    return 0;
}


int CWorkoutBike::GetLeg2HR(void) const
{
    return 0;
}


int CWorkoutBike::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CWorkoutBike::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutBike::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutBike::GetLeg3Shoes(void) const
{
    return NULL;
}


double CWorkoutBike::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutBike::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CWorkoutBike::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutBike::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutBike::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CWorkoutBike::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CWorkoutBike::SetLocationSwim(CLocationSwim* pLoc)
{
    CUtil::Fatal("CWorkoutBike::SetLocationSwim called");
}


void CWorkoutBike::SetLocationBike(CLocationBike* pLoc)
{
    m_pLocBike = pLoc;
}


void CWorkoutBike::SetLocationRun(CLocationRun* pLoc)
{
    CUtil::Fatal("CWorkoutBike::SetLocationRun called");
}


void CWorkoutBike::SetLocationStrength(CLocationStrength* pLoc)
{
    CUtil::Fatal("CWorkoutBike::SetLocationStrength called");
}


void CWorkoutBike::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CWorkoutBike::SetCourseSwim called");
}


void CWorkoutBike::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CWorkoutBike::SetCourseRun called");
}


void CWorkoutBike::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CWorkoutBike::SetCourseBike called");
}


void CWorkoutBike::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CWorkoutBike::SetCourseDuathlon called");
}


void CWorkoutBike::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CWorkoutBike::SetCourseTriathlon called");
}


void CWorkoutBike::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetShoesRun called");
}


void CWorkoutBike::SetShoesBike(CShoesBike* pShoes)
{
    m_pShoesBike = pShoes;
}


void CWorkoutBike::SetRacePosition(int nPlace)
{
    CUtil::Fatal("CWorkoutBike::SetRacePosition called");
}


void CWorkoutBike::SetRaceNumber(int nNum)
{
    CUtil::Fatal("CWorkoutBike::SetRaceNumber called");
}


void CWorkoutBike::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetSpecialShoesRun called");
}


void CWorkoutBike::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CWorkoutBike::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CWorkoutBike::SetChoppiness called");
}


void CWorkoutBike::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::Transition1Seconds called");
}


void CWorkoutBike::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::Transition2Seconds called");
}


void CWorkoutBike::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1Seconds called");
}


void CWorkoutBike::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2Seconds called");
}


void CWorkoutBike::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3Seconds called");
}


void CWorkoutBike::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1Miles called");
}


void CWorkoutBike::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2Miles called");
}


void CWorkoutBike::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3Miles called");
}


void CWorkoutBike::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1Temperature called");
}


void CWorkoutBike::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2Temperature called");
}


void CWorkoutBike::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3Temperature called");
}


void CWorkoutBike::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1Wind called");
}


void CWorkoutBike::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2Wind called");
}


void CWorkoutBike::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3Wind called");
}


void CWorkoutBike::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1HR called");
}


void CWorkoutBike::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2HR called");
}


void CWorkoutBike::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3HR called");
}


void CWorkoutBike::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1Shoes called");
}


void CWorkoutBike::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2Shoes called");
}


void CWorkoutBike::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3Shoes called");
}


void CWorkoutBike::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1RaceSeconds called");
}


void CWorkoutBike::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2RaceSeconds called");
}


void CWorkoutBike::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3RaceSeconds called");
}


void CWorkoutBike::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1RaceMiles called");
}


void CWorkoutBike::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2RaceMiles called");
}


void CWorkoutBike::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3RaceMiles called");
}


void CWorkoutBike::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg1RaceShoes called");
}


void CWorkoutBike::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg2RaceShoes called");
}


void CWorkoutBike::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutBike::SetLeg3RaceShoes called");
}