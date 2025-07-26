#include "AniDialog.h"

#pragma once


class COpenUserDlg : public CAniDialog
{
public:
	COpenUserDlg(CWnd* pParent = NULL);   
	virtual ~COpenUserDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_OPENUSERDLG };

    CString GetSelectedFile(void) const;
protected:
    void SetSelectedFile(CString str);
    void RefreshListbox(void);

	virtual void DoDataExchange(CDataExchange* pDX);  
    afx_msg void OnAddUser(void);
    afx_msg void OnDeleteUser(void);
    afx_msg void OnUpdateOKDelete(void);

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(COpenUserDlg)

    CString m_strSelected;
    CStringList m_strlstFiles;
};
