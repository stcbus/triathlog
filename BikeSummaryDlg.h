#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CBikeSummaryDlg : public CAniDialog
{
public:
	CBikeSummaryDlg(CWnd* pParent = NULL);   
	virtual ~CBikeSummaryDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_BIKESUMMARYDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnDoubleClick(void);
    CString FindExtremeDate(CBike* pBike, bool fEarliest);
    void PopulateDatesBox(CBike* pBike);

    afx_msg void OnRetire(void);
    afx_msg void UpdateRetireButton(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CBikeSummaryDlg)

    // data
    CUser* m_pUser;
};
