#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CRaceWorkoutSwimDlg : public CDialog
{
public:
	CRaceWorkoutSwimDlg(COURSESWIMARRAY& rarCourse, CWnd* pParent = NULL);   
	virtual ~CRaceWorkoutSwimDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDRACESWIM };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    CString GetDisplayName(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    double GetMiles(void) const;
    CCourseSwim* GetCourse(void) const;
    int GetChoppiness(void) const;
    int GetRacePosition(void) const;
    int GetRaceNumber(void) const;
    double GetSpecialSeconds(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetDisplayName(CString str);
    void SetTemperature(int nTemp);
    void SetHR(int nHR);
    void SetLong(bool fLong);
    void SetMiles(double dMiles);
    void SetCourse(CCourseSwim* pCourse);
    void SetChoppiness(int nAmount);
    void SetRacePosition(int nPlace);
    void SetRaceNumber(int nNum);
    void SetSpecialSeconds(double dSec);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    void UpdatePR(void);

    DECLARE_DYNAMIC(CRaceWorkoutSwimDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    double m_dRaceSeconds;
    double m_dMiles;
    int m_nTemp;
    int m_nHR;
    int m_nChoppiness;
    int m_nPlace;
    int m_nRaceNumber;
    bool m_fLong;
    CString m_strNotes;
    CString m_strDisplay;
    CCourseSwim* m_pCourse;
    COURSESWIMARRAY& m_rarCourses;

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