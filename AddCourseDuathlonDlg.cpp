#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "ConverterDlg.h"
#include "AniDialog.h"
#include "AddCourseDuathlonDlg.h"


IMPLEMENT_DYNAMIC(CAddCourseDuathlonDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddCourseDuathlonDlg, CAniDialog)
    ON_EN_CHANGE(IDC_COURSENAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_CITY, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_STATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L1LENGTH, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L1PR, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L2LENGTH, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L2PR, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L3LENGTH, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_L3PR, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TRANSITION1PR, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TRANSITION2PR, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_OVERALLPR, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
END_MESSAGE_MAP()


CAddCourseDuathlonDlg::CAddCourseDuathlonDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddCourseDuathlonDlg::IDD, pParent)
{
}


CAddCourseDuathlonDlg::~CAddCourseDuathlonDlg()
{
}


BOOL CAddCourseDuathlonDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtName.SubclassDlgItem(IDC_COURSENAME, this);
	m_edtCity.SubclassDlgItem(IDC_CITY, this);
	m_edtState.SubclassDlgItem(IDC_STATE, this);
	m_edtL1Length.SubclassDlgItem(IDC_L1LENGTH, this);
	m_edtL2Length.SubclassDlgItem(IDC_L2LENGTH, this);
	m_edtL3Length.SubclassDlgItem(IDC_L3LENGTH, this);
	m_edtL1PR.SubclassDlgItem(IDC_L1PR, this);
	m_edtL2PR.SubclassDlgItem(IDC_L2PR, this);
	m_edtL3PR.SubclassDlgItem(IDC_L3PR, this);
	m_edtTrans1PR.SubclassDlgItem(IDC_TRANSITION1PR, this);
	m_edtTrans2PR.SubclassDlgItem(IDC_TRANSITION2PR, this);
	m_edtOverallPR.SubclassDlgItem(IDC_OVERALLPR, this);
	m_edtL1Notes.SubclassDlgItem(IDC_L1NOTES, this);
	m_edtL2Notes.SubclassDlgItem(IDC_L2NOTES, this);
	m_edtL3Notes.SubclassDlgItem(IDC_L3NOTES, this);
	m_edtOverallNotes.SubclassDlgItem(IDC_OVERALLNOTES, this);

    SetDlgItemText(IDT_DISTL1, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_DISTL2, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_DISTL3, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3PACE, CUtil::GetPaceString(FORMAT_RUN));

    OnUpdateOKButton();

    return TRUE;
}


void CAddCourseDuathlonDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CAddCourseDuathlonDlg::OnOK(void)
{
    SetName(m_edtName.GetValue());
	SetCity(m_edtCity.GetValue());
	SetState(m_edtState.GetValue());
	SetL1Length(m_edtL1Length.GetValue());
	SetL2Length(m_edtL2Length.GetValue());
	SetL3Length(m_edtL3Length.GetValue());
	SetL1PRSeconds(m_edtL1PR.GetValue());
	SetL2PRSeconds(m_edtL2PR.GetValue());
	SetL3PRSeconds(m_edtL3PR.GetValue());
	SetTransition1PRSeconds(m_edtTrans1PR.GetValue());
	SetTransition2PRSeconds(m_edtTrans2PR.GetValue());
	SetOverallPRSeconds(m_edtOverallPR.GetValue());
	SetL1Notes(m_edtL1Notes.GetValue());
	SetL2Notes(m_edtL2Notes.GetValue());
	SetL3Notes(m_edtL3Notes.GetValue());
	SetOverallNotes(m_edtOverallNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddCourseDuathlonDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtName.IsInputValid(), m_edtName.IsInputEmpty());   
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCity.IsInputValid(), m_edtCity.IsInputEmpty());   
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtState.IsInputValid(), m_edtState.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Length.IsInputValid(), m_edtL1Length.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Length.IsInputValid(), m_edtL2Length.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Length.IsInputValid(), m_edtL3Length.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1PR.IsInputValid(), m_edtL1PR.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2PR.IsInputValid(), m_edtL2PR.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3PR.IsInputValid(), m_edtL3PR.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans1PR.IsInputValid(), m_edtTrans1PR.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans2PR.IsInputValid(), m_edtTrans2PR.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtOverallPR.IsInputValid(), m_edtOverallPR.IsInputEmpty(), false);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    UpdatePace();
}


void CAddCourseDuathlonDlg::UpdatePace(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1PR.GetValue(false), m_edtL1Length.GetValue(false), IDC_L1PRPACE, FORMAT_RUN);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2PR.GetValue(false), m_edtL2Length.GetValue(false), IDC_L2PRPACE, FORMAT_BIKE);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3PR.GetValue(false), m_edtL3Length.GetValue(false), IDC_L3PRPACE, FORMAT_RUN);
}


void CAddCourseDuathlonDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddCourseDuathlonDlg::GetName(void) const
{
    return m_strName;
}


CString CAddCourseDuathlonDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddCourseDuathlonDlg::GetState(void) const
{
    return m_strState;
}


double CAddCourseDuathlonDlg::GetL1Length(void) const
{
    return m_dL1Length;
}


double CAddCourseDuathlonDlg::GetL1PRSeconds(void) const
{
    return m_dL1PRSeconds;
}


CString CAddCourseDuathlonDlg::GetL1Notes(void) const
{
    return m_strL1Notes;
}


double CAddCourseDuathlonDlg::GetL2Length(void) const
{
    return m_dL2Length;
}


double CAddCourseDuathlonDlg::GetL2PRSeconds(void) const
{
    return m_dL2PRSeconds;
}


CString CAddCourseDuathlonDlg::GetL2Notes(void) const
{
    return m_strL2Notes;
}


double CAddCourseDuathlonDlg::GetL3Length(void) const
{
    return m_dL3Length;
}


double CAddCourseDuathlonDlg::GetL3PRSeconds(void) const
{
    return m_dL3PRSeconds;
}


CString CAddCourseDuathlonDlg::GetL3Notes(void) const
{
    return m_strL3Notes;
}


double CAddCourseDuathlonDlg::GetTransition1PRSeconds(void) const
{
    return m_dTransition1PRSeconds;
}


double CAddCourseDuathlonDlg::GetTransition2PRSeconds(void) const
{
    return m_dTransition2PRSeconds;
}


CString CAddCourseDuathlonDlg::GetOverallNotes(void) const
{
    return m_strNotes;
}


double CAddCourseDuathlonDlg::GetOverallPRSeconds(void) const
{
    return m_dOverallPRSeconds;
}


void CAddCourseDuathlonDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddCourseDuathlonDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddCourseDuathlonDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddCourseDuathlonDlg::SetL1Length(double dLen)
{
    m_dL1Length = dLen;
}


void CAddCourseDuathlonDlg::SetL1PRSeconds(double dSec)
{
    m_dL1PRSeconds = dSec;
}


void CAddCourseDuathlonDlg::SetL1Notes(CString str)
{
    m_strL1Notes = str;
}


void CAddCourseDuathlonDlg::SetL2Length(double dLen)
{
    m_dL2Length = dLen;
}


void CAddCourseDuathlonDlg::SetL2PRSeconds(double dSec)
{
    m_dL2PRSeconds = dSec;
}


void CAddCourseDuathlonDlg::SetL2Notes(CString str)
{
    m_strL2Notes = str;
}


void CAddCourseDuathlonDlg::SetL3Length(double dLen)
{
    m_dL3Length = dLen;
}


void CAddCourseDuathlonDlg::SetL3PRSeconds(double dSec)
{
    m_dL3PRSeconds = dSec;
}


void CAddCourseDuathlonDlg::SetL3Notes(CString str)
{
    m_strL3Notes = str;
}


void CAddCourseDuathlonDlg::SetTransition1PRSeconds(double dSec)
{
    m_dTransition1PRSeconds = dSec;
}


void CAddCourseDuathlonDlg::SetTransition2PRSeconds(double dSec)
{
    m_dTransition2PRSeconds = dSec;
}


void CAddCourseDuathlonDlg::SetOverallNotes(CString str)
{
    m_strNotes = str;
}


void CAddCourseDuathlonDlg::SetOverallPRSeconds(double dSec)
{
    m_dOverallPRSeconds = dSec;
}
