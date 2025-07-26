#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AddUserDlg.h"


IMPLEMENT_DYNAMIC(CAddUserDlg, CDialog)

BEGIN_MESSAGE_MAP(CAddUserDlg, CDialog)
    ON_EN_CHANGE(IDC_FIRSTNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_LASTNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_UNITSAMERICAN, OnUnitsChanged)
    ON_BN_CLICKED(IDC_UNITSMETRIC, OnUnitsChanged)
END_MESSAGE_MAP()


CAddUserDlg::CAddUserDlg(CWnd* pParent /* = NULL*/) : CDialog(CAddUserDlg::IDD, pParent)
{
}


CAddUserDlg::~CAddUserDlg()
{
}


BOOL CAddUserDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtFirstName.SubclassDlgItem(IDC_FIRSTNAME, this);
	m_edtLastName.SubclassDlgItem(IDC_LASTNAME, this);
	m_edtHeight.SubclassDlgItem(IDC_HEIGHT, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);

    CheckRadioButton(IDC_SEXMALE, IDC_SEXFEMALE, IDC_SEXMALE);
    CheckRadioButton(IDC_UNITSAMERICAN, IDC_UNITSMETRIC, IDC_UNITSAMERICAN);

    CDlgHelper::FillComboBoxDaysOfWeek((CComboBox*)GetDlgItem(IDC_STARTDAY), false);
    
    OnUpdateOKButton();
    OnUnitsChanged();

    return TRUE;
}


void CAddUserDlg::OnOK(void)
{
	bool fOK;

	SetFirstName(m_edtFirstName.GetValue());    
	SetLastName(m_edtLastName.GetValue());
    SetHeight(m_edtHeight.GetValue());
    SetRestHR(m_edtHR.GetValue());

    if(BST_CHECKED == IsDlgButtonChecked(IDC_SEXMALE))
    {
        SetSex(SEX_MALE);
    }
    else
    {
        SetSex(SEX_FEMALE);
    }

    SetUnitsAmerican(BST_CHECKED == IsDlgButtonChecked(IDC_UNITSAMERICAN));

    SetFirstDay(CDlgHelper::GetComboSelDayOfWeek((CComboBox*)GetDlgItem(IDC_STARTDAY), fOK));
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_STARTDAY);
    if(!fOK)
    {
        AfxMessageBox("Please select a valid day.");
        return;
    }     

    CDialog::OnOK();
}


void CAddUserDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtFirstName.IsInputValid(), m_edtFirstName.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtLastName.IsInputValid(), m_edtLastName.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHeight.IsInputValid(), m_edtHeight.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty());

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CAddUserDlg::OnUnitsChanged(void)
{
    bool bAmerican = (BST_CHECKED == IsDlgButtonChecked(IDC_UNITSAMERICAN));
    CString str = "Height";
    if(bAmerican)
    {
        str += " (in)";
    }
    else
    {
        str += " (cm)";
    }

    str += ":";

    SetDlgItemText(IDT_HEIGHT, str);
}

    
void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX); 
}


CString CAddUserDlg::GetFirstName(void) const
{
    return m_strFirstName;
}


CString CAddUserDlg::GetLastName(void) const
{
    return m_strLastName;
}


int CAddUserDlg::GetFirstDay(void) const
{
    return m_nFirstDay;
}


int CAddUserDlg::GetHeight(void) const
{
    return m_nHeight;
}


int CAddUserDlg::GetSex(void) const
{
    return m_nSex;
}


bool CAddUserDlg::AreUnitsAmerican(void) const
{
    return m_bUnitsAmerican;
}

int CAddUserDlg::GetRestHR(void) const
{
    return m_nRestHR;
}


void CAddUserDlg::SetFirstName(CString str)
{
    m_strFirstName = str;
}


void CAddUserDlg::SetLastName(CString str)
{
    m_strLastName = str;
}


void CAddUserDlg::SetFirstDay(int nDay)
{
    m_nFirstDay = nDay;
}


void CAddUserDlg::SetHeight(int nInches)
{
    m_nHeight = nInches;
}


void CAddUserDlg::SetSex(int nSex)
{
    m_nSex = nSex;
}


void CAddUserDlg::SetUnitsAmerican(bool bAmerican)
{
    m_bUnitsAmerican = bAmerican;
}


void CAddUserDlg::SetRestHR(int nHR)
{
    m_nRestHR = nHR;
}