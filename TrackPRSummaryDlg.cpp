#include "StdAfx.h"
#include <math.h>
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "TrackPRSummaryDlg.h"


CTrackPRSummaryDlg::CTrackPRSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CTrackPRSummaryDlg::IDD, pParent)
{
}


CTrackPRSummaryDlg::~CTrackPRSummaryDlg()
{
}


BOOL CTrackPRSummaryDlg::OnInitDialog(void)
{
    BOOL bRes = CAniDialog::OnInitDialog();
    CString strNA = "N/A";

    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));

    CCourseRun* pCourse400 = FindCourse("Track 400m", strNA, strNA, MetersToMiles(400));
    DisplayCourse(pCourse400, IDC_400, IDC_400PACE, IDC_400DATE2);

    CCourseRun* pCourse800 = FindCourse("Track 800m", strNA, strNA, MetersToMiles(800));
    DisplayCourse(pCourse800, IDC_800, IDC_800PACE2, IDC_800DATE);

    CCourseRun* pCourse1500 = FindCourse("Track 1500m", strNA, strNA, MetersToMiles(1500));
    DisplayCourse(pCourse1500, IDC_1500, IDC_1500PACE2, IDC_1500DATE);

    CCourseRun* pCourse1600 = FindCourse("Track 1600m", strNA, strNA, MetersToMiles(1600));
    DisplayCourse(pCourse1600, IDC_1600, IDC_1600PACE, IDC_1600DATE);

    CCourseRun* pCourseMile = FindCourse("Track Mile", strNA, strNA, 1.000);
    DisplayCourse(pCourseMile, IDC_1MILE, IDC_1MILEPACE, IDC_1MILEDATE);

    CCourseRun* pCourse3000 = FindCourse("Track 3000m", strNA, strNA, MetersToMiles(3000));
    DisplayCourse(pCourse3000, IDC_3000, IDC_3000PACE, IDC_3000DATE);

    CCourseRun* pCourse3200 = FindCourse("Track 3200m", strNA, strNA, MetersToMiles(3200));
    DisplayCourse(pCourse3200, IDC_3200, IDC_3200PACE, IDC_3200DATE);

    CCourseRun* pCourse2Mile = FindCourse("Track 2 Mile", strNA, strNA, 2.000);
    DisplayCourse(pCourse2Mile, IDC_2MILE, IDC_2MILEPACE, IDC_2MILEDATE);

    CCourseRun* pCourse5000 = FindCourse("Track 5000m", strNA, strNA, MetersToMiles(5000));
    DisplayCourse(pCourse5000, IDC_5000, IDC_5000PACE, IDC_5000DATE);

    CCourseRun* pCourse10000 = FindCourse("Track 10000m", strNA, strNA, MetersToMiles(10000));
    DisplayCourse(pCourse10000, IDC_10000, IDC_10000PACE, IDC_10000DATE);

    CCourseRun* pCourse3000Steeple = FindCourse("Track 3000m Steeple", strNA, strNA, MetersToMiles(3000));
    DisplayCourse(pCourse3000Steeple, IDC_STEEPLE, IDC_STEEPLEPACE, IDC_STEEPLEDATE);

    return bRes;
}


CCourseRun* CTrackPRSummaryDlg::FindCourse(CString strName, CString strCity, CString strState, double dLen)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        COURSERUNARRAY& rarCourses = pUser->GetRefCourseRunArray();
        int iCount = (int)rarCourses.GetCount();
        for(int i = 0; i < iCount; i++)
        {
            CCourseRun* pCur = rarCourses.ElementAt(i);
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


void CTrackPRSummaryDlg::DisplayCourse(CCourseRun* pCourse, int nID, int nIDPace, int nIDDate)
{
    if(NULL == pCourse)
    {
        return;
    }
    double dSeconds = pCourse->GetPRSeconds();

	if(CUtil::HasData(dSeconds) && (dSeconds > 0))
    {
        CDlgHelper::SetDlgOneTime(this, nID, dSeconds);

        CString strPace = CDlgHelper::FormatPace(dSeconds / 60.0, pCourse->GetLength(), FORMAT_RUN);
        SetDlgItemText(nIDPace, strPace);

        CString strDate = FindDateRun(pCourse, dSeconds);
        SetDlgItemText(nIDDate, strDate);
    }
}


CString CTrackPRSummaryDlg::FindDateRun(CCourseRun* pCourse, double dTime)
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
                    if((NULL != pWorkout) && (RACETYPE_RUN == pWorkout->GetType()))
                    {
                        if((pCourse == pWorkout->GetCourseRun()) && (dTime == pWorkout->GetSpecialSeconds()))
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


void CTrackPRSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CTrackPRSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CTrackPRSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}