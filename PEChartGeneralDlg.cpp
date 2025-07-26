#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "PEChartDlg.h"
#include "PEChartGeneralDlg.h"


BEGIN_MESSAGE_MAP(CPEChartGeneralDlg, CDialog)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()

	ON_BN_CLICKED(IDC_ROTATE, OnRotateClicked)

	ON_NOTIFY(DTN_DROPDOWN, IDC_DATEFROM, OnFromDropDown)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATETO, OnToDropDown)

	ON_CBN_SELCHANGE(IDC_GRAPHTYPE, OnGraphTypeChanged)

    ON_EN_CHANGE(IDC_STARTYEAR, OnUpdateGraphButton)
    ON_EN_CHANGE(IDC_ENDYEAR, OnUpdateGraphButton)
    ON_EN_CHANGE(IDC_INCREMENT, OnUpdateGraphButton)
END_MESSAGE_MAP()


CPEChartGeneralDlg::CPEChartGeneralDlg(CWnd* pParent) : CDialog(CPEChartGeneralDlg::IDD, pParent)
{
}


CPEChartGeneralDlg::~CPEChartGeneralDlg(void)
{
}


BOOL CPEChartGeneralDlg::OnInitDialog(void)
{
    BOOL bRet = CDialog::OnInitDialog();

	m_edtIncrement.SubclassDlgItem(IDC_INCREMENT, this);

    COleDateTime tmFrom = GetGraphTime();

	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		pFrom->SetTime(tmFrom);
	}
    
	COleDateTime tmTo = CUtil::OffsetDay(tmFrom, 7);
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		pTo->SetTime(tmTo);
	}

    SetDlgItemInt(IDC_INCREMENT, 1);

    CComboBox* pGraphTypeBox = (CComboBox*)GetDlgItem(IDC_GRAPHTYPE);
    if(NULL != pGraphTypeBox)
    {
		for(int i = FIRST_GRAPHTYPE; i <= LAST_GRAPHTYPE; i++)
		{
			pGraphTypeBox->AddString(CUtil::GraphTypeToString(i));
		}
        
        pGraphTypeBox->SetCurSel(0);
        CDlgHelper::ReadyComboBox(pGraphTypeBox, false);
    }

	CComboBox* pRotBox = (CComboBox*)GetDlgItem(IDC_ROTATIONINCREMENT);
	if(NULL != pRotBox)
	{
		for(int i = FIRST_ROTATIONINCREMENT; i <= LAST_ROTATIONINCREMENT; i++)
		{
			pRotBox->AddString(CUtil::RotationIncrementToString(i));
		}

		pRotBox->SetCurSel(ROTATION_1DEGREES);
		CDlgHelper::ReadyComboBox(pRotBox, false);
	}

	CComboBox* pPointSelBox = (CComboBox*)GetDlgItem(IDC_POINTSELECTION);
	if(NULL != pPointSelBox)
	{
		for(int i = FIRST_POINTSELECTION; i <= LAST_POINTSELECTION; i++)
		{
			pPointSelBox->AddString(CUtil::PointSelectionTypeToString(i));
		}

		pPointSelBox->SetCurSel(POINTSELECTION_NONE);
		CDlgHelper::ReadyComboBox(pPointSelBox, false);
	}

	CComboBox* pLegendBox = (CComboBox*)GetDlgItem(IDC_LEGENDLOCATION);
	if(NULL != pLegendBox)
	{
		for(int i = FIRST_LEGENDLOC; i <= LAST_LEGENDLOC; i++)
		{
			pLegendBox->AddString(CUtil::LegendLocationToString(i));
		}

		pLegendBox->SetCurSel(LEGENDLOC_TOP);
		CDlgHelper::ReadyComboBox(pLegendBox, false);
	}

	CheckDlgButton(IDC_XGRIDLINES, BST_CHECKED);
	CheckDlgButton(IDC_YGRIDLINES, BST_CHECKED);
	CheckDlgButton(IDC_ZGRIDLINES, BST_CHECKED);
	SetNPTextColor(RGB(0, 0, 0));
	SetNPBgColor(RGB(232, 238, 232), true);
	SetNPBgColor(RGB(150, 219, 142), false);
	SetPTextColor(RGB(0, 0, 90));
	SetPBgColor(RGB(179, 180, 204), true);
	SetPBgColor(RGB(214, 216, 228), false);

    InvalidateRect(NULL);

	OnGraphTypeChanged();
    OnUpdateGraphButton();

    return bRet;
}


void CPEChartGeneralDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    COLORREF crPicked = RGB(0, 0, 0);
    bool fRedraw = false;
	bool fContinue = true;
    
	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_NPTEXTCOLOR);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetNPTextColor()))
				{
					SetNPTextColor(crPicked);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_NPBGCOLOR1);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetNPBgColor(true)))
				{
					SetNPBgColor(crPicked, true);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_NPBGCOLOR2);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetNPBgColor(false)))
				{
					SetNPBgColor(crPicked, false);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_PTEXTCOLOR);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetPTextColor()))
				{
					SetPTextColor(crPicked);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_PBGCOLOR1);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetPBgColor(true)))
				{
					SetPBgColor(crPicked, true);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

	if(true == fContinue)
	{
		CWnd* pWnd = GetDlgItem(IDC_PBGCOLOR2);
		if(NULL != pWnd)
		{
			CRect rc;
			pWnd->GetWindowRect(&rc);
			ScreenToClient(&rc);
			if(rc.PtInRect(point))
			{
				if(ChooseNewColor(crPicked, GetPBgColor(false)))
				{
					SetPBgColor(crPicked, false);
					fRedraw = true;
					fContinue = false;
				}
			}
		}
	}

    if(fRedraw)
    {
        InvalidateRect(NULL);
    }
}


void CPEChartGeneralDlg::OnPaint(void)
{
    CPaintDC dc(this);

    COLORREF crShadow1 = CUtil::GetDefaultShadowColor(true);
    COLORREF crShadow2 = CUtil::GetDefaultShadowColor(false);

    CWnd* pWnd = GetDlgItem(IDC_NPTEXTCOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetNPTextColor());
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_NPBGCOLOR1);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetNPBgColor(true));
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_NPBGCOLOR2);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetNPBgColor(false));
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_PTEXTCOLOR);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetPTextColor());
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_PBGCOLOR1);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetPBgColor(true));
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }

    pWnd = GetDlgItem(IDC_PBGCOLOR2);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        dc.FillSolidRect(&rc, GetPBgColor(false));
        dc.Draw3dRect(&rc, crShadow1, crShadow2);
    }
}


void CPEChartGeneralDlg::OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		CMonthCalCtrl* pFromMonthCtrl = pFrom->GetMonthCalCtrl();
		if(NULL != pFromMonthCtrl)
		{
			pFromMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);
			
			CPEChartDlg* pParent = GetParentDlg();
			if(NULL != pParent)
			{
				CUser* pUser = pParent->GetUser();
				if(NULL != pUser)
				{
					int nStartDay = pUser->GetFirstDayOfWeek();
					if(SUNDAY == nStartDay)
					{
						nStartDay = 8;
					}
					nStartDay -= 2;

					pFromMonthCtrl->SetFirstDayOfWeek(nStartDay);
				}
			}
		}

		pFrom->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pFrom->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pFrom->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pFrom->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CPEChartGeneralDlg::OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		CMonthCalCtrl* pToMonthCtrl = pTo->GetMonthCalCtrl();
		if(NULL != pToMonthCtrl)
		{
			pToMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);

			CPEChartDlg* pParent = GetParentDlg();
			if(NULL != pParent)
			{
				CUser* pUser = pParent->GetUser();
				if(NULL != pUser)
				{
					int nStartDay = pUser->GetFirstDayOfWeek();
					if(SUNDAY == nStartDay)
					{
						nStartDay = 8;
					}
					nStartDay -= 2;

					pToMonthCtrl->SetFirstDayOfWeek(nStartDay);
				}
			}
		}

		pTo->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pTo->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pTo->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pTo->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CPEChartGeneralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


bool CPEChartGeneralDlg::ChooseNewColor(COLORREF& rcrPicked, COLORREF crStart)
{
    CColorDialog dlgColor(crStart, CC_FULLOPEN);

    if(IDOK == dlgColor.DoModal())
    {
        rcrPicked = dlgColor.GetColor();
        return true;
    }

    return false;
}


void CPEChartGeneralDlg::OnUpdateGraphButton(void)
{
    CPEChartDlg* pParent = GetParentDlg();
    if(NULL != pParent)
    {
		pParent->OnUpdateGraphButton();
    }
}


bool CPEChartGeneralDlg::DoEnableGraphButton(void) const
{
    CString strText;
    bool fEnable = true;
    
	CString str;
	GetDlgItemText(IDC_INCREMENT, str);
	if(true == str.IsEmpty())
	{
		fEnable = false;
	}

	return fEnable;
}


void CPEChartGeneralDlg::OnGraphTypeChanged(void)
{
    CPEChartDlg* pParent = GetParentDlg();
    if(NULL != pParent)
    {
		pParent->OnGraphTypeChanged();
    }
}


void CPEChartGeneralDlg::HandleGraphTypeChanged(int nGraphType)
{
	CWnd* pWndXGrid = GetDlgItem(IDC_XGRIDLINES);
	CWnd* pWndXLog = GetDlgItem(IDC_XLOGAXIS);
	CWnd* pWndYGrid = GetDlgItem(IDC_YGRIDLINES);
	CWnd* pWndYLog = GetDlgItem(IDC_YLOGAXIS);
	CWnd* pWndZGrid = GetDlgItem(IDC_ZGRIDLINES);
	CWnd* pWndZLog = GetDlgItem(IDC_ZLOGAXIS);
	CWnd* pWndLabel = GetDlgItem(IDC_LABELPOINTS);
	CWnd* pWndRotate = GetDlgItem(IDC_ROTATE);
	CWnd* pWndIncrement = GetDlgItem(IDC_ROTATIONINCREMENT);

	if((NULL == pWndXGrid) || (NULL == pWndXLog) || (NULL == pWndYGrid) || (NULL == pWndYLog) ||
       (NULL == pWndZGrid) || (NULL == pWndZLog) || (NULL == pWndRotate) || (NULL == pWndIncrement) ||
	   (NULL == pWndLabel))
	{
		return;
	}

	switch(nGraphType)
	{
	case GRAPHTYPE_PIE:
		{
			pWndXGrid->EnableWindow(FALSE);
			pWndXLog->EnableWindow(FALSE);
			pWndYGrid->EnableWindow(FALSE);
			pWndYLog->EnableWindow(FALSE);
			pWndZGrid->EnableWindow(FALSE);
			pWndZLog->EnableWindow(FALSE);
			pWndLabel->EnableWindow(FALSE);
			pWndRotate->EnableWindow(FALSE);
			pWndIncrement->EnableWindow(FALSE);
			break;
		}

	case GRAPHTYPE_POLARPOLAR:
	case GRAPHTYPE_POLARSMITH:
	case GRAPHTYPE_POLARROSE:
		{
			pWndXGrid->EnableWindow(TRUE);
			pWndXLog->EnableWindow(FALSE);
			pWndYGrid->EnableWindow(TRUE);
			pWndYLog->EnableWindow(FALSE);
			pWndZGrid->EnableWindow(FALSE);
			pWndZLog->EnableWindow(FALSE);
			pWndLabel->EnableWindow(TRUE);
			pWndRotate->EnableWindow(FALSE);
			pWndIncrement->EnableWindow(FALSE);
			break;
		}
	
	case GRAPHTYPE_2D2D:
		{
			pWndXGrid->EnableWindow(TRUE);
			pWndXLog->EnableWindow(TRUE);
			pWndYGrid->EnableWindow(TRUE);
			pWndYLog->EnableWindow(TRUE);
			pWndZGrid->EnableWindow(FALSE);
			pWndZLog->EnableWindow(FALSE);
			pWndLabel->EnableWindow(TRUE);
			pWndRotate->EnableWindow(FALSE);
			pWndIncrement->EnableWindow(FALSE);
			break;
		}

	case GRAPHTYPE_3DBAR:
	case GRAPHTYPE_3DSCATTER:
		{
			pWndXGrid->EnableWindow(TRUE);
			pWndXLog->EnableWindow(TRUE);
			pWndYGrid->EnableWindow(TRUE);
			pWndYLog->EnableWindow(TRUE);
			pWndZGrid->EnableWindow(TRUE);
			pWndZLog->EnableWindow(TRUE);
			pWndLabel->EnableWindow(TRUE);
			pWndRotate->EnableWindow(TRUE);
			pWndIncrement->EnableWindow(BST_CHECKED == IsDlgButtonChecked(IDC_ROTATE));
			break;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CPEChartGeneralDlg::HandleGraphTypeChanged");
			break;
		}
	}
}


void CPEChartGeneralDlg::OnRotateClicked(void)
{
	bool bEnable = (BST_CHECKED == IsDlgButtonChecked(IDC_ROTATE));
	CWnd* pWndIncrement = GetDlgItem(IDC_ROTATIONINCREMENT);

	if(NULL != pWndIncrement)
	{
		pWndIncrement->EnableWindow(bEnable);
	}
}


COleDateTime CPEChartGeneralDlg::GetGraphTime(void) const
{
    return m_tmDate;
}


void CPEChartGeneralDlg::SetGraphTime(COleDateTime tm)
{
    m_tmDate = tm;
}


void CPEChartGeneralDlg::SetParentDlg(CPEChartDlg* pDlg)
{
    m_pParentDlg = pDlg;
}


void CPEChartGeneralDlg::SetNPTextColor(COLORREF cr)
{
	m_crNPTextColor = cr;
}


void CPEChartGeneralDlg::SetNPBgColor(COLORREF cr, bool bStart)
{
	if(true == bStart)
	{
		m_crNPBgColor[0] = cr;
	}
	else
	{
		m_crNPBgColor[1] = cr;
	}
}


void CPEChartGeneralDlg::SetPTextColor(COLORREF cr)
{
	m_crPTextColor = cr;
}


void CPEChartGeneralDlg::SetPBgColor(COLORREF cr, bool bStart)
{
	if(true == bStart)
	{
		m_crPBgColor[0] = cr;
	}
	else
	{
		m_crPBgColor[1] = cr;
	}
}


CPEChartDlg* CPEChartGeneralDlg::GetParentDlg(void) const
{
    return m_pParentDlg;
}


COleDateTime CPEChartGeneralDlg::GetStartTime(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		pFrom->GetTime(tm);
	}

	return tm;
}


COleDateTime CPEChartGeneralDlg::GetEndTime(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

    CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		pTo->GetTime(tm);
	}

	return tm;
}


int CPEChartGeneralDlg::GetIncrement(void) const
{
    int nIncrement = m_edtIncrement.GetValue();
    if(0 == nIncrement)
    {
        AfxMessageBox("Invalid number of days to average over -- using 1");
        return 1;
    }

    return nIncrement;
}


int CPEChartGeneralDlg::GetGraphType(void) const
{
    int nGraphType = 0;
    CComboBox* pGraphType = (CComboBox*)GetDlgItem(IDC_GRAPHTYPE);
    if(NULL != pGraphType) 
    {
        nGraphType = pGraphType->GetCurSel();
    }

    return nGraphType;
}


bool CPEChartGeneralDlg::ShowXGridLines(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_XGRIDLINES));
}


bool CPEChartGeneralDlg::ShowYGridLines(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_YGRIDLINES));
}


bool CPEChartGeneralDlg::ShowZGridLines(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_ZGRIDLINES));
}


bool CPEChartGeneralDlg::IsXAxisLog(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_XLOGAXIS));
}


bool CPEChartGeneralDlg::IsYAxisLog(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_YLOGAXIS));
}


bool CPEChartGeneralDlg::IsZAxisLog(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_ZLOGAXIS));
}


int CPEChartGeneralDlg::GetPointSelection(void) const
{
    int nPointSelection = 0;
    CComboBox* pPointSelBox = (CComboBox*)GetDlgItem(IDC_POINTSELECTION);
    if(NULL != pPointSelBox) 
    {
        nPointSelection = pPointSelBox->GetCurSel();
    }

    return nPointSelection;
}


int CPEChartGeneralDlg::GetLegendLocation(void) const
{
    int nLegendLocation = 0;
    CComboBox* pLegendLocationBox = (CComboBox*)GetDlgItem(IDC_LEGENDLOCATION);
    if(NULL != pLegendLocationBox) 
    {
        nLegendLocation = pLegendLocationBox->GetCurSel();
    }

    return nLegendLocation;
}


bool CPEChartGeneralDlg::LabelPoints(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_LABELPOINTS));
}


COLORREF CPEChartGeneralDlg::GetNPTextColor(void) const
{
	return m_crNPTextColor;
}


COLORREF CPEChartGeneralDlg::GetNPBgColor(bool bStart) const
{
	if(true == bStart)
	{
		return m_crNPBgColor[0];
	}
	else
	{
		return m_crNPBgColor[1];
	}
}


COLORREF CPEChartGeneralDlg::GetPTextColor(void) const
{
	return m_crPTextColor;
}


COLORREF CPEChartGeneralDlg::GetPBgColor(bool bStart) const
{
	if(true == bStart)
	{
		return m_crPBgColor[0];
	}
	else
	{
		return m_crPBgColor[1];
	}
}


bool CPEChartGeneralDlg::DoRotate(void) const
{
	return (BST_CHECKED == IsDlgButtonChecked(IDC_ROTATE));
}


int CPEChartGeneralDlg::GetRotationIncrement(void) const
{
	int nIncrement = 1;
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_ROTATIONINCREMENT);
	if(NULL != pBox)
	{
		nIncrement = pBox->GetCurSel();
	}

	return nIncrement;
}
