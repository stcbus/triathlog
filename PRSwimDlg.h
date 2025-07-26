#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPRSwimDlg : public CAniDialog
{
public:
	CPRSwimDlg(CWnd* pParent = NULL);   
	virtual ~CPRSwimDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRSWIMDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
    CString FindDateRun(CCourseSwim* pCourse, double dTime);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPRSwimDlg)

    // data
    CUser* m_pUser;
};
