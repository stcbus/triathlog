#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "RaceSummaryDuathlonDlg.h"


IMPLEMENT_DYNAMIC(CRaceSummaryDuathlonDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CRaceSummaryDuathlonDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_COURSE, OnCourseSelChange)
    ON_CBN_SELCHANGE(IDC_DATES, OnDatesSelChange)
END_MESSAGE_MAP()


CRaceSummaryDuathlonDlg::CRaceSummaryDuathlonDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CRaceSummaryDuathlonDlg::IDD, pParent)
{
}


CRaceSummaryDuathlonDlg::~CRaceSummaryDuathlonDlg()
{
}


BOOL CRaceSummaryDuathlonDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    SetDlgItemText(IDT_L1DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_L2DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_L3DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3PACE, CUtil::GetPaceString(FORMAT_RUN));

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseDuathlonArray(), true, false);

    OnCourseSelChange();

    return TRUE;
}


void CRaceSummaryDuathlonDlg::OnCourseSelChange(void)
{
    CUser* pUser = GetUser();

    SetDlgItemText(IDC_RACEDISTANCE, "");
    SetDlgItemText(IDC_OVERALLPR, "");
    SetDlgItemText(IDC_OVERALLTIMERACE, "");
    SetDlgItemText(IDC_TRANSITION1PR, "");
    SetDlgItemText(IDC_TRANSITION2PR, "");
    SetDlgItemText(IDC_TRANSITION1, "");
    SetDlgItemText(IDC_TRANSITION2, "");
    SetDlgItemText(IDC_PLACE, "");
    SetDlgItemText(IDC_RACENUMBER, "");
    SetDlgItemText(IDC_NOTES, "");

    SetDlgItemText(IDC_L1RACEDISTANCE, "");
    SetDlgItemText(IDC_L1PR, "");
    SetDlgItemText(IDC_L1TIMERACE, "");
    SetDlgItemText(IDC_L1RACEPACE, "");
    SetDlgItemText(IDC_L1RACESHOES, "");

    SetDlgItemText(IDC_L2RACEDISTANCE, "");
    SetDlgItemText(IDC_L2PR, "");
    SetDlgItemText(IDC_L2TIMERACE, "");
    SetDlgItemText(IDC_L2RACEPACE, "");
    SetDlgItemText(IDC_L2RACEBIKE, "");
    SetDlgItemText(IDC_L2RACESHOES, "");

    SetDlgItemText(IDC_L3RACEDISTANCE, "");
    SetDlgItemText(IDC_L3PR, "");
    SetDlgItemText(IDC_L3TIMERACE, "");
    SetDlgItemText(IDC_L3RACEPACE, "");
    SetDlgItemText(IDC_L3RACESHOES, "");

    CComboBox* pCourseBox = (CComboBox*)GetDlgItem(IDC_COURSE);
    if((NULL != pUser) && (NULL != pCourseBox))
    {
        int nSel = pCourseBox->GetCurSel();
        if(nSel != CB_ERR)
        {
            CCourseDuathlon* pCourse = pUser->GetCourseDuathlonFromID(nSel);
            if(NULL != pCourse)
            {
                double dMiles1 = pCourse->GetLeg1Length();
                CString strMiles1;
                strMiles1.Format("%.2lf", dMiles1);
                SetDlgItemText(IDC_L1RACEDISTANCE, strMiles1);

                double dPRSeconds1 = pCourse->GetLeg1PRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dPRSeconds1, IDC_L1PR);

                double dMiles2 = pCourse->GetLeg2Length();
                CString strMiles2;
                strMiles2.Format("%.2lf", dMiles2);
                SetDlgItemText(IDC_L2RACEDISTANCE, strMiles2);

                double dPRSeconds2 = pCourse->GetLeg2PRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dPRSeconds2, IDC_L2PR);

                double dMiles3 = pCourse->GetLeg3Length();
                CString strMiles3;
                strMiles3.Format("%.2lf", dMiles3);
                SetDlgItemText(IDC_L3RACEDISTANCE, strMiles3);

                double dPRSeconds3 = pCourse->GetLeg3PRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dPRSeconds3, IDC_L3PR);

                double dPRSeconds = pCourse->GetPRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dPRSeconds, IDC_OVERALLPR);

                double dTrans1Seconds = pCourse->GetTransition1PRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dTrans1Seconds, IDC_TRANSITION1PR);
                double dTrans2Seconds = pCourse->GetTransition2PRSeconds();
                CDlgHelper::HandleDlgPROneTime(this, dTrans2Seconds, IDC_TRANSITION2PR);
                
                FindDates(pCourse);
                OnDatesSelChange();
            }
        }
    }
}


void CRaceSummaryDuathlonDlg::OnDatesSelChange(void)
{
    CUser* pUser = GetUser();
    CComboBox* pCourseBox = (CComboBox*)GetDlgItem(IDC_COURSE);
    CComboBox* pDateBox = (CComboBox*)GetDlgItem(IDC_DATES);
    if((NULL != pUser) && (NULL != pCourseBox) && (NULL != pDateBox))
    {
        int nSelCourse = pCourseBox->GetCurSel();
        int nSelDate = pDateBox->GetCurSel();
        if((nSelCourse != CB_ERR) && (nSelDate != CB_ERR))
        {
            CCourseDuathlon* pCourse = pUser->GetCourseDuathlonFromID(nSelCourse);
            CWorkout* pWorkout = m_rarRaces.GetAt(nSelDate);
            if((NULL != pCourse) && (NULL != pWorkout))
            {
                double dSeconds = pWorkout->GetSeconds();

                double dLength1 = pCourse->GetLeg1Length();
                double dSeconds1 = pWorkout->GetLeg1RaceSeconds();
                double dLength2 = pCourse->GetLeg2Length();
                double dSeconds2 = pWorkout->GetLeg2RaceSeconds();
                double dLength3 = pCourse->GetLeg3Length();
                double dSeconds3 = pWorkout->GetLeg3RaceSeconds();
            
				double dTrans1Seconds = pWorkout->GetTransition1Seconds();
                CDlgHelper::HandleDlgPROneTime(this, dTrans1Seconds, IDC_TRANSITION1);
				double dTrans2Seconds = pWorkout->GetTransition2Seconds();
                CDlgHelper::HandleDlgPROneTime(this, dTrans2Seconds, IDC_TRANSITION2);

                int nPlace = pWorkout->GetRacePosition();
                int nNum = pWorkout->GetRaceNumber();
                CString strNotes = pWorkout->GetNotes();
                
                CShoesRun* pShoes1 = pWorkout->GetLeg1RaceShoes();
                CString strShoes1;
                if(NULL != pShoes1)
                {
                    COleDateTime tmDay = pShoes1->GetFirstDay();
                    strShoes1.Format("%s %s (started %d/%d/%d)", pShoes1->GetBrand(), pShoes1->GetType(), 
                                    tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());
                }

                CShoesBike* pShoes2 = pWorkout->GetLeg2RaceShoes();
                CString strShoes2;
                if(NULL != pShoes2)
                {
                    COleDateTime tmDay = pShoes2->GetFirstDay();
                    strShoes2.Format("%s %s (started %d/%d/%d)", pShoes2->GetBrand(), pShoes2->GetType(), 
                                    tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());
                }

                CShoesRun* pShoes3 = pWorkout->GetLeg3RaceShoes();
                CString strShoes3;
                if(NULL != pShoes3)
                {
                    COleDateTime tmDay = pShoes3->GetFirstDay();
                    strShoes3.Format("%s %s (started %d/%d/%d)", pShoes3->GetBrand(), pShoes3->GetType(), 
                                    tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());
                }

                CDlgHelper::HandleDlgPROneTime(this, dSeconds, IDC_OVERALLTIMERACE);

                CDlgHelper::HandleDlgPROneTime(this, dSeconds1, IDC_L1TIMERACE);
                CDlgHelper::HandleDlgPROneTime(this, dSeconds2, IDC_L2TIMERACE);
                CDlgHelper::HandleDlgPROneTime(this, dSeconds3, IDC_L3TIMERACE);

                CString strPace1 = CDlgHelper::FormatPace(dSeconds1 / 60.0, dLength1, FORMAT_RUN);
                SetDlgItemText(IDC_L1RACEPACE, strPace1);

                CString strPace2 = CDlgHelper::FormatPace(dSeconds2 / 60.0, dLength2, FORMAT_BIKE);
                SetDlgItemText(IDC_L2RACEPACE, strPace2);

                CString strPace3 = CDlgHelper::FormatPace(dSeconds3 / 60.0, dLength3, FORMAT_RUN);
                SetDlgItemText(IDC_L3RACEPACE, strPace3);

                SetDlgItemText(IDC_L1RACESHOES, strShoes1);
                SetDlgItemText(IDC_L2RACESHOES, strShoes2);
                SetDlgItemText(IDC_L3RACESHOES, strShoes3);

                CBike* pBike = pWorkout->GetBike();
                CString strBike;
                if(NULL != pBike)
                {
                    COleDateTime tmDay = pBike->GetFirstDay();
                    strBike.Format("%s %s (started %d/%d/%d)", pBike->GetBrand(), pBike->GetType(), 
                                    tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());
                }
                SetDlgItemText(IDC_L2RACEBIKE, strBike);

                SetDlgItemInt(IDC_PLACE, nPlace);
                SetDlgItemInt(IDC_RACENUMBER, nNum);
                SetDlgItemText(IDC_NOTES, strNotes);
            }
        }
    }
}


void CRaceSummaryDuathlonDlg::FindDates(CCourseDuathlon* pCourse)
{
    CComboBox* pDates = (CComboBox*)GetDlgItem(IDC_DATES);
    if(NULL == pDates)
    {
        return;
    }

    bool bHasEntries = false;
    
    pDates->ResetContent();
    m_rarRaces.RemoveAll();

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
                        if(pCourse == pWorkout->GetCourseDuathlon())
                        {
                            COleDateTime tmCur = pDay->GetDate();
                            CString strDate;
                            strDate.Format("%d/%d/%d", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());
                            pDates->AddString(strDate);

                            m_rarRaces.Add(pWorkout);  

                            bHasEntries = true;
                        }
                    }
                }
            }
        }
    }

    if(bHasEntries)
    {
        pDates->SetCurSel(0);
    }
    CDlgHelper::ReadyComboBox(pDates, false);
}


void CRaceSummaryDuathlonDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CUser* CRaceSummaryDuathlonDlg::GetUser(void) const
{
    return m_pUser;
}


void CRaceSummaryDuathlonDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}