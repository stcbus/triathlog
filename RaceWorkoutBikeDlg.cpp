#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "Bike.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RaceWorkoutBikeDlg.h"


IMPLEMENT_DYNAMIC(CRaceWorkoutBikeDlg, CDialog)


BEGIN_MESSAGE_MAP(CRaceWorkoutBikeDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TIMERACE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_PLACE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_RACENUMBER, OnUpdateOKButton)

    ON_CBN_SELCHANGE(IDC_COURSE, OnUpdatePaces)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRaceWorkoutBikeDlg::CRaceWorkoutBikeDlg(COURSEBIKEARRAY& rarCourses, SHOESBIKEARRAY& rarShoes, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRaceWorkoutBikeDlg::IDD, pParent), 
                m_rarCourses(rarCourses), 
                m_rarShoes(rarShoes),
                m_rarBikes(rarBikes)
{
}


CRaceWorkoutBikeDlg::~CRaceWorkoutBikeDlg()
{
}


BOOL CRaceWorkoutBikeDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtSpecialSeconds.SubclassDlgItem(IDC_TIMERACE, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtPlace.SubclassDlgItem(IDC_PLACE, this);
	m_edtRaceNumber.SubclassDlgItem(IDC_RACENUMBER, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_BIKE));

    SetDlgItemText(IDC_DISPLAYNAME, "Bike");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_SPECSHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_BIKE);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);

    OnUpdateOKButton();
    UpdatePR();

    return TRUE;
}


void CRaceWorkoutBikeDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesBike* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CShoesBike* pSpecShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, fOK);
        CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
        CBike* pBike = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, true, false, true, SPORT_RACEBIKE, RACEBIKEFIELD_BIKE);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, pSpecShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, pCourse);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, pBike);

            OnUpdatePaces();
        }
    }
}


void CRaceWorkoutBikeDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRaceWorkoutBikeDlg::OnOK(void)
{
    bool fOK;

	double dSpecialSeconds = m_edtSpecialSeconds.GetValue();

    SetSeconds(m_edtSeconds.GetValue());
	SetSpecialSeconds(dSpecialSeconds);
    SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDisplayName(m_edtDisp.GetValue());
	SetRacePosition(m_edtPlace.GetValue());
	SetRaceNumber(m_edtRaceNumber.GetValue());

	CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

    SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), m_rarBikes, false, fOK));
    SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetSpecialShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, fOK));
    SetCourse(pCourse);

    if(NULL != pCourse)
    {
        pCourse->OptionallySetPR(dSpecialSeconds);
    }

    CDialog::OnOK();
}


void CRaceWorkoutBikeDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPlace.IsInputValid(), m_edtPlace.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_PLACE);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtRaceNumber.IsInputValid(), m_edtRaceNumber.IsInputEmpty(), SPORT_RACEBIKE, RACEBIKEFIELD_RACENUM);
 
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRaceWorkoutBikeDlg::UpdatePR(void)
{
    bool fOK;
    CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((fOK) && (NULL != pCourse))
    {
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
    }
}


void CRaceWorkoutBikeDlg::OnUpdatePaces(void)
{
    bool fOK;
	CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((!fOK) || (NULL == pCourse))
    {
        return;
    }

    double dLength = pCourse->GetLength();
    CString strText;
    strText.Format("%.2lf", dLength);
    SetDlgItemText(IDC_RACEDISTANCE, strText);
  
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_BIKE);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), dLength, IDC_RACEPACE, FORMAT_BIKE);

    UpdatePR();
}


double CRaceWorkoutBikeDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRaceWorkoutBikeDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRaceWorkoutBikeDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRaceWorkoutBikeDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRaceWorkoutBikeDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRaceWorkoutBikeDlg::GetDisplayName(void) const
{
    return m_strDisplay;
}


double CRaceWorkoutBikeDlg::GetMiles(void) const
{
    return m_dMiles;
}


CCourseBike* CRaceWorkoutBikeDlg::GetCourse(void) const
{
    return m_pCourse;
}


CShoesBike* CRaceWorkoutBikeDlg::GetShoes(void) const
{
    return m_pShoes;
}


int CRaceWorkoutBikeDlg::GetWind(void) const
{
    return m_nWind;
}


int CRaceWorkoutBikeDlg::GetRacePosition(void) const
{
    return m_nPlace;
}


int CRaceWorkoutBikeDlg::GetRaceNumber(void) const
{
    return m_nRaceNumber;
}


CBike* CRaceWorkoutBikeDlg::GetBike(void) const
{
    return m_pBike;
}


double CRaceWorkoutBikeDlg::GetSpecialSeconds(void) const
{
    return m_dRaceSeconds;
}


CShoesBike* CRaceWorkoutBikeDlg::GetSpecialShoes(void) const
{
    return m_pSpikes;
}


void CRaceWorkoutBikeDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRaceWorkoutBikeDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRaceWorkoutBikeDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRaceWorkoutBikeDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRaceWorkoutBikeDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRaceWorkoutBikeDlg::SetDisplayName(CString str)
{
    m_strDisplay = str;
}


void CRaceWorkoutBikeDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceWorkoutBikeDlg::SetCourse(CCourseBike* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceWorkoutBikeDlg::SetShoes(CShoesBike* pShoes)
{
    m_pShoes = pShoes;
}


void CRaceWorkoutBikeDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRaceWorkoutBikeDlg::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CRaceWorkoutBikeDlg::SetRaceNumber(int nNum)
{
    m_nRaceNumber = nNum;
}


void CRaceWorkoutBikeDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceWorkoutBikeDlg::SetSpecialSeconds(double dSec)
{
    m_dRaceSeconds = dSec;
}


void CRaceWorkoutBikeDlg::SetSpecialShoes(CShoesBike* pShoes)
{
    m_pSpikes = pShoes;
}