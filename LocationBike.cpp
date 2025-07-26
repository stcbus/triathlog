#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Location.h"
#include "LocationBike.h"


CLocationBike::CLocationBike(void)
{
}


CLocationBike::~CLocationBike()
{
}


CString CLocationBike::GetName(void) const
{
    return m_strName;
}


CString CLocationBike::GetCity(void) const
{
    return m_strCity;
}


CString CLocationBike::GetState(void) const
{
    return m_strState;
}


CString CLocationBike::GetNotes(void) const
{
    return m_strNotes;
}


void CLocationBike::SetName(CString str)
{
    m_strName = str;
}


void CLocationBike::SetCity(CString str)
{
    m_strCity = str;
}


void CLocationBike::SetState(CString str)
{
    m_strState = str;
}


void CLocationBike::SetNotes(CString str)
{
    m_strNotes = str;
}