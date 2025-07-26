#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "BikeWorkoutTrainerDlg.h"


IMPLEMENT_DYNAMIC(CBikeWorkoutTrainerDlg, CDialog)


BEGIN_MESSAGE_MAP(CBikeWorkoutTrainerDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CBikeWorkoutTrainerDlg::CBikeWorkoutTrainerDlg(LOCATIONBIKEARRAY& rarLocations, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CBikeWorkoutTrainerDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes),
                m_rarBikes(rarBikes)
{
}


CBikeWorkoutTrainerDlg::~CBikeWorkoutTrainerDlg()
{
}


BOOL CBikeWorkoutTrainerDlg::OnInitDialog(void)
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

    SetDlgItemText(IDC_DISPLAYNAME, "Trainer");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_BIKE, BIKEFIELD_SHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_BIKE, BIKEFIELD_BIKE);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    CheckDlgButton(IDC_COUNTONSHOES, BST_CHECKED);
    CheckDlgButton(IDC_COUNTONBIKE, BST_CHECKED);

    OnUpdateOKButton();

    return TRUE;
}


void CBikeWorkoutTrainerDlg::OnAddData(void)
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


void CBikeWorkoutTrainerDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CBikeWorkoutTrainerDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());
	
	SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetCountOnShoes(BST_CHECKED == IsDlgButtonChecked(IDC_COUNTONSHOES));
    SetCountOnBike(BST_CHECKED == IsDlgButtonChecked(IDC_COUNTONBIKE));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CBikeWorkoutTrainerDlg::OnUpdateOKButton(void)
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


void CBikeWorkoutTrainerDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_BIKE);
}


double CBikeWorkoutTrainerDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CBikeWorkoutTrainerDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CBikeWorkoutTrainerDlg::GetHR(void) const
{
    return m_nHR;
}


bool CBikeWorkoutTrainerDlg::IsLong(void) const
{
    return m_fLong;
}


bool CBikeWorkoutTrainerDlg::CountOnShoes(void) const
{
    return m_fCountOnShoes;
}


bool CBikeWorkoutTrainerDlg::CountOnBike(void) const
{
    return m_fCountOnBike;
}


CString CBikeWorkoutTrainerDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CBikeWorkoutTrainerDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CBikeWorkoutTrainerDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationBike* CBikeWorkoutTrainerDlg::GetLocation(void) const
{
    return m_pLocation;
}


CBike* CBikeWorkoutTrainerDlg::GetBike(void) const
{
    return m_pBike;
}


CShoesBike* CBikeWorkoutTrainerDlg::GetShoes(void) const
{
    return m_pShoes;
}


void CBikeWorkoutTrainerDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CBikeWorkoutTrainerDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CBikeWorkoutTrainerDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CBikeWorkoutTrainerDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CBikeWorkoutTrainerDlg::SetCountOnShoes(bool fCount)
{
    m_fCountOnShoes = fCount;
}
 

void CBikeWorkoutTrainerDlg::SetCountOnBike(bool fCount)
{
    m_fCountOnBike = fCount;
}


void CBikeWorkoutTrainerDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CBikeWorkoutTrainerDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CBikeWorkoutTrainerDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CBikeWorkoutTrainerDlg::SetLocation(CLocationBike* pLocation)
{
    m_pLocation = pLocation;
}


void CBikeWorkoutTrainerDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CBikeWorkoutTrainerDlg::SetShoes(CShoesBike* pShoes)
{
    m_pShoes = pShoes;
}