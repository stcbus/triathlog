#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "ShoesRun.h"


CShoesRun::CShoesRun(void)
{
    SetRetired(false);
}


CShoesRun::~CShoesRun()
{
}


CString CShoesRun::GetBrand(void) const
{
    return m_strBrand;
}


CString CShoesRun::GetType(void) const
{
    return m_strType;
}


double CShoesRun::GetSize(void) const
{
    return m_dSize;
}


COleDateTime CShoesRun::GetFirstDay(void) const
{
    return m_tmFirstDay;
}


CString CShoesRun::GetNotes(void) const
{
    return m_strNotes;
}


bool CShoesRun::IsRetired(void) const
{
    return m_fRetired;
}


void CShoesRun::SetBrand(CString str)
{
    m_strBrand = str;
}


void CShoesRun::SetType(CString str)
{
    m_strType = str;
}


void CShoesRun::SetSize(double dSize)
{
    m_dSize = dSize;
}


void CShoesRun::SetFirstDay(COleDateTime tm)
{
    m_tmFirstDay = tm;
}


void CShoesRun::SetNotes(CString str)
{
    m_strNotes = str;
}


void CShoesRun::SetRetired(bool fRetired)
{
    m_fRetired = fRetired;
}