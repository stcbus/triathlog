#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "EditUserDlg.h"


IMPLEMENT_DYNAMIC(CEditUserDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CEditUserDlg, CAniDialog)
    ON_EN_CHANGE(IDC_FIRSTNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_LASTNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
END_MESSAGE_MAP()


CEditUserDlg::CEditUserDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CEditUserDlg::IDD, pParent)
{
}


CEditUserDlg::~CEditUserDlg()
{
}


BOOL CEditUserDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtFirstName.SubclassDlgItem(IDC_FIRSTNAME, this);
	m_edtLastName.SubclassDlgItem(IDC_LASTNAME, this);
	m_edtHeight.SubclassDlgItem(IDC_HEIGHT, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);

	CUser* pUser = GetUser();
	if(NULL != pUser)
	{
		SetDlgItemText(IDC_FIRSTNAME, pUser->GetFirstName());
		SetDlgItemText(IDC_LASTNAME, pUser->GetLastName());
		SetDlgItemInt(IDC_HEIGHT, pUser->GetHeight());
		SetDlgItemInt(IDC_HEARTRATE, pUser->GetRestingHR());
		if(SEX_MALE == pUser->GetSex())
		{
			CheckDlgButton(IDC_SEXMALE, BST_CHECKED);
		}
		else
		{
			CheckDlgButton(IDC_SEXFEMALE, BST_CHECKED);
		}
	}

	OnUpdateOKButton();

    return TRUE;
}


void CEditUserDlg::OnOK(void)
{
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

    CAniDialog::OnOK();
}


void CEditUserDlg::OnUpdateOKButton(void)
{
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

    
void CEditUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


void CEditUserDlg::SetUser(CUser* pUser)
{
	m_pUser = pUser;
}


CString CEditUserDlg::GetFirstName(void) const
{
    return m_strFirstName;
}


CString CEditUserDlg::GetLastName(void) const
{
    return m_strLastName;
}


int CEditUserDlg::GetHeight(void) const
{
    return m_nHeight;
}


int CEditUserDlg::GetRestHR(void) const
{
	return m_nRestHR;
}


int CEditUserDlg::GetSex(void) const
{
    return m_nSex;
}


CUser* CEditUserDlg::GetUser(void) const
{
	return m_pUser;
}


void CEditUserDlg::SetFirstName(CString str)
{
    m_strFirstName = str;
}


void CEditUserDlg::SetLastName(CString str)
{
    m_strLastName = str;
}


void CEditUserDlg::SetRestHR(int nHR)
{
	m_nRestHR = nHR;
}


void CEditUserDlg::SetHeight(int nInches)
{
    m_nHeight = nInches;
}


void CEditUserDlg::SetSex(int nSex)
{
    m_nSex = nSex;
}