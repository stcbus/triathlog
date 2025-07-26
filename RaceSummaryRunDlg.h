#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CRaceSummaryRunDlg : public CAniDialog
{
public:
	CRaceSummaryRunDlg(CWnd* pParent = NULL);   
	virtual ~CRaceSummaryRunDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_RACESUMMARYRUNDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnCourseSelChange(void);
    afx_msg void OnDatesSelChange(void);

    void FindDates(CCourseRun* pCourse);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CRaceSummaryRunDlg)

    // data
    CUser* m_pUser;
    WORKOUTARRAY m_rarRaces;
};
