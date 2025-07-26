#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CAddUserDlg : public CDialog
{
public:
	CAddUserDlg(CWnd* pParent = NULL);   
	virtual ~CAddUserDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDUSERDLG };

    CString GetFirstName(void) const;
    CString GetLastName(void) const;
    int GetHeight(void) const;
    int GetRestHR(void) const;
    int GetSex(void) const;
    int GetFirstDay(void) const;
    bool AreUnitsAmerican(void) const;
protected:
    void SetFirstName(CString str);
    void SetLastName(CString str);
    void SetHeight(int nInches);
    void SetRestHR(int nHR);
    void SetSex(int nSex);
    void SetFirstDay(int nDay);
    void SetUnitsAmerican(bool bAmerican);

    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnUnitsChanged(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddUserDlg)

    // data
    CString m_strFirstName;
    CString m_strLastName;
    int m_nHeight;
    int m_nRestHR;
    int m_nSex;
    int m_nFirstDay;
    bool m_bUnitsAmerican;

	CStringFilterEdit m_edtFirstName;
	CStringFilterEdit m_edtLastName;
	CUIntFilterEdit m_edtHeight;
	CUIntFilterEdit m_edtHR;
};
