#pragma once

#include "StdAfx.h"
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
#include "BikeWorkoutMountainBikeDlg.h"
#include "BikeWorkoutTimeTrialDlg.h"
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
#include "BikeMountainBikeWorkout.h"
#include "BikeTimeTrialWorkout.h"
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
#include "Injury.h"
#include "RunningLogView.h"
#include "SkinProgress.h"

class CXMLSerializer
{
public:
    CXMLSerializer(void);
    ~CXMLSerializer();

    bool WriteFile(CUser* pUser, CString strFile);
    bool ReadFile(CUser* pUser, CString strFile);

protected:
    CString EncryptXML(CString str);
    CString DecryptXML(CString str);

    CString MakeXML(CString strTag, int nTabs, CString strAttrib, int nVal, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, CString strAttrib, unsigned __int64 i64Val, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, CString strAttrib, double dVal, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, CString strAttrib, CString strVal, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, CString strAttrib1, double dVal, CString strAttrib2, int nVal, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, CString strAttrib1, int nVal, CString strAttrib2, int nVal2, bool bDone = true);
    CString MakeXML(CString strTag, int nTabs, COleDateTime tmVal);
    CString MakeXML(CString strTag, int nTabs, bool bBegin);
    CString MakeXML(int nTabs, CCourseRun* pCourse, int nID);
    CString MakeXML(int nTabs, CCourseBike* pCourse, int nID);
    CString MakeXML(int nTabs, CCourseSwim* pCourse, int nID);
    CString MakeXML(int nTabs, CCourseDuathlon* pCourse, int nID);
    CString MakeXML(int nTabs, CCourseTriathlon* pCourse, int nID);
    CString MakeXML(int nTabs, CLocationRun* pLocation, int nID);
    CString MakeXML(int nTabs, CLocationBike* pLocation, int nID);
    CString MakeXML(int nTabs, CLocationSwim* pLocation, int nID);
    CString MakeXML(int nTabs, CLocationStrength* pLocation, int nID);
    CString MakeXML(int nTabs, CShoesRun* pShoes, int nID);
    CString MakeXML(int nTabs, CShoesBike* pShoes, int nID);
    CString MakeXML(int nTabs, CBike* pBike, int nID);
    CString MakeXML(int nTabs, CDayLog* pDay, CUser* pUser);
    CString MakeXML(int nTabs, CWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunEZWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunHardWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunHillWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunIntervalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunMiscWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunNormalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunPoolWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunTempoWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRunTreadmillWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeEZWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeHardWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeHillWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeIntervalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeMiscWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeNormalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeTrainerWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeMountainBikeWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CBikeTimeTrialWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimDrillWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimEZWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimHardWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimIntervalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimMiscWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimNormalWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CSwimOpenWaterWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CStrengthAbsWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CStrengthMiscWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CStrengthWeightsWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRaceRunWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRaceBikeWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRaceSwimWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRaceDuathlonWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, CRaceTriathlonWorkout* pWorkout, CUser* pUser);
    CString MakeXML(int nTabs, const CMap<int, int, int, int>& rmapHash);
    CString MakeXML(int nTabs, CUpcomingRace* pRace);
    CString MakeXML(int nTabs, CUpcomingWorkout* pWorkout);
    CString MakeXML(int nTabs, CInjury* pInjury);

    CString PrependXML(CString strTag, int nTabs, CString strAttrib);
    CString PostpendXML(bool bDone);

    CString ReadSingleLine(FILE* fp);

    bool ParseXML(CString str, int& rnVal);
    bool ParseXML(CString str, unsigned __int64& ri64Val);
    bool ParseXML(CString str, bool& rfVal);
    bool ParseXML(CString str, int& rnVal1, int& rnVal2);
    bool ParseXML(CString str, double& rdVal);
    bool ParseXML(CString str, COleDateTime& rtmVal);
    bool ParseXML(CString str, CString& rstrVal);
    bool ReadHashMap(CUser* pUser, FILE* fp);
    bool ReadUpcomingRaces(CUser* pUser, FILE* fp, double dVersion);
    bool ReadUpcomingWorkouts(CUser* pUser, FILE* fp);
    bool ReadInjuries(CUser* pUser, FILE* fp);
    bool ReadCoursesRun(CUser* pUser, FILE* fp);
    bool ReadCoursesBike(CUser* pUser, FILE* fp);
    bool ReadCoursesSwim(CUser* pUser, FILE* fp);
    bool ReadCoursesDuathlon(CUser* pUser, FILE* fp);
    bool ReadCoursesTriathlon(CUser* pUser, FILE* fp);
    bool ReadLocationsRun(CUser* pUser, FILE* fp);
    bool ReadLocationsBike(CUser* pUser, FILE* fp);
    bool ReadLocationsSwim(CUser* pUser, FILE* fp);
    bool ReadLocationsStrength(CUser* pUser, FILE* fp);
    bool ReadShoesRun(CUser* pUser, FILE* fp);
    bool ReadShoesBike(CUser* pUser, FILE* fp);
    bool ReadBikes(CUser* pUser, FILE* fp);
    bool ReadDays(CUser* pUser, FILE* fp);
    bool ReadWorkouts(CUser* pUser, CDayLog* pDay, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunEZWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunHardWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunHillWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunIntervalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunMiscWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunNormalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunPoolWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunTempoWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRunTreadmillWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeEZWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeHardWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeHillWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeIntervalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeMiscWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeNormalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeTrainerWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeMountainBikeWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CBikeTimeTrialWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimDrillWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimEZWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimHardWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimIntervalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimMiscWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimNormalWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CSwimOpenWaterWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CStrengthAbsWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CStrengthMiscWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CStrengthWeightsWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRaceRunWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRaceBikeWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRaceSwimWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRaceDuathlonWorkout* pWorkout, FILE* fp);
    bool ReadWorkout(CUser* pUser, CRaceTriathlonWorkout* pWorkout, FILE* fp);

    void CreateProgress(CString strMessage, int nSteps);
    void StepProgress(void);
    void DestroyProgress(void);
    // data
    CSkinProgress* m_pProgress;
    CString m_strPrependRead;
    CString m_strPrependWrite;
    CString m_strSpaces;
	double m_dVersion;
};


BOOL PeekAndPump2(void);