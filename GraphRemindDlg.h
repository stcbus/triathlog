#pragma once

#include "AniDialog.h"

class CGraphRemindDlg : public CAniDialog
{
public:
	CGraphRemindDlg();

	enum { IDD = IDD_GRAPHREMINDDLG };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
