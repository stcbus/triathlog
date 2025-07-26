#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Course.h"
#include "CourseRun.h"


CCourseRun::CCourseRun(void)
{
    SetPRSeconds(PRS_NOPR);
}


CCourseRun::~CCourseRun()
{
}


void CCourseRun::AdjustUnits(int nOldDistUnits, int nNewDistUnits)
{
    SetLength(CUtil::ConvertDistance(nOldDistUnits, nNewDistUnits, GetLength()));
}


bool CCourseRun::OptionallySetPR(double dSec)
{
    double dCur = GetPRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetPRSeconds(dSec);
        return true;
    }

    return false;
}


CString CCourseRun::GetName(void) const
{
    return m_strName;
}


CString CCourseRun::GetCity(void) const
{
    return m_strCity;
}


CString CCourseRun::GetState(void) const
{
    return m_strState;
}


double CCourseRun::GetLength(void) const
{
    return m_dLength;
}


CString CCourseRun::GetNotes(void) const
{
    return m_strNotes;
}


double CCourseRun::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


void CCourseRun::SetName(CString str)
{
    m_strName = str;
}


void CCourseRun::SetCity(CString str)
{
    m_strCity = str;
}


void CCourseRun::SetState(CString str)
{
    m_strState = str;
}


void CCourseRun::SetLength(double dLen)
{
    m_dLength = dLen;
}


void CCourseRun::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCourseRun::SetPRSeconds(double dPR)
{
    m_dPRSeconds = dPR;
}