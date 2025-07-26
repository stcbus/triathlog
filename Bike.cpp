#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Shoes.h"


CBike::CBike(void)
{
    SetRetired(false);
}


CBike::~CBike()
{
}


CString CBike::GetBrand(void) const
{
    return m_strBrand;
}


CString CBike::GetType(void) const
{
    return m_strType;
}


double CBike::GetSize(void) const
{
    return m_dSize;
}


COleDateTime CBike::GetFirstDay(void) const
{
    return m_tmFirstDay;
}


CString CBike::GetNotes(void) const
{
    return m_strNotes;
}


bool CBike::IsRetired(void) const
{
    return m_fRetired;
}


void CBike::SetBrand(CString str)
{
    m_strBrand = str;
}


void CBike::SetType(CString str)
{
    m_strType = str;
}


void CBike::SetSize(double dSize)
{
    m_dSize = dSize;
}


void CBike::SetFirstDay(COleDateTime tm)
{
    m_tmFirstDay = tm;
}


void CBike::SetNotes(CString str)
{
    m_strNotes = str;
}


void CBike::SetRetired(bool fRetired)
{
    m_fRetired = fRetired;
}