#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "AddAllDataDlg.h"
#include "StrengthWorkoutMiscDlg.h"


IMPLEMENT_DYNAMIC(CStrengthWorkoutMiscDlg, CDialog)


BEGIN_MESSAGE_MAP(CStrengthWorkoutMiscDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CStrengthWorkoutMiscDlg::CStrengthWorkoutMiscDlg(LOCATIONSTRENGTHARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CStrengthWorkoutMiscDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CStrengthWorkoutMiscDlg::~CStrengthWorkoutMiscDlg()
{
}


BOOL CStrengthWorkoutMiscDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Other");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CStrengthWorkoutMiscDlg::OnAddData(void)
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


void CStrengthWorkoutMiscDlg::OnOK(void)
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


void CStrengthWorkoutMiscDlg::OnUpdateOKButton(void)
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


double CStrengthWorkoutMiscDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CStrengthWorkoutMiscDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CStrengthWorkoutMiscDlg::GetHR(void) const
{
    return m_nHR;
}


bool CStrengthWorkoutMiscDlg::IsLong(void) const
{
    return m_fLong;
}


CString CStrengthWorkoutMiscDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CStrengthWorkoutMiscDlg::GetDispName(void) const
{
    return m_strDisp;
}


CLocationStrength* CStrengthWorkoutMiscDlg::GetLocation(void) const
{
    return m_pLocation;
}


void CStrengthWorkoutMiscDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CStrengthWorkoutMiscDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CStrengthWorkoutMiscDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CStrengthWorkoutMiscDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CStrengthWorkoutMiscDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CStrengthWorkoutMiscDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CStrengthWorkoutMiscDlg::SetLocation(CLocationStrength* pLocation)
{
    m_pLocation = pLocation;
}