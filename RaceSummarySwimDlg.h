#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CRaceSummarySwimDlg : public CAniDialog
{
public:
	CRaceSummarySwimDlg(CWnd* pParent = NULL);   
	virtual ~CRaceSummarySwimDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_RACESUMMARYSWIMDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnCourseSelChange(void);
    afx_msg void OnDatesSelChange(void);

    void FindDates(CCourseSwim* pCourse);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CRaceSummarySwimDlg)

    // data
    CUser* m_pUser;
    WORKOUTARRAY m_rarRaces;
};
