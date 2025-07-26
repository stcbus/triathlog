#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "BikeSummaryDlg.h"


IMPLEMENT_DYNAMIC(CBikeSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CBikeSummaryDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_BIKE, OnSelChange)
    ON_COMMAND(IDC_RETIREBIKE, OnRetire)
	ON_LBN_DBLCLK(IDC_DATES, OnDoubleClick)
END_MESSAGE_MAP()


CBikeSummaryDlg::CBikeSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CBikeSummaryDlg::IDD, pParent)
{
}


CBikeSummaryDlg::~CBikeSummaryDlg()
{
}


BOOL CBikeSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE, "Average Pace"));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, true, false, -1, -1);

    OnSelChange();

    return TRUE;
}


void CBikeSummaryDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pBikeBox = (CComboBox*)GetDlgItem(IDC_BIKE);
    if((NULL != pUser) && (NULL != pBikeBox))
    {
        int nSel = pBikeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            BIKEARRAY& rarBikes = pUser->GetRefBikeArray();
            CBike* pBike = rarBikes.GetAt(nSel);
            if(NULL != pBike)
            {
                COleDateTime tm = pBike->GetFirstDay();
                CString strDate;
                strDate.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
                SetDlgItemText(IDC_PURCHASED, strDate);

                CString strFirst = FindExtremeDate(pBike, true);
                SetDlgItemText(IDC_FIRSTUSED, strFirst);

                CString strLast = FindExtremeDate(pBike, false);
                SetDlgItemText(IDC_LASTUSED, strLast);

                CString strSize;
                double dSize = pBike->GetSize();
                strSize.Format("%.1lf", dSize);
                SetDlgItemText(IDC_SHOESIZE, strSize);

                CString strNotes = pBike->GetNotes();
                SetDlgItemText(IDC_NOTES, strNotes);

                int nWorkouts = pUser->SumWorkoutsBike(pBike);
                CString strWorkouts;
                strWorkouts.Format("%d", nWorkouts);
                SetDlgItemText(IDC_WORKOUTS, strWorkouts);

                double dMinutes = pUser->SumMinutesBike(pBike);
                CString strMinutes = CDlgHelper::FormatTimeNoDecimal(dMinutes);
                SetDlgItemText(IDC_MINUTES, strMinutes);

                double dMiles = pUser->SumMilesBike(pBike);
                CString strMiles;
                strMiles.Format("%.2lf", dMiles);
                SetDlgItemText(IDC_MILES, strMiles);

                CString strPace = CDlgHelper::FormatPace(dMinutes, dMiles, FORMAT_BIKE);
                SetDlgItemText(IDC_PACE, strPace);

                PopulateDatesBox(pBike);

                UpdateRetireButton();
            }
        }
    }
}


void CBikeSummaryDlg::OnDoubleClick(void)
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


void CBikeSummaryDlg::PopulateDatesBox(CBike* pBike)
{
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
                        if(pBike == pWorkout->GetBike())
                        {
                            COleDateTime tmCur = pDay->GetDate();
                            CString strDate;
                            strDate.Format("%d/%d/%d", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());

							// add it if it's not already there
							if(LB_ERR == pList->FindString(0, strDate))
							{
								pList->AddString(strDate);
							}
						}
                    }
                }
            }
        }
    }

    CDlgHelper::OrderDateBox(this, IDC_DATES);
}


CString CBikeSummaryDlg::FindExtremeDate(CBike* pBike, bool fEarliest)
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
                    if(NULL != pWorkout)
                    {
                        if(pBike == pWorkout->GetBike())
                        {
                            COleDateTime tmCur = pDay->GetDate();
                            if((COleDateTime::null == tm.GetStatus()) || (fEarliest == CUtil::IsLaterThan(tm, tmCur)))
                            {
                                tm.SetStatus(COleDateTime::valid);
                                tm = tmCur;
                            }
                        }
                    }
                }
            }
        }
    }

    CString str = "Never";
    if(CUtil::IsDateValid(tm))
    {
        str.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
    }

    return str;
}


void CBikeSummaryDlg::OnRetire(void)
{
    CUser* pUser = GetUser();
    CComboBox* pBikeBox = (CComboBox*)GetDlgItem(IDC_BIKE);
    if((NULL != pUser) && (NULL != pBikeBox))
    {
        int nSel = pBikeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            BIKEARRAY& rarBikes = pUser->GetRefBikeArray();
            CBike* pBike = rarBikes.GetAt(nSel);
            if(NULL != pBike)
            {
                pBike->SetRetired(!pBike->IsRetired());
                UpdateRetireButton();
            }
        }
    }
}


void CBikeSummaryDlg::UpdateRetireButton(void)
{
    CUser* pUser = GetUser();
    CComboBox* pBikeBox = (CComboBox*)GetDlgItem(IDC_BIKE);
    if((NULL != pUser) && (NULL != pBikeBox))
    {
        int nSel = pBikeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            BIKEARRAY& rarBikes = pUser->GetRefBikeArray();
            CBike* pBike = rarBikes.GetAt(nSel);
            if(NULL != pBike)
            {
                if(pBike->IsRetired())
                {
                    SetDlgItemText(IDC_RETIREBIKE, "Unretire");
                }
                else
                {
                    SetDlgItemText(IDC_RETIREBIKE, "Retire");
                }
            }
        }
    }
}


void CBikeSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CBikeSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CBikeSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}