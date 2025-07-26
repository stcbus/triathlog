#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DMFSwimSummaryDlg.h"


IMPLEMENT_DYNAMIC(CDMFSwimSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDMFSwimSummaryDlg, CAniDialog)
END_MESSAGE_MAP()


CDMFSwimSummaryDlg::CDMFSwimSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDMFSwimSummaryDlg::IDD, pParent)
{
}


CDMFSwimSummaryDlg::~CDMFSwimSummaryDlg()
{
}


BOOL CDMFSwimSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CWaitCursor wc;

    SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    COleDateTime tmFrom = GetTimeFrom();
    COleDateTime tmTo = GetTimeTo();
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom) + 1;

    CString strDate1;
    CString strDate2;
    strDate1.Format("%d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear());
    strDate2.Format("%d/%d/%d", tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());

    CString strTitle = "Swimming Summary: ";
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
        int anWorkouts[9];
        anWorkouts[0] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_DRILLS);
        anWorkouts[1] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_EZ);
        anWorkouts[2] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_HARD);
        anWorkouts[3] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_INTERVALS);
        anWorkouts[4] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OPENWATER);
        anWorkouts[5] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OTHER);
        anWorkouts[6] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_NORMAL);
        anWorkouts[7] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_SWIM) + 
                        pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        anWorkouts[8] = pUser->SumWorkoutsSwim(tmFrom, nDays, ACTIVITY_SWIMMING);

        double adMiles[9];
        adMiles[0] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_DRILLS);
        adMiles[1] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_EZ);
        adMiles[2] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_HARD);
        adMiles[3] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_INTERVALS);
        adMiles[4] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OPENWATER);
        adMiles[5] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OTHER);
        adMiles[6] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_NORMAL);
        adMiles[7] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_SWIM) + 
                     pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMiles[8] = pUser->SumMilesSwim(tmFrom, nDays, ACTIVITY_SWIMMING);

        double adMinutes[9];
        adMinutes[0] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_DRILLS);
        adMinutes[1] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_EZ);
        adMinutes[2] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_HARD);
        adMinutes[3] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_INTERVALS);
        adMinutes[4] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OPENWATER);
        adMinutes[5] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_OTHER);
        adMinutes[6] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING, SWIMTYPE_NORMAL);
        adMinutes[7] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_SWIM) + 
                       pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMinutes[8] = pUser->SumMinutesSwim(tmFrom, nDays, ACTIVITY_SWIMMING);

        CString astrWorkouts[9];
        CString astrMiles[9];
        CString astrMinutes[9];

        for(int i = 0; i < 9; i++)
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
    
        CString strPace = CDlgHelper::FormatPace(adMinutes[8], adMiles[8], FORMAT_SWIM);

        CString strHR;
        strHR.Format("%d", nAvgHR);

        CString strTemp;
        strTemp.Format("%d", nAvgTemp);

        int nRestDays = pUser->GetCompleteRestDays(tmFrom, nDays);
        int nNoSwimDays = pUser->GetNoSwimmingDays(tmFrom, nDays);
        
        CString strRest;
        strRest.Format("%d", nRestDays);

        CString strNoSwim;
        strNoSwim.Format("%d", nNoSwimDays);

        SetDlgItemText(IDC_DRILLSNUM, astrWorkouts[0]);
        SetDlgItemText(IDC_EASYNUM, astrWorkouts[1]);
        SetDlgItemText(IDC_HARDNUM, astrWorkouts[2]);
        SetDlgItemText(IDC_INTERVALSNUM, astrWorkouts[3]);
        SetDlgItemText(IDC_OPENWATERNUM, astrWorkouts[4]);
        SetDlgItemText(IDC_MISCNUM, astrWorkouts[5]);
        SetDlgItemText(IDC_NORMALNUM, astrWorkouts[6]);
        SetDlgItemText(IDC_RACENUM, astrWorkouts[7]);
        SetDlgItemText(IDC_TOTALNUM, astrWorkouts[8]);

		CDlgHelper::SetDlgOneTime(this, IDC_DRILLSMINS, 60.0 * adMinutes[0]);
		CDlgHelper::SetDlgOneTime(this, IDC_EASYMINS, 60.0 * adMinutes[1]);
		CDlgHelper::SetDlgOneTime(this, IDC_HARDMINS, 60.0 * adMinutes[2]);
		CDlgHelper::SetDlgOneTime(this, IDC_INTERVALSMINS, 60.0 * adMinutes[3]);
		CDlgHelper::SetDlgOneTime(this, IDC_OPENWATERMINS, 60.0 * adMinutes[4]);
		CDlgHelper::SetDlgOneTime(this, IDC_MISCMINS, 60.0 * adMinutes[5]);
		CDlgHelper::SetDlgOneTime(this, IDC_NORMALMINS, 60.0 * adMinutes[6]);
		CDlgHelper::SetDlgOneTime(this, IDC_RACEMINS, 60.0 * adMinutes[7]);
		CDlgHelper::SetDlgOneTime(this, IDC_TOTALMINS, 60.0 * adMinutes[8]);
     
        SetDlgItemText(IDC_DRILLSMILES, astrMiles[0]);
        SetDlgItemText(IDC_EASYMILES, astrMiles[1]);
        SetDlgItemText(IDC_HARDMILES, astrMiles[2]);
        SetDlgItemText(IDC_INTERVALSMILES, astrMiles[3]);
        SetDlgItemText(IDC_OPENWATERMILES, astrMiles[4]);
        SetDlgItemText(IDC_MISCMILES, astrMiles[5]);
        SetDlgItemText(IDC_NORMALMILES, astrMiles[6]);
        SetDlgItemText(IDC_RACEMILES, astrMiles[7]);
        SetDlgItemText(IDC_TOTALMILES, astrMiles[8]);

        SetDlgItemText(IDC_AVGWEIGHT, strWeight);
        SetDlgItemText(IDC_AVGHR, strHR);
		CDlgHelper::SetDlgTimeSleep(this, IDC_AVGSLEEP, dAvgSleep);
        SetDlgItemText(IDC_AVGTEMP, strTemp);
        SetDlgItemText(IDC_AVGPACE, strPace);

        SetDlgItemText(IDC_COMPLETEREST, strRest);
        SetDlgItemText(IDC_WITHOUTSWIMMING, strNoSwim);
    }
    return TRUE;
}


void CDMFSwimSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CDMFSwimSummaryDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CDMFSwimSummaryDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CDMFSwimSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CDMFSwimSummaryDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CDMFSwimSummaryDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CDMFSwimSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}