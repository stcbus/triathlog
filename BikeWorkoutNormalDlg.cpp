#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "BikeWorkoutNormalDlg.h"


IMPLEMENT_DYNAMIC(CBikeWorkoutNormalDlg, CDialog)


BEGIN_MESSAGE_MAP(CBikeWorkoutNormalDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CBikeWorkoutNormalDlg::CBikeWorkoutNormalDlg(LOCATIONBIKEARRAY& rarLocations, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CBikeWorkoutNormalDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes),
                m_rarBikes(rarBikes)
{
}


CBikeWorkoutNormalDlg::~CBikeWorkoutNormalDlg()
{
}


BOOL CBikeWorkoutNormalDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Normal");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_BIKE, BIKEFIELD_BIKE);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CBikeWorkoutNormalDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesBike* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CLocationBike* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        CBike* pBike = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_BIKE, BIKEFIELD_BIKE);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, pBike);
        }
    }
}


void CBikeWorkoutNormalDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CBikeWorkoutNormalDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());
	
	SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CBikeWorkoutNormalDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_HR);

	CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CBikeWorkoutNormalDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_BIKE);
}


double CBikeWorkoutNormalDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CBikeWorkoutNormalDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CBikeWorkoutNormalDlg::GetHR(void) const
{
    return m_nHR;
}


bool CBikeWorkoutNormalDlg::IsLong(void) const
{
    return m_fLong;
}


CString CBikeWorkoutNormalDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CBikeWorkoutNormalDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CBikeWorkoutNormalDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationBike* CBikeWorkoutNormalDlg::GetLocation(void) const
{
    return m_pLocation;
}


CBike* CBikeWorkoutNormalDlg::GetBike(void) const
{
    return m_pBike;
}


CShoesBike* CBikeWorkoutNormalDlg::GetShoes(void) const
{
    return m_pShoes;
}


int CBikeWorkoutNormalDlg::GetWind(void) const
{
    return m_nWind;
}


void CBikeWorkoutNormalDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CBikeWorkoutNormalDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CBikeWorkoutNormalDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CBikeWorkoutNormalDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CBikeWorkoutNormalDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CBikeWorkoutNormalDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CBikeWorkoutNormalDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CBikeWorkoutNormalDlg::SetLocation(CLocationBike* pLocation)
{
    m_pLocation = pLocation;
}


void CBikeWorkoutNormalDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CBikeWorkoutNormalDlg::SetShoes(CShoesBike* pShoes)
{
    m_pShoes = pShoes;
}


void CBikeWorkoutNormalDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}