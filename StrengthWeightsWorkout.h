#pragma once

#include "Workout.h"
#include "WorkoutStrength.h"

class CStrengthWeightsWorkout : public CWorkoutStrength
{
public:
    CStrengthWeightsWorkout(void);
    virtual ~CStrengthWeightsWorkout(void);

    virtual int GetType(void) const;

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);
};
