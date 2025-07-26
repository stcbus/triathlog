#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RunWorkoutTempoDlg.h"


IMPLEMENT_DYNAMIC(CRunWorkoutTempoDlg, CDialog)


BEGIN_MESSAGE_MAP(CRunWorkoutTempoDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_SPECIALTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_SPECIALDIST, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRunWorkoutTempoDlg::CRunWorkoutTempoDlg(LOCATIONRUNARRAY& rarLocations, SHOESRUNARRAY& rarShoes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRunWorkoutTempoDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes)
{
}


CRunWorkoutTempoDlg::~CRunWorkoutTempoDlg()
{
}


BOOL CRunWorkoutTempoDlg::OnInitDialog(void)
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

    SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_RUN));

    SetDlgItemText(IDC_DISPLAYNAME, "Tempo");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CRunWorkoutTempoDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesRun* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CLocationRun* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CRunWorkoutTempoDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRunWorkoutTempoDlg::OnOK(void)
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

    SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CRunWorkoutTempoDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RUN, RUNFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_RUN, RUNFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RUN, RUNFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialDist.IsInputValid(), m_edtSpecialDist.IsInputEmpty(), SPORT_RUN, RUNFIELD_SPECDIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RUN, RUNFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RUN, RUNFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRunWorkoutTempoDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_RUN);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), m_edtSpecialDist.GetValue(false), IDC_SPECIALPACE, FORMAT_RUN);
}


double CRunWorkoutTempoDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRunWorkoutTempoDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRunWorkoutTempoDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRunWorkoutTempoDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRunWorkoutTempoDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRunWorkoutTempoDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CRunWorkoutTempoDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationRun* CRunWorkoutTempoDlg::GetLocation(void) const
{
    return m_pLocation;
}


CShoesRun* CRunWorkoutTempoDlg::GetShoes(void) const
{
    return m_pShoes;
}


int CRunWorkoutTempoDlg::GetWind(void) const
{
    return m_nWind;
}


double CRunWorkoutTempoDlg::GetSpecialSeconds(void) const
{
    return m_dTempoSeconds;
}


double CRunWorkoutTempoDlg::GetSpecialMiles(void) const
{
    return m_dTempoMiles;
}


void CRunWorkoutTempoDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRunWorkoutTempoDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRunWorkoutTempoDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRunWorkoutTempoDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRunWorkoutTempoDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRunWorkoutTempoDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CRunWorkoutTempoDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRunWorkoutTempoDlg::SetLocation(CLocationRun* pLocation)
{
    m_pLocation = pLocation;
}


void CRunWorkoutTempoDlg::SetShoes(CShoesRun* pShoes)
{
    m_pShoes = pShoes;
}


void CRunWorkoutTempoDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunWorkoutTempoDlg::SetSpecialSeconds(double dSec)
{
    m_dTempoSeconds = dSec;
}


void CRunWorkoutTempoDlg::SetSpecialMiles(double dMiles)
{
    m_dTempoMiles = dMiles;
}