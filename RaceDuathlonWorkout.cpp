#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "RaceDuathlonWorkout.h"


CRaceDuathlonWorkout::CRaceDuathlonWorkout(void)
{
}


CRaceDuathlonWorkout::~CRaceDuathlonWorkout(void)
{
}


void CRaceDuathlonWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetLeg1Miles(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetLeg1Miles()));
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


int CRaceDuathlonWorkout::GetType(void) const
{
    return RACETYPE_DUATHLON;
}


double CRaceDuathlonWorkout::GetMiles(void) const
{
    return 0.0;
}


CCourseSwim* CRaceDuathlonWorkout::GetCourseSwim(void) const
{
    return NULL;
}


CCourseRun* CRaceDuathlonWorkout::GetCourseRun(void) const
{
    return NULL;
}


CCourseBike* CRaceDuathlonWorkout::GetCourseBike(void) const
{
    return NULL;
}


CCourseDuathlon* CRaceDuathlonWorkout::GetCourseDuathlon(void) const
{
    return m_pCourse;
}


CCourseTriathlon* CRaceDuathlonWorkout::GetCourseTriathlon(void) const
{
    return NULL;
}


CShoesRun* CRaceDuathlonWorkout::GetShoesRun(void) const
{
    return NULL;
}


CShoesBike* CRaceDuathlonWorkout::GetShoesBike(void) const
{
    return NULL;
}


int CRaceDuathlonWorkout::GetWind(void) const
{
    return WIND_NONE;
}


double CRaceDuathlonWorkout::GetSpecialMiles(void) const
{
    return 0.0;
}


CShoesBike* CRaceDuathlonWorkout::GetSpecialShoesBike(void) const
{
    return NULL;
}


CShoesRun* CRaceDuathlonWorkout::GetSpecialShoesRun(void) const
{
    return NULL;
}


CBike* CRaceDuathlonWorkout::GetBike(void) const
{
    return m_pBike;
}


int CRaceDuathlonWorkout::GetChoppiness(void) const
{
    return CHOPPINESS_NONE;
}


double CRaceDuathlonWorkout::GetTransition1Seconds(void) const
{
    return m_dTransition1Seconds;
}


double CRaceDuathlonWorkout::GetTransition2Seconds(void) const
{
    return m_dTransition2Seconds;
}


double CRaceDuathlonWorkout::GetLeg1Seconds(void) const
{
    return m_dLeg1Seconds;
}


double CRaceDuathlonWorkout::GetLeg2Seconds(void) const
{
    return m_dLeg2Seconds;
}


double CRaceDuathlonWorkout::GetLeg3Seconds(void) const
{
    return m_dLeg3Seconds;
}


double CRaceDuathlonWorkout::GetLeg1Miles(void) const
{
    return m_dLeg1Miles;
}


double CRaceDuathlonWorkout::GetLeg2Miles(void) const
{
    return m_dLeg2Miles;
}


double CRaceDuathlonWorkout::GetLeg3Miles(void) const
{
    return m_dLeg3Miles;
}


int CRaceDuathlonWorkout::GetLeg1Temperature(void) const
{
    return m_nLeg1Temp;
}


int CRaceDuathlonWorkout::GetLeg2Temperature(void) const
{
    return m_nLeg2Temp;
}


int CRaceDuathlonWorkout::GetLeg3Temperature(void) const
{
    return m_nLeg3Temp;
}


int CRaceDuathlonWorkout::GetLeg1Wind(void) const
{
    return m_nLeg1Wind;
}


int CRaceDuathlonWorkout::GetLeg2Wind(void) const
{
    return m_nLeg2Wind;
}


int CRaceDuathlonWorkout::GetLeg3Wind(void) const
{
    return m_nLeg3Wind;
}


int CRaceDuathlonWorkout::GetLeg1HR(void) const
{
    return m_nLeg1HR;
}


int CRaceDuathlonWorkout::GetLeg2HR(void) const
{
    return m_nLeg2HR;
}


int CRaceDuathlonWorkout::GetLeg3HR(void) const
{
    return m_nLeg3HR;
}


CShoesRun* CRaceDuathlonWorkout::GetLeg1Shoes(void) const
{
    return m_pLeg1Shoes;
}


CShoesBike* CRaceDuathlonWorkout::GetLeg2Shoes(void) const
{
    return m_pLeg2Shoes;
}


CShoesRun* CRaceDuathlonWorkout::GetLeg3Shoes(void) const
{
    return m_pLeg3Shoes;
}


double CRaceDuathlonWorkout::GetLeg1RaceSeconds(void) const
{
    return m_dLeg1RaceSeconds;
}


double CRaceDuathlonWorkout::GetLeg2RaceSeconds(void) const
{
    return m_dLeg2RaceSeconds;
}


double CRaceDuathlonWorkout::GetLeg3RaceSeconds(void) const
{
    return m_dLeg3RaceSeconds;
}


double CRaceDuathlonWorkout::GetLeg1RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg1Length();
    }
}


double CRaceDuathlonWorkout::GetLeg2RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg2Length();
    }
}


double CRaceDuathlonWorkout::GetLeg3RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg3Length();
    }
}


CShoesRun* CRaceDuathlonWorkout::GetLeg1RaceShoes(void) const
{
    return m_pLeg1RaceShoes;
}


CShoesBike* CRaceDuathlonWorkout::GetLeg2RaceShoes(void) const
{
    return m_pLeg2RaceShoes;
}


CShoesRun* CRaceDuathlonWorkout::GetLeg3RaceShoes(void) const
{
    return m_pLeg3RaceShoes;
}


void CRaceDuathlonWorkout::SetMiles(double dMiles)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetMiles called");
}


void CRaceDuathlonWorkout::SetCourseSwim(CCourseSwim* pCourse)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetCourseSwim called");
}


void CRaceDuathlonWorkout::SetCourseRun(CCourseRun* pCourse)
{
        CUtil::Fatal("CRaceDuathlonWorkout::SetCourseRun called");
}


void CRaceDuathlonWorkout::SetCourseBike(CCourseBike* pCourse)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetCourseBike called");
}


void CRaceDuathlonWorkout::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceDuathlonWorkout::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetCourseTriathlon called");
}


void CRaceDuathlonWorkout::SetShoesRun(CShoesRun* pShoes)
{
        CUtil::Fatal("CRaceDuathlonWorkout::SetCourseRun called");
}


void CRaceDuathlonWorkout::SetShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetShoesBike called");
}


void CRaceDuathlonWorkout::SetWind(int nWind)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetWind called");
}


void CRaceDuathlonWorkout::SetSpecialMiles(double dMiles)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetSpecialMiles called");
}


void CRaceDuathlonWorkout::SetSpecialShoesRun(CShoesRun* pShoes)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetSpecialShoesRun called");
}


void CRaceDuathlonWorkout::SetSpecialShoesBike(CShoesBike* pShoes)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetSpecialShoesBike called");
}


void CRaceDuathlonWorkout::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceDuathlonWorkout::SetChoppiness(int nAmount)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetChoppiness called");
}


void CRaceDuathlonWorkout::SetTransition1Seconds(double dSec)
{
    m_dTransition1Seconds = dSec;
}


void CRaceDuathlonWorkout::SetTransition2Seconds(double dSec)
{
    m_dTransition2Seconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg1Seconds(double dSec)
{
    m_dLeg1Seconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg2Seconds(double dSec)
{
    m_dLeg2Seconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg3Seconds(double dSec)
{
    m_dLeg3Seconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg1Miles(double dMiles)
{
    m_dLeg1Miles = dMiles;
}


void CRaceDuathlonWorkout::SetLeg2Miles(double dMiles)
{
    m_dLeg2Miles = dMiles;
}


void CRaceDuathlonWorkout::SetLeg3Miles(double dMiles)
{
    m_dLeg3Miles = dMiles;
}


void CRaceDuathlonWorkout::SetLeg1Temperature(int nTemp)
{
    m_nLeg1Temp = nTemp;
}


void CRaceDuathlonWorkout::SetLeg2Temperature(int nTemp)
{
    m_nLeg2Temp = nTemp;
}


void CRaceDuathlonWorkout::SetLeg3Temperature(int nTemp)
{
    m_nLeg3Temp = nTemp;
}


void CRaceDuathlonWorkout::SetLeg1Wind(int nWind)
{
    m_nLeg1Wind = nWind;
}


void CRaceDuathlonWorkout::SetLeg2Wind(int nWind)
{
    m_nLeg2Wind = nWind;
}


void CRaceDuathlonWorkout::SetLeg3Wind(int nWind)
{
    m_nLeg3Wind = nWind;
}


void CRaceDuathlonWorkout::SetLeg1HR(int nHR)
{
    m_nLeg1HR = nHR;
}


void CRaceDuathlonWorkout::SetLeg2HR(int nHR)
{
    m_nLeg2HR = nHR;
}


void CRaceDuathlonWorkout::SetLeg3HR(int nHR)
{
    m_nLeg3HR = nHR;
}


void CRaceDuathlonWorkout::SetLeg1Shoes(CShoesRun* pShoes)
{
    m_pLeg1Shoes = pShoes;
}


void CRaceDuathlonWorkout::SetLeg2Shoes(CShoesBike* pShoes)
{
    m_pLeg2Shoes = pShoes;
}


void CRaceDuathlonWorkout::SetLeg3Shoes(CShoesRun* pShoes)
{
    m_pLeg3Shoes = pShoes;
}


void CRaceDuathlonWorkout::SetLeg1RaceSeconds(double dSec)
{
    m_dLeg1RaceSeconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg2RaceSeconds(double dSec)
{
    m_dLeg2RaceSeconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg3RaceSeconds(double dSec)
{
    m_dLeg3RaceSeconds = dSec;
}


void CRaceDuathlonWorkout::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetLeg1RaceMiles called");
}


void CRaceDuathlonWorkout::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetLeg2RaceMiles called");
}


void CRaceDuathlonWorkout::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceDuathlonWorkout::SetLeg3RaceMiles called");
}


void CRaceDuathlonWorkout::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    m_pLeg1RaceShoes = pShoes;
}


void CRaceDuathlonWorkout::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    m_pLeg2RaceShoes = pShoes;
}


void CRaceDuathlonWorkout::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    m_pLeg3RaceShoes = pShoes;
}


void CRaceDuathlonWorkout::SetOverallHR(void)
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


void CRaceDuathlonWorkout::SetOverallTemperature(void)
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
