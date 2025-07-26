#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RaceSwimWorkout.h"


CRaceSwimWorkout::CRaceSwimWorkout(void)
{
}


CRaceSwimWorkout::~CRaceSwimWorkout(void)
{
}


void CRaceSwimWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistSwimUnits, nNewDistSwimUnits, GetMiles()));

    CWorkoutRace::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRaceSwimWorkout::GetType(void) const
{
    return RACETYPE_SWIM;
}


double CRaceSwimWorkout::GetMiles(void) const
{
    return m_dMiles;
}


CCourseSwim* CRaceSwimWorkout::GetCourseSwim(void) const
{
    return m_pCourse;
}


CCourseRun* CRaceSwimWorkout::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CRaceSwimWorkout::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CRaceSwimWorkout::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CRaceSwimWorkout::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CRaceSwimWorkout::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CRaceSwimWorkout::GetShoesBike(void) const
{
    return NULL;
}


int CRaceSwimWorkout::GetWind(void) const
{
    return WIND_NONE;
}


double CRaceSwimWorkout::GetSpecialMiles(void) const
{
    CCourseSwim* pCourse = GetCourseSwim();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLength();
    }
}


CShoesBike* CRaceSwimWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CRaceSwimWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


CBike* CRaceSwimWorkout::GetBike(void) const
{
    return NULL;
}


int CRaceSwimWorkout::GetChoppiness(void) const
{
    return m_nChoppiness;
}


double CRaceSwimWorkout::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg1Miles(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg2Miles(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg3Miles(void) const
{
    return 0.0;
}


int CRaceSwimWorkout::GetLeg1Temperature(void) const
{
    return 0;
}


int CRaceSwimWorkout::GetLeg2Temperature(void) const
{
    return 0;
}


int CRaceSwimWorkout::GetLeg3Temperature(void) const
{
    return 0;
}


int CRaceSwimWorkout::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CRaceSwimWorkout::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CRaceSwimWorkout::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CRaceSwimWorkout::GetLeg1HR(void) const
{
    return 0;
}


int CRaceSwimWorkout::GetLeg2HR(void) const
{
    return 0;
}


int CRaceSwimWorkout::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CRaceSwimWorkout::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CRaceSwimWorkout::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CRaceSwimWorkout::GetLeg3Shoes(void) const
{
    return NULL;
}


double CRaceSwimWorkout::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CRaceSwimWorkout::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CRaceSwimWorkout::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CRaceSwimWorkout::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CRaceSwimWorkout::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CRaceSwimWorkout::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceSwimWorkout::SetCourseSwim(CCourseSwim* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceSwimWorkout::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CRaceSwimWorkout::SetCourseRun called");
}


void CRaceSwimWorkout::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CRaceSwimWorkout::SetCourseBike called");
}


void CRaceSwimWorkout::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CRaceSwimWorkout::SetCourseDuathlon called");
}


void CRaceSwimWorkout::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CRaceSwimWorkout::SetCourseTriathlon called");
}


void CRaceSwimWorkout::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetShoesRun called");
}


void CRaceSwimWorkout::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetShoesBike called");
}


void CRaceSwimWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CRaceSwimWorkout::SetWind called");
}


void CRaceSwimWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetSpecialMiles called");
}


void CRaceSwimWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetSpecialShoesRun called");
}


void CRaceSwimWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetSpecialShoesBike called");
}


void CRaceSwimWorkout::SetBike(CBike* pBike)
{
    CUtil::Fatal("CRaceSwimWorkout::SetBike called");
}


void CRaceSwimWorkout::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CRaceSwimWorkout::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::Transition1Seconds called");
}


void CRaceSwimWorkout::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::Transition2Seconds called");
}


void CRaceSwimWorkout::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1Seconds called");
}


void CRaceSwimWorkout::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2Seconds called");
}


void CRaceSwimWorkout::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3Seconds called");
}


void CRaceSwimWorkout::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1Miles called");
}


void CRaceSwimWorkout::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2Miles called");
}


void CRaceSwimWorkout::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3Miles called");
}


void CRaceSwimWorkout::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1Temperature called");
}


void CRaceSwimWorkout::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2Temperature called");
}


void CRaceSwimWorkout::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3Temperature called");
}


void CRaceSwimWorkout::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1Wind called");
}


void CRaceSwimWorkout::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2Wind called");
}


void CRaceSwimWorkout::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3Wind called");
}


void CRaceSwimWorkout::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1HR called");
}


void CRaceSwimWorkout::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2HR called");
}


void CRaceSwimWorkout::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3HR called");
}


void CRaceSwimWorkout::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1Shoes called");
}


void CRaceSwimWorkout::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2Shoes called");
}


void CRaceSwimWorkout::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3Shoes called");
}


void CRaceSwimWorkout::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1RaceSeconds called");
}


void CRaceSwimWorkout::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2RaceSeconds called");
}


void CRaceSwimWorkout::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3RaceSeconds called");
}


void CRaceSwimWorkout::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1RaceMiles called");
}


void CRaceSwimWorkout::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2RaceMiles called");
}


void CRaceSwimWorkout::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3RaceMiles called");
}


void CRaceSwimWorkout::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg1RaceShoes called");
}


void CRaceSwimWorkout::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg2RaceShoes called");
}


void CRaceSwimWorkout::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceSwimWorkout::SetLeg3RaceShoes called");
}