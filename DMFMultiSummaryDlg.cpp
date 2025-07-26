#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DMFMultiSummaryDlg.h"


IMPLEMENT_DYNAMIC(CDMFMultiSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDMFMultiSummaryDlg, CAniDialog)
END_MESSAGE_MAP()


CDMFMultiSummaryDlg::CDMFMultiSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDMFMultiSummaryDlg::IDD, pParent)
{
}


CDMFMultiSummaryDlg::~CDMFMultiSummaryDlg()
{
}


BOOL CDMFMultiSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CWaitCursor wc;

    // don't set dist because the standards may differ
    // don't set pace because there is none
    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    COleDateTime tmFrom = GetTimeFrom();
    COleDateTime tmTo = GetTimeTo();
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom) + 1;

    CString strDate1;
    CString strDate2;
    strDate1.Format("%d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear());
    strDate2.Format("%d/%d/%d", tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());

    CString strTitle = "Multisport Summary: ";
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
        int anWorkouts[5];
        anWorkouts[0] = pUser->SumWorkoutsRun(tmFrom, nDays);
        anWorkouts[1] = pUser->SumWorkoutsBike(tmFrom, nDays);
        anWorkouts[2] = pUser->SumWorkoutsSwim(tmFrom, nDays);
        anWorkouts[3] = pUser->SumWorkoutsStrength(tmFrom, nDays);
        anWorkouts[4] = anWorkouts[0] + anWorkouts[1] + anWorkouts[2] + anWorkouts[3];

        double adMiles[5];
        adMiles[0] = pUser->SumMilesRun(tmFrom, nDays);
        adMiles[1] = pUser->SumMilesBike(tmFrom, nDays);
        adMiles[2] = pUser->SumMilesSwim(tmFrom, nDays);
        adMiles[3] = 0.0;
        adMiles[4] = adMiles[0] + adMiles[1] + adMiles[2] + adMiles[3];

        double adMinutes[5];
        adMinutes[0] = pUser->SumMinutesRun(tmFrom, nDays);
        adMinutes[1] = pUser->SumMinutesBike(tmFrom, nDays);
        adMinutes[2] = pUser->SumMinutesSwim(tmFrom, nDays);
        adMinutes[3] = pUser->SumMinutesStrength(tmFrom, nDays);
        adMinutes[4] = adMinutes[0] + adMinutes[1] + adMinutes[2] + adMinutes[3];

        double adPoints[5];
        adPoints[0] = adMiles[0] * 4.0;
        adPoints[1] = adMiles[1] * 1.0;
        adPoints[2] = adMiles[2] * 16.0;
        adPoints[3] = adMinutes[3] * 1.0;
        adPoints[4] = adPoints[0] + adPoints[1] + adPoints[2] + adPoints[3];

        CString astrWorkouts[5];
        CString astrMiles[5];
        CString astrMinutes[5];
        CString astrPoints[5];

        for(int i = 0; i < 5; i++)
        {
            astrWorkouts[i].Format("%d", anWorkouts[i]);
            astrMiles[i].Format("%.2lf", adMiles[i]);
            astrMinutes[i] = CDlgHelper::FormatTimeNoDecimal(adMinutes[i]);
            astrPoints[i].Format("%.2lf", adPoints[i]);
        }

        double dAvgWeight = pUser->GetAverageWeight(tmFrom, nDays);
        int nAvgHR = pUser->GetAverageHR(tmFrom, nDays);
        double dAvgSleep = pUser->GetAverageSleep(tmFrom, nDays);
        int nAvgTemp = pUser->GetAverageTemperature(tmFrom, nDays);

        CString strWeight;
        strWeight.Format("%.2lf", dAvgWeight);
    
        CString strHR;
        strHR.Format("%d", nAvgHR);

        CString strTemp;
        strTemp.Format("%d", nAvgTemp);

        int nRestDays = pUser->GetCompleteRestDays(tmFrom, nDays);
        int nNoBikeDays = pUser->GetNoBikingDays(tmFrom, nDays);
        int nNoRunDays = pUser->GetNoRunningDays(tmFrom, nDays);
        int nNoSwimDays = pUser->GetNoSwimmingDays(tmFrom, nDays);
        int nNoStrengthDays = pUser->GetNoStrengthDays(tmFrom, nDays);
        
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

        SetDlgItemText(IDC_RUNNINGNUM, astrWorkouts[0]);
        SetDlgItemText(IDC_BIKINGNUM, astrWorkouts[1]);
        SetDlgItemText(IDC_SWIMMINGNUM, astrWorkouts[2]);
        SetDlgItemText(IDC_STRENGTHNUM, astrWorkouts[3]);
        SetDlgItemText(IDC_TOTALNUM, astrWorkouts[4]);

		CDlgHelper::SetDlgOneTime(this, IDC_RUNNINGMINS, 60.0 * adMinutes[0]);
		CDlgHelper::SetDlgOneTime(this, IDC_BIKINGMINS, 60.0 * adMinutes[1]);
		CDlgHelper::SetDlgOneTime(this, IDC_SWIMMINGMINS, 60.0 * adMinutes[2]);
		CDlgHelper::SetDlgOneTime(this, IDC_STRENGTHMINS, 60.0 * adMinutes[3]);
		CDlgHelper::SetDlgOneTime(this, IDC_TOTALMINS, 60.0 * adMinutes[4]);
     
        SetDlgItemText(IDC_RUNNINGMILES, astrMiles[0]);
        SetDlgItemText(IDC_BIKINGMILES, astrMiles[1]);
        SetDlgItemText(IDC_SWIMMINGMILES, astrMiles[2]);
        SetDlgItemText(IDC_STRENGTHMILES, astrMiles[3]);
        SetDlgItemText(IDC_TOTALMILES, astrMiles[4]);

        SetDlgItemText(IDC_RUNNINGPOINTS, astrPoints[0]);
        SetDlgItemText(IDC_BIKINGPOINTS, astrPoints[1]);
        SetDlgItemText(IDC_SWIMMINGPOINTS, astrPoints[2]);
        SetDlgItemText(IDC_STRENGTHPOINTS, astrPoints[3]);
        SetDlgItemText(IDC_TOTALPOINTS, astrPoints[4]);

        SetDlgItemText(IDC_AVGWEIGHT, strWeight);
        SetDlgItemText(IDC_AVGHR, strHR);
		CDlgHelper::SetDlgTimeSleep(this, IDC_AVGSLEEP, dAvgSleep);
        SetDlgItemText(IDC_AVGTEMP, strTemp);

        SetDlgItemText(IDC_COMPLETEREST, strRest);
        SetDlgItemText(IDC_WITHOUTRUNNING2, strNoRun);
        SetDlgItemText(IDC_WITHOUTBIKING2, strNoBike);
        SetDlgItemText(IDC_WITHOUTSWIMMING2, strNoSwim);
        SetDlgItemText(IDC_WITHOUTSTRENGTH2, strNoStrength);
    }
    return TRUE;
}


void CDMFMultiSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CDMFMultiSummaryDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CDMFMultiSummaryDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CDMFMultiSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CDMFMultiSummaryDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CDMFMultiSummaryDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CDMFMultiSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}