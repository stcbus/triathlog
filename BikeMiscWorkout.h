#pragma once

#include "Workout.h"
#include "WorkoutBike.h"

class CBikeMiscWorkout : public CWorkoutBike
{
public:
    CBikeMiscWorkout(void);
    virtual ~CBikeMiscWorkout(void);

    virtual int GetType(void) const;

    virtual int GetWind(void) const;
    virtual double GetSpecialSeconds(void) const;
    virtual double GetSpecialMiles(void) const;
    virtual CShoesBike* GetSpecialShoesBike(void) const;
    virtual bool IsCountedOnShoes(void) const;
    virtual bool IsCountedOnBike(void) const;

    virtual void SetWind(int nWind);
    virtual void SetSpecialSeconds(double dSec);
    virtual void SetSpecialMiles(double dMiles);
    virtual void SetSpecialShoesBike(CShoesBike* pShoes);
    virtual void SetCountedOnShoes(bool fCount);
    virtual void SetCountedOnBike(bool fCount);

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);

protected:
    // data 
    int m_nWind;
    bool m_fCountOnShoes;
    bool m_fCountOnBike;
};