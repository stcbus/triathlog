#pragma once

#include "AniDialog.h"

class CSearchHelpDlg : public CAniDialog
{
public:
	CSearchHelpDlg();

	enum { IDD = IDD_SEARCHHELPDLG };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
