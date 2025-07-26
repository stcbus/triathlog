#include "OptionsSheet.h"

#pragma once

class COptionsCalendarSheet : public COptionsSheet
{
public:
	COptionsCalendarSheet(CWnd* pParent = NULL);   
	virtual ~COptionsCalendarSheet();

    void InitDialogValues(void);
    bool WriteContents(void);

	void OnSpinUpDown(NMHDR* pNmHdr, LRESULT* pResult);

	void OnRunDecimalsChanged(void);
	void OnBikeDecimalsChanged(void);
	void OnSwimDecimalsChanged(void);

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_OPTIONSCALENDARDLG };

    int GetBaseTypeRun(void) const;
    int GetBaseTypeBike(void) const;
    int GetBaseTypeSwim(void) const;
    bool DisplayInfoRun(void) const;
    bool DisplayInfoBike(void) const;
    bool DisplayInfoSwim(void) const;
    bool DisplayInfoStrength(void) const;
    bool DisplayInfoRace(void) const;   
    int GetPaceFormatRun(void) const;
    int GetPaceFormatBike(void) const;
    int GetPaceFormatSwim(void) const;
	int GetAnimTime(void) const;
	int GetRunDecimals(void) const;
	int GetBikeDecimals(void) const;
	int GetSwimDecimals(void) const;

    void SetBaseTypeRun(int nType);
    void SetBaseTypeBike(int nType);
    void SetBaseTypeSwim(int nType);
    void SetDisplayInfoRun(bool fDisp);
    void SetDisplayInfoBike(bool fDisp);
    void SetDisplayInfoSwim(bool fDisp);
    void SetDisplayInfoStrength(bool fDisp);
    void SetDisplayInfoRace(bool fDisp);    
    void SetPaceFormatRun(int nType);
    void SetPaceFormatBike(int nType);
    void SetPaceFormatSwim(int nType);
	void SetAnimTime(int nTime);
	void SetRunDecimals(int nNum);
	void SetBikeDecimals(int nNum);
	void SetSwimDecimals(int nNum);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(COptionsCalendarSheet)

    int m_nBaseTypeRun;
    int m_nBaseTypeBike;
    int m_nBaseTypeSwim;
    bool m_fDispInfoRun;
    bool m_fDispInfoBike;
    bool m_fDispInfoSwim;
    bool m_fDispInfoStrength;
    bool m_fDispInfoRace;
    int m_nPaceFormatRun;
    int m_nPaceFormatBike;
    int m_nPaceFormatSwim;
	int m_nAnimTime;
	int m_nRunDecimals;
	int m_nBikeDecimals;
	int m_nSwimDecimals;
};
