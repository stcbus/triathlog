#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RaceTriathlonWorkout.h"


CRaceTriathlonWorkout::CRaceTriathlonWorkout(void)
{
}


CRaceTriathlonWorkout::~CRaceTriathlonWorkout(void)
{
}


void CRaceTriathlonWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetLeg1Miles(CUtil::ConvertDistance(nOldDistSwimUnits, nNewDistSwimUnits, GetLeg1Miles()));
    SetLeg1Temperature(CUtil::ConvertTemperature(nOldTempUnits, nNewTempUnits, GetLeg1Temperature()));
    SetLeg2Miles(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetLeg2Miles()));
    SetLeg2Temperature(CUtil::ConvertTemperature(nOldTempUnits, nNewTempUnits, GetLeg2Temperature()));
    SetLeg3Miles(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetLeg3Miles()));
    SetLeg3Temperature(CUtil::ConvertTemperature(nOldTempUnits, nNewTempUnits, GetLeg3Temperature()));

    CWorkoutRace::AdjustUnits(nOldDistRunUnits, nOldDistBikeUnits, nOldDistSwimUnits,
                          nOldWeightUnits, nOldTempUnits, nNewDistRunUnits,
                          nNewDistBikeUnits, nNewDistSwimUnits, nNewWeightUnits, 
                          nNewTempUnits);
}


int CRaceTriathlonWorkout::GetType(void) const
{
    return RACETYPE_TRIATHLON;
}


double CRaceTriathlonWorkout::GetMiles(void) const
{
    return 0.0;
}


CCourseSwim* CRaceTriathlonWorkout::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CRaceTriathlonWorkout::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CRaceTriathlonWorkout::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CRaceTriathlonWorkout::GetCourseDuathlon(void) const
{
    return NULL;
}


CCourseTriathlon* CRaceTriathlonWorkout::GetCourseTriathlon(void) const
{
    return m_pCourse;
}


CShoesRun* CRaceTriathlonWorkout::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CRaceTriathlonWorkout::GetShoesBike(void) const
{
    return NULL;
}


int CRaceTriathlonWorkout::GetWind(void) const
{
    return WIND_NONE;
}


double CRaceTriathlonWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CRaceTriathlonWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CRaceTriathlonWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


CBike* CRaceTriathlonWorkout::GetBike(void) const
{
    return m_pBike;
}


int CRaceTriathlonWorkout::GetChoppiness(void) const
{
    return m_nLeg1Choppiness;
}


double CRaceTriathlonWorkout::GetTransition1Seconds(void) const
{
    return m_dTransition1Seconds;
}


double CRaceTriathlonWorkout::GetTransition2Seconds(void) const
{
    return m_dTransition2Seconds;
}


double CRaceTriathlonWorkout::GetLeg1Seconds(void) const
{
    return m_dLeg1Seconds;
}


double CRaceTriathlonWorkout::GetLeg2Seconds(void) const
{
    return m_dLeg2Seconds;
}


double CRaceTriathlonWorkout::GetLeg3Seconds(void) const
{
    return m_dLeg3Seconds;
}


double CRaceTriathlonWorkout::GetLeg1Miles(void) const
{
    return m_dLeg1Miles;
}


double CRaceTriathlonWorkout::GetLeg2Miles(void) const
{
    return m_dLeg2Miles;
}


double CRaceTriathlonWorkout::GetLeg3Miles(void) const
{
    return m_dLeg3Miles;
}


int CRaceTriathlonWorkout::GetLeg1Temperature(void) const
{
    return m_nLeg1Temp;
}


int CRaceTriathlonWorkout::GetLeg2Temperature(void) const
{
    return m_nLeg2Temp;
}


int CRaceTriathlonWorkout::GetLeg3Temperature(void) const
{
    return m_nLeg3Temp;
}


int CRaceTriathlonWorkout::GetLeg1Wind(void) const
{
    return WIND_NONE;
}


int CRaceTriathlonWorkout::GetLeg2Wind(void) const
{
    return m_nLeg2Wind;
}


int CRaceTriathlonWorkout::GetLeg3Wind(void) const
{
    return m_nLeg3Wind;
}


int CRaceTriathlonWorkout::GetLeg1HR(void) const
{
    return m_nLeg1HR;
}


int CRaceTriathlonWorkout::GetLeg2HR(void) const
{
    return m_nLeg2HR;
}


int CRaceTriathlonWorkout::GetLeg3HR(void) const
{
    return m_nLeg3HR;
}


CShoesRun* CRaceTriathlonWorkout::GetLeg1Shoes(void) const
{
    return NULL;
}


CShoesBike* CRaceTriathlonWorkout::GetLeg2Shoes(void) const
{
    return m_pLeg2Shoes;
}


CShoesRun* CRaceTriathlonWorkout::GetLeg3Shoes(void) const
{
    return m_pLeg3Shoes;
}


double CRaceTriathlonWorkout::GetLeg1RaceSeconds(void) const
{
    return m_dLeg1RaceSeconds;
}


double CRaceTriathlonWorkout::GetLeg2RaceSeconds(void) const
{
    return m_dLeg2RaceSeconds;
}


double CRaceTriathlonWorkout::GetLeg3RaceSeconds(void) const
{
    return m_dLeg3RaceSeconds;
}


double CRaceTriathlonWorkout::GetLeg1RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg1Length();
    }
}


double CRaceTriathlonWorkout::GetLeg2RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg2Length();
    }
}


double CRaceTriathlonWorkout::GetLeg3RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg3Length();
    }
}


CShoesRun* CRaceTriathlonWorkout::GetLeg1RaceShoes(void) const
{
    return NULL;
}


CShoesBike* CRaceTriathlonWorkout::GetLeg2RaceShoes(void) const
{
    return m_pLeg2RaceShoes;
}


CShoesRun* CRaceTriathlonWorkout::GetLeg3RaceShoes(void) const
{
    return m_pLeg3RaceShoes;
}


void CRaceTriathlonWorkout::SetMiles(double dMiles)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetMiles called");
}


void CRaceTriathlonWorkout::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetCourseSwim called");
}


void CRaceTriathlonWorkout::SetCourseRun(CCourseRun* pCourse)
{
        CUtil::Fatal("CRaceTriathlonWorkout::SetCourseRun called");
}


void CRaceTriathlonWorkout::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetCourseBike called");
}


void CRaceTriathlonWorkout::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetCourseDuathlon called");
}


void CRaceTriathlonWorkout::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceTriathlonWorkout::SetShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetCourseRun called");
}


void CRaceTriathlonWorkout::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetShoesBike called");
}


void CRaceTriathlonWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetWind called");
}


void CRaceTriathlonWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetSpecialMiles called");
}


void CRaceTriathlonWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
        CUtil::Fatal("CRaceTriathlonWorkout::SetSpecialShoesRun called");
}


void CRaceTriathlonWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetSpecialShoesBike called");
}


void CRaceTriathlonWorkout::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceTriathlonWorkout::SetChoppiness(int nAmount)
{
    m_nLeg1Choppiness = nAmount;
}


void CRaceTriathlonWorkout::SetTransition1Seconds(double dSec)
{
    m_dTransition1Seconds = dSec;
}


void CRaceTriathlonWorkout::SetTransition2Seconds(double dSec)
{
    m_dTransition2Seconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg1Seconds(double dSec)
{
    m_dLeg1Seconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg2Seconds(double dSec)
{
    m_dLeg2Seconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg3Seconds(double dSec)
{
    m_dLeg3Seconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg1Miles(double dMiles)
{
    m_dLeg1Miles = dMiles;
}


void CRaceTriathlonWorkout::SetLeg2Miles(double dMiles)
{
    m_dLeg2Miles = dMiles;
}


void CRaceTriathlonWorkout::SetLeg3Miles(double dMiles)
{
    m_dLeg3Miles = dMiles;
}


void CRaceTriathlonWorkout::SetLeg1Temperature(int nTemp)
{
    m_nLeg1Temp = nTemp;
}


void CRaceTriathlonWorkout::SetLeg2Temperature(int nTemp)
{
    m_nLeg2Temp = nTemp;
}


void CRaceTriathlonWorkout::SetLeg3Temperature(int nTemp)
{
    m_nLeg3Temp = nTemp;
}


void CRaceTriathlonWorkout::SetLeg1Wind(int nWind)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg1Wind called");
}


void CRaceTriathlonWorkout::SetLeg2Wind(int nWind)
{
    m_nLeg2Wind = nWind;
}


void CRaceTriathlonWorkout::SetLeg3Wind(int nWind)
{
    m_nLeg3Wind = nWind;
}


void CRaceTriathlonWorkout::SetLeg1HR(int nHR)
{
    m_nLeg1HR = nHR;
}


void CRaceTriathlonWorkout::SetLeg2HR(int nHR)
{
    m_nLeg2HR = nHR;
}


void CRaceTriathlonWorkout::SetLeg3HR(int nHR)
{
    m_nLeg3HR = nHR;
}


void CRaceTriathlonWorkout::SetLeg1Shoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg1Shoes called");
}


void CRaceTriathlonWorkout::SetLeg2Shoes(CShoesBike* pShoes)
{
    m_pLeg2Shoes = pShoes;
}


void CRaceTriathlonWorkout::SetLeg3Shoes(CShoesRun* pShoes)
{
    m_pLeg3Shoes = pShoes;
}


void CRaceTriathlonWorkout::SetLeg1RaceSeconds(double dSec)
{
    m_dLeg1RaceSeconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg2RaceSeconds(double dSec)
{
    m_dLeg2RaceSeconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg3RaceSeconds(double dSec)
{
    m_dLeg3RaceSeconds = dSec;
}


void CRaceTriathlonWorkout::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg1RaceMiles called");
}


void CRaceTriathlonWorkout::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg2RaceMiles called");
}


void CRaceTriathlonWorkout::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg3RaceMiles called");
}


void CRaceTriathlonWorkout::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceTriathlonWorkout::SetLeg1RaceShoes called");
}


void CRaceTriathlonWorkout::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    m_pLeg2RaceShoes = pShoes;
}


void CRaceTriathlonWorkout::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    m_pLeg3RaceShoes = pShoes;
}


void CRaceTriathlonWorkout::SetOverallHR(void)
{
	int nHR1 = GetLeg1HR();
	int nHR2 = GetLeg2HR();
	int nHR3 = GetLeg3HR();

	int nTotal = 0;
	int nDefined = 0;

	if(CUtil::HasData(nHR1))
	{
		nTotal += nHR1;
		nDefined++;
	}

	if(CUtil::HasData(nHR2))
	{
		nTotal += nHR2;
		nDefined++;
	}

	if(CUtil::HasData(nHR3))
	{
		nTotal += nHR3;
		nDefined++;
	}

	if(0 == nDefined)
	{
		SetHR(NOGRAPHDATA);
	}
	else
	{
		SetHR((int)(nTotal / nDefined));
	}
}


void CRaceTriathlonWorkout::SetOverallTemperature(void)
{
	int nTemperature1 = GetLeg1Temperature();
	int nTemperature2 = GetLeg2Temperature();
	int nTemperature3 = GetLeg3Temperature();

	int nTotal = 0;
	int nDefined = 0;

	if(CUtil::HasData(nTemperature1))
	{
		nTotal += nTemperature1;
		nDefined++;
	}

	if(CUtil::HasData(nTemperature2))
	{
		nTotal += nTemperature2;
		nDefined++;
	}

	if(CUtil::HasData(nTemperature3))
	{
		nTotal += nTemperature3;
		nDefined++;
	}

	if(0 == nDefined)
	{
		SetTemperature(NOGRAPHDATA);
	}
	else
	{
		SetTemperature((int)(nTotal / nDefined));
	}
}