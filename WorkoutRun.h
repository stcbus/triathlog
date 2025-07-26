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

class CWorkoutRun : public CWorkout
{
public:
    CWorkoutRun(void);
    virtual ~CWorkoutRun(void);

    virtual int GetType(void) const = 0;
    virtual int GetActivityType(void) const;

    virtual double GetMiles(void) const;
    virtual CLocationBike* GetLocationBike(void) const;
    virtual CLocationRun* GetLocationRun(void) const;
    virtual CLocationSwim* GetLocationSwim(void) const;
    virtual CLocationStrength* GetLocationStrength(void) const;
    virtual CCourseRun* GetCourseRun(void) const;
    virtual CCourseBike* GetCourseBike(void) const;
    virtual CCourseSwim* GetCourseSwim(void) const;
    virtual CCourseDuathlon* GetCourseDuathlon(void) const;
    virtual CCourseTriathlon* GetCourseTriathlon(void) const;
    virtual CShoesBike* GetShoesBike(void) const;
    virtual CShoesRun* GetShoesRun(void) const = 0;
    virtual int GetWind(void) const = 0;
    virtual int GetRacePosition(void) const;
    virtual int GetRaceNumber(void) const;
    virtual double GetSpecialSeconds(void) const = 0;
    virtual double GetSpecialMiles(void) const = 0;
    virtual CShoesBike* GetSpecialShoesBike(void) const;
    virtual CShoesRun* GetSpecialShoesRun(void) const = 0;
    virtual bool IsCountedOnShoes(void) const = 0;
    virtual bool IsCountedOnBike(void) const;
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
    virtual void SetLocationRun(CLocationRun* pLoc);
    virtual void SetLocationBike(CLocationBike* pLoc);
    virtual void SetLocationSwim(CLocationSwim* pLoc);
    virtual void SetLocationStrength(CLocationStrength* pLoc);
    virtual void SetCourseRun(CCourseRun* pCourse);
    virtual void SetCourseBike(CCourseBike* pCourse);
    virtual void SetCourseSwim(CCourseSwim* pCourse);
    virtual void SetCourseDuathlon(CCourseDuathlon* pCourse);
    virtual void SetCourseTriathlon(CCourseTriathlon* pCourse);
    virtual void SetShoesRun(CShoesRun* pShoes) = 0;
    virtual void SetShoesBike(CShoesBike* pShoes);
    virtual void SetWind(int nWind) = 0;
    virtual void SetRacePosition(int nPlace);
    virtual void SetRaceNumber(int nNum);
    virtual void SetSpecialSeconds(double dSec) = 0;
    virtual void SetSpecialMiles(double dMiles) = 0;
    virtual void SetSpecialShoesRun(CShoesRun* pShoes) = 0;
    virtual void SetSpecialShoesBike(CShoesBike* pShoes);
    virtual void SetCountedOnShoes(bool fCount) = 0;
    virtual void SetCountedOnBike(bool fCount);
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
    CLocationRun* m_pLocRun;
};