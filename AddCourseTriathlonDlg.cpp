#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "ConverterDlg.h"
#include "AniDialog.h"
#include "AddCourseTriathlonDlg.h"


IMPLEMENT_DYNAMIC(CAddCourseTriathlonDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddCourseTriathlonDlg, CAniDialog)
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


CAddCourseTriathlonDlg::CAddCourseTriathlonDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddCourseTriathlonDlg::IDD, pParent)
{
}


CAddCourseTriathlonDlg::~CAddCourseTriathlonDlg()
{
}


BOOL CAddCourseTriathlonDlg::OnInitDialog(void)
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
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_DISTL2, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_DISTL3, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3PACE, CUtil::GetPaceString(FORMAT_RUN));

    OnUpdateOKButton();

    return TRUE;
}


void CAddCourseTriathlonDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CAddCourseTriathlonDlg::OnOK(void)
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


void CAddCourseTriathlonDlg::OnUpdateOKButton(void)
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


void CAddCourseTriathlonDlg::UpdatePace(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1PR.GetValue(false), m_edtL1Length.GetValue(false), IDC_L1PRPACE, FORMAT_SWIM);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2PR.GetValue(false), m_edtL2Length.GetValue(false), IDC_L2PRPACE, FORMAT_BIKE);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3PR.GetValue(false), m_edtL3Length.GetValue(false), IDC_L3PRPACE, FORMAT_RUN);
}


void CAddCourseTriathlonDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddCourseTriathlonDlg::GetName(void) const
{
    return m_strName;
}


CString CAddCourseTriathlonDlg::GetCity(void) const
{
    return m_strCity;
}


CString CAddCourseTriathlonDlg::GetState(void) const
{
    return m_strState;
}


double CAddCourseTriathlonDlg::GetL1Length(void) const
{
    return m_dL1Length;
}


double CAddCourseTriathlonDlg::GetL1PRSeconds(void) const
{
    return m_dL1PRSeconds;
}


CString CAddCourseTriathlonDlg::GetL1Notes(void) const
{
    return m_strL1Notes;
}


double CAddCourseTriathlonDlg::GetL2Length(void) const
{
    return m_dL2Length;
}


double CAddCourseTriathlonDlg::GetL2PRSeconds(void) const
{
    return m_dL2PRSeconds;
}


CString CAddCourseTriathlonDlg::GetL2Notes(void) const
{
    return m_strL2Notes;
}


double CAddCourseTriathlonDlg::GetL3Length(void) const
{
    return m_dL3Length;
}


double CAddCourseTriathlonDlg::GetL3PRSeconds(void) const
{
    return m_dL3PRSeconds;
}


CString CAddCourseTriathlonDlg::GetL3Notes(void) const
{
    return m_strL3Notes;
}


double CAddCourseTriathlonDlg::GetTransition1PRSeconds(void) const
{
    return m_dTransition1PRSeconds;
}


double CAddCourseTriathlonDlg::GetTransition2PRSeconds(void) const
{
    return m_dTransition2PRSeconds;
}


CString CAddCourseTriathlonDlg::GetOverallNotes(void) const
{
    return m_strNotes;
}


double CAddCourseTriathlonDlg::GetOverallPRSeconds(void) const
{
    return m_dOverallPRSeconds;
}


void CAddCourseTriathlonDlg::SetName(CString str)
{
    m_strName = str;
}


void CAddCourseTriathlonDlg::SetCity(CString str)
{
    m_strCity = str;
}


void CAddCourseTriathlonDlg::SetState(CString str)
{
    m_strState = str;
}


void CAddCourseTriathlonDlg::SetL1Length(double dLen)
{
    m_dL1Length = dLen;
}


void CAddCourseTriathlonDlg::SetL1PRSeconds(double dSec)
{
    m_dL1PRSeconds = dSec;
}


void CAddCourseTriathlonDlg::SetL1Notes(CString str)
{
    m_strL1Notes = str;
}


void CAddCourseTriathlonDlg::SetL2Length(double dLen)
{
    m_dL2Length = dLen;
}


void CAddCourseTriathlonDlg::SetL2PRSeconds(double dSec)
{
    m_dL2PRSeconds = dSec;
}


void CAddCourseTriathlonDlg::SetL2Notes(CString str)
{
    m_strL2Notes = str;
}


void CAddCourseTriathlonDlg::SetL3Length(double dLen)
{
    m_dL3Length = dLen;
}


void CAddCourseTriathlonDlg::SetL3PRSeconds(double dSec)
{
    m_dL3PRSeconds = dSec;
}


void CAddCourseTriathlonDlg::SetL3Notes(CString str)
{
    m_strL3Notes = str;
}


void CAddCourseTriathlonDlg::SetTransition1PRSeconds(double dSec)
{
    m_dTransition1PRSeconds = dSec;
}


void CAddCourseTriathlonDlg::SetTransition2PRSeconds(double dSec)
{
    m_dTransition2PRSeconds = dSec;
}


void CAddCourseTriathlonDlg::SetOverallNotes(CString str)
{
    m_strNotes = str;
}


void CAddCourseTriathlonDlg::SetOverallPRSeconds(double dSec)
{
    m_dOverallPRSeconds = dSec;
}