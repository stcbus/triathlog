#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once


class CConverterDlg : public CAniDialog
{
public:
	CConverterDlg(CWnd* pParent = NULL);

	enum { IDD = IDD_DISTCONVERTERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	virtual BOOL OnInitDialog(void);

    afx_msg void OnUpdateDist(void);
	afx_msg void OnUpdateDecimals(void);
	afx_msg void OnCopyResult(void);

	CDoubleFilterEdit m_edtDist;

	DECLARE_MESSAGE_MAP()
};
