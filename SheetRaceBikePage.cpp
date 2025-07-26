#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "SheetTriathLogPage.h"
#include "DaySummarySheet.h"
#include "SheetRaceBikePage.h"


BEGIN_MESSAGE_MAP(CSheetRaceBikePage, CSheetTriathLogPage)
    ON_CBN_SELCHANGE(IDC_COURSE, OnUpdatePaces)

    ON_EN_CHANGE(IDC_STARTTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PREVNIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_WEIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TIMERACE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PLACE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_RACENUMBER, OnUpdateOKButton)
END_MESSAGE_MAP()


CSheetRaceBikePage::CSheetRaceBikePage(void) : CSheetTriathLogPage(CSheetRaceBikePage::IDD)
{
}


BOOL CSheetRaceBikePage::OnInitDialog(void)
{
    CSheetTriathLogPage::OnInitDialog();

	m_edtTime.SubclassDlgItem(IDC_STARTTIME, this);
	m_edtWeight.SubclassDlgItem(IDC_WEIGHT, this);
	m_edtDataFile.SubclassDlgItem(IDC_DATAFILE, this);
	m_edtSleep.SubclassDlgItem(IDC_PREVNIGHT, this);
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

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_RACEBIKE, RACEBIKEFIELD_SHOES);
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_RACESHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_RACEBIKE, RACEBIKEFIELD_SPECSHOES);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, true, true, SPORT_RACEBIKE, RACEBIKEFIELD_BIKE);

        CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), true, true);
    }

    InitDialogValues();

    OnUpdatePaces();

    return TRUE;
}


bool CSheetRaceBikePage::IsChangeAllowed(void)
{
    return true;
}


bool CSheetRaceBikePage::WriteContents(void)
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

    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return false;
    }

    if(!BaseWriteContents())
    {
        return false;
    }

    CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), fOK);

    pWorkout->SetSeconds(m_edtSeconds.GetValue());
	pWorkout->SetSpecialSeconds(m_edtSpecialSeconds.GetValue());
    pWorkout->SetMiles(m_edtDist.GetValue());
    pWorkout->SetTemperature(m_edtTemp.GetValue());
    pWorkout->SetHR(m_edtHR.GetValue());
    pWorkout->SetNotes(m_edtNotes.GetValue());
    pWorkout->SetDisplayName(m_edtDisp.GetValue());
	pWorkout->SetRacePosition(m_edtPlace.GetValue());
	pWorkout->SetRaceNumber(m_edtRaceNumber.GetValue());

    pWorkout->SetShoesBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, fOK));
    pWorkout->SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, fOK));
    pWorkout->SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    pWorkout->SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    pWorkout->SetSpecialShoesBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), pUser->GetRefShoesBikeArray(), true, fOK));
    pWorkout->SetCourseBike(pCourse);

    pUser->RecalcPRs(pCourse);
    return true;
}


void CSheetRaceBikePage::InitDialogValues(void)
{
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return;
    }

	BaseInitDialogValues();

    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, pWorkout->GetBike());
    CDlgHelper::SetDlgOneString(this, IDC_DISPLAYNAME, pWorkout->GetDisplayName());
    CDlgHelper::SetDlgOneTime(this, IDC_TIMEOVERALL, pWorkout->GetSeconds());
	CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), pUser->GetBikeDecimals());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), pWorkout->GetCourseBike());
    CDlgHelper::SetDlgOneInt(this, IDC_TEMPERATURE, pWorkout->GetTemperature());
    CDlgHelper::SetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), pWorkout->GetWind());
    CDlgHelper::SetDlgOneInt(this, IDC_HEARTRATE, pWorkout->GetHR());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetShoesBike());
    CDlgHelper::SetDlgOneTime(this, IDC_TIMERACE, pWorkout->GetSpecialSeconds());
    
    CString str;
    str.Format("%.2lf", pWorkout->GetCourseBike()->GetLength());
    CDlgHelper::SetDlgOneString(this, IDC_RACEDISTANCE, str);

    CDlgHelper::SetDlgOneInt(this, IDC_PLACE, pWorkout->GetRacePosition());
    CDlgHelper::SetDlgOneInt(this, IDC_RACENUMBER, pWorkout->GetRaceNumber());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetSpecialShoesBike());
  
    if(pWorkout->IsLong())
    {
        CheckDlgButton(IDC_LONG, BST_CHECKED);
    }

    CDlgHelper::SetDlgOneString(this, IDC_NOTES, pWorkout->GetNotes());
}


void CSheetRaceBikePage::OnUpdateOKButton(void)
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
    
    CDaySummarySheet* pParent = GetParentSheet();
    if(NULL != pParent)
    {
        pParent->UpdateOK(fEnable);
    }

    OnUpdatePaces();
}


void CSheetRaceBikePage::OnUpdatePaces(void)
{
    bool fOK;
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    if((NULL == pUser) || (NULL == pWorkout))
    {
        return;
    }

    CCourseBike* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), pUser->GetRefCourseBikeArray(), fOK);
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
	CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
}