#include "StdAfx.h"
#include <ctype.h>
#include <math.h>
#include "RunningLog.h"
#include "Util.h"
#include "AniDialog.h"
#include "PEChartGeneralDlg.h"
#include "PEChartSeriesDlg.h"
#include "PEChartSeries2Dlg.h"
#include "RollupCtrl.h"
#include "GraphRemindDlg.h"
#include "FormulaParser.h"
#include "PEGrpApi.h"
#include "PEMessage.h"
#include "PEChartDlg.h"


BEGIN_MESSAGE_MAP(CPEChartDlg, CAniDialog)
    ON_WM_DESTROY()

	ON_COMMAND(IDC_GRAPH, OnGraph)
	ON_COMMAND(IDC_GRAPHHELP, OnGraphHelp)
END_MESSAGE_MAP()


CPEChartDlg::CPEChartDlg(int nID, CWnd* pParent) : CAniDialog(nID, pParent)
{
}


CPEChartDlg::~CPEChartDlg(void)
{
}


BOOL CPEChartDlg::OnInitDialog(void)
{
    BOOL bRet = CAniDialog::OnInitDialog();

    CWnd* pChartWnd = GetDlgItem(IDC_PEGRAPH);
    if(NULL == pChartWnd)
    {
        return FALSE;
    }

	// initialize chart here?

    CWnd* pRollupWnd = GetDlgItem(IDC_ROLLUP);
    if(NULL == pRollupWnd) 
    {
        return FALSE;
    }

    CRect rcRollup;
    pRollupWnd->GetWindowRect(&rcRollup);
    ScreenToClient(&rcRollup);
    rcRollup.DeflateRect(5, 5, 5, 5);
    
    m_wndRollupCtrl.Create(WS_VISIBLE | WS_CHILD, rcRollup, this, 2);

    m_pGeneralDlg = new CPEChartGeneralDlg;
	m_pSeriesDlg = new CPEChartSeriesDlg(1, true);

	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		m_apSeries2Dlg[i] = new CPEChartSeries2Dlg(i + 2, false);
	}

	if((NULL == m_pGeneralDlg) || (NULL == m_pSeriesDlg))
	{
		return FALSE;
	}
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		if(NULL == m_apSeries2Dlg[i])
		{
			return FALSE;
		}
	}

	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		m_apSeries2Dlg[i]->SetParentDlg(this);
		m_apSeries2Dlg[i]->Create(IDD_PECHARTSERIES2DLG, &m_wndRollupCtrl);
	}

	m_pSeriesDlg->SetParentDlg(this);
	m_pSeriesDlg->Create(IDD_PECHARTSERIESDLG, &m_wndRollupCtrl);

    m_pGeneralDlg->SetParentDlg(this);
    m_pGeneralDlg->SetGraphTime(GetGraphTime());
    m_pGeneralDlg->Create(IDD_PECHARTGENERALDLG, &m_wndRollupCtrl);

    m_wndRollupCtrl.InsertPage("General", m_pGeneralDlg, TRUE);
	m_wndRollupCtrl.InsertPage("Series 1", m_pSeriesDlg, TRUE);
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		CString str;
		str.Format("Series %d", i + 2);
		m_wndRollupCtrl.InsertPage(str, m_apSeries2Dlg[i], TRUE);
	}

	for(int i = NUM_SERIES; i >= 0; i--)
	{
		BOOL bEnable = (i <= 1 ? TRUE : FALSE);
		m_wndRollupCtrl.ExpandPage(i, bEnable);
	}

	m_wndRollupCtrl.EnableAllPages(TRUE);
	m_wndRollupCtrl.ExpandAllPages(TRUE);
	m_wndRollupCtrl.ExpandAllPages(FALSE);
	m_wndRollupCtrl.ExpandPage(1, TRUE);
	m_wndRollupCtrl.ExpandPage(0, TRUE);

    OnUpdateGraphButton();

    return bRet;
}


void CPEChartDlg::OnDestroy(void)
{
    EnableAni(false);

    CAniDialog::OnDestroy();
}



void CPEChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX);
}


void CPEChartDlg::PostNcDestroy(void)
{
    CAniDialog::PostNcDestroy();

    delete this;
}


void CPEChartDlg::OnUpdateGraphButton(void)
{
	if((NULL == m_pGeneralDlg) || (NULL == m_pSeriesDlg))
    {
        return;
    }
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		if(NULL == m_apSeries2Dlg[i])
		{
			return;
		}
	}

    bool fRes = true;
    
    fRes &= m_pGeneralDlg->DoEnableGraphButton();
	fRes &= m_pSeriesDlg->DoEnableGraphButton();
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		fRes &= m_apSeries2Dlg[i]->DoEnableGraphButton();
	}

    CWnd* pWnd = GetDlgItem(IDC_GRAPH);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fRes);
    }
}


void CPEChartDlg::OnGraphTypeChanged(void)
{
	if((NULL == m_pGeneralDlg) || (NULL == m_pSeriesDlg))
    {
        return;
    }
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		if(NULL == m_apSeries2Dlg[i])
		{
			return;
		}
	}

	int nType = m_pGeneralDlg->GetGraphType();
    
	m_pGeneralDlg->HandleGraphTypeChanged(nType);
	m_pSeriesDlg->HandleGraphTypeChanged(nType);

	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		m_apSeries2Dlg[i]->HandleGraphTypeChanged(nType);
	}
}
	

int CPEChartDlg::GetGraphType(void)
{
	if(NULL == m_pGeneralDlg)
	{
		CUtil::Fatal("Bad pointer in CPEChartDlg::GetGraphType");
		return GRAPHTYPE_2D2D;
	}
	if(!::IsWindow(m_pGeneralDlg->m_hWnd))
	{
		return GRAPHTYPE_2D2D;
	}

	return m_pGeneralDlg->GetGraphType();
}


void CPEChartDlg::OnGraphHelp(void)
{
	CGraphRemindDlg dlg;
	dlg.DoModal();
}


void CPEChartDlg::OnGraph(void)
{
    if((NULL == m_pGeneralDlg) || (NULL == m_pSeriesDlg))
    {
        return;
    }

	CWaitCursor wc;

	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		if(NULL == m_apSeries2Dlg[i])
		{
			return;
		}
	}

	// get general dlg stuff
    COleDateTime tmFrom = m_pGeneralDlg->GetStartTime();
    COleDateTime tmTo = m_pGeneralDlg->GetEndTime();
    int nIncrement = m_pGeneralDlg->GetIncrement();
	int nNonTransGraphType = m_pGeneralDlg->GetGraphType();
	int nGraphType = TranslateGraphType(nNonTransGraphType);
	bool bGridX = m_pGeneralDlg->ShowXGridLines();
	bool bGridY = m_pGeneralDlg->ShowYGridLines();
	bool bGridZ = m_pGeneralDlg->ShowZGridLines();
	bool bLogX = m_pGeneralDlg->IsXAxisLog();
	bool bLogY = m_pGeneralDlg->IsYAxisLog();
	bool bLogZ = m_pGeneralDlg->IsZAxisLog();
	bool bLabelPoints = m_pGeneralDlg->LabelPoints();
	int nPointSelType = TranslatePointSelection(m_pGeneralDlg->GetPointSelection());
	int nLegendLoc = TranslateLegendLocation(m_pGeneralDlg->GetLegendLocation());
	COLORREF crNPTextColor = m_pGeneralDlg->GetNPTextColor();
	COLORREF crNPBgColor1 = m_pGeneralDlg->GetNPBgColor(true);
	COLORREF crNPBgColor2 = m_pGeneralDlg->GetNPBgColor(false);
	COLORREF crPTextColor = m_pGeneralDlg->GetPTextColor();
	COLORREF crPBgColor1 = m_pGeneralDlg->GetPBgColor(true);
	COLORREF crPBgColor2 = m_pGeneralDlg->GetPBgColor(false);
	bool bRotate = m_pGeneralDlg->DoRotate();
	int nRotationIncrement = TranslateRotationIncrement(m_pGeneralDlg->GetRotationIncrement());

	// get series dlg stuff
	bool abUseSeries[NUM_SERIES];
	abUseSeries[0] = true;
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		abUseSeries[i + 1] = m_apSeries2Dlg[i]->ShouldUseSeries();
	}
	int nSeriesUsed = 0;
	for(int i = 0; i < NUM_SERIES; i++)
	{
		if(true == abUseSeries[i])
		{
			nSeriesUsed++;
		}
	}

	CString strXAxisTitle = m_pSeriesDlg->GetXAxisTitle();
	CString strYAxisTitle = m_pSeriesDlg->GetYAxisTitle();
	CString strZAxisTitle = m_pSeriesDlg->GetZAxisTitle();
	CString strTitle = m_pSeriesDlg->GetGraphTitle();
	CString strSubtitle = m_pSeriesDlg->GetGraphSubtitle();
	int anSeriesType[NUM_SERIES];
	int anXAxisType[NUM_SERIES];
	int anYAxisType[NUM_SERIES];
	int anZAxisType[NUM_SERIES];
	CString astrSeriesName[NUM_SERIES];
	COLORREF acrLineColor[NUM_SERIES];
	COLORREF acrPointColor[NUM_SERIES];
	CString astrFormulaX[NUM_SERIES];
	CString astrFormulaY[NUM_SERIES];
	CString astrFormulaZ[NUM_SERIES];
	int anPointType[NUM_SERIES];
	int anLineType[NUM_SERIES];
	int anExtra[NUM_SERIES];

	anSeriesType[0] = TranslateSeriesType(m_pSeriesDlg->GetSeriesType(), anExtra[0], nNonTransGraphType);
	anXAxisType[0] = m_pSeriesDlg->GetXAxisType();
	anYAxisType[0] = m_pSeriesDlg->GetYAxisType();
	anZAxisType[0] = m_pSeriesDlg->GetZAxisType();
	astrSeriesName[0] = m_pSeriesDlg->GetSeriesTitle();
	astrFormulaX[0] = m_pSeriesDlg->GetFormulaX();
	astrFormulaY[0] = m_pSeriesDlg->GetFormulaY();
	astrFormulaZ[0] = m_pSeriesDlg->GetFormulaZ();
	acrLineColor[0] = m_pSeriesDlg->GetLineColor();
	acrPointColor[0] = m_pSeriesDlg->GetPointColor();
	anPointType[0] = TranslatePointType(m_pSeriesDlg->GetPointType());
	anLineType[0] = TranslateLineType(m_pSeriesDlg->GetLineType());
	
	for(int i = 0; i < NUM_SERIES - 1; i++)
	{
		if(false == abUseSeries[i + 1])
		{
			continue;
		}

		anSeriesType[i + 1] = TranslateSeriesType(m_apSeries2Dlg[i]->GetSeriesType(), anExtra[i + 1], nNonTransGraphType);
		anXAxisType[i + 1] = m_apSeries2Dlg[i]->GetXAxisType();
		anYAxisType[i + 1] = m_apSeries2Dlg[i]->GetYAxisType();
		anZAxisType[i + 1] = m_apSeries2Dlg[i]->GetZAxisType();
		astrSeriesName[i + 1] = m_apSeries2Dlg[i]->GetSeriesTitle();
		astrFormulaX[i + 1] = m_apSeries2Dlg[i]->GetFormulaX();
		astrFormulaY[i + 1] = m_apSeries2Dlg[i]->GetFormulaY();
		astrFormulaZ[i + 1] = m_apSeries2Dlg[i]->GetFormulaZ();
		acrLineColor[i + 1] = m_apSeries2Dlg[i]->GetLineColor();
		acrPointColor[i + 1] = m_apSeries2Dlg[i]->GetPointColor();
		anPointType[i + 1] = TranslatePointType(m_apSeries2Dlg[i]->GetPointType());
		anLineType[i + 1] = TranslateLineType(m_apSeries2Dlg[i]->GetLineType());
	}

    if(!CUtil::IsDateValid(tmFrom))
    {
        AfxMessageBox("Please enter a valid starting date.");
        return;
    }

    if(!CUtil::IsDateValid(tmTo))
    {
        AfxMessageBox("Please enter a valid ending date.");
        return;
    }

    int nNum = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom);
    if(nNum <= 0)
    {
        AfxMessageBox("The start date must be earlier than the end date.");
        return;
    }
    if((nNum + 1) % nIncrement != 0)
    {
        CString str;
        str.Format("The start and end date must be a multiple of %d day(s) apart.  Either extend the interval by %d days or decrease it by %d days.", nIncrement, nIncrement - ((nNum + 1) % nIncrement), (nNum + 1) % nIncrement);
        AfxMessageBox(str);
        return;
    }

	int nPoints = (nNum / nIncrement) + 1;

	CWnd* pChartWnd = GetDlgItem(IDC_PEGRAPH);
	if(NULL == pChartWnd)
	{
		return;
	}
    CRect rc;
	pChartWnd->GetClientRect(&rc);

	if(NULL != m_wndPEChart.m_hWnd)
	{
		PEdestroy(m_wndPEChart.m_hWnd);
	}

	// create here
	m_wndPEChart.m_hWnd = PEcreate(nGraphType, WS_VISIBLE, &rc, pChartWnd->m_hWnd, 1001);
	if(NULL == m_wndPEChart.m_hWnd)
	{
		return;
	}

	SetupGeneralGraph(strTitle, strSubtitle, nLegendLoc, nPointSelType, bLabelPoints, crNPTextColor, 
					  crPTextColor, crNPBgColor1, crNPBgColor2, crPBgColor1, crPBgColor2);

	if(false /* true */)
	{
		// basic stuff, just to test the graph
		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, 1);
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, 10);
		PEnset(m_wndPEChart.m_hWnd, PEP_bNULLDATAGAPS, FALSE);
		PEnset(m_wndPEChart.m_hWnd, PEP_nPLOTTINGMETHOD, PEGPM_BUBBLE);

//		PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
//		PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);
//		PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGZDATAII, TRUE);
		double d = NULL_VALUE;
		PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &d, 1);
		PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEZ, &d, 1);
		PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &d, 1);
		PEnset(m_wndPEChart.m_hWnd, PEP_bALLOWDATAHOTSPOTS, TRUE);

		// Make Data hots spot locations larger //
		PEnset(m_wndPEChart.m_hWnd, PEP_nHOTSPOTSIZE, PEHSS_LARGE);
		float dX[10] = {10.0F, 13.0F, 15.0F, 17.0F, 20.0F, 23.0F, 25.5F, 28.5F, 29.0F, 30.0F};
		float dY[10] = {10.0F, 14.0F, 17.5F, 14.5F, 25.3F, 23.0F, 0.0F, 14.0F, 12.0F, 30.0F};
		float dZ[10] = {2.0F, 1.0F, 3.0F, 4.0F, 2.0F, 5.0F, 3.0F, 2.0F, 8.0F, 0.3F};

		for(int j = 0; j < 10; j++)
		{
			PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATA, 0, j, &dX[j]);
			PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATA, 0, j, &dY[j]);
			PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faZDATA, 0, j, &dY[j]);
		}
	}
	else if(GRAPHTYPE_2D2D == nNonTransGraphType)
	{
		Setup2D2DGraph(strXAxisTitle, strYAxisTitle, bLogX, bLogY, bGridX, bGridY);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
			}
			
			if(DATATYPE_TIME == anXAxisType[i])
			{
				PEnset(m_wndPEChart.m_hWnd, PEP_nDATETIMEMODE, PEDTM_VB);
				PEnset(m_wndPEChart.m_hWnd, PEP_nTIMELABELTYPE, PETLT_12HR_AM_PM);
				PEnset(m_wndPEChart.m_hWnd, PEP_nMONTHLABELTYPE, PEMLT_3_CHAR);
				PEnset(m_wndPEChart.m_hWnd, PEP_nDAYLABELTYPE, PEDLT_3_CHAR);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naPLOTTINGMETHODS, pnPlotType, nSeriesUsed);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}

	else if(GRAPHTYPE_3DBAR == nNonTransGraphType)
	{
		if(-1 != anExtra[0])
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nPOLYMODE, anExtra[0]);
		}

		Setup3DBarGraph(bRotate, nRotationIncrement, bLogX, bLogY, bLogZ, bGridX, bGridY, bGridZ, 
				        strXAxisTitle, strYAxisTitle, strZAxisTitle);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);
		PEnset(m_wndPEChart.m_hWnd, PEP_bNULLDATAGAPS, FALSE);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		CArray<double> ardZVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || 
		   (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();
			ardZVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anZAxisType[i], ardZVals, astrFormulaZ[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
				dCur = ardZVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faZDATAII, nCur, j, &dCur);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEnset(m_wndPEChart.m_hWnd, PEP_nPLOTTINGMETHOD, pnPlotType[0]);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}

	else if(GRAPHTYPE_3DSCATTER == nNonTransGraphType)
	{
		if(-1 != anExtra[0])
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nPOLYMODE, anExtra[0]);
		}

		Setup3DScatterGraph(bRotate, nRotationIncrement, bLogX, bLogY, bLogZ, bGridX, bGridY, bGridZ,
				            strXAxisTitle, strYAxisTitle, strZAxisTitle);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);
		PEnset(m_wndPEChart.m_hWnd, PEP_bNULLDATAGAPS, FALSE);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		CArray<double> ardZVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || 
		   (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();
			ardZVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anZAxisType[i], ardZVals, astrFormulaZ[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
				dCur = ardZVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faZDATAII, nCur, j, &dCur);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEnset(m_wndPEChart.m_hWnd, PEP_nPLOTTINGMETHOD, pnPlotType[0]);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}

	else if(GRAPHTYPE_POLARPOLAR == nNonTransGraphType)
	{
		SetupPolarPolarGraph(strXAxisTitle, strYAxisTitle, bGridX, bGridY);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
			}
			
			if(DATATYPE_TIME == anXAxisType[i])
			{
				PEnset(m_wndPEChart.m_hWnd, PEP_nDATETIMEMODE, PEDTM_VB);
				PEnset(m_wndPEChart.m_hWnd, PEP_nTIMELABELTYPE, PETLT_12HR_AM_PM);
				PEnset(m_wndPEChart.m_hWnd, PEP_nMONTHLABELTYPE, PEMLT_3_CHAR);
				PEnset(m_wndPEChart.m_hWnd, PEP_nDAYLABELTYPE, PEDLT_3_CHAR);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naPLOTTINGMETHODS, pnPlotType, nSeriesUsed);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}
	
	else if(GRAPHTYPE_POLARSMITH == nNonTransGraphType)
	{
		SetupPolarSmithGraph(strXAxisTitle, strYAxisTitle, bGridX, bGridY);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
			}
			
			if(DATATYPE_TIME == anXAxisType[i])
			{
				PEnset(m_wndPEChart.m_hWnd, PEP_nDATETIMEMODE, PEDTM_VB);
				PEnset(m_wndPEChart.m_hWnd, PEP_nTIMELABELTYPE, PETLT_12HR_AM_PM);
				PEnset(m_wndPEChart.m_hWnd, PEP_nMONTHLABELTYPE, PEMLT_3_CHAR);
				PEnset(m_wndPEChart.m_hWnd, PEP_nDAYLABELTYPE, PEDLT_3_CHAR);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naPLOTTINGMETHODS, pnPlotType, nSeriesUsed);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}

	else if(GRAPHTYPE_POLARROSE == nNonTransGraphType)
	{
		SetupPolarRoseGraph(strXAxisTitle, strYAxisTitle, bGridX, bGridY);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);

		CArray<double> ardXVals;
		CArray<double> ardYVals;
		double dCur = 0.0;
		int nCur = 0;

		COLORREF* pcrLineColor = new COLORREF[nSeriesUsed];
		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];
		int* pnPointType = new int[nSeriesUsed];
		int* pnLineType = new int[nSeriesUsed];
		int* pnPlotType = new int[nSeriesUsed];

		if((NULL == pcrLineColor) || (NULL == pcrPointColor) || (NULL == pnPointType) || (NULL == pnLineType) || (NULL == pnPlotType))
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardXVals.RemoveAll();
			ardYVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			pcrLineColor[nCur] = acrLineColor[i];
			pnPointType[nCur] = anPointType[i];
			pnLineType[nCur] = anLineType[i];
			pnPlotType[nCur] = anSeriesType[i];

			GetSeriesData(tmFrom, tmTo, nIncrement, anXAxisType[i], ardXVals, astrFormulaX[i]);
			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);

			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = acrPointColor[i];   // change later to set point colors

				dCur = ardXVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATAII, nCur, j, &dCur);
				dCur = ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faYDATAII, nCur, j, &dCur);
			}
			
			if(DATATYPE_TIME == anXAxisType[i])
			{
				PEnset(m_wndPEChart.m_hWnd, PEP_nDATETIMEMODE, PEDTM_VB);
				PEnset(m_wndPEChart.m_hWnd, PEP_nTIMELABELTYPE, PETLT_12HR_AM_PM);
				PEnset(m_wndPEChart.m_hWnd, PEP_nMONTHLABELTYPE, PEMLT_3_CHAR);
				PEnset(m_wndPEChart.m_hWnd, PEP_nDAYLABELTYPE, PEDLT_3_CHAR);
			}

			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrLineColor, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_dwaPOINTCOLORS, pcrPointColor, nSeriesUsed * nPoints);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETLINETYPES, pnLineType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naSUBSETPOINTTYPES, pnPointType, nSeriesUsed);
		PEvset(m_wndPEChart.m_hWnd, PEP_naPLOTTINGMETHODS, pnPlotType, nSeriesUsed);

		delete[] pcrLineColor;
		delete[] pcrPointColor;
		delete[] pnLineType;
		delete[] pnPointType;
		delete[] pnPlotType;
	}

	else if(GRAPHTYPE_PIE == nNonTransGraphType)
	{
		SetupPieGraph(strYAxisTitle);

		PEnset(m_wndPEChart.m_hWnd, PEP_nSUBSETS, nSeriesUsed);	
		PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTS, nPoints);

		CArray<double> ardYVals;
		float fCur = 0.0;
		int nCur = 0;

		COLORREF* pcrPointColor = new COLORREF[nSeriesUsed * nPoints];

		if(NULL == pcrPointColor)
		{
			return;
		}

		for(int i = 0; i < NUM_SERIES; i++)
		{
			ardYVals.RemoveAll();

			if(false == abUseSeries[i])
			{
				continue;
			}

			GetSeriesData(tmFrom, tmTo, nIncrement, anYAxisType[i], ardYVals, astrFormulaY[i]);
			for(int j = 0; j < nPoints; j++)
			{
				pcrPointColor[nCur * nPoints + j] = CUtil::GetRandomColor2(); // acrPointColor[i];   // change later to set point colors

				fCur = (float)ardYVals.ElementAt(j);
				PEvsetcellEx(m_wndPEChart.m_hWnd, PEP_faXDATA, nCur, j, &fCur);

				CString str;
				COleDateTime tmStartInc = CUtil::OffsetDay(tmFrom, j * nIncrement);
				COleDateTime tmEndInc = CUtil::OffsetDay(tmFrom, (j + 1) * nIncrement - 1);
				if(1 == nIncrement)
				{
					str.Format("%d/%d/%d", tmStartInc.GetMonth(), tmStartInc.GetDay(), tmStartInc.GetYear());
				}
				else
				{
					str.Format("%d/%d/%d - %d/%d/%d", tmStartInc.GetMonth(), tmStartInc.GetDay(), tmStartInc.GetYear(),
								tmEndInc.GetMonth(), tmEndInc.GetDay(), tmEndInc.GetYear());
				}
				PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaPOINTLABELS, j, str.GetBuffer(64));
			}
		
			PEvset(m_wndPEChart.m_hWnd, PEP_dwaSUBSETCOLORS, pcrPointColor, nPoints);
			PEnset(m_wndPEChart.m_hWnd, PEP_nDATALABELTYPE, anExtra[i]);
		
			PEvsetcell(m_wndPEChart.m_hWnd, PEP_szaSUBSETLABELS, nCur, astrSeriesName[i].GetBuffer(64));

			nCur++;
		}

		delete[] pcrPointColor;
	}

	else
	{
		MessageBox("not supported yet");
	}

	PEreinitialize(m_wndPEChart.m_hWnd);
	PEresetimage(m_wndPEChart.m_hWnd, 0, 0);
}


void CPEChartDlg::SetupGeneralGraph(CString strTitle, CString strSubtitle, int nLegendLoc, int nPointSelType, 
									bool bLabelPoints, COLORREF crNPTextColor, COLORREF crPTextColor,
									COLORREF crNPBgColor1, COLORREF crNPBgColor2, COLORREF crPBgColor1, 
									COLORREF crPBgColor2)
{
	// no null data gaps
	PEnset(m_wndPEChart.m_hWnd, PEP_bNULLDATAGAPS, FALSE);
	
	// title stuff
	PEszset(m_wndPEChart.m_hWnd, PEP_szMAINTITLE, strTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szSUBTITLE, strSubtitle.GetBuffer(64));
	PEnset(m_wndPEChart.m_hWnd, PEP_bMAINTITLEBOLD, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bSUBTITLEBOLD, TRUE);

	// cursor stuff
	PEnset(m_wndPEChart.m_hWnd, PEP_nCURSORMODE, nPointSelType);
	PEnset(m_wndPEChart.m_hWnd, PEP_bMOUSECURSORCONTROL, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bALLOWDATAHOTSPOTS, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bCURSORPROMPTTRACKING, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_nCURSORPROMPTSTYLE, PECPS_XYVALUES);
	PEnset(m_wndPEChart.m_hWnd, PEP_nCURSORPROMPTLOCATION, PECPL_TOP_LEFT);
	PEnset(m_wndPEChart.m_hWnd, PEP_nHOTSPOTSIZE, PEHSS_LARGE);

	// legend stuff
	PEnset(m_wndPEChart.m_hWnd, PEP_nLEGENDLOCATION, nLegendLoc);
	PEnset(m_wndPEChart.m_hWnd, PEP_nLEGENDSTYLE, PELS_1_LINE);

	// gradient, text color, font face
	PEnset(m_wndPEChart.m_hWnd, PEP_bBITMAPGRADIENTMODE, TRUE);

	PEnset(m_wndPEChart.m_hWnd, PEP_dwTEXTCOLOR, crNPTextColor);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwGRAPHFORECOLOR, crPTextColor);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwTABLEFORECOLOR, crPTextColor);

	PEnset(m_wndPEChart.m_hWnd, PEP_nDESKGRADIENTSTYLE, PEGS_VERTICAL);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwDESKCOLOR, 1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwDESKGRADIENTSTART, crNPBgColor1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwDESKGRADIENTEND, crNPBgColor2);

	PEnset(m_wndPEChart.m_hWnd, PEP_nGRAPHGRADIENTSTYLE, PEGS_VERTICAL);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwGRAPHBACKCOLOR, 1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwGRAPHGRADIENTSTART, crPBgColor1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwGRAPHGRADIENTEND, crPBgColor2);

	PEnset(m_wndPEChart.m_hWnd, PEP_nTABLEGRADIENTSTYLE, PEGS_VERTICAL);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwTABLEBACKCOLOR, 1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwTABLEGRADIENTSTART, crPBgColor1);
	PEnset(m_wndPEChart.m_hWnd, PEP_dwTABLEGRADIENTEND, crPBgColor2);

	float fFactor = 0.88F;
	PEvset(m_wndPEChart.m_hWnd, PEP_fFONTSIZEGLOBALCNTL, &fFactor, 1);
	PEszset(m_wndPEChart.m_hWnd, PEP_szLABELFONT, "Arial");
	PEszset(m_wndPEChart.m_hWnd, PEP_szMAINTITLEFONT, "Arial");
	PEszset(m_wndPEChart.m_hWnd, PEP_szSUBTITLEFONT, "Arial");
	PEszset(m_wndPEChart.m_hWnd, PEP_szTABLEFONT, "Arial");

	// zooming
	PEnset(m_wndPEChart.m_hWnd, PEP_nALLOWZOOMING, PEAZ_HORZANDVERT);
	PEnset(m_wndPEChart.m_hWnd, PEP_nZOOMSTYLE, PEZS_RO2_NOT);  
	PEnset(m_wndPEChart.m_hWnd, PEP_bSCROLLINGHORZZOOM, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bSCROLLINGVERTZOOM, TRUE);

	// menus
	PEnset(m_wndPEChart.m_hWnd, PEP_nFORCEVERTPOINTSMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nLEGENDLOCATIONMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nSHOWLEGENDMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nLONGXAXISTICKMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nLONGYAXISTICKMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nPERCENTORVALUEMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nPLOTMETHODMENU, PEMC_HIDE);  
	PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINEMENU, PEMC_SHOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nVIEWINGSTYLEMENU, PEMC_SHOW);

	// allow stuff
	PEnset(m_wndPEChart.m_hWnd, PEP_bALLOWRIBBON, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bALLOWSTEP, TRUE);

	// misc
	PEnset(m_wndPEChart.m_hWnd, PEP_nPOINTSIZE, PEPS_MEDIUM);
	PEnset(m_wndPEChart.m_hWnd, PEP_nMINIMUMPOINTSIZE, PEPS_MEDIUM);

	PEnset(m_wndPEChart.m_hWnd, PEP_bGRAPHDATALABELS, (int)bLabelPoints);

	PEnset(m_wndPEChart.m_hWnd, PEP_bLINESHADOWS, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_nDATASHADOWS, PEDS_SHADOWS);
	PEnset(m_wndPEChart.m_hWnd, PEP_nTEXTSHADOWS, PETS_BOLD_TEXT);

	PEnset(m_wndPEChart.m_hWnd, PEP_nMAXDATAPRECISION, 7);
	PEnset(m_wndPEChart.m_hWnd, PEP_nDATAPRECISION, 7);

	PEnset(m_wndPEChart.m_hWnd, PEP_bXAXISLONGTICKS, FALSE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bYAXISLONGTICKS, FALSE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bZAXISLONGTICKS, FALSE);

	PEnset(m_wndPEChart.m_hWnd, PEP_bPREPAREIMAGES, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bCACHEBMP, TRUE);

	PEnset(m_wndPEChart.m_hWnd, PEP_bMARKDATAPOINTS, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bFOCALRECT, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bLOGSCALEEXPLABELS, FALSE);
	PEnset(m_wndPEChart.m_hWnd, PEP_nBORDERTYPES, PETAB_DROP_SHADOW);
	PEnset(m_wndPEChart.m_hWnd, PEP_nCURVEGRANULARITY, PECG_FINE);
	PEnset(m_wndPEChart.m_hWnd, PEP_nGRAPHPLUSTABLE, PEGPT_BOTH);
	PEnset(m_wndPEChart.m_hWnd, PEP_nBESTFITDEGREE, PEBFD_4TH);
	PEnset(m_wndPEChart.m_hWnd, PEP_nGRADIENTBARS, 8);
}


void CPEChartDlg::Setup2D2DGraph(CString strXAxisTitle, CString strYAxisTitle, 
								 bool bLogX, bool bLogY, bool bGridX, bool bGridY)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);

	// null data stuff
	double dNull = NULL_VALUE;
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &dNull, 1);
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &dNull, 1);

	// axis labels
	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));

	if(true == bLogX)
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bLogY)
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bGridY)
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}
}


void CPEChartDlg::Setup3DBarGraph(bool bRotate, int nRotationIncrement, bool bLogX, bool bLogY,
								  bool bLogZ, bool bGridX, bool bGridY, bool bGridZ,
								  CString strXAxisTitle, CString strYAxisTitle, CString strZAxisTitle)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGZDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, NULL_VALUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, NULL_VALUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEZ, NULL_VALUE);

	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONDETAIL, PERD_FULLDETAIL);
	PEnset(m_wndPEChart.m_hWnd, PEP_bAUTOROTATION, (int)bRotate);
	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONINCREMENT, nRotationIncrement);

	PEnset(m_wndPEChart.m_hWnd, PEP_nVIEWINGHEIGHT, 22);
	PEnset(m_wndPEChart.m_hWnd, PEP_nDEGREEOFROTATION, 314);
	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONDETAIL, PERD_FULLDETAIL);

	if((true == bLogX) || (true == bLogZ))
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bLogY)
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bGridY)
	{
		if((true == bGridX) || (true == bGridZ))
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if((true == bGridX) || (true == bGridZ))
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}

	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szZAXISLABEL, strZAxisTitle.GetBuffer(64));
}


void CPEChartDlg::Setup3DScatterGraph(bool bRotate, int nRotationIncrement, bool bLogX, bool bLogY,
								      bool bLogZ, bool bGridX, bool bGridY, bool bGridZ,
								      CString strXAxisTitle, CString strYAxisTitle, CString strZAxisTitle)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGZDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, NULL_VALUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, NULL_VALUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEZ, NULL_VALUE);

	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONDETAIL, PERD_FULLDETAIL);
	PEnset(m_wndPEChart.m_hWnd, PEP_bAUTOROTATION, (int)bRotate);
	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONINCREMENT, nRotationIncrement);

	PEnset(m_wndPEChart.m_hWnd, PEP_nVIEWINGHEIGHT, 22);
	PEnset(m_wndPEChart.m_hWnd, PEP_nDEGREEOFROTATION, 314);
	PEnset(m_wndPEChart.m_hWnd, PEP_nROTATIONDETAIL, PERD_FULLDETAIL);

	if((true == bLogX) || (true == bLogZ))
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nXAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bLogY)
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_LOG);
	}
	else
	{
		PEnset(m_wndPEChart.m_hWnd, PEP_nYAXISSCALECONTROL, PEAC_NORMAL);
	}

	if(true == bGridY)
	{
		if((true == bGridX) || (true == bGridZ))
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if((true == bGridX) || (true == bGridZ))
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}

	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szZAXISLABEL, strZAxisTitle.GetBuffer(64));
}


void CPEChartDlg::SetupPolarPolarGraph(CString strXAxisTitle, CString strYAxisTitle, 
								       bool bGridX, bool bGridY)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);

	// null data stuff
	double dNull = NULL_VALUE;
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &dNull, 1);
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &dNull, 1);

	// axis labels
	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));

	PEnset(m_wndPEChart.m_hWnd, PEP_nSMITHCHART, PESC_POLAR);

	if(true == bGridY)
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}
}


void CPEChartDlg::SetupPolarSmithGraph(CString strXAxisTitle, CString strYAxisTitle, 
								       bool bGridX, bool bGridY)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);

	// null data stuff
	double dNull = NULL_VALUE;
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &dNull, 1);
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &dNull, 1);

	// axis labels
	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));

	PEnset(m_wndPEChart.m_hWnd, PEP_nSMITHCHART, PESC_SMITH);

	if(true == bGridY)
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}
}


void CPEChartDlg::SetupPolarRoseGraph(CString strXAxisTitle, CString strYAxisTitle, 
								       bool bGridX, bool bGridY)
{
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGXDATAII, TRUE);
	PEnset(m_wndPEChart.m_hWnd, PEP_bUSINGYDATAII, TRUE);

	// null data stuff
	double dNull = NULL_VALUE;
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &dNull, 1);
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &dNull, 1);

	// axis labels
	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strXAxisTitle.GetBuffer(64));
	PEszset(m_wndPEChart.m_hWnd, PEP_szYAXISLABEL, strYAxisTitle.GetBuffer(64));

	PEnset(m_wndPEChart.m_hWnd, PEP_nSMITHCHART, PESC_ROSE);

	if(true == bGridY)
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_BOTH);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_YAXIS);
		}
	}
	else
	{
		if(true == bGridX)
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_XAXIS);
		}
		else
		{
			PEnset(m_wndPEChart.m_hWnd, PEP_nGRIDLINECONTROL, PEGLC_NONE);
		}
	}
}


void CPEChartDlg::SetupPieGraph(CString strYAxisTitle)
{
	// null data stuff
	double dNull = NULL_VALUE;
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUEX, &dNull, 1);
	PEvset(m_wndPEChart.m_hWnd, PEP_fNULLDATAVALUE, &dNull, 1);

	// exploding
	PEnset(m_wndPEChart.m_hWnd, PEP_nAUTOEXPLODE, PEAE_ALLSUBSETS);
	
	// axis labels
	PEszset(m_wndPEChart.m_hWnd, PEP_szXAXISLABEL, strYAxisTitle.GetBuffer(64));
	
	// data precision
	PEnset(m_wndPEChart.m_hWnd, PEP_nDATAPRECISION, 2);
}


int CPEChartDlg::GetSeriesData(COleDateTime tmFrom, COleDateTime tmTo, int nIncr, int nType,
                             CArray<double>& rardVals, CString strFormula)
{
    int nDays = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom);
    int nPoints = nDays / nIncr + 1;
    int nTotal = 0;

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        switch(nType)
        {
        case DATATYPE_TIME:
            {
                pUser->GetTimeArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MINUTESRUN:
            {
                pUser->GetMinutesRunArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MINUTESBIKE:
            {
                pUser->GetMinutesBikeArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MINUTESSWIM:
            {
                pUser->GetMinutesSwimArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MINUTESSTRENGTH:
            {
                pUser->GetMinutesStrengthArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MINUTESOVERALL:
            {
                pUser->GetMinutesOverallArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MILESRUN:
            {
                pUser->GetMilesRunArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MILESBIKE:
            {
                pUser->GetMilesBikeArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_MILESSWIM:
            {
                pUser->GetMilesSwimArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WORKOUTSRUN:
            {
                pUser->GetWorkoutRunArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WORKOUTSBIKE:
            {
                pUser->GetWorkoutBikeArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WORKOUTSSWIM:
            {
                pUser->GetWorkoutSwimArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WORKOUTSSTRENGTH:
            {
				pUser->GetWorkoutStrengthArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WORKOUTSOVERALL:
            {
                pUser->GetWorkoutOverallArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_POINTS:
            {
                pUser->GetPointsArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_TEMP:
            {
                pUser->GetTemperatureArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_HR:
            {
                pUser->GetHRArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_PACERUN:
            {
                pUser->GetPaceRunArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_PACEBIKE:
            {
                pUser->GetPaceBikeArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }
            
        case DATATYPE_PACESWIM:
            {
                pUser->GetPaceSwimArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }
        
        case DATATYPE_SLEEP:
            {
                pUser->GetSleepArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_WEIGHT:
            {
                pUser->GetWeightArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

        case DATATYPE_TIMEOFDAY:
            {
                pUser->GetTimeOfDayArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
                break;
            }

		case DATATYPE_CALORIES:
			{
				pUser->GetCalorieArray(rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, NULL_VALUE);
				break;
			}

        case DATATYPE_FORMULA:
            {
                FillFormulaArray(pUser, rardVals, tmFrom, tmTo, nDays, nPoints, nIncr, strFormula, NULL_VALUE);
                break;
            }                    

        default:
            {
				CUtil::Fatal("Bad value in CPEChartDlg::GetSeriesData");
                break;
            }
        }
	}

	return nTotal;
}


void CPEChartDlg::FillFormulaArray(CUser* pUser, CArray<double>& rardVals, COleDateTime tmFrom, 
                                 COleDateTime tmTo, int nDays, int nPoints, int nIncr, 
                                 CString strFormula, int nNullValue)
{
    if(NULL == pUser)
    {
        CUtil::Fatal("Bad parameter to CChartDlg::FillFormulaArray");
        return;
    }

    CArray<double> ardRunMinutes;
    CArray<double> ardBikeMinutes;
    CArray<double> ardSwimMinutes;
    CArray<double> ardStrengthMinutes;
    CArray<double> ardOverallMinutes;
    CArray<double> ardRunMiles;
    CArray<double> ardBikeMiles;
    CArray<double> ardSwimMiles;
    CArray<double> ardRunPace;
    CArray<double> ardBikePace;
    CArray<double> ardSwimPace;
    CArray<double> ardRunWorkouts;
    CArray<double> ardBikeWorkouts;
    CArray<double> ardSwimWorkouts;
    CArray<double> ardStrengthWorkouts;
    CArray<double> ardOverallWorkouts;
    CArray<double> ardWeight;
    CArray<double> ardSleep;
    CArray<double> ardTemperature;
    CArray<double> ardHeartrate;
    CArray<double> ardPoints;
	CArray<double> ardCalories;

    pUser->GetMinutesRunArray(ardRunMinutes, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMinutesBikeArray(ardBikeMinutes, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMinutesSwimArray(ardSwimMinutes, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMinutesStrengthArray(ardStrengthMinutes, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMinutesOverallArray(ardOverallMinutes, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMilesRunArray(ardRunMiles, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMilesBikeArray(ardBikeMiles, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetMilesSwimArray(ardSwimMiles, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetPaceRunArray(ardRunPace, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetPaceBikeArray(ardBikePace, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetPaceSwimArray(ardSwimPace, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWorkoutRunArray(ardRunWorkouts, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWorkoutBikeArray(ardBikeWorkouts, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWorkoutSwimArray(ardSwimWorkouts, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWorkoutStrengthArray(ardStrengthWorkouts, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWorkoutOverallArray(ardOverallWorkouts, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetWeightArray(ardWeight, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetSleepArray(ardSleep, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetTemperatureArray(ardTemperature, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetHRArray(ardHeartrate, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetPointsArray(ardPoints, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);
    pUser->GetCalorieArray(ardCalories, tmFrom, tmTo, nDays, nPoints, nIncr, nNullValue);

    for(int i = 0; i < nPoints; i++)
    {
		if((nNullValue == ardRunMinutes.ElementAt(i)) && (nNullValue == ardBikeMinutes.ElementAt(i)) &&
		   (nNullValue == ardSwimMinutes.ElementAt(i)) && (nNullValue == ardStrengthMinutes.ElementAt(i)) &&
		   (nNullValue == ardOverallMinutes.ElementAt(i)) && (nNullValue == ardRunMiles.ElementAt(i)) &&
		   (nNullValue == ardBikeMiles.ElementAt(i)) && (nNullValue == ardSwimMiles.ElementAt(i)) && 
		   (nNullValue == ardRunPace.ElementAt(i)) && (nNullValue == ardBikePace.ElementAt(i)) &&
           (nNullValue == ardSwimPace.ElementAt(i)) && (nNullValue == ardRunWorkouts.ElementAt(i)) &&
		   (nNullValue == ardBikeWorkouts.ElementAt(i)) && (nNullValue == ardSwimWorkouts.ElementAt(i)) &&
		   (nNullValue == ardStrengthWorkouts.ElementAt(i)) && (nNullValue == ardOverallWorkouts.ElementAt(i)) &&
		   (nNullValue == ardWeight.ElementAt(i)) && (nNullValue == ardSleep.ElementAt(i)) &&
		   (nNullValue == ardTemperature.ElementAt(i)) && (nNullValue == ardHeartrate.ElementAt(i)) &&
		   (nNullValue == ardPoints.ElementAt(i)) && (nNullValue == ardCalories.ElementAt(i)))
		{
			rardVals.Add((double)nNullValue);
		}
		else
		{
			CFormulaParser p;
			p.SetFormula(strFormula);
			p.SetFunctConst(0, ardRunMinutes.ElementAt(i));
			p.SetFunctConst(1, ardBikeMinutes.ElementAt(i));
			p.SetFunctConst(2, ardSwimMinutes.ElementAt(i));
			p.SetFunctConst(3, ardStrengthMinutes.ElementAt(i));
			p.SetFunctConst(4, ardOverallMinutes.ElementAt(i));
			p.SetFunctConst(5, ardRunMiles.ElementAt(i));
			p.SetFunctConst(6, ardBikeMiles.ElementAt(i));
			p.SetFunctConst(7, ardSwimMiles.ElementAt(i));
			p.SetFunctConst(8, ardRunPace.ElementAt(i));
			p.SetFunctConst(9, ardBikePace.ElementAt(i));
			p.SetFunctConst(10, ardSwimPace.ElementAt(i));
			p.SetFunctConst(11, ardRunWorkouts.ElementAt(i));
			p.SetFunctConst(12, ardBikeWorkouts.ElementAt(i));
			p.SetFunctConst(13, ardSwimWorkouts.ElementAt(i));
			p.SetFunctConst(14, ardStrengthWorkouts.ElementAt(i));
			p.SetFunctConst(15, ardOverallWorkouts.ElementAt(i));
			p.SetFunctConst(16, ardSleep.ElementAt(i));
			p.SetFunctConst(17, ardWeight.ElementAt(i));
			p.SetFunctConst(18, ardTemperature.ElementAt(i));
			p.SetFunctConst(19, ardHeartrate.ElementAt(i));
			p.SetFunctConst(20, ardPoints.ElementAt(i));
			p.SetFunctConst(21, ardCalories.ElementAt(i));

			CString strError;
			WORD wError = 0;
			double dRes = p.Calculation(strFormula, wError, strError);
			rardVals.Add(dRes);

			if(!strError.IsEmpty())
			{
				AfxMessageBox(CString("There was a problem with the formula.  This is most likely an overflow, a non-real value, or an attempt to divide by zero.  The parsing engine says: " + strError + ".  The graph may behave strangely."));

				return;
			}
		}
    }
}


int CPEChartDlg::TranslateGraphType(int nSel)
{
	switch(nSel)
	{
	case GRAPHTYPE_2D2D:
		{
			return PECONTROL_SGRAPH;
		}

	case GRAPHTYPE_3DBAR:
	case GRAPHTYPE_3DSCATTER:
		{
			return PECONTROL_3D;
		}

	case GRAPHTYPE_POLARPOLAR:
	case GRAPHTYPE_POLARSMITH:
	case GRAPHTYPE_POLARROSE:
		{
			return PECONTROL_PGRAPH;
		}

	case GRAPHTYPE_PIE:
		{
			return PECONTROL_PIE;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateGraphType");
			return PECONTROL_SGRAPH;
		}
	}
}


int CPEChartDlg::TranslateSeriesType(int nSel, int& rnExtra, int nGraphType)
{
	rnExtra = -1;
	if(GRAPHTYPE_2D2D == nGraphType)
	{
		switch(nSel)
		{
		case TWODSERIESTYPE2D_LINE:
			{
				return PEGPM_LINE;
			}

		case TWODSERIESTYPE2D_BAR:
			{
				return PEGPM_BAR;
			}

		case TWODSERIESTYPE2D_STICK:
			{
				return PEGPM_STICK;
			}
		case TWODSERIESTYPE2D_POINTS:
			{
				return PEGPM_POINT;
			}

		case TWODSERIESTYPE2D_SPLINE:
			{
				return PEGPM_SPLINE;
			}

		case TWODSERIESTYPE2D_AREA:
			{
				return PEGPM_AREA;
			}

		case TWODSERIESTYPE2D_RIBBON:
			{
				return PEGPM_RIBBON;
			}

		case TWODSERIESTYPE2D_STEP:
			{
				return PEGPM_STEP;
			}

		case TWODSERIESTYPE2D_POINTSPLUSLINE:
			{
				return PEGPM_POINTSPLUSLINE;
			}

		case TWODSERIESTYPE2D_POINTSPLUSBFL:
			{
				return PEGPM_POINTSPLUSBFL;
			}

		case TWODSERIESTYPE2D_POINTSPLUSBFC:
			{
				return PEGPM_POINTSPLUSBFC;
			}

		case TWODSERIESTYPE2D_POINTSPLUSSPLINE:
			{
				return PEGPM_POINTSPLUSSPLINE;
			}

		default:
			{
				CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
				return PEGPM_SPLINE;
			}	
		}
	}

	else if(GRAPHTYPE_3DBAR == nGraphType)
	{
		rnExtra = PEPM_3DBAR;
		switch(nSel)
		{
		case THREEDSERIESTYPEBAR_WIREFRAME:
			{
				return 0;
			}

		case THREEDSERIESTYPEBAR_SURFACE:
			{
				return 1;
			}

		case THREEDSERIESTYPEBAR_SURFACESHADING:
			{
				return 2;
			}

		case THREEDSERIESTYPEBAR_SURFACEPIXELS:
			{
				return 3;
			}

		default:
			{
				CUtil::Fatal("Bad parameter to CUtil::TranslateSeriesType");
				return 3;
			}
		}
	}

	else if(GRAPHTYPE_3DSCATTER == nGraphType)
	{
		rnExtra = PEPM_SCATTER;
		switch(nSel)
		{
		case THREEDSERIESTYPESCATTER_POINTS:
			{
				return 0;
			}

		case THREEDSERIESTYPESCATTER_LINE:
			{
				return 1;
			}

		case THREEDSERIESTYPESCATTER_POINTSPLUSLINE:
			{
				return 2;
			}

		case THREEDSERIESTYPESCATTER_AREA:
			{
				return 3;
			}

		default:
			{
				CUtil::Fatal("Bad parameter to CUtil::TranslateSeriesType");
				return 0;
			}
		}
	}

	else if(GRAPHTYPE_POLARPOLAR == nGraphType)
	{
		rnExtra = PESC_POLAR;
		switch(nSel)
		{
		case POLARSERIESTYPEPOLAR_LINE:
			{
				return PEGPM_LINE;
			}

		case POLARSERIESTYPEPOLAR_POINTS:
			{
				return PEGPM_POINT;
			}

		case POLARSERIESTYPEPOLAR_POINTSPLUSLINE:
			{
				return PEGPM_POINTSPLUSLINE;
			}
			
		default:
			{
				CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
				return PEGPM_POINTSPLUSLINE;
			}
		}
	}

	else if(GRAPHTYPE_POLARSMITH == nGraphType)
	{
		rnExtra = PESC_SMITH;
		switch(nSel)
		{
		case POLARSERIESTYPESMITH_LINE:
			{
				return PEGPM_LINE;
			}

		case POLARSERIESTYPESMITH_POINTS:
			{
				return PEGPM_POINT;
			}

		case POLARSERIESTYPESMITH_POINTSPLUSLINE:
			{
				return PEGPM_POINTSPLUSLINE;
			}

		default:
			{
				CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
				return PEGPM_POINTSPLUSLINE;
			}
		}
	}

	else if(GRAPHTYPE_POLARROSE == nGraphType)
	{
		rnExtra = PESC_ROSE;
		switch(nSel)
		{
		case POLARSERIESTYPEROSE_LINE:
			{
				return PEGPM_LINE;
			}

		case POLARSERIESTYPEROSE_POINTS:
			{
				return PEGPM_POINT;
			}

		case POLARSERIESTYPEROSE_POINTSPLUSLINE:
			{
				return PEGPM_POINTSPLUSLINE;
			}
			
		default:
			{
				CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
				return PEGPM_POINTSPLUSLINE;
			}
		}
	}

	else if(GRAPHTYPE_PIE == nGraphType)
	{
		switch(nSel)
		{
		case PIESERIESTYPE_VALUE:
			{
				rnExtra = PEDLT_VALUE;
				return PEGPM_LINE;
			}

		case PIESERIESTYPE_PERCENTAGE:
			{
				rnExtra = PEDLT_PERCENTAGE;
				return PEGPM_LINE;
			}

		default:
			{
				CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
				return PEGPM_LINE;
			}
		}
	}
	else
	{
		CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateSeriesType");
		return PEGPM_LINE;
	}
}


int CPEChartDlg::TranslatePointType(int nSel)
{
	switch(nSel)
	{
	case POINTTYPE_PLUS:
		{
			return PEPT_PLUS;
		}

	case POINTTYPE_CROSS:
		{
			return PEPT_CROSS;
		}

	case POINTTYPE_CIRCLE:
		{
			return PEPT_DOT;
		}

	case POINTTYPE_FILLEDCIRCLE:
		{
			return PEPT_DOTSOLID;
		}

	case POINTTYPE_SQUARE:
		{
			return PEPT_SQUARE;
		}

	case POINTTYPE_FILLEDSQUARE:
		{
			return PEPT_SQUARESOLID;
		}

	case POINTTYPE_DIAMOND:
		{
			return PEPT_DIAMOND;
		}

	case POINTTYPE_FILLEDDIAMOND:
		{
			return PEPT_DIAMONDSOLID;
		}

	case POINTTYPE_UPWARDTRI:
		{
			return PEPT_UPTRIANGLE;
		}

	case POINTTYPE_FILLEDUPWARDTRI:
		{
			return PEPT_UPTRIANGLESOLID;
		}

	case POINTTYPE_DOWNWARDTRI:
		{
			return PEPT_DOWNTRIANGLE;
		}

	case POINTTYPE_FILLEDDOWNWARDTRI:
		{
			return PEPT_DOWNTRIANGLESOLID;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPEChartDlg::TranslatePointType");
			return PEPT_SQUARE;
		}
	}
}


int CPEChartDlg::TranslateLineType(int nSel)
{
	switch(nSel)
	{
	case LINETYPE_THIN:
		{
			return PELT_THINSOLID;
		}

	case LINETYPE_MEDIUMTHIN:
		{
			return PELT_MEDIUMTHINSOLID;
		}

	case LINETYPE_MEDIUM:
		{
			return PELT_MEDIUMSOLID;
		}

	case LINETYPE_MEDIUMTHICK:
		{
			return PELT_MEDIUMTHICKSOLID;
		}

	case LINETYPE_THICK:
		{
			return PELT_THICKSOLID;
		}

	case LINETYPE_EXTRATHICK:
		{
			return PELT_EXTRATHICKSOLID;
		}

	case LINETYPE_DASH:
		{
			return PELT_DASH;
		}

	case LINETYPE_DOT:
		{
			return PELT_DOT;
		}

	case LINETYPE_DASHDOT:
		{
			return PELT_DASHDOT;
		}

	case LINETYPE_DASHDOTDOT:
		{
			return PELT_DASHDOTDOT;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateLineType");
			return PELT_MEDIUMSOLID;
		}
	}
}


int CPEChartDlg::TranslateLegendLocation(int nSel)
{
	switch(nSel)
	{
	case LEGENDLOC_TOP:
		{
			return PELL_TOP;
		}

	case LEGENDLOC_RIGHT:
		{
			return PELL_RIGHT;
		}

	case LEGENDLOC_BOTTOM:
		{
			return PELL_BOTTOM;
		}

	case LEGENDLOC_LEFT:
		{
			return PELL_LEFT;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPEChartDlg::TranslateLegendLocation");
			return PELL_TOP;
		}
	}
}


int CPEChartDlg::TranslatePointSelection(int nSel)
{
	switch(nSel)
	{
	case POINTSELECTION_NONE:
		{
			return PECM_NOCURSOR;
		}

	case POINTSELECTION_SQUARE:
		{
			return PECM_DATASQUARE;
		}

	case POINTSELECTION_CROSSHAIR:
		{
			return PECM_DATACROSS;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::PointTypeSelectionToString");
			return PECM_DATACROSS;
		}
	}
}


int CPEChartDlg::TranslateRotationIncrement(int nSel)
{
	switch(nSel)
	{
	case ROTATION_15DEGREES:
		{
			return PERI_INCBY15;
		}

	case ROTATION_10DEGREES:
		{
			return PERI_INCBY10;
		}

	case ROTATION_5DEGREES:
		{
			return PERI_INCBY5;
		}

	case ROTATION_2DEGREES:
		{
			return PERI_INCBY2;
		}

	case ROTATION_1DEGREES:
		{
			return PERI_INCBY1;
		}

	case ROTATION_N1DEGREES:
		{
			return PERI_DECBY1;
		}

	case ROTATION_N2DEGREES:
		{
			return PERI_DECBY2;
		}

	case ROTATION_N5DEGREES:
		{
			return PERI_DECBY5;
		}

	case ROTATION_N10DEGREES:
		{
			return PERI_DECBY10;
		}

	case ROTATION_N15DEGREES:
		{
			return PERI_DECBY15;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CUtil::TranslateToRotationIncrement");
			return PERI_INCBY1;
		}
	}
}


COleDateTime CPEChartDlg::GetGraphTime(void) const
{
    return m_tmDate;
}


void CPEChartDlg::SetGraphTime(COleDateTime tm)
{
    m_tmDate = tm;
}


CUser* CPEChartDlg::GetUser(void) const
{
    return m_pUser;
}


void CPEChartDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}