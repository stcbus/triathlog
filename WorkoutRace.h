#pragma once

#include "Course.h"
#include "CourseRun.h"
#include "CourseBike.h"
#include "CourseSwim.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "Location.h"
#include "LocationSwim.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationStrength.h"
#include "Shoes.h"
#include "ShoesRun.h"
#include "ShoesBike.h"

class CWorkoutRace : public CWorkout
{
public:
    CWorkoutRace(void);
    virtual ~CWorkoutRace(void);

    virtual int GetType(void) const = 0;
    virtual int GetActivityType(void) const;

    virtual double GetMiles(void) const = 0;
    virtual CLocationBike* GetLocationBike(void) const;
    virtual CLocationRun* GetLocationRun(void) const;
    virtual CLocationSwim* GetLocationSwim(void) const;
    virtual CLocationStrength* GetLocationStrength(void) const;
    virtual CCourseRun* GetCourseRun(void) const = 0;
    virtual CCourseBike* GetCourseBike(void) const = 0;
    virtual CCourseSwim* GetCourseSwim(void) const = 0;
    virtual CCourseDuathlon* GetCourseDuathlon(void) const = 0;
    virtual CCourseTriathlon* GetCourseTriathlon(void) const = 0;
    virtual CShoesBike* GetShoesBike(void) const = 0;
    virtual CShoesRun* GetShoesRun(void) const = 0;
    virtual int GetWind(void) const = 0;
    virtual int GetRacePosition(void) const;
    virtual int GetRaceNumber(void) const;
    virtual double GetSpecialSeconds(void) const;
    virtual double GetSpecialMiles(void) const = 0;
    virtual CShoesBike* GetSpecialShoesBike(void) const = 0;
    virtual CShoesRun* GetSpecialShoesRun(void) const = 0;
    virtual bool IsCountedOnShoes(void) const;
    virtual bool IsCountedOnBike(void) const;
    virtual CBike* GetBike(void) const = 0;
    virtual int GetChoppiness(void) const = 0;
    virtual double GetTransition1Seconds(void) const = 0;
    virtual double GetTransition2Seconds(void) const = 0;
    virtual double GetLeg1Seconds(void) const = 0;
    virtual double GetLeg2Seconds(void) const = 0;
    virtual double GetLeg3Seconds(void) const = 0;
    virtual double GetLeg1Miles(void) const = 0;
    virtual double GetLeg2Miles(void) const = 0;
    virtual double GetLeg3Miles(void) const = 0;
    virtual int GetLeg1Temperature(void) const = 0;
    virtual int GetLeg2Temperature(void) const = 0;
    virtual int GetLeg3Temperature(void) const = 0;
    virtual int GetLeg1Wind(void) const = 0;
    virtual int GetLeg2Wind(void) const = 0;
    virtual int GetLeg3Wind(void) const = 0;
    virtual int GetLeg1HR(void) const = 0;
    virtual int GetLeg2HR(void) const = 0;
    virtual int GetLeg3HR(void) const = 0;
    virtual CShoesRun* GetLeg1Shoes(void) const = 0;
    virtual CShoesBike* GetLeg2Shoes(void) const = 0;
    virtual CShoesRun* GetLeg3Shoes(void) const = 0;
    virtual double GetLeg1RaceSeconds(void) const = 0;
    virtual double GetLeg2RaceSeconds(void) const = 0;
    virtual double GetLeg3RaceSeconds(void) const = 0;
    virtual double GetLeg1RaceMiles(void) const = 0;
    virtual double GetLeg2RaceMiles(void) const = 0;
    virtual double GetLeg3RaceMiles(void) const = 0;
    virtual CShoesRun* GetLeg1RaceShoes(void) const = 0;
    virtual CShoesBike* GetLeg2RaceShoes(void) const = 0;
    virtual CShoesRun* GetLeg3RaceShoes(void) const = 0;

    virtual void SetMiles(double dMiles) = 0;
    virtual void SetLocationRun(CLocationRun* pLoc);
    virtual void SetLocationBike(CLocationBike* pLoc);
    virtual void SetLocationSwim(CLocationSwim* pLoc);
    virtual void SetLocationStrength(CLocationStrength* pLoc);
    virtual void SetCourseRun(CCourseRun* pCourse) = 0;
    virtual void SetCourseBike(CCourseBike* pCourse) = 0;
    virtual void SetCourseSwim(CCourseSwim* pCourse) = 0;
    virtual void SetCourseDuathlon(CCourseDuathlon* pCourse) = 0;
    virtual void SetCourseTriathlon(CCourseTriathlon* pCourse) = 0;
    virtual void SetShoesRun(CShoesRun* pShoes) = 0;
    virtual void SetShoesBike(CShoesBike* pShoes) = 0;
    virtual void SetWind(int nWind) = 0;
    virtual void SetRacePosition(int nPlace);
    virtual void SetRaceNumber(int nNum);
    virtual void SetSpecialSeconds(double dSec);
    virtual void SetSpecialMiles(double dMiles) = 0;
    virtual void SetSpecialShoesRun(CShoesRun* pShoes) = 0;
    virtual void SetSpecialShoesBike(CShoesBike* pShoes) = 0;
    virtual void SetCountedOnShoes(bool fCount);
    virtual void SetCountedOnBike(bool fCount);
    virtual void SetBike(CBike* pBike) = 0;
    virtual void SetChoppiness(int nAmount) = 0;
    virtual void SetTransition1Seconds(double dSec) = 0;
    virtual void SetTransition2Seconds(double dSec) = 0;
    virtual void SetLeg1Seconds(double dSec) = 0;
    virtual void SetLeg2Seconds(double dSec) = 0;
    virtual void SetLeg3Seconds(double dSec) = 0;
    virtual void SetLeg1Miles(double dMiles) = 0;
    virtual void SetLeg2Miles(double dMiles) = 0;
    virtual void SetLeg3Miles(double dMiles) = 0;
    virtual void SetLeg1Temperature(int nTemp) = 0;
    virtual void SetLeg2Temperature(int nTemp) = 0;
    virtual void SetLeg3Temperature(int nTemp) = 0;
    virtual void SetLeg1Wind(int nWind) = 0;
    virtual void SetLeg2Wind(int nWind) = 0;
    virtual void SetLeg3Wind(int nWind) = 0;
    virtual void SetLeg1HR(int nHR) = 0;
    virtual void SetLeg2HR(int nHR) = 0;
    virtual void SetLeg3HR(int nHR) = 0;
    virtual void SetLeg1Shoes(CShoesRun* pShoes) = 0;
    virtual void SetLeg2Shoes(CShoesBike* pShoes) = 0;
    virtual void SetLeg3Shoes(CShoesRun* pShoes) = 0;
    virtual void SetLeg1RaceSeconds(double dSec) = 0;
    virtual void SetLeg2RaceSeconds(double dSec) = 0;
    virtual void SetLeg3RaceSeconds(double dSec) = 0;
    virtual void SetLeg1RaceMiles(double dMiles) = 0;
    virtual void SetLeg2RaceMiles(double dMiles) = 0;
    virtual void SetLeg3RaceMiles(double dMiles) = 0;
    virtual void SetLeg1RaceShoes(CShoesRun* pShoes) = 0;
    virtual void SetLeg2RaceShoes(CShoesBike* pShoes) = 0;
    virtual void SetLeg3RaceShoes(CShoesRun* pShoes) = 0;

    virtual void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nOldDistSwimUnits,
                             int nOldWeightUnits, int nOldTempUnits, int nNewDistRunUnits,
                             int nNewDistBikeUnits, int nNewDistSwimUnits, int nNewWeightUnits, 
                             int nNewTempUnits);

protected:
    // data
    double m_dRaceSeconds;
    int m_nPlace;
    int m_nRaceNum;
};