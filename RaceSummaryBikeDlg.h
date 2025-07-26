#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CRaceSummaryBikeDlg : public CAniDialog
{
public:
	CRaceSummaryBikeDlg(CWnd* pParent = NULL);   
	virtual ~CRaceSummaryBikeDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_RACESUMMARYBIKEDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnCourseSelChange(void);
    afx_msg void OnDatesSelChange(void);

    void FindDates(CCourseBike* pCourse);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CRaceSummaryBikeDlg)

    // data
    CUser* m_pUser;
    WORKOUTARRAY m_rarRaces;
};
