#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CTrackPRDlg : public CDialog
{
public:
	CTrackPRDlg(CWnd* pParent = NULL);   
	virtual ~CTrackPRDlg();

    virtual void OnOK(void);
    virtual BOOL OnInitDialog(void);

	afx_msg void OnUpdateOKButton(void);

	enum { IDD = IDD_TRACKPRDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    bool MakeCourse(CTimeIntervalFilterEdit* pedtTime, CString strName, double dLen);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CTrackPRDlg)

    // data
    CUser* m_pUser;

	CTimeIntervalFilterEdit m_edt400;
	CTimeIntervalFilterEdit m_edt800;
	CTimeIntervalFilterEdit m_edt1500;
	CTimeIntervalFilterEdit m_edt1600;
	CTimeIntervalFilterEdit m_edt1Mile;
	CTimeIntervalFilterEdit m_edt3000;
	CTimeIntervalFilterEdit m_edt3200;
	CTimeIntervalFilterEdit m_edt2Mile;
	CTimeIntervalFilterEdit m_edt5000;
	CTimeIntervalFilterEdit m_edt10000;
	CTimeIntervalFilterEdit m_edt3000Steeple;
};
