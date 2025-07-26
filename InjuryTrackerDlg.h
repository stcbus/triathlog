#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CInjuryTrackerDlg : public CAniDialog
{
public:
	CInjuryTrackerDlg(CWnd* pParent = NULL);   
	virtual ~CInjuryTrackerDlg();

    virtual BOOL OnInitDialog(void);
	virtual void OnOK(void);

	enum { IDD = IDD_INJURYTRACKERDLG };

    CUser* GetUser(void) const;
	int GetLastSel(void) const;
    void SetUser(CUser* pUser);
	void SetLastSel(int nSel);

protected:
    afx_msg void OnSelChange(void);
	afx_msg void OnFinishedClicked(void);
	afx_msg void OnAddInjury(void);
	afx_msg void OnStartDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnEndDropDown(NMHDR* pNmHdr, LRESULT* pResult);

	void FillCombo(void);
	void SaveCurrentInfo(int nSel);
	void EnableWindows(bool bEnable);
    
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CInjuryTrackerDlg)

    // data
    CUser* m_pUser;
	int m_nLastSel;

	CEmptyStringFilterEdit m_edtDescription;
	CEmptyStringFilterEdit m_edtTreatment;
};
