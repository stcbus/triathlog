#pragma once

#include "AniDialog.h"

class CVersionSuccessDlg : public CAniDialog
{
public:
	CVersionSuccessDlg();

	enum { IDD = IDD_CONVERTSUCCESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
};
