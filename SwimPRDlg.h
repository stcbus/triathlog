#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSwimPRDlg : public CDialog
{
public:
	CSwimPRDlg(CWnd* pParent = NULL);   
	virtual ~CSwimPRDlg();

    virtual void OnOK(void);
    virtual BOOL OnInitDialog(void);

	afx_msg void OnUpdateOKButton(void);

	enum { IDD = IDD_SWIMPRDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    bool MakeCourse(CTimeIntervalFilterEdit* pedtTime, CString strName, double dLen);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CSwimPRDlg)

    // data
    CUser* m_pUser;

	CTimeIntervalFilterEdit m_edt50;
	CTimeIntervalFilterEdit m_edt100;
	CTimeIntervalFilterEdit m_edt200;
	CTimeIntervalFilterEdit m_edt400;
	CTimeIntervalFilterEdit m_edt800;
	CTimeIntervalFilterEdit m_edt1500;
};
