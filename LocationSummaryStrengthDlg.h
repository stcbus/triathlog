#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CLocationSummaryStrengthDlg : public CAniDialog
{
public:
	CLocationSummaryStrengthDlg(CWnd* pParent = NULL);   
	virtual ~CLocationSummaryStrengthDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_LOCATIONSUMMARYSTRENGTHDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnDoubleClick(void);
    void ComputeLocationData(CLocationStrength* pLocation, int& rnWorkouts, double& rdMinutes);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CLocationSummaryStrengthDlg)

    // data
    CUser* m_pUser;
};
