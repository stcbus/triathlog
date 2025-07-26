#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "DMFBikeSummaryDlg.h"


IMPLEMENT_DYNAMIC(CDMFBikeSummaryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CDMFBikeSummaryDlg, CAniDialog)
END_MESSAGE_MAP()


CDMFBikeSummaryDlg::CDMFBikeSummaryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CDMFBikeSummaryDlg::IDD, pParent)
{
}


CDMFBikeSummaryDlg::~CDMFBikeSummaryDlg()
{
}


BOOL CDMFBikeSummaryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CWaitCursor wc;

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    COleDateTime tmFrom = GetTimeFrom();
    COleDateTime tmTo = GetTimeTo();
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom) + 1;

    CString strDate1;
    CString strDate2;
    strDate1.Format("%d/%d/%d", tmFrom.GetMonth(), tmFrom.GetDay(), tmFrom.GetYear());
    strDate2.Format("%d/%d/%d", tmTo.GetMonth(), tmTo.GetDay(), tmTo.GetYear());

    CString strTitle = "Cycling Summary: ";
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
        anWorkouts[0] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_EZ);
        anWorkouts[1] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HARD);
        anWorkouts[2] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HILLS);
        anWorkouts[3] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_INTERVALS);
        anWorkouts[4] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_MOUNTAINBIKE);
        anWorkouts[5] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_OTHER);
        anWorkouts[6] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_NORMAL);
        anWorkouts[7] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_BIKE) + 
                        pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                        pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        anWorkouts[8] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TIMETRIAL);
        anWorkouts[9] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TRAINER);
        anWorkouts[10] = pUser->SumWorkoutsBike(tmFrom, nDays, ACTIVITY_BIKING);

        double adMiles[11];
        adMiles[0] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_EZ);
        adMiles[1] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HARD);
        adMiles[2] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HILLS);
        adMiles[3] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_INTERVALS);
        adMiles[4] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_MOUNTAINBIKE);
        adMiles[5] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_OTHER);
        adMiles[6] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_NORMAL);
        adMiles[7] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_BIKE) + 
                     pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                     pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMiles[8] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TIMETRIAL);
        adMiles[9] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TRAINER);
        adMiles[10] = pUser->SumMilesBike(tmFrom, nDays, ACTIVITY_BIKING);

        double adMinutes[11];
        adMinutes[0] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_EZ);
        adMinutes[1] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HARD);
        adMinutes[2] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_HILLS);
        adMinutes[3] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_INTERVALS);
        adMinutes[4] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_MOUNTAINBIKE);
        adMinutes[5] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_OTHER);
        adMinutes[6] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_NORMAL);
        adMinutes[7] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_BIKE) + 
                       pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_DUATHLON) + 
                       pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_RACE, RACETYPE_TRIATHLON);
        adMinutes[8] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TIMETRIAL);
		adMinutes[9] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING, BIKETYPE_TRAINER);
        adMinutes[10] = pUser->SumMinutesBike(tmFrom, nDays, ACTIVITY_BIKING);

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
    
        CString strPace = CDlgHelper::FormatPace(adMinutes[9], adMiles[9], FORMAT_BIKE);

        CString strHR;
        strHR.Format("%d", nAvgHR);

        CString strTemp;
        strTemp.Format("%d", nAvgTemp);

        int nRestDays = pUser->GetCompleteRestDays(tmFrom, nDays);
        int nNoBikeDays = pUser->GetNoBikingDays(tmFrom, nDays);
        
        CString strRest;
        strRest.Format("%d", nRestDays);

        CString strNoBike;
        strNoBike.Format("%d", nNoBikeDays);

        SetDlgItemText(IDC_EASYNUM, astrWorkouts[0]);
        SetDlgItemText(IDC_HARDNUM, astrWorkouts[1]);
        SetDlgItemText(IDC_HILLSNUM, astrWorkouts[2]);
        SetDlgItemText(IDC_INTERVALSNUM, astrWorkouts[3]);
        SetDlgItemText(IDC_MOUNTAINNUM, astrWorkouts[4]);
        SetDlgItemText(IDC_MISCNUM, astrWorkouts[5]);
        SetDlgItemText(IDC_NORMALNUM, astrWorkouts[6]);
        SetDlgItemText(IDC_RACENUM, astrWorkouts[7]);
        SetDlgItemText(IDC_TIMETRIALNUM, astrWorkouts[8]);
        SetDlgItemText(IDC_TRAINERNUM, astrWorkouts[9]);
        SetDlgItemText(IDC_TOTALNUM, astrWorkouts[10]);

		CDlgHelper::SetDlgOneTime(this, IDC_EASYMINS, 60.0 * adMinutes[0]);
		CDlgHelper::SetDlgOneTime(this, IDC_HARDMINS, 60.0 * adMinutes[1]);
		CDlgHelper::SetDlgOneTime(this, IDC_HILLSMINS, 60.0 * adMinutes[2]);
		CDlgHelper::SetDlgOneTime(this, IDC_INTERVALSMINS, 60.0 * adMinutes[3]);
		CDlgHelper::SetDlgOneTime(this, IDC_MOUNTAINMINS, 60.0 * adMinutes[4]);
		CDlgHelper::SetDlgOneTime(this, IDC_MISCMINS, 60.0 * adMinutes[5]);
		CDlgHelper::SetDlgOneTime(this, IDC_NORMALMINS, 60.0 * adMinutes[6]);
		CDlgHelper::SetDlgOneTime(this, IDC_RACEMINS, 60.0 * adMinutes[7]);
		CDlgHelper::SetDlgOneTime(this, IDC_TIMETRIALMINS, 60.0 * adMinutes[8]);
		CDlgHelper::SetDlgOneTime(this, IDC_TRAINERMINS, 60.0 * adMinutes[9]);
		CDlgHelper::SetDlgOneTime(this, IDC_TOTALMINS, 60.0 * adMinutes[10]);

        SetDlgItemText(IDC_EASYMILES, astrMiles[0]);
        SetDlgItemText(IDC_HARDMILES, astrMiles[1]);
        SetDlgItemText(IDC_HILLSMILES, astrMiles[2]);
        SetDlgItemText(IDC_INTERVALSMILES, astrMiles[3]);
        SetDlgItemText(IDC_MOUNTAINMILES, astrMiles[4]);
        SetDlgItemText(IDC_MISCMILES, astrMiles[5]);
        SetDlgItemText(IDC_NORMALMILES, astrMiles[6]);
        SetDlgItemText(IDC_RACEMILES, astrMiles[7]);
        SetDlgItemText(IDC_TIMETRIALMILES, astrMiles[8]);
        SetDlgItemText(IDC_TRAINERMILES, astrMiles[9]);
        SetDlgItemText(IDC_TOTALMILES, astrMiles[10]);

        SetDlgItemText(IDC_AVGWEIGHT, strWeight);
        SetDlgItemText(IDC_AVGHR, strHR);
		CDlgHelper::SetDlgTimeSleep(this, IDC_AVGSLEEP, dAvgSleep);
        SetDlgItemText(IDC_AVGTEMP, strTemp);
        SetDlgItemText(IDC_AVGPACE, strPace);

        SetDlgItemText(IDC_COMPLETEREST, strRest);
        SetDlgItemText(IDC_WITHOUTBIKING, strNoBike);
    }
    return TRUE;
}


void CDMFBikeSummaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CDMFBikeSummaryDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CDMFBikeSummaryDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CDMFBikeSummaryDlg::GetUser(void) const
{
    return m_pUser;
}


void CDMFBikeSummaryDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CDMFBikeSummaryDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CDMFBikeSummaryDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}