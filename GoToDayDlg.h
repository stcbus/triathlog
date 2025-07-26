#include "AniDialog.h"

#pragma once

class CGoToDayDlg : public CAniDialog
{
public:
	CGoToDayDlg(CWnd* pParent = NULL);   
	virtual ~CGoToDayDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_GOTODAYDLG };

    COleDateTime GetDate(void) const;
    void SetDate(COleDateTime tm);

protected:
    afx_msg void OnUpdateOKButton(void);
	afx_msg void OnDropDown(NMHDR* pNmHdr, LRESULT* pResult);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CGoToDayDlg)

    // data
    COleDateTime m_tmDate;
};
