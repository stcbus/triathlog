#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "PRSwimDlg.h"


IMPLEMENT_DYNAMIC(CPRSwimDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPRSwimDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnSelChange)
END_MESSAGE_MAP()


CPRSwimDlg::CPRSwimDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPRSwimDlg::IDD, pParent)
{
}


CPRSwimDlg::~CPRSwimDlg()
{
}


BOOL CPRSwimDlg::OnInitDialog(void)
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

    OnSelChange();

    return TRUE;
}


void CPRSwimDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return;
    }

    bool fOK;
    CString strDist;
    CString strDate;

    CCourseSwim* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseSwimArray(), fOK);
    if((fOK) && (NULL != pCourse))
    {        
        CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
        double dLength = pCourse->GetLength();
        strDist.Format("%.2lf", dLength);
        SetDlgItemText(IDC_RACEDISTANCE, strDist);

		double dPRSeconds = pCourse->GetPRSeconds();
        CDlgHelper::HandleDlgPaceOneTime(this, dPRSeconds, dLength, IDC_PRPACE, FORMAT_SWIM);
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


CString CPRSwimDlg::FindDateRun(CCourseSwim* pCourse, double dTime)
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


void CPRSwimDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CPRSwimDlg::GetUser(void) const
{
    return m_pUser;
}


void CPRSwimDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}