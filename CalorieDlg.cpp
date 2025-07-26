#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "CalorieDlg.h"


BEGIN_MESSAGE_MAP(CCalorieDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_WORKOUTS, OnSelChange)
END_MESSAGE_MAP()


CCalorieDlg::CCalorieDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CCalorieDlg::IDD, pParent)
{
	m_pUser = NULL;
}


CCalorieDlg::~CCalorieDlg()
{
}


BOOL CCalorieDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString());

	COleDateTime tmFrom = GetTimeFrom();
	COleDateTime tmTo = GetTimeTo();

	CString str;
	str.Format("Calories Burned: %d/%d/%d to %d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear(),
														tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());
	SetWindowText(str);

    CUser* pUser = GetUser();
    CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_WORKOUTS);
    if((NULL == pUser) || (NULL == pBox))
    {
		return FALSE;
	}

	int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom);
	if(nDays < 0)
	{
		return FALSE;
	}

	for(int i = 0; i < nDays + 1; i++)
	{
		COleDateTime tmCur = CUtil::OffsetDay(tmFrom, i);
		CDayLog* pCurDay = pUser->GetDayAt(tmCur);
		if(NULL != pCurDay)
		{
			WORKOUTARRAY& rarCur = pCurDay->GetRefWorkoutArray();
			for(int j = 0; j < (int)rarCur.GetCount(); j++)
			{
				CWorkout* pWorkout = rarCur.GetAt(j);
				if(NULL != pWorkout)
				{
					m_arWorkouts.Add(rarCur.GetAt(j));
					str.Format("%d/%d/%d: %s (%s)", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear(), 
						pWorkout->GetDisplayName(), CUtil::ActivityToString(pWorkout->GetActivityType())); 
					pBox->AddString(str);
				}
			}
		}
	}

	pBox->SetCurSel(0);

	int nNumRunWorkouts = 0;
	int nNumBikeWorkouts = 0;
	int nNumSwimWorkouts = 0;
	int nNumStrWorkouts = 0;
	int nNumRaceWorkouts = 0;
	double dRunCals = 0.0;
	double dBikeCals = 0.0;
	double dSwimCals = 0.0;
	double dStrCals = 0.0;
	double dRaceCals = 0.0;

	for(int i = 0; i < (int)m_arWorkouts.GetCount(); i++)
	{
		CWorkout* pWorkout = m_arWorkouts.GetAt(i);

		if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
		{
			nNumRunWorkouts++;			
			dRunCals += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles());
		}
		else if(ACTIVITY_BIKING == pWorkout->GetActivityType())
		{
			nNumBikeWorkouts++;			
			dBikeCals += CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
		}
		else if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
		{
			nNumSwimWorkouts++;			
			dSwimCals += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
		}
		else if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
		{
			nNumStrWorkouts++;			
			dStrCals += CUtil::ComputeStrengthCalories(pWorkout->GetWeight(), pWorkout->GetSeconds());
		}
		else if(ACTIVITY_RACE == pWorkout->GetActivityType())
		{
			nNumRaceWorkouts++;
			if(RACETYPE_RUN == pWorkout->GetType())
			{
				dRaceCals += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles());
			}
			else if(RACETYPE_BIKE == pWorkout->GetType())
			{
				dRaceCals += CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
			}
			else if(RACETYPE_SWIM == pWorkout->GetType())
			{
				dRaceCals += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
			}
			else if(RACETYPE_DUATHLON == pWorkout->GetType())
			{
				dRaceCals += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles()) +
							 CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
							 CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles());
			}
			else if(RACETYPE_TRIATHLON == pWorkout->GetType())
			{
				dRaceCals += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles(), pWorkout->GetLeg1Seconds()) +
							 CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
							 CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles());
			}
		}
	}

	int nNumTotalWorkouts = nNumRunWorkouts + nNumBikeWorkouts + nNumSwimWorkouts + nNumStrWorkouts + nNumRaceWorkouts;
	double dTotCals = dRunCals + dBikeCals + dSwimCals + dStrCals + dRaceCals;

	str.Format("%d %s, %.1lf calories burned", nNumRunWorkouts, nNumRunWorkouts == 1 ? "workout" : "workouts", dRunCals);
	SetDlgItemText(IDT_RUNNING, str);

	str.Format("%d %s, %.1lf calories burned", nNumBikeWorkouts, nNumBikeWorkouts == 1 ? "workout" : "workouts", dBikeCals);
	SetDlgItemText(IDT_BIKING, str);

	str.Format("%d %s, %.1lf calories burned", nNumSwimWorkouts, nNumSwimWorkouts == 1 ? "workout" : "workouts", dSwimCals);
	SetDlgItemText(IDT_SWIMMING, str);

	str.Format("%d %s, %.1lf calories burned", nNumStrWorkouts, nNumStrWorkouts == 1 ? "workout" : "workouts", dStrCals);
	SetDlgItemText(IDT_STRENGTH, str);

	str.Format("%d %s, %.1lf calories burned", nNumRaceWorkouts, nNumRaceWorkouts == 1 ? "workout" : "workouts", dRaceCals);
	SetDlgItemText(IDT_RACING, str);

	str.Format("%d %s, %.1lf calories burned", nNumTotalWorkouts, nNumTotalWorkouts == 1 ? "workout" : "workouts", dTotCals);
	SetDlgItemText(IDT_TOTAL, str);

	CDlgHelper::ReadyComboBox(pBox, false);

    OnSelChange();

    return TRUE;
}


void CCalorieDlg::OnSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_WORKOUTS);
    if((NULL != pUser) && (NULL != pBox))
    {
        int nSel = pBox->GetCurSel();
        if(nSel != CB_ERR)
        {
			CString str;

            CWorkout* pWorkout = m_arWorkouts.GetAt(nSel);
            if(NULL != pWorkout)
            {
				CDlgHelper::SetDlgOneTime(this, IDC_TIME, pWorkout->GetSeconds());
				CDlgHelper::SetDlgDouble(this, IDC_WEIGHT, pWorkout->GetWeight(), 1);

				if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
				{
					CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
					SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
					str.Format("%.1lf", CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles())); 
					SetDlgItemText(IDC_INDCALORIES, str);
				}
				else if(ACTIVITY_BIKING == pWorkout->GetActivityType())
				{
					CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
					SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
					str.Format("%.1lf", CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds()));
					SetDlgItemText(IDC_INDCALORIES, str);
				}
				else if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
				{
					CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
					SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
					str.Format("%.1lf", CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds()));
					SetDlgItemText(IDC_INDCALORIES, str);
				}
				else if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
				{
					SetDlgItemText(IDC_DISTANCE, "");
					SetDlgItemText(IDT_DIST, "Distance (N/A)");
					str.Format("%.1lf", CUtil::ComputeStrengthCalories(pWorkout->GetWeight(), pWorkout->GetSeconds()));
					SetDlgItemText(IDC_INDCALORIES, str);
				}
				else if(ACTIVITY_RACE == pWorkout->GetActivityType())
				{
					if(RACETYPE_RUN == pWorkout->GetType())
					{
						CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
						SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
						str.Format("%.1lf", CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles()));
						SetDlgItemText(IDC_INDCALORIES, str);
					}
					else if(RACETYPE_BIKE == pWorkout->GetType())
					{
						CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
						SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
						str.Format("%.1lf", CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds()));
						SetDlgItemText(IDC_INDCALORIES, str);
					}
					else if(RACETYPE_SWIM == pWorkout->GetType())
					{
						CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), 2);
						SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
						str.Format("%.1lf", CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds()));
						SetDlgItemText(IDC_INDCALORIES, str);
					}
					else if(RACETYPE_DUATHLON == pWorkout->GetType())
					{
						SetDlgItemText(IDC_DISTANCE, "");
						SetDlgItemText(IDT_DIST, "Distance (N/A)");
						str.Format("%.1lf", CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles()) +
										   CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
										   CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles()));
						SetDlgItemText(IDC_INDCALORIES, str);
					}
					else if(RACETYPE_TRIATHLON == pWorkout->GetType())
					{
						SetDlgItemText(IDC_DISTANCE, "");
						SetDlgItemText(IDT_DIST, "Distance (N/A)");
						str.Format("%.1lf", CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles(), pWorkout->GetLeg1Seconds()) +
										   CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
										   CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles()));
						SetDlgItemText(IDC_INDCALORIES, str);
					}
				}
            }
        }
    }
}


void CCalorieDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CCalorieDlg::GetTimeFrom(void) const
{
	return m_tmFrom;
}


COleDateTime CCalorieDlg::GetTimeTo(void) const
{
	return m_tmTo;
}


void CCalorieDlg::SetDates(COleDateTime tmFrom, COleDateTime tmTo)
{
	m_tmFrom = tmFrom;
	m_tmTo = tmTo;
}


CUser* CCalorieDlg::GetUser(void) const
{
    return m_pUser;
}


void CCalorieDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}
