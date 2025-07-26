#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Course.h"
#include "CourseTriathlon.h"


CCourseTriathlon::CCourseTriathlon(void)
{
    SetPRSeconds(PRS_NOPR);
    SetLeg1PRSeconds(PRS_NOPR);
    SetLeg2PRSeconds(PRS_NOPR);
    SetLeg3PRSeconds(PRS_NOPR);
    SetTransition1PRSeconds(PRS_NOPR);
    SetTransition2PRSeconds(PRS_NOPR);
}


CCourseTriathlon::~CCourseTriathlon()
{
}


void CCourseTriathlon::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                                   int nNewDistRunUnits, int nNewDistBikeUnits, int nNewDistSwimUnits)
{
    SetLeg1Length(CUtil::ConvertDistance(nOldDistSwimUnits, nNewDistSwimUnits, GetLeg1Length()));
    SetLeg2Length(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetLeg2Length()));
    SetLeg3Length(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetLeg3Length()));
}


bool CCourseTriathlon::OptionallySetPR(double dSec)
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


bool CCourseTriathlon::OptionallySetLeg1PR(double dSec)
{
    double dCur = GetLeg1PRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetLeg1PRSeconds(dSec);
        return true;
    }

    return false;
}


bool CCourseTriathlon::OptionallySetLeg2PR(double dSec)
{
    double dCur = GetLeg2PRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetLeg2PRSeconds(dSec);
        return true;
    }

    return false;
}


bool CCourseTriathlon::OptionallySetLeg3PR(double dSec)
{
    double dCur = GetLeg3PRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetLeg3PRSeconds(dSec);
        return true;
    }

    return false;
}


bool CCourseTriathlon::OptionallySetTransition1PR(double dSec)
{
    double dCur = GetTransition1PRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetTransition1PRSeconds(dSec);
        return true;
    }

    return false;
}


bool CCourseTriathlon::OptionallySetTransition2PR(double dSec)
{
    double dCur = GetTransition2PRSeconds();
    // set it if either there is no pr, or the new value is lower (and not NOGRAPHDATA)
	if(CUtil::HasNoData(dCur) || ((dSec < dCur) && CUtil::HasData(dSec)))
    {
        SetTransition2PRSeconds(dSec);
        return true;
    }

    return false;
}


CString CCourseTriathlon::GetName(void) const
{
    return m_strName;
}


CString CCourseTriathlon::GetCity(void) const
{
    return m_strCity;
}


CString CCourseTriathlon::GetState(void) const
{
    return m_strState;
}


CString CCourseTriathlon::GetNotes(void) const
{
    return m_strNotes;
}


double CCourseTriathlon::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


double CCourseTriathlon::GetLeg1PRSeconds(void) const
{
    return m_dLeg1PRSeconds;
}


double CCourseTriathlon::GetLeg2PRSeconds(void) const
{
    return m_dLeg2PRSeconds;
}


double CCourseTriathlon::GetLeg3PRSeconds(void) const
{
    return m_dLeg3PRSeconds;
}


double CCourseTriathlon::GetTransition1PRSeconds(void) const
{
    return m_dTransition1PRSeconds;
}


double CCourseTriathlon::GetTransition2PRSeconds(void) const
{
    return m_dTransition2PRSeconds;
}


double CCourseTriathlon::GetLeg1Length(void) const
{
    return m_dLeg1Length;
}


double CCourseTriathlon::GetLeg2Length(void) const
{
    return m_dLeg2Length;
}


double CCourseTriathlon::GetLeg3Length(void) const
{
    return m_dLeg3Length;
}


CString CCourseTriathlon::GetLeg1Notes(void) const
{
    return m_strLeg1Notes;
}


CString CCourseTriathlon::GetLeg2Notes(void) const
{
    return m_strLeg2Notes;
}


CString CCourseTriathlon::GetLeg3Notes(void) const
{
    return m_strLeg3Notes;
}


void CCourseTriathlon::SetName(CString str)
{
    m_strName = str;
}


void CCourseTriathlon::SetCity(CString str)
{
    m_strCity = str;
}


void CCourseTriathlon::SetState(CString str)
{
    m_strState = str;
}


void CCourseTriathlon::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCourseTriathlon::SetPRSeconds(double dPR)
{
    m_dPRSeconds = dPR;
}


void CCourseTriathlon::SetLeg1PRSeconds(double dPR)
{
    m_dLeg1PRSeconds = dPR;
}


void CCourseTriathlon::SetLeg2PRSeconds(double dPR)
{
    m_dLeg2PRSeconds = dPR;
}


void CCourseTriathlon::SetLeg3PRSeconds(double dPR)
{
    m_dLeg3PRSeconds = dPR;
}


void CCourseTriathlon::SetTransition1PRSeconds(double dPR)
{
    m_dTransition1PRSeconds = dPR;
}


void CCourseTriathlon::SetTransition2PRSeconds(double dPR)
{
    m_dTransition2PRSeconds = dPR;
}


void CCourseTriathlon::SetLeg1Length(double dLen)
{
    m_dLeg1Length = dLen;
}


void CCourseTriathlon::SetLeg2Length(double dLen)
{
    m_dLeg2Length = dLen;
}


void CCourseTriathlon::SetLeg3Length(double dLen)
{
    m_dLeg3Length = dLen;
}


void CCourseTriathlon::SetLeg1Notes(CString str)
{
    m_strLeg1Notes = str;
}


void CCourseTriathlon::SetLeg2Notes(CString str)
{
    m_strLeg2Notes = str;
}


void CCourseTriathlon::SetLeg3Notes(CString str)
{
    m_strLeg3Notes = str;
}