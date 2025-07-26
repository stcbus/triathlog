#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "SheetTriathLogPage.h"
#include "DaySummarySheet.h"
#include "SheetSwimEZPage.h"


BEGIN_MESSAGE_MAP(CSheetSwimEZPage, CSheetTriathLogPage)
    ON_EN_CHANGE(IDC_STARTTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_PREVNIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_WEIGHT, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
END_MESSAGE_MAP()


CSheetSwimEZPage::CSheetSwimEZPage(void) : CSheetTriathLogPage(CSheetSwimEZPage::IDD)
{
}


BOOL CSheetSwimEZPage::OnInitDialog(void)
{
    CSheetTriathLogPage::OnInitDialog();

	m_edtTime.SubclassDlgItem(IDC_STARTTIME, this);
	m_edtWeight.SubclassDlgItem(IDC_WEIGHT, this);
	m_edtDataFile.SubclassDlgItem(IDC_DATAFILE, this);
	m_edtSleep.SubclassDlgItem(IDC_PREVNIGHT, this);
	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), false);

        CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationSwimArray(), true, true);
    }

    InitDialogValues();

    OnUpdatePaces();

    return TRUE;
}


bool CSheetSwimEZPage::IsChangeAllowed(void)
{
    return true;
}


bool CSheetSwimEZPage::WriteContents(void)
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
    pWorkout->SetMiles(m_edtDist.GetValue());
    pWorkout->SetTemperature(m_edtTemp.GetValue());
    pWorkout->SetHR(m_edtHR.GetValue());
    pWorkout->SetNotes(m_edtNotes.GetValue());
    pWorkout->SetDisplayName(m_edtDisp.GetValue());

    pWorkout->SetChoppiness(CDlgHelper::GetComboSelChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), fOK));
    pWorkout->SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
	pWorkout->SetLocationSwim(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationSwimArray(), fOK));

    return true;
}


void CSheetSwimEZPage::InitDialogValues(void)
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
	CDlgHelper::SetDlgDouble(this, IDC_DISTANCE, pWorkout->GetMiles(), pUser->GetSwimDecimals());
    CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), pUser->GetRefLocationSwimArray(), pWorkout->GetLocationSwim());
    CDlgHelper::SetDlgOneInt(this, IDC_TEMPERATURE, pWorkout->GetTemperature());
    CDlgHelper::SetComboSelChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), pWorkout->GetChoppiness());
    CDlgHelper::SetDlgOneInt(this, IDC_HEARTRATE, pWorkout->GetHR());

    if(pWorkout->IsLong())
    {
        CheckDlgButton(IDC_LONG, BST_CHECKED);
    }

    CDlgHelper::SetDlgOneString(this, IDC_NOTES, pWorkout->GetNotes());
}


void CSheetSwimEZPage::OnUpdateOKButton(void)
{
    bool fEnable = true;

    fEnable &= BaseUpdateOKButton();

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_SWIM, SWIMFIELD_HR);

    CDaySummarySheet* pParent = GetParentSheet();
    if(NULL != pParent)
    {
        pParent->UpdateOK(fEnable);
    }

    OnUpdatePaces();
}


void CSheetSwimEZPage::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_SWIM);
}