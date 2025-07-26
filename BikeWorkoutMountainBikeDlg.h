#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CBikeWorkoutMountainBikeDlg : public CDialog
{
public:
	CBikeWorkoutMountainBikeDlg(LOCATIONBIKEARRAY& rarLocations, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent = NULL);   
	virtual ~CBikeWorkoutMountainBikeDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDBIKEWORKOUTMOUNTAINBIKE };

    double GetSeconds(void) const;
    CString GetNotes(void) const;
    int GetTemperature(void) const;
    int GetHR(void) const;
    bool IsLong(void) const;
    double GetMiles(void) const;
    CLocationBike* GetLocation(void) const;
    CBike* GetBike(void) const;
    CShoesBike* GetShoes(void) const;
    int GetWind(void) const;
    CString GetDispName(void) const;

    void SetSeconds(double dSec);
    void SetNotes(CString str);
    void SetTemperature(int nTemp);
    void SetHR(int nHR);
    void SetLong(bool fLong);
    void SetMiles(double dMiles);
    void SetBike(CBike* pBike);
    void SetLocation(CLocationBike* pLocation);
    void SetShoes(CShoesBike* pShoes);
    void SetWind(int nWind);
    void SetDispName(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUpdatePaces(void);
    afx_msg void OnConvert(void);
    afx_msg void OnAddData(void);

    DECLARE_DYNAMIC(CBikeWorkoutMountainBikeDlg)
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
    CBike* m_pBike;
    CLocationBike* m_pLocation;
    CShoesBike* m_pShoes;
    LOCATIONBIKEARRAY& m_rarLocations;
    SHOESBIKEARRAY& m_rarShoes;
    BIKEARRAY& m_rarBikes;

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CEmptyStringFilterEdit m_edtNotes;
};