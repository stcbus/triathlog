#pragma once

#include "Workout.h"
#include "WorkoutRace.h"

class CRaceRunWorkout : public CWorkoutRace
{
public:
    CRaceRunWorkout(void);
    virtual ~CRaceRunWorkout(void);

    virtual int GetType(void) const;

    virtual double GetMiles(void) const;
    virtual CCourseRun* GetCourseRun(void) const;
    virtual CCourseSwim* GetCourseSwim(void) const;
    virtual CCourseBike* GetCourseBike(void) const;
    virtual CCourseDuathlon* GetCourseDuathlon(void) const;
    virtual CCourseTriathlon* GetCourseTriathlon(void) const;
    virtual CShoesRun* GetShoesRun(void) const;
    virtual CShoesBike* GetShoesBike(void) const;
    virtual int GetWind(void) const;
    virtual double GetSpecialMiles(void) const;
    virtual CShoesRun* GetSpecialShoesRun(void) const;
    virtual CShoesBike* GetSpecialShoesBike(void) const;
    virtual CBike* GetBike(void) const;
    virtual int GetChoppiness(void) const;
    virtual double GetTransition1Seconds(void) const;
    virtual double GetTransition2Seconds(void) const;
    virtual double GetLeg1Seconds(void) const;
    virtual double GetLeg2Seconds(void) const;
    virtual double GetLeg3Seconds(void) const;
    virtual double GetLeg1Miles(void) const;
    virtual double GetLeg2Miles(void) const;
    virtual double GetLeg3Miles(void) const;
    virtual int GetLeg1Temperature(void) const;
    virtual int GetLeg2Temperature(void) const;
    virtual int GetLeg3Temperature(void) const;
    virtual int GetLeg1Wind(void) const;
    virtual int GetLeg2Wind(void) const;
    virtual int GetLeg3Wind(void) const;
    virtual int GetLeg1HR(void) const;
    virtual int GetLeg2HR(void) const;
    virtual int GetLeg3HR(void) const;
    virtual CShoesRun* GetLeg1Shoes(void) const;
    virtual CShoesBike* GetLeg2Shoes(void) const;
    virtual CShoesRun* GetLeg3Shoes(void) const;
    virtual double GetLeg1RaceSeconds(void) const;
    virtual double GetLeg2RaceSeconds(void) const;
    virtual double GetLeg3RaceSeconds(void) const;
    virtual double GetLeg1RaceMiles(void) const;
    virtual double GetLeg2RaceMiles(void) const;
    virtual double GetLeg3RaceMiles(void) const;
    virtual CShoesRun* GetLeg1RaceShoes(void) const;
    virtual CShoesBike* GetLeg2RaceShoes(void) const;
    virtual CShoesRun* GetLeg3RaceShoes(void) const;

    virtual void SetMiles(double dMiles);
    virtual void SetCourseRun(CCourseRun* pCourse);
    virtual void SetCourseBike(CCourseBike* pCourse);
    virtual void SetCourseSwim(CCourseSwim* pCourse);
    virtual void SetCourseDuathlon(CCourseDuathlon* pCourse);
    virtual void SetCourseTriathlon(CCourseTriathlon* pCourse);
    virtual void SetShoesRun(CShoesRun* pShoes);
    virtual void SetShoesBike(CShoesBike* pShoes);
    virtual void SetWind(int nWind);
    virtual void SetSpecialMiles(double dMiles);
    virtual void SetSpecialShoesRun(CShoesRun* pShoes);
    virtual void SetSpecialShoesBike(CShoesBike* pShoes);
    virtual void SetBike(CBike* pBike);
    virtual void SetChoppiness(int nAmount);
    virtual void SetTransition1Seconds(double dSec);
    virtual void SetTransition2Seconds(double dSec);
    virtual void SetLeg1Seconds(double dSec);
    virtual void SetLeg2Seconds(double dSec);
    virtual void SetLeg3Seconds(double dSec);
    virtual void SetLeg1Miles(double dMiles);
    virtual void SetLeg2Miles(double dMiles);
    virtual void SetLeg3Miles(double dMiles);
    virtual void SetLeg1Temperature(int nTemp);
    virtual void SetLeg2Temperature(int nTemp);
    virtual void SetLeg3Temperature(int nTemp);
    virtual void SetLeg1Wind(int nWind);
    virtual void SetLeg2Wind(int nWind);
    virtual void SetLeg3Wind(int nWind);
    virtual void SetLeg1HR(int nHR);
    virtual void SetLeg2HR(int nHR);
    virtual void SetLeg3HR(int nHR);
    virtual void SetLeg1Shoes(CShoesRun* pShoes);
    virtual void SetLeg2Shoes(CShoesBike* pShoes);
    virtual void SetLeg3Shoes(CShoesRun* pShoes);
    virtual void SetLeg1RaceSeconds(double dSec);
    virtual void SetLeg2RaceSeconds(double dSec);
    virtual void SetLeg3RaceSeconds(double dSec);
    virtual void SetLeg1RaceMiles(double dMiles);
    virtual void SetLeg2RaceMiles(double dMiles);
    virtual void SetLeg3RaceMiles(double dMiles);
    virtual void SetLeg1RaceShoes(CShoesRun* pShoes);
    virtual void SetLeg2RaceShoes(CShoesBike* pShoes);
    virtual void SetLeg3RaceShoes(CShoesRun* pShoes);

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);

protected:
    // data 
    double m_dMiles;
    CCourseRun* m_pCourse;
    int m_nWind;
    CShoesRun* m_pShoes;
    CShoesRun* m_pSpikes;
};
