#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DMFStrengthSummaryDlg.h"


IMPLEMENT_DYNAMIC(CDMFStrengthSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDMFStrengthSummaryDlg, CAniDialog)
END_MESSAGE_MAP()


CDMFStrengthSummaryDlg::CDMFStrengthSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDMFStrengthSummaryDlg::IDD, pParent)
{
}


CDMFStrengthSummaryDlg::~CDMFStrengthSummaryDlg()
{
}


BOOL CDMFStrengthSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CWaitCursor wc;

    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    COleDateTime tmFrom = GetTimeFrom();
    COleDateTime tmTo = GetTimeTo();
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom) + 1;

    CString strDate1;
    CString strDate2;
    strDate1.Format("%d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear());
    strDate2.Format("%d/%d/%d", tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());

    CString strTitle = "Strength Work Summary: ";
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
        int anWorkouts[4];
        anWorkouts[0] = pUser->SumWorkoutsStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_ABS);
        anWorkouts[1] = pUser->SumWorkoutsStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_OTHER);
        anWorkouts[2] = pUser->SumWorkoutsStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_WEIGHTS);
        anWorkouts[3] = pUser->SumWorkoutsStrength(tmFrom, nDays, ACTIVITY_STRENGTH);

        double adMinutes[4];
        adMinutes[0] = pUser->SumMinutesStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_ABS);
        adMinutes[1] = pUser->SumMinutesStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_OTHER);
        adMinutes[2] = pUser->SumMinutesStrength(tmFrom, nDays, ACTIVITY_STRENGTH, STRENGTHTYPE_WEIGHTS);
        adMinutes[3] = pUser->SumMinutesStrength(tmFrom, nDays, ACTIVITY_STRENGTH);

        CString astrWorkouts[4];
        CString astrMiles[4];
        CString astrMinutes[4];

        for(int i = 0; i < 4; i++)
        {
            astrWorkouts[i].Format("%d", anWorkouts[i]);
            astrMinutes[i] = CDlgHelper::FormatTimeNoDecimal(adMinutes[i]);
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
        int nNoStrengthDays = pUser->GetNoStrengthDays(tmFrom, nDays);
        
        CString strRest;
        strRest.Format("%d", nRestDays);

        CString strNoStrength;
        strNoStrength.Format("%d", nNoStrengthDays);

        SetDlgItemText(IDC_ABSNUM, astrWorkouts[0]);
        SetDlgItemText(IDC_MISCNUM, astrWorkouts[1]);
        SetDlgItemText(IDC_WEIGHTSNUM, astrWorkouts[2]);
        SetDlgItemText(IDC_TOTALNUM, astrWorkouts[3]);

		CDlgHelper::SetDlgOneTime(this, IDC_ABSMINS, 60.0 * adMinutes[0]);
		CDlgHelper::SetDlgOneTime(this, IDC_MISCMINS, 60.0 * adMinutes[1]);
		CDlgHelper::SetDlgOneTime(this, IDC_WEIGHTSMINS, 60.0 * adMinutes[2]);
		CDlgHelper::SetDlgOneTime(this, IDC_TOTALMINS, 60.0 * adMinutes[3]);

        SetDlgItemText(IDC_AVGWEIGHT, strWeight);
        SetDlgItemText(IDC_AVGHR, strHR);
		CDlgHelper::SetDlgTimeSleep(this, IDC_AVGSLEEP, dAvgSleep);
        SetDlgItemText(IDC_AVGTEMP, strTemp);

        SetDlgItemText(IDC_COMPLETEREST, strRest);
        SetDlgItemText(IDC_WITHOUTSTRENGTH, strNoStrength);
    }
    return TRUE;
}


void CDMFStrengthSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CDMFStrengthSummaryDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CDMFStrengthSummaryDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CDMFStrengthSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CDMFStrengthSummaryDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CDMFStrengthSummaryDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CDMFStrengthSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}