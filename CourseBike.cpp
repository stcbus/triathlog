#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "Course.h"
#include "CourseBike.h"


CCourseBike::CCourseBike(void)
{
    SetPRSeconds(PRS_NOPR);
}


CCourseBike::~CCourseBike()
{
}


void CCourseBike::AdjustUnits(int nOldDistUnits, int nNewDistUnits)
{
    SetLength(CUtil::ConvertDistance(nOldDistUnits, nNewDistUnits, GetLength()));
}


bool CCourseBike::OptionallySetPR(double dSec)
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


CString CCourseBike::GetName(void) const
{
    return m_strName;
}


CString CCourseBike::GetCity(void) const
{
    return m_strCity;
}


CString CCourseBike::GetState(void) const
{
    return m_strState;
}


double CCourseBike::GetLength(void) const
{
    return m_dLength;
}


CString CCourseBike::GetNotes(void) const
{
    return m_strNotes;
}


double CCourseBike::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


void CCourseBike::SetName(CString str)
{
    m_strName = str;
}


void CCourseBike::SetCity(CString str)
{
    m_strCity = str;
}


void CCourseBike::SetState(CString str)
{
    m_strState = str;
}


void CCourseBike::SetLength(double dLen)
{
    m_dLength = dLen;
}


void CCourseBike::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCourseBike::SetPRSeconds(double dPR)
{
    m_dPRSeconds = dPR;
}