#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "BikeWorkoutIntervalDlg.h"


IMPLEMENT_DYNAMIC(CBikeWorkoutIntervalDlg, CDialog)


BEGIN_MESSAGE_MAP(CBikeWorkoutIntervalDlg, CDialog)
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


CBikeWorkoutIntervalDlg::CBikeWorkoutIntervalDlg(LOCATIONBIKEARRAY& rarLocations, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CBikeWorkoutIntervalDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes),
                m_rarBikes(rarBikes)
{
}


CBikeWorkoutIntervalDlg::~CBikeWorkoutIntervalDlg()
{
}


BOOL CBikeWorkoutIntervalDlg::OnInitDialog(void)
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

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_BIKE));

    SetDlgItemText(IDC_DISPLAYNAME, "Intervals");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SPECSHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_BIKE, BIKEFIELD_BIKE);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CBikeWorkoutIntervalDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesBike* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CShoesBike* pSpecShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, fOK);
        CLocationBike* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        CBike* pBike = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_BIKE, BIKEFIELD_BIKE);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, pSpecShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, pBike);
        }
    }
}


void CBikeWorkoutIntervalDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CBikeWorkoutIntervalDlg::OnOK(void)
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
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));
    SetSpecialShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, fOK));

    CDialog::OnOK();
}


void CBikeWorkoutIntervalDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialDist.IsInputValid(), m_edtSpecialDist.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_SPECDIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_HR);
        
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CBikeWorkoutIntervalDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_BIKE);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), m_edtSpecialDist.GetValue(false), IDC_SPECIALPACE, FORMAT_BIKE);
}


double CBikeWorkoutIntervalDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CBikeWorkoutIntervalDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CBikeWorkoutIntervalDlg::GetHR(void) const
{
    return m_nHR;
}


bool CBikeWorkoutIntervalDlg::IsLong(void) const
{
    return m_fLong;
}


CString CBikeWorkoutIntervalDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CBikeWorkoutIntervalDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CBikeWorkoutIntervalDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationBike* CBikeWorkoutIntervalDlg::GetLocation(void) const
{
    return m_pLocation;
}


CBike* CBikeWorkoutIntervalDlg::GetBike(void) const
{
    return m_pBike;
}


CShoesBike* CBikeWorkoutIntervalDlg::GetShoes(void) const
{
    return m_pShoes;
}


int CBikeWorkoutIntervalDlg::GetWind(void) const
{
    return m_nWind;
}


double CBikeWorkoutIntervalDlg::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CBikeWorkoutIntervalDlg::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


CShoesBike* CBikeWorkoutIntervalDlg::GetSpecialShoes(void) const
{
    return m_pSpikes;
}


void CBikeWorkoutIntervalDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CBikeWorkoutIntervalDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CBikeWorkoutIntervalDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CBikeWorkoutIntervalDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CBikeWorkoutIntervalDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CBikeWorkoutIntervalDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CBikeWorkoutIntervalDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CBikeWorkoutIntervalDlg::SetLocation(CLocationBike* pLocation)
{
    m_pLocation = pLocation;
}


void CBikeWorkoutIntervalDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CBikeWorkoutIntervalDlg::SetShoes(CShoesBike* pShoes)
{
    m_pShoes = pShoes;
}


void CBikeWorkoutIntervalDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CBikeWorkoutIntervalDlg::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CBikeWorkoutIntervalDlg::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}


void CBikeWorkoutIntervalDlg::SetSpecialShoes(CShoesBike* pShoes)
{
    m_pSpikes = pShoes;
}