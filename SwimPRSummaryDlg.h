#pragma once

#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSwimPRSummaryDlg : public CAniDialog
{
public:
	CSwimPRSummaryDlg(CWnd* pParent = NULL);   
	virtual ~CSwimPRSummaryDlg();

	enum { IDD = IDD_SWIMPRSUMMARYDLG };

    virtual BOOL OnInitDialog(void);

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

protected:

    CCourseSwim* FindCourse(CString strName, CString strCity, CString strState, double dLen);
    void DisplayCourse(CCourseSwim* pCourse, int nID, int nIDPace, int nIDDate);
    CString FindDateRun(CCourseSwim* pCourse, double dTime);

	virtual void DoDataExchange(CDataExchange* pDX);    

    // data
    CUser* m_pUser;
};
