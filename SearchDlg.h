#include "AniDialog.h"
#include "User.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CSearchDlg : public CAniDialog
{
public:
	CSearchDlg(CWnd* pParent = NULL);   
	virtual ~CSearchDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_SEARCHDLG };

    COleDateTime GetTimeFrom(void) const;
    COleDateTime GetTimeTo(void) const;

    void SetTimeFrom(COleDateTime tm);
    void SetTimeTo(COleDateTime tm);

	void SetUser(CUser* pUser);
	CUser* GetUser(void) const;

protected:
	enum
	{
		NUM_FIELDS = 12,
		NUM_COMBO = 11,
		NUM_CUTOFF = 6
	};

	void OnSearchChanged(int nIDCombo, int nIDText);
	void FillWorkoutCombo(int nIDActivity, int nIDCombo);
	bool IsCombinationValid(CString strCombo, bool abUseSeries[NUM_FIELDS]) const;

	COleDateTime GetStartDate(void) const;
	COleDateTime GetEndDate(void) const;
	void FindExtremeDates(COleDateTime& rtmEarly, COleDateTime& rtmLate);

	COleDateTime GetCurStart(COleDateTime tmStart, int nTimePeriod, int nSpan);
	COleDateTime GetCurEnd(COleDateTime tmStart, int nTimePeriod, int nSpan);

	bool Evaluate(COleDateTime tmStart, COleDateTime tmEnd, int nType, int nRel, double dCutoff);
	bool Evaluate(COleDateTime tmStart, COleDateTime tmEnd, int nActivityType, int nWorkoutType);
	bool Evaluate(COleDateTime tmStart, COleDateTime tmEnd, CString strSearch);

	void SetLastSpanType(int nType);
	int GetLastSpanType(void) const;

    afx_msg void OnUpdateSearchButton(void);

	afx_msg void OnCheck1Clicked(void);
	afx_msg void OnCheck2Clicked(void);
	afx_msg void OnCheck3Clicked(void);
	afx_msg void OnCheck4Clicked(void);
	afx_msg void OnCheck5Clicked(void);
	afx_msg void OnCheck6Clicked(void);
	afx_msg void OnCheck7Clicked(void);
	afx_msg void OnCheck8Clicked(void);
	afx_msg void OnCheck9Clicked(void);
	afx_msg void OnCheck10Clicked(void);
	afx_msg void OnCheck11Clicked(void);
	afx_msg void OnCheck12Clicked(void);

	afx_msg void OnButton1Clicked(void);
	afx_msg void OnButton2Clicked(void);
	afx_msg void OnButton3Clicked(void);
	afx_msg void OnButton4Clicked(void);
	afx_msg void OnButton5Clicked(void);
	afx_msg void OnButton6Clicked(void);
	afx_msg void OnButton7Clicked(void);
	afx_msg void OnButton8Clicked(void);
	afx_msg void OnButton9Clicked(void);
	afx_msg void OnButton10Clicked(void);
	afx_msg void OnButton11Clicked(void);
	afx_msg void OnButton12Clicked(void);
	afx_msg void OnLParenClicked(void);
	afx_msg void OnAndClicked(void);
	afx_msg void OnOrClicked(void);
	afx_msg void OnNotClicked(void);
	afx_msg void OnXorClicked(void);
	afx_msg void OnRParenClicked(void);
	afx_msg void OnUndoClicked(void);
	afx_msg void OnClearClicked(void);

	afx_msg void OnHowToButtonClicked(void);
	afx_msg void OnSearchButtonClicked(void);
	afx_msg void OnCopyToClipboardButtonClicked(void);

	afx_msg void OnSearchForChanged(void);
	afx_msg void OnAllDatesClicked(void);
	afx_msg void OnBetweenDatesClicked(void);
	afx_msg void OnSearch1Changed(void);
	afx_msg void OnSearch2Changed(void);
	afx_msg void OnSearch3Changed(void);
	afx_msg void OnSearch4Changed(void);
	afx_msg void OnSearch5Changed(void);
	afx_msg void OnSearch6Changed(void);
	afx_msg void OnSearch7Changed(void);
	afx_msg void OnSearch8Changed(void);
	afx_msg void OnSearch9Changed(void);
	afx_msg void OnSearch10Changed(void);
	afx_msg void OnSearch11Changed(void);

	afx_msg void OnDoubleClick(void);

	afx_msg void OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CSearchDlg)

    // data
	CSkinProgress* m_pProgress;
    COleDateTime m_tmFrom;
    COleDateTime m_tmTo;
	CUser* m_pUser;
	CString m_strLast;
	int m_nLastSpanType;

	CDoubleFilterEdit m_edtCutoff1;
	CDoubleFilterEdit m_edtCutoff2;
	CDoubleFilterEdit m_edtCutoff3;
	CDoubleFilterEdit m_edtCutoff4;
	CDoubleFilterEdit m_edtCutoff5;
	CDoubleFilterEdit m_edtCutoff6;
	CStringFilterEdit m_edtSearch12;
};

BOOL PeekAndPump3(void);