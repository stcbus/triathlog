#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "SwimWorkoutIntervalDlg.h"


IMPLEMENT_DYNAMIC(CSwimWorkoutIntervalDlg, CDialog)


BEGIN_MESSAGE_MAP(CSwimWorkoutIntervalDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_SPECIALDIST, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_SPECIALTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CSwimWorkoutIntervalDlg::CSwimWorkoutIntervalDlg(LOCATIONSWIMARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CSwimWorkoutIntervalDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CSwimWorkoutIntervalDlg::~CSwimWorkoutIntervalDlg()
{
}


BOOL CSwimWorkoutIntervalDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();
	
	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSpecialDist.SubclassDlgItem(IDC_SPECIALDIST, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtSpecialSeconds.SubclassDlgItem(IDC_SPECIALTIME, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_SWIM));

    SetDlgItemText(IDC_DISPLAYNAME, "Intervals");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), false);

    OnUpdateOKButton();

    return TRUE;
}


void CSwimWorkoutIntervalDlg::OnAddData(void)
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


void CSwimWorkoutIntervalDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CSwimWorkoutIntervalDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
	SetSpecialSeconds(m_edtSpecialSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
	SetSpecialMiles(m_edtSpecialDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());

    SetChoppiness(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_CHOPPINESS), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CSwimWorkoutIntervalDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialDist.IsInputValid(), m_edtSpecialDist.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_SPECDIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CSwimWorkoutIntervalDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_SWIM);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), m_edtSpecialDist.GetValue(false), IDC_SPECIALPACE, FORMAT_SWIM);
}


double CSwimWorkoutIntervalDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CSwimWorkoutIntervalDlg::GetHR(void) const
{
    return m_nHR;
}


bool CSwimWorkoutIntervalDlg::IsLong(void) const
{
    return m_fLong;
}


CString CSwimWorkoutIntervalDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CSwimWorkoutIntervalDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CSwimWorkoutIntervalDlg::GetMiles(void) const
{
    return m_dMiles;
}


int CSwimWorkoutIntervalDlg::GetChoppiness(void) const
{
    return m_nChoppiness;
}


int CSwimWorkoutIntervalDlg::GetTemperature(void) const
{
    return m_nTemperature;
}


CLocationSwim* CSwimWorkoutIntervalDlg::GetLocation(void) const
{
    return m_pLocation;
}


double CSwimWorkoutIntervalDlg::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CSwimWorkoutIntervalDlg::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


void CSwimWorkoutIntervalDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CSwimWorkoutIntervalDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CSwimWorkoutIntervalDlg::SetTemperature(int nTemp)
{
    m_nTemperature = nTemp;
}


void CSwimWorkoutIntervalDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CSwimWorkoutIntervalDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CSwimWorkoutIntervalDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CSwimWorkoutIntervalDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CSwimWorkoutIntervalDlg::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CSwimWorkoutIntervalDlg::SetLocation(CLocationSwim* pLocation)
{
    m_pLocation = pLocation;
}


void CSwimWorkoutIntervalDlg::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CSwimWorkoutIntervalDlg::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}