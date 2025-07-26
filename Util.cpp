#include <stdlib.h>

#include "StdAfx.h"
#include "RunningLog.h"
#include "CalendarCtl.h"
#include "XMLSerializer.h"
#include "Util.h"

extern CUser* g_pUser;


CUtil::CUtil(void)
{
}


CUser* CUtil::GetUser(void)
{
    return g_pUser;
}


int CUtil::GetSplashSleep(void)
{
    return 50;  // 600 good
}


int CUtil::GetAnimationSpeed(void)
{
    CUser* pUser = g_pUser;
	if(NULL != pUser)
	{
		return pUser->GetDlgAnimationTime();
	}
	else
	{
		return 3;
	}
}


bool CUtil::DoAnimations(void)
{
    return true;
}


CString CUtil::GetPaceString(int nFormat, CString strDef /* = "Pace" */, bool bBare /* = false */)
{
    CUser* pUser = g_pUser;
    CString str = strDef;
	CString strBare;
    if(NULL != pUser)
    {
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
                CUtil::Fatal("Bad parameter to CUtil::GetPaceString");
                break;
            }
        }

        CString strDist;
        if(DISTUNITS_MI == nDistType)
        {
            strDist = "mi";
        }
        else if(DISTUNITS_KM == nDistType)
        {
            strDist = "km";
        }

        switch(nPaceType)
        {
        case PACEFORMAT_MINDIST:
            {
                str += " (min/" + strDist + ")";
				strBare = "min/" + strDist;
                break;
            }

        case PACEFORMAT_DISTHR:
            {
                str += " (" + strDist + "/hr)";
				strBare = strDist + "/hr";
                break;
            }

        case PACEFORMAT_MIN100M:
            {
                str += " (min/100m)";
				strBare = "min/100m";
                break;
            }

		case PACEFORMAT_MIN100Y:
			{
				str += " (min/100y)";
				strBare = "min/100y";
				break;
			}

        default:
            {
                CUtil::Fatal("Bad parameter to CUtil::GetPaceString");
                break;
            }
        }
    }
    str += ":";

	if(true == bBare)
	{
		return strBare;
	}
	else
	{
		return str;
	}
}


CString CUtil::GetRunDistString(CString strDef /* = "Distance" */)
{
    CUser* pUser = g_pUser;
    CString str = strDef;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetRunDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            str += " (mi)";
        }
        else if(DISTUNITS_KM == nUnits)
        {
            str += " (km)";
        }
    }
    str += ":";

    return str;
}


CString CUtil::GetBikeDistString(CString strDef /* = "Distance" */)
{
    CUser* pUser = g_pUser;
    CString str = strDef;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetBikeDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            str += " (mi)";
        }
        else if(DISTUNITS_KM == nUnits)
        {
            str += " (km)";
        }
    }
    str += ":";

    return str;
}


CString CUtil::GetSwimDistString(CString strDef /* = "Distance" */)
{
    CUser* pUser = g_pUser;
    CString str = strDef;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetSwimDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            str += " (mi)";
        }
        else if(DISTUNITS_KM == nUnits)
        {
            str += " (km)";
        }
    }
    str += ":";

    return str;
}


CString CUtil::GetRunDistUnitString(bool bShort /* = false */)
{
    CUser* pUser = g_pUser;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetRunDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            if(false == bShort)
            {
                return "Miles";
            }
            else
            {
                return "Mi";
            }
        }
        else if(DISTUNITS_KM == nUnits)
        {
            if(false == bShort)
            {
                return "Kilometers";
            }
            else
            {
                return "Km";
            }
        }
        else
        {
            CUtil::Fatal("Bad parameter to CUtil::GetRunDistString");
            return "";
        }
    }

    return "";
}


CString CUtil::GetBikeDistUnitString(bool bShort /* = false */)
{
    CUser* pUser = g_pUser;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetBikeDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            if(false == bShort)
            {
                return "Miles";
            }
            else
            {
                return "Mi";
            }
        }
        else if(DISTUNITS_KM == nUnits)
        {
            if(false == bShort)
            {
                return "Kilometers";
            }
            else
            {
                return "Km";
            }
        }
        else
        {
            CUtil::Fatal("Bad parameter to CUtil::GetBikeDistString");
            return "";
        }
    }

    return "";
}


CString CUtil::GetSwimDistUnitString(bool bShort /* = false */)
{
    CUser* pUser = g_pUser;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetSwimDistUnits();
        if(DISTUNITS_MI == nUnits)
        {
            if(false == bShort)
            {
                return "Miles";
            }
            else
            {
                return "Mi";
            }
        }
        else if(DISTUNITS_KM == nUnits)
        {
            if(false == bShort)
            {
                return "Kilometers";
            }
            else
            {
                return "Km";
            }
        }
        else
        {
            CUtil::Fatal("Bad parameter to CUtil::GetSwimDistString");
            return "";
        }
    }
    
    return "";
}


CString CUtil::GetTemperatureString(bool bBare /* = false */)
{
    CUser* pUser = g_pUser;
    CString str = "Temperature";
	CString strBare;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetTempUnits();
        if(TEMPUNITS_DEG == nUnits)
        {
            str += " (°F)";
			strBare = "°F";
        }
        else if(TEMPUNITS_CELSIUS == nUnits)
        {
            str += " (°C)";
			strBare = "°C";
        }
    }
    str += ":";

	if(true == bBare)
	{
		return strBare;
	}
	else
	{
		return str;
	}
}


CString CUtil::GetPWWeightString(CString strDef /* = "Post-workout weight" */)
{
    CUser* pUser = g_pUser;
    CString str = strDef;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetWeightUnits();
        if(WEIGHTUNITS_LBS == nUnits)
        {
            str += " (lb)";
        }
        else if(WEIGHTUNITS_KG == nUnits)
        {
            str += " (kg)";
        }
    }
    str += ":";

    return str;
}


CString CUtil::GetPWWeightUnitString(bool bShort /* = false */)
{
    CUser* pUser = g_pUser;
	if(NULL != pUser)
    {
        int nUnits = pUser->GetWeightUnits();
        if(WEIGHTUNITS_LBS == nUnits)
        {
			if(true == bShort)
			{
				return "Lb";
			}
			else
			{
				return "Pounds";
			}
		}
        else if(WEIGHTUNITS_KG == nUnits)
        {
            if(true == bShort)
			{
				return "Kg";
			}
			else
			{
				return "Kilograms";
			}
        }
    }

	return "NULL";
}


CString CUtil::GetHeightString(bool bBare /* = false */)
{
    CUser* pUser = g_pUser;
    CString str = "Height";
	CString strBare;
    if(NULL != pUser)
    {
        int nUnits = pUser->GetHeightUnits();
        if(HEIGHTUNITS_IN == nUnits)
        {
            str += " (in)";
			strBare = "in";
        }
        else if(HEIGHTUNITS_CM == nUnits)
        {
            str += " (cm)";
			strBare = "cm";
        }
    }
    str += ":";

	if(true == bBare)
	{
		return strBare;
	}
	else
	{
		return str;
	}
}


int CUtil::GetDayOfWeek(COleDateTime tmTime)
{
    return tmTime.GetDayOfWeek();
}


bool CUtil::IsLeapYear(int nYear)
{
    if((nYear % 4 != 0) || (nYear % 100 == 0) && (nYear % 400 != 0))
    {
        return false;
    }

    return true;
}


int CUtil::GetNumWeeks(COleDateTime tmTime, int nStartDay)
{
    int nYear = tmTime.GetYear();
    int nMonth = tmTime.GetMonth();
    int nDays = CUtil::GetNumDaysInMonth(nYear, nMonth);

    // make a time for the first and last day
    COleDateTime tmFirstDay = CUtil::GetFirstOfMonth(tmTime);
    COleDateTime tmLastDay = CUtil::GetLastOfMonth(tmTime);

    // get the day of the week each falls on
    int nDayFirst = CUtil::GetDayOfWeek(tmFirstDay);
    int nDayLast = CUtil::GetDayOfWeek(tmLastDay);

    // total is: monthly days + number of greyed days at beginning + number of grayed days at end
    int nTotalDays = nDays + CUtil::PositiveModulo(nDayFirst - nStartDay, 7);

    // return the least integer greater than or equal to (nTotalDays / 7)
    return (nTotalDays + 6) / 7;
}


int CUtil::GetNumDaysInMonth(int nYear, int nMonth)
{
    switch(nMonth)
    {
    case JANUARY:
        {
            return 31;
        }

    case FEBRUARY:
        {
            if(CUtil::IsLeapYear(nYear))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }

    case MARCH:
        {
            return 31;
        }

    case APRIL:
        {
            return 30;
        }

    case MAY:
        {
            return 31;
        }

    case JUNE:
        {
            return 30;
        }

    case JULY:
        {
            return 31;
        }

    case AUGUST:
        {
            return 31;
        }

    case SEPTEMBER:
        {
            return 30;
        }

    case OCTOBER:
        {
            return 31;
        }

    case NOVEMBER:
        {
            return 30;
        }

    case DECEMBER:
        {
            return 31;
        }

    default:
        {
            CUtil::Fatal("Bad Parameter to CUtil::GetNumDaysInMonth");
            return 0;
        }
    }
}


int CUtil::GetNumDaysInYear(int nYear)
{
    if(CUtil::IsLeapYear(nYear))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}


COleDateTime CUtil::GetFirstVisibleDay(COleDateTime tmFirst, int nStartDay)
{
    // make a time for the first
    COleDateTime tmFirstDay = CUtil::GetFirstOfMonth(tmFirst);

    int nFirst = CUtil::GetDayOfWeek(tmFirstDay);
    
    int nBack = CUtil::PositiveModulo(nFirst - nStartDay, 7);

    return CUtil::OffsetDay(tmFirstDay, -nBack);
}


COleDateTime CUtil::SubtractDay(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    if(nDay > 1)
    {
        return COleDateTime(nYear, nMonth, nDay - 1, nHour, nMinute, nSec);
    }

    else if(nMonth > JANUARY)
    {
        return COleDateTime(nYear, nMonth - 1, CUtil::GetNumDaysInMonth(nYear, nMonth - 1), nHour, nMinute, nSec);
    }

    else
    {
        return COleDateTime(nYear - 1, DECEMBER, CUtil::GetNumDaysInMonth(nYear - 1, DECEMBER), nHour, nMinute, nSec);
    }
}


COleDateTime CUtil::AddDay(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    if(nDay < CUtil::GetNumDaysInMonth(nYear, nMonth))
    {
        return COleDateTime(nYear, nMonth, nDay + 1, nHour, nMinute, nSec);
    }

    else if(nMonth < DECEMBER)
    {
        return COleDateTime(nYear, nMonth + 1, 1, nHour, nMinute, nSec);
    }

    else
    {
        return COleDateTime(nYear + 1, JANUARY, 1, nHour, nMinute, nSec);
    }
}


COleDateTime CUtil::AddMonth(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    if(nMonth < DECEMBER)
    {
        if(nDay > CUtil::GetNumDaysInMonth(nYear, nMonth + 1))
        {
            nDay = CUtil::GetNumDaysInMonth(nYear, nMonth + 1);
        }
        return COleDateTime(nYear, nMonth + 1, nDay, nHour, nMinute, nSec);
    }
    else
    {
        if(nDay > CUtil::GetNumDaysInMonth(nYear + 1, JANUARY))
        {
            nDay = CUtil::GetNumDaysInMonth(nYear + 1, JANUARY);
        }
        return COleDateTime(nYear + 1, JANUARY, nDay, nHour, nMinute, nSec);
    }
}


COleDateTime CUtil::SubtractMonth(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    if(nMonth > JANUARY)
    {
        if(nDay > CUtil::GetNumDaysInMonth(nYear, nMonth - 1))
        {
            nDay = CUtil::GetNumDaysInMonth(nYear, nMonth - 1);
        }
        return COleDateTime(nYear, nMonth - 1, nDay, nHour, nMinute, nSec);
    }
    else
    {
        if(nDay > CUtil::GetNumDaysInMonth(nYear - 1, DECEMBER))
        {
            nDay = CUtil::GetNumDaysInMonth(nYear - 1, DECEMBER);
        }
        return COleDateTime(nYear - 1, DECEMBER, nDay, nHour, nMinute, nSec);
    }
}


COleDateTime CUtil::AddYear(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    return COleDateTime(nYear + 1, nMonth, nDay, nHour, nMinute, nSec);
}


COleDateTime CUtil::SubtractYear(COleDateTime tmDay)
{
    int nYear = tmDay.GetYear();
    int nMonth = tmDay.GetMonth();
    int nDay = tmDay.GetDay();
    int nHour = tmDay.GetHour();
    int nMinute = tmDay.GetMinute();
    int nSec = tmDay.GetSecond();

    return COleDateTime(nYear - 1, nMonth, nDay, nHour, nMinute, nSec);
}


COleDateTime CUtil::OffsetDay(COleDateTime tmDay, int n)
{
    if(n < 0)
    {
        n *= -1;
        for(int i = 0; i < n; i++)
        {
            tmDay = CUtil::SubtractDay(tmDay);
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            tmDay = CUtil::AddDay(tmDay);
        }
    }
    return tmDay;
}


bool CUtil::IsLaterThan(COleDateTime tmLater, COleDateTime tmBase)
{
    if(tmLater.GetYear() > tmBase.GetYear())
    {
        return true;
    }
    else if(tmLater.GetYear() == tmBase.GetYear())
    {
        if(tmLater.GetMonth() > tmBase.GetMonth())
        {
            return true;
        }
        else if(tmLater.GetMonth() == tmBase.GetMonth())
        {
            if(tmLater.GetDay() > tmBase.GetDay())
            {
                return true;
            }
            else if(tmLater.GetDay() == tmBase.GetDay())
            {
                if(tmLater.GetHour() > tmBase.GetHour())
                {
                    return true;
                }
                else if(tmLater.GetHour() == tmBase.GetHour())
                {
                    if(tmLater.GetMinute() > tmBase.GetMinute())
                    {
                        return true;
                    }
                    else if(tmLater.GetMinute() == tmBase.GetMinute())
                    {
                        if(tmLater.GetSecond() > tmBase.GetSecond())
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}


bool CUtil::IsLaterDayThan(COleDateTime tmLater, COleDateTime tmBase)
{
    if(tmLater.GetYear() > tmBase.GetYear())
    {
        return true;
    }
    else if(tmLater.GetYear() == tmBase.GetYear())
    {
        if(tmLater.GetMonth() > tmBase.GetMonth())
        {
            return true;
        }
        else if(tmLater.GetMonth() == tmBase.GetMonth())
        {
            if(tmLater.GetDay() > tmBase.GetDay())
            {
                return true;
            }
        }
    }

    return false;
}


bool CUtil::IsSameDay(COleDateTime tm1, COleDateTime tm2)
{
    if((tm1.GetYear() == tm2.GetYear()) && (tm1.GetMonth() == tm2.GetMonth()) && 
       (tm1.GetDay() == tm2.GetDay()))
    {
        return true;
    }

    return false;
}


int CUtil::GetNumberOfDaysLaterThan(COleDateTime tmLater, COleDateTime tmBase)
{
    int nDays = 0;
    if(CUtil::IsSameDay(tmLater, tmBase))
    {
        return 0;
    }

    if(CUtil::IsLaterThan(tmLater, tmBase))
    {
        for(; !CUtil::IsSameDay(tmBase, tmLater); tmBase = CUtil::AddDay(tmBase))
        {
            nDays++;
        }

        return nDays;
    }
    else
    {
        return -CUtil::GetNumberOfDaysLaterThan(tmBase, tmLater);
    }
}


COleDateTime CUtil::GetFirstOfMonth(COleDateTime tmTime)
{
    int nYear = tmTime.GetYear();
    int nMonth = tmTime.GetMonth();
    
    return COleDateTime(nYear, nMonth, 1, 0, 0, 0);
}


COleDateTime CUtil::GetLastOfMonth(COleDateTime tmTime)
{
    int nYear = tmTime.GetYear();
    int nMonth = tmTime.GetMonth();
    int nDays = CUtil::GetNumDaysInMonth(nYear, nMonth);
    return COleDateTime(nYear, nMonth, nDays, 0, 0, 0);
}


bool CUtil::IsHighlightDayADay(COleDateTime tmCur, int nDay, int nStartDay)
{
    int nWeeks = CUtil::GetNumWeeks(tmCur, nStartDay);
    if((nDay >= 1) && (nDay <= 7 * nWeeks))
    {
        return true;
    }

    return false;
}


COleDateTime CUtil::GetHighlightedDate(COleDateTime tmCur, int nDay, int nStartDay)
{
    COleDateTime tm = CUtil::GetFirstVisibleDay(CUtil::GetFirstOfMonth(tmCur), nStartDay);
    return CUtil::OffsetDay(tm, nDay - 1);
}


int CUtil::PositiveModulo(int nNum, int nMod)
{
    int nRes = nNum % nMod;
    if(nNum < 0)
    {
        nNum += nMod;
    }

    return nNum;
}


int CUtil::NumRunWorkouts(void)
{
    return 9;
}


int CUtil::NumBikeWorkouts(void)
{
    return 7;
}


int CUtil::NumSwimWorkouts(void)
{
    return 7;
}


int CUtil::NumStrengthWorkouts(void)
{
    return 3;
}


int CUtil::NumRaces(void)
{
    return 5;
}


double CUtil::DateTimeTo24Hours(COleDateTime tm)
{
    double dRes = 0.0;
    if(COleDateTime::valid != tm.GetStatus())
    {
        return NOGRAPHDATA;
    }

    double dHours = (double)tm.GetHour();
    double dMinutes = (double)tm.GetMinute();
    double dSeconds = (double)tm.GetSecond();

    dRes = dHours + dMinutes / 60.0 + dSeconds / 3600.0;

    return dRes;
}


COleDateTime CUtil::Time24HoursToDateTime(double dTime)
{
    double dRes = 0.0;
    COleDateTime tmRes = COleDateTime::GetCurrentTime();

    int nHour = (int)dTime;
    int nMinutes = (int)((dTime - (double)nHour) * 60.0);
    int nSeconds = 0;

    tmRes.SetDateTime(tmRes.GetYear(), tmRes.GetMonth(), tmRes.GetDay(), nHour, nMinutes, nSeconds);

    return tmRes;
}


double CUtil::ComputeRunCalories(double dWeight, double dDist)
{
	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return 0.0;
	}

	dWeight = CUtil::ConvertWeight(pUser->GetWeightUnits(), WEIGHTUNITS_LBS, dWeight);
	dDist = CUtil::ConvertDistance(pUser->GetRunDistUnits(), DISTUNITS_MI, dDist);
	
	return 0.7343 * dWeight * dDist;
}


double CUtil::ComputeBikeCalories(double dWeight, double dDist, double dTime)
{
	CUser* pUser = GetUser();
	if((NULL == pUser) || (0.0 == dTime))
	{
		return 0.0;
	}

	dWeight = CUtil::ConvertWeight(pUser->GetWeightUnits(), WEIGHTUNITS_LBS, dWeight);
	dDist = CUtil::ConvertDistance(pUser->GetBikeDistUnits(), DISTUNITS_MI, dDist);

	double dMins = dTime / 60.0;
	double dHours = dTime / 3600.0;
	double dMPH = dDist / dHours;

	return dWeight * dMins * (0.00390364 * dMPH - 0.00014700 * dMPH * dMPH + 0.000008796 * dMPH * dMPH * dMPH);
}


double CUtil::ComputeSwimCalories(double dWeight, double dDist, double dTime)
{
	CUser* pUser = GetUser();
	if((NULL == pUser) || (0.0 == dTime))
	{
		return 0.0;
	}

	dWeight = CUtil::ConvertWeight(pUser->GetWeightUnits(), WEIGHTUNITS_LBS, dWeight);
	dDist = CUtil::ConvertDistance(pUser->GetSwimDistUnits(), DISTUNITS_MI, dDist) * 1760.0; // dist in yards

	double dMins = dTime / 60.0;
	double dYardsPerMin = dDist / dMins;

	return 0.001664927 * dWeight * dMins * dYardsPerMin;
}


double CUtil::ComputeStrengthCalories(double dWeight, double dTime)
{
	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return 0.0;
	}

	dWeight = CUtil::ConvertWeight(pUser->GetWeightUnits(), WEIGHTUNITS_LBS, dWeight);
	double dMins = dTime / 60.0;

	return 0.0454073 * dWeight * dMins;
}


bool CUtil::IsInRangeNear(double dValue, double dBase, double dRange /* = 1.0 */)
{
	if((dValue > dBase - dRange / 2.0) && (dValue < dBase + dRange / 2.0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool CUtil::HasNoData(double dValue, bool bEnsureNonNegative /* = true */)
{
	bool fPass1 = IsInRangeNear(dValue, NOGRAPHDATA);
	bool fPass2 = false;

	if(true == bEnsureNonNegative)
	{
		fPass2 = (dValue < 0.0);
	}

	return (fPass1 || fPass2);
}


bool CUtil::HasData(double dValue, bool bEnsureNonNegative /* = true */)
{
	return !CUtil::HasNoData(dValue, bEnsureNonNegative);
}


COleDateTime CUtil::ExtractDateFromDay(CString str)
{
	// get date out (in format month/day/year)
	int n1 = str.Find('/');
	CString strMonth;
	if(-1 != n1)
	{
		strMonth = str.Left(n1);
	}

	str = str.Right(str.GetLength() - n1 - 1);
	int n2 = str.Find('/');
	CString strDay;
	if(-1 != n2)
	{
		strDay = str.Left(n2);
	}

	CString strYear = str.Right(str.GetLength() - n2 - 1);

	int nMonth = atoi(strMonth);
	int nDay = atoi(strDay);
	int nYear = atoi(strYear);

	// the day we want to pop up the summary for
	COleDateTime tmStart(nYear, nMonth, nDay, 1, 1, 1);

	return tmStart;
}


COleDateTime CUtil::ExtractDateFromMonth(CString str)
{
	int nMonth = 1;
	if("January" == str.Left(7))
	{
		nMonth = 1;
	}
	else if("February" == str.Left(8))
	{
		nMonth = 2;
	}
	else if("March" == str.Left(5))
	{
		nMonth = 3;
	}
	else if("April" == str.Left(5))
	{
		nMonth = 4;
	}
	else if("May" == str.Left(3))
	{
		nMonth = 5;
	}
	else if("June" == str.Left(4))
	{
		nMonth = 6;
	}
	else if("July" == str.Left(4))
	{
		nMonth = 7;
	}
	else if("August" == str.Left(6))
	{
		nMonth = 8;
	}
	else if("September" == str.Left(9))
	{
		nMonth = 9;
	}
	else if("October" == str.Left(7))
	{
		nMonth = 10;
	}
	else if("November" == str.Left(8))
	{
		nMonth = 11;
	}
	else if("December" == str.Left(8))
	{
		nMonth = 12;
	}

	int nYear = atoi(str.Right(4));
	COleDateTime tmStart(nYear, nMonth, 1, 1, 1, 1);

	return tmStart;
}


CString CUtil::WorkoutToString(CWorkout* pWorkout)
{
    if(NULL == pWorkout)
    {
        CUtil::Fatal("Bad parameter to CUtil::WorkoutToString");
        return "NULL";
    }
   
    int nType = pWorkout->GetType();
    switch(pWorkout->GetActivityType())
    {
    case ACTIVITY_RUNNING:
        {
            return CUtil::RunWorkoutToString(nType);
        }

    case ACTIVITY_BIKING:
        {
            return CUtil::BikeWorkoutToString(nType);
        }

    case ACTIVITY_SWIMMING:
        {
            return CUtil::SwimWorkoutToString(nType);
        }

    case ACTIVITY_STRENGTH:
        {
            return CUtil::StrengthWorkoutToString(nType);
        }

    case ACTIVITY_RACE:
        {
            return CUtil::RaceToString(nType);
        }

    default:
        {
            return "NULL";
        }
    }
}


CString CUtil::RunWorkoutToString(int nWorkout)
{
    switch(nWorkout)
    {
    case RUNTYPE_POOL:
        {
            return "Pool";
        }

    case RUNTYPE_EZ:
        {
            return "Easy";
        }

    case RUNTYPE_NORMAL:
        {
            return "Normal";
        }

    case RUNTYPE_HARD:
        {
            return "Hard";
        }

    case RUNTYPE_TEMPO:
        {
            return "Tempo";
        }

    case RUNTYPE_INTERVALS:
        {
            return "Intervals";
        }

    case RUNTYPE_HILLS:
        {
            return "Hills";
        }

    case RUNTYPE_TREADMILL:
        {
            return "Treadmill";
        }

    case RUNTYPE_OTHER:
        {
            return "Other";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::RunWorkoutToString");
            return "NULL";
        }
    }
}


CString CUtil::BikeWorkoutToString(int nWorkout)
{
    switch(nWorkout)
    {
    case BIKETYPE_TRAINER:
        {
            return "Trainer";
        }

    case BIKETYPE_EZ:
        {
            return "Easy";
        }

    case BIKETYPE_NORMAL:
        {
            return "Normal";
        }

    case BIKETYPE_HARD:
        {
            return "Hard";
        }

    case BIKETYPE_INTERVALS:
        {
            return "Intervals";
        }

    case BIKETYPE_HILLS:
        {
            return "Hills";
        }

    case BIKETYPE_OTHER:
        {
            return "Other";
        }

	case BIKETYPE_MOUNTAINBIKE:
		{
			return "Mountain Bike";
		}

	case BIKETYPE_TIMETRIAL:
		{
			return "Time Trial";
		}

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::BikeWorkoutToString");
            return "NULL";
        }
    }
}
CString CUtil::SwimWorkoutToString(int nWorkout)
{
    switch(nWorkout)
    {
    case SWIMTYPE_DRILLS:
        {
            return "Drills";
        }

    case SWIMTYPE_EZ:
        {
            return "Easy";
        }

    case SWIMTYPE_NORMAL:
        {
            return "Normal";
        }

    case SWIMTYPE_HARD:
        {
            return "Hard";
        }

    case SWIMTYPE_INTERVALS:
        {
            return "Intervals";
        }

    case SWIMTYPE_OPENWATER:
        {
            return "Open Water";
        }

    case SWIMTYPE_OTHER:
        {
            return "Other";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::SwimWorkoutToString");
            return "NULL";
        }
    }
}


CString CUtil::StrengthWorkoutToString(int nWorkout)
{
    switch(nWorkout)
    {
    case STRENGTHTYPE_WEIGHTS:
        {
            return "Weights";
        }

    case STRENGTHTYPE_ABS:
        {
            return "Abs";
        }

    case STRENGTHTYPE_OTHER:
        {
            return "Other";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::StrengthWorkoutToString");
            return "NULL";
        }
    }
}


CString CUtil::RaceToString(int nWorkout)
{
    switch(nWorkout)
    {
    case RACETYPE_RUN:
        {
            return "Run";
        }

    case RACETYPE_BIKE:
        {
            return "Bike";
        }

    case RACETYPE_SWIM:
        {
            return "Swim";
        }

    case RACETYPE_DUATHLON:
        {
            return "Duathlon";
        }

    case RACETYPE_TRIATHLON:
        {
            return "Triathlon";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::WorkoutToString");
            return "NULL";
        }
    }
}


CString CUtil::ActivityToString(int nActivity)
{
    switch(nActivity)
    {
    case ACTIVITY_RUNNING:
        {
            return "Run";
        }

    case ACTIVITY_BIKING:
        {
            return "Bike";
        }
        
    case ACTIVITY_SWIMMING:
        {
            return "Swim";
        }

    case ACTIVITY_STRENGTH:
        {
            return "Strength";
        }

    case ACTIVITY_RACE:
        {
            return "Race";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::ActivityToString");
            return "NULL";
        }
    }
}


CString CUtil::DayToString(int nDay)
{
    switch(nDay)
    {
    case SUNDAY:
        {
            return "Sunday";
        }

    case MONDAY:
        {
            return "Monday";
        }

    case TUESDAY:
        {
            return "Tuesday";
        }

    case WEDNESDAY:
        {
            return "Wednesday";
        }

    case THURSDAY:
        {
            return "Thursday";
        }

    case FRIDAY:
        {
            return "Friday";
        }

    case SATURDAY:
        {
            return "Saturday";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::DayToString");
            return "NULL";
        }
    }
}


CString CUtil::MonthToString(int nMonth)
{
    switch(nMonth)
    {
    case JANUARY:
        {
            return "January";
        }

    case FEBRUARY:
        {
            return "February";
        }

    case MARCH:
        {
            return "March";
        }

    case APRIL:
        {
            return "April";
        }

    case MAY:
        {
            return "May";
        }

    case JUNE:
        {
            return "June";
        }
        
    case JULY:
        {
            return "July";
        }

    case AUGUST:
        {
            return "August";
        }

    case SEPTEMBER:
        {
            return "September";
        }

    case OCTOBER:
        {
            return "October";
        }

    case NOVEMBER:
        {
            return "November";
        }

    case DECEMBER:
        {
            return "December";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::MonthToString");
            return "NULL";
        }
    }
}


CString CUtil::RotationIncrementToString(int nNum)
{
	switch(nNum)
	{
	case ROTATION_15DEGREES:
		{
			return "15 Degrees";
		}

	case ROTATION_10DEGREES:
		{
			return "10 Degrees";
		}

	case ROTATION_5DEGREES:
		{
			return "5 Degrees";
		}

	case ROTATION_2DEGREES:
		{
			return "2 Degrees";
		}

	case ROTATION_1DEGREES:
		{
			return "1 Degree";
		}

	case ROTATION_N1DEGREES:
		{
			return "-1 Degree";
		}

	case ROTATION_N2DEGREES:
		{
			return "-2 Degrees";
		}

	case ROTATION_N5DEGREES:
		{
			return "-5 Degrees";
		}

	case ROTATION_N10DEGREES:
		{
			return "-10 Degrees";
		}

	case ROTATION_N15DEGREES:
		{
			return "-15 Degrees";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::RotationIncrementToString");
			return "NULL";
		}
	}
}


CString CUtil::GraphTypeToString(int nType)
{
	switch(nType)
	{
	case GRAPHTYPE_2D2D:
		{
			return "2D";
		}

	case GRAPHTYPE_3DBAR:
		{
			return "3D Bar";
		}

	case GRAPHTYPE_3DSCATTER:
		{
			return "3D Scatter";
		}

	case GRAPHTYPE_POLARPOLAR:
		{
			return "Polar";
		}

	case GRAPHTYPE_POLARSMITH:
		{
			return "Smith Polar";
		}

	case GRAPHTYPE_POLARROSE:
		{
			return "Rose Polar";
		}

	case GRAPHTYPE_PIE:
		{
			return "Pie";
		}

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::GraphTypeToString");
            return "NULL";
        }
	}
}


CString CUtil::TwoDSeriesType2DToString(int nType)
{
	switch(nType)
	{
	case TWODSERIESTYPE2D_LINE:
		{
			return "Line";
		}

		case TWODSERIESTYPE2D_BAR:
		{
			return "Bar";
		}

	case TWODSERIESTYPE2D_STICK:
		{
			return "Stick";
		}

	case TWODSERIESTYPE2D_POINTS:
		{
			return "Points";
		}

	case TWODSERIESTYPE2D_SPLINE:
		{
			return "Spline";
		}

	case TWODSERIESTYPE2D_AREA:
		{
			return "Area";
		}

	case TWODSERIESTYPE2D_RIBBON:
		{
			return "Ribbon";
		}

	case TWODSERIESTYPE2D_STEP:
		{
			return "Step";
		}

	case TWODSERIESTYPE2D_POINTSPLUSLINE:
		{
			return "Points + Line";
		}

	case TWODSERIESTYPE2D_POINTSPLUSBFL:
		{
			return "Points + Best Fit Line";
		}

	case TWODSERIESTYPE2D_POINTSPLUSBFC:
		{
			return "Points + Best Fit Curve";
		}

	case TWODSERIESTYPE2D_POINTSPLUSSPLINE:
		{
			return "Points + Spline";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::TwoDSeriesType2DToString");
			return "NULL";
		}
	}
}


CString CUtil::ThreeDSeriesTypeBarToString(int nType)
{
	switch(nType)
	{
	case THREEDSERIESTYPEBAR_WIREFRAME:
		{
			return "Wireframe";
		}

	case THREEDSERIESTYPEBAR_SURFACE:
		{
			return "Surface";
		}

	case THREEDSERIESTYPEBAR_SURFACEPIXELS:
		{
			return "Points";
		}

	case THREEDSERIESTYPEBAR_SURFACESHADING:
		{
			return "Surface with Shading";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::ThreeDSeriesTypeBarToString");
			return "NULL";
		}
	}
}


CString CUtil::ThreeDSeriesTypeScatterToString(int nType)
{
	switch(nType)
	{
	case THREEDSERIESTYPESCATTER_POINTS:
		{
			return "Points";
		}

	case THREEDSERIESTYPESCATTER_LINE:
		{
			return "Line";
		}

	case THREEDSERIESTYPESCATTER_POINTSPLUSLINE:
		{
			return "Points + Line";
		}

	case THREEDSERIESTYPESCATTER_AREA:
		{
			return "Waterfall";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::ThreeDSeriesTypeScatterToString");
			return "NULL";
		}
	}
}


CString CUtil::PolarSeriesTypePolarToString(int nType)
{
	switch(nType)
	{
	case POLARSERIESTYPEPOLAR_POINTS:
		{
			return "Points";
		}

	case POLARSERIESTYPEPOLAR_LINE:
		{
			return "Line";
		}

	case POLARSERIESTYPEPOLAR_POINTSPLUSLINE:
		{
			return "Points + Line";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PolarSeriesTypePolarToString");
			return "NULL";
		}
	}
}


CString CUtil::PolarSeriesTypeSmithToString(int nType)
{
	switch(nType)
	{
	case POLARSERIESTYPESMITH_POINTS:
		{
			return "Points";
		}

	case POLARSERIESTYPESMITH_LINE:
		{
			return "Line";
		}

	case POLARSERIESTYPESMITH_POINTSPLUSLINE:
		{
			return "Points + Line";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PolarSeriesTypeSmithToString");
			return "NULL";
		}
	}
}


CString CUtil::PolarSeriesTypeRoseToString(int nType)
{
	switch(nType)
	{
	case POLARSERIESTYPEROSE_POINTS:
		{
			return "Points";
		}

	case POLARSERIESTYPEROSE_LINE:
		{
			return "Line";
		}

	case POLARSERIESTYPEROSE_POINTSPLUSLINE:
		{
			return "Points + Line";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PolarSeriesTypeRoseToString");
			return "NULL";
		}
	}
}


CString CUtil::PieSeriesTypeToString(int nType)
{
	switch(nType)
	{
	case PIESERIESTYPE_VALUE:
		{
			return "Value";
		}

	case PIESERIESTYPE_PERCENTAGE:
		{
			return "Percentage";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PieSeriesTypeToString");
			return "NULL";
		}
	}
}


CString CUtil::PointSelectionTypeToString(int nType)
{
	switch(nType)
	{
	case POINTSELECTION_NONE:
		{
			return "None";
		}

	case POINTSELECTION_SQUARE:
		{
			return "Square";
		}

	case POINTSELECTION_CROSSHAIR:
		{
			return "Crosshair";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PointTypeSelectionToString");
			return "NULL";
		}
	}
}


CString CUtil::PointTypeToString(int nType)
{
	switch(nType)
	{
	case POINTTYPE_PLUS:
		{
			return "Plus";
		}

	case POINTTYPE_CROSS:
		{
			return "Cross";
		}

	case POINTTYPE_CIRCLE:
		{
			return "Circle";
		}

	case POINTTYPE_FILLEDCIRCLE:
		{
			return "Filled Circle";
		}

	case POINTTYPE_SQUARE:
		{
			return "Square";
		}

	case POINTTYPE_FILLEDSQUARE:
		{
			return "Filled Square";
		}

	case POINTTYPE_DIAMOND:
		{
			return "Diamond";
		}

	case POINTTYPE_FILLEDDIAMOND:
		{
			return "Filled Diamond";
		}

	case POINTTYPE_UPWARDTRI:
		{
			return "Upward Triangle";
		}

	case POINTTYPE_FILLEDUPWARDTRI:
		{
			return "Filled Upward Triangle";
		}

	case POINTTYPE_DOWNWARDTRI:
		{
			return "Downward Triangle";
		}

	case POINTTYPE_FILLEDDOWNWARDTRI:
		{
			return "Filled Downward Triangle";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PointTypeToString");
			return "NULL";
		}
	}
}


CString CUtil::LineTypeToString(int nType)
{
	switch(nType)
	{
	case LINETYPE_THIN:
		{
			return "Thin";
		}

	case LINETYPE_MEDIUMTHIN:
		{
			return "Medium Thin";
		}

	case LINETYPE_MEDIUM:
		{
			return "Medium";
		}

	case LINETYPE_MEDIUMTHICK:
		{
			return "Medium Thick";
		}

	case LINETYPE_THICK:
		{
			return "Thick";
		}

	case LINETYPE_EXTRATHICK:
		{
			return "Extra Thick";
		}

	case LINETYPE_DASH:
		{
			return "Dash";
		}

	case LINETYPE_DOT:
		{
			return "Dot";
		}

	case LINETYPE_DASHDOT:
		{
			return "Dash Dot";
		}

	case LINETYPE_DASHDOTDOT:
		{
			return "Dash Dot Dot";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::LineTypeToString");
			return "NULL";
		}
	}
}


CString CUtil::LegendLocationToString(int nLoc)
{
	switch(nLoc)
	{
	case LEGENDLOC_TOP:
		{
			return "Top";
		}

	case LEGENDLOC_RIGHT:
		{
			return "Right";
		}

	case LEGENDLOC_BOTTOM:
		{
			return "Bottom";
		}

	case LEGENDLOC_LEFT:
		{
			return "Left";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::LegendLocationToString");
			return "NULL";
		}
	}
}


CString CUtil::DataTypeToString(int nType, bool fForTitle)
{
    switch(nType)
    {
    case DATATYPE_TIME: 
        {
            return "Time";
        }

    case DATATYPE_MINUTESRUN:
        {
            return "Running Minutes";
        }

    case DATATYPE_MINUTESBIKE:
        {
            return "Cycling Minutes";
        }

    case DATATYPE_MINUTESSWIM:
        {
            return "Swimming Minutes";
        }

    case DATATYPE_MINUTESSTRENGTH:
        {
            return "Strength Work Minutes";
        }

    case DATATYPE_MINUTESOVERALL:
        {
            return "Overall Minutes";
        }

    case DATATYPE_WORKOUTSRUN:
        {
            return "Running Workouts";
        }

    case DATATYPE_WORKOUTSBIKE:
        {
            return "Cycling Workouts";
        }

    case DATATYPE_WORKOUTSSWIM:
        {
            return "Swimming Workouts";
        }

    case DATATYPE_WORKOUTSSTRENGTH:
        {
            return "Strength Workouts";
        }

    case DATATYPE_WORKOUTSOVERALL:
        {
            return "Overall Workouts";
        }

    case DATATYPE_MILESRUN:
        {
            if(fForTitle)
            {
                return "Running Distance";
            }
            else
            {
                return CUtil::GetRunDistString("Running Distance");
            }
        }

    case DATATYPE_MILESBIKE:
        {
            if(fForTitle)
            {
                return "Cycling Distance";
            }
            else
            {
                return CUtil::GetBikeDistString("Cycling Distance");
            }
        }

    case DATATYPE_MILESSWIM:
        {
            if(fForTitle)
            {
                return "Swimming Distance";
            }
            else
            {
                return CUtil::GetSwimDistString("Swimming Distance");
            }
        }

    case DATATYPE_TEMP:
        {
            if(fForTitle)
            {
                return "Temperature";
            }
            else
            {
                return "Average Temperature";
            }
        }

    case DATATYPE_HR:
        {
            if(fForTitle)
            {
                return "Heartrate";
            }
            else
            {
                return "Average Heartrate";
            }
        }

    case DATATYPE_PACERUN:
        {
            if(fForTitle)
            {
                return "Running Pace";
            }
            else
            {
                return CUtil::GetPaceString(FORMAT_RUN, "Running Pace");
            }
        }

    case DATATYPE_PACEBIKE:
        {
            if(fForTitle)
            {
                return "Cycling Pace";
            }
            else
            {
                return CUtil::GetPaceString(FORMAT_BIKE, "Cycling Pace");
            }
        }

    case DATATYPE_PACESWIM:
        {
            if(fForTitle)
            {
                return "Swimming Pace";
            }
            else
            {
                return CUtil::GetPaceString(FORMAT_SWIM, "Swimming Pace");
            }
        }

    case DATATYPE_SLEEP:
        {
            if(fForTitle)
            {
                return "Sleep";
            }
            else
            {
                return "Average Sleep";
            }
        }

    case DATATYPE_WEIGHT:
        {
            if(fForTitle)
            {
                return "Weight";
            }
            else
            {
                return "Average Weight";
            }
        }

    case DATATYPE_POINTS:
        {
            return "Points";
        }

    case DATATYPE_TIMEOFDAY:
        {
            return "Time of Day";
        }

 	case DATATYPE_CALORIES:
		{
			return "Calories";
		}  
	
	case DATATYPE_FORMULA:
        {
            return "Formula";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::DataTypeToString");
            return "NULL";
        }
    }
}


CString CUtil::SearchTypeToString(int nType)
{
    switch(nType)
    {
    case SEARCHTYPE_MINUTESRUN:
        {
            return "Running Minutes";
        }

    case SEARCHTYPE_MINUTESBIKE:
        {
            return "Cycling Minutes";
        }

    case SEARCHTYPE_MINUTESSWIM:
        {
            return "Swimming Minutes";
        }

    case SEARCHTYPE_MINUTESSTRENGTH:
        {
            return "Strength Work Minutes";
        }

    case SEARCHTYPE_MINUTESOVERALL:
        {
            return "Overall Minutes";
        }

    case SEARCHTYPE_WORKOUTSRUN:
        {
            return "Running Workouts";
        }

    case SEARCHTYPE_WORKOUTSBIKE:
        {
            return "Cycling Workouts";
        }

    case SEARCHTYPE_WORKOUTSSWIM:
        {
            return "Swimming Workouts";
        }

    case SEARCHTYPE_WORKOUTSSTRENGTH:
        {
            return "Strength Workouts";
        }

    case SEARCHTYPE_WORKOUTSOVERALL:
        {
            return "Overall Workouts";
        }

    case SEARCHTYPE_MILESRUN:
        {
            return "Running Distance";
		}

    case SEARCHTYPE_MILESBIKE:
        {
			return "Cycling Distance";
        }

    case SEARCHTYPE_MILESSWIM:
        {
            return "Swimming Distance";
        }

    case SEARCHTYPE_TEMP:
        {
			return "Temperature";
        }

    case SEARCHTYPE_HR:
        {
            return "Heartrate";
        }

    case SEARCHTYPE_PACERUN:
        {
            return "Running Pace";
        }

    case SEARCHTYPE_PACEBIKE:
        {
            return "Cycling Pace";
        }

    case SEARCHTYPE_PACESWIM:
        {
            return "Swimming Pace";
        }

    case SEARCHTYPE_SLEEP:
        {
            return "Sleep";
        }

    case SEARCHTYPE_WEIGHT:
        {
            return "Weight";
        }

    case SEARCHTYPE_POINTS:
        {
            return "Points";
        }

 	case SEARCHTYPE_CALORIES:
		{
			return "Calories";
		}  

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::SearchTypeToString");
            return "NULL";
        }
    }
}


CString CUtil::RelationTypeToString(int nType)
{
	switch(nType)
	{
	case RELATIONTYPE_LTE:
		{
			return "<=";
		}

	case RELATIONTYPE_LT:
		{
			return "<";
		}

	case RELATIONTYPE_EQ:
		{
			return "=";
		}

	case RELATIONTYPE_GT:
		{
			return ">";
		}

	case RELATIONTYPE_GTE:
		{
			return ">=";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::RelationTypeToString");
			return "NULL";
		}
	}
}


CString CUtil::SearchForToString(int nType)
{
	switch(nType)
	{
	case SEARCHFOR_DAY:
		{
			return "Days";
		}

	case SEARCHFOR_WEEK:
		{
			return "Weeks";
		}

	case SEARCHFOR_MONTH:
		{
			return "Months";
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::SearchForToString");
			return "NULL";
		}
	}
}


CString CUtil::WindToString(int nWind)
{
    switch(nWind)
    {
    case WIND_NONE:
        {
            return "None";
        }

    case WIND_LIGHT:
        {
            return "Light";
        }
        
    case WIND_STRONG:
        {
            return "Strong";
        }

	case WIND_MEDIUM:
		{
			return "Medium";
		}

	case WIND_VERYSTRONG:
		{
			return "Very strong";
		}

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::WindToString");
            return "NULL";
        }
    }
}


CString CUtil::ChoppinessToString(int nAmount)
{
    switch(nAmount)
    {
    case CHOPPINESS_NONE:
        {
            return "None";
        }

    case CHOPPINESS_LIGHT:
        {
            return "Light";
        }
        
    case CHOPPINESS_HEAVY:
        {
            return "Heavy";
        }

	case CHOPPINESS_MEDIUM:
		{
			return "Medium";
		}

	case CHOPPINESS_VERYHEAVY:
		{
			return "Very heavy";
		}

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::ChoppinessToString");
            return "NULL";
        }
    }
}


CString CUtil::UnitsToString(int nUnits)
{
    switch(nUnits)
    {
    case DISTUNITS_MI:
        {
            return "Miles";
        }

    case DISTUNITS_KM: 
        {
            return "Kilometers";
        }

    case DISTUNITS_M:
        {
            return "Meters";
        }

    case DISTUNITS_YD:
        {
            return "Yards";
        }

    case DISTUNITS_FT:
        {
            return "Feet";
        }

    case DISTUNITS_IN:
        {
            return "Inches";
        }

    case DISTUNITS_PSC:
        {
            return "Parsec";
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::UnitsToString");
            return "NULL";
        }
    }
}


bool CUtil::IsDateValid(COleDateTime tm)
{
    return (tm.GetStatus() == COleDateTime::valid);
}


COLORREF CUtil::GetRandomColor(void)
{
    COLORREF acr[8] = {RGB(251, 177, 40), 
                       RGB(64, 227, 68), 
                       RGB(49, 54, 242), 
                       RGB(204, 30, 200),
                       RGB(223, 235, 10), 
                       RGB(89, 155, 113), 
                       RGB(173, 122, 71), 
                       RGB(151, 0, 0)};
    return acr[rand() % 8];
}


COLORREF CUtil::GetRandomColor2(void)
{
	if(rand() % 4 == 0)   // preferentially generate lighter colors
	{
		return RGB(rand() % 256, rand() % 256, rand() % 256);
	}
	else
	{
		return RGB(rand () % 176 + 80, rand () % 176 + 80, rand () % 176 + 80);
	}
}


double CUtil::GetDouble(int nWhole, CString strFrac)
{
    double dRes = (double)nWhole;
    
    CString strNew = ".";
    strNew += strFrac;

    double dFrac = atof(strNew);

    return dRes + dFrac;
}


double CUtil::FigureOutNormalSpecial(double dNormal, double dSpecial, bool fNormal, bool fSpecial)
{
    if((fNormal) && (fSpecial))
    {
        if(CUtil::HasNoData(dNormal))
        {
            if(CUtil::HasNoData(dSpecial))
            {
                return NOGRAPHDATA;
            }
            else
            {
                return dSpecial;
            }
        }
        else
        {
            return dNormal;
        }
    }

    else if((fNormal) && (!fSpecial))
    {
        if(CUtil::HasNoData(dNormal))
        {
            return NOGRAPHDATA;
        }
        else
        {
            if(CUtil::HasNoData(dSpecial))
            {
                return dNormal;
            }
            else
            {
                return dNormal - dSpecial;
            }
        }
    }

    else if((!fNormal) && (fSpecial))
    {
        if(CUtil::HasNoData(dSpecial))
        {
            return NOGRAPHDATA;
        }
        else
        {
            return dSpecial;
        }
    }

    return NOGRAPHDATA;
}


void CUtil::OrderArray(int* pnArray, COleDateTime* ptmArray, int nNum, bool bEarlyToLate /* = false */)
{
    if((NULL == pnArray) || (NULL == ptmArray))
    {
        return;
    }

    for(int i = 0; i < nNum; i++)
    {
        pnArray[i] = i;
    }

    for(int i = 0; i < nNum; i++)
    {
        COleDateTime tmTemp = ptmArray[i];
        int nTemp = pnArray[i];

        // do early to late
        if(true == bEarlyToLate)
        {
            for(int j = i; j > 0 && !CUtil::IsLaterThan(tmTemp, ptmArray[pnArray[j - 1]]); j--)
            {
                pnArray[j] = pnArray[j - 1];
            }
            pnArray[j] = nTemp;
        }
        else
        {
            for(int j = i; j > 0 && CUtil::IsLaterThan(tmTemp, ptmArray[pnArray[j - 1]]); j--)
            {
                pnArray[j] = pnArray[j - 1];
            }
            pnArray[j] = nTemp;
        }

    }
}


bool CUtil::GetDistConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor)
{
    double adMilesToX[] = {1.000000, 1.609344, 1609.344, 1760.000000, 5280.0000, 63360.0000, 5.215527997e-14};

    if((nStartUnits < 0) || (nStartUnits >= NUM_DISTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_DISTUNITS))
    {
        return false;
    }

    rdFactor = adMilesToX[nEndUnits] / adMilesToX[nStartUnits];
    return true;
}


double CUtil::ConvertDistance(int nStartUnits, int nEndUnits, double dDist)
{
    if(CUtil::HasNoData(dDist))
    {
        return NOGRAPHDATA;
    }

    if((nStartUnits < 0) || (nStartUnits >= NUM_DISTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_DISTUNITS))
    {
        return NOGRAPHDATA;
    }

    double dFactor = 1.0;
    CUtil::GetDistConversionFactor(nStartUnits, nEndUnits, dFactor);

    return dDist * dFactor;
}   


bool CUtil::GetHeightConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor)
{
    double adInchesToX[] = {1.000000, 2.540000};

    if((nStartUnits < 0) || (nStartUnits >= NUM_HEIGHTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_HEIGHTUNITS))
    {
        return false;
    }

    rdFactor = adInchesToX[nEndUnits] / adInchesToX[nStartUnits];
    return true;
}


int CUtil::ConvertHeight(int nStartUnits, int nEndUnits, int nHeight)
{
    if(CUtil::HasNoData(nHeight))
    {
        return NOGRAPHDATA;
    }

    if((nStartUnits < 0) || (nStartUnits >= NUM_HEIGHTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_HEIGHTUNITS))
    {
        return NOGRAPHDATA;
    }

    double dFactor = 1.0;
    CUtil::GetHeightConversionFactor(nStartUnits, nEndUnits, dFactor);

    return (int)((double)nHeight * dFactor);
}  


bool CUtil::GetWeightConversionFactor(int nStartUnits, int nEndUnits, double& rdFactor)
{
    double adPoundsToX[] = {1.000000, 0.4535924};

    if((nStartUnits < 0) || (nStartUnits >= NUM_WEIGHTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_WEIGHTUNITS))
    {
        return false;
    }

    rdFactor = adPoundsToX[nEndUnits] / adPoundsToX[nStartUnits];
    return true;
}


double CUtil::ConvertWeight(int nStartUnits, int nEndUnits, double dWeight)
{
    if(CUtil::HasNoData(dWeight))
    {
        return NOGRAPHDATA;
    }

    if((nStartUnits < 0) || (nStartUnits >= NUM_WEIGHTUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_WEIGHTUNITS))
    {
        return NOGRAPHDATA;
    }

    double dFactor = 1.0;
    CUtil::GetWeightConversionFactor(nStartUnits, nEndUnits, dFactor);

    return dWeight * dFactor;
}  


int CUtil::ConvertTemperature(int nStartUnits, int nEndUnits, int nTemp)
{
	if(CUtil::HasNoData(nTemp))
    {
        return NOGRAPHDATA;
    }

    if((nStartUnits < 0) || (nStartUnits >= NUM_TEMPERATUREUNITS) || (nEndUnits < 0) || (nEndUnits >= NUM_TEMPERATUREUNITS))
    {
        CUtil::Fatal("Bad parameter to CUtil::ConvertTemperature");
        return NOGRAPHDATA;
    }

    if(nStartUnits == nEndUnits)
    {
        return nTemp;
    }

    if((nStartUnits == TEMPUNITS_DEG) && (nEndUnits == TEMPUNITS_CELSIUS))
    {
        return (int)(((double)nTemp - 32.0) / 1.8);
    }
    
    if((nStartUnits == TEMPUNITS_CELSIUS) && (nEndUnits == TEMPUNITS_DEG))
    {
        return (int)((double)nTemp * 1.8 + 32.0);
    }

    return NOGRAPHDATA;
}
    

void CUtil::OptionallySetLatest(COleDateTime* ptmArray, COleDateTime tmCur, int nID, int nNum)
{
    if((nID < 0) || (nID >= nNum) || (NULL == ptmArray))
    {
        return;
    }
    if(CUtil::IsLaterThan(tmCur, ptmArray[nID]))
    {
        ptmArray[nID] = tmCur;
    }
}


CString CUtil::TrimStringToFit(CDC* pDC, CString str, int nWidth)
{
    if(NULL == pDC)
    {
        CUtil::Fatal("Bad parameter to CUtil::TrimStringToFit");
        return str;
    }

    int nWidthEllipsis = pDC->GetTextExtent("...").cx;

    // if the width is too skinny to display even an ellipsis, don't display anything
    if(nWidth < nWidthEllipsis)
    {
        return NULL;
    }

    int nCurWidth = pDC->GetTextExtent(str).cx;
    int nLen = str.GetLength();

    // if the width is less than the available width, we're fine
    if(nCurWidth < nWidth)
    {
        return str;
    }

    while(nCurWidth + nWidthEllipsis > nWidth)
    {
        if(str.IsEmpty())
        {
            break;
        }

        str = str.Left(str.GetLength() - 1);
        nCurWidth = pDC->GetTextExtent(str).cx;
    }

    // cut one extra char off just to make sure
    if(!str.IsEmpty())
    {
        str = str.Left(str.GetLength() - 1);
    }
    
    str += "...";

    return str;
}


bool CUtil::SaveXML(CUser* pUser, CString strForced /* = "" */)
{
    CWinApp* pApp = AfxGetApp();
    if((NULL == pUser) || (NULL == pApp))
    {
        return false;
    }

    CString strFile;

    if(strForced.GetLength() > 0)
    {
        strFile = strForced;
    }
    else
    {
        strFile = CUtil::GetExeDirectory();

        strFile += pUser->GetFirstName();
        strFile += " ";
        strFile += pUser->GetLastName();
        strFile += CUtil::GetFileExtension();  
    }

    CXMLSerializer xmlSerialize;
    return xmlSerialize.WriteFile(pUser, strFile);
}


bool CUtil::ReadXML(CUser* pUser, CString strLocal)
{
    CString strFile = CUtil::GetExeDirectory();
    strFile += strLocal;
    strFile += CUtil::GetFileExtension();

    CXMLSerializer xmlSerialize;
    return xmlSerialize.ReadFile(pUser, strFile);
}


void CUtil::DeleteLocalFile(CString strLocal)
{
    CString strFile = CUtil::GetExeDirectory();
    strFile += strLocal;
    strFile += CUtil::GetFileExtension();

    ::DeleteFile(strFile);
}


CString CUtil::GetExeDirectory(void)
{
    CString strFile = _pgmptr;
    int n = strFile.ReverseFind('\\');
    return strFile.Left(n + 1);
}


CString CUtil::GetFileExtension(void)
{
    return ".tlg"; 
}


int CUtil::GetDefaultBaseTypeRun(void)
{
    return BASED_ON_DISTANCE;
}


int CUtil::GetDefaultBaseTypeBike(void)
{
    return BASED_ON_DISTANCE;
}


int CUtil::GetDefaultBaseTypeSwim(void)
{
    return BASED_ON_DISTANCE;
}


int CUtil::GetDefaultPaceFormatRun(void)
{
    return PACEFORMAT_MINDIST;
}


int CUtil::GetDefaultPaceFormatBike(void)
{
    return PACEFORMAT_DISTHR;
}


int CUtil::GetDefaultPaceFormatSwim(void)
{
    return PACEFORMAT_MIN100M;
}


bool CUtil::GetDefaultDisplayInfo(int nActivity)
{
    // default is to display all, so no checking is needed
    return true;
}


COLORREF CUtil::GetDefaultMonthCtrlBgColor(void)
{
	return CUtil::GetDefaultGradientColor(false);
}


COLORREF CUtil::GetDefaultMonthCtrlTextColor(void)
{
	return RGB(0, 0, 0);
}


COLORREF CUtil::GetDefaultMonthCtrlTitleTextColor(void)
{
	return RGB(255, 255, 255);
}


COLORREF CUtil::GetDefaultMonthCtrlTrailingTextColor(void)
{
	return RGB(100, 100, 100);
}


COLORREF CUtil::GetDefaultMonthCtrlHeadingColor(void)
{
	return CUtil::GetDefaultGradientColor(true);
}


COLORREF CUtil::GetDefaultBgColor(void)
{
    return RGB(124, 135, 231);
}


COLORREF CUtil::GetDefaultDayColor(int nType)
{
    switch(nType)
    {
    case DAYTYPE_NORMAL:
        {
            return RGB(255, 255, 255);
        }

    case DAYTYPE_GRAYED:
        {
            return RGB(230, 230, 230);
        }

    case DAYTYPE_MONTHSUM:
        {
            return RGB(243, 245, 175);
        }

    case DAYTYPE_WEEKSUM:
        {
            return RGB(243, 245, 175);
        }

    default:
        {
            CUtil::Fatal("Bad parameter to CUtil::GetDayColor");
            return RGB(0, 0, 0);
        }
    }
}


COLORREF CUtil::GetDefaultButtonColor(void)
{
    return RGB(209, 230, 196);  
}


COLORREF CUtil::GetDefaultHighlightColor(void)
{
    return RGB(198, 254, 110);   // 255, 243, 55 yellow
}


COLORREF CUtil::GetDefaultShadowColor(bool bOne)
{
    if(bOne)
    {
        return RGB(20, 20, 20);
    }
    else
    {
        return RGB(200, 200, 200);
    }
}


COLORREF CUtil::GetDefaultGradientColor(bool bBegin)
{
    if(bBegin)
    {
        return RGB(77, 140, 19);
    }
    else
    {
        return RGB(226, 231, 52);
    }
}


COLORREF CUtil::GetDefaultHeadingTextColor(void)
{
    return RGB(250, 250, 250);
}


COLORREF CUtil::GetDefaultDayTextColor(void)
{
    return RGB(10, 10, 10);
}


COLORREF CUtil::GetDefaultAnnotationTextColor(void)
{
    return RGB(213, 43, 43);
}


COLORREF CUtil::GetDefaultRaceDayColor(void)
{
    return RGB(255, 188, 121);
}


COLORREF CUtil::GetDefaultUpcomingRaceDayColor(void)
{
    return RGB(254, 226, 131);
}


COLORREF CUtil::GetDefaultUpcomingWorkoutDayColor(void)
{
    return RGB(181, 253, 214);
}


COLORREF CUtil::GetDefaultEditBgColor(void)
{
    return RGB(228, 249, 190);
}


int CUtil::GetDefaultDlgAnimationTime(void)
{
	return 3;
}


int CUtil::GetDefaultRunDecimals(void)
{
	return 1;
}


int CUtil::GetDefaultBikeDecimals(void)
{
	return 1;
}


int CUtil::GetDefaultSwimDecimals(void)
{
	return 1;
}


void CUtil::Fatal(CString str)
{
#ifdef _DEBUG
    AfxMessageBox(str);
#endif // _DEBUG
}




