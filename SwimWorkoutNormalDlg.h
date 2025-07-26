#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSwimWorkoutNormalDlg : public CDialog
{
public:
	CSwimWorkoutNormalDlg(LOCATIONSWIMARRAY& rarLocations, CWnd* pParent = NULL);   
	virtual ~CSwimWorkoutNormalDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDSWIMWORKOUTNORMAL };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    int GetTemperature(void) const;
    double GetMiles(void) const;
    int GetChoppiness(void) const;
    CLocationSwim* GetLocation(void) const;
    CString GetDispName(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetHR(int nHR);
    void SetTemperature(int nTemp);
    void SetChoppiness(int nAmount);
    void SetLong(bool fLong);
    void SetMiles(double dMiles);
    void SetLocation(CLocationSwim* pLocation);
    void SetDispName(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    DECLARE_DYNAMIC(CSwimWorkoutNormalDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    double m_dMiles;
    int m_nHR;
    bool m_fLong;
    int m_nTemperature;
    int m_nChoppiness;
    CString m_strNotes;
    CString m_strDisp;
    CLocationSwim* m_pLocation;
    LOCATIONSWIMARRAY& m_rarLocations;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CEmptyStringFilterEdit m_edtNotes;
};