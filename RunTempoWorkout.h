#pragma once

#include "Workout.h"
#include "WorkoutRun.h"

class CRunTempoWorkout : public CWorkoutRun
{
public:
    CRunTempoWorkout(void);
    virtual ~CRunTempoWorkout(void);

    virtual int GetType(void) const;

    virtual int GetWind(void) const;
    virtual CShoesRun* GetShoesRun(void) const;
    virtual double GetSpecialSeconds(void) const;
    virtual double GetSpecialMiles(void) const;
    virtual CShoesRun* GetSpecialShoesRun(void) const;
    virtual bool IsCountedOnShoes(void) const;

    virtual void SetWind(int nWind);
    virtual void SetShoesRun(CShoesRun* pShoes);
    virtual void SetSpecialSeconds(double dSec);
    virtual void SetSpecialMiles(double dMiles);
    virtual void SetSpecialShoesRun(CShoesRun* pShoesRun);
    virtual void SetCountedOnShoes(bool fCount);

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);

protected:
    // data
    CShoesRun* m_pShoesRun;
    int m_nWind;
    double m_dTempoSeconds;
    double m_dTempoMiles;
};