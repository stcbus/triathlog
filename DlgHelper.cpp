#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "DlgHelper.h"

extern CUser* g_pUser;


void CDlgHelper::FillComboBox(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fRedoWidth, 
                              bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesBike* pShoes = rarShoes.ElementAt(i);
        if(NULL != pShoes)
        {
            if((fKeepRetired) || (!pShoes->IsRetired()))
            {
                COleDateTime tmDay = pShoes->GetFirstDay();
                CString str;
                str.Format("%s %s (started %d/%d/%d)", pShoes->GetBrand(), pShoes->GetType(), 
                            tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());

                pBox->AddString(str);
            }
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, nWhichSport, nField); 

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fRedoWidth, 
                              bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesRun* pShoes = rarShoes.ElementAt(i);
        if(NULL != pShoes)
        {
            if((fKeepRetired) || (!pShoes->IsRetired()))
            {
                COleDateTime tmDay = pShoes->GetFirstDay();
                CString str;
                str.Format("%s %s (started %d/%d/%d)", pShoes->GetBrand(), pShoes->GetType(), 
                            tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());

                pBox->AddString(str);
            }
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, nWhichSport, nField); 

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, COURSERUNARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseRun* pCourse = rarCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            CString str;
            CString strDistUnits = CUtil::GetRunDistUnitString(true);
            strDistUnits = strDistUnits.MakeLower();
            str.Format("%s (%.2lf %s)", pCourse->GetName(), pCourse->GetLength(), strDistUnits);

            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RACERUN, RACERUNFIELD_COURSE);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();  
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseBike* pCourse = rarCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            CString str;
            CString strDistUnits = CUtil::GetBikeDistUnitString(true);
            strDistUnits = strDistUnits.MakeLower();
            str.Format("%s (%.2lf %s)", pCourse->GetName(), pCourse->GetLength(), strDistUnits);

            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RACEBIKE, RACEBIKEFIELD_COURSE);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, COURSESWIMARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseSwim* pCourse = rarCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            CString str;
            CString strDistUnits = CUtil::GetSwimDistUnitString(true);
            strDistUnits = strDistUnits.MakeLower();
            str.Format("%s (%.2lf %s)", pCourse->GetName(), pCourse->GetLength(), strDistUnits);

            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RACESWIM, RACESWIMFIELD_COURSE);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseDuathlon* pCourse = rarCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            CString str;
            CString strDistUnitsRun1 = CUtil::GetRunDistUnitString(true);
            strDistUnitsRun1 = strDistUnitsRun1.MakeLower();
            CString strDistUnitsBike = CUtil::GetBikeDistUnitString(true);
            strDistUnitsBike = strDistUnitsBike.MakeLower();
            CString strDistUnitsRun2 = CUtil::GetRunDistUnitString(true);
            strDistUnitsRun2 = strDistUnitsRun2.MakeLower();

            str.Format("%s (%.2lf %s/%.2lf %s/%.2lf %s)", pCourse->GetName(), 
                       pCourse->GetLeg1Length(), strDistUnitsRun1, pCourse->GetLeg2Length(), 
                       strDistUnitsBike, pCourse->GetLeg3Length(), strDistUnitsRun2);
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RACEDU, RACEDUFIELD_COURSE);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseTriathlon* pCourse = rarCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            CString str;
            CString strDistUnitsSwim = CUtil::GetSwimDistUnitString(true);
            strDistUnitsSwim = strDistUnitsSwim.MakeLower();
            CString strDistUnitsBike = CUtil::GetBikeDistUnitString(true);
            strDistUnitsBike = strDistUnitsBike.MakeLower();
            CString strDistUnitsRun = CUtil::GetRunDistUnitString(true);
            strDistUnitsRun = strDistUnitsRun.MakeLower();

            str.Format("%s (%.2lf %s/%.2lf %s/%.2lf %s)", pCourse->GetName(), 
                       pCourse->GetLeg1Length(), strDistUnitsSwim, pCourse->GetLeg2Length(), 
                       strDistUnitsBike, pCourse->GetLeg3Length(), strDistUnitsRun);
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RACETRI, RACETRIFIELD_COURSE);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationRun* pLocation = rarLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            CString str = pLocation->GetName();
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_RUN, RUNFIELD_LOCATION);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationBike* pLocation = rarLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            CString str = pLocation->GetName();
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_BIKE, BIKEFIELD_LOCATION);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationSwim* pLocation = rarLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            CString str = pLocation->GetName();
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_SWIM, SWIMFIELD_LOCATION);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationStrength* pLocation = rarLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            CString str = pLocation->GetName();
            pBox->AddString(str);
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, SPORT_STRENGTH, STRFIELD_LOCATION);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBox(CComboBox* pBox, BIKEARRAY& rarBikes, bool fRedoWidth, 
                              bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBox");
        return;
    }

    pBox->ResetContent();
    for(int i = 0; i < rarBikes.GetCount(); i++)
    {
        CBike* pBike = rarBikes.ElementAt(i);
        if(NULL != pBike)
        {
            if((fKeepRetired) || (!pBike->IsRetired()))
            {
                COleDateTime tmDay = pBike->GetFirstDay();
                CString str;
                str.Format("%s %s (started %d/%d/%d)", pBike->GetBrand(), pBike->GetType(), 
                            tmDay.GetMonth(), tmDay.GetDay(), tmDay.GetYear());

                pBox->AddString(str);
            }
        }
    }

    CDlgHelper::OptionallyAddEmptySpace(pBox, fAddBlankIfNeeded, nWhichSport, nField);

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBoxWind(CComboBox* pBox, bool fRedoWidth)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBoxWind");
        return;
    }

    pBox->ResetContent();
    pBox->AddString(CUtil::WindToString(WIND_NONE));
    pBox->AddString(CUtil::WindToString(WIND_LIGHT));
	pBox->AddString(CUtil::WindToString(WIND_MEDIUM));
    pBox->AddString(CUtil::WindToString(WIND_STRONG));
	pBox->AddString(CUtil::WindToString(WIND_VERYSTRONG));

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBoxChoppiness(CComboBox* pBox, bool fRedoWidth)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::FillComboBoxChoppiness");
        return;
    }

    pBox->ResetContent();
    pBox->AddString(CUtil::ChoppinessToString(CHOPPINESS_NONE));
    pBox->AddString(CUtil::ChoppinessToString(CHOPPINESS_LIGHT));
	pBox->AddString(CUtil::ChoppinessToString(CHOPPINESS_MEDIUM));
    pBox->AddString(CUtil::ChoppinessToString(CHOPPINESS_HEAVY));
	pBox->AddString(CUtil::ChoppinessToString(CHOPPINESS_VERYHEAVY));

    pBox->SetCurSel(0);
    CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
}


void CDlgHelper::FillComboBoxMonths(CComboBox* pBox, bool fRedoWidth)
{
    if(NULL != pBox)
    {
        pBox->ResetContent();
        for(int i = JANUARY; i <= DECEMBER; i++)
        {
            pBox->AddString(CUtil::MonthToString(i));
        }

        pBox->SetCurSel(0);
        CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
    }
}


void CDlgHelper::FillComboBoxDays(CComboBox* pDayBox, CComboBox* pMonthBox, int nYear)
{
    if((NULL != pMonthBox) && (NULL != pDayBox))
    {
        pDayBox->ResetContent();

        int nSel = pMonthBox->GetCurSel() + 1;
        CString str;

        // if they have filled in a year, use that for calculation
        // otherwise, use 1997 (a non-leap year)

        int nDays = CUtil::GetNumDaysInMonth(nYear, nSel);
        for(int i = 1; i <= nDays; i++)
        {
            CString str;
            str.Format("%d", i);
            pDayBox->AddString(str);
        }
        pDayBox->SetCurSel(0);
        CDlgHelper::ReadyComboBox(pDayBox, false);
    }
}


void CDlgHelper::FillComboBoxDaysOfWeek(CComboBox* pBox, bool fRedoWidth)
{
    if(NULL != pBox)
    {
        pBox->ResetContent();
        for(int i = SUNDAY; i <= SATURDAY; i++)
        {
            pBox->AddString(CUtil::DayToString(i));
        }
        pBox->SetCurSel(0);
        CDlgHelper::ReadyComboBox(pBox, fRedoWidth);
    }
}


bool CDlgHelper::OptionallyAddEmptySpace(CComboBox* pBox, bool bAddBlankIfNeeded, int nWhichSport, int nField)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::OptionallyAddEmptySpace");
        return false;
    }

    CUser* pUser = g_pUser;
    if((true == bAddBlankIfNeeded) && (NULL != pUser))
    {
        if(false == CDlgHelper::IsUserFieldMandatory(nWhichSport, nField))
        {
            pBox->AddString("");
            return true;
        }
    }

    return false;
}


bool CDlgHelper::IsUserFieldMandatory(int nWhichSport, int nField)
{
    CUser* pUser = g_pUser;
    if(NULL == pUser)
    {
        return true;
    }

    switch(nWhichSport)
    {
    case SPORT_RUN:
        {
            return pUser->IsRunFieldMandatory(nField);
        }

    case SPORT_BIKE:
        {
            return pUser->IsBikeFieldMandatory(nField);
        }

    case SPORT_SWIM:
        {
            return pUser->IsSwimFieldMandatory(nField);
        }

    case SPORT_STRENGTH:
        {
            return pUser->IsStrengthFieldMandatory(nField);
        }

    case SPORT_RACERUN:
        {
            return pUser->IsRaceRunFieldMandatory(nField);
        }

    case SPORT_RACEBIKE:
        {
            return pUser->IsRaceBikeFieldMandatory(nField);
        }

    case SPORT_RACESWIM:
        {
            return pUser->IsRaceSwimFieldMandatory(nField);
        }

    case SPORT_RACEDU:
        {
            return pUser->IsRaceDuathlonFieldMandatory(nField);
        }

    case SPORT_RACETRI:
        {
            return pUser->IsRaceTriathlonFieldMandatory(nField);
        }

    case SPORT_START:
        {
            return pUser->IsStartFieldMandatory(nField);
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CDlgHelper::OptionallyAddEmptySpace");
            return true;
        }
    }
}


double CDlgHelper::ReadDlgTwoDistances(CDialog* pDlg, int nID1, int nID2, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return NOGRAPHDATA;
    }

    BOOL fOK1;
    int nDistWhole = pDlg->GetDlgItemInt(nID1, &fOK1);
    CString strDistFrac;
    pDlg->GetDlgItemText(nID2, strDistFrac);

    // handling possibly empty parts
    // if all are not there, then use the value that says nothing
    if((strDistFrac.IsEmpty()) && (false == fOK1))
    {
        rfOK = false;
        return NOGRAPHDATA;
    }
    // otherwise, put in zeroes for the ones that didn't get filled out
    else
    {
        if(false == fOK1)
        {
            nDistWhole = 0;
        }
        if(strDistFrac.IsEmpty())
        {
            strDistFrac = "0";
        }
    }

    double dMiles = CUtil::GetDouble(nDistWhole, strDistFrac);

    rfOK = (fOK1 && !strDistFrac.IsEmpty());

    return dMiles;
}


double CDlgHelper::ReadDlgTwoTimes(CDialog* pDlg, int nID1, int nID2, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return 0.0;
    }

    BOOL fOK1;
    BOOL fOK2;

    int nMinutes = pDlg->GetDlgItemInt(nID1, &fOK1);
    int nSeconds = pDlg->GetDlgItemInt(nID2, &fOK2);
    
    // handling possibly empty parts
    // if all are not there, then use the value that says nothing
    if((false == fOK1) && (false == fOK2))
    {
        rfOK = false;
        return NOGRAPHDATA;
    }
    // otherwise, put in zeroes for the ones that didn't get filled out
    else
    {
        if(false == fOK1)
        {
            nMinutes = 0;
        }
        if(false == fOK2)
        {
            nSeconds = 0;
        }
    }

    double dTotal = 60 * (double) nMinutes + (double) nSeconds;
    
    rfOK = (fOK1 && fOK2);

    return dTotal;
}


double CDlgHelper::ReadDlgTimeSleep(CDialog* pDlg, int nID1, int nID2, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return 0.0;
    }

    bool fOK1;
    bool fOK2;

    int nHours = CDlgHelper::ReadDlgOneInt(pDlg, nID1, fOK1);
    int nMinutes = CDlgHelper::ReadDlgOneInt(pDlg, nID2, fOK2);

    // handling possibly empty parts
    // if all are not there, then use the value that says nothing
    if((false == fOK1) && (false == fOK2))
    {
        rfOK = false;
        return NOGRAPHDATA;
    }
    // otherwise, put in zeroes for the ones that didn't get filled out
    else
    {
        if(false == fOK1)
        {
            nHours = 0;
        }
        if(false == fOK2)
        {
            nMinutes = 0;
        }
    }

    if((nHours > 24) || (nHours < 0) || (nMinutes < 0) || (nMinutes > 59))
    {
        rfOK = false;
        return 0.0;
    }

    double dSleep = double(nHours) + (double)nMinutes / 60.0;

    return dSleep;
}


COleDateTime CDlgHelper::ReadDlgTimeSpinner(CDialog* pDlg, int nID1, int nID2, int nID3, COleDateTime tmDay, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return COleDateTime();
    }

    bool fOK;
    bool fOK2;

    int nHour = CDlgHelper::ReadDlgOneInt(pDlg, nID1, fOK);
    int nMinute = CDlgHelper::ReadDlgOneInt(pDlg, nID2, fOK2);
    CString str;
    pDlg->GetDlgItemText(nID3, str);
    bool bAM = ("AM" == str);
    if((!fOK) || (!fOK2) || (nHour > 12) || (nHour < 1) || (nMinute < 0) || (nMinute > 59))
    {
        rfOK = false;
        return COleDateTime();
    }
    if((!bAM) && (nHour < 12))
    {
        nHour += 12;
    }
    if((bAM) && (12 == nHour))
    {
        nHour = 0;
    }
    return COleDateTime(tmDay.GetYear(), tmDay.GetMonth(), tmDay.GetDay(), nHour, nMinute, 0);
}


double CDlgHelper::ReadDlgFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return 0.0;
    }

    BOOL fOK1;
    BOOL fOK2;
    BOOL fOK3;

    int nRaceHours = pDlg->GetDlgItemInt(nID1, &fOK1);
    int nRaceMinutes = pDlg->GetDlgItemInt(nID2, &fOK2);
    int nRaceSeconds = pDlg->GetDlgItemInt(nID3, &fOK3);
    CString strRaceFrac;
    pDlg->GetDlgItemText(nID4, strRaceFrac);

    // handling possibly empty parts
    // if all are not there, then use the value that says nothing
    if((false == fOK1) && (false == fOK2) && (false == fOK3) && (strRaceFrac.IsEmpty()))
    {
        rfOK = false;
        return NOGRAPHDATA;
    }
    // otherwise, put in zeroes for the ones that didn't get filled out
    else
    {
        if(false == fOK1)
        {
            nRaceHours = 0;
        }
        if(false == fOK2)
        {
            nRaceMinutes = 0;
        }
        if(false == fOK3)
        {
            nRaceSeconds = 0;
        }
        if(strRaceFrac.IsEmpty())
        {
            strRaceFrac = "0";
        }
    }

    double dSecTime = (double)nRaceHours * 3600 + (double)nRaceMinutes * 60 + CUtil::GetDouble(nRaceSeconds, strRaceFrac);

    rfOK = (fOK1 && fOK2 && fOK3 && !strRaceFrac.IsEmpty());

    return dSecTime;
}


int CDlgHelper::ReadDlgOneInt(CDialog* pDlg, int nID1, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return 0;
    }

    BOOL fOK1;
    int nInt = pDlg->GetDlgItemInt(nID1, &fOK1);

    // if it's empty, note that
    if(false == fOK1)
    {
        rfOK = false;
        return NOGRAPHDATA;
    }

    rfOK = (TRUE == fOK1);

    return nInt;
}


CString CDlgHelper::ReadDlgOneString(CDialog* pDlg, int nID1, bool& rfOK)
{
    if(NULL == pDlg)
    {
        rfOK = false;
        return "NULL";
    }

    CString str;
    pDlg->GetDlgItemText(nID1, str);

    rfOK = (!str.IsEmpty());

    return str;
}


void CDlgHelper::SetDlgTwoDistances(CDialog* pDlg, int nID1, int nID2, double dDist)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
	if(CUtil::HasNoData(dDist))
    {
        return;
    }

    CString str;
    str.Format("%.3lf", dDist);
    int n = str.Find('.');

    // should always find a decimal since we specified %.3lf above
    if(-1 != n)
    {
        CString strInt = str.Left(n);
        pDlg->SetDlgItemText(nID1, strInt);

        CString strDec = str.Right(str.GetLength() - n - 1);

        // remove trailing zeroes, keeping at least two digits
        while((strDec.GetLength() > 2) && (strDec.Right(1) == "0"))
        {
            strDec = strDec.Left(strDec.GetLength() - 1);
        }

        pDlg->SetDlgItemText(nID2, strDec);
    }
}


void CDlgHelper::SetDlgOneTime(CDialog* pDlg, int nID, double dSec)
{
	if(NULL == pDlg)
	{
		return;
	}

	if(CUtil::HasNoData(dSec))
	{
		return;
	}

    CString strFrac;

    int nHours = (int)(dSec / 3600.0);
    dSec -= 3600.0 * nHours;
    int nMinutes = (int)(dSec / 60.0);
    dSec -= 60.0 * nMinutes;
    int nSeconds = (int)dSec;

    strFrac.Format("%.2lf", dSec);
    strFrac = strFrac.Right(2);

	CString strResult;

	if(0 == nHours)
	{
		strResult.Format("%d:%02d", nMinutes, nSeconds);
		
		if("00" != strFrac)
		{
			strResult += "." + strFrac;
		}
	}
	else
	{
		strResult.Format("%d:%02d:%02d", nHours, nMinutes, nSeconds);

		if("00" != strFrac)
		{
			strResult += "." + strFrac;
		}
	}

	pDlg->SetDlgItemText(nID, strResult);
}


void CDlgHelper::SetDlgTwoTimes(CDialog* pDlg, int nID1, int nID2, double dSec)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
    if(CUtil::HasNoData(dSec))
    {
        return;
    }

    int nMinutes = (int)(dSec / 60.0);
    int nSeconds = ((int)dSec) % 60;

    pDlg->SetDlgItemInt(nID1, nMinutes);
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID2, nSeconds);
}


void CDlgHelper::SetDlgThreeTimes(CDialog* pDlg, int nID1, int nID2, int nID3, double dSec)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
    if(CUtil::HasNoData(dSec))
    {
        return;
    }

    CString strFrac;

    int nMinutes = (int)(dSec / 60.0);
    dSec -= 60.0 * nMinutes;
    int nSeconds = (int)dSec;

    strFrac.Format("%.2lf", dSec);
    strFrac = strFrac.Right(2);
    
    CDlgHelper::SetDlgOneInt(pDlg, nID1, nMinutes);
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID2, nSeconds);
    pDlg->SetDlgItemText(nID3, strFrac);
}


void CDlgHelper::SetDlgFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, double dSec)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
    if(CUtil::HasNoData(dSec))
    {
        return;
    }

    CString strFrac;

    int nHours = (int)(dSec / 3600.0);
    dSec -= 3600.0 * nHours;
    int nMinutes = (int)(dSec / 60.0);
    dSec -= 60.0 * nMinutes;
    int nSeconds = (int)dSec;

    strFrac.Format("%.2lf", dSec);
    strFrac = strFrac.Right(2);
    
    pDlg->SetDlgItemInt(nID1, nHours);
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID2, nMinutes);
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID3, nSeconds);
    pDlg->SetDlgItemText(nID4, strFrac);
}


void CDlgHelper::SetDlgOneIntTwoDigits(CDialog* pDlg, int nID1, int nVal)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
    if(CUtil::HasNoData(nVal))
    {
        return;
    }

    CString str;
    str.Format("%d", nVal);
    if(1 == str.GetLength())
    {
        str = "0" + str;
    }

    pDlg->SetDlgItemText(nID1, str);
}


void CDlgHelper::SetDlgOneInt(CDialog* pDlg, int nID1, int nVal)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if there is no data here, don't set anything
	if(CUtil::HasNoData(nVal))
    {
        return;
    }

    pDlg->SetDlgItemInt(nID1, nVal);
}


void CDlgHelper::SetDlgTimeSpinner(CDialog* pDlg, int nID1, int nID2, int nID3, COleDateTime tm)
{
    if(NULL == pDlg)
    {
        return;
    }

    bool fAM = (tm.GetHour() < 12);
    int nHour = tm.GetHour();
    if(nHour >= 12)
    {
        nHour -= 12;
    }
    if(nHour == 0)
    {
        nHour = 12;
    }
    CString str;
    if(fAM)
    {
        str = "AM"; 
    }
    else 
    {
        str = "PM";
    }
    pDlg->SetDlgItemText(nID3, str);
    pDlg->SetDlgItemInt(nID1, nHour);
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID2, tm.GetMinute());
}


void CDlgHelper::SetDlgTimeStart(CDialog* pDlg, int nID, COleDateTime tm)
{
    if(NULL == pDlg)
    {
        return;
    }

    bool fAM = (tm.GetHour() < 12);
    int nHour = tm.GetHour();
    if(nHour >= 12)
    {
        nHour -= 12;
    }
    if(nHour == 0)
    {
        nHour = 12;
    }
    CString str;
    if(fAM)
    {
        str = "AM"; 
    }
    else 
    {
        str = "PM";
    }

	CString strTime;
	strTime.Format("%d:%02d %s", nHour, tm.GetMinute(), str);

	pDlg->SetDlgItemText(nID, strTime);
}


void CDlgHelper::SetDlgDouble(CDialog* pDlg, int nID, double dVal, int nDecimals)
{
	if(NULL == pDlg)
	{
		return;
	}

	// if there is no data, do nothing
	if(CUtil::HasNoData(dVal))
	{
		return;
	}

	CString str;
	if(0 == nDecimals)
	{
		str.Format("%d", (int)dVal);
	}
	else if(1 == nDecimals)
	{
		str.Format("%.1lf", dVal);
	}
	else if(2 == nDecimals)
	{
		str.Format("%.2lf", dVal);
	}
	else if(3 == nDecimals)
	{
		str.Format("%.3lf", dVal);
	}
	else if(4 == nDecimals)
	{
		str.Format("%.4lf", dVal);
	}

	pDlg->SetDlgItemText(nID, str);
}


void CDlgHelper::SetDlgTimeSleep(CDialog* pDlg, int nID, double dSleep)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if no data, set them to nothing
	if(CUtil::HasNoData(dSleep))
    {
        return;
    }

	int nHours = (int)dSleep;
    double dFracSleep = dSleep - nHours;
	int nMinutes = (int)(dFracSleep * 60 + 0.04);  // the 0.04 is a fudge factor for rounding errors

	CString str;
	str.Format("%d:%02d", nHours, nMinutes);

	pDlg->SetDlgItemText(nID, str);
}


void CDlgHelper::SetDlgTimeSleep(CDialog* pDlg, int nID1, int nID2, double dSleep)
{
    if(NULL == pDlg)
    {
        return;
    }

    // if no data, set them to nothing
	if(CUtil::HasNoData(dSleep))
    {
        return;
    }

    pDlg->SetDlgItemInt(nID1, (int)dSleep);
    double dFracSleep = dSleep - (int)dSleep;
    CDlgHelper::SetDlgOneIntTwoDigits(pDlg, nID2, (int)(dFracSleep * 60 + .04)); // fudge factor for round off errors
}


void CDlgHelper::SetDlgOneString(CDialog* pDlg, int nID1, CString str)
{
    if(NULL == pDlg)
    {
        return;
    }

    pDlg->SetDlgItemText(nID1, str);
}


CShoesBike* CDlgHelper::GetComboSel(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fKeepRetired, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if within range and they're keeping retired shoes in the box, just get it
    if((fKeepRetired) && (nSel < rarShoes.GetCount()))
    {
        return rarShoes.GetAt(nSel);
    }

    // if they're not keeping them, walk through non-retired ones and find it
    int nActive = 0;
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesBike* pCur = rarShoes.GetAt(i);
        if(NULL != pCur)
        {
            if(!pCur->IsRetired())
            {
                if(nActive == nSel)
                {
                    return pCur;
                }
                nActive++;
            }
        }
    }

    // if they're here, either something's wrong or the selection is the blank spot
    // either way, there's nothing to return but NULL
    rfOK = false;
    return NULL;
}


CShoesRun* CDlgHelper::GetComboSel(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fKeepRetired, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if within range and they're keeping retired shoes in the box, just get it
    if((fKeepRetired) && (nSel < rarShoes.GetCount()))
    {
        return rarShoes.GetAt(nSel);
    }

    // if they're not keeping them, walk through non-retired ones and find it
    int nActive = 0;
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesRun* pCur = rarShoes.GetAt(i);
        if(NULL != pCur)
        {
            if(!pCur->IsRetired())
            {
                if(nActive == nSel)
                {
                    return pCur;
                }
                nActive++;
            }
        }
    }

    // if they're here, either something's wrong or the selection is the blank spot
    // either way, there's nothing to return but NULL
    rfOK = false;
    return NULL;
}


CCourseRun* CDlgHelper::GetComboSel(CComboBox* pBox, COURSERUNARRAY& rarCourses, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarCourses.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarCourses.GetAt(nSel);
}


CCourseBike* CDlgHelper::GetComboSel(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarCourses.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarCourses.GetAt(nSel);
}


CCourseSwim* CDlgHelper::GetComboSel(CComboBox* pBox, COURSESWIMARRAY& rarCourses, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarCourses.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarCourses.GetAt(nSel);
}


CCourseDuathlon* CDlgHelper::GetComboSel(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarCourses.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarCourses.GetAt(nSel);
}


CCourseTriathlon* CDlgHelper::GetComboSel(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarCourses.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarCourses.GetAt(nSel);
}


CLocationRun* CDlgHelper::GetComboSel(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarLocations.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarLocations.GetAt(nSel);
}

CLocationBike* CDlgHelper::GetComboSel(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarLocations.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarLocations.GetAt(nSel);
}


CLocationSwim* CDlgHelper::GetComboSel(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarLocations.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarLocations.GetAt(nSel);
}


CLocationStrength* CDlgHelper::GetComboSel(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they selected the blank space afterwards, return NULL
    if(nSel >= rarLocations.GetCount())
    {
        rfOK = false;
        return NULL;
    }

    return rarLocations.GetAt(nSel);
}


CBike* CDlgHelper::GetComboSel(CComboBox* pBox, BIKEARRAY& rarBikes, bool fKeepRetired, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return NULL;
    }

    int nSel = pBox->GetCurSel();
    if(CB_ERR == nSel)
    {
        rfOK = false;
        return NULL;
    }

    // if they're keeping the retired bikes, just get the one they wanted
    if((fKeepRetired) && (nSel < rarBikes.GetCount()))
    {
        return rarBikes.GetAt(nSel);
    }

    // otherwise we have to run through all looking for non-retired ones
    int nActive = 0;
    for(int i = 0; i < rarBikes.GetCount(); i++)
    {
        CBike* pCur = rarBikes.GetAt(i);
        if(NULL != pCur)
        {
            if(!pCur->IsRetired())
            {
                if(nActive == nSel)
                {
                    return pCur;
                }
                nActive++;
            }
        }
    }

    // if we're here either something is wrong or they chose the blank edit box
    // either way, we can only return NULL
    rfOK = false;
    return NULL;
}


int CDlgHelper::GetComboSelWind(CComboBox* pBox, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return WIND_NONE;
    }
    
    int nSel = pBox->GetCurSel();

	switch(nSel)
	{
	case 0:
		{
			return WIND_NONE;
		}
	
	case 1:
		{
			return WIND_LIGHT;
		}

	case 2:
		{
			return WIND_MEDIUM;
		}

	case 3:
		{
			return WIND_STRONG;
		}

	case 4:
		{
			return WIND_VERYSTRONG;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CDlgHelper::GetComboSelWind");
			rfOK = false;
			return WIND_NONE;
		}
	}

    return nSel;
}
    

int CDlgHelper::GetComboSelChoppiness(CComboBox* pBox, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return CHOPPINESS_NONE;
    }
    
    int nSel = pBox->GetCurSel();

	switch(nSel)
	{
	case 0:
		{
			return CHOPPINESS_NONE;
		}
	
	case 1:
		{
			return CHOPPINESS_LIGHT;
		}

	case 2:
		{
			return CHOPPINESS_MEDIUM;
		}

	case 3:
		{
			return CHOPPINESS_HEAVY;
		}

	case 4:
		{
			return CHOPPINESS_VERYHEAVY;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CDlgHelper::GetComboSelChoppiness");
			rfOK = false;
			return CHOPPINESS_NONE;
		}
	}

    return nSel;
}


int CDlgHelper::GetComboSelDayOfWeek(CComboBox* pBox, bool& rfOK)
{
    rfOK = true;
    if(NULL == pBox)
    {
        rfOK = false;
        return MONDAY;
    }
    int n = pBox->GetCurSel();
    
    // the list box starts at 0, MONDAY starts at 1
    n++;

    rfOK = ((n >= SUNDAY) && (n <= SATURDAY));
   
    return n;
}   


int CDlgHelper::GetComboSel(CComboBox* pBox, bool fNoSelIsOK /* = false */)
{
	if(NULL == pBox)
	{
		CUtil::Fatal("Bad parameter to CDlgHelper::GetComboSel");
		return -1;
	}

	int nSel = pBox->GetCurSel();
	if((CB_ERR == nSel) && (false == fNoSelIsOK))
	{
		CUtil::Fatal("Bad selection in CDlgHelper::GetComboSel");
		return -1;
	}

	return nSel;
}


void CDlgHelper::SetComboSel(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fKeepRetired, CShoesBike* pShoes)
{
    if(NULL == pBox)
    {
        return;
    }
    int iSel = 0;

    for(int i = 0; iSel <(int)rarShoes.GetCount(); i++)
    {
        CShoesBike* pCur = rarShoes.GetAt(i);
        if(pCur == pShoes)
        {
            break;
        }
        else if((fKeepRetired) || (NULL != pCur && !pCur->IsRetired()))
        {
            iSel++;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fKeepRetired, CShoesRun* pShoes)
{
    if(NULL == pBox)
    {
        return;
    }
    int iSel = 0;

    for(int i = 0; iSel <(int)rarShoes.GetCount(); i++)
    {
        CShoesRun* pCur = rarShoes.GetAt(i);
        if(pCur == pShoes)
        {
            break;
        }
        else if((fKeepRetired) || (NULL != pCur && !pCur->IsRetired()))
        {
            iSel++;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, COURSERUNARRAY& rarCourses, CCourseRun* pCourse)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel < (int)rarCourses.GetCount(); iSel++)
    {
        CCourseRun* pCur = rarCourses.GetAt(iSel);
        if(pCur == pCourse)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, CCourseBike* pCourse)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarCourses.GetCount(); iSel++)
    {
        CCourseBike* pCur = rarCourses.GetAt(iSel);
        if(pCur == pCourse)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, COURSESWIMARRAY& rarCourses, CCourseSwim* pCourse)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarCourses.GetCount(); iSel++)
    {
        CCourseSwim* pCur = rarCourses.GetAt(iSel);
        if(pCur == pCourse)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, CCourseDuathlon* pCourse)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarCourses.GetCount(); iSel++)
    {
        CCourseDuathlon* pCur = rarCourses.GetAt(iSel);
        if(pCur == pCourse)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, CCourseTriathlon* pCourse)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarCourses.GetCount(); iSel++)
    {
        CCourseTriathlon* pCur = rarCourses.GetAt(iSel);
        if(pCur == pCourse)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, CLocationRun* pLocation)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarLocations.GetCount(); iSel++)
    {
        CLocationRun* pCur = rarLocations.GetAt(iSel);
        if(pCur == pLocation)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, CLocationBike* pLocation)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarLocations.GetCount(); iSel++)
    {
        CLocationBike* pCur = rarLocations.GetAt(iSel);
        if(pCur == pLocation)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, CLocationSwim* pLocation)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarLocations.GetCount(); iSel++)
    {
        CLocationSwim* pCur = rarLocations.GetAt(iSel);
        if(pCur == pLocation)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, CLocationStrength* pLocation)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(iSel = 0; iSel <(int)rarLocations.GetCount(); iSel++)
    {
        CLocationStrength* pCur = rarLocations.GetAt(iSel);
        if(pCur == pLocation)
        {
            break;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSel(CComboBox* pBox, BIKEARRAY& rarBikes, bool fKeepRetired, CBike* pBike)
{
    if(NULL == pBox)
    {
        return;
    }

    int iSel = 0;
    for(int i = 0; iSel <(int)rarBikes.GetCount(); i++)
    {
        CBike* pCur = rarBikes.GetAt(iSel);
        if(pCur == pBike)
        {
            break;
        }
        else if((fKeepRetired) || (NULL != pCur && !pCur->IsRetired()))
        {
            iSel++;
        }
    }

    // if we can, just set the current selection
    if(iSel < pBox->GetCount())
    {
        pBox->SetCurSel(iSel);
    }
    // otherwise, as may happen if someone initially didn't require bike shoes and didn't choose them,
    // then later required them and viewed the day they didn't enter them, this gets reset to the start
    else
    {
        if(pBox->GetCount() > 0)
        {
            pBox->SetCurSel(0);
        }
    }
}


void CDlgHelper::SetComboSelWind(CComboBox* pBox, int nWind)
{
    if(NULL == pBox)
    {
        return;
    }

	switch(nWind)
	{
	case WIND_NONE:
		{
			pBox->SetCurSel(0);
			break;
		}

	case WIND_LIGHT:
		{
			pBox->SetCurSel(1);
			break;
		}

	case WIND_MEDIUM:
		{
			pBox->SetCurSel(2);
			break;
		}

	case WIND_STRONG:
		{
			pBox->SetCurSel(3);
			break;
		}

	case WIND_VERYSTRONG:
		{
			pBox->SetCurSel(4);
			break;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CDlgHelper::SetComboSelWind");
			break;
		}
	}
}


void CDlgHelper::SetComboSelChoppiness(CComboBox* pBox, int nChoppiness)
{
    if(NULL == pBox)
    {
        return;
    }

	switch(nChoppiness)
	{
	case CHOPPINESS_NONE:
		{
			pBox->SetCurSel(0);
			break;
		}

	case CHOPPINESS_LIGHT:
		{
			pBox->SetCurSel(1);
			break;
		}

	case CHOPPINESS_MEDIUM:
		{
			pBox->SetCurSel(2);
			break;
		}

	case CHOPPINESS_HEAVY:
		{
			pBox->SetCurSel(3);
			break;
		}

	case CHOPPINESS_VERYHEAVY:
		{
			pBox->SetCurSel(4);
			break;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CDlgHelper::SetComboSelChoppiness");
			break;
		}
	}
}

   
bool CDlgHelper::HandleDlgPROneTime(CDialog* pDlg, double dSec, int nID)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nID, "");

	CString strText[4];
	CString strAlt1;
	if((CUtil::HasData(dSec)) && (dSec > 0))
    {
        int nSec = (int)dSec;
        double dMilli = dSec - (double)nSec;
        strText[3].Format("%.2lf", dMilli);
        if("0." == strText[3].Left(2))
        {
            strText[3] = strText[3].Right(strText[3].GetLength() - 2);
        }

        int nSecPart = nSec % 60;
        strText[2].Format("%02d", nSecPart);

        nSec -= nSecPart;
        int nMin = (nSec / 60) % 60;
        strText[1].Format("%02d", nMin);
		strAlt1.Format("%d", nMin);   // provide an alternative that does not have 2 digits necessarily

        nSec -= 60 * nMin;
        int nHour = nSec / 3600;
        strText[0].Format("%d", nHour);

		CString strFinal;
		if(0 == nHour)
		{
			strFinal = strAlt1 + ":" + strText[2];
			if(0.0 != dMilli)
			{
				strFinal += "." + strText[3];
			}
		}
		else
		{
			strFinal = strText[0] + ":" + strText[1] + ":" + strText[2];
			if(0.0 != dMilli)
			{
				strFinal += "." + strText[3];
			}
		}	

		pDlg->SetDlgItemText(nID, strFinal);
        return true;
    }
    return false;
}


bool CDlgHelper::HandleDlgPRTwoTimes(CDialog* pDlg, double dSec, int nID1, int nID2)
{
    if(NULL == pDlg)
    {
        return false;
    }

    CString strText[4];
	if(CUtil::HasData(dSec) && (dSec > 0))
    {
        int nSec = (int)dSec;
        double dMilli = dSec - (double)nSec;
        strText[3].Format("%.2lf", dMilli);
        if("0." == strText[3].Left(2))
        {
            strText[3] = strText[3].Right(strText[3].GetLength() - 2);
        }

        int nSecPart = nSec % 60;
        strText[2].Format("%02d", nSecPart);

        nSec -= nSecPart;
        int nMin = nSec / 60;
        strText[1].Format("%d", nMin);

        nSec -= nMin;
        int nHour = nSec / 3600;
        strText[0].Format("%02d", nHour);
    }

    pDlg->SetDlgItemText(nID1, strText[1]);
    pDlg->SetDlgItemText(nID2, strText[2]);
    return true;
}


bool CDlgHelper::HandleDlgPRFourTimes(CDialog* pDlg, double dSec, int nID1, int nID2, int nID3, int nID4)
{
    if(NULL == pDlg)
    {
        return false;
    }

    CString strText[4];
	if(CUtil::HasData(dSec) && (dSec > 0))
    {
        int nSec = (int)dSec;
        double dMilli = dSec - (double)nSec;
        strText[3].Format("%.2lf", dMilli);
        if("0." == strText[3].Left(2))
        {
            strText[3] = strText[3].Right(strText[3].GetLength() - 2);
        }

        int nSecPart = nSec % 60;
        strText[2].Format("%02d", nSecPart);

        nSec -= nSecPart;
        int nMin = nSec % 3600;
        int nMinPart = nMin / 60;
        strText[1].Format("%02d", nMinPart);

        nSec -= nMin;
        int nHour = nSec / 3600;
        strText[0].Format("%02d", nHour);
    }

    pDlg->SetDlgItemText(nID1, strText[0]);
    pDlg->SetDlgItemText(nID2, strText[1]);
    pDlg->SetDlgItemText(nID3, strText[2]);
    pDlg->SetDlgItemText(nID4, strText[3]);
    return true;
}



bool CDlgHelper::HandleDlgPaceTwoTimes(CDialog* pDlg, int nIDT1, int nIDT2, int nIDD1, int nIDD2, int nIDDest, int nFormat)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nIDDest, "");

    bool fOK;

    double dSeconds = CDlgHelper::ReadDlgTwoTimes(pDlg, nIDT1, nIDT2, fOK);
    double dMinutes = dSeconds / 60;
    if(CUtil::HasData(dSeconds))
    {
        double dDistance = CDlgHelper::ReadDlgTwoDistances(pDlg, nIDD1, nIDD2, fOK);
        if((CUtil::HasData(dDistance)) && (0.0 != dDistance))
        {
            CString strText = CDlgHelper::FormatPace(dMinutes, dDistance, nFormat);
            pDlg->SetDlgItemText(nIDDest, strText);
            return true;
        }
    }
    return false;
}


bool CDlgHelper::HandleDlgPaceTwoTimes(CDialog* pDlg, int nIDT1, int nIDT2, double dDistance, int nIDDest, int nFormat)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nIDDest, "");

    bool fOK;

    double dSeconds = CDlgHelper::ReadDlgTwoTimes(pDlg, nIDT1, nIDT2, fOK);
    double dMinutes = dSeconds / 60;
    if((CUtil::HasData(dSeconds)) && (0.0 != dDistance))
    {
        CString strText = CDlgHelper::FormatPace(dMinutes, dDistance, nFormat);
        pDlg->SetDlgItemText(nIDDest, strText);
        return true;
    }
    return false;
}


bool CDlgHelper::HandleDlgPaceFourTimes(CDialog* pDlg, int nIDT1, int nIDT2, int nIDT3, 
                                   int nIDT4, int nIDD1, int nIDD2, int nIDDest, int nFormat)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nIDDest, "");

    bool fOK;

    double dSeconds = CDlgHelper::ReadDlgFourTimes(pDlg, nIDT1, nIDT2, nIDT3, nIDT4, fOK);
    double dMinutes = dSeconds / 60;
    if(CUtil::HasData(dSeconds))
    {
        double dDistance = CDlgHelper::ReadDlgTwoDistances(pDlg, nIDD1, nIDD2, fOK);
        if((CUtil::HasData(dDistance)) && (0.0 != dDistance))
        {
            CString strText = CDlgHelper::FormatPace(dMinutes, dDistance, nFormat);
            pDlg->SetDlgItemText(nIDDest, strText);
            return true;
        }
    }
    return false;
}


bool CDlgHelper::HandleDlgPaceFourTimes(CDialog* pDlg, int nIDT1, int nIDT2, int nIDT3, int nIDT4,
                                   double dDistance, int nIDDest, int nFormat)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nIDDest, "");

    bool fOK;

    double dSeconds = CDlgHelper::ReadDlgFourTimes(pDlg, nIDT1, nIDT2, nIDT3, nIDT4, fOK);
    double dMinutes = dSeconds / 60;
    if((CUtil::HasData(dSeconds)) && (0.0 != dDistance))
    {
        CString strText = CDlgHelper::FormatPace(dMinutes, dDistance, nFormat);
        pDlg->SetDlgItemText(nIDDest, strText);
        return true;
    }
    return false;
}



bool CDlgHelper::HandleDlgPaceOneTime(CDialog* pDlg, double dSeconds, double dDist, int nIDDest, int nFormat)
{
    if(NULL == pDlg)
    {
        return false;
    }

    pDlg->SetDlgItemText(nIDDest, "");

    double dMinutes = dSeconds / 60;
	if((CUtil::HasData(dSeconds)) && (0.0 != dDist) && (CUtil::HasData(dDist)))
    {
        CString strText = CDlgHelper::FormatPace(dMinutes, dDist, nFormat);
        pDlg->SetDlgItemText(nIDDest, strText);
        return true;
    }
    return false;
}


CString CDlgHelper::FormatTimeNoDecimal(double dTime)
{
    CString strTime = CDlgHelper::FormatTime(dTime);

    int n = strTime.Find('.');
    if(n >= 0)
    {
        strTime = strTime.Left(n);
    }

    return strTime;
}


CString CDlgHelper::FormatTime(double dTime)
{
    CString str;
    CString strTemp;
    CString strResult;

    int nMinutes = (int)dTime;
    double dSecPace = 60 * (dTime - (double)nMinutes);
    int nSeconds = (int)dSecPace;

    strTemp.Format("%.2lf", dSecPace - nSeconds);
    if("0." == strTemp.Left(2))
    {
        strTemp = strTemp.Right(strTemp.GetLength() - 2);
    }
    else if("1." == strTemp.Left(2))
    {
        strTemp = strTemp.Right(strTemp.GetLength() - 2);
        if(nSeconds < 59)
        {
            nSeconds++;
        }
        else
        {
            nMinutes++;
            nSeconds = 0;
        }
    }
    str.Format("%d:%.2d.", nMinutes, nSeconds);
    strResult = str + strTemp;

    return strResult;
}


CString CDlgHelper::FormatPaceNoDecimal(double dPace, int nFormat)
{
    CString str = CDlgHelper::FormatPace(dPace, nFormat);
    int n = str.Find('.');
    
    if(n >= 0)
    {
        return str.Left(n);
    }
    else
    {
        return str;
    }
}


CString CDlgHelper::FormatPace(double dMinutes, double dDistance, int nFormat)
{
	if((0.0 == dDistance) || CUtil::HasNoData(dMinutes * 60.0) || CUtil::HasNoData(dDistance))
    {
        return NULL;
    }

    return CDlgHelper::FormatPace(dMinutes / dDistance, nFormat);
}


CString CDlgHelper::FormatPace(double dPace, int nFormat)
{
    CUser* pUser = g_pUser;
    if(NULL == pUser)
    {
        return NULL;
    }

    int nDistType;
    int nPaceType;
    switch(nFormat)
    {
    case FORMAT_RUN:
        {
            nDistType = pUser->GetRunDistUnits();
            nPaceType = pUser->GetPaceFormatRun();
            break;
        }

    case FORMAT_BIKE:
        {
            nDistType = pUser->GetBikeDistUnits();
            nPaceType = pUser->GetPaceFormatBike();
            break;
        }

    case FORMAT_SWIM:
        {
            nDistType = pUser->GetSwimDistUnits();
            nPaceType = pUser->GetPaceFormatSwim();
            break;
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CDlgHelper::FormatPace");
            break;
        }
    }

    return CDlgHelper::FormatPaceKnownPaceType(dPace, nPaceType, nDistType);
}


CString CDlgHelper::FormatPaceKnownPaceType(double dPace, int nPaceType, int nDistType)
{
    CString str;
    CString strTemp;
    CString strResult;

    if((PACEFORMAT_MINDIST == nPaceType) || (PACEFORMAT_MIN100M == nPaceType) || (PACEFORMAT_MIN100Y == nPaceType))
    {
        if(PACEFORMAT_MIN100M == nPaceType)
        {
            // translate whatever pace we got (either min/mile or min/km) into min/mile
            double dFactor = 1.0;
            CUtil::GetDistConversionFactor(nDistType, DISTUNITS_MI, dFactor);
            dPace /= dFactor;

            // we want min per 100m, not min per mile
            dPace /= MilesToMeters(1);
            dPace *= 100;
        }
        if(PACEFORMAT_MIN100Y == nPaceType)
        {
            // translate whatever pace we got (either min/mile or min/km) into min/mile
            double dFactor = 1.0;
            CUtil::GetDistConversionFactor(nDistType, DISTUNITS_MI, dFactor);
            dPace /= dFactor;

            // we want min per 100y, not min per mile
            dPace /= 17.6;
        }

        int nMinutes = (int)dPace;
        double dSecPace = 60 * (dPace - (double)nMinutes);
        int nSeconds = (int)dSecPace;

        strTemp.Format("%.2lf", dSecPace - nSeconds);
        if("0." == strTemp.Left(2))
        {
            strTemp = strTemp.Right(strTemp.GetLength() - 2);
        }
        else if("1." == strTemp.Left(2))
        {
            strTemp = strTemp.Right(strTemp.GetLength() - 2);
            if(nSeconds < 59)
            {
                nSeconds++;
            }
            else
            {
                nMinutes++;
                nSeconds = 0;
            }
        }
        str.Format("%d:%.2d.", nMinutes, nSeconds);
        strResult = str + strTemp;
    }

    else if(PACEFORMAT_DISTHR == nPaceType)
    {
        if(0.0 != dPace)
        {
            double dNewPace = 1 / dPace;
            dNewPace *= 60;
            strResult.Format("%.2lf", dNewPace);
        }
    }
       
    return strResult;
}


void CDlgHelper::ReadyComboBox(CComboBox* pBox, bool fRedoWidth)
{
    if(NULL == pBox)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::ReadyComboBox");
        return;
    }

    if(fRedoWidth)
    {
        CString str;
        CSize sz;
        int nWidth = pBox->GetDroppedWidth();
        TEXTMETRIC tm;
        CDC* pDC = pBox->GetDC();
        CFont* pFont = pBox->GetFont();

        CFont* pOldFont = pDC->SelectObject(pFont);
        pDC->GetTextMetrics(&tm);

        for (int i = 0; i < pBox->GetCount(); i++)
        {
            pBox->GetLBText(i, str);
            sz = pDC->GetTextExtent(str);

            // add the avg width to prevent clipping
            sz.cx += tm.tmAveCharWidth;
               
            if (sz.cx > nWidth)
            {
                nWidth = sz.cx;
            }
        }

        pDC->SelectObject(pOldFont);
        pBox->ReleaseDC(pDC);

        // adjust the width for the vertical scroll bar and the left and right border.
        nWidth += ::GetSystemMetrics(SM_CXVSCROLL) + 2 * ::GetSystemMetrics(SM_CXEDGE);

        pBox->SetDroppedWidth(nWidth);
    }

    pBox->SetExtendedUI();

    // set the dropdown size
	int nLines = min(max(pBox->GetCount(), 1), 15);  
	CRect rcDrop;
	pBox->GetWindowRect(&rcDrop);
    rcDrop.bottom += nLines * pBox->GetItemHeight(-1);
	pBox->SetWindowPos(NULL, 0, 0, rcDrop.Width(), rcDrop.Height(), SWP_NOMOVE | SWP_NOZORDER );
}


void CDlgHelper::OrderDateBox(CDialog* pDlg, int nID)
{
    if(NULL == pDlg)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::OrderDateBox");
        return;
    }

    CListBox* pDates = (CListBox*)pDlg->GetDlgItem(nID);
    if(NULL == pDates)
    {
        CUtil::Fatal("Could not get dates box in CDlgHelper::OrderDateBox");
        return;
    }

    int nNum = pDates->GetCount();

    // if it's 1 or less, it's already in some sort of order
    if(nNum <= 1)
    {
        return;
    }

    CStringList strlstData;
    COleDateTime* adtItems = new COleDateTime[nNum];
    int* anOrder = new int[nNum];
    if((NULL == adtItems) || (NULL == anOrder))
    {
        // ok to delete something that's NULL
        delete[] adtItems;
        delete[] anOrder;

        return;
    }

    for(int i = 0; i < nNum; i++)
    {
        CString strCur;
        pDates->GetText(i, strCur);
        strlstData.AddTail(strCur);

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

        adtItems[i].SetDateTime(nYear, nMonth, nDay, 1, 1, 1);
        adtItems[i].SetStatus(COleDateTime::valid);
    }

    CUtil::OrderArray(anOrder, adtItems, nNum, true);

    pDates->ResetContent();

    for(int i = 0; i < nNum; i++)
    {
        POSITION pos = strlstData.FindIndex(anOrder[i]);
        pDates->AddString(strlstData.GetAt(pos));
    }

    delete[] adtItems;
    delete[] anOrder;
}


bool CDlgHelper::HelpUpdateOKButton(CDialog* pDlg, int nID, int nWhichSport, int nField)
{
    bool bRet = true;
    if(CDlgHelper::IsUserFieldMandatory(nWhichSport, nField))
    {
        // call the one that checks, given that it's a mandatory field
        bRet = CDlgHelper::HelpUpdateOKButton(pDlg, nID);
    }

    return bRet;
}


bool CDlgHelper::HelpUpdateOKButton(CDialog* pDlg, int nID)
{
    if(NULL == pDlg)
    {
        CUtil::Fatal("Bad parameter to CDlgHelper::HelpUpdateOKButton");
        return true;
    }

    CString strText;
    pDlg->GetDlgItemText(nID, strText);
    return !strText.IsEmpty();
}


bool CDlgHelper::HelpUpdateOKButton(bool bIsValid, bool bIsEmpty, int nWhichSport, int nField)
{
	return CDlgHelper::HelpUpdateOKButton(bIsValid, bIsEmpty, CDlgHelper::IsUserFieldMandatory(nWhichSport, nField));
}


bool CDlgHelper::HelpUpdateOKButton(bool bIsValid, bool bIsEmpty, bool bFieldRequired /* = true */)
{
	bool bRet = true;

	if(true == bFieldRequired)
    {
        // if it's mandatory field, then we care whether the input is valid
        bRet = bIsValid;
    }
	else
	{
		// if it's not mandatory, it can be empty, but it cannot be non-empty and invalid
		if((false == bIsEmpty) && (false == bIsValid))
		{
			bRet = false;
		}
	}

    return bRet;
}