#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "PRTriathlonDlg.h"


IMPLEMENT_DYNAMIC(CPRTriathlonDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPRTriathlonDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnSelChange)
END_MESSAGE_MAP()


CPRTriathlonDlg::CPRTriathlonDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPRTriathlonDlg::IDD, pParent)
{
}


CPRTriathlonDlg::~CPRTriathlonDlg()
{
}


BOOL CPRTriathlonDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_L1DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_L2DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_L3DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3PACE, CUtil::GetPaceString(FORMAT_RUN));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseTriathlonArray(), true, false);

    OnSelChange();

    return TRUE;
}


void CPRTriathlonDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return;
    }

    bool fOK;
    CString strDist;
    CString strDate;

    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseTriathlonArray(), fOK);
    if((fOK) && (NULL != pCourse))
    {
        // overall
		double dPRSeconds = pCourse->GetPRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dPRSeconds, IDC_PR);
        strDate = FindDateRun(pCourse, dPRSeconds, QUANTITY_OVERALL);
		if(CUtil::HasData(dPRSeconds))
		{
			SetDlgItemText(IDC_DATERUN, strDate);
		}
		else
		{
			SetDlgItemText(IDC_DATERUN, "");
		}

        // trans1
		double dTrans1PRSeconds = pCourse->GetTransition1PRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dTrans1PRSeconds, IDC_TRANSITIONPR1);
        strDate = FindDateRun(pCourse, dTrans1PRSeconds, QUANTITY_TRANS1);
		if(CUtil::HasData(dTrans1PRSeconds))
		{
			SetDlgItemText(IDC_TRANS1DATE, strDate);
		}
		else
		{
			SetDlgItemText(IDC_TRANS1DATE, "");
		}

        // trans2
		double dTrans2PRSeconds = pCourse->GetTransition2PRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dTrans2PRSeconds, IDC_TRANSITIONPR2);
        strDate = FindDateRun(pCourse, dTrans2PRSeconds, QUANTITY_TRANS2);
		if(CUtil::HasData(dTrans2PRSeconds))
		{
			SetDlgItemText(IDC_TRANS2DATE, strDate);
		}
		else
		{
			SetDlgItemText(IDC_TRANS2DATE, "");
		}

        // leg 1
		double dL1PRSeconds = pCourse->GetLeg1PRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dL1PRSeconds, IDC_L1PR);
        double dLeg1Length = pCourse->GetLeg1Length();
        strDist.Format("%.2lf", dLeg1Length);
        SetDlgItemText(IDC_L1RACEDISTANCE, strDist);
        CDlgHelper::HandleDlgPaceOneTime(this, dL1PRSeconds, dLeg1Length, IDC_L1RACEPACE, FORMAT_SWIM);
        strDate = FindDateRun(pCourse, dL1PRSeconds, QUANTITY_LEG1);
		if(CUtil::HasData(dL1PRSeconds))
		{
			SetDlgItemText(IDC_L1DATERUN, strDate);
		}
		else
		{
			SetDlgItemText(IDC_L1DATERUN, "");
		}

        // leg 2
		double dL2PRSeconds = pCourse->GetLeg2PRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dL2PRSeconds, IDC_L2PR);
        double dLeg2Length = pCourse->GetLeg2Length();
        strDist.Format("%.2lf", dLeg2Length);
        SetDlgItemText(IDC_L2RACEDISTANCE, strDist);
        CDlgHelper::HandleDlgPaceOneTime(this, dL2PRSeconds, dLeg2Length, IDC_L2RACEPACE, FORMAT_BIKE);
        strDate = FindDateRun(pCourse, dL2PRSeconds, QUANTITY_LEG2);
		if(CUtil::HasData(dL2PRSeconds))
		{
			SetDlgItemText(IDC_L2DATERUN, strDate);
		}
		else
		{
			SetDlgItemText(IDC_L2DATERUN, "");
		}

        // leg 3
		double dL3PRSeconds = pCourse->GetLeg3PRSeconds();
        CDlgHelper::HandleDlgPROneTime(this, dL3PRSeconds, IDC_L3PR);
        double dLeg3Length = pCourse->GetLeg3Length();
        strDist.Format("%.2lf", dLeg3Length);
        SetDlgItemText(IDC_L3RACEDISTANCE, strDist);
        CDlgHelper::HandleDlgPaceOneTime(this, dL3PRSeconds, dLeg3Length, IDC_L3RACEPACE, FORMAT_RUN);
        strDate = FindDateRun(pCourse, dL3PRSeconds, QUANTITY_LEG3);
		if(CUtil::HasData(dL3PRSeconds))
		{
			SetDlgItemText(IDC_L3DATERUN, strDate);
		}
		else
		{
			SetDlgItemText(IDC_L3DATERUN, "");
		}
    }
}


CString CPRTriathlonDlg::FindDateRun(CCourseTriathlon* pCourse, double dTime, int nQuantity)
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
                    if((NULL != pWorkout) && (RACETYPE_TRIATHLON == pWorkout->GetType()))
                    {
                        if(pCourse == pWorkout->GetCourseTriathlon())
                        {
                            if(((QUANTITY_OVERALL == nQuantity) && (dTime == pWorkout->GetSeconds())) ||
                               ((QUANTITY_TRANS1 == nQuantity) && (dTime == pWorkout->GetTransition1Seconds())) ||
                               ((QUANTITY_TRANS2 == nQuantity) && (dTime == pWorkout->GetTransition2Seconds())) || 
                               ((QUANTITY_LEG1 == nQuantity) && (dTime == pWorkout->GetLeg1RaceSeconds())) ||
                               ((QUANTITY_LEG2 == nQuantity) && (dTime == pWorkout->GetLeg2RaceSeconds())) ||
                               ((QUANTITY_LEG3 == nQuantity) && (dTime == pWorkout->GetLeg3RaceSeconds())))
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
    }

DONE:

    CString str = "Initial PR";
    if(CUtil::IsDateValid(tm))
    {
        str.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
    }

    return str;
}


void CPRTriathlonDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CPRTriathlonDlg::GetUser(void) const
{
    return m_pUser;
}


void CPRTriathlonDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}
