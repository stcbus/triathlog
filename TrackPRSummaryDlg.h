#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#include "AniDialog.h"

class CTrackPRSummaryDlg : public CAniDialog
{
public:
	CTrackPRSummaryDlg(CWnd* pParent = NULL);   
	virtual ~CTrackPRSummaryDlg();

	enum { IDD = IDD_TRACKPRSUMMARYDLG };

    virtual BOOL OnInitDialog(void);

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

protected:

    CCourseRun* FindCourse(CString strName, CString strCity, CString strState, double dLen);
    void DisplayCourse(CCourseRun* pCourse, int nID, int nIDPace, int nIDDate);
    CString FindDateRun(CCourseRun* pCourse, double dTime);

	virtual void DoDataExchange(CDataExchange* pDX);    

    // data
    CUser* m_pUser;
};
