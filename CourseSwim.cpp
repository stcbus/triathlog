#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Course.h"
#include "CourseSwim.h"


CCourseSwim::CCourseSwim(void)
{
    SetPRSeconds(PRS_NOPR);
}


CCourseSwim::~CCourseSwim()
{
}


void CCourseSwim::AdjustUnits(int nOldDistUnits, int nNewDistUnits)
{
    SetLength(CUtil::ConvertDistance(nOldDistUnits, nNewDistUnits, GetLength()));
}


bool CCourseSwim::OptionallySetPR(double dSec)
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


CString CCourseSwim::GetName(void) const
{
    return m_strName;
}


CString CCourseSwim::GetCity(void) const
{
    return m_strCity;
}


CString CCourseSwim::GetState(void) const
{
    return m_strState;
}


double CCourseSwim::GetLength(void) const
{
    return m_dLength;
}


CString CCourseSwim::GetNotes(void) const
{
    return m_strNotes;
}


double CCourseSwim::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


void CCourseSwim::SetName(CString str)
{
    m_strName = str;
}


void CCourseSwim::SetCity(CString str)
{
    m_strCity = str;
}


void CCourseSwim::SetState(CString str)
{
    m_strState = str;
}


void CCourseSwim::SetLength(double dLen)
{
    m_dLength = dLen;
}


void CCourseSwim::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCourseSwim::SetPRSeconds(double dPR)
{
    m_dPRSeconds = dPR;
}