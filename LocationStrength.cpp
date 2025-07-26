#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Location.h"
#include "LocationStrength.h"


CLocationStrength::CLocationStrength(void)
{
}


CLocationStrength::~CLocationStrength()
{
}


CString CLocationStrength::GetName(void) const
{
    return m_strName;
}


CString CLocationStrength::GetCity(void) const
{
    return m_strCity;
}


CString CLocationStrength::GetState(void) const
{
    return m_strState;
}


CString CLocationStrength::GetNotes(void) const
{
    return m_strNotes;
}


void CLocationStrength::SetName(CString str)
{
    m_strName = str;
}


void CLocationStrength::SetCity(CString str)
{
    m_strCity = str;
}


void CLocationStrength::SetState(CString str)
{
    m_strState = str;
}


void CLocationStrength::SetNotes(CString str)
{
    m_strNotes = str;
}