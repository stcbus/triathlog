#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RaceBikeWorkout.h"


CRaceBikeWorkout::CRaceBikeWorkout(void)
{
}


CRaceBikeWorkout::~CRaceBikeWorkout(void)
{
}


void CRaceBikeWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetMiles()));

    CWorkoutRace::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRaceBikeWorkout::GetType(void) const
{
    return RACETYPE_BIKE;
}


double CRaceBikeWorkout::GetMiles(void) const
{
    return m_dMiles;
}


CCourseSwim* CRaceBikeWorkout::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CRaceBikeWorkout::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CRaceBikeWorkout::GetCourseBike(void) const
{
    return m_pCourse;
}


CCourseDuathlon* CRaceBikeWorkout::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CRaceBikeWorkout::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CRaceBikeWorkout::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CRaceBikeWorkout::GetShoesBike(void) const
{
    return m_pShoes;
}


int CRaceBikeWorkout::GetWind(void) const
{
    return m_nWind;
}


double CRaceBikeWorkout::GetSpecialMiles(void) const
{
    CCourseBike* pCourse = GetCourseBike();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLength();
    }
}


CShoesBike* CRaceBikeWorkout::GetSpecialShoesBike(void) const
{
    return m_pSpikes;
}


CShoesRun* CRaceBikeWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


CBike* CRaceBikeWorkout::GetBike(void) const
{
    return m_pBike;
}


int CRaceBikeWorkout::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CRaceBikeWorkout::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg1Miles(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg2Miles(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg3Miles(void) const
{
    return 0.0;
}


int CRaceBikeWorkout::GetLeg1Temperature(void) const
{
    return 0;
}


int CRaceBikeWorkout::GetLeg2Temperature(void) const
{
    return 0;
}


int CRaceBikeWorkout::GetLeg3Temperature(void) const
{
    return 0;
}


int CRaceBikeWorkout::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CRaceBikeWorkout::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CRaceBikeWorkout::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CRaceBikeWorkout::GetLeg1HR(void) const
{
    return 0;
}


int CRaceBikeWorkout::GetLeg2HR(void) const
{
    return 0;
}


int CRaceBikeWorkout::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CRaceBikeWorkout::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CRaceBikeWorkout::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CRaceBikeWorkout::GetLeg3Shoes(void) const
{
    return NULL;
}


double CRaceBikeWorkout::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CRaceBikeWorkout::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CRaceBikeWorkout::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CRaceBikeWorkout::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CRaceBikeWorkout::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CRaceBikeWorkout::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceBikeWorkout::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CRaceBikeWorkout::SetCourseSwim called");
}


void CRaceBikeWorkout::SetCourseRun(CCourseRun* pCourse)
{
    CUtil::Fatal("CRaceBikeWorkout::SetCourseRun called");
}


void CRaceBikeWorkout::SetCourseBike(CCourseBike* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceBikeWorkout::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CRaceBikeWorkout::SetCourseDuathlon called");
}


void CRaceBikeWorkout::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CRaceBikeWorkout::SetCourseTriathlon called");
}


void CRaceBikeWorkout::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetShoesRun called");
}


void CRaceBikeWorkout::SetShoesBike(CShoesBike* pShoes)
{
    m_pShoes = pShoes;
}


void CRaceBikeWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRaceBikeWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetSpecialMiles called");
}


void CRaceBikeWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetSpecialShoesRun called");
}


void CRaceBikeWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    m_pSpikes = pShoes;
}


void CRaceBikeWorkout::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceBikeWorkout::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CRaceBikeWorkout::SetChoppiness called");
}



void CRaceBikeWorkout::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::Transition1Seconds called");
}


void CRaceBikeWorkout::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::Transition2Seconds called");
}


void CRaceBikeWorkout::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1Seconds called");
}


void CRaceBikeWorkout::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2Seconds called");
}


void CRaceBikeWorkout::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3Seconds called");
}


void CRaceBikeWorkout::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1Miles called");
}


void CRaceBikeWorkout::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2Miles called");
}


void CRaceBikeWorkout::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3Miles called");
}


void CRaceBikeWorkout::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1Temperature called");
}


void CRaceBikeWorkout::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2Temperature called");
}


void CRaceBikeWorkout::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3Temperature called");
}


void CRaceBikeWorkout::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1Wind called");
}


void CRaceBikeWorkout::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2Wind called");
}


void CRaceBikeWorkout::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3Wind called");
}


void CRaceBikeWorkout::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1HR called");
}


void CRaceBikeWorkout::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2HR called");
}


void CRaceBikeWorkout::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3HR called");
}


void CRaceBikeWorkout::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1Shoes called");
}


void CRaceBikeWorkout::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2Shoes called");
}


void CRaceBikeWorkout::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3Shoes called");
}


void CRaceBikeWorkout::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1RaceSeconds called");
}


void CRaceBikeWorkout::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2RaceSeconds called");
}


void CRaceBikeWorkout::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3RaceSeconds called");
}


void CRaceBikeWorkout::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1RaceMiles called");
}


void CRaceBikeWorkout::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2RaceMiles called");
}


void CRaceBikeWorkout::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3RaceMiles called");
}


void CRaceBikeWorkout::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg1RaceShoes called");
}


void CRaceBikeWorkout::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg2RaceShoes called");
}


void CRaceBikeWorkout::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceBikeWorkout::SetLeg3RaceShoes called");
}