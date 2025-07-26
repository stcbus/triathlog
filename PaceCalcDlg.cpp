#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "PaceCalcDlg.h"

#include <math.h>


IMPLEMENT_DYNAMIC(CPaceCalcDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CPaceCalcDlg, CAniDialog)
    ON_EN_CHANGE(IDC_DIST1, OnUpdatePaces)
    ON_EN_CHANGE(IDC_DIST2, OnUpdatePaces)
    ON_EN_CHANGE(IDC_TIME1, OnUpdatePaces)
	ON_EN_CHANGE(IDC_EXPONENT, OnUpdatePaces)
    ON_CBN_SELCHANGE(IDC_PACETYPE1, OnUpdatePaces)
    ON_CBN_SELCHANGE(IDC_PACETYPE2, OnUpdatePaces)
    ON_CBN_SELCHANGE(IDC_UNITS1, OnUpdatePaces)
    ON_CBN_SELCHANGE(IDC_UNITS2, OnUpdatePaces)

    ON_BN_CLICKED(IDC_SEIGEL, OnUpdatePaces)
    ON_BN_CLICKED(IDC_CONSTANT, OnUpdatePaces)
END_MESSAGE_MAP()


CPaceCalcDlg::CPaceCalcDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CPaceCalcDlg::IDD, pParent)
{
}


CPaceCalcDlg::~CPaceCalcDlg()
{
}


BOOL CPaceCalcDlg::OnInitDialog(void)
{
    BOOL fRes = CAniDialog::OnInitDialog();

	m_edtDist1.SubclassDlgItem(IDC_DIST1, this);
	m_edtDist2.SubclassDlgItem(IDC_DIST2, this);
	m_edtTime1.SubclassDlgItem(IDC_TIME1, this);
	m_edtExp.SubclassDlgItem(IDC_EXPONENT, this);

	m_btnFormula.SubclassDlgItem(IDC_FORMULABTN, this);
	m_btnFormula.SetBitmaps(IDB_PACEFORMULA, RGB(255, 255, 255));
	m_btnFormula.SizeToContent();
	m_btnFormula.DrawFlatFocus(FALSE);
	m_btnFormula.DrawBorder(FALSE);

    CheckDlgButton(IDC_CONSTANT, BST_CHECKED);

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
        pBox1->SetCurSel(DISTUNITS_MI);
        pBox2->SetCurSel(DISTUNITS_MI);
    }

    pBox1 = (CComboBox*)GetDlgItem(IDC_PACETYPE1);
    pBox2 = (CComboBox*)GetDlgItem(IDC_PACETYPE2);
    if((NULL != pBox1) && (NULL != pBox2))
    {
        pBox1->AddString("min/mi");
        pBox1->AddString("min/km");
        pBox1->AddString("min/100m");
		pBox1->AddString("min/100y");
        pBox1->AddString("mi/hr");
        pBox1->AddString("km/hr");
        pBox2->AddString("min/mi");
        pBox2->AddString("min/km");
        pBox2->AddString("min/100m");
		pBox2->AddString("min/100y");
        pBox2->AddString("mi/hr");
        pBox2->AddString("km/hr");
        CDlgHelper::ReadyComboBox(pBox1, true);
        CDlgHelper::ReadyComboBox(pBox2, true);
        pBox1->SetCurSel(0);
        pBox2->SetCurSel(0);
    }

	SetDlgItemText(IDC_EXPONENT, "1.07");

    return fRes;
}


void CPaceCalcDlg::OnUpdatePaces(void)
{
    double dMiles1;
    double dMiles2;

    bool fMilesEntered1 = GetMiles(dMiles1, true);
    bool fMilesEntered2 = GetMiles(dMiles2, false);

    SetDlgItemText(IDC_PACE1, "");
    SetDlgItemText(IDC_PACE2, "");
	SetDlgItemText(IDC_TIME2, "");

	bool fTimeEntered1 = m_edtTime1.IsInputValid();

    double dSeconds = m_edtTime1.GetValue(false);

    double dMinutes = dSeconds / 60.0;

    if((fMilesEntered1) && (fTimeEntered1))
    {
        SetPaceBox(dMinutes, dMiles1, IDC_PACETYPE1, IDC_PACE1);

        if((fMilesEntered2) && (0.0 != dMiles1))
        {
            double dExp = 1.0;
            if(BST_CHECKED == IsDlgButtonChecked(IDC_SEIGEL))
            {
                dExp = m_edtExp.GetValue();

				if(false == m_edtExp.IsInputValid())
				{
					return;
				}
            }

            double dRatio = dMiles2 / dMiles1;

            double dCalcSeconds = dSeconds * pow(dRatio, dExp);
            double dCalcMinutes = dCalcSeconds / 60.0;

            CDlgHelper::SetDlgOneTime(this, IDC_TIME2, dCalcSeconds);

            SetPaceBox(dCalcMinutes, dMiles2, IDC_PACETYPE2, IDC_PACE2);
        }
    }
}


bool CPaceCalcDlg::GetMiles(double& rdMiles, bool f1)
{
    bool fOK;

	int nUnits = f1 ? IDC_UNITS1 : IDC_UNITS2;

	if(true == f1)
	{
		rdMiles = m_edtDist1.GetValue();
		fOK = m_edtDist1.IsInputValid();
	}
	else
	{
		rdMiles = m_edtDist2.GetValue();
		fOK = m_edtDist2.IsInputValid();
	}

    CComboBox* pUnitsBox = (CComboBox*)GetDlgItem(nUnits);
    if(NULL != pUnitsBox)
    {
        int nSel = pUnitsBox->GetCurSel();
        rdMiles = CUtil::ConvertDistance(nSel, DISTUNITS_MI, rdMiles);
    }

    return fOK;
}


void CPaceCalcDlg::SetPaceBox(double dMinutes, double dMiles, int nIDPaceType, int nIDPace)
{
    CComboBox* pBox = (CComboBox*)GetDlgItem(nIDPaceType);
    CString str;
    if(NULL != pBox)
    {
        int nSel = pBox->GetCurSel();
        switch(nSel)
        {
        case 0: // min/mi
            {
                if(0.0 != dMiles)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dMiles, PACEFORMAT_MINDIST, DISTUNITS_MI);
                }
                
                break;
            }

        case 1: // min/km
            {
                double dKm = CUtil::ConvertDistance(DISTUNITS_MI, DISTUNITS_KM, dMiles);
                if(0.0 != dKm)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dKm, PACEFORMAT_MINDIST, DISTUNITS_KM);
                }

                break;
            }

        case 2: // min/100m
            {
                if(0.0 != dMiles)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dMiles, PACEFORMAT_MIN100M, DISTUNITS_MI);
                }

                break;
            }

        case 3: // min/100y
            {
                if(0.0 != dMiles)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dMiles, PACEFORMAT_MIN100Y, DISTUNITS_MI);
                }

                break;
            }

        case 4: // mi/hr
            {
                if(0.0 != dMiles)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dMiles, PACEFORMAT_DISTHR, DISTUNITS_MI);
                }

                break;
            }

        case 5: // km/hr
            {
                double dKm = CUtil::ConvertDistance(DISTUNITS_MI, DISTUNITS_KM, dMiles);
                if(0.0 != dMinutes)
                {
                    str = CDlgHelper::FormatPaceKnownPaceType(dMinutes / dKm, PACEFORMAT_DISTHR, DISTUNITS_KM);
                }

                break;
            }
        }

        SetDlgItemText(nIDPace, str);
    }   
}


void CPaceCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}