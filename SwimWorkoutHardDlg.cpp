#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "SwimWorkoutHardDlg.h"


IMPLEMENT_DYNAMIC(CSwimWorkoutHardDlg, CDialog)


BEGIN_MESSAGE_MAP(CSwimWorkoutHardDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CSwimWorkoutHardDlg::CSwimWorkoutHardDlg(LOCATIONSWIMARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CSwimWorkoutHardDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CSwimWorkoutHardDlg::~CSwimWorkoutHardDlg()
{
}


BOOL CSwimWorkoutHardDlg::OnInitDialog(void)
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

    SetDlgItemText(IDC_DISPLAYNAME, "Hard");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), false);

    OnUpdateOKButton();

    return TRUE;
}


void CSwimWorkoutHardDlg::OnAddData(void)
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


void CSwimWorkoutHardDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CSwimWorkoutHardDlg::OnOK(void)
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


void CSwimWorkoutHardDlg::OnUpdateOKButton(void)
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


void CSwimWorkoutHardDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_SWIM);
}


double CSwimWorkoutHardDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CSwimWorkoutHardDlg::GetHR(void) const
{
    return m_nHR;
}


bool CSwimWorkoutHardDlg::IsLong(void) const
{
    return m_fLong;
}


CString CSwimWorkoutHardDlg::GetNotes(void) const
{
    return m_strNotes;
}


int CSwimWorkoutHardDlg::GetChoppiness(void) const
{
    return m_nChoppiness;
}


int CSwimWorkoutHardDlg::GetTemperature(void) const
{
    return m_nTemperature;
}


CString CSwimWorkoutHardDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CSwimWorkoutHardDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationSwim* CSwimWorkoutHardDlg::GetLocation(void) const
{
    return m_pLocation;
}


void CSwimWorkoutHardDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CSwimWorkoutHardDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CSwimWorkoutHardDlg::SetTemperature(int nTemp)
{
    m_nTemperature = nTemp;
}


void CSwimWorkoutHardDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CSwimWorkoutHardDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CSwimWorkoutHardDlg::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CSwimWorkoutHardDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CSwimWorkoutHardDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CSwimWorkoutHardDlg::SetLocation(CLocationSwim* pLocation)
{
    m_pLocation = pLocation;
}