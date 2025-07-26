#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CChartDlg;

class CPEChartSeriesDlg : public CDialog
{
public:
	CPEChartSeriesDlg(int nNum, bool bCheck, CWnd* pParent = NULL);
    virtual ~CPEChartSeriesDlg();

	enum { IDD = IDD_PECHARTSERIESDLG };

    virtual BOOL OnInitDialog(void);

    COLORREF GetLineColor(void) const;
    void SetLineColor(COLORREF cr);
	COLORREF GetPointColor(void) const;
	void SetPointColor(COLORREF cr);

    int GetXAxisType(void) const;
    int GetYAxisType(void) const;
	int GetZAxisType(void) const;
    CString GetXAxisTitle(void) const;
    CString GetYAxisTitle(void) const;
	CString GetZAxisTitle(void) const;
    CString GetGraphTitle(void) const;
	CString GetGraphSubtitle(void) const;
    CString GetSeriesTitle(void) const;
	int GetSeriesType(void) const;
	bool ShouldUseSeries(void) const;
	int GetPointType(void) const;
	int GetLineType(void) const;

    CString GetFormulaX(void) const;
    CString GetFormulaY(void) const;
    CString GetFormulaZ(void) const;

    void SetParentDlg(CPEChartDlg* pDlg);
    CPEChartDlg* GetParentDlg(void) const;

    bool DoEnableGraphButton(void) const;
	void HandleGraphTypeChanged(int nGraphType);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnPaint(void);
    afx_msg void OnXAxisChanged(void);
    afx_msg void OnYAxisChanged(void);
    afx_msg void OnZAxisChanged(void);
	afx_msg void OnUseSeriesChanged(void);

    CString TranslateToEnglish(CString str, bool fForTitle);
    CString CharToFunction(char ch, bool fForTitle);

    bool ChooseNewColor(COLORREF& rcrPicked, COLORREF crStart);

	DECLARE_MESSAGE_MAP()

    // data
    COLORREF m_crLine;
	COLORREF m_crPoint;
	CString m_strNum;
	bool m_bStartChecked;
    CPEChartDlg* m_pParentDlg;
    CString m_strXFormula;
    CString m_strYFormula;
	CString m_strZFormula;
    int m_nLastXSel;
    int m_nLastYSel;
	int m_nLastZSel;

	CEmptyStringFilterEdit m_edtSeriesTitle;
	CEmptyStringFilterEdit m_edtXTitle;
	CEmptyStringFilterEdit m_edtYTitle;
	CEmptyStringFilterEdit m_edtZTitle;
	CEmptyStringFilterEdit m_edtGraphTitle;
	CEmptyStringFilterEdit m_edtGraphSubtitle;
};