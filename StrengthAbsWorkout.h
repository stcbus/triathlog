#pragma once

#include "Workout.h"
#include "WorkoutStrength.h"

class CStrengthAbsWorkout : public CWorkoutStrength
{
public:
    CStrengthAbsWorkout(void);
    virtual ~CStrengthAbsWorkout(void);

    virtual int GetType(void) const;

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);
};
