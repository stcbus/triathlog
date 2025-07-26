#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "SkinProgress.h"
#include "PrintToFileDlg.h"


IMPLEMENT_DYNAMIC(CPrintToFileDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPrintToFileDlg, CAniDialog)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATESTART, OnFromDropDown)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATEEND, OnToDropDown)

	ON_BN_CLICKED(IDC_CHANGEFILENAME, OnChangeFilename)

	ON_BN_CLICKED(IDC_PRINTTOFILE, OnPrintToFileButtonClicked)

	ON_BN_CLICKED(IDC_ALLDATES, OnAllDatesClicked)
	ON_BN_CLICKED(IDC_BETWEENDATES, OnBetweenDatesClicked)
END_MESSAGE_MAP()


CPrintToFileDlg::CPrintToFileDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPrintToFileDlg::IDD, pParent)
{
	SetUser(NULL);
	m_pProgress = NULL;
}


CPrintToFileDlg::~CPrintToFileDlg()
{
}


BOOL CPrintToFileDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtFile.SubclassDlgItem(IDC_FILENAME, this);

    COleDateTime tmStart = GetTimeFrom();
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pFrom)
	{
		pFrom->SetTime(tmStart);
	}
    
	COleDateTime tmTo = GetTimeTo();
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pTo)
	{
		pTo->SetTime(tmTo);
	}

	CComboBox* pSearchForBox = (CComboBox*)GetDlgItem(IDC_SEARCHFOR);
	if(NULL != pSearchForBox)
	{
		for(int i = FIRST_SEARCHFOR; i <= LAST_SEARCHFOR; i++)
		{
			pSearchForBox->AddString(CUtil::SearchForToString(i));
		}
		pSearchForBox->SetCurSel(SEARCHFOR_DAY);
		CDlgHelper::ReadyComboBox(pSearchForBox, false);
	}

	CheckDlgButton(IDC_PRINTRUN, BST_CHECKED);
	CheckDlgButton(IDC_PRINTBIKE, BST_CHECKED);
	CheckDlgButton(IDC_PRINTSWIM, BST_CHECKED);
	CheckDlgButton(IDC_PRINTSTRENGTH, BST_CHECKED);

	CheckDlgButton(IDC_OPENRESULT, BST_CHECKED);
	CheckDlgButton(IDC_ALLDATES, BST_CHECKED);

	OnAllDatesClicked();

	CUser* pUser = GetUser();
	if(NULL != pUser)
	{
		CString str = CUtil::GetExeDirectory();
		str += pUser->GetFirstName();
		str += " ";
		str += pUser->GetLastName();
		str += ".txt";

		SetDlgItemText(IDC_FILENAME, str);
	}

	return TRUE;
}


void CPrintToFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


void CPrintToFileDlg::OnAllDatesClicked(void)
{
	CWnd* pWndStart = GetDlgItem(IDC_DATESTART);
	CWnd* pWndEnd = GetDlgItem(IDC_DATEEND);

	if((NULL == pWndStart) || (NULL == pWndEnd))
	{
		return;
	}

	pWndStart->EnableWindow(FALSE);
	pWndEnd->EnableWindow(FALSE);
}


void CPrintToFileDlg::OnBetweenDatesClicked(void)
{
	CWnd* pWndStart = GetDlgItem(IDC_DATESTART);
	CWnd* pWndEnd = GetDlgItem(IDC_DATEEND);

	if((NULL == pWndStart) || (NULL == pWndEnd))
	{
		return;
	}

	pWndStart->EnableWindow(TRUE);
	pWndEnd->EnableWindow(TRUE);
}


void CPrintToFileDlg::OnPrintToFileButtonClicked(void)
{
	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return;
	}

	int nSpan = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCHFOR));

	COleDateTime tmStart;
	COleDateTime tmEnd;

	if(BST_CHECKED == IsDlgButtonChecked(IDC_ALLDATES))
	{
		FindExtremeDates(tmStart, tmEnd);
	}
	else
	{
		tmStart = GetStartDate();
		tmEnd = GetEndDate();

		if(!CUtil::IsDateValid(tmStart))
		{
			AfxMessageBox("Please enter a valid starting date.");
			return;
		}

		if(!CUtil::IsDateValid(tmEnd))
		{
			AfxMessageBox("Please enter a valid ending date.");
			return;
		}

		int nNum = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart);
		if(nNum <= 0)
		{
			AfxMessageBox("The start date must be earlier than the end date.");
			return;
		}
	}

	int nSize = 0;
	if(SEARCHFOR_DAY == nSpan)
	{
		nSize = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1;
	}
	else if(SEARCHFOR_WEEK == nSpan)
	{
		// walk it back until first day
		while(CUtil::GetDayOfWeek(tmStart) != pUser->GetFirstDayOfWeek())
		{
			tmStart = CUtil::OffsetDay(tmStart, -1);
		}
		// walk it forward until last day
		while(CUtil::GetDayOfWeek(tmEnd) != pUser->GetLastDayOfWeek())
		{
			tmEnd = CUtil::OffsetDay(tmEnd, 1);
		}

		nSize = (CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1) / 7;
	}
	else
	{
		tmStart.SetDate(tmStart.GetYear(), tmStart.GetMonth(), 1);
		tmEnd.SetDate(tmEnd.GetYear(), tmEnd.GetMonth(), CUtil::GetNumDaysInMonth(tmEnd.GetYear(), tmEnd.GetMonth()));

		COleDateTime tmCur = tmStart;
		while(CUtil::IsLaterDayThan(tmEnd, tmCur))
		{
			tmCur = CUtil::OffsetDay(tmCur, CUtil::GetNumDaysInMonth(tmCur.GetYear(), tmCur.GetMonth()));
			nSize++;
		}
	}

	bool bPrintRun = (BST_CHECKED == IsDlgButtonChecked(IDC_PRINTRUN));
	bool bPrintBike = (BST_CHECKED == IsDlgButtonChecked(IDC_PRINTBIKE));
	bool bPrintSwim = (BST_CHECKED == IsDlgButtonChecked(IDC_PRINTSWIM));
	bool bPrintStrength = (BST_CHECKED == IsDlgButtonChecked(IDC_PRINTSTRENGTH));

	CString strFile = m_edtFile.GetValue();
	if(true == strFile.IsEmpty())
	{
		AfxMessageBox("Please enter a valid filename");
		return;
	}

	bool bOpenResult = (BST_CHECKED == IsDlgButtonChecked(IDC_OPENRESULT));

	bool bSuccess = PrintToFile(strFile, nSpan, nSize, tmStart, tmEnd, bPrintRun, bPrintBike, bPrintSwim, bPrintStrength);

	if(false == bSuccess)
	{
		AfxMessageBox("There was a problem printing to the file");
		return;
	}
	else
	{
		if(false == bOpenResult)
		{
			AfxMessageBox("Printing to the file completed successfully");
		}
		else
		{
			OpenEditor(strFile);
		}
	}

	CAniDialog::OnOK();
}


bool CPrintToFileDlg::PrintToFile(CString strFile, int nSpan, int nSize, COleDateTime tmStart, COleDateTime tmEnd, 
					 bool bPrintRun, bool bPrintBike, bool bPrintSwim, bool bPrintStrength)
{
	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return false;
	}

	FILE* fp = fopen(strFile, "w+");
	if(NULL == fp)
	{
		AfxMessageBox("Could not open file for writing");
		return false;
	}

	m_pProgress = new CSkinProgress(GetDlgItem(IDC_PROGRESS), nSize, NULL, FALSE, NULL, NULL, cSPT_PERCENT);

	CString strPre;

	if(SEARCHFOR_DAY == nSpan)
	{
		strPre.Format("Daily workout data for %s %s between %d/%d/%d and %d/%d/%d (%d days)\r\n", pUser->GetFirstName(), 
					  pUser->GetLastName(), tmStart.GetMonth(), tmStart.GetDay(), tmStart.GetYear(), tmEnd.GetMonth(), 
					  tmEnd.GetDay(), tmEnd.GetYear(), nSize);
		fprintf(fp, "------------------------------------------------------------------\r\n");
		fprintf(fp, strPre);
		fprintf(fp, "------------------------------------------------------------------\r\n\r\n");

		for(int i = 0; i < nSize; i++)
		{
			COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
			CDayLog* pDay = pUser->GetDayAt(tmCur);
			if(NULL != pDay)
			{
				WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();

				int nLen = (int)rarWorkouts.GetSize();

				if(nLen > 0)
				{
					CString strDayHeader;
					strDayHeader.Format("Data for %d/%d/%d\r\n", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());
					fprintf(fp, "-----------------------------------------\r\n");
					fprintf(fp, strDayHeader);
					fprintf(fp, "-----------------------------------------\r\n");
					fprintf(fp, "\r\n");
				}

				for(int j = 0; j < nLen; j++)
				{
					CWorkout* pWorkout = rarWorkouts.GetAt(j);
					if(NULL != pWorkout)
					{
						PrintWorkoutToFile(fp, pWorkout, bPrintRun, bPrintBike, bPrintSwim, bPrintStrength);
					}
				}
			}

			if(NULL != m_pProgress)
			{
				m_pProgress->StepIt();
				PeekAndPump4();
			}
		}
	}	
	else if(SEARCHFOR_WEEK == nSpan)
	{
		strPre.Format("Weekly workout data for %s %s between %d/%d/%d and %d/%d/%d (%d weeks)\r\n", pUser->GetFirstName(), 
					  pUser->GetLastName(), tmStart.GetMonth(), tmStart.GetDay(), tmStart.GetYear(), tmEnd.GetMonth(), 
					  tmEnd.GetDay(), tmEnd.GetYear(), nSize);
		fprintf(fp, "------------------------------------------------------------------\r\n");
		fprintf(fp, strPre);
		fprintf(fp, "------------------------------------------------------------------\r\n\r\n");

		for(int i = 0; i < nSize; i++)
		{
			COleDateTime tmCur = CUtil::OffsetDay(tmStart, 7 * i);
			COleDateTime tmWeekEnd = CUtil::OffsetDay(tmCur, 6);
			int nDays = 7;

			CString strWeekHeader;
			strWeekHeader.Format("Data for %d/%d/%d thru %d/%d/%d\r\n", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear(),
								 tmWeekEnd.GetMonth(), tmWeekEnd.GetDay(), tmWeekEnd.GetYear());
			fprintf(fp, "-----------------------------------------\r\n");
			fprintf(fp, strWeekHeader);
			fprintf(fp, "-----------------------------------------\r\n");
			fprintf(fp, "\r\n");

			int anWorkouts[5];
			anWorkouts[0] = pUser->SumWorkoutsRun(tmCur, nDays);
			anWorkouts[1] = pUser->SumWorkoutsBike(tmCur, nDays);
			anWorkouts[2] = pUser->SumWorkoutsSwim(tmCur, nDays);
			anWorkouts[3] = pUser->SumWorkoutsStrength(tmCur, nDays);
			anWorkouts[4] = anWorkouts[0] + anWorkouts[1] + anWorkouts[2] + anWorkouts[3];

			double adMiles[5];
			adMiles[0] = pUser->SumMilesRun(tmCur, nDays);
			adMiles[1] = pUser->SumMilesBike(tmCur, nDays);
			adMiles[2] = pUser->SumMilesSwim(tmCur, nDays);
			adMiles[3] = 0.0;
			adMiles[4] = adMiles[0] + adMiles[1] + adMiles[2] + adMiles[3];

			double adMinutes[5];
			adMinutes[0] = pUser->SumMinutesRun(tmCur, nDays);
			adMinutes[1] = pUser->SumMinutesBike(tmCur, nDays);
			adMinutes[2] = pUser->SumMinutesSwim(tmCur, nDays);
			adMinutes[3] = pUser->SumMinutesStrength(tmCur, nDays);
			adMinutes[4] = adMinutes[0] + adMinutes[1] + adMinutes[2] + adMinutes[3];

			CString astrWorkouts[5];
			CString astrMiles[5];
			CString astrMinutes[5];

			for(int i = 0; i < 5; i++)
			{
				astrWorkouts[i].Format("%d", anWorkouts[i]);
				astrMiles[i].Format("%.2lf", adMiles[i]);
				astrMinutes[i] = CDlgHelper::FormatTimeNoDecimal(adMinutes[i]);
			}

			double dAvgWeight = pUser->GetAverageWeight(tmCur, nDays);
			int nAvgHR = pUser->GetAverageHR(tmCur, nDays);
			double dAvgSleep = pUser->GetAverageSleep(tmCur, nDays);
			int nAvgTemp = pUser->GetAverageTemperature(tmCur, nDays);

			CString strWeight;
			strWeight.Format("%.2lf", dAvgWeight);
	    
			CString strHR;
			strHR.Format("%d", nAvgHR);

			CString strSleep;
			strSleep.Format("%.1lf", dAvgSleep);

			CString strTemp;
			strTemp.Format("%d", nAvgTemp);

			int nRestDays = pUser->GetCompleteRestDays(tmCur, nDays);
			int nNoBikeDays = pUser->GetNoBikingDays(tmCur, nDays);
			int nNoRunDays = pUser->GetNoRunningDays(tmCur, nDays);
			int nNoSwimDays = pUser->GetNoSwimmingDays(tmCur, nDays);
			int nNoStrengthDays = pUser->GetNoStrengthDays(tmCur, nDays);
	        
			CString strRest;
			strRest.Format("%d", nRestDays);

			CString strNoBike;
			strNoBike.Format("%d", nNoBikeDays);
			CString strNoRun;
			strNoRun.Format("%d", nNoRunDays);
			CString strNoSwim;
			strNoSwim.Format("%d", nNoSwimDays);
			CString strNoStrength;
			strNoStrength.Format("%d", nNoStrengthDays);

			CString strPrint;

			if(true == bPrintRun)
			{
				strPrint += MakeText("Running workouts", astrWorkouts[0]);
				strPrint += MakeText("Running miles", astrMiles[0]);
				strPrint += MakeText("Running minutes", astrMinutes[0]);
				strPrint += MakeText("Days without running", strNoRun);
			}
			if(true == bPrintBike)
			{
				strPrint += MakeText("Cycling workouts", astrWorkouts[1]);
				strPrint += MakeText("Cycling miles", astrMiles[1]);
				strPrint += MakeText("Cycling minutes", astrMinutes[1]);
				strPrint += MakeText("Days without cycling", strNoBike);
			}
			if(true == bPrintSwim)
			{
				strPrint += MakeText("Swimming workouts", astrWorkouts[2]);
				strPrint += MakeText("Swimming miles", astrMiles[2]);
				strPrint += MakeText("Swimming minutes", astrMinutes[2]);
				strPrint += MakeText("Days without swimming", strNoSwim);
			}
			if(true == bPrintStrength)
			{
				strPrint += MakeText("Strength workouts", astrWorkouts[3]);
				strPrint += MakeText("Strength work minutes", astrMinutes[3]);
				strPrint += MakeText("Days without strength work", strNoStrength);
			}
			
			strPrint += MakeText("Total minutes", astrMinutes[4]);
			strPrint += MakeText("Total workouts", astrWorkouts[4]);
			strPrint += MakeText("Complete rest days", strRest);
			strPrint += MakeText("Average weight", strWeight);
			strPrint += MakeText("Average heartrate", strHR);
			strPrint += MakeText("Average sleep", strSleep);
			strPrint += MakeText("Average temperature", strTemp);

			fprintf(fp, strPrint);
			fprintf(fp, "\r\n");

			if(NULL != m_pProgress)
			{
				m_pProgress->StepIt();
				PeekAndPump4();
			}
		}
	}	
	else if(SEARCHFOR_MONTH == nSpan)
	{
		strPre.Format("Monthly workout data for %s %s between %d/%d and %d/%d (%d months)\r\n", pUser->GetFirstName(), 
					  pUser->GetLastName(), tmStart.GetMonth(), tmStart.GetYear(), tmEnd.GetMonth(), tmEnd.GetYear(), nSize);
		fprintf(fp, "------------------------------------------------------------------\r\n");
		fprintf(fp, strPre);
		fprintf(fp, "------------------------------------------------------------------\r\n\r\n");

		COleDateTime tmCur = tmStart;
		for(int i = 0; i < nSize; i++)
		{
			int nDays = CUtil::GetNumDaysInMonth(tmCur.GetYear(), tmCur.GetMonth());

			CString strMonthHeader;
			strMonthHeader.Format("Data for %d/%d (%d days)\r\n", tmCur.GetMonth(), tmCur.GetYear(), nDays);
			fprintf(fp, "-----------------------------------------\r\n");
			fprintf(fp, strMonthHeader);
			fprintf(fp, "-----------------------------------------\r\n");
			fprintf(fp, "\r\n");

			int anWorkouts[5];
			anWorkouts[0] = pUser->SumWorkoutsRun(tmCur, nDays);
			anWorkouts[1] = pUser->SumWorkoutsBike(tmCur, nDays);
			anWorkouts[2] = pUser->SumWorkoutsSwim(tmCur, nDays);
			anWorkouts[3] = pUser->SumWorkoutsStrength(tmCur, nDays);
			anWorkouts[4] = anWorkouts[0] + anWorkouts[1] + anWorkouts[2] + anWorkouts[3];

			double adMiles[5];
			adMiles[0] = pUser->SumMilesRun(tmCur, nDays);
			adMiles[1] = pUser->SumMilesBike(tmCur, nDays);
			adMiles[2] = pUser->SumMilesSwim(tmCur, nDays);
			adMiles[3] = 0.0;
			adMiles[4] = adMiles[0] + adMiles[1] + adMiles[2] + adMiles[3];

			double adMinutes[5];
			adMinutes[0] = pUser->SumMinutesRun(tmCur, nDays);
			adMinutes[1] = pUser->SumMinutesBike(tmCur, nDays);
			adMinutes[2] = pUser->SumMinutesSwim(tmCur, nDays);
			adMinutes[3] = pUser->SumMinutesStrength(tmCur, nDays);
			adMinutes[4] = adMinutes[0] + adMinutes[1] + adMinutes[2] + adMinutes[3];

			CString astrWorkouts[5];
			CString astrMiles[5];
			CString astrMinutes[5];

			for(int i = 0; i < 5; i++)
			{
				astrWorkouts[i].Format("%d", anWorkouts[i]);
				astrMiles[i].Format("%.2lf", adMiles[i]);
				astrMinutes[i] = CDlgHelper::FormatTimeNoDecimal(adMinutes[i]);
			}

			double dAvgWeight = pUser->GetAverageWeight(tmCur, nDays);
			int nAvgHR = pUser->GetAverageHR(tmCur, nDays);
			double dAvgSleep = pUser->GetAverageSleep(tmCur, nDays);
			int nAvgTemp = pUser->GetAverageTemperature(tmCur, nDays);

			CString strWeight;
			strWeight.Format("%.2lf", dAvgWeight);
	    
			CString strHR;
			strHR.Format("%d", nAvgHR);

			CString strSleep;
			strSleep.Format("%.1lf", dAvgSleep);

			CString strTemp;
			strTemp.Format("%d", nAvgTemp);

			int nRestDays = pUser->GetCompleteRestDays(tmCur, nDays);
			int nNoBikeDays = pUser->GetNoBikingDays(tmCur, nDays);
			int nNoRunDays = pUser->GetNoRunningDays(tmCur, nDays);
			int nNoSwimDays = pUser->GetNoSwimmingDays(tmCur, nDays);
			int nNoStrengthDays = pUser->GetNoStrengthDays(tmCur, nDays);
	        
			CString strRest;
			strRest.Format("%d", nRestDays);

			CString strNoBike;
			strNoBike.Format("%d", nNoBikeDays);
			CString strNoRun;
			strNoRun.Format("%d", nNoRunDays);
			CString strNoSwim;
			strNoSwim.Format("%d", nNoSwimDays);
			CString strNoStrength;
			strNoStrength.Format("%d", nNoStrengthDays);

			CString strPrint;

			if(true == bPrintRun)
			{
				strPrint += MakeText("Running workouts", astrWorkouts[0]);
				strPrint += MakeText("Running miles", astrMiles[0]);
				strPrint += MakeText("Running minutes", astrMinutes[0]);
				strPrint += MakeText("Days without running", strNoRun);
			}
			if(true == bPrintBike)
			{
				strPrint += MakeText("Cycling workouts", astrWorkouts[1]);
				strPrint += MakeText("Cycling miles", astrMiles[1]);
				strPrint += MakeText("Cycling minutes", astrMinutes[1]);
				strPrint += MakeText("Days without cycling", strNoBike);
			}
			if(true == bPrintSwim)
			{
				strPrint += MakeText("Swimming workouts", astrWorkouts[2]);
				strPrint += MakeText("Swimming miles", astrMiles[2]);
				strPrint += MakeText("Swimming minutes", astrMinutes[2]);
				strPrint += MakeText("Days without swimming", strNoSwim);
			}
			if(true == bPrintStrength)
			{
				strPrint += MakeText("Strength workouts", astrWorkouts[3]);
				strPrint += MakeText("Strength work minutes", astrMinutes[3]);
				strPrint += MakeText("Days without strength work", strNoStrength);
			}
			
			strPrint += MakeText("Total minutes", astrMinutes[4]);
			strPrint += MakeText("Total workouts", astrWorkouts[4]);
			strPrint += MakeText("Complete rest days", strRest);
			strPrint += MakeText("Average weight", strWeight);
			strPrint += MakeText("Average heartrate", strHR);
			strPrint += MakeText("Average sleep", strSleep);
			strPrint += MakeText("Average temperature", strTemp);

			fprintf(fp, strPrint);
			fprintf(fp, "\r\n");

			tmCur = CUtil::OffsetDay(tmCur, nDays);

			if(NULL != m_pProgress)
			{
				m_pProgress->StepIt();
				PeekAndPump4();
			}
		}
	}
	else
	{
		CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintToFile");
		fclose(fp);

		if(NULL != m_pProgress)
		{
			delete m_pProgress;
			m_pProgress = NULL;
		}
		return false;
	}

	CString strEnd;
	strEnd.Format("End of workout data\r\n");
	fprintf(fp, "--------------------------------------------------------\r\n");
	fprintf(fp, strEnd);
	fprintf(fp, "--------------------------------------------------------\r\n");

	fclose(fp);
	if(NULL != m_pProgress)
	{
		delete m_pProgress;
		m_pProgress = NULL;
	}

	return true;
}


bool CPrintToFileDlg::PrintWorkoutToFile(FILE* fp, CWorkout* pWorkout, bool bPrintRun, bool bPrintBike, bool bPrintSwim, 
										 bool bPrintStrength)
{
    // write out the workout to the file
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return NULL;
    }

	CString strWorkout;

	switch(pWorkout->GetActivityType())
    {
    case ACTIVITY_RUNNING:
        {
			if(true == bPrintRun)
			{
				switch(pWorkout->GetType())
				{
				case RUNTYPE_EZ:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunEZWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_HARD:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunHardWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_HILLS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunHillWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_INTERVALS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunIntervalWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_OTHER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunMiscWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_NORMAL:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunNormalWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_POOL:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunPoolWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_TEMPO:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunTempoWorkout*>(pWorkout));
						break;
					}

				case RUNTYPE_TREADMILL:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRunTreadmillWorkout*>(pWorkout));
						break;
					}

				default:
					{
						CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
						return false;
					}
				}
			}

			break;
		}

    case ACTIVITY_BIKING:
        {
			if(true == bPrintBike)
			{
			switch(pWorkout->GetType())
				{
				case BIKETYPE_EZ:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeEZWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_HARD:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeHardWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_HILLS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeHillWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_INTERVALS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeIntervalWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_OTHER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeMiscWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_NORMAL:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeNormalWorkout*>(pWorkout));
						break;
					}

				case BIKETYPE_TRAINER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CBikeTrainerWorkout*>(pWorkout));
						break;
					}

				default:
					{
						CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
						return false;
					}
				}
			}

			break;
        }

    case ACTIVITY_SWIMMING:
        {
			if(bPrintSwim)
			{
			switch(pWorkout->GetType())
				{
				case SWIMTYPE_DRILLS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimDrillWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_EZ:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimEZWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_HARD:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimHardWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_INTERVALS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimIntervalWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_OTHER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimMiscWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_NORMAL:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimNormalWorkout*>(pWorkout));
						break;
					}

				case SWIMTYPE_OPENWATER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CSwimOpenWaterWorkout*>(pWorkout));
						break;
					}

				default:
					{
						CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
						return false;
					}
				}
			}

			break;
        }

    case ACTIVITY_STRENGTH:
        {
			if(bPrintStrength)
			{
			switch(pWorkout->GetType())
				{
				case STRENGTHTYPE_ABS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CStrengthAbsWorkout*>(pWorkout));
						break;
					}

				case STRENGTHTYPE_OTHER:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CStrengthMiscWorkout*>(pWorkout));
						break;
					}

				case STRENGTHTYPE_WEIGHTS:
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CStrengthWeightsWorkout*>(pWorkout));
						break;
					}

				default:
					{
						CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
						return false;
					}
				}
			}

			break;
        }

    case ACTIVITY_RACE:
        {
            switch(pWorkout->GetType())
            {
            case RACETYPE_RUN:
                {
					if(true == bPrintRun)
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRaceRunWorkout*>(pWorkout));
						break;
					}
				}

            case RACETYPE_BIKE:
                {
					if(true == bPrintBike)
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRaceBikeWorkout*>(pWorkout));
						break;
					}
				}

            case RACETYPE_SWIM:
                {
					if(true == bPrintSwim)
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRaceSwimWorkout*>(pWorkout));
						break;
					}
				}

            case RACETYPE_DUATHLON:
                {
					if((true == bPrintRun) || (true == bPrintBike))
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRaceDuathlonWorkout*>(pWorkout));
						break;
					}
				}

            case RACETYPE_TRIATHLON:
                {
					if((true == bPrintRun) || (true == bPrintBike) || (true == bPrintSwim))
					{
						strWorkout = PrintWorkoutToFile(dynamic_cast<CRaceTriathlonWorkout*>(pWorkout));
						break;
					}
				}

            default:
                {
                    CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
                    return false;
                }
            }

			break;
        }
        
    default:
        {
            CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
            return false;
        }
    }

	if(!strWorkout.IsEmpty())
	{
		fprintf(fp, strWorkout);
		fprintf(fp, "\r\n\r\n");
	}

	return true;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunEZWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());
    
    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunHardWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunHillWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time on hills", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance on hills", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

	return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunIntervalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
	strText += MakeText("Shoes for intervals", pWorkout->GetSpecialShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time in intervals", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance in intervals", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunMiscWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunNormalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

	return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunPoolWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());
    strText += MakeText("Workout", false);

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunTempoWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time at tempo", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance at tempo", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRunTreadmillWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeEZWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeHardWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
    
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeHillWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time on hills", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance on hills", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeIntervalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
	strText += MakeText("Shoes for intervals", pWorkout->GetSpecialShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time in intervals", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance in intervals", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeMiscWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeNormalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CBikeTrainerWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
    
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimDrillWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimEZWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimHardWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimIntervalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time in intervals", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
	strText += MakeText("Distance in intervals", pWorkout->GetSpecialMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimMiscWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimNormalWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CSwimOpenWaterWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CStrengthAbsWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CStrengthMiscWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CStrengthWeightsWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
   
	strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Location", pWorkout->GetLocationSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRaceRunWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Course", pWorkout->GetCourseRun());
    strText += MakeText("Shoes", pWorkout->GetShoesRun());
	strText += MakeText("Shoes for intervals", pWorkout->GetSpecialShoesRun());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time racing", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Place", pWorkout->GetRacePosition());
    strText += MakeText("RaceNumber", pWorkout->GetRaceNumber());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRaceBikeWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Course", pWorkout->GetCourseBike());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Shoes", pWorkout->GetShoesBike());
	strText += MakeText("Shoes for intervals", pWorkout->GetSpecialShoesBike());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time racing", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Wind", pWorkout->GetWind(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Place", pWorkout->GetRacePosition());
    strText += MakeText("RaceNumber", pWorkout->GetRaceNumber());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRaceSwimWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Course", pWorkout->GetCourseSwim());
    strText += MakeText("Time", pWorkout->GetSeconds(), true);
	strText += MakeText("Time racing", pWorkout->GetSpecialSeconds(), true);
    strText += MakeText("Distance", pWorkout->GetMiles());
    strText += MakeText("Temperature", pWorkout->GetTemperature());
    strText += MakeText("Choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Heartrate", pWorkout->GetHR());
    strText += MakeText("Place", pWorkout->GetRacePosition());
    strText += MakeText("RaceNumber", pWorkout->GetRaceNumber());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());
    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRaceDuathlonWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;

    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Course", pWorkout->GetCourseDuathlon());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Place", pWorkout->GetRacePosition());
    strText += MakeText("RaceNumber", pWorkout->GetRaceNumber());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());

    strText += MakeText("Overall time", pWorkout->GetSeconds(), true);
	strText += MakeText("Overall race time", pWorkout->GetLeg1RaceSeconds() + pWorkout->GetTransition1Seconds() +
						pWorkout->GetLeg2RaceSeconds() + pWorkout->GetTransition2Seconds() + pWorkout->GetLeg3RaceSeconds(), true);

    strText += MakeText("Leg 1 overall time", pWorkout->GetLeg1Seconds(), true);
	strText += MakeText("Leg 1 overall distance", pWorkout->GetLeg1Miles());
    strText += MakeText("Leg 1 racing time", pWorkout->GetLeg1RaceSeconds(), true);
    strText += MakeText("Leg 1 temperature", pWorkout->GetLeg1Temperature());
    strText += MakeText("Leg 1 wind", pWorkout->GetLeg1Wind(), true);
    strText += MakeText("Leg 1 heartrate", pWorkout->GetLeg1HR());
    strText += MakeText("Leg 1 shoes", pWorkout->GetLeg1Shoes());
    strText += MakeText("Leg 1 race shoes", pWorkout->GetLeg1RaceShoes());

    strText += MakeText("Time for transition one", pWorkout->GetTransition1Seconds(), true);
 
	strText += MakeText("Leg 2 overall time", pWorkout->GetLeg2Seconds(), true);
	strText += MakeText("Leg 2 overall distance", pWorkout->GetLeg2Miles());
    strText += MakeText("Leg 2 racing time", pWorkout->GetLeg2RaceSeconds(), true);
    strText += MakeText("Leg 2 temperature", pWorkout->GetLeg2Temperature());
    strText += MakeText("Leg 2 wind", pWorkout->GetLeg2Wind(), true);
    strText += MakeText("Leg 2 heartrate", pWorkout->GetLeg2HR());
    strText += MakeText("Leg 2 shoes", pWorkout->GetLeg2Shoes());
    strText += MakeText("Leg 2 race shoes", pWorkout->GetLeg2RaceShoes());

    strText += MakeText("Time for transition two", pWorkout->GetTransition2Seconds(), true);

	strText += MakeText("Leg 3 overall time", pWorkout->GetLeg3Seconds(), true);
	strText += MakeText("Leg 3 overall distance", pWorkout->GetLeg3Miles());
    strText += MakeText("Leg 3 racing time", pWorkout->GetLeg3RaceSeconds(), true);
    strText += MakeText("Leg 3 temperature", pWorkout->GetLeg3Temperature());
    strText += MakeText("Leg 3 wind", pWorkout->GetLeg3Wind(), true);
    strText += MakeText("Leg 3 heartrate", pWorkout->GetLeg3HR());
    strText += MakeText("Leg 3 shoes", pWorkout->GetLeg3Shoes());
    strText += MakeText("Leg 3 race shoes", pWorkout->GetLeg3RaceShoes());

    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::PrintWorkoutToFile(CRaceTriathlonWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CPrintToFileDlg::PrintWorkoutToFile");
        return "NULL";
    }

    CString strText;
    strText += MakeText("Name", pWorkout->GetDisplayName());
	strText += MakeText("Weight", pWorkout->GetWeight());
    strText += MakeText("Start time", pWorkout->GetTimeStart());
    strText += MakeText("Previous night's sleep", pWorkout->GetPrevNightSleep());
    strText += MakeText("Course", pWorkout->GetCourseDuathlon());
    strText += MakeText("Bike", pWorkout->GetBike());
    strText += MakeText("Place", pWorkout->GetRacePosition());
    strText += MakeText("RaceNumber", pWorkout->GetRaceNumber());
    strText += MakeText("Long workout", pWorkout->IsLong());
    strText += MakeText("Feeling injured", pWorkout->IsInjured());
	strText += MakeText("Feeling sick", pWorkout->IsSick());

    strText += MakeText("Overall time", pWorkout->GetSeconds(), true);
	strText += MakeText("Overall race time", pWorkout->GetLeg1RaceSeconds() + pWorkout->GetTransition1Seconds() +
						pWorkout->GetLeg2RaceSeconds() + pWorkout->GetTransition2Seconds() + pWorkout->GetLeg3RaceSeconds(), true);

    strText += MakeText("Leg 1 overall time", pWorkout->GetLeg1Seconds(), true);
	strText += MakeText("Leg 1 overall distance", pWorkout->GetLeg1Miles());
    strText += MakeText("Leg 1 racing time", pWorkout->GetLeg1RaceSeconds(), true);
    strText += MakeText("Leg 1 temperature", pWorkout->GetLeg1Temperature());
    strText += MakeText("Leg 1 choppiness", pWorkout->GetChoppiness(), true);
    strText += MakeText("Leg 1 heartrate", pWorkout->GetLeg1HR());

    strText += MakeText("Time for transition one", pWorkout->GetTransition1Seconds(), true);
 
	strText += MakeText("Leg 2 overall time", pWorkout->GetLeg2Seconds(), true);
	strText += MakeText("Leg 2 overall distance", pWorkout->GetLeg2Miles());
    strText += MakeText("Leg 2 racing time", pWorkout->GetLeg2RaceSeconds(), true);
    strText += MakeText("Leg 2 temperature", pWorkout->GetLeg2Temperature());
    strText += MakeText("Leg 2 wind", pWorkout->GetLeg2Wind(), true);
    strText += MakeText("Leg 2 heartrate", pWorkout->GetLeg2HR());
    strText += MakeText("Leg 2 shoes", pWorkout->GetLeg2Shoes());
    strText += MakeText("Leg 2 race shoes", pWorkout->GetLeg2RaceShoes());

    strText += MakeText("Time for transition two", pWorkout->GetTransition2Seconds(), true);

	strText += MakeText("Leg 3 overall time", pWorkout->GetLeg3Seconds(), true);
	strText += MakeText("Leg 3 overall distance", pWorkout->GetLeg3Miles());
    strText += MakeText("Leg 3 racing time", pWorkout->GetLeg3RaceSeconds(), true);
    strText += MakeText("Leg 3 temperature", pWorkout->GetLeg3Temperature());
    strText += MakeText("Leg 3 wind", pWorkout->GetLeg3Wind(), true);
    strText += MakeText("Leg 3 heartrate", pWorkout->GetLeg3HR());
    strText += MakeText("Leg 3 shoes", pWorkout->GetLeg3Shoes());
    strText += MakeText("Leg 3 race shoes", pWorkout->GetLeg3RaceShoes());

    strText += MakeText("Notes", pWorkout->GetNotes());

    return strText;
}


CString CPrintToFileDlg::MakeText(CString strTag, int nVal, bool bTreatAsWind /* = false */)
{
	CString strRet;

	if(false == bTreatAsWind)
	{
		strRet.Format("%s: %d\r\n", strTag, nVal);
	}
	else
	{
		CString strAmt;
		
		if(WIND_NONE == nVal)
		{
			strAmt = "none";
		}
		else if(WIND_LIGHT == nVal)
		{
			strAmt = "light";
		}
		else if(WIND_STRONG == nVal)
		{
			strAmt = "heavy";
		}

		strRet.Format("%s: %s\r\n", strTag, strAmt);
	}			
	
	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, double dVal, bool bFormatAsTime /* = false */)
{
	CString strRet;

	if(false == bFormatAsTime)
	{
		strRet.Format("%s: %.2lf\r\n", strTag, dVal);
	}
	else
	{
		int nVal = (int)dVal;
		int nHours = nVal / 3600;
		int nMinutes = nVal / 60 - 60 * nHours;
		int nSeconds = nVal - 3600 * nHours - 60 * nMinutes;
		double dMS = dVal - (double)nVal;

		if(nHours > 0)
		{
			strRet.Format("%s: %d:%02d:%02d.%d\r\n", strTag, nHours, nMinutes, nSeconds, (int)(dMS * 100));
		}
		else
		{
			strRet.Format("%s: %d:%02d.%d\r\n", strTag, nMinutes, nSeconds, (int)(dMS * 100));
		}
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, COleDateTime tmVal)
{
	CString strRet;
	bool bAM = true;
	int nHour = tmVal.GetHour();

	if(nHour >= 12)
	{
		bAM = false;
		
		if(nHour >= 13)
		{
			nHour -= 12;
		}
	}
	if(0 == nHour)
	{
		nHour = 12;
	}

	strRet.Format("%s: %d:%02d %s\r\n", strTag, nHour, tmVal.GetMinute(), bAM ? "AM" : "PM");

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CString strVal)
{
	CString strRet;

	strRet.Format("%s: %s\r\n", strTag, strVal);

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, bool bVal)
{
	CString strRet;

	strRet.Format("%s: %s\r\n", strTag, bVal ? "yes" : "no");

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CCourseRun* pCourse)
{
	CString strRet;

	if(NULL == pCourse)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s (%.2lf miles)\r\n", strTag, pCourse->GetName(), pCourse->GetLength());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CCourseBike* pCourse)
{
	CString strRet;

	if(NULL == pCourse)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s (%.2lf miles)\r\n", strTag, pCourse->GetName(), pCourse->GetLength());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CCourseSwim* pCourse)
{
	CString strRet;

	if(NULL == pCourse)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s (%.2lf miles)\r\n", strTag, pCourse->GetName(), pCourse->GetLength());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CCourseDuathlon* pCourse)
{
	CString strRet;

	if(NULL == pCourse)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s (%.2lf/%.2lf/%.2lf miles)\r\n", strTag, pCourse->GetName(), pCourse->GetLeg1Length(), 
					   pCourse->GetLeg2Length(), pCourse->GetLeg3Length());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CCourseTriathlon* pCourse)
{
	CString strRet;

	if(NULL == pCourse)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s (%.2lf/%.2lf/%.2lf miles)\r\n", strTag, pCourse->GetName(), pCourse->GetLeg1Length(), 
					   pCourse->GetLeg2Length(), pCourse->GetLeg3Length());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CLocationRun* pLocation)
{
	CString strRet;

	if(NULL == pLocation)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s\r\n", strTag, pLocation->GetName());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CLocationBike* pLocation)
{
	CString strRet;

	if(NULL == pLocation)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s\r\n", strTag, pLocation->GetName());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CLocationSwim* pLocation)
{
	CString strRet;

	if(NULL == pLocation)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s\r\n", strTag, pLocation->GetName());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CLocationStrength* pLocation)
{
	CString strRet;

	if(NULL == pLocation)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s\r\n", strTag, pLocation->GetName());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CShoesRun* pShoes)
{
	CString strRet;

	if(NULL == pShoes)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s %s\r\n", strTag, pShoes->GetBrand(), pShoes->GetType());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CShoesBike* pShoes)
{
	CString strRet;

	if(NULL == pShoes)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s %s\r\n", strTag, pShoes->GetBrand(), pShoes->GetType());
	}

	return strRet;
}


CString CPrintToFileDlg::MakeText(CString strTag, CBike* pBike)
{
	CString strRet;

	if(NULL == pBike)
	{
		strRet.Format("%s: NULL\r\n", strTag);
	}
	else
	{
		strRet.Format("%s: %s %s\r\n", strTag, pBike->GetBrand(), pBike->GetType());
	}

	return strRet;
}


bool CPrintToFileDlg::OpenEditor(CString strFile)
{
	EnableAni(FALSE);

    // try ShellExecute()
    HINSTANCE hResult = ShellExecute(NULL, _T("open"), strFile, NULL, NULL, SW_SHOW);

    // if it failed, get the .txt regkey and lookup the program
    if((UINT)hResult <= HINSTANCE_ERROR) 
	{
		AfxMessageBox("Could not find the text editor in order to open the file");
		return false;
	}

	return true;
}


void CPrintToFileDlg::OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pFrom)
	{
		CMonthCalCtrl* pFromMonthCtrl = pFrom->GetMonthCalCtrl();
		if(NULL != pFromMonthCtrl)
		{
			pFromMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);
			
			CUser* pUser = GetUser();
			if(NULL != pUser)
			{
				int nStartDay = pUser->GetFirstDayOfWeek();
				if(SUNDAY == nStartDay)
				{
					nStartDay = 8;
				}
				nStartDay -= 2;

				pFromMonthCtrl->SetFirstDayOfWeek(nStartDay);
			}
		}

		pFrom->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pFrom->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pFrom->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pFrom->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CPrintToFileDlg::OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pTo)
	{
		CMonthCalCtrl* pToMonthCtrl = pTo->GetMonthCalCtrl();
		if(NULL != pToMonthCtrl)
		{
			pToMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);

			CUser* pUser = GetUser();
			if(NULL != pUser)
			{
				int nStartDay = pUser->GetFirstDayOfWeek();
				if(SUNDAY == nStartDay)
				{
					nStartDay = 8;
				}
				nStartDay -= 2;

				pToMonthCtrl->SetFirstDayOfWeek(nStartDay);
			}
		}

		pTo->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pTo->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pTo->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pTo->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CPrintToFileDlg::OnChangeFilename(void)
{
    CString strFilter = "Text Files (*.txt)|*.txt||";
	CString strFile;
	GetDlgItemText(IDC_FILENAME, strFile);

    CFileDialog dlg(false, ".txt", strFile, OFN_OVERWRITEPROMPT, strFilter, this); 
    if(IDOK == dlg.DoModal())
    {
        CString strFile2 = dlg.GetPathName();
        SetDlgItemText(IDC_FILENAME, strFile2);
    }
}


COleDateTime CPrintToFileDlg::GetCurStart(COleDateTime tmStart, int nTimePeriod, int nSpan)
{
	switch(nSpan)
	{
	case SEARCHFOR_DAY:
		{
			return CUtil::OffsetDay(tmStart, nTimePeriod);
		}

	case SEARCHFOR_WEEK:
		{
			return CUtil::OffsetDay(tmStart, nTimePeriod * 7);
		}

	case SEARCHFOR_MONTH:
		{
			COleDateTime tmCur = tmStart;
			for(int i = nTimePeriod; i > 0; i--)
			{
				tmCur = CUtil::OffsetDay(tmCur, CUtil::GetNumDaysInMonth(tmCur.GetYear(), tmCur.GetMonth()));
			}

			return tmCur;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPrintToFileDlg::GetCurStart");
			return tmStart;
		}
	}
}


COleDateTime CPrintToFileDlg::GetCurEnd(COleDateTime tmStart, int nTimePeriod, int nSpan)
{
	return CUtil::OffsetDay(GetCurStart(tmStart, nTimePeriod + 1, nSpan), -1);
}


COleDateTime CPrintToFileDlg::GetStartDate(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

    CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pDate)
	{
		pDate->GetTime(tm);
	}

    return tm;
}


COleDateTime CPrintToFileDlg::GetEndDate(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

    CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pDate)
	{
		pDate->GetTime(tm);
	}

    return tm;
}


void CPrintToFileDlg::FindExtremeDates(COleDateTime& rtmEarly, COleDateTime& rtmLate)
{
	rtmEarly.SetStatus(COleDateTime::null);
	rtmLate.SetStatus(COleDateTime::null);

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        DAYARRAY& rarDays = pUser->GetRefDayArray();
        for(int i = 0; i < rarDays.GetCount(); i++)
        {
            CDayLog* pDay = rarDays.GetAt(i);
            if(NULL != pDay)
            {
				COleDateTime tmCur = pDay->GetDate();

                if((COleDateTime::null == rtmEarly.GetStatus()) || (true == CUtil::IsLaterThan(rtmEarly, tmCur)))
                {
                    rtmEarly.SetStatus(COleDateTime::valid);
                    rtmEarly = tmCur;
                }

                if((COleDateTime::null == rtmLate.GetStatus()) || (false == CUtil::IsLaterThan(rtmLate, tmCur)))
                {
                    rtmLate.SetStatus(COleDateTime::valid);
                    rtmLate = tmCur;
                }
            }
        }
    }

	if((false == CUtil::IsDateValid(rtmEarly)) || (false == CUtil::IsDateValid(rtmLate)))
	{
		CUtil::Fatal("Bad search result in CPrintToFileDlg::FindExtremeDates");
		return;
	}
}


COleDateTime CPrintToFileDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CPrintToFileDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CPrintToFileDlg::GetUser(void) const
{
	return m_pUser;
}


void CPrintToFileDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CPrintToFileDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CPrintToFileDlg::SetUser(CUser* pUser)
{
	m_pUser = pUser;
}


BOOL PeekAndPump4(void)
{
  static MSG msg;

  while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
  {
	  if(!AfxGetApp()->PumpMessage())
    {
		  ::PostQuitMessage(0);
		  return FALSE;
	  }	
  }

  return TRUE;
}