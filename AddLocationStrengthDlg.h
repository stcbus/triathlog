#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CAddLocationStrengthDlg : public CAniDialog
{
public:
	CAddLocationStrengthDlg(CWnd* pParent = NULL);   
	virtual ~CAddLocationStrengthDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDLOCATIONSTRENGTHDLG };

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    CString GetNotes(void) const;

protected:
    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);
    void SetNotes(CString str);

    afx_msg void OnUpdateOKButton(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddLocationStrengthDlg)

    // data
    CString m_strName;
    CString m_strCity;
    CString m_strState;
    CString m_strNotes;

	CStringFilterEdit m_edtName;
	CStringFilterEdit m_edtCity;
	CStringFilterEdit m_edtState;
	CEmptyStringFilterEdit m_edtNotes;
};
