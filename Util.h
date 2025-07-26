#pragma once

#include "StdAfx.h"
#include "Math.h"
#include "RunningLog.h"
#include "RunningLogDoc.h"
#include "CalendarCtl.h"
#include "Util.h"
#include "BtnST.h"
#include "PRRunDlg.h"
#include "PRBikeDlg.h"
#include "PRSwimDlg.h"
#include "PRDuathlonDlg.h"
#include "PRTriathlonDlg.h"
#include "AboutDlg.h"
#include "DaySummarySheet.h"
#include "GoToDayDlg.h"
#include "DMFRunSummaryDlg.h"
#include "DMFBikeSummaryDlg.h"
#include "DMFSwimSummaryDlg.h"
#include "DMFStrengthSummaryDlg.h"
#include "DMFMultiSummaryDlg.h"
#include "ShoeSummaryRunDlg.h"
#include "ShoeSummaryBikeDlg.h"
#include "BikeSummaryDlg.h"
#include "TrackPRDlg.h"
#include "CurrentNotesDlg.h"
#include "UpcomingRaceDlg.h"
#include "UpcomingWorkoutDlg.h"
#include "PaceCalcDlg.h"
#include "HelpDlg.h"
#include "GetDatesDlg.h"
#include "AddUserDlg.h"
#include "AddCourseRunDlg.h"
#include "AddCourseBikeDlg.h"
#include "AddCourseSwimDlg.h"
#include "AddCourseDuathlonDlg.h"
#include "AddCourseTriathlonDlg.h"
#include "AddLocationRunDlg.h"
#include "AddLocationBikeDlg.h"
#include "AddLocationSwimDlg.h"
#include "AddLocationStrengthDlg.h"
#include "AddShoesRunDlg.h"
#include "AddShoesBikeDlg.h"
#include "AddBikeDlg.h"
#include "OpenUserDlg.h"
#include "OptionsDlg.h"
#include "WorkoutStartDlg.h"
#include "RunWorkoutEZDlg.h"
#include "RunWorkoutNormalDlg.h"
#include "RunWorkoutHardDlg.h"
#include "RunWorkoutTempoDlg.h"
#include "RunWorkoutIntervalDlg.h"
#include "RunWorkoutHillDlg.h"
#include "RunWorkoutTreadmillDlg.h"
#include "RunWorkoutPoolDlg.h"
#include "RunWorkoutMiscDlg.h"
#include "BikeWorkoutEZDlg.h"
#include "BikeWorkoutNormalDlg.h"
#include "BikeWorkoutHardDlg.h"
#include "BikeWorkoutIntervalDlg.h"
#include "BikeWorkoutHillDlg.h"
#include "BikeWorkoutTrainerDlg.h"
#include "BikeWorkoutMiscDlg.h"
#include "SwimWorkoutEZDlg.h"
#include "SwimWorkoutNormalDlg.h"
#include "SwimWorkoutHardDlg.h"
#include "SwimWorkoutIntervalDlg.h"
#include "SwimWorkoutOpenWaterDlg.h"
#include "SwimWorkoutDrillsDlg.h"
#include "SwimWorkoutMiscDlg.h"
#include "StrengthWorkoutAbsDlg.h"
#include "StrengthWorkoutWeightsDlg.h"
#include "StrengthWorkoutMiscDlg.h"
#include "RaceWorkoutRunDlg.h"
#include "RaceWorkoutBikeDlg.h"
#include "RaceWorkoutSwimDlg.h"
#include "RaceWorkoutDuathlonDlg.h"
#include "RaceWorkoutTriathlonDlg.h"
#include "RunEZWorkout.h"
#include "RunNormalWorkout.h"
#include "RunHardWorkout.h"
#include "RunTempoWorkout.h"
#include "RunIntervalWorkout.h"
#include "RunHillWorkout.h"
#include "RunTreadmillWorkout.h"
#include "RunPoolWorkout.h"
#include "RunMiscWorkout.h"
#include "BikeEZWorkout.h"
#include "BikeNormalWorkout.h"
#include "BikeHardWorkout.h"
#include "BikeIntervalWorkout.h"
#include "BikeHillWorkout.h"
#include "BikeTrainerWorkout.h"
#include "BikeMiscWorkout.h"
#include "SwimEZWorkout.h"
#include "SwimNormalWorkout.h"
#include "SwimHardWorkout.h"
#include "SwimIntervalWorkout.h"
#include "SwimOpenWaterWorkout.h"
#include "SwimDrillWorkout.h"
#include "SwimMiscWorkout.h"
#include "StrengthAbsWorkout.h"
#include "StrengthWeightsWorkout.h"
#include "StrengthMiscWorkout.h"
#include "RaceRunWorkout.h"
#include "RaceBikeWorkout.h"
#include "RaceSwimWorkout.h"
#include "RaceDuathlonWorkout.h"
#include "RaceTriathlonWorkout.h"
#include "Course.h"
#include "CourseRun.h"
#include "CourseBike.h"
#include "CourseSwim.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "Location.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "UpcomingRace.h"
#include "UpcomingWorkout.h"
#include "ConverterDlg.h"
#include "ExpandWnd.h"
#include "SplashScreenEx.h"
#include "RunningLogView.h"

class CUtil
{
protected:
    CUtil();
    
public:
    static CUser* GetUser(void);
    static int GetSplashSleep(void);
    static int GetAnimationSpeed(void);
    static bool DoAnimations(void);
    static int GetDayOfWeek(COleDateTime tmTime);
    static bool IsLeapYear(int nYear);
    static int GetNumWeeks(COleDateTime tmTime, int nStartDay);
    static int GetNumDaysInMonth(int nYear, int nMonth);
    static int GetNumDaysInYear(int nYear);
    static COleDateTime GetFirstVisibleDay(COleDateTime tmFirst, int nStartDay);
    static COleDateTime OffsetDay(COleDateTime tmDay, int n);
    static COleDateTime SubtractDay(COleDateTime tmDay);
    static COleDateTime AddDay(COleDateTime tmDay);
    static COleDateTime AddMonth(COleDateTime tmDay);
    static COleDateTime SubtractMonth(COleDateTime tmDay);
    static COleDateTime AddYear(COleDateTime tmDay);
    static COleDateTime SubtractYear(COleDateTime tmDay);
    static bool IsLaterThan(COleDateTime tmLater, COleDateTime tmBase);
    static bool IsLaterDayThan(COleDateTime tmLater, COleDateTime tmBase);
    static bool IsSameDay(COleDateTime tm1, COleDateTime tm2);
    static int GetNumberOfDaysLaterThan(COleDateTime tmLater, COleDateTime tmBase);
    static int PositiveModulo(int nNum, int nMod);
    static CString DayToString(int nDay);
    static CString MonthToString(int nMonth);
    static CString WorkoutToString(CWorkout* pWorkout);
    static CString RunWorkoutToString(int nWorkout);
    static CString BikeWorkoutToString(int nWorkout);
    static CString SwimWorkoutToString(int nWorkout);
    static CString StrengthWorkoutToString(int nWorkout);
    static CString RaceToString(int nWorkout);
    static CString ActivityToString(int nActivity);
	static CString GraphTypeToString(int nType);
	static CString RotationIncrementToString(int nNum);
    static CString DataTypeToString(int nType, bool fForTitle);
    static CString SearchTypeToString(int nType);
    static CString RelationTypeToString(int nType);
	static CString SearchForToString(int nType);
	static CString TwoDSeriesType2DToString(int nType);
	static CString TwoDSeriesType3DToString(int nType);
	static CString ThreeDSeriesTypeSurfaceToString(int nType);
	static CString ThreeDSeriesTypeBarToString(int nType);
	static CString ThreeDSeriesTypeScatterToString(int nType);
	static CString PolarSeriesTypePolarToString(int nType);
	static CString PolarSeriesTypeSmithToString(int nType);
	static CString PolarSeriesTypeRoseToString(int nType);
	static CString PieSeriesTypeToString(int nType);
	static CString PointSelectionTypeToString(int nType);
	static CString PointTypeToString(int nType);
	static CString LineTypeToString(int nType);
	static CString LegendLocationToString(int nLoc);
    static CString WindToString(int nWind);
    static CString ChoppinessToString(int nWind);
    static CString UnitsToString(int nUnits);
    static int NumRunWorkouts(void);
    static int NumBikeWorkouts(void);
    static int NumSwimWorkouts(void);
    static int NumStrengthWorkouts(void);
    static int NumRaces(void);
    static COleDateTime GetFirstOfMonth(COleDateTime tmTime);
    static COleDateTime GetLastOfMonth(COleDateTime tmTime);
    static bool IsHighlightDayADay(COleDateTime tmCur, int nDay, int nStartDay);
    static COleDateTime GetHighlightedDate(COleDateTime tmCur, int nDay, int nStartDay);
    static double GetDouble(int nWhole, CString strFrac);
    static CString TrimStringToFit(CDC* pDC, CString str, int nWidth);
    static bool IsDateValid(COleDateTime tm);
    static COLORREF GetRandomColor(void);
    static COLORREF GetRandomColor2(void);

	static COleDateTime ExtractDateFromDay(CString str);
	static COleDateTime ExtractDateFromMonth(CString str);

	static bool IsInRangeNear(double dValue, double dBase, double dRange = 1.0);
	static bool HasNoData(double dValue, bool bEnsureNonNegative = true);
	static bool HasData(double dValue, bool bEnsureNonNegative = true);

	static double ComputeRunCalories(double dWeight, double dDist);
	static double ComputeBikeCalories(double dWeight, double dDist, double dTime);
	static double ComputeSwimCalories(double dWeight, double dDist, double dTime);
	static double ComputeStrengthCalories(double dWeight, double dTime);

    static bool GetDistConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor);
    static bool GetHeightConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor);
    static bool GetWeightConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor);
    static double ConvertDistance(int nStartUnits, int nEndUnits, double dDist);
    static int ConvertHeight(int nStartUnits, int nEndUnits, int nHeight);
    static double ConvertWeight(int nStartUnits, int nEndUnits, double dWeight);
    static int ConvertTemperature(int nStartUnits, int nEndUnits, int nTemp);

    static void OrderArray(int* pnArray, COleDateTime* ptmArray, int nNum, bool bEarlyToLate = false);
    static void OptionallySetLatest(COleDateTime* ptmArray, COleDateTime tmCur, int nID, int nNum);

    static double DateTimeTo24Hours(COleDateTime tm);
    static COleDateTime Time24HoursToDateTime(double dTime);

    static double FigureOutNormalSpecial(double dNormal, double dSpecial, bool fNormal, bool fSpecial);

    static bool SaveXML(CUser* pUser, CString strForced = "");
    static bool ReadXML(CUser* pUser, CString strLocal);
    static void DeleteLocalFile(CString strLocal);

    static CString GetRunDistString(CString strDef = "Distance");
    static CString GetBikeDistString(CString strDef = "Distance");
    static CString GetSwimDistString(CString strDef = "Distance");
    static CString GetRunDistUnitString(bool bShort = false);
    static CString GetBikeDistUnitString(bool bShort = false);
    static CString GetSwimDistUnitString(bool bShort = false);
    static CString GetTemperatureString(bool bBare = false);
    static CString GetHeightString(bool bBare = false);
    static CString GetPWWeightString(CString strDef = "Post-workout weight");
	static CString GetPWWeightUnitString(bool bShort = false);
    static CString GetPaceString(int nFormat, CString strDef = "Pace", bool bBare = false);

    static int GetDefaultBaseTypeRun(void);    
    static int GetDefaultBaseTypeSwim(void);    
    static int GetDefaultBaseTypeBike(void);    
    static COLORREF GetDefaultBgColor(void);
    static COLORREF GetDefaultDayColor(int nType);
    static COLORREF GetDefaultButtonColor(void);
    static COLORREF GetDefaultHighlightColor(void);
    static COLORREF GetDefaultShadowColor(bool bOne);
    static COLORREF GetDefaultGradientColor(bool bBegin);
    static COLORREF GetDefaultHeadingTextColor(void);
    static COLORREF GetDefaultDayTextColor(void);
    static COLORREF GetDefaultAnnotationTextColor(void);
    static COLORREF GetDefaultRaceDayColor(void);
    static COLORREF GetDefaultUpcomingRaceDayColor(void);
    static COLORREF GetDefaultUpcomingWorkoutDayColor(void);
    static COLORREF GetDefaultEditBgColor(void);
    static bool GetDefaultDisplayInfo(int nActivity);
    static int GetDefaultPaceFormatRun(void);
    static int GetDefaultPaceFormatBike(void);
    static int GetDefaultPaceFormatSwim(void);
	static COLORREF GetDefaultMonthCtrlBgColor(void);
	static COLORREF GetDefaultMonthCtrlTextColor(void);
	static COLORREF GetDefaultMonthCtrlTitleTextColor(void);
	static COLORREF GetDefaultMonthCtrlTrailingTextColor(void);
	static COLORREF GetDefaultMonthCtrlHeadingColor(void);
	static int GetDefaultRunDecimals(void);
	static int GetDefaultBikeDecimals(void);
	static int GetDefaultSwimDecimals(void);

	static int GetDefaultDlgAnimationTime(void);

    static CString GetExeDirectory(void);
    static CString GetFileExtension(void);

    static void Fatal(CString str);
};