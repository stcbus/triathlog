#pragma once

#include "Workout.h"
#include "WorkoutSwim.h"

class CSwimOpenWaterWorkout : public CWorkoutSwim
{
public:
    CSwimOpenWaterWorkout(void);
    virtual ~CSwimOpenWaterWorkout(void);

    virtual int GetType(void) const;

    virtual double GetSpecialSeconds(void) const;
    virtual double GetSpecialMiles(void) const;

    virtual void SetSpecialSeconds(double dSec);
    virtual void SetSpecialMiles(double dMiles);

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);
};
