#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once


class CEditUserDlg : public CAniDialog
{
public:
	CEditUserDlg(CWnd* pParent = NULL);   
	virtual ~CEditUserDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_EDITUSERDLG };

	void SetUser(CUser* pUser);

    CString GetFirstName(void) const;
    CString GetLastName(void) const;
    int GetHeight(void) const;
    int GetRestHR(void) const;
    int GetSex(void) const;
	CUser* GetUser(void) const;

protected:
    void SetFirstName(CString str);
    void SetLastName(CString str);
    void SetHeight(int nInches);
    void SetRestHR(int nHR);
    void SetSex(int nSex);

    afx_msg void OnUpdateOKButton(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CEditUserDlg)

    // data
    CString m_strFirstName;
    CString m_strLastName;
    int m_nHeight;
    int m_nRestHR;
    int m_nSex;
	CUser* m_pUser;

	CStringFilterEdit m_edtFirstName;
	CStringFilterEdit m_edtLastName;
	CUIntFilterEdit m_edtHeight;
	CUIntFilterEdit m_edtHR;
};
