#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddLocationBikeDlg.h"


IMPLEMENT_DYNAMIC(CAddLocationBikeDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddLocationBikeDlg, CAniDialog)
    ON_EN_CHANGE(IDC_LOCATIONNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
END_MESSAGE_MAP()


CAddLocationBikeDlg::CAddLocationBikeDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddLocationBikeDlg::IDD, pParent)
{
}


CAddLocationBikeDlg::~CAddLocationBikeDlg()
{
}


BOOL CAddLocationBikeDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_LOCATIONNAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    OnUpdateOKButton();

    return TRUE;
}


void CAddLocationBikeDlg::OnOK(void)
{
	SetName(m_edtName.GetValue());
	SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddLocationBikeDlg::OnUpdateOKButton(void)
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


void CAddLocationBikeDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddLocationBikeDlg::GetName(void) const
{
    return m_strName;
}


CString CAddLocationBikeDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddLocationBikeDlg::GetState(void) const
{
    return m_strState;
}


CString CAddLocationBikeDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddLocationBikeDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddLocationBikeDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddLocationBikeDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddLocationBikeDlg::SetNotes(CString str)
{
    m_strNotes = str;
}