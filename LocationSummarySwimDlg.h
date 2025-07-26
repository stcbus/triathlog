#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CLocationSummarySwimDlg : public CAniDialog
{
public:
	CLocationSummarySwimDlg(CWnd* pParent = NULL);   
	virtual ~CLocationSummarySwimDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_LOCATIONSUMMARYSWIMDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnDoubleClick(void);
    void ComputeLocationData(CLocationSwim* pLocation, int& rnWorkouts, double& rdMinutes, double& rdMiles);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CLocationSummarySwimDlg)

    // data
    CUser* m_pUser;
};
