#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CUpcomingWorkoutDlg : public CDialog
{
public:
	CUpcomingWorkoutDlg(CWnd* pParent = NULL);   
	virtual ~CUpcomingWorkoutDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDUPCOMINGWORKOUTDLG };

    COleDateTime GetDate(void) const;
    CString GetLineOne(void) const;
    CString GetLineTwo(void) const;
	CString GetLineThree(void) const;

    void SetDate(COleDateTime tm);
    void SetLineOne(CString str);
    void SetLineTwo(CString str);
	void SetLineThree(CString str);

protected:
    afx_msg void OnUpdateOKButton(void);

    DECLARE_DYNAMIC(CUpcomingWorkoutDlg)
    DECLARE_MESSAGE_MAP()

    // data
    CString m_strLine1;
    CString m_strLine2;
	CString m_strLine3;
    COleDateTime m_tmDate;

	CStringFilterEdit m_edtLine1;
	CEmptyStringFilterEdit m_edtLine2;
	CEmptyStringFilterEdit m_edtLine3;
};