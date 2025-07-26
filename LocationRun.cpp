#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Location.h"
#include "LocationRun.h"


CLocationRun::CLocationRun(void)
{
}


CLocationRun::~CLocationRun()
{
}


CString CLocationRun::GetName(void) const
{
    return m_strName;
}


CString CLocationRun::GetCity(void) const
{
    return m_strCity;
}


CString CLocationRun::GetState(void) const
{
    return m_strState;
}


CString CLocationRun::GetNotes(void) const
{
    return m_strNotes;
}


void CLocationRun::SetName(CString str)
{
    m_strName = str;
}


void CLocationRun::SetCity(CString str)
{
    m_strCity = str;
}


void CLocationRun::SetState(CString str)
{
    m_strState = str;
}


void CLocationRun::SetNotes(CString str)
{
    m_strNotes = str;
}