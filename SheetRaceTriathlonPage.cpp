#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "SheetTriathLogPage.h"
#include "DaySummarySheet.h"
#include "SheetRaceTriathlonPage.h"


BEGIN_MESSAGE_MAP(CSheetRaceTriathlonPage, CSheetTriathLogPage)
    ON_CBN_SELCHANGE(IDC_COURSE, OnUpdatePaces)

    ON_EN_CHANGE(IDC_STARTTIME3, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PREVNIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_WEIGHT2, OnUpdateOKButton)

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
END_MESSAGE_MAP()


CSheetRaceTriathlonPage::CSheetRaceTriathlonPage(void) : CSheetTriathLogPage(CSheetRaceTriathlonPage::IDD)
{
}


BOOL CSheetRaceTriathlonPage::OnInitDialog(void)
{
    CSheetTriathLogPage::OnInitDialog();

	m_edtTime.SubclassDlgItem(IDC_STARTTIME3, this);
	m_edtWeight.SubclassDlgItem(IDC_WEIGHT2, this);
	m_edtDataFile.SubclassDlgItem(IDC_DATAFILE2, this);
	m_edtSleep.SubclassDlgItem(IDC_PREVNIGHT, this);
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

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2SHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_RACETRI, RACETRIFIELD_L2SHOES);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACESHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_RACETRI, RACETRIFIELD_L2SPECSHOES);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3SHOES), pUser->GetRefShoesRunArray(), true, true, true, SPORT_RACETRI, RACETRIFIELD_L3SHOES);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L3RACESHOES), pUser->GetRefShoesRunArray(), true, true, true, SPORT_RACETRI, RACETRIFIELD_L3SPECSHOES);
        CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_L1CHOPPINESS), false);
        CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L2WIND), false);
        CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_L3WIND), false);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseTriathlonArray(), true, true);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), pUser->GetRefBikeArray(), true, true, true, SPORT_RACETRI, RACETRIFIELD_L2BIKE);
    }

    InitDialogValues();

    OnUpdatePaces();

    return TRUE;
}


bool CSheetRaceTriathlonPage::IsChangeAllowed(void)
{
    return true;
}


bool CSheetRaceTriathlonPage::WriteContents(void)
{
    if(!::IsWindow(m_hWnd))
    {
        // if we haven't been initialized, we couldn't have been changed yet
        return true;
    }

    if(!IsChangeAllowed())
    {
        return false;
    }

    bool fOK;

    CRaceTriathlonWorkout* pWorkout = dynamic_cast<CRaceTriathlonWorkout*>(GetWorkout());
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return false;
    }

    if(!BaseWriteContents(true))
    {
        return false;
    }

	double dOverallSec = m_edtOverallSeconds.GetValue();
	double dTransition1Sec = m_edtTrans1Seconds.GetValue();
	double dTransition2Sec = m_edtTrans2Seconds.GetValue();
	double dLeg1RaceSeconds = m_edtL1SpecialSeconds.GetValue();
	double dLeg2RaceSeconds = m_edtL2SpecialSeconds.GetValue();
	double dLeg3RaceSeconds = m_edtL3SpecialSeconds.GetValue();
    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseTriathlonArray(), fOK);

    pWorkout->SetSeconds(dOverallSec);
	pWorkout->SetTransition1Seconds(dTransition1Sec);
	pWorkout->SetTransition2Seconds(dTransition2Sec);
    pWorkout->SetNotes(m_edtNotes.GetValue());
    pWorkout->SetDisplayName(m_edtDisp.GetValue());
	pWorkout->SetRacePosition(m_edtPlace.GetValue());
	pWorkout->SetRaceNumber(m_edtRaceNumber.GetValue());

	pWorkout->SetLeg1Seconds(m_edtL1Seconds.GetValue());
    pWorkout->SetLeg1Miles(m_edtL1Dist.GetValue());
	pWorkout->SetLeg1Temperature(m_edtL1Temp.GetValue());
	pWorkout->SetLeg1HR(m_edtL1HR.GetValue());
	pWorkout->SetLeg1RaceSeconds(dLeg1RaceSeconds);

	pWorkout->SetLeg2Seconds(m_edtL2Seconds.GetValue());
    pWorkout->SetLeg2Miles(m_edtL2Dist.GetValue());
	pWorkout->SetLeg2Temperature(m_edtL2Temp.GetValue());
	pWorkout->SetLeg2HR(m_edtL2HR.GetValue());
	pWorkout->SetLeg2RaceSeconds(dLeg2RaceSeconds);

	pWorkout->SetLeg3Seconds(m_edtL3Seconds.GetValue());
    pWorkout->SetLeg3Miles(m_edtL3Dist.GetValue());
	pWorkout->SetLeg3Temperature(m_edtL3Temp.GetValue());
	pWorkout->SetLeg3HR(m_edtL3HR.GetValue());
	pWorkout->SetLeg3RaceSeconds(dLeg3RaceSeconds);

    pWorkout->SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    pWorkout->SetChoppiness(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L1CHOPPINESS), fOK));

	pWorkout->SetLeg2Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L2WIND), fOK));
	pWorkout->SetLeg2Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), pUser->GetRefShoesBikeArray(), true, fOK));
	pWorkout->SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), pUser->GetRefBikeArray(), true, fOK));
	pWorkout->SetLeg2RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), pUser->GetRefShoesBikeArray(), true, fOK));

	pWorkout->SetLeg3Wind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_L3WIND), fOK));
	pWorkout->SetLeg3Shoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), pUser->GetRefShoesRunArray(), true, fOK));
    pWorkout->SetLeg3RaceShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), pUser->GetRefShoesRunArray(), true, fOK));
    pWorkout->SetCourseTriathlon(pCourse);

	pWorkout->SetOverallHR();
	pWorkout->SetOverallTemperature();

    pUser->RecalcPRs(pCourse);

    return true;
}


void CSheetRaceTriathlonPage::InitDialogValues(void)
{
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return;
    }

	BaseInitDialogValues(true);

    CDlgHelper::SetDlgOneString(this, IDC_DISPLAYNAME, pWorkout->GetDisplayName());
    CDlgHelper::SetDlgOneTime(this, IDC_OVERALLTIMERACE, pWorkout->GetSeconds());
    CDlgHelper::SetDlgOneTime(this, IDC_TRANSITION1, pWorkout->GetTransition1Seconds());
    CDlgHelper::SetDlgOneTime(this, IDC_TRANSITION2, pWorkout->GetTransition2Seconds());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseDuathlonArray(), pWorkout->GetCourseDuathlon());
    CDlgHelper::SetDlgOneInt(this, IDC_PLACE, pWorkout->GetRacePosition());
    CDlgHelper::SetDlgOneInt(this, IDC_RACENUMBER, pWorkout->GetRaceNumber());

    CDlgHelper::SetDlgOneTime(this, IDC_L1TIMEOVERALL, pWorkout->GetLeg1Seconds());
	CDlgHelper::SetDlgDouble(this, IDC_L1DISTANCE, pWorkout->GetLeg1Miles(), pUser->GetSwimDecimals());
    CDlgHelper::SetComboSelChoppiness((CComboBox*)GetDlgItem(IDC_L1CHOPPINESS), pWorkout->GetChoppiness());
    CDlgHelper::SetDlgOneInt(this, IDC_L1HEARTRATE, pWorkout->GetLeg1HR());
    CDlgHelper::SetDlgOneInt(this, IDC_L1TEMPERATURE, pWorkout->GetLeg1Temperature());
    CDlgHelper::SetDlgOneTime(this, IDC_L1TIMERACE, pWorkout->GetLeg1RaceSeconds());

    CDlgHelper::SetDlgOneTime(this, IDC_L2TIMEOVERALL, pWorkout->GetLeg2Seconds());
    CDlgHelper::SetDlgDouble(this, IDC_L2DISTANCE, pWorkout->GetLeg2Miles(), pUser->GetBikeDecimals());
    CDlgHelper::SetComboSelWind((CComboBox*)GetDlgItem(IDC_L2WIND), pWorkout->GetLeg2Wind());
    CDlgHelper::SetDlgOneInt(this, IDC_L2HEARTRATE, pWorkout->GetLeg2HR());
    CDlgHelper::SetDlgOneInt(this, IDC_L2TEMPERATURE, pWorkout->GetLeg2Temperature());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2SHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetLeg2Shoes());
    CDlgHelper::SetDlgOneTime(this, IDC_L2TIMERACE, pWorkout->GetLeg2RaceSeconds());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2RACESHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetLeg2RaceShoes());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L2RACEBIKE), pUser->GetRefBikeArray(), true, pWorkout->GetBike());

    CDlgHelper::SetDlgOneTime(this, IDC_L3TIMEOVERALL, pWorkout->GetLeg3Seconds());
    CDlgHelper::SetDlgDouble(this, IDC_L3DISTANCE, pWorkout->GetLeg3Miles(), pUser->GetRunDecimals());
    CDlgHelper::SetComboSelWind((CComboBox*)GetDlgItem(IDC_L3WIND), pWorkout->GetLeg3Wind());
    CDlgHelper::SetDlgOneInt(this, IDC_L3HEARTRATE, pWorkout->GetLeg3HR());
    CDlgHelper::SetDlgOneInt(this, IDC_L3TEMPERATURE, pWorkout->GetLeg3Temperature());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L3SHOES), pUser->GetRefShoesRunArray(), true, pWorkout->GetLeg3Shoes());
    CDlgHelper::SetDlgOneTime(this, IDC_L3TIMERACE, pWorkout->GetLeg3RaceSeconds());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_L3RACESHOES), pUser->GetRefShoesRunArray(), true, pWorkout->GetLeg3RaceShoes());

    if(pWorkout->IsLong())
    {
        CheckDlgButton(IDC_LONG, BST_CHECKED);
    }

    CDlgHelper::SetDlgOneString(this, IDC_NOTES, pWorkout->GetNotes());
}


void CSheetRaceTriathlonPage::OnUpdateOKButton(void)
{
    bool fEnable = true;

    fEnable &= BaseUpdateOKButton(true);

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

    CDaySummarySheet* pParent = GetParentSheet();
    if(NULL != pParent)
    {
        pParent->UpdateOK(fEnable);
    }

    OnUpdatePaces();
}


void CSheetRaceTriathlonPage::OnUpdatePaces(void)
{
    bool fOK;
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    if((NULL == pUser) || (NULL == pWorkout))
    {
        return;
    }

    CCourseTriathlon* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseTriathlonArray(), fOK);
    if((!fOK) || (NULL == pCourse))
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

	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_OVERALLPR);
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetTransition1PRSeconds(), IDC_TRANSITIONPR1);
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetTransition2PRSeconds(), IDC_TRANSITIONPR2);
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg1PRSeconds(), IDC_L1PR);
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg2PRSeconds(), IDC_L2PR);
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetLeg3PRSeconds(), IDC_L3PR);
}