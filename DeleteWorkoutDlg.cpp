#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DayLog.h"
#include "User.h"
#include "DeleteWorkoutDlg.h"


IMPLEMENT_DYNAMIC(CDeleteWorkoutDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDeleteWorkoutDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_WORKOUTS, OnWorkoutSelChange)
    ON_BN_CLICKED(ID_DELETE, OnDelete)
END_MESSAGE_MAP()


CDeleteWorkoutDlg::CDeleteWorkoutDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDeleteWorkoutDlg::IDD, pParent)
{
    SetChanged(false);
	SetDeleteType(EDeleteWorkout);
}


CDeleteWorkoutDlg::~CDeleteWorkoutDlg()
{
}


BOOL CDeleteWorkoutDlg::OnInitDialog(void)
{
    BOOL bRes = CAniDialog::OnInitDialog();

	if(EDeleteWorkout == GetDeleteType())
	{
		SetWindowText("Delete Workout");
	}
	else if(EDeleteUpcomingRace == GetDeleteType())
	{
		SetWindowText("Delete Upcoming Race");
	}
	else if(EDeleteUpcomingWorkout == GetDeleteType())
	{
		SetWindowText("Delete Planned Workout");
	}
	else
	{
		CUtil::Fatal("Bad delete value given in CDeleteWorkoutDlg::OnInitDialog");
		SetDeleteType(EDeleteWorkout);
	}

    FillWorkoutBox();
    OnWorkoutSelChange();

    return bRes;
}


void CDeleteWorkoutDlg::FillWorkoutBox(void)
{
    CString strCombo;
	int nType = GetDeleteType();

    int nSel = 0;

    CDayLog* pDay = GetDay();
	CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CComboBox* pWorkoutBox = (CComboBox*)GetDlgItem(IDC_WORKOUTS);
        if(NULL != pWorkoutBox)
        {
            nSel = pWorkoutBox->GetCurSel();
            pWorkoutBox->ResetContent();

			if((EDeleteWorkout == nType) && (NULL != pDay))
			{
				WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
				for(int i = 0; i < (int)rarWorkouts.GetCount(); i++)
				{
					CWorkout* pWorkout = rarWorkouts.GetAt(i);
					if(NULL != pWorkout)
					{
						int nActType = pWorkout->GetActivityType();
						int nType = pWorkout->GetType();
						strCombo.Format("Workout %d: %s | %s", i + 1, CUtil::ActivityToString(nActType),
										CUtil::WorkoutToString(pWorkout));

						pWorkoutBox->AddString(strCombo);
					}
				}
			}
			else if(EDeleteUpcomingRace == nType)
			{  // TODO: work here, day doesn't have this, user has it.
				CUpcomingRace* pUpcoming = pUser->GetUpcomingRaceAt(GetDate());
				
				if(NULL != pUpcoming)
				{
					strCombo = "Upcoming Race";

					pWorkoutBox->AddString(strCombo);
				}
			}
			else if(EDeleteUpcomingWorkout == nType)
			{  // TODO: work here, day doesn't have this, user has it.
				CUpcomingWorkout* pUpcoming = pUser->GetUpcomingWorkoutAt(GetDate());
				
				if(NULL != pUpcoming)
				{
					strCombo = "Planned Workout";

					pWorkoutBox->AddString(strCombo);
				}
			}

            CDlgHelper::ReadyComboBox(pWorkoutBox, true);

            if(-1 == nSel)
            {
                nSel = 0;
            }
            if(nSel >= pWorkoutBox->GetCount())
            {
                nSel = pWorkoutBox->GetCount() - 1;
            }

            if(pWorkoutBox->GetCount() > 0)
            {
                pWorkoutBox->SetCurSel(nSel);
            }
        }
    }
}


void CDeleteWorkoutDlg::OnWorkoutSelChange(void)
{
    CString str;
    SetDlgItemText(IDC_DISPLAY, "");

    CDayLog* pDay = GetDay();
	CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CComboBox* pWorkoutBox = (CComboBox*)GetDlgItem(IDC_WORKOUTS);
        if(NULL != pWorkoutBox)
        {
            int nSel = pWorkoutBox->GetCurSel();
            if(-1 != nSel)
            {
				int nType = GetDeleteType();
				if((EDeleteWorkout == nType) && (NULL != pDay))
				{
					WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
					CWorkout* pWorkout = rarWorkouts.GetAt(nSel);
					if(NULL != pWorkout)
					{
						str = pWorkout->GetDisplayName();

						SetDlgItemText(IDC_DISPLAY, str);
					}
				}
				else if(EDeleteUpcomingRace == nType)
				{
					CUpcomingRace* pUpcoming = pUser->GetUpcomingRaceAt(GetDate());
					
					if(NULL != pUpcoming)
					{
						CString str;
						str.Format("%s | %s | %s", pUpcoming->GetLineOne(), pUpcoming->GetLineTwo(), 
									pUpcoming->GetLineThree());

						SetDlgItemText(IDC_DISPLAY, str);
					}
				}
				else if(EDeleteUpcomingWorkout == nType)
				{
					CUpcomingWorkout* pUpcoming = pUser->GetUpcomingWorkoutAt(GetDate());
					
					if(NULL != pUpcoming)
					{
						CString str;
						str.Format("%s | %s | %s", pUpcoming->GetLineOne(), pUpcoming->GetLineTwo(), 
									pUpcoming->GetLineThree());

						SetDlgItemText(IDC_DISPLAY, str);
					}
				}
            }
        }
    }
}


void CDeleteWorkoutDlg::OnDelete(void)
{
    CString str;

    CDayLog* pDay = GetDay();
	CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CComboBox* pWorkoutBox = (CComboBox*)GetDlgItem(IDC_WORKOUTS);
        if(NULL != pWorkoutBox)
        {
            int nSel = pWorkoutBox->GetCurSel();
            if(-1 != nSel)
            {
				int nType = GetDeleteType();
				if((EDeleteWorkout == nType) && (NULL != pDay))
				{
					WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
					CWorkout* pWorkout = rarWorkouts.GetAt(nSel);
	                
					rarWorkouts.RemoveAt(nSel);
					if(NULL != pWorkout)
					{
						delete pWorkout;
						pWorkout = NULL;
					}
				}

				else if(EDeleteUpcomingRace == nType)
				{
					CUpcomingRace* pUpcoming = pUser->GetUpcomingRaceAt(GetDate());

					UPCOMINGRACEARRAY& rarUpcoming = pUser->GetRefUpcomingRaceArray();

					// search for the one we have
					for(int j = 0; j < (int)rarUpcoming.GetCount(); j++)
					{
						CUpcomingRace* pCur = rarUpcoming.GetAt(j);
						
						if(pCur == pUpcoming)
						{
							rarUpcoming.RemoveAt(j);
							if(NULL != pUpcoming)
							{
								delete pUpcoming;
								pUpcoming = NULL;
								break;
							}
						}
					}
				}

				else if(EDeleteUpcomingWorkout == nType)
				{
					CUpcomingWorkout* pUpcoming = pUser->GetUpcomingWorkoutAt(GetDate());

					UPCOMINGWORKOUTARRAY& rarUpcoming = pUser->GetRefUpcomingWorkoutArray();

					// search for the one we have
					for(int j = 0; j < (int)rarUpcoming.GetCount(); j++)
					{
						CUpcomingWorkout* pCur = rarUpcoming.GetAt(j);
						
						if(pCur == pUpcoming)
						{
							rarUpcoming.RemoveAt(j);
							if(NULL != pUpcoming)
							{
								delete pUpcoming;
								pUpcoming = NULL;
								break;
							}
						}
					}
				}

                SetChanged(true);
            }
        }
    }

    FillWorkoutBox();
    OnWorkoutSelChange();
}


void CDeleteWorkoutDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


bool CDeleteWorkoutDlg::GetChanged(void) const
{
    return m_bChanged;
}


void CDeleteWorkoutDlg::SetChanged(bool bChanged) 
{
    m_bChanged = bChanged;
}


CDayLog* CDeleteWorkoutDlg::GetDay(void) const
{
    return m_pDay;
}


void CDeleteWorkoutDlg::SetDay(CDayLog* pDay)
{
    m_pDay = pDay;
}


COleDateTime CDeleteWorkoutDlg::GetDate(void) const
{
    return m_tmDay;
}


void CDeleteWorkoutDlg::SetDate(COleDateTime tm)
{
    m_tmDay = tm;
}


CUser* CDeleteWorkoutDlg::GetUser(void) const
{
	return m_pUser;
}


void CDeleteWorkoutDlg::SetUser(CUser* pUser)
{
	m_pUser = pUser;
}


int CDeleteWorkoutDlg::GetDeleteType(void) const
{
	return m_nType;
}


void CDeleteWorkoutDlg::SetDeleteType(int nType)
{
	m_nType = nType;
}