#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPRTriathlonDlg : public CAniDialog
{
public:
	CPRTriathlonDlg(CWnd* pParent = NULL);   
	virtual ~CPRTriathlonDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRTRIATHLONDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

protected:
    afx_msg void OnSelChange(void);

    CString FindDateRun(CCourseTriathlon* pCourse, double dTime, int nQuantity);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPRTriathlonDlg)

    // data
    CUser* m_pUser;
};
