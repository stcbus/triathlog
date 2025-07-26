#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "ShoeSummaryBikeDlg.h"


IMPLEMENT_DYNAMIC(CShoeSummaryBikeDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CShoeSummaryBikeDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_SHOES, OnSelChange)
    ON_COMMAND(IDC_RETIRESHOES, OnRetire)
	ON_LBN_DBLCLK(IDC_DATES, OnDoubleClick)
END_MESSAGE_MAP()


CShoeSummaryBikeDlg::CShoeSummaryBikeDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CShoeSummaryBikeDlg::IDD, pParent)
{
}


CShoeSummaryBikeDlg::~CShoeSummaryBikeDlg()
{
}


BOOL CShoeSummaryBikeDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE, "Average Pace"));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, true, false, -1, -1);

    OnSelChange();

    return TRUE;
}


void CShoeSummaryBikeDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pShoeBox = (CComboBox*)GetDlgItem(IDC_SHOES);
    if((NULL != pUser) && (NULL != pShoeBox))
    {
        int nSel = pShoeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            SHOESBIKEARRAY& rarShoes = pUser->GetRefShoesBikeArray();
            CShoesBike* pShoes = rarShoes.GetAt(nSel);
            if(NULL != pShoes)
            {
                COleDateTime tm = pShoes->GetFirstDay();
                CString strDate;
                strDate.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
                SetDlgItemText(IDC_PURCHASED, strDate);

                CString strFirst = FindExtremeDate(pShoes, true);
                SetDlgItemText(IDC_FIRSTUSED, strFirst);

                CString strLast = FindExtremeDate(pShoes, false);
                SetDlgItemText(IDC_LASTUSED, strLast);

                CString strSize;
                double dSize = pShoes->GetSize();
                strSize.Format("%.1lf", dSize);
                SetDlgItemText(IDC_SHOESIZE, strSize);

                CString strNotes = pShoes->GetNotes();
                SetDlgItemText(IDC_NOTES, strNotes);

                int nWorkouts = pUser->SumWorkoutsBike(pShoes);
                CString strWorkouts;
                strWorkouts.Format("%d", nWorkouts);
                SetDlgItemText(IDC_WORKOUTS, strWorkouts);

                double dMinutes = pUser->SumMinutesBike(pShoes);
                CString strMinutes = CDlgHelper::FormatTimeNoDecimal(dMinutes);
                SetDlgItemText(IDC_MINUTES, strMinutes);

                double dMiles = pUser->SumMilesBike(pShoes);
                CString strMiles;
                strMiles.Format("%.2lf", dMiles);
                SetDlgItemText(IDC_MILES, strMiles);

                CString strPace = CDlgHelper::FormatPace(dMinutes, dMiles, FORMAT_BIKE);
                SetDlgItemText(IDC_PACE, strPace);
                
                PopulateDatesBox(pShoes);

                UpdateRetireButton();
            }
        }
    }
}


void CShoeSummaryBikeDlg::OnDoubleClick(void)
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


void CShoeSummaryBikeDlg::PopulateDatesBox(CShoesBike* pShoes)
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
                        if((pShoes == pWorkout->GetShoesBike()) || (pShoes == pWorkout->GetSpecialShoesBike()) ||
                            (pShoes == pWorkout->GetLeg2Shoes()) || (pShoes == pWorkout->GetLeg2RaceShoes()))
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


CString CShoeSummaryBikeDlg::FindExtremeDate(CShoesBike* pShoes, bool fEarliest)
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
                        if((pShoes == pWorkout->GetShoesBike()) || (pShoes == pWorkout->GetSpecialShoesBike()))
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


void CShoeSummaryBikeDlg::OnRetire(void)
{
    CUser* pUser = GetUser();
    CComboBox* pShoeBox = (CComboBox*)GetDlgItem(IDC_SHOES);
    if((NULL != pUser) && (NULL != pShoeBox))
    {
        int nSel = pShoeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            SHOESBIKEARRAY& rarShoes = pUser->GetRefShoesBikeArray();
            CShoesBike* pShoes = rarShoes.GetAt(nSel);
            if(NULL != pShoes)
            {
                pShoes->SetRetired(!pShoes->IsRetired());
                UpdateRetireButton();
            }
        }
    }
}


void CShoeSummaryBikeDlg::UpdateRetireButton(void)
{
    CUser* pUser = GetUser();
    CComboBox* pShoeBox = (CComboBox*)GetDlgItem(IDC_SHOES);
    if((NULL != pUser) && (NULL != pShoeBox))
    {
        int nSel = pShoeBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            SHOESBIKEARRAY& rarShoes = pUser->GetRefShoesBikeArray();
            CShoesBike* pShoes = rarShoes.GetAt(nSel);
            if(NULL != pShoes)
            {
                if(pShoes->IsRetired())
                {
                    SetDlgItemText(IDC_RETIRESHOES, "Unretire");
                }
                else
                {
                    SetDlgItemText(IDC_RETIRESHOES, "Retire");
                }
            }
        }
    }
}


void CShoeSummaryBikeDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CShoeSummaryBikeDlg::GetUser(void) const
{
    return m_pUser;
}


void CShoeSummaryBikeDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}