#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CRaceSummaryDuathlonDlg : public CAniDialog
{
public:
	CRaceSummaryDuathlonDlg(CWnd* pParent = NULL);   
	virtual ~CRaceSummaryDuathlonDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_RACESUMMARYDUATHLONDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnCourseSelChange(void);
    afx_msg void OnDatesSelChange(void);

    void FindDates(CCourseDuathlon* pCourse);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CRaceSummaryDuathlonDlg)

    // data
    CUser* m_pUser;
    WORKOUTARRAY m_rarRaces;
};
