#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DMFRunSummaryDlg.h"


IMPLEMENT_DYNAMIC(CDMFRunSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDMFRunSummaryDlg, CAniDialog)
END_MESSAGE_MAP()


CDMFRunSummaryDlg::CDMFRunSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDMFRunSummaryDlg::IDD, pParent)
{
}


CDMFRunSummaryDlg::~CDMFRunSummaryDlg()
{
}


BOOL CDMFRunSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CWaitCursor wc;

    SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    COleDateTime tmFrom = GetTimeFrom();
    COleDateTime tmTo = GetTimeTo();
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom) + 1;

    CString strDate1;
    CString strDate2;
    strDate1.Format("%d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear());
    strDate2.Format("%d/%d/%d", tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());

    CString strTitle = "Running Summary: ";
    strTitle += strDate1;
    strTitle += " to ";
    strTitle += strDate2;
    CString strDays;
    strDays.Format(" (%d days)", nDays);
    strTitle += strDays;
    SetWindowText(strTitle);

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        int anWorkouts[11];
        anWorkouts[0] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_EZ);
        anWorkouts[1] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HARD);
        anWorkouts[2] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HILLS);
        anWorkouts[3] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_INTERVALS);
        anWorkouts[4] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_OTHER);
        anWorkouts[5] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_NORMAL);
        anWorkouts[6] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_POOL);
        anWorkouts[7] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_RUN) + 
                        pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                        pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        anWorkouts[8] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TEMPO);
        anWorkouts[9] = pUser->SumWorkoutsRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TREADMILL);
        anWorkouts[10] = pUser->SumWorkoutsRun(tmFrom, nDays);

        double adMiles[11];
        adMiles[0] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_EZ);
        adMiles[1] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HARD);
        adMiles[2] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HILLS);
        adMiles[3] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_INTERVALS);
        adMiles[4] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_OTHER);
        adMiles[5] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_NORMAL);
        adMiles[6] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_POOL);
        adMiles[7] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_RUN) + 
                     pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                     pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMiles[8] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TEMPO);
        adMiles[9] = pUser->SumMilesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TREADMILL);
        adMiles[10] = pUser->SumMilesRun(tmFrom, nDays);

        double adMinutes[11];
        adMinutes[0] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_EZ);
        adMinutes[1] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HARD);
        adMinutes[2] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_HILLS);
        adMinutes[3] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_INTERVALS);
        adMinutes[4] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_OTHER);
        adMinutes[5] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_NORMAL);
        adMinutes[6] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_POOL);
        adMinutes[7] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_RUN) + 
                       pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                       pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMinutes[8] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TEMPO);
        adMinutes[9] = pUser->SumMinutesRun(tmFrom, nDays, ACTIVITY_RUNNING, RUNTYPE_TREADMILL);
        adMinutes[10] = pUser->SumMinutesRun(tmFrom, nDays);

        CString astrWorkouts[11];
        CString astrMiles[11];
        CString astrMinutes[11];

        for(int i = 0; i < 11; i++)
        {
            astrWorkouts[i].Format("%d", anWorkouts[i]);
            astrMiles[i].Format("%.2lf", adMiles[i]);
            astrMinutes[i] = CDlgHelper::FormatTimeNoDecimal(adMinutes[i]);
        }

        double dAvgWeight = pUser->GetAverageWeight(tmFrom, nDays);
        int nAvgHR = pUser->GetAverageHR(tmFrom, nDays);

        double dAvgSleep = pUser->GetAverageSleep(tmFrom, nDays);
        int nAvgTemp = pUser->GetAverageTemperature(tmFrom, nDays);

        CString strWeight;
        strWeight.Format("%.2lf", dAvgWeight);
    
        CString strPace = CDlgHelper::FormatPace(adMinutes[10], adMiles[10], FORMAT_RUN);

        CString strHR;
        strHR.Format("%d", nAvgHR);

        CString strTemp;
        strTemp.Format("%d", nAvgTemp);

        int nRestDays = pUser->GetCompleteRestDays(tmFrom, nDays);
        int nNoRunDays = pUser->GetNoRunningDays(tmFrom, nDays);
        
        CString strRest;
        strRest.Format("%d", nRestDays);

        CString strNoRun;
        strNoRun.Format("%d", nNoRunDays);

        SetDlgItemText(IDC_EASYNUM, astrWorkouts[0]);
        SetDlgItemText(IDC_HARDNUM, astrWorkouts[1]);
        SetDlgItemText(IDC_HILLSNUM, astrWorkouts[2]);
        SetDlgItemText(IDC_INTERVALSNUM, astrWorkouts[3]);
        SetDlgItemText(IDC_MISCNUM, astrWorkouts[4]);
        SetDlgItemText(IDC_NORMALNUM, astrWorkouts[5]);
        SetDlgItemText(IDC_POOLNUM, astrWorkouts[6]);
        SetDlgItemText(IDC_RACENUM, astrWorkouts[7]);
        SetDlgItemText(IDC_TEMPONUM, astrWorkouts[8]);
        SetDlgItemText(IDC_TREADMILLNUM, astrWorkouts[9]);
        SetDlgItemText(IDC_TOTALNUM, astrWorkouts[10]);

		CDlgHelper::SetDlgOneTime(this, IDC_EASYMINS, 60.0 * adMinutes[0]);
		CDlgHelper::SetDlgOneTime(this, IDC_HARDMINS, 60.0 * adMinutes[1]);
		CDlgHelper::SetDlgOneTime(this, IDC_HILLSMINS, 60.0 * adMinutes[2]);
		CDlgHelper::SetDlgOneTime(this, IDC_INTERVALSMINS, 60.0 * adMinutes[3]);
		CDlgHelper::SetDlgOneTime(this, IDC_MISCMINS, 60.0 * adMinutes[4]);
		CDlgHelper::SetDlgOneTime(this, IDC_NORMALMINS, 60.0 * adMinutes[5]);
		CDlgHelper::SetDlgOneTime(this, IDC_POOLMINS, 60.0 * adMinutes[6]);
		CDlgHelper::SetDlgOneTime(this, IDC_RACEMINS, 60.0 * adMinutes[7]);
		CDlgHelper::SetDlgOneTime(this, IDC_TEMPOMINS, 60.0 * adMinutes[8]);
		CDlgHelper::SetDlgOneTime(this, IDC_TREADMILLMINS, 60.0 * adMinutes[9]);
		CDlgHelper::SetDlgOneTime(this, IDC_TOTALMINS, 60.0 * adMinutes[10]);
     
        SetDlgItemText(IDC_EASYMILES, astrMiles[0]);
        SetDlgItemText(IDC_HARDMILES, astrMiles[1]);
        SetDlgItemText(IDC_HILLSMILES, astrMiles[2]);
        SetDlgItemText(IDC_INTERVALSMILES, astrMiles[3]);
        SetDlgItemText(IDC_MISCMILES, astrMiles[4]);
        SetDlgItemText(IDC_NORMALMILES, astrMiles[5]);
        SetDlgItemText(IDC_POOLMILES, astrMiles[6]);
        SetDlgItemText(IDC_RACEMILES, astrMiles[7]);
        SetDlgItemText(IDC_TEMPOMILES, astrMiles[8]);
        SetDlgItemText(IDC_TREADMILLMILES, astrMiles[9]);
        SetDlgItemText(IDC_TOTALMILES, astrMiles[10]);

        SetDlgItemText(IDC_AVGWEIGHT, strWeight);
        SetDlgItemText(IDC_AVGHR, strHR);
		CDlgHelper::SetDlgTimeSleep(this, IDC_AVGSLEEP, dAvgSleep);
        SetDlgItemText(IDC_AVGTEMP, strTemp);
        SetDlgItemText(IDC_AVGPACE, strPace);

        SetDlgItemText(IDC_COMPLETEREST, strRest);
        SetDlgItemText(IDC_WITHOUTRUNNING, strNoRun);
    }
    return TRUE;
}


void CDMFRunSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CDMFRunSummaryDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CDMFRunSummaryDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CDMFRunSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CDMFRunSummaryDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CDMFRunSummaryDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CDMFRunSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}