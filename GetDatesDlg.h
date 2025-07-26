#include "AniDialog.h"

#pragma once

class CGetDatesDlg : public CAniDialog
{
public:
	CGetDatesDlg(CWnd* pParent = NULL);   
	virtual ~CGetDatesDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_GETDATESDLG };

    COleDateTime GetTimeFrom(void) const;
    COleDateTime GetTimeTo(void) const;

    void SetTimeFrom(COleDateTime tm);
    void SetTimeTo(COleDateTime tm);

    afx_msg void OnUpdateOKButton(void);
	afx_msg void OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CGetDatesDlg)

    // data
    COleDateTime m_tmFrom;
    COleDateTime m_tmTo;
};