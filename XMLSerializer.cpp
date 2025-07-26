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
#include "XMLSerializer.h"


CXMLSerializer::CXMLSerializer(void)
{
    m_pProgress = NULL;
    m_strPrependRead = "Currently reading: ";
    m_strPrependWrite = "Currently writing: ";
    m_strSpaces = "    ";
}


CXMLSerializer::~CXMLSerializer()
{
}


bool CXMLSerializer::WriteFile(CUser* pUser, CString strFile)
{
    if(NULL == pUser || (strFile.IsEmpty()))
    {
        return false;
    }

    FILE* fp = fopen(strFile, "w+");
    if(NULL == fp)
    {
        return false;
    }

    CreateProgress(m_strPrependWrite + "general information" + m_strSpaces, 61);

    CString strText = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\n";

    StepProgress();

    int nTabs = 0;
    strText += MakeXML("TriathLog", nTabs, "version", 4.06, false);
    nTabs++;

    StepProgress();

    strText += MakeXML("User", nTabs, true);
    nTabs++;

    StepProgress();

    strText += MakeXML("FirstName", nTabs, "value", pUser->GetFirstName());

    StepProgress();

    strText += MakeXML("LastName", nTabs, "value", pUser->GetLastName());

    StepProgress();

    strText += MakeXML("Sex", nTabs, "value", pUser->GetSex());

    StepProgress();

    strText += MakeXML("Height", nTabs, "value", pUser->GetHeight());

    StepProgress();

    strText += MakeXML("BaseTypeRun", nTabs, "value", pUser->GetBaseTypeRun());

    StepProgress();

    strText += MakeXML("BaseTypeBike", nTabs, "value", pUser->GetBaseTypeBike());

    StepProgress();

    strText += MakeXML("BaseTypeSwim", nTabs, "value", pUser->GetBaseTypeSwim());

    StepProgress();
    
    strText += MakeXML("RunDistUnits", nTabs, "value", pUser->GetRunDistUnits());

    StepProgress();

    strText += MakeXML("BikeDistUnits", nTabs, "value", pUser->GetBikeDistUnits());

    StepProgress();

    strText += MakeXML("SwimDistUnits", nTabs, "value", pUser->GetSwimDistUnits());

    StepProgress();

    strText += MakeXML("HeightUnits", nTabs, "value", pUser->GetHeightUnits());

    StepProgress();

    strText += MakeXML("WeightUnits", nTabs, "value", pUser->GetWeightUnits());

    StepProgress();

    strText += MakeXML("TemperatureUnits", nTabs, "value", pUser->GetTempUnits());

    StepProgress();

    strText += MakeXML("RunPaceFormat", nTabs, "value", pUser->GetPaceFormatRun());

    StepProgress();

    strText += MakeXML("BikePaceFormat", nTabs, "value", pUser->GetPaceFormatBike());

    StepProgress();

    strText += MakeXML("SwimPaceFormat", nTabs, "value", pUser->GetPaceFormatSwim());

    StepProgress();

	strText += MakeXML("RunDecimals", nTabs, "value", pUser->GetRunDecimals());

	StepProgress();

	strText += MakeXML("BikeDecimals", nTabs, "value", pUser->GetBikeDecimals());

	StepProgress();

	strText += MakeXML("SwimDecimals", nTabs, "value", pUser->GetSwimDecimals());

	StepProgress();

    strText += MakeXML("RunMandatory", nTabs, "value", pUser->GetMandatoryRunFields());

    StepProgress();

    strText += MakeXML("BikeMandatory", nTabs, "value", pUser->GetMandatoryBikeFields());

    StepProgress();

    strText += MakeXML("SwimMandatory", nTabs, "value", pUser->GetMandatorySwimFields());

    StepProgress();

    strText += MakeXML("StrengthMandatory", nTabs, "value", pUser->GetMandatoryStrengthFields());

    StepProgress();

    strText += MakeXML("RaceRunMandatory", nTabs, "value", pUser->GetMandatoryRaceRunFields());

    StepProgress();

    strText += MakeXML("RaceBikeMandatory", nTabs, "value", pUser->GetMandatoryRaceBikeFields());

    StepProgress();

    strText += MakeXML("RaceSwimMandatory", nTabs, "value", pUser->GetMandatoryRaceSwimFields());

    StepProgress();

    strText += MakeXML("RaceDuathlonMandatory", nTabs, "value", pUser->GetMandatoryRaceDuathlonFields());

    StepProgress();

    strText += MakeXML("RaceTriathlonMandatory", nTabs, "value", pUser->GetMandatoryRaceTriathlonFields());

    StepProgress();

    strText += MakeXML("StartMandatory", nTabs, "value", pUser->GetMandatoryStartFields());

    StepProgress();

	strText += MakeXML("AnimationTiming", nTabs, "value", pUser->GetDlgAnimationTime());

	StepProgress();

    strText += MakeXML("StartDay", nTabs, "value", pUser->GetFirstDayOfWeek());

    StepProgress();

    strText += MakeXML("RestHR", nTabs, "value", pUser->GetRestingHR());

    StepProgress();

    strText += MakeXML("Notes", nTabs, "value", pUser->GetNotes());

    StepProgress();

    strText += MakeXML("HighlightDay", nTabs, "value", pUser->GetHighlightDay());

    StepProgress();

    strText += MakeXML("CurrentTime", nTabs, pUser->GetCurrentDate());

    StepProgress();

    strText += MakeXML("DispInfoRun", nTabs, "value", pUser->DisplayInfoRun());

    StepProgress();

    strText += MakeXML("DispInfoBike", nTabs, "value", pUser->DisplayInfoBike());

    StepProgress();

    strText += MakeXML("DispInfoSwim", nTabs, "value", pUser->DisplayInfoSwim());

    StepProgress();

    strText += MakeXML("DispInfoStrength", nTabs, "value", pUser->DisplayInfoStrength());

    StepProgress();

    strText += MakeXML("DispInfoRace", nTabs, "value", pUser->DisplayInfoRace());

    StepProgress();

    strText += MakeXML("NormalDayColor", nTabs, "value", (int)pUser->GetDayColor(DAYTYPE_NORMAL));

    StepProgress();

    strText += MakeXML("GrayedDayColor", nTabs, "value", (int)pUser->GetDayColor(DAYTYPE_GRAYED));

    StepProgress();

    strText += MakeXML("WeekSumColor", nTabs, "value", (int)pUser->GetDayColor(DAYTYPE_WEEKSUM));

    StepProgress();

    strText += MakeXML("MonthSumColor", nTabs, "value", (int)pUser->GetDayColor(DAYTYPE_MONTHSUM));

    StepProgress();

    strText += MakeXML("HighlightColor", nTabs, "value", (int)pUser->GetHighlightColor());

    StepProgress();

    strText += MakeXML("BgColor", nTabs, "value", (int)pUser->GetBgColor());

    StepProgress();

    strText += MakeXML("ButtonColor", nTabs, "value", (int)pUser->GetButtonColor());

    StepProgress();

    strText += MakeXML("HeadingTextColor", nTabs, "value", (int)pUser->GetHeadingTextColor());

    StepProgress();

    strText += MakeXML("DayTextColor", nTabs, "value", (int)pUser->GetDayTextColor());

    StepProgress();

    strText += MakeXML("AnnotationTextColor", nTabs, "value", (int)pUser->GetAnnotationTextColor());

    StepProgress();

    strText += MakeXML("GradientStartColor", nTabs, "value", (int)pUser->GetGradientColor(true));

    StepProgress();

    strText += MakeXML("GradientEndColor", nTabs, "value", (int)pUser->GetGradientColor(false));

    StepProgress();

    strText += MakeXML("ShadowTLColor", nTabs, "value", (int)pUser->GetShadowColor(true));

    StepProgress();

    strText += MakeXML("ShadowBRColor", nTabs, "value", (int)pUser->GetShadowColor(false));

    StepProgress();

	strText += MakeXML("RaceDayColor", nTabs, "value", (int)pUser->GetRaceDayColor());

    StepProgress();

	strText += MakeXML("UpcomingRaceDayColor", nTabs, "value", (int)pUser->GetUpcomingRaceDayColor());

    StepProgress();

	strText += MakeXML("UpcomingWorkoutDayColor", nTabs, "value", (int)pUser->GetUpcomingWorkoutDayColor());

    StepProgress();

	strText += MakeXML("EditBgColor", nTabs, "value", (int)pUser->GetEditBgColor());

    StepProgress();

	DestroyProgress();

    fprintf(fp, strText);
    strText.Empty();

    CreateProgress(m_strPrependWrite + "hash table" + m_strSpaces, 1);
    strText += MakeXML(nTabs, pUser->GetHashMap());
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();
    DestroyProgress();
  
    CreateProgress(m_strPrependWrite + "courses" + m_strSpaces, 5);
    COURSERUNARRAY& rarCoursesRun = pUser->GetRefCourseRunArray();
    strText += MakeXML("CoursesRun", nTabs, "num", (int)rarCoursesRun.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarCoursesRun.GetCount(); i++)
    {
        CCourseRun* pCourse = rarCoursesRun.GetAt(i);
        if(NULL != pCourse)
        {
            strText += MakeXML(nTabs, pCourse, i);
        }
    }
    nTabs--;
    strText += MakeXML("CoursesRun", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();    
    StepProgress();

    COURSEBIKEARRAY& rarCoursesBike = pUser->GetRefCourseBikeArray();
    strText += MakeXML("CoursesBike", nTabs, "num", (int)rarCoursesBike.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarCoursesBike.GetCount(); i++)
    {
        CCourseBike* pCourse = rarCoursesBike.GetAt(i);
        if(NULL != pCourse)
        {
            strText += MakeXML(nTabs, pCourse, i);
        }
    }
    nTabs--;
    strText += MakeXML("CoursesBike", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    COURSESWIMARRAY& rarCoursesSwim = pUser->GetRefCourseSwimArray();
    strText += MakeXML("CoursesSwim", nTabs, "num", (int)rarCoursesSwim.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarCoursesSwim.GetCount(); i++)
    {
        CCourseSwim* pCourse = rarCoursesSwim.GetAt(i);
        if(NULL != pCourse)
        {
            strText += MakeXML(nTabs, pCourse, i);
        }
    }
    nTabs--;
    strText += MakeXML("CoursesSwim", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    COURSEDUATHLONARRAY& rarCoursesDuathlon = pUser->GetRefCourseDuathlonArray();
    strText += MakeXML("CoursesDuathlon", nTabs, "num", (int)rarCoursesDuathlon.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarCoursesDuathlon.GetCount(); i++)
    {
        CCourseDuathlon* pCourse = rarCoursesDuathlon.GetAt(i);
        if(NULL != pCourse)
        {
            strText += MakeXML(nTabs, pCourse, i);
        }
    }
    nTabs--;
    strText += MakeXML("CoursesDuathlon", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    COURSETRIATHLONARRAY& rarCoursesTriathlon = pUser->GetRefCourseTriathlonArray();
    strText += MakeXML("CoursesTriathlon", nTabs, "num", (int)rarCoursesTriathlon.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarCoursesTriathlon.GetCount(); i++)
    {
        CCourseTriathlon* pCourse = rarCoursesTriathlon.GetAt(i);
        if(NULL != pCourse)
        {
            strText += MakeXML(nTabs, pCourse, i);
        }
    }
    nTabs--;
    strText += MakeXML("CoursesTriathlon", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();
    DestroyProgress();

    CreateProgress(m_strPrependWrite + "locations" + m_strSpaces, 4);
    LOCATIONRUNARRAY& rarLocationsRun = pUser->GetRefLocationRunArray();
    strText += MakeXML("LocationsRun", nTabs, "num", (int)rarLocationsRun.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarLocationsRun.GetCount(); i++)
    {
        CLocationRun* pLocation = rarLocationsRun.GetAt(i);
        if(NULL != pLocation)
        {
            strText += MakeXML(nTabs, pLocation, i);
        }
    } 
    nTabs--;
    strText += MakeXML("LocationsRun", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    LOCATIONBIKEARRAY& rarLocationsBike = pUser->GetRefLocationBikeArray();
    strText += MakeXML("LocationsBike", nTabs, "num", (int)rarLocationsBike.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarLocationsBike.GetCount(); i++)
    {
        CLocationBike* pLocation = rarLocationsBike.GetAt(i);
        if(NULL != pLocation)
        {
            strText += MakeXML(nTabs, pLocation, i);
        }
    } 
    nTabs--;
    strText += MakeXML("LocationsBike", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    LOCATIONSWIMARRAY& rarLocationsSwim = pUser->GetRefLocationSwimArray();
    strText += MakeXML("LocationsSwim", nTabs, "num", (int)rarLocationsSwim.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarLocationsSwim.GetCount(); i++)
    {
        CLocationSwim* pLocation = rarLocationsSwim.GetAt(i);
        if(NULL != pLocation)
        {
            strText += MakeXML(nTabs, pLocation, i);
        }
    } 
    nTabs--;
    strText += MakeXML("LocationsSwim", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    LOCATIONSTRENGTHARRAY& rarLocationsStrength = pUser->GetRefLocationStrengthArray();
    strText += MakeXML("LocationsStrength", nTabs, "num", (int)rarLocationsStrength.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarLocationsStrength.GetCount(); i++)
    {
        CLocationStrength* pLocation = rarLocationsStrength.GetAt(i);
        if(NULL != pLocation)
        {
            strText += MakeXML(nTabs, pLocation, i);
        }
    } 
    nTabs--;
    strText += MakeXML("LocationsStrength", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();
    DestroyProgress();

    CreateProgress(m_strPrependWrite + "shoes" + m_strSpaces, 2);
    SHOESRUNARRAY& rarShoesRun = pUser->GetRefShoesRunArray();
    strText += MakeXML("ShoesRun", nTabs, "num", (int)rarShoesRun.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarShoesRun.GetCount(); i++)
    {
        CShoesRun* pShoes = rarShoesRun.GetAt(i);
        if(NULL != pShoes)
        {
            strText += MakeXML(nTabs, pShoes, i);
        }
    }
    nTabs--;
    strText += MakeXML("ShoesRun", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();

    SHOESBIKEARRAY& rarShoesBike = pUser->GetRefShoesBikeArray();
    strText += MakeXML("ShoesBike", nTabs, "num", (int)rarShoesBike.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarShoesBike.GetCount(); i++)
    {
        CShoesBike* pShoes = rarShoesBike.GetAt(i);
        if(NULL != pShoes)
        {
            strText += MakeXML(nTabs, pShoes, i);
        }
    }
    nTabs--;
    strText += MakeXML("ShoesBike", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();
    DestroyProgress();

    CreateProgress(m_strPrependWrite + "bikes" + m_strSpaces, 1);
    BIKEARRAY& rarBikes = pUser->GetRefBikeArray();
    strText += MakeXML("Bikes", nTabs, "num", (int)rarBikes.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarBikes.GetCount(); i++)
    {
        CBike* pBike = rarBikes.GetAt(i);
        if(NULL != pBike)
        {
            strText += MakeXML(nTabs, pBike, i);
        }
    }
    nTabs--;
    strText += MakeXML("Bikes", nTabs, false);
    fprintf(fp, strText);
    strText.Empty();
    StepProgress();
    DestroyProgress();

    DAYARRAY& rarDays = pUser->GetRefDayArray();
    int nNumDays = (int)rarDays.GetCount();
    CreateProgress(m_strPrependWrite + "days" + m_strSpaces, max(1, nNumDays)); 
    strText += MakeXML("Days", nTabs, "num", nNumDays, false);
    nTabs++;
    for(int i = 0; i < nNumDays; i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            strText += MakeXML(nTabs, pDay, pUser);
        }

        fprintf(fp, strText);
        strText.Empty();
        StepProgress();
    }
    nTabs--;
    strText += MakeXML("Days", nTabs, false);
    DestroyProgress();

    CreateProgress(m_strPrependWrite + "upcoming races" + m_strSpaces, 1);
    UPCOMINGRACEARRAY& rarRaces = pUser->GetRefUpcomingRaceArray();
    strText += MakeXML("UpcomingRaces", nTabs, "num", (int)rarRaces.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarRaces.GetCount(); i++)
    {
        CUpcomingRace* pRace = rarRaces.GetAt(i);
        if(NULL != pRace)
        {
            strText += MakeXML(nTabs, pRace);
        }
    }
    nTabs--;
    strText += MakeXML("UpcomingRaces", nTabs, false);
    StepProgress();
	DestroyProgress();

    CreateProgress(m_strPrependWrite + "planned workouts" + m_strSpaces, 1);
    UPCOMINGWORKOUTARRAY& rarWorkouts = pUser->GetRefUpcomingWorkoutArray();
    strText += MakeXML("UpcomingWorkouts", nTabs, "num", (int)rarWorkouts.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CUpcomingWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            strText += MakeXML(nTabs, pWorkout);
        }
    }
    nTabs--;
    strText += MakeXML("UpcomingWorkouts", nTabs, false);
    StepProgress();
    DestroyProgress();

    CreateProgress(m_strPrependWrite + "injuries" + m_strSpaces, 1);
    INJURYARRAY& rarInjuries = pUser->GetRefInjuryArray();
    strText += MakeXML("Injuries", nTabs, "num", (int)rarInjuries.GetCount(), false);
    nTabs++;
    for(int i = 0; i < rarInjuries.GetCount(); i++)
    {
        CInjury* pInjury = rarInjuries.GetAt(i);
        if(NULL != pInjury)
        {
            strText += MakeXML(nTabs, pInjury);
        }
    }
    nTabs--;
    strText += MakeXML("Injuries", nTabs, false);
    StepProgress();
    DestroyProgress();

    nTabs--;
    strText += MakeXML("User", nTabs, false);

    nTabs--;
    strText += MakeXML("TriathLog", nTabs, false);
    
    fprintf(fp, strText);
    fclose(fp);

    return true;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, bool bBegin)
{
    // if bBegin, return <strTag>.  otherwise, return </strTag>
    CString strText;
    for(int i = 0; i < nTabs; i++)
    {
        strText += "\t";
    }

    strText += "<";
    
    if(!bBegin)
    {
        strText += "/";
    }

    strText += strTag;
    strText += ">\n";

    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib, int nVal, 
                                bool bDone /* = true */)
{
    // return <strTag strAttrib="nVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib);

    CString strCur;
    strCur.Format("%d", nVal);
    strText += strCur;

    strText += PostpendXML(bDone);

    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib, unsigned __int64 i64Val, 
                                bool bDone /* = true */)
{
    // return <strTag strAttrib="nVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib);

    CString strCur;
    strCur.Format("%I64u", i64Val);
    strText += strCur;

    strText += PostpendXML(bDone);

    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib, double dVal, 
                                bool bDone /* = true */)
{
    // return <strTag strAttrib="dVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib);

    CString strCur;
    strCur.Format("%lf", dVal);
    strText += strCur;

    strText += PostpendXML(bDone);
    
    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib1, double dVal, 
                                CString strAttrib2, int nVal, bool bDone /* = true */)
{
    // return <strTag strAttrib1="dVal" strAttrib2="nVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib1);

    CString strCur;
    strCur.Format("%lf", dVal);
    strText += strCur;
    strText += "\" ";
    strText += strAttrib2;
    strText += "=\"";
    strCur.Format("%d", nVal);
    strText += strCur;

    strText += PostpendXML(bDone);
    
    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib1, int nVal1, 
                                CString strAttrib2, int nVal2, bool bDone /* = true */)
{
    // return <strTag strAttrib1="nVal1" strAttrib2="nVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib1);

    CString strCur;
    strCur.Format("%d", nVal1);
    strText += strCur;
    strText += "\" ";
    strText += strAttrib2;
    strText += "=\"";
    strCur.Format("%d", nVal2);
    strText += strCur;

    strText += PostpendXML(bDone);
    
    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, CString strAttrib, CString strVal, 
                                bool bDone /* = true */)
{
    // return <strTag strAttrib="strVal">
    CString strText = PrependXML(strTag, nTabs, strAttrib);

    strText += EncryptXML(strVal);

    strText += PostpendXML(bDone);

    return strText;
}


CString CXMLSerializer::MakeXML(CString strTag, int nTabs, COleDateTime tmVal)
{
    CString strText = PrependXML(strTag, nTabs, NULL);

    CString strCur;
    strCur.Format("year=\"%d\" month=\"%d\" day=\"%d\" hour=\"%d\" minute=\"%d\" second=\"%d", tmVal.GetYear(),
                   tmVal.GetMonth(), tmVal.GetDay(), tmVal.GetHour(), tmVal.GetMinute(), tmVal.GetSecond());
    strText += strCur;

    strText += PostpendXML(true);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CCourseRun* pCourse, int nID)
{
    // write out the course in XML
    if(NULL == pCourse)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("CourseRun", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pCourse->GetName());
    strText += MakeXML("Length", nTabs, "value", pCourse->GetLength());
    strText += MakeXML("PR", nTabs, "value", pCourse->GetPRSeconds());
    strText += MakeXML("City", nTabs, "value", pCourse->GetCity());
    strText += MakeXML("State", nTabs, "value", pCourse->GetState());
    strText += MakeXML("Notes", nTabs, "value", pCourse->GetNotes());

    nTabs--;
    strText += MakeXML("CourseRun", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CCourseBike* pCourse, int nID)
{
    // write out the course in XML
    if(NULL == pCourse)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("CourseBike", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pCourse->GetName());
    strText += MakeXML("Length", nTabs, "value", pCourse->GetLength());
    strText += MakeXML("PR", nTabs, "value", pCourse->GetPRSeconds());
    strText += MakeXML("City", nTabs, "value", pCourse->GetCity());
    strText += MakeXML("Statet", nTabs, "value", pCourse->GetState());
    strText += MakeXML("Notes", nTabs, "value", pCourse->GetNotes());

    nTabs--;
    strText += MakeXML("CourseBike", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CCourseSwim* pCourse, int nID)
{
    // write out the course in XML
    if(NULL == pCourse)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("CourseSwim", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pCourse->GetName());
    strText += MakeXML("Length", nTabs, "value", pCourse->GetLength());
    strText += MakeXML("PR", nTabs, "value", pCourse->GetPRSeconds());
    strText += MakeXML("City", nTabs, "value", pCourse->GetCity());
    strText += MakeXML("State", nTabs, "value", pCourse->GetState());
    strText += MakeXML("Notes", nTabs, "value", pCourse->GetNotes());

    nTabs--;
    strText += MakeXML("CourseSwim", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CCourseDuathlon* pCourse, int nID)
{
    // write out the course in XML
    if(NULL == pCourse)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("CourseDuathlon", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pCourse->GetName());
    strText += MakeXML("PR", nTabs, "value", pCourse->GetPRSeconds());
    strText += MakeXML("Trans1PR", nTabs, "value", pCourse->GetTransition1PRSeconds());
    strText += MakeXML("Trans2PR", nTabs, "value", pCourse->GetTransition2PRSeconds());
    strText += MakeXML("Leg1PR", nTabs, "value", pCourse->GetLeg1PRSeconds());
    strText += MakeXML("Leg1Length", nTabs, "value", pCourse->GetLeg1Length());
    strText += MakeXML("Leg1Notes", nTabs, "value", pCourse->GetLeg1Notes());    
    strText += MakeXML("Leg2PR", nTabs, "value", pCourse->GetLeg2PRSeconds());
    strText += MakeXML("Leg2Length", nTabs, "value", pCourse->GetLeg2Length());
    strText += MakeXML("Leg2Notes", nTabs, "value", pCourse->GetLeg2Notes());    
    strText += MakeXML("Leg3PR", nTabs, "value", pCourse->GetLeg3PRSeconds());
    strText += MakeXML("Leg3Length", nTabs, "value", pCourse->GetLeg3Length());
    strText += MakeXML("Leg3Notes", nTabs, "value", pCourse->GetLeg3Notes());
    strText += MakeXML("City", nTabs, "value", pCourse->GetCity());
    strText += MakeXML("State", nTabs, "value", pCourse->GetState());
    strText += MakeXML("Notes", nTabs, "value", pCourse->GetNotes());

    nTabs--;
    strText += MakeXML("CourseDuathlon", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CCourseTriathlon* pCourse, int nID)
{
    // write out the course in XML
    if(NULL == pCourse)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("CourseTriathlon", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pCourse->GetName());
    strText += MakeXML("PR", nTabs, "value", pCourse->GetPRSeconds());
    strText += MakeXML("Trans1PR", nTabs, "value", pCourse->GetTransition1PRSeconds());
    strText += MakeXML("Trans2PR", nTabs, "value", pCourse->GetTransition2PRSeconds());
    strText += MakeXML("Leg1PR", nTabs, "value", pCourse->GetLeg1PRSeconds());
    strText += MakeXML("Leg1Length", nTabs, "value", pCourse->GetLeg1Length());
    strText += MakeXML("Leg1Notes", nTabs, "value", pCourse->GetLeg1Notes());    
    strText += MakeXML("Leg2PR", nTabs, "value", pCourse->GetLeg2PRSeconds());
    strText += MakeXML("Leg2Length", nTabs, "value", pCourse->GetLeg2Length());
    strText += MakeXML("Leg2Notes", nTabs, "value", pCourse->GetLeg2Notes());    
    strText += MakeXML("Leg3PR", nTabs, "value", pCourse->GetLeg3PRSeconds());
    strText += MakeXML("Leg3Length", nTabs, "value", pCourse->GetLeg3Length());
    strText += MakeXML("Leg3Notes", nTabs, "value", pCourse->GetLeg3Notes());
    strText += MakeXML("City", nTabs, "value", pCourse->GetCity());
    strText += MakeXML("State", nTabs, "value", pCourse->GetState());
    strText += MakeXML("Notes", nTabs, "value", pCourse->GetNotes());

    nTabs--;
    strText += MakeXML("CourseTriathlon", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CLocationRun* pLocation, int nID)
{
    // write out the location in XML
    if(NULL == pLocation)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("LocationRun", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pLocation->GetName());
    strText += MakeXML("City", nTabs, "value", pLocation->GetCity());
    strText += MakeXML("State", nTabs, "value", pLocation->GetState());
    strText += MakeXML("Notes", nTabs, "value", pLocation->GetNotes());

    nTabs--;
    strText += MakeXML("LocationRun", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CLocationBike* pLocation, int nID)
{
    // write out the location in XML
    if(NULL == pLocation)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("LocationBike", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pLocation->GetName());
    strText += MakeXML("City", nTabs, "value", pLocation->GetCity());
    strText += MakeXML("State", nTabs, "value", pLocation->GetState());
    strText += MakeXML("Notes", nTabs, "value", pLocation->GetNotes());

    nTabs--;
    strText += MakeXML("LocationBike", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CLocationSwim* pLocation, int nID)
{
    // write out the location in XML
    if(NULL == pLocation)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("LocationSwim", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pLocation->GetName());
    strText += MakeXML("City", nTabs, "value", pLocation->GetCity());
    strText += MakeXML("State", nTabs, "value", pLocation->GetState());
    strText += MakeXML("Notes", nTabs, "value", pLocation->GetNotes());

    nTabs--;
    strText += MakeXML("LocationSwim", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CLocationStrength* pLocation, int nID)
{
    // write out the location in XML
    if(NULL == pLocation)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("LocationStrength", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Name", nTabs, "value", pLocation->GetName());
    strText += MakeXML("City", nTabs, "value", pLocation->GetCity());
    strText += MakeXML("State", nTabs, "value", pLocation->GetState());
    strText += MakeXML("Notes", nTabs, "value", pLocation->GetNotes());

    nTabs--;
    strText += MakeXML("LocationStrength", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CShoesRun* pShoes, int nID)
{
    // write out the shoes in XML
    if(NULL == pShoes)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("ShoeRun", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Brand", nTabs, "value", pShoes->GetBrand());
    strText += MakeXML("Type", nTabs, "value", pShoes->GetType());
    strText += MakeXML("Size", nTabs, "value", pShoes->GetSize());
    strText += MakeXML("FirstDay", nTabs, pShoes->GetFirstDay());
    strText += MakeXML("Notes", nTabs, "value", pShoes->GetNotes());
    strText += MakeXML("Retired", nTabs, "value", pShoes->IsRetired());

    nTabs--;
    strText += MakeXML("ShoeRun", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CShoesBike* pShoes, int nID)
{
    // write out the shoes in XML
    if(NULL == pShoes)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("ShoeBike", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Brand", nTabs, "value", pShoes->GetBrand());
    strText += MakeXML("Type", nTabs, "value", pShoes->GetType());
    strText += MakeXML("Size", nTabs, "value", pShoes->GetSize());
    strText += MakeXML("FirstDay", nTabs, pShoes->GetFirstDay());
    strText += MakeXML("Notes", nTabs, "value", pShoes->GetNotes());
    strText += MakeXML("Retired", nTabs, "value", pShoes->IsRetired());

    nTabs--;
    strText += MakeXML("ShoeBike", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBike* pBike, int nID)
{
    // write out the shoes in XML
    if(NULL == pBike)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("Bike", nTabs, "id", nID, false);
    nTabs++;

    strText += MakeXML("Brand", nTabs, "value", pBike->GetBrand());
    strText += MakeXML("Type", nTabs, "value", pBike->GetType());
    strText += MakeXML("Size", nTabs, "value", pBike->GetSize());
    strText += MakeXML("FirstDay", nTabs, pBike->GetFirstDay());
    strText += MakeXML("Notes", nTabs, "value", pBike->GetNotes());
    strText += MakeXML("Retired", nTabs, "value", pBike->IsRetired());

    nTabs--;
    strText += MakeXML("Bike", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CUpcomingRace* pRace)
{
    // write out the race in XML
    if(NULL == pRace)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("Upcoming Race", nTabs, true);
    nTabs++;

    strText += MakeXML("Date", nTabs, pRace->GetDate());
    strText += MakeXML("Line1", nTabs, "value", pRace->GetLineOne());
    strText += MakeXML("Line2", nTabs, "value", pRace->GetLineTwo());
    strText += MakeXML("Line3", nTabs, "value", pRace->GetLineThree());

    nTabs--;
    strText += MakeXML("UpcomingRace", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CUpcomingWorkout* pWorkout)
{
    // write out the Workout in XML
    if(NULL == pWorkout)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("Planned Workout", nTabs, true);
    nTabs++;

    strText += MakeXML("Date", nTabs, pWorkout->GetDate());
    strText += MakeXML("Line1", nTabs, "value", pWorkout->GetLineOne());
    strText += MakeXML("Line2", nTabs, "value", pWorkout->GetLineTwo());
    strText += MakeXML("Line3", nTabs, "value", pWorkout->GetLineThree());

    nTabs--;
    strText += MakeXML("UpcomingWorkout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CInjury* pInjury)
{
    // write out the Workout in XML
    if(NULL == pInjury)
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("Injury", nTabs, true);
    nTabs++;

	strText += MakeXML("Name", nTabs, "value", pInjury->GetName());
    strText += MakeXML("StartDate", nTabs, pInjury->GetStartDate());
    strText += MakeXML("EndDate", nTabs, pInjury->GetEndDate());
	strText += MakeXML("Finished", nTabs, "value", pInjury->IsFinished());
	strText += MakeXML("Description", nTabs, "value", pInjury->GetDescription());
	strText += MakeXML("Treatment", nTabs, "value", pInjury->GetTreatment());

    nTabs--;
    strText += MakeXML("Injury", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CDayLog* pDay, CUser* pUser)
{
    // write out the day in XML
    if((NULL == pDay) || (NULL == pUser))
    { 
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    CString strText;
    strText += MakeXML("Day", nTabs, true);
    nTabs++;

    strText += MakeXML("Date", nTabs, pDay->GetDate());
 
    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();

    strText += MakeXML("Workouts", nTabs, "num", (int)rarWorkouts.GetCount(), false);
    nTabs++;

    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            strText += MakeXML(nTabs, pWorkout, pUser);
        }
    }

    nTabs--;
    strText += MakeXML("Workouts", nTabs, false);

    nTabs--;
    strText += MakeXML("Day", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CWorkout* pWorkout, CUser* pUser)
{
    // write out the workout in XML
    if((NULL == pWorkout) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return NULL;
    }

    switch(pWorkout->GetActivityType())
    {
    case ACTIVITY_RUNNING:
        {
            switch(pWorkout->GetType())
            {
            case RUNTYPE_EZ:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunEZWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_HARD:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunHardWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_HILLS:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunHillWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_INTERVALS:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunIntervalWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_OTHER:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunMiscWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_NORMAL:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunNormalWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_POOL:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunPoolWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_TEMPO:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunTempoWorkout*>(pWorkout), pUser);
                }

            case RUNTYPE_TREADMILL:
                {
                    return MakeXML(nTabs, dynamic_cast<CRunTreadmillWorkout*>(pWorkout), pUser);
                }

            default:
                {
                    CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
                    return "NULL";
                }
            }
        }

    case ACTIVITY_BIKING:
        {
           switch(pWorkout->GetType())
            {
            case BIKETYPE_EZ:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeEZWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_HARD:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeHardWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_HILLS:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeHillWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_INTERVALS:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeIntervalWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_OTHER:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeMiscWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_NORMAL:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeNormalWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_TRAINER:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeTrainerWorkout*>(pWorkout), pUser);
                }

            case BIKETYPE_MOUNTAINBIKE:
                {
                    return MakeXML(nTabs, dynamic_cast<CBikeMountainBikeWorkout*>(pWorkout), pUser);
                }

			case BIKETYPE_TIMETRIAL:
				{
					return MakeXML(nTabs, dynamic_cast<CBikeTimeTrialWorkout*>(pWorkout), pUser);
				}

            default:
                {
                    CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
                    return "NULL";
                }
            }
        }

    case ACTIVITY_SWIMMING:
        {
           switch(pWorkout->GetType())
            {
            case SWIMTYPE_DRILLS:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimDrillWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_EZ:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimEZWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_HARD:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimHardWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_INTERVALS:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimIntervalWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_OTHER:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimMiscWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_NORMAL:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimNormalWorkout*>(pWorkout), pUser);
                }

            case SWIMTYPE_OPENWATER:
                {
                    return MakeXML(nTabs, dynamic_cast<CSwimOpenWaterWorkout*>(pWorkout), pUser);
                }

            default:
                {
                    CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
                    return "NULL";
                }
            }
        }

    case ACTIVITY_STRENGTH:
        {
           switch(pWorkout->GetType())
            {
            case STRENGTHTYPE_ABS:
                {
                    return MakeXML(nTabs, dynamic_cast<CStrengthAbsWorkout*>(pWorkout), pUser);
                }

            case STRENGTHTYPE_OTHER:
                {
                    return MakeXML(nTabs, dynamic_cast<CStrengthMiscWorkout*>(pWorkout), pUser);
                }

            case STRENGTHTYPE_WEIGHTS:
                {
                    return MakeXML(nTabs, dynamic_cast<CStrengthWeightsWorkout*>(pWorkout), pUser);
                }

            default:
                {
                    CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
                    return "NULL";
                }
            }
        }

    case ACTIVITY_RACE:
        {
            switch(pWorkout->GetType())
            {
            case RACETYPE_RUN:
                {
                    return MakeXML(nTabs, dynamic_cast<CRaceRunWorkout*>(pWorkout), pUser);
                }

            case RACETYPE_BIKE:
                {
                    return MakeXML(nTabs, dynamic_cast<CRaceBikeWorkout*>(pWorkout), pUser);
                }

            case RACETYPE_SWIM:
                {
                    return MakeXML(nTabs, dynamic_cast<CRaceSwimWorkout*>(pWorkout), pUser);
                }

            case RACETYPE_DUATHLON:
                {
                    return MakeXML(nTabs, dynamic_cast<CRaceDuathlonWorkout*>(pWorkout), pUser);
                }

            case RACETYPE_TRIATHLON:
                {
                    return MakeXML(nTabs, dynamic_cast<CRaceTriathlonWorkout*>(pWorkout), pUser);
                }

            default:
                {
                    CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
                    return "NULL";
                }
            }
        }
        
    default:
        {
            CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
            return "NULL";
        }
    }
}


CString CXMLSerializer::MakeXML(int nTabs, CRunEZWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_EZ, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunHardWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_HARD, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunHillWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_HILLS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunIntervalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_INTERVALS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("SpecialShoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetSpecialShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunMiscWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_OTHER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    strText += MakeXML("CountOnShoes", nTabs, "value", pWorkout->IsCountedOnShoes());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunNormalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_NORMAL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunPoolWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_POOL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunTempoWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_TEMPO, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRunTreadmillWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RUNNING, "type", RUNTYPE_TREADMILL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationRun(pWorkout->GetLocationRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeEZWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_EZ, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeHardWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_HARD, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeHillWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_HILLS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeIntervalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_INTERVALS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("SpecialShoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetSpecialShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeMiscWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_OTHER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    strText += MakeXML("CountOnShoes", nTabs, "value", pWorkout->IsCountedOnShoes());
    strText += MakeXML("CountOnBike", nTabs, "value", pWorkout->IsCountedOnBike());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeNormalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_NORMAL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeTrainerWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_TRAINER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    strText += MakeXML("CountOnShoes", nTabs, "value", pWorkout->IsCountedOnShoes());
    strText += MakeXML("CountOnBike", nTabs, "value", pWorkout->IsCountedOnBike());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeMountainBikeWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_MOUNTAINBIKE, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CBikeTimeTrialWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_BIKING, "type", BIKETYPE_TIMETRIAL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationBike(pWorkout->GetLocationBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("SpecialShoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetSpecialShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimDrillWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_DRILLS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimEZWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_EZ, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimHardWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_HARD, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimIntervalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_INTERVALS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    strText += MakeXML("SpecialDist", nTabs, "value", pWorkout->GetSpecialMiles());
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimMiscWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_OTHER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimNormalWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_NORMAL, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CSwimOpenWaterWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_SWIMMING, "type", SWIMTYPE_OPENWATER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationSwim(pWorkout->GetLocationSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CStrengthAbsWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_STRENGTH, "type", STRENGTHTYPE_ABS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationStrength(pWorkout->GetLocationStrength()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CStrengthMiscWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_STRENGTH, "type", STRENGTHTYPE_OTHER, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationStrength(pWorkout->GetLocationStrength()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CStrengthWeightsWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_STRENGTH, "type", STRENGTHTYPE_WEIGHTS, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("LocationAt", nTabs, "id", pUser->GetIDFromLocationStrength(pWorkout->GetLocationStrength()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRaceRunWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RACE, "type", RACETYPE_RUN, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("CourseAt", nTabs, "id", pUser->GetIDFromCourseRun(pWorkout->GetCourseRun()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("Place", nTabs, "value", pWorkout->GetRacePosition());
    strText += MakeXML("RaceNumber", nTabs, "value", pWorkout->GetRaceNumber());

    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetShoesRun()));
    strText += MakeXML("SpecialShoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetSpecialShoesRun()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRaceBikeWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RACE, "type", RACETYPE_BIKE, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("CourseAt", nTabs, "id", pUser->GetIDFromCourseBike(pWorkout->GetCourseBike()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("Place", nTabs, "value", pWorkout->GetRacePosition());
    strText += MakeXML("RaceNumber", nTabs, "value", pWorkout->GetRaceNumber());

    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Wind", nTabs, "value", pWorkout->GetWind());
    strText += MakeXML("ShoesUsed", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetShoesBike()));
    strText += MakeXML("SpecialShoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetSpecialShoesBike()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRaceSwimWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RACE, "type", RACETYPE_SWIM, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("CourseAt", nTabs, "id", pUser->GetIDFromCourseSwim(pWorkout->GetCourseSwim()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
    strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
    strText += MakeXML("HR", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("SpecialSeconds", nTabs, "value", pWorkout->GetSpecialSeconds());
    strText += MakeXML("Place", nTabs, "value", pWorkout->GetRacePosition());
    strText += MakeXML("RaceNumber", nTabs, "value", pWorkout->GetRaceNumber());

    strText += MakeXML("Distance", nTabs, "value", pWorkout->GetMiles());
    strText += MakeXML("Choppiness", nTabs, "value", pWorkout->GetChoppiness());

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRaceDuathlonWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RACE, "type", RACETYPE_DUATHLON, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("CourseAt", nTabs, "id", pUser->GetIDFromCourseDuathlon(pWorkout->GetCourseDuathlon()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
	strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
	strText += MakeXML("Heartrate", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Place", nTabs, "value", pWorkout->GetRacePosition());
    strText += MakeXML("RaceNumber", nTabs, "value", pWorkout->GetRaceNumber());

    strText += MakeXML("Trans1Seconds", nTabs, "value", pWorkout->GetTransition1Seconds());
    strText += MakeXML("Trans2Seconds", nTabs, "value", pWorkout->GetTransition2Seconds());

    strText += MakeXML("L1Seconds", nTabs, "value", pWorkout->GetLeg1Seconds());
    strText += MakeXML("L1RaceSeconds", nTabs, "value", pWorkout->GetLeg1RaceSeconds());
    strText += MakeXML("L1Distance", nTabs, "value", pWorkout->GetLeg1Miles());
    strText += MakeXML("L1Temperature", nTabs, "value", pWorkout->GetLeg1Temperature());
    strText += MakeXML("L1Wind", nTabs, "value", pWorkout->GetLeg1Wind());
    strText += MakeXML("L1HR", nTabs, "value", pWorkout->GetLeg1HR());
    strText += MakeXML("L1Shoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg1Shoes()));
    strText += MakeXML("L1SpecialShoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg1RaceShoes()));

    strText += MakeXML("L2Seconds", nTabs, "value", pWorkout->GetLeg2Seconds());
    strText += MakeXML("L2RaceSeconds", nTabs, "value", pWorkout->GetLeg2RaceSeconds());
    strText += MakeXML("L2Distance", nTabs, "value", pWorkout->GetLeg2Miles());
    strText += MakeXML("L2Temperature", nTabs, "value", pWorkout->GetLeg2Temperature());
    strText += MakeXML("L2Wind", nTabs, "value", pWorkout->GetLeg2Wind());
    strText += MakeXML("L2HR", nTabs, "value", pWorkout->GetLeg2HR());
    strText += MakeXML("L2Shoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetLeg2Shoes()));
    strText += MakeXML("L2SpecialShoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetLeg2RaceShoes()));

    strText += MakeXML("L3Seconds", nTabs, "value", pWorkout->GetLeg3Seconds());
    strText += MakeXML("L3RaceSeconds", nTabs, "value", pWorkout->GetLeg3RaceSeconds());
    strText += MakeXML("L3Distance", nTabs, "value", pWorkout->GetLeg3Miles());
    strText += MakeXML("L3Temperature", nTabs, "value", pWorkout->GetLeg3Temperature());
    strText += MakeXML("L3Wind", nTabs, "value", pWorkout->GetLeg3Wind());
    strText += MakeXML("L3HR", nTabs, "value", pWorkout->GetLeg3HR());
    strText += MakeXML("L3Shoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg3Shoes()));
    strText += MakeXML("L3SpecialShoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg3RaceShoes()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, CRaceTriathlonWorkout* pWorkout, CUser* pUser)
{
    if((NULL == pUser) || (NULL == pWorkout))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::MakeXML");
        return "NULL";
    }

    CString strText;
    strText += MakeXML("Workout", nTabs, "activity", ACTIVITY_RACE, "type", RACETYPE_TRIATHLON, false);
    nTabs++;

    strText += MakeXML("DispName", nTabs, "value", pWorkout->GetDisplayName());
    strText += MakeXML("Bike", nTabs, "id", pUser->GetIDFromBike(pWorkout->GetBike()));
    strText += MakeXML("Weight", nTabs, "value", pWorkout->GetWeight());
	strText += MakeXML("Data File", nTabs, "value", pWorkout->GetDataFile());
    strText += MakeXML("StartTime", nTabs, pWorkout->GetTimeStart());
    strText += MakeXML("PreviousSleep", nTabs, "value", pWorkout->GetPrevNightSleep());
    strText += MakeXML("CourseAt", nTabs, "id", pUser->GetIDFromCourseTriathlon(pWorkout->GetCourseTriathlon()));
    strText += MakeXML("Seconds", nTabs, "value", pWorkout->GetSeconds());
	strText += MakeXML("Temperature", nTabs, "value", pWorkout->GetTemperature());
	strText += MakeXML("Heartrate", nTabs, "value", pWorkout->GetHR());
    strText += MakeXML("Long", nTabs, "value", pWorkout->IsLong());
    strText += MakeXML("Injured", nTabs, "value", pWorkout->IsInjured());
	strText += MakeXML("Sick", nTabs, "value", pWorkout->IsSick());
    strText += MakeXML("Notes", nTabs, "value", pWorkout->GetNotes());
    
    strText += MakeXML("Place", nTabs, "value", pWorkout->GetRacePosition());
    strText += MakeXML("RaceNumber", nTabs, "value", pWorkout->GetRaceNumber());

    strText += MakeXML("Trans1Seconds", nTabs, "value", pWorkout->GetTransition1Seconds());
    strText += MakeXML("Trans2Seconds", nTabs, "value", pWorkout->GetTransition2Seconds());

    strText += MakeXML("L1Seconds", nTabs, "value", pWorkout->GetLeg1Seconds());
    strText += MakeXML("L1RaceSeconds", nTabs, "value", pWorkout->GetLeg1RaceSeconds());
    strText += MakeXML("L1Distance", nTabs, "value", pWorkout->GetLeg1Miles());
    strText += MakeXML("L1Temperature", nTabs, "value", pWorkout->GetLeg1Temperature());
    strText += MakeXML("L1Choppiness", nTabs, "value", pWorkout->GetChoppiness());
    strText += MakeXML("L1HR", nTabs, "value", pWorkout->GetLeg1HR());

    strText += MakeXML("L2Seconds", nTabs, "value", pWorkout->GetLeg2Seconds());
    strText += MakeXML("L2RaceSeconds", nTabs, "value", pWorkout->GetLeg2RaceSeconds());
    strText += MakeXML("L2Distance", nTabs, "value", pWorkout->GetLeg2Miles());
    strText += MakeXML("L2Temperature", nTabs, "value", pWorkout->GetLeg2Temperature());
    strText += MakeXML("L2Wind", nTabs, "value", pWorkout->GetLeg2Wind());
    strText += MakeXML("L2HR", nTabs, "value", pWorkout->GetLeg2HR());
    strText += MakeXML("L2Shoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetLeg2Shoes()));
    strText += MakeXML("L2SpecialShoes", nTabs, "id", pUser->GetIDFromShoesBike(pWorkout->GetLeg2RaceShoes()));

    strText += MakeXML("L3Seconds", nTabs, "value", pWorkout->GetLeg3Seconds());
    strText += MakeXML("L3RaceSeconds", nTabs, "value", pWorkout->GetLeg3RaceSeconds());
    strText += MakeXML("L3Distance", nTabs, "value", pWorkout->GetLeg3Miles());
    strText += MakeXML("L3Temperature", nTabs, "value", pWorkout->GetLeg3Temperature());
    strText += MakeXML("L3Wind", nTabs, "value", pWorkout->GetLeg3Wind());
    strText += MakeXML("L3HR", nTabs, "value", pWorkout->GetLeg3HR());
    strText += MakeXML("L3Shoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg3Shoes()));
    strText += MakeXML("L3SpecialShoes", nTabs, "id", pUser->GetIDFromShoesRun(pWorkout->GetLeg3RaceShoes()));

    nTabs--;
    strText += MakeXML("Workout", nTabs, false);

    return strText;
}


CString CXMLSerializer::MakeXML(int nTabs, const CMap<int, int, int, int>& rmapHash)
{
    CString strText;
    strText += MakeXML("HashMap", nTabs, "num", (int)rmapHash.GetCount(), false);
    nTabs++;

    int nCurKey = 0;
    int nCurElem = 0;
    POSITION pos = rmapHash.GetStartPosition();
    while(NULL != pos)
    {
        rmapHash.GetNextAssoc(pos, nCurKey, nCurElem);
        strText += MakeXML("HashElement", nTabs, "key", nCurKey, "value", nCurElem);
    }

    nTabs--;
    strText += MakeXML("HashMap", nTabs, false);
    
    return strText;    
}


CString CXMLSerializer::PrependXML(CString strTag, int nTabs, CString strAttrib)
{
    // send back \t\t<TAG attrib=" (if attrib is not null) or \t\t<TAG (if attrib is null)
    CString strText;
    for(int i = 0; i < nTabs; i++)
    {
        strText += "\t";
    }

    strText += "<";
    strText += strTag;
    strText += " ";

    if(!strAttrib.IsEmpty())
    {
        strText += strAttrib;
        strText += "=\"";
    }

    return strText;
}


CString CXMLSerializer::PostpendXML(bool bDone)
{
    // send back "/>\n  or ">\n
    CString strText;
    if(bDone)
    {
        strText += "\"/>\n";
    }
    else
    {
        strText += "\">\n";
    }
    
    return strText;
}


bool CXMLSerializer::ReadFile(CUser* pUser, CString strFile)
{
    if(NULL == pUser)
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadFile");
        return false;
    }

    FILE* fp = fopen(strFile, "r+");
    if(NULL == fp)
    {
        return false;
    }

    double dVersion = 0.0;

    bool fRes = true;
    bool fCur1 = false;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nCur2 = 0;
    unsigned __int64 i64Cur = 0;
    CString strCur;
    COleDateTime tmCur;

    // skip the <xml version .../> stuff
    ReadSingleLine(fp);

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dVersion);

	m_dVersion = dVersion;

    // read 3.0 or 3.1 only
    if((3.0 == dVersion) || (3.1 == dVersion) || (4.0 <=dVersion))
    {
        // skip over <User>
        ReadSingleLine(fp);

        CreateProgress(m_strPrependRead + "general information" + m_strSpaces, 33);

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetFirstName(strCur);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetLastName(strCur);
    
        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetSex(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHeight(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBaseTypeRun(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBaseTypeBike(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBaseTypeSwim(nCur1);

        StepProgress();

        // with version 3.1 there's some more stuff to read here
        if((3.1 == dVersion) || (4.0 <=dVersion))
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetRunDistUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetBikeDistUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetSwimDistUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetHeightUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetWeightUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetTempUnits(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetPaceFormatRun(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetPaceFormatBike(nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);
            pUser->SetPaceFormatSwim(nCur1);

			if(4.0 <=dVersion)
			{
				strLine = ReadSingleLine(fp);
				fRes &= ParseXML(strLine, nCur1);
				pUser->SetRunDecimals(nCur1);

				strLine = ReadSingleLine(fp);
				fRes &= ParseXML(strLine, nCur1);
				pUser->SetBikeDecimals(nCur1);

				strLine = ReadSingleLine(fp);
				fRes &= ParseXML(strLine, nCur1);
				pUser->SetSwimDecimals(nCur1);
			}

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRunFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryBikeFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatorySwimFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryStrengthFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRaceRunFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRaceBikeFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRaceSwimFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRaceDuathlonFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryRaceTriathlonFields(i64Cur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, i64Cur);
            pUser->SetMandatoryStartFields(i64Cur);

			if(4.0 <=dVersion)
			{
				strLine = ReadSingleLine(fp);
				fRes &= ParseXML(strLine, nCur1);
				pUser->SetDlgAnimationTime(nCur1);
			}
        }

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetFirstDayOfWeek(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetRestingHR(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetNotes(strCur);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHighlightDay(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, tmCur);
        pUser->SetCurrentDate(tmCur);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, fCur1);
        pUser->SetDisplayInfoRun(fCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, fCur1);
        pUser->SetDisplayInfoBike(fCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, fCur1);
        pUser->SetDisplayInfoSwim(fCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, fCur1);
        pUser->SetDisplayInfoStrength(fCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, fCur1);
        pUser->SetDisplayInfoRace(fCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_NORMAL, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_GRAYED, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_WEEKSUM, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_MONTHSUM, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHighlightColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBgColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetButtonColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHeadingTextColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayTextColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetAnnotationTextColor(nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetGradientColor(true, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetGradientColor(false, nCur1);
        
        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetShadowColor(true, nCur1);

        StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetShadowColor(false, nCur1);

		StepProgress();

		if(4.0 <=dVersion)
		{
			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, nCur1);
			pUser->SetRaceDayColor(nCur1);

			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, nCur1);
			pUser->SetUpcomingRaceDayColor(nCur1);

			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, nCur1);
			pUser->SetUpcomingWorkoutDayColor(nCur1);

			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, nCur1);
			pUser->SetEditBgColor(nCur1);
		}			

        StepProgress();
        DestroyProgress();

        fRes &= ReadHashMap(pUser, fp);

        CreateProgress(m_strPrependRead + "courses" + m_strSpaces, 5);
        fRes &= ReadCoursesRun(pUser, fp);      
        StepProgress();
        fRes &= ReadCoursesBike(pUser, fp);
        StepProgress();
        fRes &= ReadCoursesSwim(pUser, fp);
        StepProgress();
        fRes &= ReadCoursesDuathlon(pUser, fp);
        StepProgress();
        fRes &= ReadCoursesTriathlon(pUser, fp);
        StepProgress();
        DestroyProgress();

        CreateProgress(m_strPrependRead + "locations" + m_strSpaces, 4);
        fRes &= ReadLocationsRun(pUser, fp);
        StepProgress();
        fRes &= ReadLocationsBike(pUser, fp);
        StepProgress();
        fRes &= ReadLocationsSwim(pUser, fp);
        StepProgress();
        fRes &= ReadLocationsStrength(pUser, fp);
        StepProgress();
        DestroyProgress();

        CreateProgress(m_strPrependRead + "shoes" + m_strSpaces, 2);
        fRes &= ReadShoesRun(pUser, fp);
        StepProgress();
        fRes &= ReadShoesBike(pUser, fp);
        StepProgress();
        DestroyProgress();

        CreateProgress(m_strPrependRead + "bikes" + m_strSpaces, 1);
        fRes &= ReadBikes(pUser, fp);
        StepProgress();
        DestroyProgress();

        fRes &= ReadDays(pUser, fp);

        CreateProgress(m_strPrependRead + "upcoming races" + m_strSpaces, 1);
        fRes &= ReadUpcomingRaces(pUser, fp, dVersion);
        StepProgress();
        DestroyProgress();

		if(4.0 <=dVersion)
		{
			CreateProgress(m_strPrependRead + "planned workouts" + m_strSpaces, 1);
			fRes &= ReadUpcomingWorkouts(pUser, fp);
			StepProgress();
			DestroyProgress();
		}

		if(4.05 <= dVersion)
		{
			CreateProgress(m_strPrependRead + "injuries" + m_strSpaces, 1);
			fRes &= ReadInjuries(pUser, fp);
			StepProgress();
			DestroyProgress();
		}
    }
    else
    {
        fRes = false;
    }
    
    fclose(fp);
    return fRes;
}


CString CXMLSerializer::ReadSingleLine(FILE* fp)
{
    if(NULL == fp)
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadSingleLine");
        return NULL;
    }

    CString strRet;
    
    char ch = fgetc(fp);
    while(0 == feof(fp))
    {
        strRet += ch;

        if('>' == ch)
        {
            break;
        }

        ch = fgetc(fp);
    }

    return strRet;
}


bool CXMLSerializer::ParseXML(CString str, int& rnVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rnVal = atoi(str);
    return true;
}


bool CXMLSerializer::ParseXML(CString str, unsigned __int64& ri64Val)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    ri64Val = _atoi64(str);
    return true;
}


bool CXMLSerializer::ParseXML(CString str, bool& rfVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    int nVal = atoi(str);
    if(nVal == 1)
    {
        rfVal = true;
    }
    else
    {
        rfVal = false;
    }
    return true;
}


bool CXMLSerializer::ParseXML(CString str, int& rnVal1, int& rnVal2)
{
    int n = -1;
    CString astrVals[2];

    for(int i = 0; i < 2; i++)
    {
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');

        astrVals[i] = str.Left(n);
    }

    rnVal1 = atoi(astrVals[0]);
    rnVal2 = atoi(astrVals[1]);

    return true;
}


bool CXMLSerializer::ParseXML(CString str, double& rdVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rdVal = atof(str);
    return true;
}


bool CXMLSerializer::ParseXML(CString str, COleDateTime& rtmVal)
{
    int n = -1;
    CString astrVals[6];

    for(int i = 0; i < 6; i++)
    {
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');

        astrVals[i] = str.Left(n);
    }

    int nYear = atoi(astrVals[0]);
    int nMonth = atoi(astrVals[1]);
    int nDay = atoi(astrVals[2]);
    int nHour = atoi(astrVals[3]);
    int nMinute = atoi(astrVals[4]);
    int nSecond = atoi(astrVals[5]);

    rtmVal = COleDateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
    return true;
}


bool CXMLSerializer::ParseXML(CString str, CString& rstrVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rstrVal = DecryptXML(str);
    return true;
}


bool CXMLSerializer::ReadHashMap(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadHashMap");
        return NULL;
    }

    bool fRes = true;
    int nCur1 = 0;
    int nCur2 = 0;
    int nNum = 0;
    CMap<int, int, int, int> mapHash;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);

    CreateProgress(m_strPrependRead + "hash table" + m_strSpaces, max(1, nNum));
    
    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1, nCur2);
        mapHash[nCur1] = nCur2;
        StepProgress();
    }
    pUser->SetHashMap(mapHash);

    DestroyProgress();
    
    ReadSingleLine(fp);

    return fRes;
}


bool CXMLSerializer::ReadCoursesRun(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadCoursesRun");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CCourseRun* pCourse = new CCourseRun;
        if(NULL != pCourse)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLength(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetPRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddCourseRun(pCourse);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadCoursesBike(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadCoursesBike");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CCourseBike* pCourse = new CCourseBike;
        if(NULL != pCourse)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLength(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetPRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddCourseBike(pCourse);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadCoursesSwim(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadCoursesSwim");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CCourseSwim* pCourse = new CCourseSwim;
        if(NULL != pCourse)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLength(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetPRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddCourseSwim(pCourse);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadCoursesDuathlon(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadCoursesDuathlon");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CCourseDuathlon* pCourse = new CCourseDuathlon;
        if(NULL != pCourse)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetPRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetTransition1PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetTransition2PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg1PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg1Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg1Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg2PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg2Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg2Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg3PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg3Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg3Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddCourseDuathlon(pCourse);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadCoursesTriathlon(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadCoursesTriathlon");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CCourseTriathlon* pCourse = new CCourseTriathlon;
        if(NULL != pCourse)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetPRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetTransition1PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetTransition2PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg1PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg1Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg1Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg2PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg2Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg2Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg3PRSeconds(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pCourse->SetLeg3Length(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetLeg3Notes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pCourse->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddCourseTriathlon(pCourse);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadLocationsRun(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadLocationsRun");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CLocationRun* pLocation = new CLocationRun;
        if(NULL != pLocation)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddLocationRun(pLocation);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadLocationsBike(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadLocationsBike");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CLocationBike* pLocation = new CLocationBike;
        if(NULL != pLocation)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddLocationBike(pLocation);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadLocationsSwim(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadLocationsSwim");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CLocationSwim* pLocation = new CLocationSwim;
        if(NULL != pLocation)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddLocationSwim(pLocation);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadLocationsStrength(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadLocationsStrength");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CLocationStrength* pLocation = new CLocationStrength;
        if(NULL != pLocation)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetName(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetCity(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetState(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pLocation->SetNotes(strCur);

            ReadSingleLine(fp);

            pUser->AddLocationStrength(pLocation);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadShoesRun(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadShoesRun");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    bool fCur1 = false;
    COleDateTime tmCur;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CShoesRun* pShoes = new CShoesRun;
        if(NULL != pShoes)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetBrand(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetType(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pShoes->SetSize(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pShoes->SetFirstDay(tmCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetNotes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, fCur1);
            pShoes->SetRetired(fCur1);

            ReadSingleLine(fp);

            pUser->AddShoesRun(pShoes);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadShoesBike(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadShoesBike");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    bool fCur1 = false;
    COleDateTime tmCur;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CShoesBike* pShoes = new CShoesBike;
        if(NULL != pShoes)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetBrand(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetType(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pShoes->SetSize(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pShoes->SetFirstDay(tmCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pShoes->SetNotes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, fCur1);
            pShoes->SetRetired(fCur1);

            ReadSingleLine(fp);

            pUser->AddShoesBike(pShoes);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadBikes(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadBikes");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    bool fCur1 = false;
    COleDateTime tmCur;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CBike* pBike = new CBike;
        if(NULL != pBike)
        {
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, nCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pBike->SetBrand(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pBike->SetType(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, dCur1);
            pBike->SetSize(dCur1);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pBike->SetFirstDay(tmCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pBike->SetNotes(strCur);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, fCur1);
            pBike->SetRetired(fCur1);

            ReadSingleLine(fp);

            pUser->AddBike(pBike);
        }
    }

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLSerializer::ReadUpcomingRaces(CUser* pUser, FILE* fp, double dVersion)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadUpcomingRaces");
        return NULL;
    }

    bool fRes = true;
    COleDateTime tmCur;
    int nNum = 0;
    CString strCur;

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CUpcomingRace* pRace = new CUpcomingRace;
        if(NULL != pRace)
        {
            strLine = ReadSingleLine(fp);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pRace->SetDate(tmCur);
            
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pRace->SetLineOne(strCur);
           
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pRace->SetLineTwo(strCur);

			if(4.0 <=dVersion)
			{
				strLine = ReadSingleLine(fp);
				fRes &= ParseXML(strLine, strCur);
				pRace->SetLineThree(strCur);
			}

            ReadSingleLine(fp);

            // only add the race if it is in not in the past
            if(!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate()))
            {
                pUser->AddUpcomingRace(pRace);
            }
        }
    }

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLSerializer::ReadUpcomingWorkouts(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadUpcomingWorkouts");
        return NULL;
    }

    bool fRes = true;
    COleDateTime tmCur;
    int nNum = 0;
    CString strCur;

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CUpcomingWorkout* pWorkout = new CUpcomingWorkout;
        if(NULL != pWorkout)
        {
            strLine = ReadSingleLine(fp);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pWorkout->SetDate(tmCur);
            
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pWorkout->SetLineOne(strCur);
           
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pWorkout->SetLineTwo(strCur);

			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, strCur);
			pWorkout->SetLineThree(strCur);

            ReadSingleLine(fp);

            // only add the Workout if it is in not in the past
            if(!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pWorkout->GetDate()))
            {
                pUser->AddUpcomingWorkout(pWorkout);
            }
        }
    }

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLSerializer::ReadInjuries(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadInjuries");
        return NULL;
    }

    bool fRes = true;
	bool fCur = false;
    COleDateTime tmCur;
    int nNum = 0;
    CString strCur;

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        CInjury* pInjury = new CInjury;
        if(NULL != pInjury)
        {
            strLine = ReadSingleLine(fp);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pInjury->SetName(strCur);

			strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pInjury->SetStartDate(tmCur);

			strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pInjury->SetEndDate(tmCur);

			strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, fCur);
			pInjury->SetFinished(fCur);
           
            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, strCur);
            pInjury->SetDescription(strCur);

			strLine = ReadSingleLine(fp);
			fRes &= ParseXML(strLine, strCur);
			pInjury->SetTreatment(strCur);

            ReadSingleLine(fp);

            pUser->AddInjury(pInjury);
        }
    }

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLSerializer::ReadDays(CUser* pUser, FILE* fp)
{
    if((NULL == fp) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadDays");
        return NULL;
    }

    bool fRes = true;
    COleDateTime tmCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    CreateProgress(m_strPrependRead + "days" + m_strSpaces, max(1, nNum));

    for(int i = 0; i < nNum; i++)
    {
        CDayLog* pDay = new CDayLog;
        if(NULL != pDay)
        {
            strLine = ReadSingleLine(fp);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pDay->SetDate(tmCur);
            
            fRes &= ReadWorkouts(pUser, pDay, fp);

            ReadSingleLine(fp);

            pUser->SetDayAt(tmCur, pDay);
        }

        StepProgress();
    }

    DestroyProgress();

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLSerializer::ReadWorkouts(CUser* pUser, CDayLog* pDay, FILE* fp)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser))
    {
        CUtil::Fatal("Bad parameter to CXMLSerializer::ReadWorkouts");
        return NULL;
    }

    bool fRes = true;
    int nCur1 = 0;
    int nCur2 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1, nCur2);

        switch(nCur1)
        {
        case ACTIVITY_RUNNING:
            {
                switch(nCur2)
                {
                case RUNTYPE_EZ:
                    {
                        CRunEZWorkout* pWorkout = new CRunEZWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_HARD:
                    {
                        CRunHardWorkout* pWorkout = new CRunHardWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_HILLS:
                    {
                        CRunHillWorkout* pWorkout = new CRunHillWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_INTERVALS:
                    {
                        CRunIntervalWorkout* pWorkout = new CRunIntervalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_OTHER:
                    {
                        CRunMiscWorkout* pWorkout = new CRunMiscWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_NORMAL:
                    {
                        CRunNormalWorkout* pWorkout = new CRunNormalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_POOL:
                    {
                        CRunPoolWorkout* pWorkout = new CRunPoolWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_TEMPO:
                    {
                        CRunTempoWorkout* pWorkout = new CRunTempoWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RUNTYPE_TREADMILL:
                    {
                        CRunTreadmillWorkout* pWorkout = new CRunTreadmillWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                default:
                    {
                        fRes = false;
                        break;
                    }
                }
                break;
            }

        case ACTIVITY_BIKING:
            {
                switch(nCur2)
                {
                case BIKETYPE_EZ:
                    {
                        CBikeEZWorkout* pWorkout = new CBikeEZWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_HARD:
                    {
                        CBikeHardWorkout* pWorkout = new CBikeHardWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_HILLS:
                    {
                        CBikeHillWorkout* pWorkout = new CBikeHillWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_INTERVALS:
                    {
                        CBikeIntervalWorkout* pWorkout = new CBikeIntervalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_OTHER:
                    {
                        CBikeMiscWorkout* pWorkout = new CBikeMiscWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_NORMAL:
                    {
                        CBikeNormalWorkout* pWorkout = new CBikeNormalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_TRAINER:
                    {
                        CBikeTrainerWorkout* pWorkout = new CBikeTrainerWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_MOUNTAINBIKE:
                    {
                        CBikeMountainBikeWorkout* pWorkout = new CBikeMountainBikeWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case BIKETYPE_TIMETRIAL:
                    {
                        CBikeTimeTrialWorkout* pWorkout = new CBikeTimeTrialWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                default:
                    {
                        fRes = false;
                        break;
                    }
                }
                break;
            }

        case ACTIVITY_SWIMMING:
            {
                switch(nCur2)
                {
                case SWIMTYPE_DRILLS:
                    {
                        CSwimDrillWorkout* pWorkout = new CSwimDrillWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case SWIMTYPE_EZ:
                    {
                        CSwimEZWorkout* pWorkout = new CSwimEZWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case SWIMTYPE_HARD:
                    {
                        CSwimHardWorkout* pWorkout = new CSwimHardWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case SWIMTYPE_INTERVALS:
                    {
                        CSwimIntervalWorkout* pWorkout = new CSwimIntervalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case SWIMTYPE_OTHER:
                    {
                        CSwimMiscWorkout* pWorkout = new CSwimMiscWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case SWIMTYPE_NORMAL:
                    {
                        CSwimNormalWorkout* pWorkout = new CSwimNormalWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }


                case SWIMTYPE_OPENWATER:
                    {
                        CSwimOpenWaterWorkout* pWorkout = new CSwimOpenWaterWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                default:
                    {
                        fRes = false;
                        break;
                    }
                }
                break;
            }

        case ACTIVITY_STRENGTH:
            {
                switch(nCur2)
                {
                case STRENGTHTYPE_ABS:
                    {
                        CStrengthAbsWorkout* pWorkout = new CStrengthAbsWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case STRENGTHTYPE_OTHER:
                    {
                        CStrengthMiscWorkout* pWorkout = new CStrengthMiscWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case STRENGTHTYPE_WEIGHTS:
                    {
                        CStrengthWeightsWorkout* pWorkout = new CStrengthWeightsWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                default:
                    {
                        fRes = false;
                        break;
                    }
                }
                break;
            }

        case ACTIVITY_RACE:
            {
                switch(nCur2)
                {
                case RACETYPE_RUN:
                    {
                        CRaceRunWorkout* pWorkout = new CRaceRunWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RACETYPE_BIKE:
                    {
                        CRaceBikeWorkout* pWorkout = new CRaceBikeWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RACETYPE_SWIM:
                    {
                        CRaceSwimWorkout* pWorkout = new CRaceSwimWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RACETYPE_DUATHLON:
                    {
                        CRaceDuathlonWorkout* pWorkout = new CRaceDuathlonWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                case RACETYPE_TRIATHLON:
                    {
                        CRaceTriathlonWorkout* pWorkout = new CRaceTriathlonWorkout;
                        if(NULL != pWorkout)
                        {
                            fRes &= ReadWorkout(pUser, pWorkout, fp);
                            pDay->AddWorkout(pWorkout);
                        }
                        break;
                    }

                default:
                    {
                        fRes = false;
                        break;
                    }
                }
                break;
            }
            
        default:
            {
                fRes = false;
                break;
            }
        }

        ReadSingleLine(fp);
    }

    ReadSingleLine(fp);

    return fRes;
}
         

bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunEZWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

	strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunHardWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

	strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunHillWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunIntervalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetSpecialShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunMiscWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetCountedOnShoes(fCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunNormalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunPoolWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunTempoWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRunTreadmillWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationRun(pUser->GetLocationRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeEZWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeHardWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeHillWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeIntervalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetSpecialShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeMiscWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetCountedOnShoes(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetCountedOnBike(fCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeNormalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeTrainerWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetCountedOnShoes(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetCountedOnBike(fCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeMountainBikeWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CBikeTimeTrialWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationBike(pUser->GetLocationBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetSpecialShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimDrillWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimEZWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimHardWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimIntervalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimMiscWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimNormalWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

	strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CSwimOpenWaterWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationSwim(pUser->GetLocationSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CStrengthAbsWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

	strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationStrength(pUser->GetLocationStrengthFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CStrengthMiscWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationStrength(pUser->GetLocationStrengthFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CStrengthWeightsWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLocationStrength(pUser->GetLocationStrengthFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRaceRunWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetCourseRun(pUser->GetCourseRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRacePosition(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRaceNumber(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesRun(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetSpecialShoesRun(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRaceBikeWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);
    
    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetCourseBike(pUser->GetCourseBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRacePosition(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRaceNumber(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetWind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetShoesBike(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetSpecialShoesBike(pUser->GetShoesBikeFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRaceSwimWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetCourseSwim(pUser->GetCourseSwimFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetTemperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetHR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSpecialSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRacePosition(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRaceNumber(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetMiles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRaceDuathlonWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);
    
    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetCourseDuathlon(pUser->GetCourseDuathlonFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

	if(4.06 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, nCur);
		pWorkout->SetTemperature(nCur);

		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, nCur);
		pWorkout->SetHR(nCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRacePosition(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRaceNumber(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetTransition1Seconds(dCur);
    
    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetTransition2Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1Wind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1Shoes(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1RaceShoes(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Wind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Shoes(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2RaceShoes(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Wind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Shoes(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3RaceShoes(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


bool CXMLSerializer::ReadWorkout(CUser* pUser, CRaceTriathlonWorkout* pWorkout, FILE* fp)
{
    if((NULL == fp) || (NULL == pWorkout) || (NULL == pUser))
    {
        return false;
    }

    double dCur = 0.0;
    int nCur = 0;
    bool fCur = false;
    COleDateTime tmCur;
    CString strCur;
    CString strLine;
    bool fRes = true;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetDisplayName(strCur);
    
    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetBike(pUser->GetBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetWeight(dCur);

	if(4.03 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, strCur);
		pWorkout->SetDataFile(strCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmCur);
    pWorkout->SetTimeStart(tmCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetPrevNightSleep(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetCourseTriathlon(pUser->GetCourseTriathlonFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetSeconds(dCur);

	if(4.06 <= m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, nCur);
		pWorkout->SetTemperature(nCur);

		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, nCur);
		pWorkout->SetHR(nCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetLong(fCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fCur);
    pWorkout->SetInjured(fCur);

	if(4.0 <=m_dVersion)
	{
		strLine = ReadSingleLine(fp);
		fRes &= ParseXML(strLine, fCur);
		pWorkout->SetSick(fCur);
	}

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strCur);
    pWorkout->SetNotes(strCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRacePosition(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetRaceNumber(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetTransition1Seconds(dCur);
    
    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetTransition2Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg1Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetChoppiness(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg1HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg2Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Wind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2Shoes(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg2RaceShoes(pUser->GetShoesBikeFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3Seconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3RaceSeconds(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur);
    pWorkout->SetLeg3Miles(dCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Temperature(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Wind(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3HR(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3Shoes(pUser->GetShoesRunFromID(nCur));

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pWorkout->SetLeg3RaceShoes(pUser->GetShoesRunFromID(nCur));

    return fRes;
}


CString CXMLSerializer::EncryptXML(CString str)
{
    str.Replace("&", "&amp");
    str.Replace("\\r\\n", "&cr");
    str.Replace("%", "&pct");
    str.Replace("\"", "&quot");
    str.Replace("<", "&lt");
    str.Replace(">", "&gt");
    return str;
}


CString CXMLSerializer::DecryptXML(CString str)
{
    str.Replace("&gt", ">");
    str.Replace("&lt", "<");
    str.Replace("&quot", "\"");
    str.Replace("&pct", "%");
    str.Replace("&cr", "\\r\\n");
    str.Replace("&amp", "&");
    return str;
}


void CXMLSerializer::CreateProgress(CString strMessage, int nSteps)
{
    if(NULL != m_pProgress)
    {
        return;
    }
    m_pProgress = new CSkinProgress(strMessage, nSteps, cSPT_PERCENT, 1, 200);
}


void CXMLSerializer::DestroyProgress(void)
{
    if(NULL != m_pProgress)
    {
        delete m_pProgress;
        m_pProgress = NULL;
    }
}


void CXMLSerializer::StepProgress(void)
{
    if(NULL != m_pProgress)
    {
        m_pProgress->StepIt();
        PeekAndPump2();
    }
}


BOOL PeekAndPump2(void)
{
  static MSG msg;

  while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
  {
	  if(!AfxGetApp()->PumpMessage())
    {
		  ::PostQuitMessage(0);
		  return FALSE;
	  }	
  }

  return TRUE;
}