#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "WorkoutSwim.h"


CWorkoutSwim::CWorkoutSwim(void)
{
}


CWorkoutSwim::~CWorkoutSwim(void)
{
}


void CWorkoutSwim::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistSwimUnits, nNewDistSwimUnits, GetMiles()));
    
    CWorkout::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CWorkoutSwim::GetActivityType(void) const
{
    return ACTIVITY_SWIMMING;
}


double CWorkoutSwim::GetMiles(void) const
{
    return m_dMiles;
}


CLocationSwim* CWorkoutSwim::GetLocationSwim(void) const
{
    return m_pLocSwim;
}


CLocationRun* CWorkoutSwim::GetLocationRun(void) const
{
    return NULL;
}


CLocationBike* CWorkoutSwim::GetLocationBike(void) const
{
    return NULL;
}


CLocationStrength* CWorkoutSwim::GetLocationStrength(void) const
{
    return NULL;
}


CCourseSwim* CWorkoutSwim::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CWorkoutSwim::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CWorkoutSwim::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CWorkoutSwim::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CWorkoutSwim::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CWorkoutSwim::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CWorkoutSwim::GetShoesBike(void) const
{
    return NULL;
}


int CWorkoutSwim::GetWind(void) const
{
    return WIND_NONE;
}


int CWorkoutSwim::GetRacePosition(void) const
{
    return 0;
}


int CWorkoutSwim::GetRaceNumber(void) const
{
    return 0;
}


CShoesBike* CWorkoutSwim::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CWorkoutSwim::GetSpecialShoesRun(void) const
{
    return NULL;
}


bool CWorkoutSwim::IsCountedOnShoes(void) const
{
    return false;
}


bool CWorkoutSwim::IsCountedOnBike(void) const
{
    return false;
}


CBike* CWorkoutSwim::GetBike(void) const
{
    return NULL;
}


int CWorkoutSwim::GetChoppiness(void) const
{
    return m_nChoppiness;
}


double CWorkoutSwim::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg1Miles(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg2Miles(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg3Miles(void) const
{
    return 0.0;
}


int CWorkoutSwim::GetLeg1Temperature(void) const
{
    return 0;
}


int CWorkoutSwim::GetLeg2Temperature(void) const
{
    return 0;
}


int CWorkoutSwim::GetLeg3Temperature(void) const
{
    return 0;
}


int CWorkoutSwim::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutSwim::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutSwim::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CWorkoutSwim::GetLeg1HR(void) const
{
    return 0;
}


int CWorkoutSwim::GetLeg2HR(void) const
{
    return 0;
}


int CWorkoutSwim::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CWorkoutSwim::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutSwim::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutSwim::GetLeg3Shoes(void) const
{
    return NULL;
}


double CWorkoutSwim::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CWorkoutSwim::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CWorkoutSwim::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CWorkoutSwim::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CWorkoutSwim::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CWorkoutSwim::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CWorkoutSwim::SetLocationSwim(CLocationSwim* pLoc)
{
    m_pLocSwim = pLoc;
}


void CWorkoutSwim::SetLocationBike(CLocationBike* pLoc)
{
    CUtil::Fatal("CWorkoutSwim::SetLocationBike called");
}


void CWorkoutSwim::SetLocationRun(CLocationRun* pLoc)
{
    CUtil::Fatal("CWorkoutSwim::SetLocationRun called");
}


void CWorkoutSwim::SetLocationStrength(CLocationStrength* pLoc)
{
    CUtil::Fatal("CWorkoutSwim::SetLocationStrength called");
}


void CWorkoutSwim::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CWorkoutSwim::SetCourseSwim called");
}


void CWorkoutSwim::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CWorkoutSwim::SetCourseRun called");
}


void CWorkoutSwim::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CWorkoutSwim::SetCourseBike called");
}


void CWorkoutSwim::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CWorkoutSwim::SetCourseDuathlon called");
}


void CWorkoutSwim::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CWorkoutSwim::SetCourseTriathlon called");
}


void CWorkoutSwim::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetShoesRun called");
}


void CWorkoutSwim::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetShoesBike called");
}


void CWorkoutSwim::SetWind(int nWind)
{
    CUtil::Fatal("CWorkoutSwim::SetWind called");
}


void CWorkoutSwim::SetRacePosition(int nPlace)
{
    CUtil::Fatal("CWorkoutSwim::SetRacePosition called");
}


void CWorkoutSwim::SetRaceNumber(int nNum)
{
    CUtil::Fatal("CWorkoutSwim::SetRaceNumber called");
}


void CWorkoutSwim::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetSpecialShoesRun called");
}


void CWorkoutSwim::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetSpecialShoesBike called");
}


void CWorkoutSwim::SetCountedOnShoes(bool fCount)
{
    CUtil::Fatal("CWorkoutSwim::SetCountedOnShoes called");
}


void CWorkoutSwim::SetCountedOnBike(bool fCount)
{
    CUtil::Fatal("CWorkoutSwim::SetCountedOnBike called");
}


void CWorkoutSwim::SetBike(CBike* pBike)
{
    CUtil::Fatal("CWorkoutSwim::SetBike called");
}


void CWorkoutSwim::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CWorkoutSwim::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::Transition1Seconds called");
}


void CWorkoutSwim::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::Transition2Seconds called");
}


void CWorkoutSwim::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1Seconds called");
}


void CWorkoutSwim::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2Seconds called");
}


void CWorkoutSwim::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3Seconds called");
}


void CWorkoutSwim::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1Miles called");
}


void CWorkoutSwim::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2Miles called");
}


void CWorkoutSwim::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3Miles called");
}


void CWorkoutSwim::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1Temperature called");
}


void CWorkoutSwim::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2Temperature called");
}


void CWorkoutSwim::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3Temperature called");
}


void CWorkoutSwim::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1Wind called");
}


void CWorkoutSwim::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2Wind called");
}


void CWorkoutSwim::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3Wind called");
}


void CWorkoutSwim::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1HR called");
}


void CWorkoutSwim::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2HR called");
}


void CWorkoutSwim::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3HR called");
}


void CWorkoutSwim::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1Shoes called");
}


void CWorkoutSwim::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2Shoes called");
}


void CWorkoutSwim::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3Shoes called");
}


void CWorkoutSwim::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1RaceSeconds called");
}


void CWorkoutSwim::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2RaceSeconds called");
}


void CWorkoutSwim::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3RaceSeconds called");
}


void CWorkoutSwim::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1RaceMiles called");
}


void CWorkoutSwim::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2RaceMiles called");
}


void CWorkoutSwim::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3RaceMiles called");
}


void CWorkoutSwim::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg1RaceShoes called");
}


void CWorkoutSwim::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg2RaceShoes called");
}


void CWorkoutSwim::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CWorkoutSwim::SetLeg3RaceShoes called");
}