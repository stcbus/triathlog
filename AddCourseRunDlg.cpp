#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "ConverterDlg.h"
#include "AniDialog.h"
#include "AddCourseRunDlg.h"


IMPLEMENT_DYNAMIC(CAddCourseRunDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddCourseRunDlg, CAniDialog)
    ON_EN_CHANGE(IDC_COURSENAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_LENGTH, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PR, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
END_MESSAGE_MAP()


CAddCourseRunDlg::CAddCourseRunDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddCourseRunDlg::IDD, pParent)
{
}


CAddCourseRunDlg::~CAddCourseRunDlg()
{
}


BOOL CAddCourseRunDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_COURSENAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtLength.SubclassDlgItem(IDC_LENGTH, this);
	m_edtPR.SubclassDlgItem(IDC_PR, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));

    OnUpdateOKButton();

    return TRUE;
}


void CAddCourseRunDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CAddCourseRunDlg::OnOK(void)
{
    SetName(m_edtName.GetValue());
    SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetLength(m_edtLength.GetValue());
	SetPRSeconds(m_edtPR.GetValue());
	SetNotes(m_edtNotes.GetValue());
    
    CAniDialog::OnOK();
}


void CAddCourseRunDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtName.IsInputValid(), m_edtName.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCity.IsInputValid(), m_edtCity.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtState.IsInputValid(), m_edtState.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtLength.IsInputValid(), m_edtLength.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPR.IsInputValid(), m_edtPR.IsInputEmpty(), false);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    UpdatePace();
}


void CAddCourseRunDlg::UpdatePace(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtPR.GetValue(false), m_edtLength.GetValue(false), IDC_PRPACE, FORMAT_RUN);
}


void CAddCourseRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddCourseRunDlg::GetName(void) const
{
    return m_strName;
}


CString CAddCourseRunDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddCourseRunDlg::GetState(void) const
{
    return m_strState;
}


double CAddCourseRunDlg::GetLength(void) const
{
    return m_dLength;
}


double CAddCourseRunDlg::GetPRSeconds(void) const
{
    return m_dPRSeconds;
}


CString CAddCourseRunDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddCourseRunDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddCourseRunDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddCourseRunDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddCourseRunDlg::SetLength(double dLen)
{
    m_dLength = dLen;
}


void CAddCourseRunDlg::SetPRSeconds(double dSec)
{
    m_dPRSeconds = dSec;
}


void CAddCourseRunDlg::SetNotes(CString str)
{
    m_strNotes = str;
}