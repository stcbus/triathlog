#include "StdAfx.h"
#include <ctype.h>
#include "RunningLog.h"
#include "DlgHelper.h"
#include "AniDialog.h"
#include "BtnST.h"
#include "FormulaDlg.h"
#include "Util.h"
#include "PEChartDlg.h"
#include "PEChartSeriesDlg.h"


BEGIN_MESSAGE_MAP(CPEChartSeriesDlg, CDialog)
    ON_WM_LBUTTONDBLCLK()
    ON_WM_PAINT()

	ON_BN_CLICKED(IDC_COUNTSERIES, OnUseSeriesChanged)
    ON_CBN_SELCHANGE(IDC_XAXIS, OnXAxisChanged)
    ON_CBN_SELCHANGE(IDC_YAXIS, OnYAxisChanged)
	ON_CBN_SELCHANGE(IDC_ZAXIS, OnZAxisChanged)
END_MESSAGE_MAP()


CPEChartSeriesDlg::CPEChartSeriesDlg(int nNum, bool bCheck, CWnd* pParent) : CDialog(CPEChartSeriesDlg::IDD, pParent)
{
    SetLineColor(CUtil::GetRandomColor2());
	SetPointColor(GetLineColor());
    m_nLastXSel = 0;
    m_nLastYSel = 0;
	m_nLastZSel = 0;

	m_bStartChecked = bCheck;
	m_strNum.Format("Plot data from series %d", nNum);
}


CPEChartSeriesDlg::~CPEChartSeriesDlg(void)
{
}


BOOL CPEChartSeriesDlg::OnInitDialog(void)
{
    BOOL bRet = CDialog::OnInitDialog();

	m_edtSeriesTitle.SubclassDlgItem(IDC_SERIESNAME, this);
	m_edtXTitle.SubclassDlgItem(IDC_XAXISTITLE, this);
	m_edtYTitle.SubclassDlgItem(IDC_YAXISTITLE, this);
	m_edtZTitle.SubclassDlgItem(IDC_ZAXISTITLE, this);
	m_edtGraphTitle.SubclassDlgItem(IDC_GRAPHTITLE, this);
	m_edtGraphSubtitle.SubclassDlgItem(IDC_GRAPHSUBTITLE, this);

	SetDlgItemText(IDC_PLOTDATATEXT, m_strNum);

    CComboBox* pXBox = (CComboBox*)GetDlgItem(IDC_XAXIS);
    if(NULL != pXBox)
    {
        for(int i = FIRST_DATATYPE; i <= LAST_DATATYPE; i++)
        {
            pXBox->AddString(CUtil::DataTypeToString(i, true));
        }
        pXBox->SetCurSel(DATATYPE_TIME);
        m_nLastXSel = DATATYPE_TIME;
        CDlgHelper::ReadyComboBox(pXBox, false);
    }

    CComboBox* pYBox = (CComboBox*)GetDlgItem(IDC_YAXIS);
    if(NULL != pYBox)
    {
        for(int i = FIRST_DATATYPE; i <= LAST_DATATYPE; i++)
        {
            pYBox->AddString(CUtil::DataTypeToString(i, true));
        }
        pYBox->SetCurSel(DATATYPE_MINUTESRUN);
        m_nLastXSel = DATATYPE_MINUTESRUN;
        CDlgHelper::ReadyComboBox(pYBox, false);
    }

    CComboBox* pZBox = (CComboBox*)GetDlgItem(IDC_ZAXIS);
    if(NULL != pZBox)
    {
        for(int i = FIRST_DATATYPE; i <= LAST_DATATYPE; i++)
        {
            pZBox->AddString(CUtil::DataTypeToString(i, true));
        }
        pZBox->SetCurSel(DATATYPE_PACERUN);
        m_nLastXSel = DATATYPE_PACERUN;
        CDlgHelper::ReadyComboBox(pZBox, false);
    }

	CPEChartDlg* pParent = GetParentDlg();
	if(NULL != pParent)
	{
		HandleGraphTypeChanged(pParent->GetGraphType());
	}

	CComboBox* pPointBox = (CComboBox*)GetDlgItem(IDC_POINTTYPE);
	if(NULL != pPointBox)
	{
        for(int i = FIRST_POINTTYPE; i <= LAST_POINTTYPE; i++)
        {
            pPointBox->AddString(CUtil::PointTypeToString(i));
        }
        pPointBox->SetCurSel(POINTTYPE_FILLEDSQUARE);
        CDlgHelper::ReadyComboBox(pPointBox, false);
    }

	CComboBox* pLineBox = (CComboBox*)GetDlgItem(IDC_LINETYPE);
	if(NULL != pLineBox)
	{
        for(int i = FIRST_LINETYPE; i <= LAST_LINETYPE; i++)
        {
            pLineBox->AddString(CUtil::LineTypeToString(i));
        }
        pLineBox->SetCurSel(LINETYPE_MEDIUM);
        CDlgHelper::ReadyComboBox(pLineBox, false);
    }

	CheckDlgButton(IDC_COUNTSERIES, (TRUE == m_bStartChecked ? BST_CHECKED : BST_UNCHECKED));
	CheckDlgButton(IDC_KEEPSAME, BST_CHECKED);

    InvalidateRect(NULL);

    OnXAxisChanged();
    OnYAxisChanged();
	OnZAxisChanged();
	OnUseSeriesChanged();

    return bRet;
}


void CPEChartSeriesDlg::OnUseSeriesChanged(void)
{
	CWnd* pWndX = GetDlgItem(IDC_XAXIS);
	CWnd* pWndXTitle = GetDlgItem(IDC_XAXISTITLE);
	CWnd* pWndY = GetDlgItem(IDC_YAXIS);
	CWnd* pWndYTitle = GetDlgItem(IDC_YAXISTITLE);
	CWnd* pWndZ = GetDlgItem(IDC_ZAXIS);
	CWnd* pWndZTitle = GetDlgItem(IDC_ZAXISTITLE);
	CWnd* pWndTitle = GetDlgItem(IDC_GRAPHTITLE);
	CWnd* pWndSubtitle = GetDlgItem(IDC_GRAPHSUBTITLE);
	CWnd* pWndSeries = GetDlgItem(IDC_SERIESTYPE);
	CWnd* pWndSeriesName = GetDlgItem(IDC_SERIESNAME);
	CWnd* pWndColor = GetDlgItem(IDC_LINECOLOR);
	CWnd* pWndPoint = GetDlgItem(IDC_POINTTYPE);
	CWnd* pWndLine = GetDlgItem(IDC_LINETYPE);

	if((NULL != pWndX) && (NULL != pWndXTitle) && (NULL != pWndY) && (NULL != pWndYTitle) &&
	   (NULL != pWndZ) && (NULL != pWndZTitle) && (NULL != pWndTitle) && (NULL != pWndSubtitle) &&
	   (NULL != pWndSeries) && (NULL != pWndSeriesName) && (NULL != pWndColor) && (NULL != pWndPoint) &&
	   (NULL != pWndLine))
	{
		BOOL bEnabled = TRUE;

		pWndX->EnableWindow(bEnabled);
		pWndXTitle->EnableWindow(bEnabled);
		pWndY->EnableWindow(bEnabled);
		pWndYTitle->EnableWindow(bEnabled);
		pWndZ->EnableWindow(bEnabled);
		pWndZTitle->EnableWindow(bEnabled);
		pWndTitle->EnableWindow(bEnabled);
		pWndSubtitle->EnableWindow(bEnabled);
		pWndSeries->EnableWindow(bEnabled);
		pWndSeriesName->EnableWindow(bEnabled);
		pWndColor->EnableWindow(bEnabled);
		pWndPoint->EnableWindow(bEnabled);
		pWndLine->EnableWindow(bEnabled);

		if(TRUE == bEnabled)
		{
			CPEChartDlg* pParentDlg = GetParentDlg();
			if(NULL == pParentDlg)
			{
				return;
			}

			HandleGraphTypeChanged(pParentDlg->GetGraphType());
		}
	}
}


bool CPEChartSeriesDlg::DoEnableGraphButton(void) const
{
    return true;
}


void CPEChartSeriesDlg::HandleGraphTypeChanged(int nGraphType)
{
	CWnd* pWndXAxis = GetDlgItem(IDC_XAXIS);
	CWnd* pWndXTitle = GetDlgItem(IDC_XAXISTITLE);
	CWnd* pWndZAxis = GetDlgItem(IDC_ZAXIS);
	CWnd* pWndZTitle = GetDlgItem(IDC_ZAXISTITLE);
	CWnd* pWndPoint = GetDlgItem(IDC_POINTTYPE);
	CWnd* pWndLine = GetDlgItem(IDC_LINETYPE);
	CComboBox* pSeriesBox = (CComboBox*)GetDlgItem(IDC_SERIESTYPE);

	if((NULL == pWndXAxis) || (NULL == pWndXTitle) || (NULL == pWndZAxis) || (NULL == pWndZTitle) ||
       (NULL == pWndPoint) || (NULL == pWndLine) || (NULL == pSeriesBox))
	{
		return;
	}

	if(GRAPHTYPE_PIE == nGraphType)
	{
		pWndXAxis->EnableWindow(FALSE);
		pWndXTitle->EnableWindow(FALSE);
		pWndZAxis->EnableWindow(FALSE);
		pWndZTitle->EnableWindow(FALSE);
		pWndPoint->EnableWindow(FALSE);
		pWndLine->EnableWindow(FALSE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_PIESERIESTYPE; i <= LAST_PIESERIESTYPE; i++)
		{
			pSeriesBox->AddString(CUtil::PieSeriesTypeToString(i));
		}	

        pSeriesBox->SetCurSel(PIESERIESTYPE_PERCENTAGE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_POLARPOLAR == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(FALSE);
		pWndZTitle->EnableWindow(FALSE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_POLARSERIESTYPEPOLAR; i <= LAST_POLARSERIESTYPEPOLAR; i++)
		{
			pSeriesBox->AddString(CUtil::PolarSeriesTypePolarToString(i));
		}	

        pSeriesBox->SetCurSel(POLARSERIESTYPEPOLAR_LINE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_POLARSMITH == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(FALSE);
		pWndZTitle->EnableWindow(FALSE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_POLARSERIESTYPESMITH; i <= LAST_POLARSERIESTYPESMITH; i++)
		{
			pSeriesBox->AddString(CUtil::PolarSeriesTypeSmithToString(i));
		}	

        pSeriesBox->SetCurSel(POLARSERIESTYPESMITH_LINE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_POLARROSE == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(FALSE);
		pWndZTitle->EnableWindow(FALSE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_POLARSERIESTYPEROSE; i <= LAST_POLARSERIESTYPEROSE; i++)
		{
			pSeriesBox->AddString(CUtil::PolarSeriesTypeRoseToString(i));
		}	

        pSeriesBox->SetCurSel(POLARSERIESTYPEROSE_LINE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_2D2D == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(FALSE);
		pWndZTitle->EnableWindow(FALSE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_TWODSERIESTYPE2D; i <= LAST_TWODSERIESTYPE2D; i++)
		{
			pSeriesBox->AddString(CUtil::TwoDSeriesType2DToString(i));
		}	

        pSeriesBox->SetCurSel(TWODSERIESTYPE2D_SPLINE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_3DBAR == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(TRUE);
		pWndZTitle->EnableWindow(TRUE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_THREEDSERIESTYPEBAR; i <= LAST_THREEDSERIESTYPEBAR; i++)
		{
			pSeriesBox->AddString(CUtil::ThreeDSeriesTypeBarToString(i));
		}	

        pSeriesBox->SetCurSel(THREEDSERIESTYPEBAR_SURFACE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	else if(GRAPHTYPE_3DSCATTER == nGraphType)
	{
		pWndXAxis->EnableWindow(TRUE);
		pWndXTitle->EnableWindow(TRUE);
		pWndZAxis->EnableWindow(TRUE);
		pWndZTitle->EnableWindow(TRUE);
		pWndPoint->EnableWindow(TRUE);
		pWndLine->EnableWindow(TRUE);

		pSeriesBox->ResetContent();
		for(int i = FIRST_THREEDSERIESTYPESCATTER; i <= LAST_THREEDSERIESTYPESCATTER; i++)
		{
			pSeriesBox->AddString(CUtil::ThreeDSeriesTypeScatterToString(i));
		}	

        pSeriesBox->SetCurSel(THREEDSERIESTYPESCATTER_POINTSPLUSLINE);
        CDlgHelper::ReadyComboBox(pSeriesBox, false);
	}
	OnXAxisChanged();
}


void CPEChartSeriesDlg::OnXAxisChanged(void)
{
    bool bFormula = false;
    CString strFormula;

    CComboBox* pXCombo = (CComboBox*)GetDlgItem(IDC_XAXIS);
    int nSelX = 0;
    if(NULL != pXCombo)
    {
        nSelX = pXCombo->GetCurSel();
        if(DATATYPE_FORMULA == nSelX)
        {
            CFormulaDlg dlg;
            if(IDOK == dlg.DoModal())
            {
                m_strXFormula = dlg.GetFormula();
                bFormula = true;
            }
            else
            {
                pXCombo->SetCurSel(m_nLastXSel);
                nSelX = m_nLastXSel;
				return;
            }
        }
    }           

    CString strX;
    CString strXTitle;
    if(bFormula)
    {
        strX = TranslateToEnglish(m_strXFormula, false);
        strXTitle = TranslateToEnglish(m_strXFormula, true);
    }
    else
    {
        strX = CUtil::DataTypeToString(nSelX, false);
        strXTitle = CUtil::DataTypeToString(nSelX, true);
    }

    CComboBox* pYCombo = (CComboBox*)GetDlgItem(IDC_YAXIS);
    int nSelY = 0;
    if(NULL != pYCombo)
    {
        nSelY = pYCombo->GetCurSel();
    }

    CString strY;
    CString strYTitle;
    if(DATATYPE_FORMULA == nSelY)
    {
        strY = TranslateToEnglish(m_strYFormula, false);
        strYTitle = TranslateToEnglish(m_strYFormula, true);
    }
    else
    {
        strY = CUtil::DataTypeToString(nSelY, false);
        strYTitle = CUtil::DataTypeToString(nSelY, true);
    }
    
    CComboBox* pZCombo = (CComboBox*)GetDlgItem(IDC_ZAXIS);
    int nSelZ = 0;
    if(NULL != pZCombo)
    {
        nSelZ = pZCombo->GetCurSel();
    }

    CString strZ;
    CString strZTitle;
    if(DATATYPE_FORMULA == nSelZ)
    {
        strZ = TranslateToEnglish(m_strZFormula, false);
        strZTitle = TranslateToEnglish(m_strZFormula, true);
    }
    else
    {
        strZ = CUtil::DataTypeToString(nSelZ, false);
        strZTitle = CUtil::DataTypeToString(nSelZ, true);
    }

	CString strTitle;
	CString strSeries;

	CPEChartDlg* pParent = GetParentDlg();
	if(NULL != pParent)
	{
		int nGraphType = pParent->GetGraphType();
		if(GRAPHTYPE_PIE == nGraphType)
		{
			strTitle = strYTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_POLARPOLAR == nGraphType) || (GRAPHTYPE_POLARSMITH == nGraphType) ||
			    (GRAPHTYPE_POLARROSE == nGraphType) || (GRAPHTYPE_2D2D == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_3DBAR == nGraphType) || (GRAPHTYPE_3DSCATTER == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle + " and " + strZTitle;
			strSeries = strY;
		}
	}

    SetDlgItemText(IDC_XAXISTITLE, strX);
    SetDlgItemText(IDC_YAXISTITLE, strY);
	SetDlgItemText(IDC_ZAXISTITLE, strZ);
    SetDlgItemText(IDC_GRAPHTITLE, strTitle);
    SetDlgItemText(IDC_SERIESNAME, strSeries);

    m_nLastXSel = nSelX;
    m_nLastYSel = nSelY;
	m_nLastZSel = nSelZ;
}


void CPEChartSeriesDlg::OnYAxisChanged(void)
{
    bool bFormula = false;
    CString strFormula;

    CComboBox* pYCombo = (CComboBox*)GetDlgItem(IDC_YAXIS);
    int nSelY = 0;
    if(NULL != pYCombo)
    {
        nSelY = pYCombo->GetCurSel();
        if(DATATYPE_FORMULA == nSelY)
        {
            CFormulaDlg dlg;
            if(IDOK == dlg.DoModal())
            {
                m_strYFormula = dlg.GetFormula();
                bFormula = true;
            }
            else
            {
                pYCombo->SetCurSel(m_nLastYSel);
                nSelY = m_nLastYSel;
				return;
            }
        }
    }           

    CString strY;
    CString strYTitle;
    if(bFormula)
    {
        strY = TranslateToEnglish(m_strYFormula, false);
        strYTitle = TranslateToEnglish(m_strYFormula, true);
    }
    else
    {
        strY = CUtil::DataTypeToString(nSelY, false);
        strYTitle = CUtil::DataTypeToString(nSelY, true);
    }

    CComboBox* pXCombo = (CComboBox*)GetDlgItem(IDC_XAXIS);
    int nSelX = 0;
    if(NULL != pXCombo)
    {
        nSelX = pXCombo->GetCurSel();
    }

    CString strX;
    CString strXTitle;
    if(DATATYPE_FORMULA == nSelX)
    {
        strX = TranslateToEnglish(m_strXFormula, false);
        strXTitle = TranslateToEnglish(m_strXFormula, true);
    }
    else
    {
        strX = CUtil::DataTypeToString(nSelX, false);
        strXTitle = CUtil::DataTypeToString(nSelX, true);
    }
    
    CComboBox* pZCombo = (CComboBox*)GetDlgItem(IDC_ZAXIS);
    int nSelZ = 0;
    if(NULL != pZCombo)
    {
        nSelZ = pZCombo->GetCurSel();
    }

    CString strZ;
    CString strZTitle;
    if(DATATYPE_FORMULA == nSelZ)
    {
        strZ = TranslateToEnglish(m_strZFormula, false);
        strZTitle = TranslateToEnglish(m_strZFormula, true);
    }
    else
    {
        strZ = CUtil::DataTypeToString(nSelZ, false);
        strZTitle = CUtil::DataTypeToString(nSelZ, true);
    }

	CString strTitle;
	CString strSeries;

	CPEChartDlg* pParent = GetParentDlg();
	if(NULL != pParent)
	{
		int nGraphType = pParent->GetGraphType();
		if(GRAPHTYPE_PIE == nGraphType)
		{
			strTitle = strYTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_POLARPOLAR == nGraphType) || (GRAPHTYPE_POLARSMITH == nGraphType) ||
			    (GRAPHTYPE_POLARROSE == nGraphType) || (GRAPHTYPE_2D2D == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_3DBAR == nGraphType) || (GRAPHTYPE_3DSCATTER == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle + " and " + strZTitle;
			strSeries = strY;
		}
	}

    SetDlgItemText(IDC_XAXISTITLE, strX);
    SetDlgItemText(IDC_YAXISTITLE, strY);
	SetDlgItemText(IDC_ZAXISTITLE, strZ);
    SetDlgItemText(IDC_GRAPHTITLE, strTitle);
    SetDlgItemText(IDC_SERIESNAME, strSeries);

    m_nLastXSel = nSelX;
    m_nLastYSel = nSelY;
	m_nLastZSel = nSelZ;
}


void CPEChartSeriesDlg::OnZAxisChanged(void)
{
    bool bFormula = false;
    CString strFormula;

    CComboBox* pZCombo = (CComboBox*)GetDlgItem(IDC_ZAXIS);
    int nSelZ = 0;
    if(NULL != pZCombo)
    {
        nSelZ = pZCombo->GetCurSel();
        if(DATATYPE_FORMULA == nSelZ)
        {
            CFormulaDlg dlg;
            if(IDOK == dlg.DoModal())
            {
                m_strZFormula = dlg.GetFormula();
                bFormula = true;
            }
            else
            {
                pZCombo->SetCurSel(m_nLastZSel);
                nSelZ = m_nLastZSel;
				return;
            }
        }
    }           

    CString strZ;
    CString strZTitle;
    if(bFormula)
    {
        strZ = TranslateToEnglish(m_strZFormula, false);
        strZTitle = TranslateToEnglish(m_strZFormula, true);
    }
    else
    {
        strZ = CUtil::DataTypeToString(nSelZ, false);
        strZTitle = CUtil::DataTypeToString(nSelZ, true);
    }

    CComboBox* pXCombo = (CComboBox*)GetDlgItem(IDC_XAXIS);
    int nSelX = 0;
    if(NULL != pXCombo)
    {
        nSelX = pXCombo->GetCurSel();
    }

    CString strX;
    CString strXTitle;
    if(DATATYPE_FORMULA == nSelX)
    {
        strX = TranslateToEnglish(m_strXFormula, false);
        strXTitle = TranslateToEnglish(m_strXFormula, true);
    }
    else
    {
        strX = CUtil::DataTypeToString(nSelX, false);
        strXTitle = CUtil::DataTypeToString(nSelX, true);
    }

    CComboBox* pYCombo = (CComboBox*)GetDlgItem(IDC_YAXIS);
    int nSelY = 0;
    if(NULL != pYCombo)
    {
        nSelY = pYCombo->GetCurSel();
    }

    CString strY;
    CString strYTitle;
    if(DATATYPE_FORMULA == nSelY)
    {
        strY = TranslateToEnglish(m_strYFormula, false);
        strYTitle = TranslateToEnglish(m_strYFormula, true);
    }
    else
    {
        strY = CUtil::DataTypeToString(nSelY, false);
        strYTitle = CUtil::DataTypeToString(nSelY, true);
    }

	CString strTitle;
	CString strSeries = strY;

	CPEChartDlg* pParent = GetParentDlg();
	if(NULL != pParent)
	{
		int nGraphType = pParent->GetGraphType();
		if(GRAPHTYPE_PIE == nGraphType)
		{
			strTitle = strYTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_POLARPOLAR == nGraphType) || (GRAPHTYPE_POLARSMITH == nGraphType) ||
			    (GRAPHTYPE_POLARROSE == nGraphType) || (GRAPHTYPE_2D2D == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle;
			strSeries = strY;
		}
		else if((GRAPHTYPE_3DBAR == nGraphType) || (GRAPHTYPE_3DSCATTER == nGraphType))
		{
			strTitle = strYTitle + " vs. " + strXTitle + " and " + strZTitle;
			strSeries = strY;
		}
	}

    SetDlgItemText(IDC_XAXISTITLE, strX);
    SetDlgItemText(IDC_YAXISTITLE, strY);
	SetDlgItemText(IDC_ZAXISTITLE, strZ);
    SetDlgItemText(IDC_GRAPHTITLE, strTitle);
    SetDlgItemText(IDC_SERIESNAME, strSeries);

    m_nLastXSel = nSelX;
    m_nLastYSel = nSelY;
	m_nLastZSel = nSelZ;
}


void CPEChartSeriesDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    COLORREF crPicked = RGB(0, 0, 0);
    bool fRedraw = false;

	CPEChartDlg* pParent = GetParentDlg();
	if(NULL == pParent)
	{
		return;
	}

	if(GRAPHTYPE_PIE == pParent->GetGraphType())
	{
		return;
	}
    
    CWnd* pWnd = GetDlgItem(IDC_LINECOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);
        if(rc.PtInRect(point))
        {
            if(ChooseNewColor(crPicked, GetLineColor()))
            {
                SetLineColor(crPicked);

				if(BST_CHECKED == IsDlgButtonChecked(IDC_KEEPSAME))
				{
					SetPointColor(crPicked);
				}

                fRedraw = true;
            }
        }
    }

    pWnd = GetDlgItem(IDC_POINTCOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);
        if(rc.PtInRect(point))
        {
            if(ChooseNewColor(crPicked, GetPointColor()))
            {
                SetPointColor(crPicked);

				if(BST_CHECKED == IsDlgButtonChecked(IDC_KEEPSAME))
				{
					SetLineColor(crPicked);
				}

                fRedraw = true;
            }
        }
    }

    if(fRedraw)
    {
        InvalidateRect(NULL);
    }
}


void CPEChartSeriesDlg::OnPaint(void)
{
    CPaintDC dc(this);

    COLORREF crShadow1 = CUtil::GetDefaultShadowColor(true);
    COLORREF crShadow2 = CUtil::GetDefaultShadowColor(false);

    CWnd* pWnd = GetDlgItem(IDC_LINECOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetLineColor());
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_POINTCOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetPointColor());
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }
}


void CPEChartSeriesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


bool CPEChartSeriesDlg::ChooseNewColor(COLORREF& rcrPicked, COLORREF crStart)
{
    CColorDialog dlgColor(crStart, CC_FULLOPEN);

    if(IDOK == dlgColor.DoModal())
    {
        rcrPicked = dlgColor.GetColor();
        return true;
    }

    return false;
}


COLORREF CPEChartSeriesDlg::GetLineColor(void) const
{
    return m_crLine;
}


void CPEChartSeriesDlg::SetLineColor(COLORREF cr)
{
    m_crLine = cr;
}


COLORREF CPEChartSeriesDlg::GetPointColor(void) const
{
    return m_crPoint;
}


void CPEChartSeriesDlg::SetPointColor(COLORREF cr)
{
    m_crPoint = cr;
}


void CPEChartSeriesDlg::SetParentDlg(CPEChartDlg* pDlg)
{
    m_pParentDlg = pDlg;
}


CPEChartDlg* CPEChartSeriesDlg::GetParentDlg(void) const
{
    return m_pParentDlg;
}


int CPEChartSeriesDlg::GetXAxisType(void) const
{
    int nXType = 1;
    CComboBox* pXBox = (CComboBox*)GetDlgItem(IDC_XAXIS);
    if(NULL != pXBox)
    {
        nXType = pXBox->GetCurSel();
    }

    return nXType;
}

int CPEChartSeriesDlg::GetYAxisType(void) const
{
    int nYType = 1;
    CComboBox* pYBox = (CComboBox*)GetDlgItem(IDC_YAXIS);
    if(NULL != pYBox)
    {
        nYType = pYBox->GetCurSel();
    }

    return nYType;
}


int CPEChartSeriesDlg::GetZAxisType(void) const
{
    int nZType = 1;
    CComboBox* pZBox = (CComboBox*)GetDlgItem(IDC_ZAXIS);
    if(NULL != pZBox)
    {
        nZType = pZBox->GetCurSel();
    }

    return nZType;
}


CString CPEChartSeriesDlg::GetXAxisTitle(void) const
{
    return m_edtXTitle.GetValue();
}


CString CPEChartSeriesDlg::GetYAxisTitle(void) const
{
    return m_edtYTitle.GetValue();
}


CString CPEChartSeriesDlg::GetZAxisTitle(void) const
{
    return m_edtZTitle.GetValue();
}


CString CPEChartSeriesDlg::GetGraphTitle(void) const
{
    return m_edtGraphTitle.GetValue();
}


CString CPEChartSeriesDlg::GetGraphSubtitle(void) const
{
    return m_edtGraphSubtitle.GetValue();
}


CString CPEChartSeriesDlg::GetSeriesTitle(void) const
{
	return m_edtSeriesTitle.GetValue();
}


int CPEChartSeriesDlg::GetSeriesType(void) const
{
	int nType = 0;

	CComboBox* pSeriesBox = (CComboBox*)GetDlgItem(IDC_SERIESTYPE);
	if(NULL != pSeriesBox)
	{
		nType = pSeriesBox->GetCurSel();
	}

	return nType;
}


int CPEChartSeriesDlg::GetPointType(void) const
{
	int nType = 0;

	CComboBox* pPointBox = (CComboBox*)GetDlgItem(IDC_POINTTYPE);
	if(NULL != pPointBox)
	{
		nType = pPointBox->GetCurSel();
	}

	return nType;
}


int CPEChartSeriesDlg::GetLineType(void) const
{
	int nType = 0;

	CComboBox* pLineBox = (CComboBox*)GetDlgItem(IDC_LINETYPE);
	if(NULL != pLineBox)
	{
		nType = pLineBox->GetCurSel();
	}

	return nType;
}


bool CPEChartSeriesDlg::ShouldUseSeries(void) const
{
	return true;
}


CString CPEChartSeriesDlg::GetFormulaX(void) const
{
    return m_strXFormula;
}


CString CPEChartSeriesDlg::GetFormulaY(void) const
{
    return m_strYFormula;
}


CString CPEChartSeriesDlg::GetFormulaZ(void) const
{
    return m_strZFormula;
}


CString CPEChartSeriesDlg::TranslateToEnglish(CString str, bool fForTitle)
{
    CString strRes;
    int nLen = str.GetLength();
    for(int i = 0; i < nLen; i++)
    {
        char nCur = str.GetAt(i);
        char nBefore = ' ';
        char nAfter = ' ';
        if(i != 0)
        {
            nBefore = str.GetAt(i - 1);
        }
        if(i != nLen - 1)
        {
            nAfter = str.GetAt(i + 1);
        }
        
        if(isalpha(nCur) && !(isalpha(nBefore) || isalpha(nAfter)))
        {
            strRes += CharToFunction(nCur, fForTitle);
        }
        else
        {
            strRes += nCur;
        }
    }
    
    return strRes;
}


CString CPEChartSeriesDlg::CharToFunction(char ch, bool fForTitle)
{
    switch(ch)
    {
    case 'B':
        {
            if(fForTitle)
            {
                return "[Running Minutes]";
            }
            else
            {
                return "[Run Mins]";
            }
        }
        
    case 'F':
        {
            if(fForTitle)
            {
                return "[Cycling Minutes]";
            }
            else
            {
                return "[Cycle Mins]";
            }
        }
        
    case 'J':
        {
            if(fForTitle)
            {
                return "[Swimming Minutes]";
            }
            else
            {
                return "[Swim Mins]";
            }
        }

    case 'K':
        {
            if(fForTitle)
            {
                return "[Strength Work Minutes]";
            }
            else
            {
                return "[Str Mins]";
            }
        }

    case 'M':
        {
            if(fForTitle)
            {
                return "[Overall Minutes]";
            }
            else
            {
                return "[Overall Mins]";
            }
        }

    case 'N':
        {
            if(fForTitle)
            {
                return "[Running Distance]";
            }
            else
            {
                return "[Run Dist]";
            }
        }

    case 'P':
        {
            if(fForTitle)
            {
                return "[Cycling Distance]";
            }
            else
            {
                return "[Cycle Dist]";
            }
        }

    case 'Q':
        {
            if(fForTitle)
            {
                return "[Swimming Distance]";
            }
            else
            {
                return "[Swim Dist]";
            }
        }

    case 'X':
        {
            if(fForTitle)
            {
                return "[Running Pace]";
            }
            else
            {
                return "[Run Pace]";
            }
        }

    case 'Y':
        {
            if(fForTitle)
            {
                return "[Cycling Pace]";
            }
            else
            {
                return "[Cycle Pace]";
            }
        }

    case 'b':
        {
            if(fForTitle)
            {
                return "[Swimming Pace]";
            }
            else
            {
                return "[Swim Pace]";
            }
        }

    case 'f':
        {
            if(fForTitle)
            {
                return "[Running Workouts]";
            }
            else
            {
                return "[Run Workouts]";
            }
        }

    case 'j':
        {
            if(fForTitle)
            {
                return "[Cycling Workouts]";
            }
            else
            {
                return "[Cycle Workouts]";
            }
        }

    case 'k':
        {
            if(fForTitle)
            {
                return "[Swimming Workouts]";
            }
            else
            {
                return "[Swim Workouts]";
            }
        }

    case 'm':
        {
            if(fForTitle)
            {
                return "[Strength Workouts]";
            }
            else
            {
                return "[Str Workouts]";
            }
        }

    case 'n':
        {
            if(fForTitle)
            {
                return "[Overall Workouts]";
            }
            else
            {
                return "[Overall Workouts]";
            }
        }

    case 'p':
        {
            if(fForTitle)
            {
                return "[Sleep]";
            }
            else
            {
                return "[Sleep]";
            }
        }

    case 'q':
        {
            if(fForTitle)
            {
                return "[Weight]";
            }
            else
            {
                return "[Weight]";
            }
        }

    case 'x':
        {
            if(fForTitle)
            {
                return "[Temperature]";
            }
            else
            {
                return "[Temperature]";
            }
        }

    case 'y':
        {
            if(fForTitle)
            {
                return "[Heartrate]";
            }
            else
            {
                return "[Heartrate]";
            }
        }
        
    case 'z':
        {
            if(fForTitle)
            {
                return "[Points]";
            }
            else
            {
                return "[Points]";
            }
        }

	case 'C':
		{
			if(fForTitle)
			{
				return "[Calories]";
			}
			else
			{
				return "[Calories]";
			}
		}

    default:
        {
            CString str(ch);
            return str;
        }
    }
}