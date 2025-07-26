#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CShoeSummaryBikeDlg : public CAniDialog
{
public:
	CShoeSummaryBikeDlg(CWnd* pParent = NULL);   
	virtual ~CShoeSummaryBikeDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_SHOESUMMARYBIKEDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnDoubleClick(void);
    CString FindExtremeDate(CShoesBike* pShoes, bool fEarliest);
    void PopulateDatesBox(CShoesBike* pShoes);
    
    afx_msg void OnRetire(void);
    afx_msg void UpdateRetireButton(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CShoeSummaryBikeDlg)

    // data
    CUser* m_pUser;
};
