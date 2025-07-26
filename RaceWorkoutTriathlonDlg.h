#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CRaceWorkoutTriathlonDlg : public CDialog
{
public:
	CRaceWorkoutTriathlonDlg(COURSETRIATHLONARRAY& rarCourse, SHOESRUNARRAY& rarShoesRun, 
                            SHOESBIKEARRAY& rarShoesBike, BIKEARRAY& rarBikes, CWnd* pParent = NULL);   
	virtual ~CRaceWorkoutTriathlonDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDRACETRIATHLON };

    CCourseTriathlon* GetCourseTriathlon(void) const;
    CBike* GetBike(void) const;
    double GetOverallSeconds(void) const;
    CString GetNotes(void) const;
    bool IsLong(void) const;
    CString GetDisplayName(void) const;
    int GetRaceNumber(void) const;
    int GetRacePosition(void) const;
    double GetTransition1Seconds(void) const;
    double GetTransition2Seconds(void) const;
    double GetLeg1Seconds(void) const;
    double GetLeg2Seconds(void) const;
    double GetLeg3Seconds(void) const;
    double GetLeg1Miles(void) const;
    double GetLeg2Miles(void) const;
    double GetLeg3Miles(void) const;
    int GetLeg1Temperature(void) const;
    int GetLeg2Temperature(void) const;
    int GetLeg3Temperature(void) const;
    int GetLeg1Choppiness(void) const;
    int GetLeg2Wind(void) const;
    int GetLeg3Wind(void) const;
    int GetLeg1HR(void) const;
    int GetLeg2HR(void) const;
    int GetLeg3HR(void) const;
    CShoesBike* GetLeg2Shoes(void) const;
    CShoesRun* GetLeg3Shoes(void) const;
    double GetLeg1RaceSeconds(void) const;
    double GetLeg2RaceSeconds(void) const;
    double GetLeg3RaceSeconds(void) const;
    double GetLeg1RaceMiles(void) const;
    double GetLeg2RaceMiles(void) const;
    double GetLeg3RaceMiles(void) const;
    CShoesBike* GetLeg2RaceShoes(void) const;
    CShoesRun* GetLeg3RaceShoes(void) const;

    void SetCourseTriathlon(CCourseTriathlon* pCourse);
    void SetBike(CBike* pBike);
    void SetOverallSeconds(double dSec);
    void SetNotes(CString str);
    void SetLong(bool fLong);
    void SetDisplayName(CString strName);
    void SetRaceNumber(int nNum);
    void SetRacePosition(int nPlace);
    void SetTransition1Seconds(double dSec);
    void SetTransition2Seconds(double dSec);
    void SetLeg1Seconds(double dSec);
    void SetLeg2Seconds(double dSec);
    void SetLeg3Seconds(double dSec);
    void SetLeg1Miles(double dMiles);
    void SetLeg2Miles(double dMiles);
    void SetLeg3Miles(double dMiles);
    void SetLeg1Temperature(int nTemp);
    void SetLeg2Temperature(int nTemp);
    void SetLeg3Temperature(int nTemp);
    void SetLeg1Choppiness(int nAmount);
    void SetLeg2Wind(int nWind);
    void SetLeg3Wind(int nWind);
    void SetLeg1HR(int nHR);
    void SetLeg2HR(int nHR);
    void SetLeg3HR(int nHR);
    void SetLeg2Shoes(CShoesBike* pShoes);
    void SetLeg3Shoes(CShoesRun* pShoes);
    void SetLeg1RaceSeconds(double dSec);
    void SetLeg2RaceSeconds(double dSec);
    void SetLeg3RaceSeconds(double dSec);
    void SetLeg1RaceMiles(double dMiles);
    void SetLeg2RaceMiles(double dMiles);
    void SetLeg3RaceMiles(double dMiles);
    void SetLeg2RaceShoes(CShoesBike* pShoes);
    void SetLeg3RaceShoes(CShoesRun* pShoes);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    void UpdatePR(void);

    DECLARE_DYNAMIC(CRaceWorkoutTriathlonDlg)
    DECLARE_MESSAGE_MAP()

    // data
    
protected:
    // data 
    CCourseTriathlon* m_pCourse;
    CBike* m_pBike;
    CString m_strDisplay;
    int m_nPlace;
    int m_nRaceNumber;
    bool m_fLong;
    CString m_strNotes;
    double m_dOverallSeconds;
    double m_dTransition1Seconds;
    double m_dTransition2Seconds;
    double m_dLeg1Seconds;
    double m_dLeg2Seconds;
    double m_dLeg3Seconds;
    double m_dLeg1Miles;
    double m_dLeg2Miles;
    double m_dLeg3Miles;
    int m_nLeg1Temp;
    int m_nLeg2Temp;
    int m_nLeg3Temp;
    int m_nLeg1Choppiness;
    int m_nLeg2Wind;
    int m_nLeg3Wind;
    int m_nLeg1HR;
    int m_nLeg2HR;
    int m_nLeg3HR;
    CShoesBike* m_pLeg2Shoes;
    CShoesRun* m_pLeg3Shoes;
    CShoesBike* m_pLeg2RaceShoes;
    CShoesRun* m_pLeg3RaceShoes;
    double m_dLeg1RaceSeconds;
    double m_dLeg2RaceSeconds;
    double m_dLeg3RaceSeconds;
    COURSETRIATHLONARRAY& m_rarCourses;
    SHOESRUNARRAY& m_rarShoesRun;
    SHOESBIKEARRAY& m_rarShoesBike;
    BIKEARRAY& m_rarBikes;

	CStringFilterEdit m_edtDisp;
	CTimeIntervalFilterEdit m_edtOverallSeconds;
	CTimeIntervalFilterEdit m_edtTrans1Seconds;
	CTimeIntervalFilterEdit m_edtTrans2Seconds;
	CEmptyStringFilterEdit m_edtNotes;
	CUIntFilterEdit m_edtPlace;
	CUIntFilterEdit m_edtRaceNumber;

	CUIntFilterEdit m_edtL1Temp;
	CUIntFilterEdit m_edtL1HR;
	CDoubleFilterEdit m_edtL1Dist;
	CTimeIntervalFilterEdit m_edtL1Seconds;
	CTimeIntervalFilterEdit m_edtL1SpecialSeconds;
	CUIntFilterEdit m_edtL2Temp;
	CUIntFilterEdit m_edtL2HR;
	CDoubleFilterEdit m_edtL2Dist;
	CTimeIntervalFilterEdit m_edtL2Seconds;
	CTimeIntervalFilterEdit m_edtL2SpecialSeconds;
	CUIntFilterEdit m_edtL3Temp;
	CUIntFilterEdit m_edtL3HR;
	CDoubleFilterEdit m_edtL3Dist;
	CTimeIntervalFilterEdit m_edtL3Seconds;
	CTimeIntervalFilterEdit m_edtL3SpecialSeconds;
};