#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPRDuathlonDlg : public CAniDialog
{
public:
	CPRDuathlonDlg(CWnd* pParent = NULL);   
	virtual ~CPRDuathlonDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRDUATHLONDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

protected:
    afx_msg void OnSelChange(void);

    CString FindDateRun(CCourseDuathlon* pCourse, double dTime, int nQuantity);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPRDuathlonDlg)

    // data
    CUser* m_pUser;
};
