#include "StdAfx.h"
#include "RunningLog.h"
#include "CalendarCtl.h"
#include "DayLog.h"
#include "Util.h"
#include "Bike.h"
#include "UpcomingWorkout.h"
#include "UpcomingRace.h"
#include "User.h"


CUser::CUser(void)
{
    ResetDefaults();
    SetFirstName("");
    SetLastName("");
    SetRestingHR(0);
    SetHeight(0);
    SetSex(SEX_MALE);
    SetCurrentDate(COleDateTime::GetCurrentTime());
    SetHighlightDay(0);
	SetRunDecimals(CUtil::GetDefaultRunDecimals());
	SetBikeDecimals(CUtil::GetDefaultBikeDecimals());
	SetSwimDecimals(CUtil::GetDefaultSwimDecimals());
}


CUser::~CUser(void)
{
    CFont* pFontDay = GetDayFont();
    if(NULL != pFontDay)
    {
        delete pFontDay;
        pFontDay = NULL;
    }

    CFont* pFontHeading = GetHeadingFont();
    if(NULL != pFontHeading)
    {
        delete pFontHeading;
        pFontHeading = NULL;
    }

    CFont* pFontTitle = GetTitleFont();
    if(NULL != pFontTitle)
    {
        delete pFontTitle;
        pFontTitle = NULL;
    }

    CFont* pFontAnt = GetAnnotationFont();
    if(NULL != pFontAnt)
    {
        delete pFontAnt;
        pFontAnt = NULL;
    }

    CFont* pFontAntBold = GetAnnotationFontBold();
    if(NULL != pFontAntBold)
    {
        delete pFontAntBold;
        pFontAntBold = NULL;
    }

    COURSERUNARRAY& rarRunCourses = GetRefCourseRunArray();
    for(int i = 0; i < rarRunCourses.GetCount(); i++)
    {
        CCourseRun* pCourse = rarRunCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            delete pCourse;
            pCourse = NULL;
            rarRunCourses.SetAt(i, pCourse);
        }
    }
    rarRunCourses.RemoveAll();

    COURSEBIKEARRAY& rarBikeCourses = GetRefCourseBikeArray();
    for(int i = 0; i < rarBikeCourses.GetCount(); i++)
    {
        CCourseBike* pCourse = rarBikeCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            delete pCourse;
            pCourse = NULL;
            rarBikeCourses.SetAt(i, pCourse);
        }
    }
    rarBikeCourses.RemoveAll();

    COURSESWIMARRAY& rarSwimCourses = GetRefCourseSwimArray();
    for(int i = 0; i < rarSwimCourses.GetCount(); i++)
    {
        CCourseSwim* pCourse = rarSwimCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            delete pCourse;
            pCourse = NULL;
            rarSwimCourses.SetAt(i, pCourse);
        }
    }
    rarSwimCourses.RemoveAll();

    COURSEDUATHLONARRAY& rarDuathlonCourses = GetRefCourseDuathlonArray();
    for(int i = 0; i < rarDuathlonCourses.GetCount(); i++)
    {
        CCourseDuathlon* pCourse = rarDuathlonCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            delete pCourse;
            pCourse = NULL;
            rarDuathlonCourses.SetAt(i, pCourse);
        }
    }
    rarDuathlonCourses.RemoveAll();

    COURSETRIATHLONARRAY& rarTriathlonCourses = GetRefCourseTriathlonArray();
    for(int i = 0; i < rarTriathlonCourses.GetCount(); i++)
    {
        CCourseTriathlon* pCourse = rarTriathlonCourses.ElementAt(i);
        if(NULL != pCourse)
        {
            delete pCourse;
            pCourse = NULL;
            rarTriathlonCourses.SetAt(i, pCourse);
        }
    }
    rarTriathlonCourses.RemoveAll();

    LOCATIONRUNARRAY& rarRunLocations = GetRefLocationRunArray();
    for(int i = 0; i < rarRunLocations.GetCount(); i++)
    {
        CLocationRun* pLocation = rarRunLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            delete pLocation;
            pLocation = NULL;
            rarRunLocations.SetAt(i, pLocation);
        }
    }  
    rarRunLocations.RemoveAll();

    LOCATIONBIKEARRAY& rarBikeLocations = GetRefLocationBikeArray();
    for(int i = 0; i < rarBikeLocations.GetCount(); i++)
    {
        CLocationBike* pLocation = rarBikeLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            delete pLocation;
            pLocation = NULL;
            rarBikeLocations.SetAt(i, pLocation);
        }
    } 
    rarBikeLocations.RemoveAll();

    LOCATIONSWIMARRAY& rarSwimLocations = GetRefLocationSwimArray();
    for(int i = 0; i < rarSwimLocations.GetCount(); i++)
    {
        CLocationSwim* pLocation = rarSwimLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            delete pLocation;
            pLocation = NULL;
            rarSwimLocations.SetAt(i, pLocation);
        }
    } 
    rarSwimLocations.RemoveAll();

    LOCATIONSTRENGTHARRAY& rarStrengthLocations = GetRefLocationStrengthArray();
    for(int i = 0; i < rarStrengthLocations.GetCount(); i++)
    {
        CLocationStrength* pLocation = rarStrengthLocations.ElementAt(i);
        if(NULL != pLocation)
        {
            delete pLocation;
            pLocation = NULL;
            rarStrengthLocations.SetAt(i, pLocation);
        }
    } 
    rarStrengthLocations.RemoveAll();

    SHOESRUNARRAY& rarRunShoes = GetRefShoesRunArray();
    for(int i = 0; i < rarRunShoes.GetCount(); i++)
    {
        CShoesRun* pShoes = rarRunShoes.ElementAt(i);
        if(NULL != pShoes)
        {
            delete pShoes;
            pShoes = NULL;
            rarRunShoes.SetAt(i, pShoes);
        }
    } 
    rarRunShoes.RemoveAll();
    
    SHOESBIKEARRAY& rarBikeShoes = GetRefShoesBikeArray();
    for(int i = 0; i < rarBikeShoes.GetCount(); i++)
    {
        CShoesBike* pShoes = rarBikeShoes.ElementAt(i);
        if(NULL != pShoes)
        {
            delete pShoes;
            pShoes = NULL;
            rarBikeShoes.SetAt(i, pShoes);
        }
    }  
    rarBikeShoes.RemoveAll();

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            delete pDay;
            pDay = NULL;
            rarDays.SetAt(i, pDay);
        }
    }  
    rarDays.RemoveAll();

    BIKEARRAY& rarBikes = GetRefBikeArray();
    for(int i = 0; i < rarBikes.GetCount(); i++)
    {
        CBike* pBike = rarBikes.ElementAt(i);
        if(NULL != pBike)
        {
            delete pBike;
            pBike = NULL;
            rarBikes.SetAt(i, pBike);
        }
    }  
    rarBikes.RemoveAll();

    UPCOMINGRACEARRAY& rarUpcomingRaces = GetRefUpcomingRaceArray();
    for(int i = 0; i < rarUpcomingRaces.GetCount(); i++)
    {
        CUpcomingRace* pUpcoming = rarUpcomingRaces.ElementAt(i);
        if(NULL != pUpcoming)
        {
            delete pUpcoming;
            pUpcoming = NULL;
            rarUpcomingRaces.SetAt(i, pUpcoming);
        }
    }  
    rarUpcomingRaces.RemoveAll();

    UPCOMINGWORKOUTARRAY& rarUpcomingWorkouts = GetRefUpcomingWorkoutArray();
    for(int i = 0; i < rarUpcomingWorkouts.GetCount(); i++)
    {
        CUpcomingWorkout* pUpcoming = rarUpcomingWorkouts.ElementAt(i);
        if(NULL != pUpcoming)
        {
            delete pUpcoming;
            pUpcoming = NULL;
            rarUpcomingWorkouts.SetAt(i, pUpcoming);
        }
    }  
    rarUpcomingWorkouts.RemoveAll();

    INJURYARRAY& rarInjuries = GetRefInjuryArray();
    for(int i = 0; i < rarInjuries.GetCount(); i++)
    {
        CInjury* pInjury = rarInjuries.ElementAt(i);
        if(NULL != pInjury)
        {
            delete pInjury;
            pInjury = NULL;
            rarInjuries.SetAt(i, pInjury);
        }
    }  
    rarInjuries.RemoveAll();
}


void CUser::ResetDefaults(void)
{
    SetBgColor(CUtil::GetDefaultBgColor());
    SetDayColor(DAYTYPE_NORMAL, CUtil::GetDefaultDayColor(DAYTYPE_NORMAL));
    SetDayColor(DAYTYPE_GRAYED, CUtil::GetDefaultDayColor(DAYTYPE_GRAYED));
    SetDayColor(DAYTYPE_MONTHSUM, CUtil::GetDefaultDayColor(DAYTYPE_MONTHSUM));
    SetDayColor(DAYTYPE_WEEKSUM, CUtil::GetDefaultDayColor(DAYTYPE_WEEKSUM));
    SetButtonColor(CUtil::GetDefaultButtonColor());  
    SetHighlightColor(CUtil::GetDefaultHighlightColor());
    SetShadowColor(true, CUtil::GetDefaultShadowColor(true));
    SetShadowColor(false, CUtil::GetDefaultShadowColor(false));
    SetHeadingTextColor(CUtil::GetDefaultHeadingTextColor());
    SetDayTextColor(CUtil::GetDefaultDayTextColor());
    SetAnnotationTextColor(CUtil::GetDefaultAnnotationTextColor());
    SetGradientColor(true, CUtil::GetDefaultGradientColor(true));
    SetGradientColor(false, CUtil::GetDefaultGradientColor(false));
	SetRaceDayColor(CUtil::GetDefaultRaceDayColor());
	SetUpcomingRaceDayColor(CUtil::GetDefaultUpcomingRaceDayColor());
	SetUpcomingWorkoutDayColor(CUtil::GetDefaultUpcomingWorkoutDayColor());
	SetEditBgColor(CUtil::GetDefaultEditBgColor());
    SetBaseTypeRun(CUtil::GetDefaultBaseTypeRun());
    SetBaseTypeBike(CUtil::GetDefaultBaseTypeBike());
    SetBaseTypeSwim(CUtil::GetDefaultBaseTypeSwim());
    SetDisplayInfoRun(CUtil::GetDefaultDisplayInfo(ACTIVITY_RUNNING));
    SetDisplayInfoBike(CUtil::GetDefaultDisplayInfo(ACTIVITY_BIKING));
    SetDisplayInfoSwim(CUtil::GetDefaultDisplayInfo(ACTIVITY_SWIMMING));
    SetDisplayInfoStrength(CUtil::GetDefaultDisplayInfo(ACTIVITY_STRENGTH));
    SetDisplayInfoRace(CUtil::GetDefaultDisplayInfo(ACTIVITY_RACE));
    SetPaceFormatRun(CUtil::GetDefaultPaceFormatRun());
    SetPaceFormatBike(CUtil::GetDefaultPaceFormatBike());
    SetPaceFormatSwim(CUtil::GetDefaultPaceFormatSwim());

    unsigned __int64 i64All = 0xffffffffffffffff;
    SetMandatoryRunFields(i64All);
    SetMandatoryBikeFields(i64All);
    SetMandatorySwimFields(i64All);
    SetMandatoryStrengthFields(i64All);
    SetMandatoryRaceRunFields(i64All);
    SetMandatoryRaceBikeFields(i64All);
    SetMandatoryRaceSwimFields(i64All);
    SetMandatoryRaceDuathlonFields(i64All);
    SetMandatoryRaceTriathlonFields(i64All);
    SetMandatoryStartFields(i64All);

    SetRunDistUnits(DISTUNITS_MI);
    SetBikeDistUnits(DISTUNITS_MI);
    SetSwimDistUnits(DISTUNITS_MI);
    SetHeightUnits(HEIGHTUNITS_IN);
    SetWeightUnits(WEIGHTUNITS_LBS);
    SetTempUnits(TEMPUNITS_DEG);

    SetFirstDayOfWeek(MONDAY);

    CFont* pFontDay = new CFont;
    if(NULL != pFontDay)
    {
        pFontDay->DeleteObject();
        pFontDay->CreateFont(15, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
    }
    CFont* pFontHeading = new CFont;
    if(NULL != pFontHeading)
    {
        pFontHeading->DeleteObject();
        pFontHeading->CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
    }
    CFont* pFontTitle = new CFont;
    if(NULL != pFontTitle)
    {
        pFontTitle->DeleteObject();
        pFontTitle->CreateFont(48, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
    }

    CFont* pFontAnnotation = new CFont;
    if(NULL != pFontAnnotation)
    {
        pFontAnnotation->DeleteObject();
        pFontAnnotation->CreateFont(14, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
    }

    CFont* pFontAnnotationBold = new CFont;
    if(NULL != pFontAnnotationBold)
    {
        pFontAnnotationBold->DeleteObject();
        pFontAnnotationBold->CreateFont(14, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
    }

    SetDayFont(pFontDay);
    SetHeadingFont(pFontHeading);
    SetTitleFont(pFontTitle);
    SetAnnotationFont(pFontAnnotation);
    SetAnnotationFontBold(pFontAnnotationBold);

	SetDlgAnimationTime(CUtil::GetDefaultDlgAnimationTime());
	SetRunDecimals(CUtil::GetDefaultRunDecimals());
	SetBikeDecimals(CUtil::GetDefaultBikeDecimals());
	SetSwimDecimals(CUtil::GetDefaultSwimDecimals());
}


CDayLog* CUser::GetDayAt(COleDateTime tmDay)
{
    DAYARRAY& rarDays = GetRefDayArray();

    int n = m_mapHash[HashDay(tmDay)];
    if(0 == n)
    {
        return NULL;
    }

    return rarDays.GetAt(n - 1);
}


CDayLog* CUser::GetDayAtCreate(COleDateTime tmDay)
{
    CDayLog* pDay = GetDayAt(tmDay);
    if(NULL == pDay)
    {
        DAYARRAY& rarDays = GetRefDayArray();
        m_mapHash[HashDay(tmDay)] = (int)rarDays.GetCount() + 1;
        pDay = new CDayLog;
        if(NULL != pDay)
        {
            pDay->SetDate(tmDay);
            rarDays.SetAtGrow(rarDays.GetCount(), pDay);
        }
    }
    
    return pDay;
}


void CUser::SetDayAt(COleDateTime tm, CDayLog* pDay)
{
    // the time better be in the map, or we won't add it
    int n = m_mapHash[HashDay(tm)];
    if(0 != n)
    {
        DAYARRAY& rarDays = GetRefDayArray();
        rarDays.SetAtGrow(n - 1, pDay);
    }
}


CUpcomingRace* CUser::GetUpcomingRaceAt(COleDateTime tmDay)
{
    UPCOMINGRACEARRAY& rarRaces = GetRefUpcomingRaceArray();
    for(int i = 0; i < (int)rarRaces.GetCount(); i++)
    {
        CUpcomingRace* pRace = rarRaces.GetAt(i);
        if((NULL != pRace) && (CUtil::IsSameDay(tmDay, pRace->GetDate())))
        {
            return pRace;
        }
    }

    return NULL;
}


CUpcomingWorkout* CUser::GetUpcomingWorkoutAt(COleDateTime tmDay)
{
    UPCOMINGWORKOUTARRAY& rarWorkouts = GetRefUpcomingWorkoutArray();
    for(int i = 0; i < (int)rarWorkouts.GetCount(); i++)
    {
        CUpcomingWorkout* pWorkout = rarWorkouts.GetAt(i);
        if((NULL != pWorkout) && (CUtil::IsSameDay(tmDay, pWorkout->GetDate())))
        {
            return pWorkout;
        }
    }

    return NULL;
}


int CUser::HashDay(COleDateTime tm)
{
    return ((tm.GetYear() - 1900) * 600 + tm.GetMonth() * 40 + tm.GetDay());
}


void CUser::GetTimeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                         int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        rardVals.Add(tmCur.m_dt);
	}
}


void CUser::GetMinutesRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                               int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumSecondsRun(tmCur, nIncr);
        double dVal = dCur / (60.0 * (double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetMinutesBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                               int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumSecondsBike(tmCur, nIncr);
        double dVal = dCur / (60.0 * (double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetMinutesSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumSecondsSwim(tmCur, nIncr);
        double dVal = dCur / (60.0 * (double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetMinutesStrengthArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                    int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumSecondsStrength(tmCur, nIncr);
        double dVal = dCur / (60.0 * (double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetMinutesOverallArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                   int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur1 = SumSecondsRun(tmCur, nIncr);
        double dCur2 = SumSecondsBike(tmCur, nIncr);
        double dCur3 = SumSecondsSwim(tmCur, nIncr);
        double dCur4 = SumSecondsStrength(tmCur, nIncr);
        double dVal = 0.0;
        bool bAdd = false;
        if(CUtil::HasData(dCur1))
        {
            dVal += dCur1;
            bAdd = true;
        }
        if(CUtil::HasData(dCur2))
        {
            dVal += dCur2;
            bAdd = true;
        }
        if(CUtil::HasData(dCur3))
        {
            dVal += dCur3;
            bAdd = true;
        }
        if(CUtil::HasData(dCur4))
        {
            dVal += dCur4;
            bAdd = true;
        }
        dVal /= (60.0 * (double)nIncr);
          
		if(false == bAdd)
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetMilesRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumMilesRun(tmCur, nIncr);
        double dVal = dCur / ((double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetMilesBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumMilesBike(tmCur, nIncr);
        double dVal = dCur / ((double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetMilesSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                              int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur = SumMilesSwim(tmCur, nIncr);
        double dVal = dCur / ((double)nIncr);

		if(CUtil::HasNoData(dCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetTemperatureArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iCur = GetAverageTemperature(tmCur, nIncr);
        double dVal = (double)iCur;

		if(CUtil::HasNoData(iCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetHRArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                       int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iCur = GetAverageHR(tmCur, nIncr);
        double dVal = (double)iCur;

		if(CUtil::HasNoData(iCur))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetPaceRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageRunPace(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetPaceBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageBikePace(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetPaceSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                             int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageSwimPace(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetPointsArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                           int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dCur1 = SumMilesRun(tmCur, nIncr);
        double dCur2 = SumMilesBike(tmCur, nIncr);
        double dCur3 = SumMilesSwim(tmCur, nIncr);
        double dCur4 = SumMinutesStrength(tmCur, nIncr);
        double dVal = 0.0;
        bool bAdd = false;
        if(CUtil::HasData(dCur1))
        {
            dVal += dCur1 * 4.0;
            bAdd = true;
        }
        if(CUtil::HasData(dCur2))
        {
            dVal += dCur2;
            bAdd = true;
        }
        if(CUtil::HasData(dCur3))
        {
            dVal += dCur3 * 16.0;
            bAdd = true;
        }
        if(CUtil::HasData(dCur4))
        {
            dVal += dCur4;
            bAdd = true;
        }
        dVal /= ((double)nIncr);
            
		if(false == bAdd)
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
    }
}


void CUser::GetSleepArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageSleep(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWeightArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageWeight(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWorkoutRunArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iVal = SumWorkoutsRun(tmCur, nIncr);
		double dVal = (double)iVal / (double)nIncr;

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWorkoutBikeArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iVal = SumWorkoutsBike(tmCur, nIncr);
		double dVal = (double)iVal / (double)nIncr;

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWorkoutSwimArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iVal = SumWorkoutsSwim(tmCur, nIncr);
		double dVal = (double)iVal / (double)nIncr;

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWorkoutStrengthArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                    int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iVal = SumWorkoutsStrength(tmCur, nIncr);
		double dVal = (double)iVal / (double)nIncr;

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetWorkoutOverallArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                                   int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        int iVal = SumWorkoutsRun(tmCur, nIncr) + SumWorkoutsBike(tmCur, nIncr) + 
                      SumWorkoutsSwim(tmCur, nIncr) + SumWorkoutsStrength(tmCur, nIncr);
		double dVal = (double)iVal / (double)nIncr;

        rardVals.Add(dVal);
    }
}


void CUser::GetCalorieArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                            int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageCalories(tmCur, nIncr);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(dVal);
		}
	}
}


void CUser::GetTimeOfDayArray(CArray<double>& rardVals, COleDateTime tmFrom, COleDateTime tmTo, int nDays, 
                              int nPoints, int nIncr, int nNullValue)
{
    COleDateTime tmCur;

    for(int i = 0; i < nPoints; i++)
    {
        tmCur = CUtil::OffsetDay(tmFrom, i * nIncr);
        double dVal = GetAverageTimeOfDay(tmCur, nIncr);
        COleDateTime tmVal = CUtil::Time24HoursToDateTime(dVal);

		if(CUtil::HasNoData(dVal))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			rardVals.Add(tmVal.m_dt);
		}
	}
}


int CUser::GetAverageTemperature(COleDateTime tmStart, int nDays)
{
    double dTemp = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->GetAverageTemperature();
            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dTemp += dCur;
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (int)(dTemp / (double)nDefined);
    }
}


int CUser::GetAverageHR(COleDateTime tmStart, int nDays)
{
    double dHR = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
		COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);

        if(NULL != pDay)
        {
            double dCur = pDay->GetAverageHR();

            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dHR += dCur;		
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (int)(dHR / (double)nDefined);
    }
}


double CUser::GetAverageRunPace(COleDateTime tmStart, int nDays)
{
    double dSeconds = SumRunSecondsWithMiles(tmStart, nDays);
    double dMiles = SumMilesRun(tmStart, nDays);

    int nFmt = GetPaceFormatRun();
    int nUnits = GetRunDistUnits();

    return GetPaceWithFormat(dSeconds, dMiles, nFmt, nUnits);
}


double CUser::GetAverageBikePace(COleDateTime tmStart, int nDays)
{
    double dSeconds = SumBikeSecondsWithMiles(tmStart, nDays);
    double dMiles = SumMilesBike(tmStart, nDays);

    int nFmt = GetPaceFormatBike();
    int nUnits = GetBikeDistUnits();

    return GetPaceWithFormat(dSeconds, dMiles, nFmt, nUnits);
}


double CUser::GetAverageSwimPace(COleDateTime tmStart, int nDays)
{
    double dSeconds = SumSwimSecondsWithMiles(tmStart, nDays);
    double dMiles = SumMilesSwim(tmStart, nDays);

    int nFmt = GetPaceFormatSwim();
    int nUnits = GetSwimDistUnits();

    return GetPaceWithFormat(dSeconds, dMiles, nFmt, nUnits);
}


double CUser::GetAverageSleep(COleDateTime tmStart, int nDays)
{
    double dSleep = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->GetAverageSleep();
            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dSleep += dCur;
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dSleep / (double)nDefined);
    }
}


double CUser::GetAverageWeight(COleDateTime tmStart, int nDays)
{
    double dWeight = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->GetAverageWeight();
            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dWeight += dCur;
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dWeight / (double)nDefined);
    }
}


double CUser::GetAveragePoints(COleDateTime tmStart, int nDays)
{
	double dPoints = 0.0;
	int nDefined = 0;

    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
			double dCur1 = pDay->SumMilesRun();
			double dCur2 = pDay->SumMilesBike();
			double dCur3 = pDay->SumMilesSwim();
			double dCur4 = pDay->SumSecondsStrength() / 60.0;
			double dVal = 0.0;
			bool bAdd = false;
			if(CUtil::HasData(dCur1))
			{
				dVal += dCur1 * 4.0;
				bAdd = true;
			}
			if(CUtil::HasData(dCur2))
			{
				dVal += dCur2;
				bAdd = true;
			}
			if(CUtil::HasData(dCur3))
			{
				dVal += dCur3 * 16.0;
				bAdd = true;
			}
			if(CUtil::HasData(dCur4))
			{
				dVal += dCur4;
				bAdd = true;
			}
			
			if(true == bAdd)
			{
				dPoints += dVal;
				nDefined++;
			}
		}
	}

    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dPoints / (double)nDefined);
    }
}


double CUser::GetAverageCalories(COleDateTime tmStart, int nDays)
{
    double dCalories = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->GetTotalCalories();
            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dCalories += dCur;
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dCalories / (double)nDefined);
    }
}


double CUser::GetAverageTimeOfDay(COleDateTime tmStart, int nDays)
{
    double dTime = 0.0;
    int nDefined = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->GetAverageTimeOfDay();
            if(CUtil::HasData(dCur))
            {
                nDefined++;
                dTime += dCur;
            }
        }
    }
    if(0 == nDefined)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTime / (double)nDefined);
    }
}


double CUser::GetPaceWithFormat(double dSeconds, double dDist, int nFmt, int nUnits)
{
	if(CUtil::HasNoData(dSeconds) || CUtil::HasNoData(dDist))
    {
        return NOGRAPHDATA;
    }

    double dTotalMin = dSeconds / 60.0;
    double dTotalHrs = dSeconds / 3600.0;

    if(PACEFORMAT_MINDIST == nFmt)
    {
        if(0.0 == dDist)
        {
            return NOGRAPHDATA;
        }
        else
        {
            return dTotalMin / dDist;
        }
    }

    else if(PACEFORMAT_DISTHR == nFmt)
    {
        if(0.0 == dTotalHrs)
        {
            return NOGRAPHDATA;
        }
        else
        {
            return dDist / dTotalHrs;
        }
    }

    else if(PACEFORMAT_MIN100M == nFmt)
    {
        // convert what we have to km, then divide by 10 to get 100m
        double d100s = CUtil::ConvertDistance(nUnits, DISTUNITS_KM, dDist) / 10.0;
        if(0.0 == d100s)
        {
            return NOGRAPHDATA;
        }
        else
        {
            return dTotalMin / d100s;
        }
    }

    else if(PACEFORMAT_MIN100Y == nFmt)
    {
        // convert what we have to yards, then divide by 100 to get 100 yards
        double d100s = CUtil::ConvertDistance(nUnits, DISTUNITS_YD, dDist) / 100.0;
        if(0.0 == d100s)
        {
            return NOGRAPHDATA;
        }
        else
        {
            return dTotalMin / d100s;
        }
    }

    else
    {
        CUtil::Fatal("Bad parameter to CUser::GetPaceWithFormat");
        return NOGRAPHDATA;
    }
}


int CUser::SumTotalWorkouts(COleDateTime tmStart, int nDays)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumTotalWorkouts();
        }
    }

    return nNum;
}


int CUser::SumWorkoutsRun(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsRun(nActivity, nType);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsRun(CShoesRun* pShoes)
{
    int nNum = 0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsRun(pShoes);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsBike(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsBike(nActivity, nType);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsBike(CShoesBike* pShoes)
{
    int nNum = 0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsBike(pShoes);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsBike(CBike* pBike)
{
    int nNum = 0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsBike(pBike);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsSwim(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsSwim(nActivity, nType);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsStrength(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsStrength(nActivity, nType);
        }
    }

    return nNum;
}


int CUser::SumWorkoutsRace(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    int nNum = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            nNum += pDay->SumWorkoutsRace(nActivity, nType);
        }
    }

    return nNum;
}


double CUser::SumSecondsRun(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsRun(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsRun(CShoesRun* pShoes)
{
    double dSec = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsRun(pShoes);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsBike(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsBike(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsBike(CShoesBike* pShoes)
{
    double dSec = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsBike(pShoes);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsBike(CBike* pBike)
{
    double dSec = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsBike(pBike);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsSwim(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsSwim(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSecondsStrength(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSecondsStrength(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumMinutesRun(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dCur = SumSecondsRun(tmStart, nDays, nActivity, nType);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesRun(CShoesRun* pShoes)
{
    double dCur = SumSecondsRun(pShoes);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesBike(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dCur = SumSecondsBike(tmStart, nDays, nActivity, nType);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesBike(CShoesBike* pShoes)
{
    double dCur = SumSecondsBike(pShoes);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesBike(CBike* pBike)
{
    double dCur = SumSecondsBike(pBike);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesSwim(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dCur = SumSecondsSwim(tmStart, nDays, nActivity, nType);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumMinutesStrength(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /*= -1 */)
{
    double dCur = SumSecondsStrength(tmStart, nDays, nActivity, nType);
	if(CUtil::HasNoData(dCur))
    {
        return NOGRAPHDATA;
    }
    else
    {
        return dCur / 60.0;
    }
}


double CUser::SumRunSecondsWithMiles(COleDateTime tmStart, int nDays)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumRunSecondsWithMiles();
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumBikeSecondsWithMiles(COleDateTime tmStart, int nDays)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumBikeSecondsWithMiles();
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumSwimSecondsWithMiles(COleDateTime tmStart, int nDays)
{
    double dSec = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumSwimSecondsWithMiles();
            if(CUtil::HasData(dCur))
            {
                dSec += dCur;
            }
        }
    }

    return dSec;
}


double CUser::SumMilesRun(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesRun(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


double CUser::SumMilesRun(CShoesRun* pShoes)
{
    double dMiles = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesRun(pShoes);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


double CUser::SumMilesBike(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesBike(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


double CUser::SumMilesBike(CShoesBike* pShoes)
{
    double dMiles = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesBike(pShoes);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


double CUser::SumMilesBike(CBike* pBike)
{
    double dMiles = 0.0;
    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.ElementAt(i);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesBike(pBike);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


double CUser::SumMilesSwim(COleDateTime tmStart, int nDays, int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(NULL != pDay)
        {
            double dCur = pDay->SumMilesSwim(nActivity, nType);
            if(CUtil::HasData(dCur))
            {
                dMiles += dCur;
            }
        }
    }

    return dMiles;
}


COleDateTime CUser::GetEarliestDay(void)
{
    COleDateTime tm;
    tm.SetStatus(COleDateTime::null);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmCur = pDay->GetDate();
            if((COleDateTime::null == tm.GetStatus()) || CUtil::IsLaterThan(tm, tmCur))
            {
                tm = tmCur;
            }
        }
    }

    if(COleDateTime::null == tm.GetStatus())
    {
        tm = tm.GetCurrentTime();
    }

    return tm;
}


COleDateTime CUser::GetLatestDay(void)
{
    COleDateTime tm;
    tm.SetStatus(COleDateTime::null);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmCur = pDay->GetDate();
            if((COleDateTime::null == tm.GetStatus()) || CUtil::IsLaterThan(tmCur, tm))
            {
                tm = tmCur;
            }
        }
    }

    if(COleDateTime::null == tm.GetStatus())
    {
        tm = tm.GetCurrentTime();
    }

    return tm;
}


int CUser::GetCompleteRestDays(COleDateTime tmStart, int nDays)
{
    int nTotal = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(((NULL != pDay) && (pDay->IsCompleteRestDay())) || (NULL == pDay))
        {
            nTotal++;
        }
    }

    return nTotal;
}


int CUser::GetNoRunningDays(COleDateTime tmStart, int nDays)
{
    int nTotal = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(((NULL != pDay) && (pDay->IsNoRunningDay())) || (NULL == pDay))
        {
            nTotal++;
        }
    }

    return nTotal;
}


int CUser::GetNoBikingDays(COleDateTime tmStart, int nDays)
{
    int nTotal = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(((NULL != pDay) && (pDay->IsNoBikingDay())) || (NULL == pDay))
        {
            nTotal++;
        }
    }

    return nTotal;
}


int CUser::GetNoSwimmingDays(COleDateTime tmStart, int nDays)
{
    int nTotal = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(((NULL != pDay) && (pDay->IsNoSwimmingDay())) || (NULL == pDay))
        {
            nTotal++;
        }
    }

    return nTotal;
}


int CUser::GetNoStrengthDays(COleDateTime tmStart, int nDays)
{
    int nTotal = 0;
    for(int i = 0; i < nDays; i++)
    {
        COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
        CDayLog* pDay = GetDayAt(tmCur);
        if(((NULL != pDay) && (pDay->IsNoStrengthDay())) || (NULL == pDay))
        {
            nTotal++;
        }
    }

    return nTotal;
}


void CUser::AddCourseRun(CCourseRun* pCourse)
{
    if(NULL != pCourse)
    {
        COURSERUNARRAY& rarCourses = GetRefCourseRunArray();
        rarCourses.Add(pCourse);
    }
}


void CUser::AddCourseBike(CCourseBike* pCourse)
{
    if(NULL != pCourse)
    {
        COURSEBIKEARRAY& rarCourses = GetRefCourseBikeArray();
        rarCourses.Add(pCourse);
    }
}


void CUser::AddCourseSwim(CCourseSwim* pCourse)
{
    if(NULL != pCourse)
    {
        COURSESWIMARRAY& rarCourses = GetRefCourseSwimArray();
        rarCourses.Add(pCourse);
    }
}


void CUser::AddCourseDuathlon(CCourseDuathlon* pCourse)
{
    if(NULL != pCourse)
    {
        COURSEDUATHLONARRAY& rarCourses = GetRefCourseDuathlonArray();
        rarCourses.Add(pCourse);
    }
}


void CUser::AddCourseTriathlon(CCourseTriathlon* pCourse)
{
    if(NULL != pCourse)
    {
        COURSETRIATHLONARRAY& rarCourses = GetRefCourseTriathlonArray();
        rarCourses.Add(pCourse);
    }
}


void CUser::AddLocationRun(CLocationRun* pLocation)
{
    if(NULL != pLocation)
    {
        LOCATIONRUNARRAY& rarLocations = GetRefLocationRunArray();
        rarLocations.Add(pLocation);
    }
}


void CUser::AddLocationBike(CLocationBike* pLocation)
{
    if(NULL != pLocation)
    {
        LOCATIONBIKEARRAY& rarLocations = GetRefLocationBikeArray();
        rarLocations.Add(pLocation);
    }
}


void CUser::AddLocationSwim(CLocationSwim* pLocation)
{
    if(NULL != pLocation)
    {
        LOCATIONSWIMARRAY& rarLocations = GetRefLocationSwimArray();
        rarLocations.Add(pLocation);
    }
}


void CUser::AddLocationStrength(CLocationStrength* pLocation)
{
    if(NULL != pLocation)
    {
        LOCATIONSTRENGTHARRAY& rarLocations = GetRefLocationStrengthArray();
        rarLocations.Add(pLocation);
    }
}


void CUser::AddShoesRun(CShoesRun* pShoes)
{
    if(NULL != pShoes)
    {
        SHOESRUNARRAY& rarShoes = GetRefShoesRunArray();
        rarShoes.Add(pShoes);
    }
}


void CUser::AddBike(CBike* pBike)
{
    if(NULL != pBike)
    {
        BIKEARRAY& rarBikes = GetRefBikeArray();
        rarBikes.Add(pBike);
    }
}


void CUser::AddShoesBike(CShoesBike* pShoes)
{
    if(NULL != pShoes)
    {
        SHOESBIKEARRAY& rarShoes = GetRefShoesBikeArray();
        rarShoes.Add(pShoes);
    }
}


void CUser::AddUpcomingRace(CUpcomingRace* pRace)
{
    if(NULL != pRace)
    {
        UPCOMINGRACEARRAY& rarRaces = GetRefUpcomingRaceArray();
        rarRaces.Add(pRace);
    }
}


void CUser::AddUpcomingWorkout(CUpcomingWorkout* pWorkout)
{
    if(NULL != pWorkout)
    {
        UPCOMINGWORKOUTARRAY& rarWorkouts = GetRefUpcomingWorkoutArray();
        rarWorkouts.Add(pWorkout);
    }
}


void CUser::AddInjury(CInjury* pInjury)
{
    if(NULL != pInjury)
    {
        INJURYARRAY& rarInjuries = GetRefInjuryArray();
        rarInjuries.Add(pInjury);
    }
}


int CUser::GetIDFromCourseRun(CCourseRun* pCourse)
{
    COURSERUNARRAY& rarCourses = GetRefCourseRunArray();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseRun* pCurCourse = rarCourses.ElementAt(i);
        if(pCurCourse == pCourse)
        {
            return i;
        }
    }

    return -1;
}


int CUser::GetIDFromCourseBike(CCourseBike* pCourse)
{
    COURSEBIKEARRAY& rarCourses = GetRefCourseBikeArray();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseBike* pCurCourse = rarCourses.ElementAt(i);
        if(pCurCourse == pCourse)
        {
            return i;
        }
    }

    return -1;
}


int CUser::GetIDFromCourseSwim(CCourseSwim* pCourse)
{
    COURSESWIMARRAY& rarCourses = GetRefCourseSwimArray();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseSwim* pCurCourse = rarCourses.ElementAt(i);
        if(pCurCourse == pCourse)
        {
            return i;
        }
    }

    return -1;
}


int CUser::GetIDFromCourseDuathlon(CCourseDuathlon* pCourse)
{
    COURSEDUATHLONARRAY& rarCourses = GetRefCourseDuathlonArray();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseDuathlon* pCurCourse = rarCourses.ElementAt(i);
        if(pCurCourse == pCourse)
        {
            return i;
        }
    }

    return -1;
}


int CUser::GetIDFromCourseTriathlon(CCourseTriathlon* pCourse)
{
    COURSETRIATHLONARRAY& rarCourses = GetRefCourseTriathlonArray();
    for(int i = 0; i < rarCourses.GetCount(); i++)
    {
        CCourseTriathlon* pCurCourse = rarCourses.ElementAt(i);
        if(pCurCourse == pCourse)
        {
            return i;
        }
    }

    return -1;
}


int CUser::GetIDFromLocationRun(CLocationRun* pLocation)
{
    LOCATIONRUNARRAY& rarLocations = GetRefLocationRunArray();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationRun* pCurLocation = rarLocations.ElementAt(i);
        if(pCurLocation == pLocation)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromLocationBike(CLocationBike* pLocation)
{
    LOCATIONBIKEARRAY& rarLocations = GetRefLocationBikeArray();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationBike* pCurLocation = rarLocations.ElementAt(i);
        if(pCurLocation == pLocation)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromLocationSwim(CLocationSwim* pLocation)
{
    LOCATIONSWIMARRAY& rarLocations = GetRefLocationSwimArray();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationSwim* pCurLocation = rarLocations.ElementAt(i);
        if(pCurLocation == pLocation)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromLocationStrength(CLocationStrength* pLocation)
{
    LOCATIONSTRENGTHARRAY& rarLocations = GetRefLocationStrengthArray();
    for(int i = 0; i < rarLocations.GetCount(); i++)
    {
        CLocationStrength* pCurLocation = rarLocations.ElementAt(i);
        if(pCurLocation == pLocation)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromShoesRun(CShoesRun* pShoes)
{
    SHOESRUNARRAY& rarShoes = GetRefShoesRunArray();
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesRun* pCurShoes = rarShoes.ElementAt(i);
        if(pCurShoes == pShoes)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromShoesBike(CShoesBike* pShoes)
{
    SHOESBIKEARRAY& rarShoes = GetRefShoesBikeArray();
    for(int i = 0; i < rarShoes.GetCount(); i++)
    {
        CShoesBike* pCurShoes = rarShoes.ElementAt(i);
        if(pCurShoes == pShoes)
        {
            return i;
        }
    }  

    return -1;
}


int CUser::GetIDFromBike(CBike* pBike)
{
    BIKEARRAY& rarBikes = GetRefBikeArray();
    for(int i = 0; i < rarBikes.GetCount(); i++)
    {
        CBike* pCurBike = rarBikes.ElementAt(i);
        if(pCurBike == pBike)
        {
            return i;
        }
    }  

    return -1;
}


CCourseRun* CUser::GetCourseRunFromID(int nID)
{
    COURSERUNARRAY& rarCourses = GetRefCourseRunArray();
    if((nID < 0) || (nID >= (int)rarCourses.GetCount()))
    {
        return NULL;
    }

    return rarCourses.GetAt(nID);
}


CCourseBike* CUser::GetCourseBikeFromID(int nID)
{
    COURSEBIKEARRAY& rarCourses = GetRefCourseBikeArray();
    if((nID < 0) || (nID >= (int)rarCourses.GetCount()))
    {
        return NULL;
    }

    return rarCourses.GetAt(nID);
}


CCourseSwim* CUser::GetCourseSwimFromID(int nID)
{
    COURSESWIMARRAY& rarCourses = GetRefCourseSwimArray();
    if((nID < 0) || (nID >= (int)rarCourses.GetCount()))
    {
        return NULL;
    }

    return rarCourses.GetAt(nID);
}


CCourseDuathlon* CUser::GetCourseDuathlonFromID(int nID)
{
    COURSEDUATHLONARRAY& rarCourses = GetRefCourseDuathlonArray();
    if((nID < 0) || (nID >= (int)rarCourses.GetCount()))
    {
        return NULL;
    }

    return rarCourses.GetAt(nID);
}


CCourseTriathlon* CUser::GetCourseTriathlonFromID(int nID)
{
    COURSETRIATHLONARRAY& rarCourses = GetRefCourseTriathlonArray();
    if((nID < 0) || (nID >= (int)rarCourses.GetCount()))
    {
        return NULL;
    }

    return rarCourses.GetAt(nID);
}


CLocationRun* CUser::GetLocationRunFromID(int nID)
{
    LOCATIONRUNARRAY& rarLocations = GetRefLocationRunArray();
    if((nID < 0) || (nID >= (int)rarLocations.GetCount()))
    {
        return NULL;
    }

    return rarLocations.GetAt(nID);
}


CLocationBike* CUser::GetLocationBikeFromID(int nID)
{
    LOCATIONBIKEARRAY& rarLocations = GetRefLocationBikeArray();
    if((nID < 0) || (nID >= (int)rarLocations.GetCount()))
    {
        return NULL;
    }

    return rarLocations.GetAt(nID);
}


CLocationSwim* CUser::GetLocationSwimFromID(int nID)
{
    LOCATIONSWIMARRAY& rarLocations = GetRefLocationSwimArray();
    if((nID < 0) || (nID >= (int)rarLocations.GetCount()))
    {
        return NULL;
    }

    return rarLocations.GetAt(nID);
}


CLocationStrength* CUser::GetLocationStrengthFromID(int nID)
{
    LOCATIONSTRENGTHARRAY& rarLocations = GetRefLocationStrengthArray();
    if((nID < 0) || (nID >= (int)rarLocations.GetCount()))
    {
        return NULL;
    }

    return rarLocations.GetAt(nID);
}


CShoesRun* CUser::GetShoesRunFromID(int nID)
{
    SHOESRUNARRAY& rarShoes = GetRefShoesRunArray();
    if((nID < 0) || (nID >= (int)rarShoes.GetCount()))
    {
        return NULL;
    }

    return rarShoes.GetAt(nID);
}


CShoesBike* CUser::GetShoesBikeFromID(int nID)
{
    SHOESBIKEARRAY& rarShoes = GetRefShoesBikeArray();
    if((nID < 0) || (nID >= (int)rarShoes.GetCount()))
    {
        return NULL;
    }

    return rarShoes.GetAt(nID);
}



CBike* CUser::GetBikeFromID(int nID)
{
    BIKEARRAY& rarBikes = GetRefBikeArray();
    if((nID < 0) || (nID >= (int)rarBikes.GetCount()))
    {
        return NULL;
    }

    return rarBikes.GetAt(nID);
}


void CUser::ReorderData(void)
{
    COURSERUNARRAY& rarCoursesRun = GetRefCourseRunArray();
    int nCoursesRun = (int)rarCoursesRun.GetCount();
    COleDateTime* ptmCoursesRun = new COleDateTime[nCoursesRun];
    int* pnCoursesRunOrder = new int[nCoursesRun];
    COURSEBIKEARRAY& rarCoursesBike = GetRefCourseBikeArray();
    int nCoursesBike = (int)rarCoursesBike.GetCount();
    COleDateTime* ptmCoursesBike = new COleDateTime[nCoursesBike];
    int* pnCoursesBikeOrder = new int[nCoursesBike];
    COURSESWIMARRAY& rarCoursesSwim = GetRefCourseSwimArray();
    int nCoursesSwim = (int)rarCoursesSwim.GetCount();
    COleDateTime* ptmCoursesSwim = new COleDateTime[nCoursesSwim];
    int* pnCoursesSwimOrder = new int[nCoursesSwim];
    COURSEDUATHLONARRAY& rarCoursesDuathlon = GetRefCourseDuathlonArray();
    int nCoursesDuathlon = (int)rarCoursesDuathlon.GetCount();
    COleDateTime* ptmCoursesDuathlon = new COleDateTime[nCoursesDuathlon];
    int* pnCoursesDuathlonOrder = new int[nCoursesDuathlon];
    COURSETRIATHLONARRAY& rarCoursesTriathlon = GetRefCourseTriathlonArray();
    int nCoursesTriathlon = (int)rarCoursesTriathlon.GetCount();
    COleDateTime* ptmCoursesTriathlon = new COleDateTime[nCoursesTriathlon];
    int* pnCoursesTriathlonOrder = new int[nCoursesTriathlon];
    LOCATIONRUNARRAY& rarLocationsRun = GetRefLocationRunArray();
    int nLocationsRun = (int)rarLocationsRun.GetCount();
    COleDateTime* ptmLocationsRun = new COleDateTime[nLocationsRun];
    int* pnLocationsRunOrder = new int[nLocationsRun];
    LOCATIONBIKEARRAY& rarLocationsBike = GetRefLocationBikeArray();
    int nLocationsBike = (int)rarLocationsBike.GetCount();
    COleDateTime* ptmLocationsBike = new COleDateTime[nLocationsBike];
    int* pnLocationsBikeOrder = new int[nLocationsBike];
    LOCATIONSWIMARRAY& rarLocationsSwim = GetRefLocationSwimArray();
    int nLocationsSwim = (int)rarLocationsSwim.GetCount();
    COleDateTime* ptmLocationsSwim = new COleDateTime[nLocationsSwim];
    int* pnLocationsSwimOrder = new int[nLocationsSwim];
    LOCATIONSTRENGTHARRAY& rarLocationsStrength = GetRefLocationStrengthArray();
    int nLocationsStrength = (int)rarLocationsStrength.GetCount();
    COleDateTime* ptmLocationsStrength = new COleDateTime[nLocationsStrength];
    int* pnLocationsStrengthOrder = new int[nLocationsStrength];
    SHOESRUNARRAY& rarShoesRun = GetRefShoesRunArray();
    int nShoesRun = (int)rarShoesRun.GetCount();
    COleDateTime* ptmShoesRun = new COleDateTime[nShoesRun];
    int* pnShoesRunOrder = new int[nShoesRun];
    SHOESBIKEARRAY& rarShoesBike = GetRefShoesBikeArray();
    int nShoesBike = (int)rarShoesBike.GetCount();
    COleDateTime* ptmShoesBike = new COleDateTime[nShoesBike];
    int* pnShoesBikeOrder = new int[nShoesBike];
    BIKEARRAY& rarBikes = GetRefBikeArray();
    int nBikes = (int)rarBikes.GetCount();
    COleDateTime* ptmBikes = new COleDateTime[nBikes];
    int* pnBikesOrder = new int[nBikes];

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        COleDateTime tmDay = pDay->GetDate();
        if(NULL != pDay)
        {
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseRun* pCourseRun = pWorkout->GetCourseRun();
                    if(NULL != pCourseRun)
                    {
                        int nID = GetIDFromCourseRun(pCourseRun);
                        CUtil::OptionallySetLatest(ptmCoursesRun, tmDay, nID, nCoursesRun);
                    }

                    CCourseBike* pCourseBike = pWorkout->GetCourseBike();
                    if(NULL != pCourseBike)
                    {
                        int nID = GetIDFromCourseBike(pCourseBike);
                        CUtil::OptionallySetLatest(ptmCoursesBike, tmDay, nID, nCoursesBike);
                    }

                    CCourseSwim* pCourseSwim = pWorkout->GetCourseSwim();
                    if(NULL != pCourseSwim)
                    {
                        int nID = GetIDFromCourseSwim(pCourseSwim);
                        CUtil::OptionallySetLatest(ptmCoursesSwim, tmDay, nID, nCoursesSwim);
                    }

                    CCourseDuathlon* pCourseDuathlon = pWorkout->GetCourseDuathlon();
                    if(NULL != pCourseDuathlon)
                    {
                        int nID = GetIDFromCourseDuathlon(pCourseDuathlon);
                        CUtil::OptionallySetLatest(ptmCoursesDuathlon, tmDay, nID, nCoursesDuathlon);
                    }

                    CCourseTriathlon* pCourseTriathlon = pWorkout->GetCourseTriathlon();
                    if(NULL != pCourseTriathlon)
                    {
                        int nID = GetIDFromCourseTriathlon(pCourseTriathlon);
                        CUtil::OptionallySetLatest(ptmCoursesTriathlon, tmDay, nID, nCoursesTriathlon);
                    }

                    CLocationRun* pLocationRun = pWorkout->GetLocationRun();
                    if(NULL != pLocationRun)
                    {
                        int nID = GetIDFromLocationRun(pLocationRun);
                        CUtil::OptionallySetLatest(ptmLocationsRun, tmDay, nID, nLocationsRun);
                    }

                    CLocationBike* pLocationBike = pWorkout->GetLocationBike();
                    if(NULL != pLocationBike)
                    {
                        int nID = GetIDFromLocationBike(pLocationBike);
                        CUtil::OptionallySetLatest(ptmLocationsBike, tmDay, nID, nLocationsBike);
                    }

                    CLocationSwim* pLocationSwim = pWorkout->GetLocationSwim();
                    if(NULL != pLocationSwim)
                    {
                        int nID = GetIDFromLocationSwim(pLocationSwim);
                        CUtil::OptionallySetLatest(ptmLocationsSwim, tmDay, nID, nLocationsSwim);
                    }

                    CLocationStrength* pLocationStrength = pWorkout->GetLocationStrength();
                    if(NULL != pLocationStrength)
                    {
                        int nID = GetIDFromLocationStrength(pLocationStrength);
                        CUtil::OptionallySetLatest(ptmLocationsStrength, tmDay, nID, nLocationsStrength);
                    }

                    CShoesRun* pShoesRun = pWorkout->GetShoesRun();
                    if(NULL != pShoesRun)
                    {
                        int nID = GetIDFromShoesRun(pShoesRun);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesRun* pShoesRunSpecial = pWorkout->GetSpecialShoesRun();
                    if(NULL != pShoesRunSpecial)
                    {
                        int nID = GetIDFromShoesRun(pShoesRunSpecial);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesRun* pShoesLeg1 = pWorkout->GetLeg1Shoes();
                    if(NULL != pShoesLeg1)
                    {
                        int nID = GetIDFromShoesRun(pShoesLeg1);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesRun* pShoesRaceLeg1 = pWorkout->GetLeg1RaceShoes();
                    if(NULL != pShoesRaceLeg1)
                    {
                        int nID = GetIDFromShoesRun(pShoesRaceLeg1);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesRun* pShoesLeg3 = pWorkout->GetLeg3Shoes();
                    if(NULL != pShoesRun)
                    {
                        int nID = GetIDFromShoesRun(pShoesLeg3);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesRun* pShoesRaceLeg3 = pWorkout->GetLeg3RaceShoes();
                    if(NULL != pShoesRun)
                    {
                        int nID = GetIDFromShoesRun(pShoesRaceLeg3);
                        CUtil::OptionallySetLatest(ptmShoesRun, tmDay, nID, nShoesRun);
                    }

                    CShoesBike* pShoesBike = pWorkout->GetShoesBike();
                    if(NULL != pShoesBike)
                    {
                        int nID = GetIDFromShoesBike(pShoesBike);
                        CUtil::OptionallySetLatest(ptmShoesBike, tmDay, nID, nShoesBike);
                    }

                    CShoesBike* pShoesBikeSpecial = pWorkout->GetSpecialShoesBike();
                    if(NULL != pShoesBikeSpecial)
                    {
                        int nID = GetIDFromShoesBike(pShoesBikeSpecial);
                        CUtil::OptionallySetLatest(ptmShoesBike, tmDay, nID, nShoesBike);
                    }

                    CShoesBike* pShoesLeg2 = pWorkout->GetLeg2Shoes();
                    if(NULL != pShoesLeg2)
                    {
                        int nID = GetIDFromShoesBike(pShoesLeg2);
                        CUtil::OptionallySetLatest(ptmShoesBike, tmDay, nID, nShoesBike);
                    }

                    CShoesBike* pShoesRaceLeg2 = pWorkout->GetLeg2RaceShoes();
                    if(NULL != pShoesRaceLeg2)
                    {
                        int nID = GetIDFromShoesBike(pShoesRaceLeg2);
                        CUtil::OptionallySetLatest(ptmShoesBike, tmDay, nID, nShoesBike);
                    }

                    CBike* pBike = pWorkout->GetBike();
                    if(NULL != pBike)
                    {
                        int nID = GetIDFromBike(pBike);
                        CUtil::OptionallySetLatest(ptmBikes, tmDay, nID, nBikes);
                    }
                }
            }
        }
    }

    CUtil::OrderArray(pnCoursesRunOrder, ptmCoursesRun, nCoursesRun);
    COURSERUNARRAY arCoursesRunTemp;
    arCoursesRunTemp.Copy(rarCoursesRun);
    for(int k = 0; k < nCoursesRun; k++)
    {
        rarCoursesRun.SetAt(k, arCoursesRunTemp.GetAt(pnCoursesRunOrder[k]));
    }

    CUtil::OrderArray(pnCoursesBikeOrder, ptmCoursesBike, nCoursesBike);
    COURSEBIKEARRAY arCoursesBikeTemp;
    arCoursesBikeTemp.Copy(rarCoursesBike);
    for(int k = 0; k < nCoursesBike; k++)
    {
        rarCoursesBike.SetAt(k, arCoursesBikeTemp.GetAt(pnCoursesBikeOrder[k]));
    }

    CUtil::OrderArray(pnCoursesSwimOrder, ptmCoursesSwim, nCoursesSwim);
    COURSESWIMARRAY arCoursesSwimTemp;
    arCoursesSwimTemp.Copy(rarCoursesSwim);
    for(int k = 0; k < nCoursesSwim; k++)
    {
        rarCoursesSwim.SetAt(k, arCoursesSwimTemp.GetAt(pnCoursesSwimOrder[k]));
    }

    CUtil::OrderArray(pnCoursesDuathlonOrder, ptmCoursesDuathlon, nCoursesDuathlon);
    COURSEDUATHLONARRAY arCoursesDuathlonTemp;
    arCoursesDuathlonTemp.Copy(rarCoursesDuathlon);
    for(int k = 0; k < nCoursesDuathlon; k++)
    {
        rarCoursesDuathlon.SetAt(k, arCoursesDuathlonTemp.GetAt(pnCoursesDuathlonOrder[k]));
    }

    CUtil::OrderArray(pnCoursesTriathlonOrder, ptmCoursesTriathlon, nCoursesTriathlon);
    COURSETRIATHLONARRAY arCoursesTriathlonTemp;
    arCoursesTriathlonTemp.Copy(rarCoursesTriathlon);
    for(int k = 0; k < nCoursesTriathlon; k++)
    {
        rarCoursesTriathlon.SetAt(k, arCoursesTriathlonTemp.GetAt(pnCoursesTriathlonOrder[k]));
    }

    CUtil::OrderArray(pnLocationsRunOrder, ptmLocationsRun, nLocationsRun);
    LOCATIONRUNARRAY arLocationsRunTemp;
    arLocationsRunTemp.Copy(rarLocationsRun);
    for(int k = 0; k < nLocationsRun; k++)
    {
        rarLocationsRun.SetAt(k, arLocationsRunTemp.GetAt(pnLocationsRunOrder[k]));
    }

    CUtil::OrderArray(pnLocationsBikeOrder, ptmLocationsBike, nLocationsBike);
    LOCATIONBIKEARRAY arLocationsBikeTemp;
    arLocationsBikeTemp.Copy(rarLocationsBike);
    for(int k = 0; k < nLocationsBike; k++)
    {
        rarLocationsBike.SetAt(k, arLocationsBikeTemp.GetAt(pnLocationsBikeOrder[k]));
    }

    CUtil::OrderArray(pnLocationsSwimOrder, ptmLocationsSwim, nLocationsSwim);
    LOCATIONSWIMARRAY arLocationsSwimTemp;
    arLocationsSwimTemp.Copy(rarLocationsSwim);
    for(int k = 0; k < nLocationsSwim; k++)
    {
        rarLocationsSwim.SetAt(k, arLocationsSwimTemp.GetAt(pnLocationsSwimOrder[k]));
    }

    CUtil::OrderArray(pnLocationsStrengthOrder, ptmLocationsStrength, nLocationsStrength);
    LOCATIONSTRENGTHARRAY arLocationsStrengthTemp;
    arLocationsStrengthTemp.Copy(rarLocationsStrength);
    for(int k = 0; k < nLocationsStrength; k++)
    {
        rarLocationsStrength.SetAt(k, arLocationsStrengthTemp.GetAt(pnLocationsStrengthOrder[k]));
    }

    CUtil::OrderArray(pnShoesRunOrder, ptmShoesRun, nShoesRun);
    SHOESRUNARRAY arShoesRunTemp;
    arShoesRunTemp.Copy(rarShoesRun);
    for(int k = 0; k < nShoesRun; k++)
    {
        rarShoesRun.SetAt(k, arShoesRunTemp.GetAt(pnShoesRunOrder[k]));
    }

    CUtil::OrderArray(pnShoesBikeOrder, ptmShoesBike, nShoesBike);
    SHOESBIKEARRAY arShoesBikeTemp;
    arShoesBikeTemp.Copy(rarShoesBike);
    for(int k = 0; k < nShoesBike; k++)
    {
        rarShoesBike.SetAt(k, arShoesBikeTemp.GetAt(pnShoesBikeOrder[k]));
    }

    CUtil::OrderArray(pnBikesOrder, ptmBikes, nBikes);
    BIKEARRAY arBikesTemp;
    arBikesTemp.Copy(rarBikes);
    for(int k = 0; k < nBikes; k++)
    {
        rarBikes.SetAt(k, arBikesTemp.GetAt(pnBikesOrder[k]));
    }

    delete[] pnCoursesRunOrder;
    delete[] pnCoursesBikeOrder;
    delete[] pnCoursesSwimOrder;
    delete[] pnCoursesDuathlonOrder;
    delete[] pnCoursesTriathlonOrder;
    delete[] pnLocationsRunOrder;
    delete[] pnLocationsBikeOrder;
    delete[] pnLocationsSwimOrder;
    delete[] pnLocationsStrengthOrder;
    delete[] pnShoesRunOrder;
    delete[] pnShoesBikeOrder;
    delete[] pnBikesOrder;
    delete[] ptmCoursesRun;
    delete[] ptmCoursesBike;
    delete[] ptmCoursesSwim;
    delete[] ptmCoursesDuathlon;
    delete[] ptmCoursesTriathlon;
    delete[] ptmLocationsRun;
    delete[] ptmLocationsBike;
    delete[] ptmLocationsSwim;
    delete[] ptmLocationsStrength;
    delete[] ptmShoesRun;
    delete[] ptmShoesBike;
    delete[] ptmBikes;
}


void CUser::RecalcPRs(CCourseRun* pCourse)
{
    if(NULL == pCourse)
    {
        return;
    }
    pCourse->SetPRSeconds(PRS_NOPR);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmDay = pDay->GetDate();
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseRun* pCourse2 = pWorkout->GetCourseRun();
                    if(pCourse2 == pCourse)
                    {
                        pCourse->OptionallySetPR(pWorkout->GetSpecialSeconds());
                    }
                }
            }
        }
    }
}


void CUser::RecalcPRs(CCourseBike* pCourse)
{
    if(NULL == pCourse)
    {
        return;
    }
    pCourse->SetPRSeconds(PRS_NOPR);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmDay = pDay->GetDate();
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseBike* pCourse2 = pWorkout->GetCourseBike();
                    if(pCourse2 == pCourse)
                    {
                        pCourse->OptionallySetPR(pWorkout->GetSpecialSeconds());
                    }
                }
            }
        }
    }
}


void CUser::RecalcPRs(CCourseSwim* pCourse)
{
    if(NULL == pCourse)
    {
        return;
    }
    pCourse->SetPRSeconds(PRS_NOPR);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmDay = pDay->GetDate();
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseSwim* pCourse2 = pWorkout->GetCourseSwim();
                    if(pCourse2 == pCourse)
                    {
                        pCourse->OptionallySetPR(pWorkout->GetSpecialSeconds());
                    }
                }
            }
        }
    }
}


void CUser::RecalcPRs(CCourseDuathlon* pCourse)
{
    if(NULL == pCourse)
    {
        return;
    }
    pCourse->SetPRSeconds(PRS_NOPR);
    pCourse->SetTransition1PRSeconds(PRS_NOPR);
    pCourse->SetTransition2PRSeconds(PRS_NOPR);
    pCourse->SetLeg1PRSeconds(PRS_NOPR);
    pCourse->SetLeg2PRSeconds(PRS_NOPR);
    pCourse->SetLeg3PRSeconds(PRS_NOPR);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmDay = pDay->GetDate();
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseDuathlon* pCourse2 = pWorkout->GetCourseDuathlon();
                    if(pCourse2 == pCourse)
                    {
                        pCourse->OptionallySetPR(pWorkout->GetSeconds());
                        pCourse->OptionallySetTransition1PR(pWorkout->GetTransition1Seconds());
                        pCourse->OptionallySetTransition2PR(pWorkout->GetTransition2Seconds());
                        pCourse->OptionallySetLeg1PR(pWorkout->GetLeg1RaceSeconds());
                        pCourse->OptionallySetLeg2PR(pWorkout->GetLeg2RaceSeconds());
                        pCourse->OptionallySetLeg3PR(pWorkout->GetLeg3RaceSeconds());
                    }
                }
            }
        }
    }
}


void CUser::RecalcPRs(CCourseTriathlon* pCourse)
{
    if(NULL == pCourse)
    {
        return;
    }
    pCourse->SetPRSeconds(PRS_NOPR);
    pCourse->SetTransition1PRSeconds(PRS_NOPR);
    pCourse->SetTransition2PRSeconds(PRS_NOPR);
    pCourse->SetLeg1PRSeconds(PRS_NOPR);
    pCourse->SetLeg2PRSeconds(PRS_NOPR);
    pCourse->SetLeg3PRSeconds(PRS_NOPR);

    DAYARRAY& rarDays = GetRefDayArray();
    for(int i = 0; i < rarDays.GetCount(); i++)
    {
        CDayLog* pDay = rarDays.GetAt(i);
        if(NULL != pDay)
        {
            COleDateTime tmDay = pDay->GetDate();
            WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
            for(int j = 0; j < rarWorkouts.GetCount(); j++)
            {
                CWorkout* pWorkout = rarWorkouts.GetAt(j);
                if(NULL != pWorkout)
                {   
                    CCourseTriathlon* pCourse2 = pWorkout->GetCourseTriathlon();
                    if(pCourse2 == pCourse)
                    {
                        pCourse->OptionallySetPR(pWorkout->GetSeconds());
                        pCourse->OptionallySetTransition1PR(pWorkout->GetTransition1Seconds());
                        pCourse->OptionallySetTransition2PR(pWorkout->GetTransition2Seconds());
                        pCourse->OptionallySetLeg1PR(pWorkout->GetLeg1RaceSeconds());
                        pCourse->OptionallySetLeg2PR(pWorkout->GetLeg2RaceSeconds());
                        pCourse->OptionallySetLeg3PR(pWorkout->GetLeg3RaceSeconds());
                    }
                }
            }
        }
    }
}


void CUser::AdjustUnits(int nDistRunUnitsOld, int nDistBikeUnitsOld, int nDistSwimUnitsOld,
                        int nHeightUnitsOld, int nWeightUnitsOld, int nTempUnitsOld)
{
    SetHeight(CUtil::ConvertHeight(nHeightUnitsOld, GetHeightUnits(), GetHeight()));

    // change the day data
    DAYARRAY& rarDays = GetRefDayArray();
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
                    pWorkout->AdjustUnits(nDistRunUnitsOld, nDistBikeUnitsOld, nDistSwimUnitsOld,
                                          nWeightUnitsOld, nTempUnitsOld, GetRunDistUnits(), 
                                          GetBikeDistUnits(), GetSwimDistUnits(), GetWeightUnits(),
                                          GetTempUnits());
                }
            }
        }
    }

    COURSERUNARRAY& rarCoursesRun = GetRefCourseRunArray();
    for(int i = 0; i < (int)rarCoursesRun.GetCount(); i++)
    {
        CCourseRun* pCourse = rarCoursesRun.GetAt(i);
        if(NULL != pCourse)
        {
            pCourse->AdjustUnits(nDistRunUnitsOld, GetRunDistUnits());
        }
    }

    COURSEBIKEARRAY& rarCoursesBike = GetRefCourseBikeArray();
    for(int i = 0; i < (int)rarCoursesBike.GetCount(); i++)
    {
        CCourseBike* pCourse = rarCoursesBike.GetAt(i);
        if(NULL != pCourse)
        {
            pCourse->AdjustUnits(nDistBikeUnitsOld, GetBikeDistUnits());
        }
    }

    COURSESWIMARRAY& rarCoursesSwim = GetRefCourseSwimArray();
    for(int i = 0; i < (int)rarCoursesSwim.GetCount(); i++)
    {
        CCourseSwim* pCourse = rarCoursesSwim.GetAt(i);
        if(NULL != pCourse)
        {
            pCourse->AdjustUnits(nDistSwimUnitsOld, GetSwimDistUnits());
        }
    }

    COURSEDUATHLONARRAY& rarCoursesDuathlon = GetRefCourseDuathlonArray();
    for(int i = 0; i < (int)rarCoursesDuathlon.GetCount(); i++)
    {
        CCourseDuathlon* pCourse = rarCoursesDuathlon.GetAt(i);
        if(NULL != pCourse)
        {
            pCourse->AdjustUnits(nDistRunUnitsOld, nDistBikeUnitsOld,
                                 GetRunDistUnits(), GetBikeDistUnits());
        }
    }

    COURSETRIATHLONARRAY& rarCoursesTriathlon = GetRefCourseTriathlonArray();
    for(int i = 0; i < (int)rarCoursesTriathlon.GetCount(); i++)
    {
        CCourseTriathlon* pCourse = rarCoursesTriathlon.GetAt(i);
        if(NULL != pCourse)
        {
            pCourse->AdjustUnits(nDistRunUnitsOld, nDistBikeUnitsOld, nDistSwimUnitsOld,
                                 GetRunDistUnits(), GetBikeDistUnits(), GetSwimDistUnits());
        }
    }

    // none of the locations, shoes, or bikes need to convert anything
}


DAYARRAY& CUser::GetRefDayArray(void)
{
    return m_arDays;
}


COURSERUNARRAY& CUser::GetRefCourseRunArray(void)
{
    return m_arCoursesRun;
}


COURSEBIKEARRAY& CUser::GetRefCourseBikeArray(void)
{
    return m_arCoursesBike;
}


COURSESWIMARRAY& CUser::GetRefCourseSwimArray(void)
{
    return m_arCoursesSwim;
}


COURSEDUATHLONARRAY& CUser::GetRefCourseDuathlonArray(void)
{
    return m_arCoursesDuathlon;
}


COURSETRIATHLONARRAY& CUser::GetRefCourseTriathlonArray(void)
{
    return m_arCoursesTriathlon;
}


LOCATIONRUNARRAY& CUser::GetRefLocationRunArray(void)
{
    return m_arLocationsRun;
}


LOCATIONBIKEARRAY& CUser::GetRefLocationBikeArray(void)
{
    return m_arLocationsBike;
}


LOCATIONSWIMARRAY& CUser::GetRefLocationSwimArray(void)
{
    return m_arLocationsSwim;
}


LOCATIONSTRENGTHARRAY& CUser::GetRefLocationStrengthArray(void)
{
    return m_arLocationsStrength;
}


SHOESRUNARRAY& CUser::GetRefShoesRunArray(void)
{
    return m_arShoesRun;
}


SHOESBIKEARRAY& CUser::GetRefShoesBikeArray(void)
{
    return m_arShoesBike;
}


BIKEARRAY& CUser::GetRefBikeArray(void)
{
    return m_arBikes;
}


UPCOMINGRACEARRAY& CUser::GetRefUpcomingRaceArray(void)
{
    return m_arRaces;
}


UPCOMINGWORKOUTARRAY& CUser::GetRefUpcomingWorkoutArray(void)
{
    return m_arWorkouts;
}


INJURYARRAY& CUser::GetRefInjuryArray(void)
{
    return m_arInjuries;
}


const CMap<int, int, int, int>& CUser::GetHashMap(void) const
{
    return m_mapHash;
}


CString CUser::GetFirstName(void) const
{
    return m_strFirstName;
}


CString CUser::GetLastName(void) const
{
    return m_strLastName;
}


int CUser::GetSex(void) const
{
    return m_nSex;
}


int CUser::GetHeight(void) const
{
    return m_nHeight;
}


int CUser::GetRestingHR(void) const
{
    return m_nRestHR;
}


CString CUser::GetNotes(void) const
{
    return m_strNotes;
}


int CUser::GetBaseTypeRun(void) const
{
    return m_nBaseTypeRun;
}


int CUser::GetBaseTypeBike(void) const
{
    return m_nBaseTypeBike;
}


int CUser::GetBaseTypeSwim(void) const
{
    return m_nBaseTypeSwim;
}


int CUser::GetPaceFormatRun(void) const
{
    return m_nPaceFormatRun;
}


int CUser::GetPaceFormatBike(void) const
{
    return m_nPaceFormatBike;
}


int CUser::GetPaceFormatSwim(void) const
{
    return m_nPaceFormatSwim;
}


int CUser::GetFirstDayOfWeek(void) const
{
    return m_nStartDay;
}


int CUser::GetLastDayOfWeek(void) const
{
	int nStartDay  = GetFirstDayOfWeek();
	
	if(nStartDay > SUNDAY)
	{
		return nStartDay - 1;
	}
	else
	{
		return SATURDAY;
	}
}


bool CUser::DisplayInfoRun(void) const
{
    return m_fDispInfoRun;
}


bool CUser::DisplayInfoBike(void) const
{
    return m_fDispInfoBike;
}


bool CUser::DisplayInfoSwim(void) const
{
    return m_fDispInfoSwim;
}


bool CUser::DisplayInfoStrength(void) const
{
    return m_fDispInfoStrength;
}


bool CUser::DisplayInfoRace(void) const
{
    return m_fDispInfoRace;
}


COleDateTime CUser::GetCurrentDate(void) const
{
    return m_tmCur;
}


int CUser::GetHighlightDay(void) const
{
    return m_nDayHilight;
}


COLORREF CUser::GetBgColor(void) const
{
    return m_crBg;
}


COLORREF CUser::GetDayColor(int nType) const
{
    switch(nType)
    {
    case DAYTYPE_NORMAL:
        {
            return m_acrDay[0];
        }

    case DAYTYPE_GRAYED:
        {
            return m_acrDay[1];
        }

    case DAYTYPE_MONTHSUM:
        {
            return m_acrDay[2];
        }

    case DAYTYPE_WEEKSUM:
        {
            return m_acrDay[3];
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUser::GetDayColor");
            return RGB(0, 0, 0);
        }
    }
}


COLORREF CUser::GetButtonColor(void) const
{
    return m_crButton;
}


COLORREF CUser::GetHighlightColor(void) const
{
    return m_crHighlight;
}


COLORREF CUser::GetShadowColor(bool bOne) const
{
    if(bOne)
    {
        return m_acrShadow[0];
    }
    else
    {
        return m_acrShadow[1];
    }
}


COLORREF CUser::GetGradientColor(bool bBegin) const
{
    if(bBegin)
    {
        return m_acrGrad[0];
    }
    else
    {
        return m_acrGrad[1];
    }
}


COLORREF CUser::GetHeadingTextColor(void) const
{
    return m_crHeadingText;
}


COLORREF CUser::GetDayTextColor(void) const
{
    return m_crDayText;
}


COLORREF CUser::GetAnnotationTextColor(void) const
{
    return m_crAnnotation;
}


COLORREF CUser::GetRaceDayColor(void) const
{
	return m_crRaceDay;
}


COLORREF CUser::GetUpcomingRaceDayColor(void) const
{
	return m_crUpcomingRaceDay;
}


COLORREF CUser::GetUpcomingWorkoutDayColor(void) const
{
	return m_crUpcomingWorkoutDay;
}


COLORREF CUser::GetEditBgColor(void) const
{
	return m_crEditBg;
}


CFont* CUser::GetDayFont(void) const
{
    return m_pfntDay;
}


CFont* CUser::GetHeadingFont(void) const
{
    return m_pfntHeading;
}


CFont* CUser::GetTitleFont(void) const
{
    return m_pfntTitle;
}


CFont* CUser::GetAnnotationFont(void) const
{
    return m_pfntAnnotation;
}


CFont* CUser::GetAnnotationFontBold(void) const
{
    return m_pfntAnnotationBold;
}


int CUser::GetDlgAnimationTime(void) const
{
	return m_nDlgAnimationTime;
}


int CUser::GetRunDecimals(void) const
{
	return m_nRunDecimals;
}


int CUser::GetBikeDecimals(void) const
{
	return m_nBikeDecimals;
}


int CUser::GetSwimDecimals(void) const
{
	return m_nSwimDecimals;
}


void CUser::SetHashMap(CMap<int, int, int, int>& rmapHash)
{
    m_mapHash.RemoveAll();

    POSITION pos = rmapHash.GetStartPosition();
    int nKey;
    int nVal;
    while(NULL != pos)
    {
        rmapHash.GetNextAssoc(pos, nKey, nVal);
        m_mapHash[nKey] = nVal;
    }
}


void CUser::SetFirstName(CString str)
{
    m_strFirstName = str;
}


void CUser::SetLastName(CString str)
{
    m_strLastName = str;
}


void CUser::SetSex(int nSex)
{
    if((SEX_MALE != nSex) && (SEX_FEMALE != nSex))
    {
        CUtil::Fatal("Bad parameter to CUser::SetSex");
        return;
    }
    
    m_nSex = nSex;
}


void CUser::SetHeight(int nHeight)
{
    if(nHeight < 0)
    {
        CUtil::Fatal("Bad parameter to CUser::SetHeight");
        return;
    }

    m_nHeight = nHeight;
}


void CUser::SetRestingHR(int nHR)
{
    if(nHR < 0)
    {
        CUtil::Fatal("Bad parameter to CUser::SetRestingHR");
        return;
    }

    m_nRestHR = nHR;
}


void CUser::SetNotes(CString str)
{
    m_strNotes = str;
}


void CUser::SetBaseTypeRun(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetBaseTypeRun");
        return;
    }

    m_nBaseTypeRun = nType;
}


void CUser::SetBaseTypeBike(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetBaseTypeBike");
        return;
    }

    m_nBaseTypeBike = nType;
}


void CUser::SetBaseTypeSwim(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetBaseTypeSwim");
        return;
    }

    m_nBaseTypeSwim = nType;
}


void CUser::SetPaceFormatRun(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetPaceFormatRun");
        return;
    }

    m_nPaceFormatRun = nType;
}


void CUser::SetPaceFormatBike(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetPaceFormatBike");
        return;
    }

    m_nPaceFormatBike = nType;
}


void CUser::SetPaceFormatSwim(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType) && (PACEFORMAT_MIN100M != nType) && (PACEFORMAT_MIN100Y != nType))
    {
        CUtil::Fatal("Bad parameter to CUser::SetPaceFormatSwim");
        return;
    }

    m_nPaceFormatSwim = nType;
}

void CUser::SetFirstDayOfWeek(int nDay)
{
    if((MONDAY != nDay) && (TUESDAY != nDay) && (WEDNESDAY != nDay) && (THURSDAY != nDay) &&
       (FRIDAY != nDay) && (SATURDAY != nDay) && (SUNDAY != nDay))
    {
        CUtil::Fatal("Bad parameter to CUser::SetFirstDayOfWeek");
        return;
    }

    m_nStartDay = nDay;
}


void CUser::SetDisplayInfoRun(bool fDisp)
{
    m_fDispInfoRun = fDisp;
}


void CUser::SetDisplayInfoBike(bool fDisp)
{
    m_fDispInfoBike = fDisp;
}


void CUser::SetDisplayInfoSwim(bool fDisp)
{
    m_fDispInfoSwim = fDisp;
}


void CUser::SetDisplayInfoStrength(bool fDisp)
{
    m_fDispInfoStrength = fDisp;
}


void CUser::SetDisplayInfoRace(bool fDisp)
{
    m_fDispInfoRace = fDisp;
}


void CUser::SetCurrentDate(COleDateTime tmCur)
{
    m_tmCur = tmCur;
}


void CUser::SetHighlightDay(int nDay)
{
    m_nDayHilight = nDay;
}


void CUser::SetBgColor(COLORREF cr)
{
    m_crBg = cr;
}


void CUser::SetDayColor(int nType, COLORREF cr)
{
    switch(nType)
    {
    case DAYTYPE_NORMAL:
        {
            m_acrDay[0] = cr;
            break;
        }

    case DAYTYPE_GRAYED:
        {
            m_acrDay[1] = cr;
            break;
        }

    case DAYTYPE_MONTHSUM:
        {
            m_acrDay[2] = cr;
            break;
        }

    case DAYTYPE_WEEKSUM:
        {
            m_acrDay[3] = cr;
            break;
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUser::SetDayColor");
        }
    }
}


void CUser::SetButtonColor(COLORREF cr)
{
    m_crButton = cr;
}


void CUser::SetHighlightColor(COLORREF cr)
{
    m_crHighlight = cr;
}


void CUser::SetShadowColor(bool bOne, COLORREF cr)
{
    if(bOne)
    {
        m_acrShadow[0] = cr;
    }
    else
    {
        m_acrShadow[1] = cr;
    }
}


void CUser::SetGradientColor(bool bBegin, COLORREF cr)
{
    if(bBegin)
    {
        m_acrGrad[0] = cr;
    }
    else
    {
        m_acrGrad[1] = cr;
    }
}


void CUser::SetHeadingTextColor(COLORREF cr)
{
    m_crHeadingText = cr;
}


void CUser::SetDayTextColor(COLORREF cr)
{
    m_crDayText = cr;
}


void CUser::SetAnnotationTextColor(COLORREF cr)
{
    m_crAnnotation = cr;
}


void CUser::SetRaceDayColor(COLORREF cr)
{
	m_crRaceDay = cr;
}


void CUser::SetUpcomingRaceDayColor(COLORREF cr)
{
	m_crUpcomingRaceDay = cr;
}


void CUser::SetUpcomingWorkoutDayColor(COLORREF cr)
{
	m_crUpcomingWorkoutDay = cr;
}


void CUser::SetEditBgColor(COLORREF cr)
{
	m_crEditBg = cr;
}


void CUser::SetDayFont(CFont* pfnt)
{
    m_pfntDay = pfnt;
}


void CUser::SetHeadingFont(CFont* pfnt)
{
    m_pfntHeading = pfnt;
}


void CUser::SetTitleFont(CFont* pfnt)
{
    m_pfntTitle = pfnt;
}


void CUser::SetAnnotationFont(CFont* pfnt)
{
    m_pfntAnnotation = pfnt;
}


void CUser::SetAnnotationFontBold(CFont* pfnt)
{
    m_pfntAnnotationBold = pfnt;
}


unsigned __int64 CUser::GetMandatoryRunFields(void) const
{
    return m_i64RunMand;
}


void CUser::SetMandatoryRunFields(unsigned __int64 i64Fields)
{
    m_i64RunMand = i64Fields;
}


bool CUser::IsRunFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRunFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRunFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRunFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRunFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRunFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRunFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryBikeFields(void) const
{
    return m_i64BikeMand;
}


void CUser::SetMandatoryBikeFields(unsigned __int64 i64Fields)
{
    m_i64BikeMand = i64Fields;
}


bool CUser::IsBikeFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > BIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsBikeFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryBikeFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetBikeFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > BIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetBikeFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryBikeFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryBikeFields(i64Field);
}


unsigned __int64 CUser::GetMandatorySwimFields(void) const
{
    return m_i64SwimMand;
}


void CUser::SetMandatorySwimFields(unsigned __int64 i64Fields)
{
    m_i64SwimMand = i64Fields;
}


bool CUser::IsSwimFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > SWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsSwimFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatorySwimFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetSwimFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > SWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetSwimFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatorySwimFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatorySwimFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryStrengthFields(void) const
{
    return m_i64StrMand;
}


void CUser::SetMandatoryStrengthFields(unsigned __int64 i64Fields)
{
    m_i64StrMand = i64Fields;
}


bool CUser::IsStrengthFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsStrengthFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryStrengthFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetStrengthFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetStrengthFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryStrengthFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryStrengthFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryRaceRunFields(void) const
{
    return m_i64RaceRunMand;
}


void CUser::SetMandatoryRaceRunFields(unsigned __int64 i64Fields)
{
    m_i64RaceRunMand = i64Fields;
}


bool CUser::IsRaceRunFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACERUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRaceRunFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceRunFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRaceRunFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RACERUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRaceRunFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceRunFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRaceRunFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryRaceBikeFields(void) const
{
    return m_i64RaceBikeMand;
}


void CUser::SetMandatoryRaceBikeFields(unsigned __int64 i64Fields)
{
    m_i64RaceBikeMand = i64Fields;
}


bool CUser::IsRaceBikeFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACEBIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRaceBikeFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceBikeFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRaceBikeFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RACEBIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRaceBikeFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceBikeFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRaceBikeFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryRaceSwimFields(void) const
{
    return m_i64RaceSwimMand;
}


void CUser::SetMandatoryRaceSwimFields(unsigned __int64 i64Fields)
{
    m_i64RaceSwimMand = i64Fields;
}


bool CUser::IsRaceSwimFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACESWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRaceSwimFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceSwimFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRaceSwimFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RACESWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRaceSwimFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceSwimFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRaceSwimFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryRaceDuathlonFields(void) const
{
    return m_i64RaceDuathlonMand;
}


void CUser::SetMandatoryRaceDuathlonFields(unsigned __int64 i64Fields)
{
    m_i64RaceDuathlonMand = i64Fields;
}


bool CUser::IsRaceDuathlonFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACEDUFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRaceDuathlonFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceDuathlonFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRaceDuathlonFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RACEDUFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRaceDuathlonFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceDuathlonFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRaceDuathlonFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryRaceTriathlonFields(void) const
{
    return m_i64RaceTriathlonMand;
}


void CUser::SetMandatoryRaceTriathlonFields(unsigned __int64 i64Fields)
{
    m_i64RaceTriathlonMand = i64Fields;
}


bool CUser::IsRaceTriathlonFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACETRIFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsRaceTriathlonFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceTriathlonFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetRaceTriathlonFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > RACETRIFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetRaceTriathlonFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryRaceTriathlonFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryRaceTriathlonFields(i64Field);
}


unsigned __int64 CUser::GetMandatoryStartFields(void) const
{
    return m_i64StartMand;
}


void CUser::SetMandatoryStartFields(unsigned __int64 i64Fields)
{
    m_i64StartMand = i64Fields;
}


bool CUser::IsStartFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > STARTFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::IsStartFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryStartFields();

    return (0 != (i64Field & i64Mask));
}


void CUser::SetStartFieldMandatory(int nField, bool bMandatory)
{
    if((nField < 0) || (nField > STARTFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to CUser::SetStartFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryStartFields();

    if(bMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryStartFields(i64Field);
}


int CUser::GetRunDistUnits(void) const
{
    return m_nRunDistUnits;;
}


int CUser::GetBikeDistUnits(void) const
{
    return m_nBikeDistUnits;;
}


int CUser::GetSwimDistUnits(void) const
{
    return m_nSwimDistUnits;;
}


int CUser::GetHeightUnits(void) const
{
    return m_nHeightUnits;;
}


int CUser::GetWeightUnits(void) const
{
    return m_nWeightUnits;;
}


int CUser::GetTempUnits(void) const
{
    return m_nTempUnits;
}


void CUser::SetRunDistUnits(int nUnits)
{
    m_nRunDistUnits = nUnits;
}


void CUser::SetBikeDistUnits(int nUnits)
{
    m_nBikeDistUnits = nUnits;
}


void CUser::SetSwimDistUnits(int nUnits)
{
    m_nSwimDistUnits = nUnits;
}


void CUser::SetHeightUnits(int nUnits)
{
    m_nHeightUnits = nUnits;
}


void CUser::SetWeightUnits(int nUnits)
{
    m_nWeightUnits = nUnits;
}


void CUser::SetTempUnits(int nUnits)
{
    m_nTempUnits = nUnits;
}


void CUser::SetDlgAnimationTime(int nTime)
{
	m_nDlgAnimationTime = nTime;
}


void CUser::SetRunDecimals(int nNum)
{
	m_nRunDecimals = nNum;
}


void CUser::SetBikeDecimals(int nNum)
{
	m_nBikeDecimals = nNum;
}


void CUser::SetSwimDecimals(int nNum)
{
	m_nSwimDecimals = nNum;
}