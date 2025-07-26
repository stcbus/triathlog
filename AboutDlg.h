#pragma once

#include "HyperLink.h"
#include "AniDialog.h"

class CAboutDlg : public CAniDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    CHyperLink m_lnkEmail;
    CHyperLink m_lnkWebsite;
	CHyperLink m_lnkPayPal;
	DECLARE_MESSAGE_MAP()
};
