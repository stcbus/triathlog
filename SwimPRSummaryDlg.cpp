#include "StdAfx.h"
#include <math.h>
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "SwimPRSummaryDlg.h"


CSwimPRSummaryDlg::CSwimPRSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CSwimPRSummaryDlg::IDD, pParent)
{
}


CSwimPRSummaryDlg::~CSwimPRSummaryDlg()
{
}


BOOL CSwimPRSummaryDlg::OnInitDialog(void)
{
    BOOL bRes = CAniDialog::OnInitDialog();
    CString strNA = "N/A";

    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));

    CCourseSwim* pCourse50 = FindCourse("50m Freestyle", strNA, strNA, MetersToMiles(50));
    DisplayCourse(pCourse50, IDC_50, IDC_50PACE, IDC_50DATE);

    CCourseSwim* pCourse100 = FindCourse("100m Freestyle", strNA, strNA, MetersToMiles(100));
    DisplayCourse(pCourse100, IDC_100, IDC_100PACE, IDC_100DATE);

    CCourseSwim* pCourse200 = FindCourse("200m Freestyle", strNA, strNA, MetersToMiles(200));
    DisplayCourse(pCourse200, IDC_200, IDC_200PACE, IDC_200DATE);

    CCourseSwim* pCourse400 = FindCourse("400m Freestyle", strNA, strNA, MetersToMiles(400));
    DisplayCourse(pCourse400, IDC_400, IDC_400PACE, IDC_400DATE);

    CCourseSwim* pCourse800 = FindCourse("800m Freestyle", strNA, strNA, MetersToMiles(800));
    DisplayCourse(pCourse800, IDC_800, IDC_800PACE, IDC_800DATE);

    CCourseSwim* pCourse1500 = FindCourse("1500m Freestyle", strNA, strNA, MetersToMiles(1500));
    DisplayCourse(pCourse1500, IDC_1500, IDC_1500PACE, IDC_1500DATE);

    return bRes;
}


CCourseSwim* CSwimPRSummaryDlg::FindCourse(CString strName, CString strCity, CString strState, double dLen)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COURSESWIMARRAY& rarCourses = pUser->GetRefCourseSwimArray();
        int iCount = (int)rarCourses.GetCount();
        for(int i = 0; i < iCount; i++)
        {
            CCourseSwim* pCur = rarCourses.ElementAt(i);
            if(NULL != pCur)
            {
                if((strName == pCur->GetName()) && (strCity == pCur->GetCity()) && 
                    (strState == pCur->GetState()) && (fabs(pCur->GetLength() - dLen) < .01))
                {
                    return pCur;
                }
            }
        }
    }

    return NULL;
}


void CSwimPRSummaryDlg::DisplayCourse(CCourseSwim* pCourse, int nID, int nIDPace, int nIDDate)
{
    if(NULL == pCourse)
    {
        return;
    }
    double dSeconds = pCourse->GetPRSeconds();

	if(CUtil::HasData(dSeconds) && (dSeconds > 0))
    {
        CDlgHelper::SetDlgOneTime(this, nID, dSeconds);

        CString strPace = CDlgHelper::FormatPace(dSeconds / 60.0, pCourse->GetLength(), FORMAT_SWIM);
        SetDlgItemText(nIDPace, strPace);

        CString strDate = FindDateRun(pCourse, dSeconds);
        SetDlgItemText(nIDDate, strDate);
    }
}


CString CSwimPRSummaryDlg::FindDateRun(CCourseSwim* pCourse, double dTime)
{
    COleDateTime tm;
    tm.SetStatus(COleDateTime::null);

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        DAYARRAY& rarDays = pUser->GetRefDayArray();
        for(int i = 0; i < rarDays.GetCount(); i++)
        {
            CDayLog* pDay = rarDays.GetAt(i);
            if(NULL != pDay)
            {
                WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
                for(int j = 0; j < rarWorkouts.GetCount(); j++)
                {
                    CWorkout* pWorkout = rarWorkouts.GetAt(j);
                    if((NULL != pWorkout) && (RACETYPE_SWIM == pWorkout->GetType()))
                    {
                        if((pCourse == pWorkout->GetCourseSwim()) && (dTime == pWorkout->GetSpecialSeconds()))
                        {
                            tm.SetStatus(COleDateTime::valid);
                            tm = pDay->GetDate();
                            goto DONE;
                        }
                    }
                }
            }
        }
    }

DONE:

    CString str = "Initial PR";
    if(CUtil::IsDateValid(tm))
    {
        str.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
    }

    return str;
}


void CSwimPRSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CSwimPRSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CSwimPRSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}