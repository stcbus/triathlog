#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "Util.h"
#include "UpcomingRace.h"


CUpcomingRace::CUpcomingRace(void)
{
}


CUpcomingRace::~CUpcomingRace(void)
{
}


COleDateTime CUpcomingRace::GetDate(void) const
{
    return m_tmDay;
}


CString CUpcomingRace::GetLineOne(void) const
{
    return m_strLine1;
}


CString CUpcomingRace::GetLineTwo(void) const
{
    return m_strLine2;
}


CString CUpcomingRace::GetLineThree(void) const
{
	return m_strLine3;
}


void CUpcomingRace::SetDate(COleDateTime tm)
{
    m_tmDay = tm;
}


void CUpcomingRace::SetLineOne(CString str)
{
    m_strLine1 = str;
}


void CUpcomingRace::SetLineTwo(CString str)
{
    m_strLine2 = str;
}


void CUpcomingRace::SetLineThree(CString str)
{
    m_strLine3 = str;
}