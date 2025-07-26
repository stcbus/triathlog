#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "PRBikeDlg.h"


IMPLEMENT_DYNAMIC(CPRBikeDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPRBikeDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnSelChange)
END_MESSAGE_MAP()


CPRBikeDlg::CPRBikeDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPRBikeDlg::IDD, pParent)
{
}


CPRBikeDlg::~CPRBikeDlg()
{
}


BOOL CPRBikeDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), true, false);

    OnSelChange();

    return TRUE;
}


void CPRBikeDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return;
    }

    bool fOK;
    CString strDist;
    CString strDate;

    CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), fOK);
    if((fOK) && (NULL != pCourse))
    {        
        CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
        double dLength = pCourse->GetLength();
        strDist.Format("%.2lf", dLength);
        SetDlgItemText(IDC_RACEDISTANCE, strDist);

		double dPRSeconds = pCourse->GetPRSeconds();
        CDlgHelper::HandleDlgPaceOneTime(this, dPRSeconds, dLength, IDC_PRPACE, FORMAT_BIKE);
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


CString CPRBikeDlg::FindDateRun(CCourseBike* pCourse, double dTime)
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
                    if((NULL != pWorkout) && (RACETYPE_BIKE == pWorkout->GetType()))
                    {
                        if((pCourse == pWorkout->GetCourseBike()) && (dTime == pWorkout->GetSpecialSeconds()))
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


void CPRBikeDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CPRBikeDlg::GetUser(void) const
{
    return m_pUser;
}


void CPRBikeDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}