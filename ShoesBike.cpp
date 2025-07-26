#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "ShoesBike.h"


CShoesBike::CShoesBike(void)
{
    SetRetired(false);
}


CShoesBike::~CShoesBike()
{
}


CString CShoesBike::GetBrand(void) const
{
    return m_strBrand;
}


CString CShoesBike::GetType(void) const
{
    return m_strType;
}


double CShoesBike::GetSize(void) const
{
    return m_dSize;
}


COleDateTime CShoesBike::GetFirstDay(void) const
{
    return m_tmFirstDay;
}


CString CShoesBike::GetNotes(void) const
{
    return m_strNotes;
}


bool CShoesBike::IsRetired(void) const
{
    return m_fRetired;
}


void CShoesBike::SetBrand(CString str)
{
    m_strBrand = str;
}


void CShoesBike::SetType(CString str)
{
    m_strType = str;
}


void CShoesBike::SetSize(double dSize)
{
    m_dSize = dSize;
}


void CShoesBike::SetFirstDay(COleDateTime tm)
{
    m_tmFirstDay = tm;
}


void CShoesBike::SetNotes(CString str)
{
    m_strNotes = str;
}


void CShoesBike::SetRetired(bool fRetired)
{
    m_fRetired = fRetired;
}