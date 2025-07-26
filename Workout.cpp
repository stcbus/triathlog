#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Workout.h"


CWorkout::CWorkout(void)
{
	SetInjured(false);
	SetSick(false);
}


CWorkout::~CWorkout(void)
{
}


void CWorkout::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits)
{
    SetTemperature(CUtil::ConvertTemperature(nOldTempUnits, nNewTempUnits, GetTemperature()));
    SetWeight(CUtil::ConvertWeight(nOldWeightUnits, nNewWeightUnits, GetWeight()));
}


int CWorkout::GetType(void) const
{
    return -1;
}


double CWorkout::GetSeconds(void) const
{
    return m_dSeconds;
}


COleDateTime CWorkout::GetTimeStart(void) const
{
    return m_tmStart;
}


int CWorkout::GetTemperature(void) const
{
    return m_nTemp;
}


double CWorkout::GetPrevNightSleep(void) const
{
    return m_dPrevNightSleep;
}


int CWorkout::GetHR(void) const
{
    return m_nHR;
}


bool CWorkout::IsLong(void) const
{
    return m_fLong;
}


bool CWorkout::IsInjured(void) const
{
    return m_fInjured;
}


bool CWorkout::IsSick(void) const
{
    return m_fSick;
}


double CWorkout::GetWeight(void) const
{
    return m_dWeight;
}


CString CWorkout::GetNotes(void) const
{
    return m_strNotes;
}


CString CWorkout::GetDisplayName(void) const
{
    return m_strDispName;
}


CString CWorkout::GetDataFile(void) const
{
    return m_strDataFile;
}


void CWorkout::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CWorkout::SetTimeStart(COleDateTime tm)
{
    m_tmStart = tm;
}


void CWorkout::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CWorkout::SetPrevNightSleep(double dSleep)
{
    m_dPrevNightSleep = dSleep;
}


void CWorkout::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CWorkout::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CWorkout::SetInjured(bool fInjured)
{
    m_fInjured = fInjured;
}


void CWorkout::SetSick(bool fSick)
{
    m_fSick = fSick;
}


void CWorkout::SetWeight(double dWeight)
{
    m_dWeight = dWeight;
}


void CWorkout::SetNotes(CString str)
{
    m_strNotes = str;
}


void CWorkout::SetDisplayName(CString str)
{
    m_strDispName = str;
}


void CWorkout::SetDataFile(CString str)
{
    m_strDataFile = str;
}