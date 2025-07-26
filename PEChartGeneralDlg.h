#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CPEChartDlg;

class CPEChartGeneralDlg : public CDialog
{
public:
	CPEChartGeneralDlg(CWnd* pParent = NULL);
    virtual ~CPEChartGeneralDlg();

	enum { IDD = IDD_PECHARTGENERALDLG };

    virtual BOOL OnInitDialog(void);

    void SetGraphTime(COleDateTime tm);
    COleDateTime GetGraphTime(void) const;
    COleDateTime GetStartTime(void) const;
    COleDateTime GetEndTime(void) const;
    int GetIncrement(void) const;
    int GetGraphType(void) const;
	bool ShowXGridLines(void) const;
	bool ShowYGridLines(void) const;
	bool ShowZGridLines(void) const;
	bool IsXAxisLog(void) const;
	bool IsYAxisLog(void) const;
	bool IsZAxisLog(void) const;
	int GetPointSelection(void) const;
	int GetLegendLocation(void) const;
	bool LabelPoints(void) const;
	bool DoRotate(void) const;
	int GetRotationIncrement(void) const;

	void SetNPTextColor(COLORREF cr);
	void SetNPBgColor(COLORREF cr, bool bStart);
	void SetPTextColor(COLORREF cr);
	void SetPBgColor(COLORREF cr, bool bStart);

	COLORREF GetNPTextColor(void) const;
	COLORREF GetNPBgColor(bool bStart) const;
	COLORREF GetPTextColor(void) const;
	COLORREF GetPBgColor(bool bStart) const;

    void SetParentDlg(CPEChartDlg* pDlg);
    CPEChartDlg* GetParentDlg(void) const;

    bool DoEnableGraphButton(void) const;
	void HandleGraphTypeChanged(int nGraphType);
protected:
	bool ChooseNewColor(COLORREF& rcrPicked, COLORREF crStart);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPaint(void);

	afx_msg void OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult);
	afx_msg void OnRotateClicked(void);
    afx_msg void OnUpdateGraphButton(void);
	afx_msg void OnGraphTypeChanged(void);

	DECLARE_MESSAGE_MAP()

    // data
    COleDateTime m_tmDate;
    CPEChartDlg* m_pParentDlg;
	COLORREF m_crNPTextColor;
	COLORREF m_crNPBgColor[2];
	COLORREF m_crPTextColor;
	COLORREF m_crPBgColor[2];

	CUIntFilterEdit m_edtIncrement;
};