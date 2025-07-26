#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "AddAllDataDlg.h"
#include "StrengthWorkoutWeightsDlg.h"


IMPLEMENT_DYNAMIC(CStrengthWorkoutWeightsDlg, CDialog)


BEGIN_MESSAGE_MAP(CStrengthWorkoutWeightsDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CStrengthWorkoutWeightsDlg::CStrengthWorkoutWeightsDlg(LOCATIONSTRENGTHARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CStrengthWorkoutWeightsDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CStrengthWorkoutWeightsDlg::~CStrengthWorkoutWeightsDlg()
{
}


BOOL CStrengthWorkoutWeightsDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);
	
	SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Weights");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CStrengthWorkoutWeightsDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CLocationStrength* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CStrengthWorkoutWeightsDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());
	
	SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CStrengthWorkoutWeightsDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


double CStrengthWorkoutWeightsDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CStrengthWorkoutWeightsDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CStrengthWorkoutWeightsDlg::GetHR(void) const
{
    return m_nHR;
}


bool CStrengthWorkoutWeightsDlg::IsLong(void) const
{
    return m_fLong;
}


CString CStrengthWorkoutWeightsDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CStrengthWorkoutWeightsDlg::GetDispName(void) const
{
    return m_strDisp;
}


CLocationStrength* CStrengthWorkoutWeightsDlg::GetLocation(void) const
{
    return m_pLocation;
}


void CStrengthWorkoutWeightsDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CStrengthWorkoutWeightsDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CStrengthWorkoutWeightsDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CStrengthWorkoutWeightsDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CStrengthWorkoutWeightsDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CStrengthWorkoutWeightsDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CStrengthWorkoutWeightsDlg::SetLocation(CLocationStrength* pLocation)
{
    m_pLocation = pLocation;
}