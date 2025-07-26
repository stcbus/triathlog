#pragma once

#include "Workout.h"
#include "WorkoutSwim.h"

class CSwimHardWorkout : public CWorkoutSwim
{
public:
    CSwimHardWorkout(void);
    virtual ~CSwimHardWorkout(void);

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
