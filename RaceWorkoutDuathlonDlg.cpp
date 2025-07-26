#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RaceWorkoutDuathlonDlg.h"


IMPLEMENT_DYNAMIC(CRaceWorkoutDuathlonDlg, CDialog)


BEGIN_MESSAGE_MAP(CRaceWorkoutDuathlonDlg, CDialog)
    ON_EN_CHANGE(IDC_OVERALLTIMERACE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_PLACE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_RACENUMBER, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TRANSITION1, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TRANSITION2, OnUpdateOKButton)

	ON_EN_CHANGE(IDC_L1TIMEOVERALL, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L1DISTANCE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L1TEMPERATURE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L1HEARTRATE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L1TIMERACE, OnUpdateOKButton)

	ON_EN_CHANGE(IDC_L2TIMEOVERALL, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L2DISTANCE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L2TEMPERATURE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L2HEARTRATE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L2TIMERACE, OnUpdateOKButton)

	ON_EN_CHANGE(IDC_L3TIMEOVERALL, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L3DISTANCE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L3TEMPERATURE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L3HEARTRATE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_L3TIMERACE, OnUpdateOKButton)

    ON_CBN_SELCHANGE(IDC_COURSE, OnUpdatePaces)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRaceWorkoutDuathlonDlg::CRaceWorkoutDuathlonDlg(COURSEDUATHLONARRAY& rarCourses, SHOESRUNARRAY& rarShoesRun, 
                                                 SHOESBIKEARRAY& rarShoesBike, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRaceWorkoutDuathlonDlg::IDD, pParent), 
                m_rarCourses(rarCourses), 
                m_rarShoesRun(rarShoesRun),
                m_rarShoesBike(rarShoesBike),
                m_rarBikes(rarBikes)
{
}


CRaceWorkoutDuathlonDlg::~CRaceWorkoutDuathlonDlg()
{
}


BOOL CRaceWorkoutDuathlonDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtOverallSeconds.SubclassDlgItem(IDC_OVERALLTIMERACE, this);
	m_edtTrans1Seconds.SubclassDlgItem(IDC_TRANSITION1, this);
	m_edtTrans2Seconds.SubclassDlgItem(IDC_TRANSITION2, this);
	m_edtPlace.SubclassDlgItem(IDC_PLACE, this);
	m_edtRaceNumber.SubclassDlgItem(IDC_RACENUMBER, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

	m_edtL1Seconds.SubclassDlgItem(IDC_L1TIMEOVERALL, this);
	m_edtL1Dist.SubclassDlgItem(IDC_L1DISTANCE, this);
	m_edtL1Temp.SubclassDlgItem(IDC_L1TEMPERATURE, this);
	m_edtL1HR.SubclassDlgItem(IDC_L1HEARTRATE, this);
	m_edtL1SpecialSeconds.SubclassDlgItem(IDC_L1TIMERACE, this);

	m_edtL2Seconds.SubclassDlgItem(IDC_L2TIMEOVERALL, this);
	m_edtL2Dist.SubclassDlgItem(IDC_L2DISTANCE, this);
	m_edtL2Temp.SubclassDlgItem(IDC_L2TEMPERATURE, this);
	m_edtL2HR.SubclassDlgItem(IDC_L2HEARTRATE, this);
	m_edtL2SpecialSeconds.SubclassDlgItem(IDC_L2TIMERACE, this);

	m_edtL3Seconds.SubclassDlgItem(IDC_L3TIMEOVERALL, this);
	m_edtL3Dist.SubclassDlgItem(IDC_L3DISTANCE, this);
	m_edtL3Temp.SubclassDlgItem(IDC_L3TEMPERATURE, this);
	m_edtL3HR.SubclassDlgItem(IDC_L3HEARTRATE, this);
	m_edtL3SpecialSeconds.SubclassDlgItem(IDC_L3TIMERACE, this);

    SetDlgItemText(IDT_L1DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_L1TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_L1SPECIALDIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L1SPECIALPACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_L2DIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2PACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_L2TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_L2SPECIALDIST, CUtil::GetBikeDistString());
    SetDlgItemText(IDT_L2SPECIALPACE, CUtil::GetPaceString(FORMAT_BIKE));
    SetDlgItemText(IDT_L3DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_L3TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_L3SPECIALDIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_L3SPECIALPACE, CUtil::GetPaceString(FORMAT_RUN));

    SetDlgItemText(IDC_DISPLAYNAME, "Duathlon");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L1SHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L1SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L1RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L1SPECSHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2SPECSHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L3SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L3SPECSHOES);
    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L1WIND), false);
    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L2WIND), false);
    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L3WIND), false);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2BIKE);
    OnUpdateOKButton();
    UpdatePR();

    return TRUE;
}


void CRaceWorkoutDuathlonDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesRun* pShoes1 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L1SHOES), m_rarShoesRun, false, fOK);
        CShoesRun* pSpecShoes1 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L1RACESHOES), m_rarShoesRun, false, fOK);
        CShoesBike* pShoes2 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, false, fOK);
        CShoesBike* pSpecShoes2 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, false, fOK);
        CShoesRun* pShoes3 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, false, fOK);
        CShoesRun* pSpecShoes3 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, false, fOK);
        CCourseDuathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
        CBike* pBike = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, false, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L1SHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L1SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L1RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L1SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L3SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACEDU, RACEDUFIELD_L3SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, true, false, true, SPORT_RACEDU, RACEDUFIELD_L2BIKE);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L1SHOES), m_rarShoesRun, false, pShoes1);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L1RACESHOES), m_rarShoesRun, false, pSpecShoes1);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, false, pShoes2);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, false, pSpecShoes2);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, false, pShoes3);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, false, pSpecShoes3);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, pCourse);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, false, pBike);

            OnUpdatePaces();
        }
    }
}


void CRaceWorkoutDuathlonDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRaceWorkoutDuathlonDlg::OnOK(void)
{
    bool fOK;

	double dOverallSec = m_edtOverallSeconds.GetValue();
	double dTransition1Sec = m_edtTrans1Seconds.GetValue();
	double dTransition2Sec = m_edtTrans2Seconds.GetValue();
	double dLeg1RaceSeconds = m_edtL1SpecialSeconds.GetValue();
	double dLeg2RaceSeconds = m_edtL2SpecialSeconds.GetValue();
	double dLeg3RaceSeconds = m_edtL3SpecialSeconds.GetValue();

    SetOverallSeconds(dOverallSec);
	SetTransition1Seconds(dTransition1Sec);
	SetTransition2Seconds(dTransition2Sec);
    SetNotes(m_edtNotes.GetValue());
    SetDisplayName(m_edtDisp.GetValue());
	SetRacePosition(m_edtPlace.GetValue());
	SetRaceNumber(m_edtRaceNumber.GetValue());

	SetLeg1Seconds(m_edtL1Seconds.GetValue());
    SetLeg1Miles(m_edtL1Dist.GetValue());
	SetLeg1Temperature(m_edtL1Temp.GetValue());
	SetLeg1HR(m_edtL1HR.GetValue());
	SetLeg1RaceSeconds(dLeg1RaceSeconds);

	SetLeg2Seconds(m_edtL2Seconds.GetValue());
    SetLeg2Miles(m_edtL2Dist.GetValue());
	SetLeg2Temperature(m_edtL2Temp.GetValue());
	SetLeg2HR(m_edtL2HR.GetValue());
	SetLeg2RaceSeconds(dLeg2RaceSeconds);

	SetLeg3Seconds(m_edtL3Seconds.GetValue());
    SetLeg3Miles(m_edtL3Dist.GetValue());
	SetLeg3Temperature(m_edtL3Temp.GetValue());
	SetLeg3HR(m_edtL3HR.GetValue());
	SetLeg3RaceSeconds(dLeg3RaceSeconds);

    CCourseDuathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLeg1Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L1WIND), fOK));
    SetLeg1Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L1SHOES), m_rarShoesRun, false, fOK));
    SetLeg1RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L1RACESHOES), m_rarShoesRun, false, fOK));

	SetLeg2Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L2WIND), fOK));
    SetLeg2Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, false, fOK));
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, false, fOK));
    SetLeg2RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, false, fOK));

	SetLeg3Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L3WIND), fOK));
    SetLeg3Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, false, fOK));
    SetLeg3RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, false, fOK));
    SetCourseDuathlon(pCourse);

    if(NULL != pCourse)
    {
        pCourse->OptionallySetPR(dOverallSec);
        pCourse->OptionallySetTransition1PR(dTransition1Sec);
        pCourse->OptionallySetTransition2PR(dTransition2Sec);
        pCourse->OptionallySetLeg1PR(dLeg1RaceSeconds);
        pCourse->OptionallySetLeg2PR(dLeg2RaceSeconds);
        pCourse->OptionallySetLeg3PR(dLeg3RaceSeconds);
    }

    CDialog::OnOK();
}


void CRaceWorkoutDuathlonDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtOverallSeconds.IsInputValid(), m_edtOverallSeconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_OVERALLTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans1Seconds.IsInputValid(), m_edtTrans1Seconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_TRANS);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans2Seconds.IsInputValid(), m_edtTrans2Seconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_TRANS);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPlace.IsInputValid(), m_edtPlace.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_PLACE);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtRaceNumber.IsInputValid(), m_edtRaceNumber.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_RACENUM);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Seconds.IsInputValid(), m_edtL1Seconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L1TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Dist.IsInputValid(), m_edtL1Dist.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L1DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Temp.IsInputValid(), m_edtL1Temp.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L1TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1HR.IsInputValid(), m_edtL1HR.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L1HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1SpecialSeconds.IsInputValid(), m_edtL1SpecialSeconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L1SPECTIME);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Seconds.IsInputValid(), m_edtL2Seconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L2TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Dist.IsInputValid(), m_edtL2Dist.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L2DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Temp.IsInputValid(), m_edtL2Temp.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L2TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2HR.IsInputValid(), m_edtL2HR.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L2HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2SpecialSeconds.IsInputValid(), m_edtL2SpecialSeconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L2SPECTIME);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Seconds.IsInputValid(), m_edtL3Seconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L3TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Dist.IsInputValid(), m_edtL3Dist.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L3DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Temp.IsInputValid(), m_edtL3Temp.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L3TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3HR.IsInputValid(), m_edtL3HR.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L3HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3SpecialSeconds.IsInputValid(), m_edtL3SpecialSeconds.IsInputEmpty(), SPORT_RACEDU, RACEDUFIELD_L3SPECTIME);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRaceWorkoutDuathlonDlg::UpdatePR(void)
{
    bool fOK;
    CCourseDuathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((fOK) && (NULL != pCourse))
    {
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_OVERALLPR);
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetTransition1PRSeconds(), IDC_TRANSITIONPR1);
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetTransition2PRSeconds(), IDC_TRANSITIONPR2);
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg1PRSeconds(), IDC_L1PR);
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg2PRSeconds(), IDC_L2PR);
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg3PRSeconds(), IDC_L3PR);
    }
}


void CRaceWorkoutDuathlonDlg::OnUpdatePaces(void)
{
    bool fOK;

    CCourseDuathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if(NULL == pCourse)
    {
        return;
    }

    CString strDist;
    double dLeg1Length = pCourse->GetLeg1Length();
    double dLeg2Length = pCourse->GetLeg2Length();
    double dLeg3Length = pCourse->GetLeg3Length();

    strDist.Format("%.2lf", dLeg1Length);
    SetDlgItemText(IDC_L1RACEDISTANCE, strDist);

    strDist.Format("%.2lf", dLeg2Length);
    SetDlgItemText(IDC_L2RACEDISTANCE, strDist);

    strDist.Format("%.2lf", dLeg3Length);
    SetDlgItemText(IDC_L3RACEDISTANCE, strDist);

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1Seconds.GetValue(false), m_edtL1Dist.GetValue(false), IDC_L1PACE, FORMAT_RUN);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1SpecialSeconds.GetValue(false), dLeg1Length, IDC_L1RACEPACE, FORMAT_RUN);

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2Seconds.GetValue(false), m_edtL2Dist.GetValue(false), IDC_L2PACE, FORMAT_BIKE);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2SpecialSeconds.GetValue(false), dLeg2Length, IDC_L2RACEPACE, FORMAT_BIKE);

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3Seconds.GetValue(false), m_edtL3Dist.GetValue(false), IDC_L3PACE, FORMAT_RUN);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3SpecialSeconds.GetValue(false), dLeg3Length, IDC_L3RACEPACE, FORMAT_RUN);

    UpdatePR();
}


CCourseDuathlon* CRaceWorkoutDuathlonDlg::GetCourseDuathlon(void) const
{
    return m_pCourse;
}


CBike* CRaceWorkoutDuathlonDlg::GetBike(void) const
{
    return m_pBike;
}


double CRaceWorkoutDuathlonDlg::GetOverallSeconds(void) const
{
    return m_dOverallSeconds;
}


CString CRaceWorkoutDuathlonDlg::GetDisplayName(void) const
{
    return m_strDisplay;
}


bool CRaceWorkoutDuathlonDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRaceWorkoutDuathlonDlg::GetNotes(void) const
{
    return m_strNotes;
}


int CRaceWorkoutDuathlonDlg::GetRacePosition(void) const
{
    return m_nPlace;
}


int CRaceWorkoutDuathlonDlg::GetRaceNumber(void) const
{
    return m_nRaceNumber;
}


double CRaceWorkoutDuathlonDlg::GetTransition1Seconds(void) const
{
    return m_dTransition1Seconds;
}


double CRaceWorkoutDuathlonDlg::GetTransition2Seconds(void) const
{
    return m_dTransition2Seconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg1Seconds(void) const
{
    return m_dLeg1Seconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg2Seconds(void) const
{
    return m_dLeg2Seconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg3Seconds(void) const
{
    return m_dLeg3Seconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg1Miles(void) const
{
    return m_dLeg1Miles;
}


double CRaceWorkoutDuathlonDlg::GetLeg2Miles(void) const
{
    return m_dLeg2Miles;
}


double CRaceWorkoutDuathlonDlg::GetLeg3Miles(void) const
{
    return m_dLeg3Miles;
}


int CRaceWorkoutDuathlonDlg::GetLeg1Temperature(void) const
{
    return m_nLeg1Temp;
}


int CRaceWorkoutDuathlonDlg::GetLeg2Temperature(void) const
{
    return m_nLeg2Temp;
}


int CRaceWorkoutDuathlonDlg::GetLeg3Temperature(void) const
{
    return m_nLeg3Temp;
}


int CRaceWorkoutDuathlonDlg::GetLeg1Wind(void) const
{
    return m_nLeg1Wind;
}


int CRaceWorkoutDuathlonDlg::GetLeg2Wind(void) const
{
    return m_nLeg2Wind;
}


int CRaceWorkoutDuathlonDlg::GetLeg3Wind(void) const
{
    return m_nLeg3Wind;
}


int CRaceWorkoutDuathlonDlg::GetLeg1HR(void) const
{
    return m_nLeg1HR;
}


int CRaceWorkoutDuathlonDlg::GetLeg2HR(void) const
{
    return m_nLeg2HR;
}


int CRaceWorkoutDuathlonDlg::GetLeg3HR(void) const
{
    return m_nLeg3HR;
}


CShoesRun* CRaceWorkoutDuathlonDlg::GetLeg1Shoes(void) const
{
    return m_pLeg1Shoes;
}


CShoesBike* CRaceWorkoutDuathlonDlg::GetLeg2Shoes(void) const
{
    return m_pLeg2Shoes;
}


CShoesRun* CRaceWorkoutDuathlonDlg::GetLeg3Shoes(void) const
{
    return m_pLeg3Shoes;
}


double CRaceWorkoutDuathlonDlg::GetLeg1RaceSeconds(void) const
{
    return m_dLeg1RaceSeconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg2RaceSeconds(void) const
{
    return m_dLeg2RaceSeconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg3RaceSeconds(void) const
{
    return m_dLeg3RaceSeconds;
}


double CRaceWorkoutDuathlonDlg::GetLeg1RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg1Length();
    }
}


double CRaceWorkoutDuathlonDlg::GetLeg2RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg2Length();
    }
}


double CRaceWorkoutDuathlonDlg::GetLeg3RaceMiles(void) const
{
    CCourseDuathlon* pCourse = GetCourseDuathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg3Length();
    }
}


CShoesRun* CRaceWorkoutDuathlonDlg::GetLeg1RaceShoes(void) const
{
    return m_pLeg1RaceShoes;
}


CShoesBike* CRaceWorkoutDuathlonDlg::GetLeg2RaceShoes(void) const
{
    return m_pLeg2RaceShoes;
}


CShoesRun* CRaceWorkoutDuathlonDlg::GetLeg3RaceShoes(void) const
{
    return m_pLeg3RaceShoes;
}


void CRaceWorkoutDuathlonDlg::SetCourseDuathlon(CCourseDuathlon* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceWorkoutDuathlonDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceWorkoutDuathlonDlg::SetOverallSeconds(double dSec)
{
    m_dOverallSeconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetDisplayName(CString strName)
{
    m_strDisplay = strName;
}


void CRaceWorkoutDuathlonDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRaceWorkoutDuathlonDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRaceWorkoutDuathlonDlg::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CRaceWorkoutDuathlonDlg::SetRaceNumber(int nNum)
{
    m_nRaceNumber = nNum;
}


void CRaceWorkoutDuathlonDlg::SetTransition1Seconds(double dSec)
{
    m_dTransition1Seconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetTransition2Seconds(double dSec)
{
    m_dTransition2Seconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg1Seconds(double dSec)
{
    m_dLeg1Seconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg2Seconds(double dSec)
{
    m_dLeg2Seconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg3Seconds(double dSec)
{
    m_dLeg3Seconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg1Miles(double dMiles)
{
    m_dLeg1Miles = dMiles;
}


void CRaceWorkoutDuathlonDlg::SetLeg2Miles(double dMiles)
{
    m_dLeg2Miles = dMiles;
}


void CRaceWorkoutDuathlonDlg::SetLeg3Miles(double dMiles)
{
    m_dLeg3Miles = dMiles;
}


void CRaceWorkoutDuathlonDlg::SetLeg1Temperature(int nTemp)
{
    m_nLeg1Temp = nTemp;
}


void CRaceWorkoutDuathlonDlg::SetLeg2Temperature(int nTemp)
{
    m_nLeg2Temp = nTemp;
}


void CRaceWorkoutDuathlonDlg::SetLeg3Temperature(int nTemp)
{
    m_nLeg3Temp = nTemp;
}


void CRaceWorkoutDuathlonDlg::SetLeg1Wind(int nWind)
{
    m_nLeg1Wind = nWind;
}


void CRaceWorkoutDuathlonDlg::SetLeg2Wind(int nWind)
{
    m_nLeg2Wind = nWind;
}


void CRaceWorkoutDuathlonDlg::SetLeg3Wind(int nWind)
{
    m_nLeg3Wind = nWind;
}


void CRaceWorkoutDuathlonDlg::SetLeg1HR(int nHR)
{
    m_nLeg1HR = nHR;
}


void CRaceWorkoutDuathlonDlg::SetLeg2HR(int nHR)
{
    m_nLeg2HR = nHR;
}


void CRaceWorkoutDuathlonDlg::SetLeg3HR(int nHR)
{
    m_nLeg3HR = nHR;
}


void CRaceWorkoutDuathlonDlg::SetLeg1Shoes(CShoesRun* pShoes)
{
    m_pLeg1Shoes = pShoes;
}


void CRaceWorkoutDuathlonDlg::SetLeg2Shoes(CShoesBike* pShoes)
{
    m_pLeg2Shoes = pShoes;
}


void CRaceWorkoutDuathlonDlg::SetLeg3Shoes(CShoesRun* pShoes)
{
    m_pLeg3Shoes = pShoes;
}


void CRaceWorkoutDuathlonDlg::SetLeg1RaceSeconds(double dSec)
{
    m_dLeg1RaceSeconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg2RaceSeconds(double dSec)
{
    m_dLeg2RaceSeconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg3RaceSeconds(double dSec)
{
    m_dLeg3RaceSeconds = dSec;
}


void CRaceWorkoutDuathlonDlg::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutDuathlonDlg::SetLeg1RaceMiles called");
}


void CRaceWorkoutDuathlonDlg::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutDuathlonDlg::SetLeg2RaceMiles called");
}


void CRaceWorkoutDuathlonDlg::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutDuathlonDlg::SetLeg3RaceMiles called");
}


void CRaceWorkoutDuathlonDlg::SetLeg1RaceShoes(CShoesRun* pShoes)
{
    m_pLeg1RaceShoes = pShoes;
}


void CRaceWorkoutDuathlonDlg::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    m_pLeg2RaceShoes = pShoes;
}


void CRaceWorkoutDuathlonDlg::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    m_pLeg3RaceShoes = pShoes;
}