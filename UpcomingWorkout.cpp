#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "Util.h"
#include "UpcomingWorkout.h"


CUpcomingWorkout::CUpcomingWorkout(void)
{
}


CUpcomingWorkout::~CUpcomingWorkout(void)
{
}


COleDateTime CUpcomingWorkout::GetDate(void) const
{
    return m_tmDay;
}


CString CUpcomingWorkout::GetLineOne(void) const
{
    return m_strLine1;
}


CString CUpcomingWorkout::GetLineTwo(void) const
{
    return m_strLine2;
}


CString CUpcomingWorkout::GetLineThree(void) const
{
	return m_strLine3;
}


void CUpcomingWorkout::SetDate(COleDateTime tm)
{
    m_tmDay = tm;
}


void CUpcomingWorkout::SetLineOne(CString str)
{
    m_strLine1 = str;
}


void CUpcomingWorkout::SetLineTwo(CString str)
{
    m_strLine2 = str;
}


void CUpcomingWorkout::SetLineThree(CString str)
{
    m_strLine3 = str;
}