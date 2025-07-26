#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "LocationSummaryStrengthDlg.h"


IMPLEMENT_DYNAMIC(CLocationSummaryStrengthDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CLocationSummaryStrengthDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_LOCATIONS, OnSelChange)
	ON_LBN_DBLCLK(IDC_DATES, OnDoubleClick)
END_MESSAGE_MAP()


CLocationSummaryStrengthDlg::CLocationSummaryStrengthDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CLocationSummaryStrengthDlg::IDD, pParent)
{
}


CLocationSummaryStrengthDlg::~CLocationSummaryStrengthDlg()
{
}


BOOL CLocationSummaryStrengthDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATIONS), pUser->GetRefLocationStrengthArray(), true, false);

    OnSelChange();

    return TRUE;
}


void CLocationSummaryStrengthDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pLocBox = (CComboBox*)GetDlgItem(IDC_LOCATIONS);
    if((NULL != pUser) && (NULL != pLocBox))
    {
        int nSel = pLocBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            LOCATIONSTRENGTHARRAY& rarLocs = pUser->GetRefLocationStrengthArray();
            CLocationStrength* pLocation = rarLocs.GetAt(nSel);
            if(NULL != pLocation)
            {
                CString strCity = pLocation->GetCity();
                SetDlgItemText(IDC_CITY, strCity);

                CString strState = pLocation->GetState();
                SetDlgItemText(IDC_STATE, strState);

                CString strNotes = pLocation->GetNotes();
                SetDlgItemText(IDC_NOTES, strNotes);

                int nWorkouts = 0;
                double dMinutes = 0.0;
                double dMiles = 0.0;

                ComputeLocationData(pLocation, nWorkouts, dMinutes);

                CString strWorkouts;
                strWorkouts.Format("%d", nWorkouts);
                SetDlgItemText(IDC_WORKOUTS, strWorkouts);

                CString strMinutes = CDlgHelper::FormatTimeNoDecimal(dMinutes);
                SetDlgItemText(IDC_MINUTES, strMinutes);
            }
        }
    }
}


void CLocationSummaryStrengthDlg::OnDoubleClick(void)
{
    CUser* pUser = GetUser();

    CListBox* pListBox = (CListBox*)GetDlgItem(IDC_DATES);
    if((NULL != pUser) && (NULL != pListBox))
    {
		int nSel = pListBox->GetCurSel();
        if(nSel != CB_ERR)
        {
			CString strCur;
			pListBox->GetText(nSel, strCur);

			// get date out (in format month/day/year)
			int n1 = strCur.Find('/');
			CString strMonth;
			if(-1 != n1)
			{
				strMonth = strCur.Left(n1);
			}

			strCur = strCur.Right(strCur.GetLength() - n1 - 1);
			int n2 = strCur.Find('/');
			CString strDay;
			if(-1 != n2)
			{
				strDay = strCur.Left(n2);
			}

			CString strYear = strCur.Right(strCur.GetLength() - n2 - 1);

			int nMonth = atoi(strMonth);
			int nDay = atoi(strDay);
			int nYear = atoi(strYear);

			// the day we want to pop up the summary for
			COleDateTime tmStart(nYear, nMonth, nDay, 1, 1, 1);

			CRunningLogView* pParent = (CRunningLogView*)GetParent();
			if(NULL != pParent)
			{
				pParent->MakeDaySummarySheet(tmStart, pUser, this, false);
			}
		}
	}
}


void CLocationSummaryStrengthDlg::ComputeLocationData(CLocationStrength* pLocation, int& rnWorkouts, double& rdMinutes)
{
    rnWorkouts = 0;
    rdMinutes = 0.0;

    CListBox* pList = (CListBox*)GetDlgItem(IDC_DATES);
    if(NULL == pList)
    {
        return;
    }
    
    pList->ResetContent();

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
                        if(pLocation == pWorkout->GetLocationStrength())
                        {
                            COleDateTime tmCur = pDay->GetDate();
                            CString strDate;
                            strDate.Format("%d/%d/%d", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());

							// add it if it's not already there
							if(LB_ERR == pList->FindString(0, strDate))
							{
								pList->AddString(strDate);
							}

                            rnWorkouts++;
                            rdMinutes += pWorkout->GetSeconds() / 60.0;
                        }
                    }
                }
            }
        }
    }

    CDlgHelper::OrderDateBox(this, IDC_DATES);
}


void CLocationSummaryStrengthDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CLocationSummaryStrengthDlg::GetUser(void) const
{
    return m_pUser;
}


void CLocationSummaryStrengthDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}