#pragma once

#include "StdAfx.h"
#include "User.h"
#include "RunningLog.h"
#include "Util.h"
#include <math.h>
#include "AniDialog.h"
#include "PEChartGeneralDlg.h"
#include "PEChartSeriesDlg.h"
#include "PEChartSeries2Dlg.h"
#include "RollupCtrl.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"


class CPEChartDlg : public CAniDialog
{
public:
	CPEChartDlg(int nID, CWnd* pParent);
    virtual ~CPEChartDlg();

	enum { IDD = IDD_PECHARTMEDIUMDLG };

    virtual BOOL OnInitDialog(void);

    COleDateTime GetGraphTime(void) const;
    void SetGraphTime(COleDateTime tm);

	CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

	void OnUpdateGraphButton(void);
	void OnGraphTypeChanged(void);
	int GetGraphType(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void PostNcDestroy(void);
	afx_msg void OnDestroy(void);

	afx_msg void OnGraph(void);
	afx_msg void OnGraphHelp(void);

	int GetSeriesData(COleDateTime tmFrom, COleDateTime tmTo, int nIncr, int nType,
                      CArray<double>& rardVals, CString strFormula);
	void FillFormulaArray(CUser* pUser, CArray<double>& rardVals, COleDateTime tmFrom, 
                          COleDateTime tmTo, int nDays, int nPoints, int nIncr, 
                          CString strFormula, int nNullValue);
	int TranslateGraphType(int nSel);
	int TranslateSeriesType(int nSel, int& rnExtra, int nGraphType);
	int TranslatePointType(int nSel);
	int TranslateLineType(int nSel);
	int TranslateLegendLocation(int nSel);
	int TranslatePointSelection(int nSel);
	int TranslateRotationIncrement(int nSel);

	void SetupGeneralGraph(CString strTitle, CString strSubtitle, int nLegendLoc, int nPointSelType, 
						   bool bLabelPoints, COLORREF crNPTextColor, COLORREF crPTextColor,
						   COLORREF crNPBgColor1, COLORREF crNPBgColor2, COLORREF crPBgColor1, 
						   COLORREF crPBgColor2);
	void Setup2D2DGraph(CString strXAxisTitle, CString strYAxisTitle, 
						bool bLogX, bool bLogY, bool bGridX, bool bGridY);
	void Setup3DBarGraph(bool bRotate, int nRotationIncrement, bool bLogX, bool bLogY,
						 bool bLogZ, bool bGridX, bool bGridY, bool bGrid,
			    		 CString strXAxisTitle, CString strYAxisTitle, CString strZAxisTitle);
	void Setup3DScatterGraph(bool bRotate, int nRotationIncrement, bool bLogX, bool bLogY,
							 bool bLogZ, bool bGridX, bool bGridY, bool bGridZ,
							 CString strXAxisTitle, CString strYAxisTitle, CString strZAxisTitle);
	void SetupPolarPolarGraph(CString strXAxisTitle, CString strYAxisTitle, 
						      bool bGridX, bool bGridY);
	void SetupPolarSmithGraph(CString strXAxisTitle, CString strYAxisTitle, 
						      bool bGridX, bool bGridY);
	void SetupPolarRoseGraph(CString strXAxisTitle, CString strYAxisTitle, 
						      bool bGridX, bool bGridY);
	void SetupPieGraph(CString strYAxisTitle);


	DECLARE_MESSAGE_MAP()

	enum
	{
		NULL_VALUE = -54321,
		NUM_SERIES = 12
	};

    // data
    COleDateTime m_tmDate;
    CUser* m_pUser;

	CWnd m_wndPEChart;
    CPEChartGeneralDlg* m_pGeneralDlg;
    CPEChartSeriesDlg* m_pSeriesDlg;
	CPEChartSeries2Dlg* m_apSeries2Dlg[NUM_SERIES - 1];

    CRollupCtrl m_wndRollupCtrl;
};