#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Location.h"
#include "LocationSwim.h"


CLocationSwim::CLocationSwim(void)
{
}


CLocationSwim::~CLocationSwim()
{
}


CString CLocationSwim::GetName(void) const
{
    return m_strName;
}


CString CLocationSwim::GetCity(void) const
{
    return m_strCity;
}


CString CLocationSwim::GetState(void) const
{
    return m_strState;
}


CString CLocationSwim::GetNotes(void) const
{
    return m_strNotes;
}


void CLocationSwim::SetName(CString str)
{
    m_strName = str;
}


void CLocationSwim::SetCity(CString str)
{
    m_strCity = str;
}


void CLocationSwim::SetState(CString str)
{
    m_strState = str;
}


void CLocationSwim::SetNotes(CString str)
{
    m_strNotes = str;
}