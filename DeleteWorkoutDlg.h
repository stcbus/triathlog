#include "AniDialog.h"
#include "DayLog.h"
#include "User.h"

#pragma once

class CDeleteWorkoutDlg : public CAniDialog
{
public:
	CDeleteWorkoutDlg(CWnd* pParent = NULL);   
	virtual ~CDeleteWorkoutDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnDelete(void);

	enum { IDD = IDD_DELETEWORKOUTDLG };
	enum
	{
		EDeleteWorkout,
		EDeleteUpcomingWorkout,
		EDeleteUpcomingRace
	} EDeleteType;

    CDayLog* GetDay(void) const;
    void SetDay(CDayLog* pDay);

	COleDateTime GetDate(void) const;
	void SetDate(COleDateTime tm);

	CUser* GetUser(void) const;
	void SetUser(CUser* pUser);

    bool GetChanged(void) const;
    void SetChanged(bool bChanged);

	int GetDeleteType(void) const;
	void SetDeleteType(int nType);

protected:
    afx_msg void OnWorkoutSelChange(void);
    void FillWorkoutBox(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CDeleteWorkoutDlg)

    // data
	COleDateTime m_tmDay;
	CUser* m_pUser;
    CDayLog* m_pDay;
    bool m_bChanged;
	int m_nType;
};
