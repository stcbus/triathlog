#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"
#include "AniDialog.h"

class CWorkoutStartDlg : public CAniDialog
{
public:
	CWorkoutStartDlg(CWnd* pParent = NULL);   
	virtual ~CWorkoutStartDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_WORKOUTSTARTDLG };
    
    int GetActivityType(void) const;
    int GetWorkoutType(void) const;
    bool IsInjured(void) const;
	bool IsSick(void) const;
    double GetPrevNightSleep(void) const;
    double GetWeight(void) const;
    COleDateTime GetDate(void) const;
	COleDateTime GetTime(void) const;
    COleDateTime GetStartTime(void) const;
    bool IsPreset(void) const;
	CString GetDataFile(void) const;

    void SetActivityType(int nType);
    void SetWorkoutType(int nType);
    void SetInjured(bool fInjured);
	void SetSick(bool fSick);
    void SetPrevNightSleep(double dSleep);
    void SetWeight(double dWeight);
    void SetDate(COleDateTime tmDate);
	void SetTime(COleDateTime tmTime);
	void SetStartTime(COleDateTime tmTime);
    void SetPreset(bool fPreset);
	void SetDataFile(CString str);

protected:
    afx_msg void OnUpdateNextButton(void);
	afx_msg void OnChooseDataFile(void);
    afx_msg void OnUpdateActivityType(void);

    void FillWorkoutCombo(void);

    DECLARE_MESSAGE_MAP()

    // data
    int m_nActivityType;
    int m_nWorkoutType;
    bool m_fInjured;
	bool m_fSick;
    double m_dPrevSleep;
    double m_dWeight;
    COleDateTime m_tmDate;
	COleDateTime m_tmTime;
    bool m_fPreset;
	CString m_strDataFile;

	CDoubleFilterEdit m_edtWeight;
	CSleepTimeIntervalFilterEdit m_edtSleep;
	CTimeOfDayFilterEdit m_edtTime;
	CEmptyStringFilterEdit m_edtDataFile;
};