#pragma once

#include "AniDialog.h"

class CGettingStartedDlg : public CAniDialog
{
public:
	CGettingStartedDlg();

	enum { IDD = IDD_GETTINGSTARTEDDLG };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
