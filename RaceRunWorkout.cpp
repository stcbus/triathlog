#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RaceRunWorkout.h"


CRaceRunWorkout::CRaceRunWorkout(void)
{
}


CRaceRunWorkout::~CRaceRunWorkout(void)
{
}


void CRaceRunWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetMiles(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetMiles()));

    CWorkoutRace::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRaceRunWorkout::GetType(void) const
{
    return RACETYPE_RUN;
}


double CRaceRunWorkout::GetMiles(void) const
{
    return m_dMiles;
}


CCourseSwim* CRaceRunWorkout::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CRaceRunWorkout::GetCourseRun(void) const
{
    return m_pCourse;
}


CCourseBike* CRaceRunWorkout::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CRaceRunWorkout::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CRaceRunWorkout::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CRaceRunWorkout::GetShoesRun(void) const
{
    return m_pShoes;
}


CShoesBike* CRaceRunWorkout::GetShoesBike(void) const
{
    return NULL;
}


int CRaceRunWorkout::GetWind(void) const
{
    return m_nWind;
}


double CRaceRunWorkout::GetSpecialMiles(void) const
{
    CCourseRun* pCourse = GetCourseRun();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLength();
    }
}


CShoesBike* CRaceRunWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CRaceRunWorkout::GetSpecialShoesRun(void) const
{
    return m_pSpikes;
}


CBike* CRaceRunWorkout::GetBike(void) const
{
    return NULL;
}


int CRaceRunWorkout::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CRaceRunWorkout::GetTransition1Seconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetTransition2Seconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg1Seconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg2Seconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg3Seconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg1Miles(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg2Miles(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg3Miles(void) const
{
    return 0.0;
}


int CRaceRunWorkout::GetLeg1Temperature(void) const
{
    return 0;
}


int CRaceRunWorkout::GetLeg2Temperature(void) const
{
    return 0;
}


int CRaceRunWorkout::GetLeg3Temperature(void) const
{
    return 0;
}


int CRaceRunWorkout::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CRaceRunWorkout::GetLeg2Wind(void) const
{
    return WIND_NONE;
}


int CRaceRunWorkout::GetLeg3Wind(void) const
{
    return WIND_NONE;
}


int CRaceRunWorkout::GetLeg1HR(void) const
{
    return 0;
}


int CRaceRunWorkout::GetLeg2HR(void) const
{
    return 0;
}


int CRaceRunWorkout::GetLeg3HR(void) const
{
    return 0;
}


CShoesRun* CRaceRunWorkout::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CRaceRunWorkout::GetLeg2Shoes(void) const
{
    return NULL;
}


CShoesRun* CRaceRunWorkout::GetLeg3Shoes(void) const
{
    return NULL;
}


double CRaceRunWorkout::GetLeg1RaceSeconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg2RaceSeconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg3RaceSeconds(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg1RaceMiles(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg2RaceMiles(void) const
{
    return 0.0;
}


double CRaceRunWorkout::GetLeg3RaceMiles(void) const
{
    return 0.0;
}


CShoesRun* CRaceRunWorkout::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CRaceRunWorkout::GetLeg2RaceShoes(void) const
{
    return NULL;
}


CShoesRun* CRaceRunWorkout::GetLeg3RaceShoes(void) const
{
    return NULL;
}


void CRaceRunWorkout::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceRunWorkout::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CRaceRunWorkout::SetCourseSwim called");
}


void CRaceRunWorkout::SetCourseRun(CCourseRun* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceRunWorkout::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CRaceRunWorkout::SetCourseBike called");
}


void CRaceRunWorkout::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CRaceRunWorkout::SetCourseDuathlon called");
}


void CRaceRunWorkout::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CRaceRunWorkout::SetCourseTriathlon called");
}


void CRaceRunWorkout::SetShoesRun(CShoesRun* pShoes)
{
    m_pShoes = pShoes;
}


void CRaceRunWorkout::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetShoesBike called");
}


void CRaceRunWorkout::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRaceRunWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetSpecialMiles called");
}


void CRaceRunWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    m_pSpikes = pShoes;
}


void CRaceRunWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetSpecialShoesBike called");
}


void CRaceRunWorkout::SetBike(CBike* pBike)
{
    CUtil::Fatal("CRaceRunWorkout::SetBike called");
}



void CRaceRunWorkout::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CRaceRunWorkout::SetChoppiness called");
}


void CRaceRunWorkout::SetTransition1Seconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::Transition1Seconds called");
}


void CRaceRunWorkout::SetTransition2Seconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::Transition2Seconds called");
}


void CRaceRunWorkout::SetLeg1Seconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1Seconds called");
}


void CRaceRunWorkout::SetLeg2Seconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2Seconds called");
}


void CRaceRunWorkout::SetLeg3Seconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3Seconds called");
}


void CRaceRunWorkout::SetLeg1Miles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1Miles called");
}


void CRaceRunWorkout::SetLeg2Miles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2Miles called");
}


void CRaceRunWorkout::SetLeg3Miles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3Miles called");
}


void CRaceRunWorkout::SetLeg1Temperature(int nTemp)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1Temperature called");
}


void CRaceRunWorkout::SetLeg2Temperature(int nTemp)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2Temperature called");
}


void CRaceRunWorkout::SetLeg3Temperature(int nTemp)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3Temperature called");
}


void CRaceRunWorkout::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1Wind called");
}


void CRaceRunWorkout::SetLeg2Wind(int nWind)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2Wind called");
}


void CRaceRunWorkout::SetLeg3Wind(int nWind)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3Wind called");
}


void CRaceRunWorkout::SetLeg1HR(int nHR)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1HR called");
}


void CRaceRunWorkout::SetLeg2HR(int nHR)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2HR called");
}


void CRaceRunWorkout::SetLeg3HR(int nHR)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3HR called");
}


void CRaceRunWorkout::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1Shoes called");
}


void CRaceRunWorkout::SetLeg2Shoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2Shoes called");
}


void CRaceRunWorkout::SetLeg3Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3Shoes called");
}


void CRaceRunWorkout::SetLeg1RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1RaceSeconds called");
}


void CRaceRunWorkout::SetLeg2RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2RaceSeconds called");
}


void CRaceRunWorkout::SetLeg3RaceSeconds(double dSec)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3RaceSeconds called");
}


void CRaceRunWorkout::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1RaceMiles called");
}


void CRaceRunWorkout::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2RaceMiles called");
}


void CRaceRunWorkout::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3RaceMiles called");
}


void CRaceRunWorkout::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg1RaceShoes called");
}


void CRaceRunWorkout::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg2RaceShoes called");
}


void CRaceRunWorkout::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceRunWorkout::SetLeg3RaceShoes called");
}