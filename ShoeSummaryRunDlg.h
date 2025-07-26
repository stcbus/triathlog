#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CShoeSummaryRunDlg : public CAniDialog
{
public:
	CShoeSummaryRunDlg(CWnd* pParent = NULL);   
	virtual ~CShoeSummaryRunDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_SHOESUMMARYRUNDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnDoubleClick(void);
    CString FindExtremeDate(CShoesRun* pShoes, bool fEarliest);
    void PopulateDatesBox(CShoesRun* pShoes);
    
    afx_msg void OnRetire(void);
    afx_msg void UpdateRetireButton(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CShoeSummaryRunDlg)

    // data
    CUser* m_pUser;
};
