#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Injury.h"


CInjury::CInjury(void)
{
    SetFinished(false);
	SetStartDate(COleDateTime::GetCurrentTime());
	SetEndDate(COleDateTime::GetCurrentTime());
}


CInjury::~CInjury()
{
}


CString CInjury::GetName(void) const
{
    return m_strName;
}


COleDateTime CInjury::GetStartDate(void) const
{
    return m_tmStart;
}


COleDateTime CInjury::GetEndDate(void) const
{
    return m_tmEnd;
}


bool CInjury::IsFinished(void) const
{
	return m_bFinished;
}


CString CInjury::GetDescription(void) const
{
    return m_strDescription;
}


CString CInjury::GetTreatment(void) const
{
    return m_strTreatment;
}


void CInjury::SetName(CString str)
{
    m_strName = str;
}


void CInjury::SetStartDate(COleDateTime tm)
{
    m_tmStart = tm;
}


void CInjury::SetEndDate(COleDateTime tm)
{
    m_tmEnd = tm;
}


void CInjury::SetFinished(bool bFinished)
{
    m_bFinished = bFinished;
}


void CInjury::SetDescription(CString str)
{
    m_strDescription = str;
}


void CInjury::SetTreatment(CString str)
{
    m_strTreatment = str;
}