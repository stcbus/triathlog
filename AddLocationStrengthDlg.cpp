#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddLocationStrengthDlg.h"


IMPLEMENT_DYNAMIC(CAddLocationStrengthDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddLocationStrengthDlg, CAniDialog)
    ON_EN_CHANGE(IDC_LOCATIONNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
END_MESSAGE_MAP()


CAddLocationStrengthDlg::CAddLocationStrengthDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddLocationStrengthDlg::IDD, pParent)
{
}


CAddLocationStrengthDlg::~CAddLocationStrengthDlg()
{
}


BOOL CAddLocationStrengthDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_LOCATIONNAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    OnUpdateOKButton();

    return TRUE;
}


void CAddLocationStrengthDlg::OnOK(void)
{
	SetName(m_edtName.GetValue());
	SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddLocationStrengthDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtName.IsInputValid(), m_edtName.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCity.IsInputValid(), m_edtCity.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtState.IsInputValid(), m_edtState.IsInputEmpty());

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CAddLocationStrengthDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddLocationStrengthDlg::GetName(void) const
{
    return m_strName;
}


CString CAddLocationStrengthDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddLocationStrengthDlg::GetState(void) const
{
    return m_strState;
}


CString CAddLocationStrengthDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddLocationStrengthDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddLocationStrengthDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddLocationStrengthDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddLocationStrengthDlg::SetNotes(CString str)
{
    m_strNotes = str;
}