#include "StdAfx.h"
#include "Workout.h"
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
#include "RunningLog.h"
#include "Util.h"
#include "DayLog.h"


CDayLog::CDayLog(void)
{
}


CDayLog::~CDayLog()
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < (int)rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            delete pWorkout;
            pWorkout = NULL;
            rarWorkouts.SetAt(i, NULL);
        }
    }
    rarWorkouts.RemoveAll();
}


COleDateTime CDayLog::GetDate(void) const
{
    return m_tmDay;
}


void CDayLog::SetDate(COleDateTime tm)
{
    m_tmDay = tm;
}


double CDayLog::GetAverageTemperature(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();
    int nUsed = 0;

    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nCur = pWorkout->GetTemperature();
            if(CUtil::HasData(nCur))
            {
                dTotal += (double)nCur;
                nUsed++;
            }
        }
    }
    if(0 == nUsed)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTotal / (double)nUsed);
    }
}


double CDayLog::GetAverageHR(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();
    int nUsed = 0;

    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nCur = pWorkout->GetHR();
            if(CUtil::HasData(nCur))
            {
                dTotal += (double)nCur;
                nUsed++;
            }
        }
    }
    if(0 == nUsed)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTotal / (double)nUsed);
    }
}


double CDayLog::GetAverageSleep(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();
    int nUsed = 0;
    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            double dCur = pWorkout->GetPrevNightSleep();
            if(CUtil::HasData(dCur))
            {
                dTotal += dCur;
                nUsed++;
            }
        }
    }
    if(0 == nUsed)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTotal / (double)nUsed);
    }
}


double CDayLog::GetAverageWeight(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();
    int nUsed = 0;

    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            double dCur = pWorkout->GetWeight();
            if(CUtil::HasData(dCur))
            {
                dTotal += dCur;
                nUsed++;
            }
        }
    }
    if(0 == nUsed)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTotal / (double)nUsed);
    }
}


double CDayLog::GetTotalCalories(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();

    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
			if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
			{
				dTotal += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles());
			}
			else if(ACTIVITY_BIKING == pWorkout->GetActivityType())
			{
				dTotal += CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
			}
			else if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
			{
				dTotal += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
			}
			else if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
			{
				dTotal += CUtil::ComputeStrengthCalories(pWorkout->GetWeight(), pWorkout->GetSeconds());
			}
			else if(ACTIVITY_RACE == pWorkout->GetActivityType())
			{
				if(RACETYPE_RUN == pWorkout->GetType())
				{
					dTotal += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetMiles());
				}
				else if(RACETYPE_BIKE == pWorkout->GetType())
				{
					dTotal += CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
				}
				else if(RACETYPE_SWIM == pWorkout->GetType())
				{
					dTotal += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetMiles(), pWorkout->GetSeconds());
				}
				else if(RACETYPE_DUATHLON == pWorkout->GetType())
				{
					dTotal += CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles()) +
						      CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
							  CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles());
				}
				else if(RACETYPE_TRIATHLON == pWorkout->GetType())
				{
					dTotal += CUtil::ComputeSwimCalories(pWorkout->GetWeight(), pWorkout->GetLeg1Miles(), pWorkout->GetLeg1Seconds()) +
							  CUtil::ComputeBikeCalories(pWorkout->GetWeight(), pWorkout->GetLeg2Miles(), pWorkout->GetLeg2Seconds()) +
						      CUtil::ComputeRunCalories(pWorkout->GetWeight(), pWorkout->GetLeg3Miles());
				}
			}       
		}
    }

	return dTotal;
}


double CDayLog::GetAverageTimeOfDay(void)
{
    double dTotal = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    int nCount = (int)rarWorkouts.GetCount();
    int nUsed = 0;

    for(int i = 0; i < nCount; i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            COleDateTime tmCur = pWorkout->GetTimeStart();
            double dCur = CUtil::DateTimeTo24Hours(tmCur);
            if(CUtil::HasData(dCur))
            {
                dTotal += dCur;
                nUsed++;
            }
        }
    }
    if(0 == nUsed)
    {
        return NOGRAPHDATA;
    }
    else
    {
        return (dTotal / (double)nUsed);
    }
}


double CDayLog::SumMilesRun(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetMiles();
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_RUN == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetMiles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        double dCur1 = pWorkout->GetLeg1Miles();
                        if(CUtil::HasData(dCur1))
                        {
                            dMiles += dCur1;
                        }
                        double dCur2 = pWorkout->GetLeg3Miles();
                        if(CUtil::HasData(dCur2))
                        {
                            dMiles += dCur2;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur2 = pWorkout->GetLeg3Miles();
                        if(CUtil::HasData(dCur2))
                        {
                            dMiles += dCur2;
                        }
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumMilesRun(CShoesRun* pShoes)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            bool fNormal = (pShoes == pWorkout->GetShoesRun());
            bool fSpecial = (pShoes == pWorkout->GetSpecialShoesRun());
            fSpecial |= ((fNormal) && (NULL == pWorkout->GetSpecialShoesRun()));
            bool fLeg1 = (pShoes == pWorkout->GetLeg1Shoes());
            bool fRaceLeg1 = (pShoes == pWorkout->GetLeg1RaceShoes());
            bool fLeg3 = (pShoes == pWorkout->GetLeg3Shoes());
            bool fRaceLeg3 = (pShoes == pWorkout->GetLeg3RaceShoes());
            
            if((ACTIVITY_RUNNING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnShoes()))
            {
                double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetMiles(), pWorkout->GetSpecialMiles(), fNormal, fSpecial);
                if(CUtil::HasData(dCur))
                {
                    dMiles += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_RUN == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetMiles(), pWorkout->GetSpecialMiles(), fNormal, fSpecial);
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur1 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg1Miles(), pWorkout->GetLeg1RaceMiles(), fLeg1, fRaceLeg1);
                    if(CUtil::HasData(dCur1))
                    {
                        dMiles += dCur1;
                    }

                    double dCur2 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg3Miles(), pWorkout->GetLeg3RaceMiles(), fLeg3, fRaceLeg3);
                    if(CUtil::HasData(dCur2))
                    {
                        dMiles += dCur2;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur2 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg3Miles(), pWorkout->GetLeg3RaceMiles(), fLeg3, fRaceLeg3);
                    if(CUtil::HasData(dCur2))
                    {
                        dMiles += dCur2;
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumMilesBike(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_BIKING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetMiles();
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_BIKE == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetMiles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg2Miles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg2Miles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumMilesBike(CShoesBike* pShoes)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            bool fNormal = (pShoes == pWorkout->GetShoesBike());
            bool fSpecial = (pShoes == pWorkout->GetSpecialShoesBike());
            fSpecial |= ((fNormal) && (NULL == pWorkout->GetSpecialShoesBike()));
            bool fLeg2 = (pShoes == pWorkout->GetLeg2Shoes());
            bool fRaceLeg2 = (pShoes == pWorkout->GetLeg2RaceShoes());
            
            if((ACTIVITY_BIKING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnShoes()))
            {
                double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetMiles(), pWorkout->GetSpecialMiles(), fNormal, fSpecial);
                if(CUtil::HasData(dCur))
                {
                    dMiles += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetMiles(), pWorkout->GetSpecialMiles(), fNormal, fSpecial);
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg2Miles(), pWorkout->GetLeg2RaceMiles(), fLeg2, fRaceLeg2);
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg2Miles(), pWorkout->GetLeg2RaceMiles(), fLeg2, fRaceLeg2);
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumMilesBike(CBike* pBike)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            bool fNormal = (pBike == pWorkout->GetBike());

            if((ACTIVITY_BIKING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnBike()))
            {
                double dCur = pWorkout->GetMiles();
                if((CUtil::HasData(dCur)) && (true == fNormal))
                {
                    dMiles += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetMiles();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dMiles += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetLeg2Miles();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dMiles += dCur;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetLeg2Miles();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dMiles += dCur;
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumMilesSwim(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dMiles = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetMiles();
                    if(CUtil::HasData(dCur))
                    {
                        dMiles += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_SWIM == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetMiles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg1Miles();
                        if(CUtil::HasData(dCur))
                        {
                            dMiles += dCur;
                        }
                    }
                }
            }
        }
    }

    return dMiles;
}


double CDayLog::SumSecondsRun(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetSeconds();
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_RUN == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetSeconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        double dCur1 = pWorkout->GetLeg1Seconds();
                        if(CUtil::HasData(dCur1))
                        {
                            dSeconds += dCur1;
                        }

                        double dCur2 = pWorkout->GetLeg3Seconds();
                        if(CUtil::HasData(dCur2))
                        {
                            dSeconds += dCur2;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur2 = pWorkout->GetLeg3Seconds();
                        if(CUtil::HasData(dCur2))
                        {
                            dSeconds += dCur2;
                        }
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsRun(CShoesRun* pShoes)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            bool fNormal = (pShoes == pWorkout->GetShoesRun());
            bool fSpecial = (pShoes == pWorkout->GetSpecialShoesRun());
            fSpecial |= ((fNormal) && (NULL == pWorkout->GetSpecialShoesRun()));
            bool fLeg1 = (pShoes == pWorkout->GetLeg1Shoes());
            bool fRaceLeg1 = (pShoes == pWorkout->GetLeg1RaceShoes());
            bool fLeg3 = (pShoes == pWorkout->GetLeg3Shoes());
            bool fRaceLeg3 = (pShoes == pWorkout->GetLeg3RaceShoes());
            
            if((ACTIVITY_RUNNING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnShoes()))
            {
                double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetSeconds(), pWorkout->GetSpecialSeconds(), fNormal, fSpecial);
                if(CUtil::HasData(dCur))
                {
                    dSeconds += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_RUN == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetSeconds(), pWorkout->GetSpecialSeconds(), fNormal, fSpecial);
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur1 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg1Seconds(), pWorkout->GetLeg1RaceSeconds(), fLeg1, fRaceLeg1);
                    if(CUtil::HasData(dCur1))
                    {
                        dSeconds += dCur1;
                    }

                    double dCur2 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg3Seconds(), pWorkout->GetLeg3RaceSeconds(), fLeg3, fRaceLeg3);
                    if(CUtil::HasData(dCur2))
                    {
                        dSeconds += dCur2;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur2 = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg3Seconds(), pWorkout->GetLeg3RaceSeconds(), fLeg3, fRaceLeg3);
                    if(CUtil::HasData(dCur2))
                    {
                        dSeconds += dCur2;
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsBike(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_BIKING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetSeconds();
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_BIKE == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetSeconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg2Seconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg2Seconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsBike(CShoesBike* pShoes)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            bool fNormal = (pShoes == pWorkout->GetShoesBike());
            bool fSpecial = (pShoes == pWorkout->GetSpecialShoesBike());
            fSpecial |= ((fNormal) && (NULL == pWorkout->GetSpecialShoesBike()));
            bool fLeg2 = (pShoes == pWorkout->GetLeg2Shoes());
            bool fRaceLeg2 = (pShoes == pWorkout->GetLeg2RaceShoes());
            
            if((ACTIVITY_BIKING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnShoes()))
            {
                double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetSeconds(), pWorkout->GetSpecialSeconds(), fNormal, fSpecial);
                if(CUtil::HasData(dCur))
                {
                    dSeconds += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetSeconds(), pWorkout->GetSpecialSeconds(), fNormal, fSpecial);
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg2Seconds(), pWorkout->GetLeg2RaceSeconds(), fLeg2, fRaceLeg2);
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur = CUtil::FigureOutNormalSpecial(pWorkout->GetLeg2Seconds(), pWorkout->GetLeg2RaceSeconds(), fLeg2, fRaceLeg2);
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsBike(CBike* pBike)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {            
            bool fNormal = (pBike == pWorkout->GetBike());

            if((ACTIVITY_BIKING == pWorkout->GetActivityType()) && (pWorkout->IsCountedOnBike()))
            {
                double dCur = pWorkout->GetSeconds();
                if((CUtil::HasData(dCur)) && (true == fNormal))
                {
                    dSeconds += dCur;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetSeconds();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetLeg2Seconds();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    double dCur = pWorkout->GetLeg2Seconds();
                    if((CUtil::HasData(dCur)) && (true == fNormal))
                    {
                        dSeconds += dCur;
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsSwim(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetSeconds();
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_SWIM == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetSeconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        double dCur = pWorkout->GetLeg1Seconds();
                        if(CUtil::HasData(dCur))
                        {
                            dSeconds += dCur;
                        }
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumSecondsStrength(int nActivity /* = -1 */, int nType /* = -1 */)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
                {
                    double dCur = pWorkout->GetSeconds();
                    if(CUtil::HasData(dCur))
                    {
                        dSeconds += dCur;
                    }
                }
            }
        }
    }

    return dSeconds;
}


double CDayLog::SumRunSecondsWithMiles(void)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        double dMiles1 = 0.0;
        double dMiles3 = 0.0;
        double dChance1 = 0.0;
        double dChance3 = 0.0;

        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
            {
                dMiles1 = pWorkout->GetMiles();
                dChance1 = pWorkout->GetSeconds();
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_RUN == pWorkout->GetType())
                {
                    dMiles1 = pWorkout->GetMiles();
                    dChance1 = pWorkout->GetSeconds();
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    dMiles1 = pWorkout->GetLeg1Miles();
                    dMiles3 = pWorkout->GetLeg3Miles();
                    dChance1 = pWorkout->GetLeg1Seconds();
                    dChance3 = pWorkout->GetLeg3Seconds();
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    dMiles3 = pWorkout->GetLeg3Miles();
                    dChance3 = pWorkout->GetLeg3Seconds();
                }
            }
        }

        if((dMiles1 > 0.0) && (CUtil::HasData(dMiles1)) && (CUtil::HasData(dChance1)))
        {
            dSeconds += dChance1;
        }
        if((dMiles3 > 0.0) && (CUtil::HasData(dMiles3)) && (CUtil::HasData(dChance3)))
        {
            dSeconds += dChance3;
        }
    }

    return dSeconds;
}


double CDayLog::SumBikeSecondsWithMiles(void)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        double dMiles = 0.0;
        double dChance = 0.0;

        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_BIKING == pWorkout->GetActivityType())
            {
                dMiles = pWorkout->GetMiles();
                dChance = pWorkout->GetSeconds();
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    dMiles = pWorkout->GetMiles();
                    dChance = pWorkout->GetSeconds();
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    dMiles = pWorkout->GetLeg2Miles();
                    dChance = pWorkout->GetLeg2Seconds();
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    dMiles = pWorkout->GetLeg2Miles();
                    dChance = pWorkout->GetLeg2Seconds();
                }
            }
        }

        if((dMiles > 0.0) && (CUtil::HasData(dMiles)) && (CUtil::HasData(dChance)))
        {
            dSeconds += dChance;
        }
    }

    return dSeconds;
}


double CDayLog::SumSwimSecondsWithMiles(void)
{
    double dSeconds = 0.0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        double dMiles = 0.0;
        double dChance = 0.0;

        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
            {
                dMiles = pWorkout->GetMiles();
                dChance = pWorkout->GetSeconds();
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_SWIM == pWorkout->GetType())
                {
                    dMiles = pWorkout->GetMiles();
                    dChance = pWorkout->GetSeconds();
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    dMiles = pWorkout->GetLeg1Miles();
                    dChance = pWorkout->GetLeg1Seconds();
                }
            }
        }

        if((dMiles > 0.0) && (CUtil::HasData(dMiles)) && (CUtil::HasData(dChance)))
        {
            dSeconds += dChance;
        }
    }

    return dSeconds;
}


int CDayLog::SumTotalWorkouts(void)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    
    return (int)rarWorkouts.GetCount();
}


int CDayLog::SumWorkoutsRun(int nActivity /* = -1 */, int nType /* = -1 */)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
                {
                    nWorkouts++;
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_RUN == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        nWorkouts += 2;
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsRun(CShoesRun* pShoes)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {            
            if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
            {
                if((pShoes == pWorkout->GetShoesRun() && pWorkout->IsCountedOnShoes()) || (pShoes == pWorkout->GetSpecialShoesRun()))
                {
                    nWorkouts++;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_RUN == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetShoesRun()) || (pShoes == pWorkout->GetSpecialShoesRun()))
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetLeg1Shoes()) || (pShoes == pWorkout->GetLeg1RaceShoes()))
                    {
                        nWorkouts++;
                    }
                    if((pShoes == pWorkout->GetLeg3Shoes()) || (pShoes == pWorkout->GetLeg3RaceShoes()))
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetLeg3Shoes()) || (pShoes == pWorkout->GetLeg3RaceShoes()))
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsBike(int nActivity /* = -1 */, int nType /* = -1 */)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_BIKING == pWorkout->GetActivityType())
                {
                    nWorkouts++;
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_BIKE == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                    else if(RACETYPE_DUATHLON == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsBike(CShoesBike* pShoes)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_BIKING == pWorkout->GetActivityType())
            {
                if((pShoes == pWorkout->GetShoesBike() && pWorkout->IsCountedOnShoes()) || (pShoes == pWorkout->GetSpecialShoesBike()))
                {
                    nWorkouts++;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetShoesBike()) || (pShoes == pWorkout->GetSpecialShoesBike()))
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetLeg2Shoes()) || (pShoes == pWorkout->GetLeg2RaceShoes()))
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    if((pShoes == pWorkout->GetLeg2Shoes()) || (pShoes == pWorkout->GetLeg2RaceShoes()))
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsBike(CBike* pBike)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_BIKING == pWorkout->GetActivityType())
            {
                if(pBike == pWorkout->GetBike() && pWorkout->IsCountedOnBike())
                {
                    nWorkouts++;
                }
            }
            else if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if(RACETYPE_BIKE == pWorkout->GetType())
                {
                    if(pBike == pWorkout->GetBike())
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_DUATHLON == pWorkout->GetType())
                {
                    if(pBike == pWorkout->GetBike())
                    {
                        nWorkouts++;
                    }
                }
                else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                {
                    if(pBike == pWorkout->GetBike())
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsSwim(int nActivity /* = -1 */, int nType /* = -1 */)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
                {
                    nWorkouts++;
                }
                else if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    if(RACETYPE_SWIM == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                    else if(RACETYPE_TRIATHLON == pWorkout->GetType())
                    {
                        nWorkouts++;
                    }
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsStrength(int nActivity /* = -1 */, int nType /* = -1 */)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
                {
                    nWorkouts++;
                }
            }
        }
    }

    return nWorkouts;
}


int CDayLog::SumWorkoutsRace(int nActivity /* = -1 */, int nType /* = -1 */)
{
    int nWorkouts = 0;
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if((-1 == nType) || (nActivity == pWorkout->GetActivityType() && nType == pWorkout->GetType()))
            {
                if(ACTIVITY_RACE == pWorkout->GetActivityType())
                {
                    nWorkouts++;
                }
            }
        }
    }

    return nWorkouts;
}


bool CDayLog::IsInjured(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(pWorkout->IsInjured())
            {
                return true;
            }
        }
    }

    return false;
}


bool CDayLog::IsSick(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(pWorkout->IsSick())
            {
                return true;
            }
        }
    }

    return false;
}


bool CDayLog::IsBrick(void)
{
    int iRun = 0;
    int iBike = 0;
    int iSwim = 0;
    int iRace = 0;

    // if there are more than two workouts of the above four types, it's a brick
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int iActivity = pWorkout->GetActivityType();
            if(ACTIVITY_RUNNING == iActivity)
            {
                iRun++;
            }
            else if(ACTIVITY_BIKING == iActivity)
            {
                iBike++;
            }
            else if(ACTIVITY_SWIMMING == iActivity)
            {
                iSwim++;
            }
            else if(ACTIVITY_RACE == iActivity)
            {
                iRace++;
            }
        }
    }

    if(iRun + iBike + iSwim + iRace >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool CDayLog::IsJamba(void)
{
    // if there are more than two workouts of the above four types, it's a brick
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            CString str = pWorkout->GetNotes();
            str = str.MakeLower();
            if(-1 != str.Find("jamba"))
            {
                return true;
            }
        }
    }

    return false;
}


bool CDayLog::IsLong(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(pWorkout->IsLong())
            {
                return true;
            }
        }
    }

    return false;
}


bool CDayLog::IsRaceDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                return true;
            }
        }
    }

    return false;
}


bool CDayLog::IsCompleteRestDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    return (0 == rarWorkouts.GetCount());
}


bool CDayLog::IsNoRunningDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nType = pWorkout->GetType();
            if(ACTIVITY_RUNNING == pWorkout->GetActivityType())
            {
                if((RUNTYPE_EZ == nType) || (RUNTYPE_HILLS == nType) || (RUNTYPE_INTERVALS == nType) ||
                (RUNTYPE_NORMAL == nType) || (RUNTYPE_HARD == nType) || (RUNTYPE_TEMPO == nType) ||
                (RUNTYPE_TREADMILL == nType) || (RUNTYPE_OTHER == nType))
                {
                    return false;
                }
            }
            if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if((RACETYPE_RUN == nType) || (RACETYPE_DUATHLON == nType) || (RACETYPE_TRIATHLON == nType))
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}


bool CDayLog::IsNoBikingDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nType = pWorkout->GetType();
            if(ACTIVITY_BIKING == pWorkout->GetActivityType())
            {
                if((BIKETYPE_EZ == nType) || (BIKETYPE_HILLS == nType) || (BIKETYPE_INTERVALS == nType) ||
                (BIKETYPE_NORMAL == nType) || (BIKETYPE_HARD == nType) || (BIKETYPE_TRAINER == nType) ||
                (BIKETYPE_OTHER == nType))
                {
                    return false;
                }
            }
            if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if((RACETYPE_BIKE == nType) || (RACETYPE_DUATHLON == nType) || (RACETYPE_TRIATHLON == nType))
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}


bool CDayLog::IsNoSwimmingDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nType = pWorkout->GetType();
            if(ACTIVITY_SWIMMING == pWorkout->GetActivityType())
            {
                return false;
            }
            if(ACTIVITY_RACE == pWorkout->GetActivityType())
            {
                if((RACETYPE_SWIM == nType) || (RACETYPE_TRIATHLON == nType))
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}


bool CDayLog::IsNoStrengthDay(void)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            int nType = pWorkout->GetType();
            if(ACTIVITY_STRENGTH == pWorkout->GetActivityType())
            {
                return false;
            }
        }
    }
    
    return true;
}


WORKOUTARRAY& CDayLog::GetRefWorkoutArray(void)
{
    return m_arWorkouts;
}


void CDayLog::AddWorkout(CWorkout* pWorkout)
{
    WORKOUTARRAY& rarWorkouts = GetRefWorkoutArray();
    rarWorkouts.Add(pWorkout);
}