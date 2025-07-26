#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPRRunDlg : public CAniDialog
{
public:
	CPRRunDlg(CWnd* pParent = NULL);   
	virtual ~CPRRunDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRRUNDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
    CString FindDateRun(CCourseRun* pCourse, double dTime);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPRRunDlg)

    // data
    CUser* m_pUser;
};
