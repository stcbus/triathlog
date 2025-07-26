#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CStrengthWorkoutAbsDlg : public CDialog
{
public:
	CStrengthWorkoutAbsDlg(LOCATIONSTRENGTHARRAY& rarLocations, CWnd* pParent = NULL);   
	virtual ~CStrengthWorkoutAbsDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDSTRENGTHWORKOUTABS };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    CLocationStrength* GetLocation(void) const;
    CString GetDispName(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetTemperature(int nTemp);
    void SetHR(int nHR);
    void SetLong(bool fLong);
    void SetLocation(CLocationStrength* pLocation);
    void SetDispName(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnAddData(void);

    DECLARE_DYNAMIC(CStrengthWorkoutAbsDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    int m_nTemp;
    int m_nHR;
    bool m_fLong;
    CString m_strNotes;
    CString m_strDisp;
    CLocationStrength* m_pLocation;
    LOCATIONSTRENGTHARRAY& m_rarLocations;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CTimeIntervalFilterEdit m_edtSeconds;
	CEmptyStringFilterEdit m_edtNotes;
};