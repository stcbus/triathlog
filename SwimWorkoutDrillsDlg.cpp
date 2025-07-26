#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "SwimWorkoutDrillsDlg.h"


IMPLEMENT_DYNAMIC(CSwimWorkoutDrillsDlg, CDialog)


BEGIN_MESSAGE_MAP(CSwimWorkoutDrillsDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CSwimWorkoutDrillsDlg::CSwimWorkoutDrillsDlg(LOCATIONSWIMARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CSwimWorkoutDrillsDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CSwimWorkoutDrillsDlg::~CSwimWorkoutDrillsDlg()
{
}


BOOL CSwimWorkoutDrillsDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Drills");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), false);

    OnUpdateOKButton();

    return TRUE;
}


void CSwimWorkoutDrillsDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CLocationSwim* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CSwimWorkoutDrillsDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CSwimWorkoutDrillsDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());
	
	SetChoppiness(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_CHOPPINESS), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CSwimWorkoutDrillsDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CSwimWorkoutDrillsDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_SWIM);
}


double CSwimWorkoutDrillsDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CSwimWorkoutDrillsDlg::GetHR(void) const
{
    return m_nHR;
}


bool CSwimWorkoutDrillsDlg::IsLong(void) const
{
    return m_fLong;
}


CString CSwimWorkoutDrillsDlg::GetNotes(void) const
{
    return m_strNotes;
}


int CSwimWorkoutDrillsDlg::GetChoppiness(void) const
{
    return m_nChoppiness;
}


int CSwimWorkoutDrillsDlg::GetTemperature(void) const
{
    return m_nTemperature;
}


CString CSwimWorkoutDrillsDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CSwimWorkoutDrillsDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationSwim* CSwimWorkoutDrillsDlg::GetLocation(void) const
{
    return m_pLocation;
}


void CSwimWorkoutDrillsDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CSwimWorkoutDrillsDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CSwimWorkoutDrillsDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CSwimWorkoutDrillsDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CSwimWorkoutDrillsDlg::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CSwimWorkoutDrillsDlg::SetTemperature(int nTemp)
{
    m_nTemperature = nTemp;
}


void CSwimWorkoutDrillsDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CSwimWorkoutDrillsDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CSwimWorkoutDrillsDlg::SetLocation(CLocationSwim* pLocation)
{
    m_pLocation = pLocation;
}