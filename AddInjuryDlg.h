#include "AniDialog.h"

#pragma once

#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CAddInjuryDlg : public CAniDialog
{
public:
	CAddInjuryDlg(CWnd* pParent = NULL);   
	virtual ~CAddInjuryDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDINJURYDLG };

	CString GetName(void) const;
    COleDateTime GetDate(void) const;
	void SetName(CString str);
    void SetDate(COleDateTime tm);

protected:
    afx_msg void OnUpdateOKButton(void);
	afx_msg void OnDropDown(NMHDR* pNmHdr, LRESULT* pResult);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddInjuryDlg)

    // data
    COleDateTime m_tmDate;
	CString m_strName;

	CStringFilterEdit m_edtName;
};
