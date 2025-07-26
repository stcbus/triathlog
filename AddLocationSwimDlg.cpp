#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddLocationSwimDlg.h"


IMPLEMENT_DYNAMIC(CAddLocationSwimDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddLocationSwimDlg, CAniDialog)
    ON_EN_CHANGE(IDC_LOCATIONNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
END_MESSAGE_MAP()


CAddLocationSwimDlg::CAddLocationSwimDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddLocationSwimDlg::IDD, pParent)
{
}


CAddLocationSwimDlg::~CAddLocationSwimDlg()
{
}


BOOL CAddLocationSwimDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_LOCATIONNAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    OnUpdateOKButton();

    return TRUE;
}


void CAddLocationSwimDlg::OnOK(void)
{
	SetName(m_edtName.GetValue());
	SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddLocationSwimDlg::OnUpdateOKButton(void)
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


void CAddLocationSwimDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddLocationSwimDlg::GetName(void) const
{
    return m_strName;
}


CString CAddLocationSwimDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddLocationSwimDlg::GetState(void) const
{
    return m_strState;
}


CString CAddLocationSwimDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddLocationSwimDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddLocationSwimDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddLocationSwimDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddLocationSwimDlg::SetNotes(CString str)
{
    m_strNotes = str;
}