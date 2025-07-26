#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "SheetTriathLogPage.h"
#include "DaySummarySheet.h"
#include "SheetBikeTimeTrialPage.h"


BEGIN_MESSAGE_MAP(CSheetBikeTimeTrialPage, CSheetTriathLogPage)
    ON_EN_CHANGE(IDC_STARTTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PREVNIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_WEIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_SPECIALTIME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_SPECIALDIST, OnUpdateOKButton)
END_MESSAGE_MAP()


CSheetBikeTimeTrialPage::CSheetBikeTimeTrialPage(void) : CSheetTriathLogPage(CSheetBikeTimeTrialPage::IDD)
{
}


BOOL CSheetBikeTimeTrialPage::OnInitDialog(void)
{
    CSheetTriathLogPage::OnInitDialog();

	m_edtTime.SubclassDlgItem(IDC_STARTTIME, this);
	m_edtWeight.SubclassDlgItem(IDC_WEIGHT, this);
	m_edtDataFile.SubclassDlgItem(IDC_DATAFILE, this);
	m_edtSleep.SubclassDlgItem(IDC_PREVNIGHT, this);
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

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_BIKE, BIKEFIELD_SHOES);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), pUser->GetRefShoesBikeArray(), true, true, true, SPORT_BIKE, BIKEFIELD_SPECSHOES);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, true, true, SPORT_BIKE, BIKEFIELD_BIKE);

        CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationBikeArray(), true, true);
    }

    InitDialogValues();

    OnUpdatePaces();

    return TRUE;
}


bool CSheetBikeTimeTrialPage::IsChangeAllowed(void)
{
    return true;
}


bool CSheetBikeTimeTrialPage::WriteContents(void)
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

    pWorkout->SetSeconds(m_edtSeconds.GetValue());
	pWorkout->SetSpecialSeconds(m_edtSpecialSeconds.GetValue());
    pWorkout->SetMiles(m_edtDist.GetValue());
	pWorkout->SetSpecialMiles(m_edtSpecialDist.GetValue());
    pWorkout->SetTemperature(m_edtTemp.GetValue());
    pWorkout->SetHR(m_edtHR.GetValue());
    pWorkout->SetNotes(m_edtNotes.GetValue());
    pWorkout->SetDisplayName(m_edtDisp.GetValue());

	pWorkout->SetShoesBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, fOK));
    pWorkout->SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
	pWorkout->SetBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, fOK));
    pWorkout->SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
	pWorkout->SetLocationBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationBikeArray(), fOK));
    pWorkout->SetSpecialShoesBike(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), pUser->GetRefShoesBikeArray(), true, fOK));

    return true;
}


void CSheetBikeTimeTrialPage::InitDialogValues(void)
{
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return;
    }

	BaseInitDialogValues();

    CDlgHelper::SetDlgOneString(this, IDC_DISPLAYNAME, pWorkout->GetDisplayName());
    CDlgHelper::SetDlgOneTime(this, IDC_TIMEOVERALL, pWorkout->GetSeconds());
	CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), pUser->GetBikeDecimals());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationBikeArray(), pWorkout->GetLocationBike());
    CDlgHelper::SetDlgOneInt(this, IDC_TEMPERATURE, pWorkout->GetTemperature());
    CDlgHelper::SetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), pWorkout->GetWind());
    CDlgHelper::SetDlgOneInt(this, IDC_HEARTRATE, pWorkout->GetHR());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetShoesBike());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), pUser->GetRefShoesBikeArray(), true, pWorkout->GetSpecialShoesBike());
    CDlgHelper::SetDlgOneTime(this, IDC_SPECIALTIME, pWorkout->GetSpecialSeconds());
	CDlgHelper::SetDlgDouble(this, IDC_SPECIALDIST, pWorkout->GetSpecialMiles(), pUser->GetBikeDecimals());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_BIKE), pUser->GetRefBikeArray(), true, pWorkout->GetBike());

    if(pWorkout->IsLong())
    {
        CheckDlgButton(IDC_LONG, BST_CHECKED);
    }

    CDlgHelper::SetDlgOneString(this, IDC_NOTES, pWorkout->GetNotes());
}


void CSheetBikeTimeTrialPage::OnUpdateOKButton(void)
{
    bool fEnable = true;

    fEnable &= BaseUpdateOKButton();
       
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialDist.IsInputValid(), m_edtSpecialDist.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_SPECDIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_BIKE, BIKEFIELD_HR);
    
    CDaySummarySheet* pParent = GetParentSheet();
    if(NULL != pParent)
    {
        pParent->UpdateOK(fEnable);
    }

    OnUpdatePaces();
}


void CSheetBikeTimeTrialPage::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_BIKE);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), m_edtSpecialDist.GetValue(false), IDC_SPECIALPACE, FORMAT_BIKE);
}