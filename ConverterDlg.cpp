#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "ConverterDlg.h"


BEGIN_MESSAGE_MAP(CConverterDlg, CAniDialog)
    ON_EN_CHANGE(IDC_DIST1, OnUpdateDist)
    ON_CBN_SELCHANGE(IDC_UNITS1, OnUpdateDist)
    ON_CBN_SELCHANGE(IDC_UNITS2, OnUpdateDist)
	ON_BN_CLICKED(IDC_COPYRESULT, OnCopyResult)
	ON_CBN_SELCHANGE(IDC_NUMDECIMALS, OnUpdateDecimals)
END_MESSAGE_MAP()


CConverterDlg::CConverterDlg(CWnd* pParent /*=NULL*/) : CAniDialog(CConverterDlg::IDD, pParent)
{
}


void CConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX);
}


BOOL CConverterDlg::OnInitDialog(void)
{
	CAniDialog::OnInitDialog();

	m_edtDist.SubclassDlgItem(IDC_DIST1, this);

	CheckDlgButton(IDC_CLOSEONCOPY, BST_CHECKED);

    CComboBox* pBox1 = (CComboBox*)GetDlgItem(IDC_UNITS1);
    CComboBox* pBox2 = (CComboBox*)GetDlgItem(IDC_UNITS2);
    if((NULL != pBox1) && (NULL != pBox2))
    {
        for(int i = 0; i < NUM_DISTUNITS; i++)
        {
            CString str = CUtil::UnitsToString(i);
            pBox1->AddString(str);
            pBox2->AddString(str);
        }
        CDlgHelper::ReadyComboBox(pBox1, true);
        CDlgHelper::ReadyComboBox(pBox2, true);
        pBox1->SetCurSel(DISTUNITS_KM);
        pBox2->SetCurSel(DISTUNITS_MI);
    }

	CComboBox* pDecimalsBox = (CComboBox*)GetDlgItem(IDC_NUMDECIMALS);
	if(NULL != pDecimalsBox)
	{
		for(int i = 0; i < 5; i++)
		{
			CString str;
			str.Format("%d", i);

			pDecimalsBox->AddString(str);
		}

		CDlgHelper::ReadyComboBox(pDecimalsBox, true);
		pDecimalsBox->SetCurSel(3);
	}
	
	return TRUE; 
}


void CConverterDlg::OnUpdateDist(void)
{
    CString strRes = "";
	bool fOK = m_edtDist.IsInputValid();
	double dDist1 = m_edtDist.GetValue();
    if(fOK)
    {        
        CComboBox* pBox1 = (CComboBox*)GetDlgItem(IDC_UNITS1);
        CComboBox* pBox2 = (CComboBox*)GetDlgItem(IDC_UNITS2);
        if((NULL != pBox1) && (NULL != pBox2))
        {           
            double dConv = 0.0;
            if(CUtil::GetDistConversionFactor(pBox1->GetCurSel(), pBox2->GetCurSel(), dConv))
            {
                double dNewDist = dDist1 * dConv;
                strRes.Format("%lf", dNewDist);
            }
        }
    }

    SetDlgItemText(IDC_DIST2, strRes);
}


void CConverterDlg::OnUpdateDecimals(void)
{
	CComboBox* pDecimalsBox = (CComboBox*)GetDlgItem(IDC_NUMDECIMALS);
	if(NULL != pDecimalsBox)
	{
		int nSel = pDecimalsBox->GetCurSel();
		if(1 == nSel)
		{
			SetDlgItemText(IDT_DECIMALS, "decimal place");
		}
		else
		{
			SetDlgItemText(IDT_DECIMALS, "decimal places");
		}
	}
}


void CConverterDlg::OnCopyResult(void)
{	
	CComboBox* pDecimalsBox = (CComboBox*)GetDlgItem(IDC_NUMDECIMALS);
	CEdit* pResultBox = (CEdit*)GetDlgItem(IDC_DIST2);
	
	if((NULL != pResultBox) && (NULL != pDecimalsBox))
	{
		int nSel = pDecimalsBox->GetCurSel();
		if(-1 == nSel)
		{
			return;
		}
		
		CString strCur;
		pResultBox->GetWindowText(strCur);
		double dCur = atof(strCur);

		CString strCut;
		if(0 == nSel)
		{
			strCut.Format("%d", (int)dCur);
		}
		else if(1 == nSel)
		{
			strCut.Format("%.1lf", dCur);
		}
		else if(2 == nSel)
		{
			strCut.Format("%.2lf", dCur);
		}
		else if(3 == nSel)
		{
			strCut.Format("%.3lf", dCur);
		}
		else if(4 == nSel)
		{
			strCut.Format("%.4lf", dCur);
		}

		pResultBox->SetWindowText(strCut);
		pResultBox->SetSel(0, -1);
		pResultBox->Copy();

		pResultBox->SetWindowText(strCur);
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_CLOSEONCOPY))
	{
		EndDialog(IDOK);
	}
}
