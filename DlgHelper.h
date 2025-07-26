#pragma once

#include "StdAfx.h"
#include "RunningLog.h"

class CDlgHelper
{
public:
    static void FillComboBox(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fRedoWidth, bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField);
    static void FillComboBox(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fRedoWidth, bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField);
    static void FillComboBox(CComboBox* pBox, COURSERUNARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, COURSESWIMARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, bool fRedoWidth, bool fAddBlankIfNeeded);
    static void FillComboBox(CComboBox* pBox, BIKEARRAY& rarBikes, bool fRedoWidth, bool fKeepRetired, bool fAddBlankIfNeeded, int nWhichSport, int nField);
    
    static void FillComboBoxMonths(CComboBox* pBox, bool fRedoWidth);
    static void FillComboBoxDays(CComboBox* pDayBox, CComboBox* pMonthBox, int nYear);
    static void FillComboBoxWind(CComboBox* pBox, bool fRedoWidth);
    static void FillComboBoxDaysOfWeek(CComboBox* pBox, bool fRedoWidth);
    static void FillComboBoxChoppiness(CComboBox* pBox, bool fRedoWidth);

    static bool OptionallyAddEmptySpace(CComboBox* pBox, bool bAddBlankIfNeeded, int nWhichSport, int nField);
    static bool IsUserFieldMandatory(int nWhichSport, int nField);

    static double ReadDlgTwoDistances(CDialog* pDlg, int nID1, int nID2, bool& rfOK);
    static double ReadDlgTwoTimes(CDialog* pDlg, int nID1, int nID2, bool& rfOK);
    static double ReadDlgTimeSleep(CDialog* pDlg, int nID1, int nID2, bool& rfOK);
    static COleDateTime ReadDlgTimeSpinner(CDialog* pDlg, int nID1, int nID2, int nID3, COleDateTime tmDay, bool& rfOK);
    static double ReadDlgFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, bool& rfOK);
    static int ReadDlgOneInt(CDialog* pDlg, int nID1, bool& rfOK);
    static CString ReadDlgOneString(CDialog* pDlg, int nID1, bool& rfOK);

    static void SetDlgTwoDistances(CDialog* pDlg, int nID1, int nID2, double dDist);
    static void SetDlgTwoTimes(CDialog* pDlg, int nID1, int nID2, double dSec);
    static void SetDlgThreeTimes(CDialog* pDlg, int nID1, int nID2, int nID3, double dSec);
    static void SetDlgFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, double dSec);
	static void SetDlgOneTime(CDialog* pDlg, int nID, double dSec);
    static void SetDlgOneInt(CDialog* pDlg, int nID1, int nVal);
    static void SetDlgOneIntTwoDigits(CDialog* pDlg, int nID1, int nVal);
    static void SetDlgTimeSpinner(CDialog* pDlg, int nID1, int nID2, int nID3, COleDateTime tm);
    static void SetDlgTimeSleep(CDialog* pDlg, int nID1, int nID2, double dSleep);
    static void SetDlgOneString(CDialog* pDlg, int nID1, CString str);

	static void SetDlgTimeStart(CDialog* pDlg, int nID, COleDateTime tm);
	static void SetDlgDouble(CDialog* pDlg, int nID, double dVal, int nDecimals);
	static void SetDlgTimeSleep(CDialog* pDlg, int nID, double dSleep);

    static CShoesBike* GetComboSel(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fKeepRetired, bool& rfOK);
    static CShoesRun* GetComboSel(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fKeepRetired, bool& rfOK);
    static CCourseRun* GetComboSel(CComboBox* pBox, COURSERUNARRAY& rarCourses, bool& rfOK);
    static CCourseBike* GetComboSel(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, bool& rfOK);
    static CCourseSwim* GetComboSel(CComboBox* pBox, COURSESWIMARRAY& rarCourses, bool& rfOK);
    static CCourseDuathlon* GetComboSel(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, bool& rfOK);
    static CCourseTriathlon* GetComboSel(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, bool& rfOK);
    static CLocationRun* GetComboSel(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, bool& rfOK);
    static CLocationBike* GetComboSel(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, bool& rfOK);
    static CLocationSwim* GetComboSel(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, bool& rfOK);
    static CLocationStrength* GetComboSel(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, bool& rfOK);
    static CBike* GetComboSel(CComboBox* pBox, BIKEARRAY& rarBikes, bool fKeepRetired, bool& rfOK);
	static int GetComboSel(CComboBox* pBox, bool fNoSelIsOK = false);

    static int GetComboSelWind(CComboBox* pBox, bool& rfOK);
    static int GetComboSelChoppiness(CComboBox* pBox, bool& rfOK);
    static int GetComboSelDayOfWeek(CComboBox* pBox, bool& rfOK);

    static void SetComboSel(CComboBox* pBox, SHOESBIKEARRAY& rarShoes, bool fKeepRetired, CShoesBike* pShoes);
    static void SetComboSel(CComboBox* pBox, SHOESRUNARRAY& rarShoes, bool fKeepRetired, CShoesRun* pShoes);
    static void SetComboSel(CComboBox* pBox, COURSERUNARRAY& rarCourses, CCourseRun* pCourse);
    static void SetComboSel(CComboBox* pBox, COURSEBIKEARRAY& rarCourses, CCourseBike* pCourse);
    static void SetComboSel(CComboBox* pBox, COURSESWIMARRAY& rarCourses, CCourseSwim* pCourse);
    static void SetComboSel(CComboBox* pBox, COURSEDUATHLONARRAY& rarCourses, CCourseDuathlon* pCourse);
    static void SetComboSel(CComboBox* pBox, COURSETRIATHLONARRAY& rarCourses, CCourseTriathlon* pCourse);
    static void SetComboSel(CComboBox* pBox, LOCATIONRUNARRAY& rarLocations, CLocationRun* pLocation);
    static void SetComboSel(CComboBox* pBox, LOCATIONBIKEARRAY& rarLocations, CLocationBike* pLocation);
    static void SetComboSel(CComboBox* pBox, LOCATIONSWIMARRAY& rarLocations, CLocationSwim* pLocation);
    static void SetComboSel(CComboBox* pBox, LOCATIONSTRENGTHARRAY& rarLocations, CLocationStrength* pLocation);
    static void SetComboSel(CComboBox* pBox, BIKEARRAY& rarBikes, bool fKeepRetired, CBike* pBike);

    static void SetComboSelWind(CComboBox* pBox, int nWind);
    static void SetComboSelChoppiness(CComboBox* pBox, int nChoppiness);

	static bool HandleDlgPROneTime(CDialog* pDlg, double dSec, int nID);
    static bool HandleDlgPRTwoTimes(CDialog* pDlg, double dSec, int nID1, int nID2);
    static bool HandleDlgPRFourTimes(CDialog* pDlg, double dSec, int nID1, int nID2, int nID3, int nID4);

    static bool HandleDlgPaceTwoTimes(CDialog* pDlg, int nID1, int nID2, int nIDD1, int nIDD2, int nIDDest, int nFormat);
    static bool HandleDlgPaceTwoTimes(CDialog* pDlg, int nID1, int nID2, double dDistance, int nIDDest, int nFormat);
    static bool HandleDlgPaceFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, int nIDD1, int nIDD2, int nIDDest, int nFormat);
    static bool HandleDlgPaceFourTimes(CDialog* pDlg, int nID1, int nID2, int nID3, int nID4, double dDistance, int nIDDest, int nFormat);
    static bool HandleDlgPaceOneTime(CDialog* pDlg, double dSeconds, double dDist, int nIDDest, int nFormat);

    static CString FormatTimeNoDecimal(double dTime);
    static CString FormatTime(double dTime);
    static CString FormatPaceNoDecimal(double dPace, int nFormat);
    static CString FormatPace(double dPace, int nFormat);
    static CString FormatPace(double dMinutes, double dDistance, int nFormat);
    static CString FormatPaceKnownPaceType(double dPaceMinMile, int nPaceType, int nDistType);

    static void ReadyComboBox(CComboBox* pBox, bool fRedoWidth);

    static void OrderDateBox(CDialog* pDlg, int nID);

    static bool HelpUpdateOKButton(CDialog* pDlg, int nID, int nWhichSport, int nField);
    static bool HelpUpdateOKButton(CDialog* pDlg, int nID);
	static bool HelpUpdateOKButton(bool bIsValid, bool bIsEmpty, int nWhichSport, int nField);
	static bool HelpUpdateOKButton(bool bIsValid, bool bIsEmpty, bool bFieldRequired = true);
};
