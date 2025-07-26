#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddLocationRunDlg.h"


IMPLEMENT_DYNAMIC(CAddLocationRunDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddLocationRunDlg, CAniDialog)
    ON_EN_CHANGE(IDC_LOCATIONNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
END_MESSAGE_MAP()


CAddLocationRunDlg::CAddLocationRunDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddLocationRunDlg::IDD, pParent)
{
}


CAddLocationRunDlg::~CAddLocationRunDlg()
{
}


BOOL CAddLocationRunDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_LOCATIONNAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    OnUpdateOKButton();

    return TRUE;
}


void CAddLocationRunDlg::OnOK(void)
{
	SetName(m_edtName.GetValue());
	SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddLocationRunDlg::OnUpdateOKButton(void)
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


void CAddLocationRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddLocationRunDlg::GetName(void) const
{
    return m_strName;
}


CString CAddLocationRunDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddLocationRunDlg::GetState(void) const
{
    return m_strState;
}


CString CAddLocationRunDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddLocationRunDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddLocationRunDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddLocationRunDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddLocationRunDlg::SetNotes(CString str)
{
    m_strNotes = str;
}