#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Course.h"
#include "CourseDuathlon.h"


CCourseDuathlon::CCourseDuathlon(void)
{
    SetPRSeconds(PRS_NOPR);
    SetLeg1PRSeconds(PRS_NOPR);
    SetLeg2PRSeconds(PRS_NOPR);
    SetLeg3PRSeconds(PRS_NOPR);
    SetTransition1PRSeconds(PRS_NOPR);
    SetTransition2PRSeconds(PRS_NOPR);
}


CCourseDuathlon::~CCourseDuathlon()
{
}


void CCourseDuathlon::AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits,
                                  int nNewDistRunUnits, int nNewDistBikeUnits)
{
    SetLeg1Length(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetLeg1Length()));
    SetLeg2Length(CUtil::ConvertDistance(nOldDistBikeUnits, nNewDistBikeUnits, GetLeg2Length()));
    SetLeg3Length(CUtil::ConvertDistance(nOldDistRunUnits, nNewDistRunUnits, GetLeg3Length()));
}


bool CCourseDuathlon::OptionallySetPR(double dSec)
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


bool CCourseDuathlon::OptionallySetLeg1PR(double dSec)
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


bool CCourseDuathlon::OptionallySetLeg2PR(double dSec)
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


bool CCourseDuathlon::OptionallySetLeg3PR(double dSec)
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


bool CCourseDuathlon::OptionallySetTransition1PR(double dSec)
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


bool CCourseDuathlon::OptionallySetTransition2PR(double dSec)
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


CString CCourseDuathlon::GetName(void) const
{
    return m_strName;
}


CString CCourseDuathlon::GetCity(void) const
{
    return m_strCity;
}


CString CCourseDuathlon::GetState(void) const
{
    return m_strState;
}


CString CCourseDuathlon::GetNotes(void) const
{
    return m_strNotes;
}


double CCourseDuathlon::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


double CCourseDuathlon::GetLeg1PRSeconds(void) const
{
    return m_dLeg1PRSeconds;
}


double CCourseDuathlon::GetLeg2PRSeconds(void) const
{
    return m_dLeg2PRSeconds;
}


double CCourseDuathlon::GetLeg3PRSeconds(void) const
{
    return m_dLeg3PRSeconds;
}


double CCourseDuathlon::GetTransition1PRSeconds(void) const
{
    return m_dTransition1PRSeconds;
}


double CCourseDuathlon::GetTransition2PRSeconds(void) const
{
    return m_dTransition2PRSeconds;
}


double CCourseDuathlon::GetLeg1Length(void) const
{
    return m_dLeg1Length;
}


double CCourseDuathlon::GetLeg2Length(void) const
{
    return m_dLeg2Length;
}


double CCourseDuathlon::GetLeg3Length(void) const
{
    return m_dLeg3Length;
}


CString CCourseDuathlon::GetLeg1Notes(void) const
{
    return m_strLeg1Notes;
}


CString CCourseDuathlon::GetLeg2Notes(void) const
{
    return m_strLeg2Notes;
}


CString CCourseDuathlon::GetLeg3Notes(void) const
{
    return m_strLeg3Notes;
}


void CCourseDuathlon::SetName(CString str)
{
    m_strName = str;
}


void CCourseDuathlon::SetCity(CString str)
{
    m_strCity = str;
}


void CCourseDuathlon::SetState(CString str)
{
    m_strState = str;
}


void CCourseDuathlon::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCourseDuathlon::SetPRSeconds(double dPR)
{
    m_dPRSeconds = dPR;
}


void CCourseDuathlon::SetLeg1PRSeconds(double dPR)
{
    m_dLeg1PRSeconds = dPR;
}


void CCourseDuathlon::SetLeg2PRSeconds(double dPR)
{
    m_dLeg2PRSeconds = dPR;
}


void CCourseDuathlon::SetLeg3PRSeconds(double dPR)
{
    m_dLeg3PRSeconds = dPR;
}


void CCourseDuathlon::SetTransition1PRSeconds(double dPR)
{
    m_dTransition1PRSeconds = dPR;
}


void CCourseDuathlon::SetTransition2PRSeconds(double dPR)
{
    m_dTransition2PRSeconds = dPR;
}


void CCourseDuathlon::SetLeg1Length(double dLen)
{
    m_dLeg1Length = dLen;
}


void CCourseDuathlon::SetLeg2Length(double dLen)
{
    m_dLeg2Length = dLen;
}


void CCourseDuathlon::SetLeg3Length(double dLen)
{
    m_dLeg3Length = dLen;
}


void CCourseDuathlon::SetLeg1Notes(CString str)
{
    m_strLeg1Notes = str;
}


void CCourseDuathlon::SetLeg2Notes(CString str)
{
    m_strLeg2Notes = str;
}


void CCourseDuathlon::SetLeg3Notes(CString str)
{
    m_strLeg3Notes = str;
}