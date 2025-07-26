#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CRunWorkoutEZDlg : public CDialog
{
public:
	CRunWorkoutEZDlg(LOCATIONRUNARRAY& rarLocations, SHOESRUNARRAY& rarShoes, CWnd* pParent = NULL);   
	virtual ~CRunWorkoutEZDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDRUNWORKOUTEZ };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    double GetMiles(void) const;
    CLocationRun* GetLocation(void) const;
    CShoesRun* GetShoes(void) const;
    int GetWind(void) const;
    CString GetDispName(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetTemperature(int nTemp);
    void SetHR(int nHR);
    void SetLong(bool fLong);
    void SetMiles(double dMiles);
    void SetLocation(CLocationRun* pLocation);
    void SetShoes(CShoesRun* pShoes);
    void SetWind(int nWind);
    void SetDispName(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    DECLARE_DYNAMIC(CRunWorkoutEZDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    double m_dMiles;
    int m_nTemp;
    int m_nHR;
    int m_nWind;
    bool m_fLong;
    CString m_strNotes;
    CString m_strDisp;
    CLocationRun* m_pLocation;
    CShoesRun* m_pShoes;
    LOCATIONRUNARRAY& m_rarLocations;
    SHOESRUNARRAY& m_rarShoes;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CEmptyStringFilterEdit m_edtNotes;
};