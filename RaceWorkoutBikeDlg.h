#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CRaceWorkoutBikeDlg : public CDialog
{
public:
	CRaceWorkoutBikeDlg(COURSEBIKEARRAY& rarCourse, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent = NULL);   
	virtual ~CRaceWorkoutBikeDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDRACEBIKE };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    CString GetDisplayName(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    double GetMiles(void) const;
    CCourseBike* GetCourse(void) const;
    CShoesBike* GetShoes(void) const;
    int GetWind(void) const;
    int GetRacePosition(void) const;
    int GetRaceNumber(void) const;
    CBike* GetBike(void) const;
    double GetSpecialSeconds(void) const;
    CShoesBike* GetSpecialShoes(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetDisplayName(CString str);
    void SetTemperature(int nTemp);
    void SetHR(int nHR);
    void SetLong(bool fLong);
    void SetMiles(double dMiles);
    void SetCourse(CCourseBike* pCourse);
    void SetShoes(CShoesBike* pShoes);
    void SetWind(int nWind);
    void SetRacePosition(int nPlace);
    void SetRaceNumber(int nNum);
    void SetBike(CBike* pBike);
    void SetSpecialSeconds(double dSec);
    void SetSpecialShoes(CShoesBike* pShoes);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    void UpdatePR(void);

    DECLARE_DYNAMIC(CRaceWorkoutBikeDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    double m_dRaceSeconds;
    double m_dMiles;
    int m_nTemp;
    int m_nHR;
    int m_nWind;
    int m_nPlace;
    int m_nRaceNumber;
    bool m_fLong;
    CString m_strNotes;
    CString m_strDisplay;
    CCourseBike* m_pCourse;
    CShoesBike* m_pShoes;
    CShoesBike* m_pSpikes;
    CBike* m_pBike;
    COURSEBIKEARRAY& m_rarCourses;
    SHOESBIKEARRAY& m_rarShoes;
    BIKEARRAY& m_rarBikes;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CTimeIntervalFilterEdit m_edtSpecialSeconds;
	CEmptyStringFilterEdit m_edtNotes;
	CUIntFilterEdit m_edtPlace;
	CUIntFilterEdit m_edtRaceNumber;
};