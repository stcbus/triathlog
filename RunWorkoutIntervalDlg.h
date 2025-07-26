#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CRunWorkoutIntervalDlg : public CDialog
{
public:
	CRunWorkoutIntervalDlg(LOCATIONRUNARRAY& rarLocations, SHOESRUNARRAY& rarShoes, CWnd* pParent = NULL);   
	virtual ~CRunWorkoutIntervalDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDRUNWORKOUTINTERVALS };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    double GetMiles(void) const;
    CLocationRun* GetLocation(void) const;
    CShoesRun* GetShoes(void) const;
    int GetWind(void) const;
    double GetSpecialSeconds(void) const;
    double GetSpecialMiles(void) const;
    CShoesRun* GetSpecialShoes(void) const;
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
    void SetSpecialSeconds(double dSec);
    void SetSpecialMiles(double dMiles);
    void SetSpecialShoes(CShoesRun* pShoes);
    void SetDispName(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    DECLARE_DYNAMIC(CRunWorkoutIntervalDlg)
    DECLARE_MESSAGE_MAP()

    // data
    double m_dSeconds;
    double m_dMiles;
    double m_dIntervalSeconds;
    double m_dIntervalMiles;
    int m_nTemp;
    int m_nHR;
    int m_nWind;
    bool m_fLong;
    CString m_strNotes;
    CString m_strDisp;
    CLocationRun* m_pLocation;
    CShoesRun* m_pShoes;
    CShoesRun* m_pSpikes;
    LOCATIONRUNARRAY& m_rarLocations;
    SHOESRUNARRAY& m_rarShoes;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSpecialSeconds;
	CDoubleFilterEdit m_edtSpecialDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CEmptyStringFilterEdit m_edtNotes;
};