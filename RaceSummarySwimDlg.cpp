#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "RaceSummarySwimDlg.h"


IMPLEMENT_DYNAMIC(CRaceSummarySwimDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CRaceSummarySwimDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnCourseSelChange)
    ON_CBN_SELCHANGE(IDC_DATES, OnDatesSelChange)
END_MESSAGE_MAP()


CRaceSummarySwimDlg::CRaceSummarySwimDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CRaceSummarySwimDlg::IDD, pParent)
{
}


CRaceSummarySwimDlg::~CRaceSummarySwimDlg()
{
}


BOOL CRaceSummarySwimDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_L1DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_SWIM));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseSwimArray(), true, false);

    OnCourseSelChange();

    return TRUE;
}


void CRaceSummarySwimDlg::OnCourseSelChange(void)
{
    CUser* pUser = GetUser();

    SetDlgItemText(IDC_RACEDISTANCE, "");
    SetDlgItemText(IDC_PR, "");
    SetDlgItemText(IDC_TIMERACE, "");
    SetDlgItemText(IDC_RACEPACE, "");
    SetDlgItemText(IDC_PLACE, "");
    SetDlgItemText(IDC_RACENUMBER, "");
    SetDlgItemText(IDC_NOTES, "");

    CComboBox* pCourseBox = (CComboBox*)GetDlgItem(IDC_COURSE);
    if((NULL != pUser) && (NULL != pCourseBox))
    {
        int nSel = pCourseBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            CCourseSwim* pCourse = pUser->GetCourseSwimFromID(nSel);
            if(NULL != pCourse)
            {
                double dMiles = pCourse->GetLength();
                CString strMiles;
                strMiles.Format("%.2lf", dMiles);
                SetDlgItemText(IDC_RACEDISTANCE, strMiles);

                double dPRSeconds = pCourse->GetPRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dPRSeconds, IDC_PR);

                FindDates(pCourse);
                OnDatesSelChange();
            }
        }
    }
}


void CRaceSummarySwimDlg::OnDatesSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pCourseBox = (CComboBox*)GetDlgItem(IDC_COURSE);
    CComboBox* pDateBox = (CComboBox*)GetDlgItem(IDC_DATES);
    if((NULL != pUser) && (NULL != pCourseBox) && (NULL != pDateBox))
    {
        int nSelCourse = pCourseBox->GetCurSel();
        int nSelDate = pDateBox->GetCurSel();
        if((nSelCourse != CB_ERR) && (nSelDate != CB_ERR))
        {
            CCourseSwim* pCourse = pUser->GetCourseSwimFromID(nSelCourse);
            CWorkout* pWorkout = m_rarRaces.GetAt(nSelDate);
            if((NULL != pCourse) && (NULL != pWorkout))
            {
                double dLength = pCourse->GetLength();

                double dSeconds = pWorkout->GetSpecialSeconds();
                
                int nPlace = pWorkout->GetRacePosition();
                int nNum = pWorkout->GetRaceNumber();
                CString strNotes = pWorkout->GetNotes();

                CDlgHelper::HandleDlgPROneTime(this, dSeconds, IDC_TIMERACE);

                CString strPace = CDlgHelper::FormatPace(dSeconds / 60.0, dLength, FORMAT_SWIM);
                SetDlgItemText(IDC_RACEPACE, strPace);

                SetDlgItemInt(IDC_PLACE, nPlace);
                SetDlgItemInt(IDC_RACENUMBER, nNum);
                SetDlgItemText(IDC_NOTES, strNotes);
            }
        }
    }
}


void CRaceSummarySwimDlg::FindDates(CCourseSwim* pCourse)
{
    CComboBox* pDates = (CComboBox*)GetDlgItem(IDC_DATES);
    if(NULL == pDates)
    {
        return;
    }

    bool bHasEntries = false;
    
    pDates->ResetContent();
    m_rarRaces.RemoveAll();

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
                    if(NULL != pWorkout)
                    {
                        if(pCourse == pWorkout->GetCourseSwim())
                        {
                            COleDateTime tmCur = pDay->GetDate();
                            CString strDate;
                            strDate.Format("%d/%d/%d", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());
                            pDates->AddString(strDate);

                            m_rarRaces.Add(pWorkout);  

                            bHasEntries = true;
                        }
                    }
                }
            }
        }
    }

    if(bHasEntries)
    {
        pDates->SetCurSel(0);
    }
    CDlgHelper::ReadyComboBox(pDates, false);
}


void CRaceSummarySwimDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CRaceSummarySwimDlg::GetUser(void) const
{
    return m_pUser;
}


void CRaceSummarySwimDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}