#pragma once

#include <afxtempl.h>
#include "Course.h"
#include "Location.h"
#include "Shoes.h"
#include "Workout.h"

typedef CTypedPtrArray<CPtrArray, CWorkout*> WORKOUTARRAY;

class CDayLog
{
public:
    CDayLog(void);
    ~CDayLog();

    void AddWorkout(CWorkout* pWorkout);

    COleDateTime GetDate(void) const;
    WORKOUTARRAY& GetRefWorkoutArray(void);

    void SetDate(COleDateTime tm);

    double GetAverageTemperature(void);
    double GetAverageHR(void);
    double GetAverageSleep(void);
    double GetAverageWeight(void);
	double GetTotalCalories(void);
    double GetAverageTimeOfDay(void);

    double SumSecondsRun(int nActivity = -1, int nType = -1);
    double SumSecondsRun(CShoesRun* pShoes);
    double SumSecondsBike(int nActivity = -1, int nType = -1);
    double SumSecondsBike(CShoesBike* pShoes);
    double SumSecondsBike(CBike* pBike);
    double SumSecondsSwim(int nActivity = -1, int nType = -1);
    double SumSecondsStrength(int nActivity = -1, int nType = -1);
    double SumRunSecondsWithMiles(void);
    double SumBikeSecondsWithMiles(void);
    double SumSwimSecondsWithMiles(void);
    double SumMilesRun(int nActivity = -1, int nType = -1);
    double SumMilesRun(CShoesRun* pShoes);
    double SumMilesBike(int nActivity = -1, int nType = -1);
    double SumMilesBike(CShoesBike* pShoes);
    double SumMilesBike(CBike* pBike);
    double SumMilesSwim(int nActivity = -1, int nType = -1);
    int SumTotalWorkouts(void);
    int SumWorkoutsRun(int nActivity = -1, int nType = -1);
    int SumWorkoutsRun(CShoesRun* pShoes);
    int SumWorkoutsBike(int nActivity = -1, int nType = -1);
    int SumWorkoutsBike(CShoesBike* pShoes);
    int SumWorkoutsBike(CBike* pBike);
    int SumWorkoutsSwim(int nActivity = -1, int nType = -1);
    int SumWorkoutsStrength(int nActivity = -1, int nType = -1);
	int SumWorkoutsRace(int nActivity = -1, int nType = -1);

    bool IsInjured(void);
	bool IsSick(void);
    bool IsLong(void);
    bool IsBrick(void);
    bool IsJamba(void);
	bool IsRaceDay(void);

    bool IsCompleteRestDay(void);
    bool IsNoRunningDay(void);
    bool IsNoBikingDay(void);
    bool IsNoSwimmingDay(void);
    bool IsNoStrengthDay(void);

protected:
    // data
    COleDateTime m_tmDay;
    WORKOUTARRAY m_arWorkouts;
};