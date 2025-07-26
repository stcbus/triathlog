#pragma once

#include <afxtempl.h>
#include "CourseRun.h"
#include "CourseSwim.h"
#include "CourseBike.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "ShoesRun.h"
#include "ShoesBike.h"
#include "Workout.h"
#include "DayLog.h"
#include "Bike.h"
#include "Injury.h"

class CUser
{
public:
    CUser();
    ~CUser();

    void ResetDefaults(void);
    void AddCourseRun(CCourseRun* pCourse);
    void AddCourseSwim(CCourseSwim* pCourse);
    void AddCourseBike(CCourseBike* pCourse);
    void AddCourseDuathlon(CCourseDuathlon* pCourse);
    void AddCourseTriathlon(CCourseTriathlon* pCourse);
    void AddLocationRun(CLocationRun* pLocation);
    void AddLocationSwim(CLocationSwim* pLocation);
    void AddLocationBike(CLocationBike* pLocation);
    void AddLocationStrength(CLocationStrength* pLocation);
    void AddShoesRun(CShoesRun* pShoes);    
    void AddShoesBike(CShoesBike* pShoes);
    void AddBike(CBike* pBike);
    void AddInjury(CInjury* pInjury);
    void AddUpcomingRace(CUpcomingRace* pRace);
    CUpcomingRace* GetUpcomingRaceAt(COleDateTime tmDay);
    void AddUpcomingWorkout(CUpcomingWorkout* pWorkout);
    CUpcomingWorkout* GetUpcomingWorkoutAt(COleDateTime tmDay);
    CDayLog* GetDayAt(COleDateTime tmDay);
    CDayLog* GetDayAtCreate(COleDateTime tmDay);
    void SetDayAt(COleDateTime tm, CDayLog* pDay);

    int GetIDFromCourseRun(CCourseRun* pCourse);
    int GetIDFromCourseBike(CCourseBike* pCourse);
    int GetIDFromCourseSwim(CCourseSwim* pCourse);
    int GetIDFromCourseDuathlon(CCourseDuathlon* pCourse);
    int GetIDFromCourseTriathlon(CCourseTriathlon* pCourse);
    int GetIDFromLocationRun(CLocationRun* pLocation);
    int GetIDFromLocationBike(CLocationBike* pLocation);
    int GetIDFromLocationSwim(CLocationSwim* pLocation);
    int GetIDFromLocationStrength(CLocationStrength* pLocation);
    int GetIDFromShoesRun(CShoesRun* pShoes);
    int GetIDFromShoesBike(CShoesBike* pShoes);
    int GetIDFromBike(CBike* pBike);

    CCourseRun* GetCourseRunFromID(int nID);
    CCourseBike* GetCourseBikeFromID(int nID);
    CCourseSwim* GetCourseSwimFromID(int nID);
    CCourseDuathlon* GetCourseDuathlonFromID(int nID);
    CCourseTriathlon* GetCourseTriathlonFromID(int nID);
    CLocationRun* GetLocationRunFromID(int nID);
    CLocationBike* GetLocationBikeFromID(int nID);
    CLocationSwim* GetLocationSwimFromID(int nID);
    CLocationStrength* GetLocationStrengthFromID(int nID);
    CShoesRun* GetShoesRunFromID(int nID);
    CShoesBike* GetShoesBikeFromID(int nID);
    CBike* GetBikeFromID(int nID);

    COleDateTime GetEarliestDay(void);
    COleDateTime GetLatestDay(void);

    int GetCompleteRestDays(COleDateTime tmStart, int nDays);
    int GetNoRunningDays(COleDateTime tmStart, int nDays);
    int GetNoBikingDays(COleDateTime tmStart, int nDays);
    int GetNoSwimmingDays(COleDateTime tmStart, int nDays);
    int GetNoStrengthDays(COleDateTime tmStart, int nDays);

    bool IsRunFieldMandatory(int nField) const;
    void SetRunFieldMandatory(int nField, bool bMandatory);
    bool IsBikeFieldMandatory(int nField) const;
    void SetBikeFieldMandatory(int nField, bool bMandatory);
    bool IsSwimFieldMandatory(int nField) const;
    void SetSwimFieldMandatory(int nField, bool bMandatory);
    bool IsStrengthFieldMandatory(int nField) const;
    void SetStrengthFieldMandatory(int nField, bool bMandatory);
    bool IsRaceRunFieldMandatory(int nField) const;
    void SetRaceRunFieldMandatory(int nField, bool bMandatory);
    bool IsRaceBikeFieldMandatory(int nField) const;
    void SetRaceBikeFieldMandatory(int nField, bool bMandatory);
    bool IsRaceSwimFieldMandatory(int nField) const;
    void SetRaceSwimFieldMandatory(int nField, bool bMandatory);
    bool IsRaceDuathlonFieldMandatory(int nField) const;
    void SetRaceDuathlonFieldMandatory(int nField, bool bMandatory);
    bool IsRaceTriathlonFieldMandatory(int nField) const;
    void SetRaceTriathlonFieldMandatory(int nField, bool bMandatory);
    bool IsStartFieldMandatory(int nField) const;
    void SetStartFieldMandatory(int nField, bool bMandatory);

    unsigned __int64 GetMandatoryRunFields(void) const;
    void SetMandatoryRunFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryBikeFields(void) const;
    void SetMandatoryBikeFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatorySwimFields(void) const;
    void SetMandatorySwimFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryStrengthFields(void) const;
    void SetMandatoryStrengthFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryRaceRunFields(void) const;
    void SetMandatoryRaceRunFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryRaceBikeFields(void) const;
    void SetMandatoryRaceBikeFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryRaceSwimFields(void) const;
    void SetMandatoryRaceSwimFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryRaceDuathlonFields(void) const;
    void SetMandatoryRaceDuathlonFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryRaceTriathlonFields(void) const;
    void SetMandatoryRaceTriathlonFields(unsigned __int64 i64Fields);
    unsigned __int64 GetMandatoryStartFields(void) const;
    void SetMandatoryStartFields(unsigned __int64 i64Fields);

    int GetRunDistUnits(void) const;
    void SetRunDistUnits(int nUnits);
    int GetBikeDistUnits(void) const;
    void SetBikeDistUnits(int nUnits);
    int GetSwimDistUnits(void) const;
    void SetSwimDistUnits(int nUnits);
    int GetHeightUnits(void) const;
    void SetHeightUnits(int nUnits);
    int GetWeightUnits(void) const;
    void SetWeightUnits(int nUnits);
    int GetTempUnits(void) const;
    void SetTempUnits(int nUnits);

	int GetDlgAnimationTime(void) const;

    int SumTotalWorkouts(COleDateTime tmStart, int nDays);
    int SumWorkoutsRun(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    int SumWorkoutsRun(CShoesRun* pShoes);    
    int SumWorkoutsBike(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    int SumWorkoutsBike(CShoesBike* pShoes);
    int SumWorkoutsBike(CBike* pBike);
    int SumWorkoutsSwim(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    int SumWorkoutsStrength(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
	int SumWorkoutsRace(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);

    double SumMilesRun(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumMilesRun(CShoesRun* pShoes);
    double SumMilesBike(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumMilesBike(CShoesBike* pShoes);
    double SumMilesBike(CBike* pBike);
    double SumMilesSwim(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);

    double SumSecondsRun(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumSecondsRun(CShoesRun* pShoes);
    double SumSecondsBike(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumSecondsBike(CShoesBike* pShoes);
    double SumSecondsBike(CBike* pBike);
    double SumSecondsSwim(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumSecondsStrength(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);

    double SumMinutesRun(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumMinutesRun(CShoesRun* pShoes);
    double SumMinutesBike(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumMinutesBike(CShoesBike* pShoes);
    double SumMinutesBike(CBike* pBike);
    double SumMinutesSwim(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);
    double SumMinutesStrength(COleDateTime tmStart, int nDays, int nActivity = -1, int nType = -1);

    double SumRunSecondsWithMiles(COleDateTime tmStart, int nDays);
    double SumBikeSecondsWithMiles(COleDateTime tmStart, int nDays);
    double SumSwimSecondsWithMiles(COleDateTime tmStart, int nDays);

    int GetAverageTemperature(COleDateTime tmStart, int nDays);
    int GetAverageHR(COleDateTime tmStart, int nDays);
    double GetAverageRunPace(COleDateTime tmStart, int nDays);
    double GetAverageSwimPace(COleDateTime tmStart, int nDays);
    double GetAverageBikePace(COleDateTime tmStart, int nDays);
    double GetPaceWithFormat(double dSeconds, double dDist, int nFmt, int nUnits);
    double GetAverageSleep(COleDateTime tmStart, int nDays);
    double GetAverageWeight(COleDateTime tmStart, int nDays);
	double GetAverageCalories(COleDateTime tmStart, int nDays);
	double GetAveragePoints(COleDateTime tmStart, int nDays);
    double GetAverageTimeOfDay(COleDateTime tmStart, int nDays);

    void GetTimeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                      int nPoints, int nIncr, int nNullValue);
    void GetMinutesRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue);
    void GetMinutesBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue);
    void GetMinutesSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue);
    void GetMinutesStrengthArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                 int nPoints, int nIncr, int nNullValue);
    void GetMinutesOverallArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                int nPoints, int nIncr, int nNullValue);
    void GetMilesRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                          int nPoints, int nIncr, int nNullValue);
    void GetMilesBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                           int nPoints, int nIncr, int nNullValue);
    void GetMilesSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                           int nPoints, int nIncr, int nNullValue);
    void GetTemperatureArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue);
    void GetHRArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                    int nPoints, int nIncr, int nNullValue);
    void GetPaceRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                         int nPoints, int nIncr, int nNullValue);
    void GetPaceBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                          int nPoints, int nIncr, int nNullValue);
    void GetPaceSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                          int nPoints, int nIncr, int nNullValue);
    void GetSleepArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                       int nPoints, int nIncr, int nNullValue);
    void GetWeightArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                        int nPoints, int nIncr, int nNullValue);
    void GetWorkoutRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue);
    void GetWorkoutBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue);
    void GetWorkoutSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue);
    void GetWorkoutStrengthArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                 int nPoints, int nIncr, int nNullValue);
    void GetWorkoutOverallArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                int nPoints, int nIncr, int nNullValue);
    void GetTimeOfDayArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                           int nPoints, int nIncr, int nNullValue);
    void GetPointsArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                        int nPoints, int nIncr, int nNullValue);
	void GetCalorieArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                         int nPoints, int nIncr, int nNullValue);

    int HashDay(COleDateTime tm);
    const CMap<int, int, int, int>& GetHashMap(void) const;
    void SetHashMap(CMap<int, int, int, int>& rmapHash);

    void ReorderData(void);
    void RecalcPRs(CCourseRun* pCourse);
    void RecalcPRs(CCourseBike* pCourse);
    void RecalcPRs(CCourseSwim* pCourse);
    void RecalcPRs(CCourseDuathlon* pCourse);
    void RecalcPRs(CCourseTriathlon* pCourse);

    void AdjustUnits(int nDistRunUnitsOld, int nDistBikeUnitsOld, int nDistSwimUnitsOld,
                     int nHeightUnitsOld, int nWeightUnitsOld, int nTempUnitsOld);

    DAYARRAY& GetRefDayArray(void);
    COURSERUNARRAY& GetRefCourseRunArray(void);
    COURSEBIKEARRAY& GetRefCourseBikeArray(void);
    COURSESWIMARRAY& GetRefCourseSwimArray(void);
    COURSEDUATHLONARRAY& GetRefCourseDuathlonArray(void);
    COURSETRIATHLONARRAY& GetRefCourseTriathlonArray(void);
    LOCATIONRUNARRAY& GetRefLocationRunArray(void);
    LOCATIONBIKEARRAY& GetRefLocationBikeArray(void);
    LOCATIONSWIMARRAY& GetRefLocationSwimArray(void);
    LOCATIONSTRENGTHARRAY& GetRefLocationStrengthArray(void);
    SHOESRUNARRAY& GetRefShoesRunArray(void);
    SHOESBIKEARRAY& GetRefShoesBikeArray(void);
    BIKEARRAY& GetRefBikeArray(void);
    UPCOMINGRACEARRAY& GetRefUpcomingRaceArray(void);
    UPCOMINGWORKOUTARRAY& GetRefUpcomingWorkoutArray(void);
	INJURYARRAY& GetRefInjuryArray(void);

    CString GetFirstName(void) const;
    CString GetLastName(void) const;
    int GetSex(void) const;
    int GetHeight(void) const;
    int GetRestingHR(void) const;
    CString GetNotes(void) const;
    int GetBaseTypeRun(void) const;
    int GetBaseTypeBike(void) const;
    int GetBaseTypeSwim(void) const;
    int GetFirstDayOfWeek(void) const;
	int GetLastDayOfWeek(void) const;
    bool DisplayInfoRun(void) const;
    bool DisplayInfoBike(void) const;
    bool DisplayInfoSwim(void) const;
    bool DisplayInfoStrength(void) const;
    bool DisplayInfoRace(void) const;
    int GetPaceFormatRun(void) const;
    int GetPaceFormatBike(void) const;
    int GetPaceFormatSwim(void) const;
    COleDateTime GetCurrentDate(void) const;
    int GetHighlightDay(void) const;
    COLORREF GetBgColor(void) const;
    COLORREF GetDayColor(int nType) const;
    COLORREF GetButtonColor(void) const;
    COLORREF GetHighlightColor(void) const;
    COLORREF GetShadowColor(bool bOne) const;
    COLORREF GetGradientColor(bool bBegin) const;
    COLORREF GetHeadingTextColor(void) const;
    COLORREF GetDayTextColor(void) const;
    COLORREF GetAnnotationTextColor(void) const;
	COLORREF GetRaceDayColor(void) const;
	COLORREF GetUpcomingRaceDayColor(void) const;
	COLORREF GetUpcomingWorkoutDayColor(void) const;
	COLORREF GetEditBgColor(void) const;
    CFont* GetDayFont(void) const;
    CFont* GetHeadingFont(void) const;
    CFont* GetTitleFont(void) const;
    CFont* GetAnnotationFont(void) const;
    CFont* GetAnnotationFontBold(void) const;
	int GetRunDecimals(void) const;
	int GetBikeDecimals(void) const;
	int GetSwimDecimals(void) const;

    void SetFirstName(CString str);
    void SetLastName(CString str);
    void SetSex(int nSex);
    void SetHeight(int nHeight);
    void SetRestingHR(int nHR);
    void SetNotes(CString str);
    void SetBaseTypeRun(int nType);
    void SetBaseTypeBike(int nType);
    void SetBaseTypeSwim(int nType);
    void SetFirstDayOfWeek(int nDay);
    void SetDisplayInfoRun(bool fDisp);
    void SetDisplayInfoBike(bool fDisp);
    void SetDisplayInfoSwim(bool fDisp);
    void SetDisplayInfoStrength(bool fDisp);
    void SetDisplayInfoRace(bool fDisp);
    void SetPaceFormatRun(int nType);
    void SetPaceFormatBike(int nType);
    void SetPaceFormatSwim(int nType);
    void SetCurrentDate(COleDateTime tmCur);
    void SetHighlightDay(int nDay);
    void SetBgColor(COLORREF cr);
    void SetDayColor(int nType, COLORREF cr);
    void SetButtonColor(COLORREF cr);
    void SetHighlightColor(COLORREF cr);
    void SetShadowColor(bool bOne, COLORREF cr);
    void SetGradientColor(bool bBegin, COLORREF cr);
	void SetRaceDayColor(COLORREF cr);
	void SetUpcomingRaceDayColor(COLORREF cr);
	void SetUpcomingWorkoutDayColor(COLORREF cr);
    void SetHeadingTextColor(COLORREF cr);
    void SetDayTextColor(COLORREF cr);
    void SetAnnotationTextColor(COLORREF cr);
	void SetEditBgColor(COLORREF cr);
    void SetDayFont(CFont* pfnt);
    void SetHeadingFont(CFont* pfnt);
    void SetTitleFont(CFont* pfnt); 
    void SetAnnotationFont(CFont* pfnt);
    void SetAnnotationFontBold(CFont* pfnt);
	void SetDlgAnimationTime(int nTime);
	void SetRunDecimals(int nNum);
	void SetBikeDecimals(int nNum);
	void SetSwimDecimals(int nNum);

protected:
    // data
    CString m_strFirstName;
    CString m_strLastName;
    int m_nSex;
    int m_nHeight;
    int m_nBaseTypeRun;
    int m_nBaseTypeBike;
    int m_nBaseTypeSwim;
    int m_nStartDay;
    int m_nRestHR;
    bool m_fDispInfoRun;
    bool m_fDispInfoBike;
    bool m_fDispInfoSwim;
    bool m_fDispInfoStrength;
    bool m_fDispInfoRace;
    CString m_strNotes;

    int m_nRunDistUnits;
    int m_nBikeDistUnits;
    int m_nSwimDistUnits;
    int m_nHeightUnits;
    int m_nWeightUnits;
    int m_nTempUnits;

    int m_nPaceFormatRun;
    int m_nPaceFormatBike;
    int m_nPaceFormatSwim;

	int m_nDlgAnimationTime;

	int m_nRunDecimals;
	int m_nBikeDecimals;
	int m_nSwimDecimals;

    unsigned __int64 m_i64RunMand;
    unsigned __int64 m_i64BikeMand;
    unsigned __int64 m_i64SwimMand;
    unsigned __int64 m_i64StrMand;
    unsigned __int64 m_i64RaceRunMand;
    unsigned __int64 m_i64RaceBikeMand;
    unsigned __int64 m_i64RaceSwimMand;
    unsigned __int64 m_i64RaceDuathlonMand;
    unsigned __int64 m_i64RaceTriathlonMand;
    unsigned __int64 m_i64StartMand;

    CFont* m_pfntTitle;
    CFont* m_pfntDay;
    CFont* m_pfntHeading;
    CFont* m_pfntAnnotation;
	CFont* m_pfntAnnotationBold;
    COLORREF m_crBg;
    COLORREF m_crButton;
    COLORREF m_acrDay[4];
    COLORREF m_acrShadow[2];
    COLORREF m_crHeadingText;
    COLORREF m_crDayText;
    COLORREF m_crAnnotation;
    COLORREF m_crHighlight;
    COLORREF m_acrGrad[2];
	COLORREF m_crRaceDay;
	COLORREF m_crUpcomingRaceDay;
	COLORREF m_crUpcomingWorkoutDay;
	COLORREF m_crEditBg;
    COleDateTime m_tmCur;
    int m_nDayHilight;

    DAYARRAY m_arDays;
    COURSERUNARRAY m_arCoursesRun;
    COURSEBIKEARRAY m_arCoursesBike;
    COURSESWIMARRAY m_arCoursesSwim;
    COURSEDUATHLONARRAY m_arCoursesDuathlon;
    COURSETRIATHLONARRAY m_arCoursesTriathlon;
    LOCATIONRUNARRAY m_arLocationsRun;
    LOCATIONBIKEARRAY m_arLocationsBike;
    LOCATIONSWIMARRAY m_arLocationsSwim;
    LOCATIONSTRENGTHARRAY m_arLocationsStrength;
    SHOESRUNARRAY m_arShoesRun;
    SHOESBIKEARRAY m_arShoesBike;
    BIKEARRAY m_arBikes;
    UPCOMINGRACEARRAY m_arRaces;
	UPCOMINGWORKOUTARRAY m_arWorkouts;
	INJURYARRAY m_arInjuries;

    CMap<int, int, int, int> m_mapHash;
};
