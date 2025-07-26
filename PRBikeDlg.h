#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CPRBikeDlg : public CAniDialog
{
public:
	CPRBikeDlg(CWnd* pParent = NULL);   
	virtual ~CPRBikeDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PRBIKEDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
    CString FindDateRun(CCourseBike* pCourse, double dTime);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPRBikeDlg)

    // data
    CUser* m_pUser;
};
