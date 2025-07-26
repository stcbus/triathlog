#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RaceWorkoutTriathlonDlg.h"


IMPLEMENT_DYNAMIC(CRaceWorkoutTriathlonDlg, CDialog)


BEGIN_MESSAGE_MAP(CRaceWorkoutTriathlonDlg, CDialog)
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


CRaceWorkoutTriathlonDlg::CRaceWorkoutTriathlonDlg(COURSETRIATHLONARRAY& rarCourses, SHOESRUNARRAY& rarShoesRun, 
                                                 SHOESBIKEARRAY& rarShoesBike, BIKEARRAY& rarBikes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRaceWorkoutTriathlonDlg::IDD, pParent), 
                m_rarCourses(rarCourses), 
                m_rarShoesRun(rarShoesRun),
                m_rarShoesBike(rarShoesBike),
                m_rarBikes(rarBikes)
{
}


CRaceWorkoutTriathlonDlg::~CRaceWorkoutTriathlonDlg()
{
}


BOOL CRaceWorkoutTriathlonDlg::OnInitDialog(void)
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

    SetDlgItemText(IDT_L1DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_L1PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_L1TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_L1SPECIALDIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_L1SPECIALPACE, CUtil::GetPaceString(FORMAT_SWIM));
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

    SetDlgItemText(IDC_DISPLAYNAME, "Triathlon");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2SPECSHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, true, false, true, SPORT_RACETRI, RACETRIFIELD_L3SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACETRI, RACETRIFIELD_L3SPECSHOES);
    CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_L1CHOPPINESS), false);
    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L2WIND), false);
    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L3WIND), false);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2BIKE);

    OnUpdateOKButton();
    UpdatePR();

    return TRUE;
}


void CRaceWorkoutTriathlonDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesBike* pShoes2 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, false, fOK);
        CShoesBike* pSpecShoes2 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, false, fOK);
        CShoesRun* pShoes3 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, false, fOK);
        CShoesRun* pSpecShoes3 = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, false, fOK);
        CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
        CBike* pBike = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, false, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, true, false, true, SPORT_RACETRI, RACETRIFIELD_L3SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, true, false, true, SPORT_RACETRI, RACETRIFIELD_L3SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, true, false, true, SPORT_RACETRI, RACETRIFIELD_L2BIKE);

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


void CRaceWorkoutTriathlonDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRaceWorkoutTriathlonDlg::OnOK(void)
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

    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLeg1Choppiness(CDlgHelper::GetComboSelChoppiness((CComboBox*)GetDlgItem(IDC_L1CHOPPINESS), fOK));

    SetLeg2Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L2WIND), fOK));
    SetLeg2Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), m_rarShoesBike, false, fOK));
    SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), m_rarBikes, false, fOK));
    SetLeg2RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), m_rarShoesBike, false, fOK));

    SetLeg3Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L3WIND), fOK));
    SetLeg3Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), m_rarShoesRun, false, fOK));
    SetLeg3RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), m_rarShoesRun, false, fOK));

    SetCourseTriathlon(pCourse);

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


void CRaceWorkoutTriathlonDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtOverallSeconds.IsInputValid(), m_edtOverallSeconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_OVERALLTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans1Seconds.IsInputValid(), m_edtTrans1Seconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_TRANS);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTrans2Seconds.IsInputValid(), m_edtTrans2Seconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_TRANS);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPlace.IsInputValid(), m_edtPlace.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_PLACE);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtRaceNumber.IsInputValid(), m_edtRaceNumber.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_RACENUM);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Seconds.IsInputValid(), m_edtL1Seconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L1TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Dist.IsInputValid(), m_edtL1Dist.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L1DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1Temp.IsInputValid(), m_edtL1Temp.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L1TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1HR.IsInputValid(), m_edtL1HR.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L1HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL1SpecialSeconds.IsInputValid(), m_edtL1SpecialSeconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L1SPECTIME);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Seconds.IsInputValid(), m_edtL2Seconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L2TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Dist.IsInputValid(), m_edtL2Dist.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L2DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2Temp.IsInputValid(), m_edtL2Temp.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L2TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2HR.IsInputValid(), m_edtL2HR.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L2HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL2SpecialSeconds.IsInputValid(), m_edtL2SpecialSeconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L2SPECTIME);

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Seconds.IsInputValid(), m_edtL3Seconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L3TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Dist.IsInputValid(), m_edtL3Dist.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L3DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3Temp.IsInputValid(), m_edtL3Temp.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L3TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3HR.IsInputValid(), m_edtL3HR.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L3HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtL3SpecialSeconds.IsInputValid(), m_edtL3SpecialSeconds.IsInputEmpty(), SPORT_RACETRI, RACETRIFIELD_L3SPECTIME);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRaceWorkoutTriathlonDlg::UpdatePR(void)
{
    bool fOK;
    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
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

void CRaceWorkoutTriathlonDlg::OnUpdatePaces(void)
{
    bool fOK;

    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
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

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1Seconds.GetValue(false), m_edtL1Dist.GetValue(false), IDC_L1PACE, FORMAT_SWIM);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL1SpecialSeconds.GetValue(false), dLeg1Length, IDC_L1RACEPACE, FORMAT_SWIM);

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2Seconds.GetValue(false), m_edtL2Dist.GetValue(false), IDC_L2PACE, FORMAT_BIKE);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL2SpecialSeconds.GetValue(false), dLeg2Length, IDC_L2RACEPACE, FORMAT_BIKE);

	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3Seconds.GetValue(false), m_edtL3Dist.GetValue(false), IDC_L3PACE, FORMAT_RUN);
	CDlgHelper::HandleDlgPaceOneTime(this, m_edtL3SpecialSeconds.GetValue(false), dLeg3Length, IDC_L3RACEPACE, FORMAT_RUN);

    UpdatePR();
}


CCourseTriathlon* CRaceWorkoutTriathlonDlg::GetCourseTriathlon(void) const
{
    return m_pCourse;
}


CBike* CRaceWorkoutTriathlonDlg::GetBike(void) const
{
    return m_pBike;
}


double CRaceWorkoutTriathlonDlg::GetOverallSeconds(void) const
{
    return m_dOverallSeconds;
}


CString CRaceWorkoutTriathlonDlg::GetDisplayName(void) const
{
    return m_strDisplay;
}


bool CRaceWorkoutTriathlonDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRaceWorkoutTriathlonDlg::GetNotes(void) const
{
    return m_strNotes;
}


int CRaceWorkoutTriathlonDlg::GetRacePosition(void) const
{
    return m_nPlace;
}


int CRaceWorkoutTriathlonDlg::GetRaceNumber(void) const
{
    return m_nRaceNumber;
}


double CRaceWorkoutTriathlonDlg::GetTransition1Seconds(void) const
{
    return m_dTransition1Seconds;
}


double CRaceWorkoutTriathlonDlg::GetTransition2Seconds(void) const
{
    return m_dTransition2Seconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg1Seconds(void) const
{
    return m_dLeg1Seconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg2Seconds(void) const
{
    return m_dLeg2Seconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg3Seconds(void) const
{
    return m_dLeg3Seconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg1Miles(void) const
{
    return m_dLeg1Miles;
}


double CRaceWorkoutTriathlonDlg::GetLeg2Miles(void) const
{
    return m_dLeg2Miles;
}


double CRaceWorkoutTriathlonDlg::GetLeg3Miles(void) const
{
    return m_dLeg3Miles;
}


int CRaceWorkoutTriathlonDlg::GetLeg1Temperature(void) const
{
    return m_nLeg1Temp;
}


int CRaceWorkoutTriathlonDlg::GetLeg2Temperature(void) const
{
    return m_nLeg2Temp;
}


int CRaceWorkoutTriathlonDlg::GetLeg3Temperature(void) const
{
    return m_nLeg3Temp;
}


int CRaceWorkoutTriathlonDlg::GetLeg1Choppiness(void) const
{
    return m_nLeg1Choppiness;
}


int CRaceWorkoutTriathlonDlg::GetLeg2Wind(void) const
{
    return m_nLeg2Wind;
}


int CRaceWorkoutTriathlonDlg::GetLeg3Wind(void) const
{
    return m_nLeg3Wind;
}


int CRaceWorkoutTriathlonDlg::GetLeg1HR(void) const
{
    return m_nLeg1HR;
}


int CRaceWorkoutTriathlonDlg::GetLeg2HR(void) const
{
    return m_nLeg2HR;
}


int CRaceWorkoutTriathlonDlg::GetLeg3HR(void) const
{
    return m_nLeg3HR;
}


CShoesBike* CRaceWorkoutTriathlonDlg::GetLeg2Shoes(void) const
{
    return m_pLeg2Shoes;
}


CShoesRun* CRaceWorkoutTriathlonDlg::GetLeg3Shoes(void) const
{
    return m_pLeg3Shoes;
}


double CRaceWorkoutTriathlonDlg::GetLeg1RaceSeconds(void) const
{
    return m_dLeg1RaceSeconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg2RaceSeconds(void) const
{
    return m_dLeg2RaceSeconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg3RaceSeconds(void) const
{
    return m_dLeg3RaceSeconds;
}


double CRaceWorkoutTriathlonDlg::GetLeg1RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg1Length();
    }
}


double CRaceWorkoutTriathlonDlg::GetLeg2RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg2Length();
    }
}


double CRaceWorkoutTriathlonDlg::GetLeg3RaceMiles(void) const
{
    CCourseTriathlon* pCourse = GetCourseTriathlon();
    if(NULL == pCourse)
    {
        return 0.0;
    }
    else
    {
        return pCourse->GetLeg3Length();
    }
}


CShoesBike* CRaceWorkoutTriathlonDlg::GetLeg2RaceShoes(void) const
{
    return m_pLeg2RaceShoes;
}


CShoesRun* CRaceWorkoutTriathlonDlg::GetLeg3RaceShoes(void) const
{
    return m_pLeg3RaceShoes;
}


void CRaceWorkoutTriathlonDlg::SetCourseTriathlon(CCourseTriathlon* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceWorkoutTriathlonDlg::SetBike(CBike* pBike)
{
    m_pBike = pBike;
}


void CRaceWorkoutTriathlonDlg::SetOverallSeconds(double dSec)
{
    m_dOverallSeconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetDisplayName(CString strName)
{
    m_strDisplay = strName;
}


void CRaceWorkoutTriathlonDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRaceWorkoutTriathlonDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRaceWorkoutTriathlonDlg::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CRaceWorkoutTriathlonDlg::SetRaceNumber(int nNum)
{
    m_nRaceNumber = nNum;
}


void CRaceWorkoutTriathlonDlg::SetTransition1Seconds(double dSec)
{
    m_dTransition1Seconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetTransition2Seconds(double dSec)
{
    m_dTransition2Seconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg1Seconds(double dSec)
{
    m_dLeg1Seconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg2Seconds(double dSec)
{
    m_dLeg2Seconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg3Seconds(double dSec)
{
    m_dLeg3Seconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg1Miles(double dMiles)
{
    m_dLeg1Miles = dMiles;
}


void CRaceWorkoutTriathlonDlg::SetLeg2Miles(double dMiles)
{
    m_dLeg2Miles = dMiles;
}


void CRaceWorkoutTriathlonDlg::SetLeg3Miles(double dMiles)
{
    m_dLeg3Miles = dMiles;
}


void CRaceWorkoutTriathlonDlg::SetLeg1Temperature(int nTemp)
{
    m_nLeg1Temp = nTemp;
}


void CRaceWorkoutTriathlonDlg::SetLeg2Temperature(int nTemp)
{
    m_nLeg2Temp = nTemp;
}


void CRaceWorkoutTriathlonDlg::SetLeg3Temperature(int nTemp)
{
    m_nLeg3Temp = nTemp;
}


void CRaceWorkoutTriathlonDlg::SetLeg1Choppiness(int nAmount)
{
    m_nLeg1Choppiness = nAmount;
}


void CRaceWorkoutTriathlonDlg::SetLeg2Wind(int nWind)
{
    m_nLeg2Wind = nWind;
}


void CRaceWorkoutTriathlonDlg::SetLeg3Wind(int nWind)
{
    m_nLeg3Wind = nWind;
}


void CRaceWorkoutTriathlonDlg::SetLeg1HR(int nHR)
{
    m_nLeg1HR = nHR;
}


void CRaceWorkoutTriathlonDlg::SetLeg2HR(int nHR)
{
    m_nLeg2HR = nHR;
}


void CRaceWorkoutTriathlonDlg::SetLeg3HR(int nHR)
{
    m_nLeg3HR = nHR;
}


void CRaceWorkoutTriathlonDlg::SetLeg2Shoes(CShoesBike* pShoes)
{
    m_pLeg2Shoes = pShoes;
}


void CRaceWorkoutTriathlonDlg::SetLeg3Shoes(CShoesRun* pShoes)
{
    m_pLeg3Shoes = pShoes;
}


void CRaceWorkoutTriathlonDlg::SetLeg1RaceSeconds(double dSec)
{
    m_dLeg1RaceSeconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg2RaceSeconds(double dSec)
{
    m_dLeg2RaceSeconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg3RaceSeconds(double dSec)
{
    m_dLeg3RaceSeconds = dSec;
}


void CRaceWorkoutTriathlonDlg::SetLeg1RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutTriathlonDlg::SetLeg1RaceMiles called");
}


void CRaceWorkoutTriathlonDlg::SetLeg2RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutTriathlonDlg::SetLeg2RaceMiles called");
}


void CRaceWorkoutTriathlonDlg::SetLeg3RaceMiles(double dMiles)
{
    CUtil::Fatal("CRaceWorkoutTriathlonDlg::SetLeg3RaceMiles called");
}


void CRaceWorkoutTriathlonDlg::SetLeg2RaceShoes(CShoesBike* pShoes)
{
    m_pLeg2RaceShoes = pShoes;
}


void CRaceWorkoutTriathlonDlg::SetLeg3RaceShoes(CShoesRun* pShoes)
{
    m_pLeg3RaceShoes = pShoes;
}