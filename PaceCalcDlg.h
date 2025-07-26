#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"
#include "BtnST.h"

#pragma once


class CPaceCalcDlg : public CAniDialog
{
public:
	CPaceCalcDlg(CWnd* pParent = NULL);   
	virtual ~CPaceCalcDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_PACECALCDLG };

protected:
    afx_msg void OnUpdatePaces(void);

    bool GetMiles(double& rdMiles, bool f1);
    void SetPaceBox(double dMinutes, double dMiles, int nIDPaceType, int nIDPace);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_DYNAMIC(CPaceCalcDlg)
    DECLARE_MESSAGE_MAP()

	CDoubleFilterEdit m_edtDist1;
	CDoubleFilterEdit m_edtDist2;
	CDoubleFilterEdit m_edtExp;
	CTimeIntervalFilterEdit m_edtTime1;

	CButtonST m_btnFormula;
};