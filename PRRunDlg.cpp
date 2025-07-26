#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "PRRunDlg.h"


IMPLEMENT_DYNAMIC(CPRRunDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPRRunDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnSelChange)
END_MESSAGE_MAP()


CPRRunDlg::CPRRunDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPRRunDlg::IDD, pParent)
{
}


CPRRunDlg::~CPRRunDlg()
{
}


BOOL CPRRunDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_L1DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_RUN));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseRunArray(), true, false);

    OnSelChange();

    return TRUE;
}


void CPRRunDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return;
    }

    bool fOK;
    CString strDist;
    CString strDate;

    CCourseRun* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseRunArray(), fOK);
    if((fOK) && (NULL != pCourse))
    {        
        CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
        double dLength = pCourse->GetLength();
        strDist.Format("%.2lf", dLength);
        SetDlgItemText(IDC_RACEDISTANCE, strDist);

		double dPRSeconds = pCourse->GetPRSeconds();
        CDlgHelper::HandleDlgPaceOneTime(this, dPRSeconds, dLength, IDC_PRPACE, FORMAT_RUN);
        strDate = FindDateRun(pCourse, dPRSeconds);

		if(CUtil::HasData(dPRSeconds))
		{
			SetDlgItemText(IDC_DATERUN, strDate);
		}
		else
		{
			SetDlgItemText(IDC_DATERUN, "");
		}
	}
}


CString CPRRunDlg::FindDateRun(CCourseRun* pCourse, double dTime)
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


void CPRRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CPRRunDlg::GetUser(void) const
{
    return m_pUser;
}


void CPRRunDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}