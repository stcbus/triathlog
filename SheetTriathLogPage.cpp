#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "DaySummarySheet.h"
#include "User.h"
#include "Workout.h"
#include "ConverterDlg.h"
#include "SheetTriathLogPage.h"


IMPLEMENT_DYNAMIC(CSheetTriathLogPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CSheetTriathLogPage, CPropertyPage)
	ON_BN_CLICKED(IDC_CONVERT, OnConvert)
	ON_BN_CLICKED(IDB_CHOOSEDATAFILE, OnChooseDataFile)
END_MESSAGE_MAP()


CSheetTriathLogPage::CSheetTriathLogPage(int nID) : CPropertyPage(nID)
{
}


BOOL CSheetTriathLogPage::OnInitDialog(void)
{
    BOOL bRet = CPropertyPage::OnInitDialog();

    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString("Weight"));
    
    return bRet;
}


bool CSheetTriathLogPage::BaseWriteContents(bool bIs2 /* = false */)
{
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return false;
    }

	COleDateTime tm = m_edtTime.GetValue();
	if(COleDateTime::valid != tm.GetStatus())
	{
		AfxMessageBox("Please enter a valid start time");
		return false;
	}

	pWorkout->SetTimeStart(tm);
    pWorkout->SetPrevNightSleep(m_edtSleep.GetValue());
    pWorkout->SetWeight(m_edtWeight.GetValue());
	pWorkout->SetDataFile(m_edtDataFile.GetValue());

    pWorkout->SetInjured(BST_CHECKED == IsDlgButtonChecked(IDC_INJURED));

    pWorkout->SetSick(BST_CHECKED == IsDlgButtonChecked(IDC_SICK));

    return true;
}


void CSheetTriathLogPage::BaseInitDialogValues(bool bIs2 /* = false */)
{
    CWorkout* pWorkout = GetWorkout();
    CUser* pUser = GetUser();
    CDayLog* pDay = GetParentSheet()->GetDay();
    if((NULL == pWorkout) || (NULL == pUser) || (NULL == pDay))
    {
        return;
    }

	int nIDStart = (true == bIs2 ? IDC_STARTTIME3 : IDC_STARTTIME);
	int nIDWeight = (true == bIs2 ? IDC_WEIGHT2 : IDC_WEIGHT);
	int nIDDataFile = (true == bIs2 ? IDC_DATAFILE2 : IDC_DATAFILE);

	CDlgHelper::SetDlgTimeStart(this, nIDStart, pWorkout->GetTimeStart());
	CDlgHelper::SetDlgDouble(this, nIDWeight, pWorkout->GetWeight(), 1);
	CDlgHelper::SetDlgTimeSleep(this, IDC_PREVNIGHT, pWorkout->GetPrevNightSleep());
	CDlgHelper::SetDlgOneString(this, nIDDataFile, pWorkout->GetDataFile());

    if(pWorkout->IsInjured())
    {
        CheckDlgButton(IDC_INJURED, BST_CHECKED);
    }

    if(pWorkout->IsSick())
    {
        CheckDlgButton(IDC_SICK, BST_CHECKED);
    }
}


bool CSheetTriathLogPage::BaseUpdateOKButton(bool bIs2 /* = false */)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTime.IsInputValid(), m_edtTime.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSleep.IsInputValid(), m_edtSleep.IsInputEmpty(), SPORT_START, STARTFIELD_SLEEP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtWeight.IsInputValid(), m_edtSleep.IsInputEmpty(), SPORT_START, STARTFIELD_WEIGHT);

    return fEnable;
}


void CSheetTriathLogPage::OnConvert(void)
{
	CConverterDlg dlg;
	dlg.DoModal();
}


void CSheetTriathLogPage::OnChooseDataFile(void)
{
	CString strFilter = "Polar HRM files (*.hrm)|*.hrm|All files (*.*)|*.*||";
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, strFilter, this);

	if(IDOK == dlg.DoModal())
	{
		m_edtDataFile.SetWindowText(dlg.GetPathName());
	}
}


CWorkout* CSheetTriathLogPage::GetWorkout(void) const
{
    return m_pWorkout;
}


void CSheetTriathLogPage::SetWorkout(CWorkout* pWorkout)
{
    m_pWorkout = pWorkout;
}


CDaySummarySheet* CSheetTriathLogPage::GetParentSheet(void) const
{
    return m_pParentSheet;
}


void CSheetTriathLogPage::SetParentSheet(CDaySummarySheet* pSheet)
{
    m_pParentSheet = pSheet;
}


CUser* CSheetTriathLogPage::GetUser(void) const
{
    return m_pUser;
}


void CSheetTriathLogPage::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}


CDayLog* CSheetTriathLogPage::GetDay(void) const
{
    CDaySummarySheet* pParent = GetParentSheet();
    CDayLog* pDay = NULL;
    if(NULL != pParent)
    {
        pDay = pParent->GetDay();
    }

    return pDay;
}


CString CSheetTriathLogPage::GetDataFilename(void)
{
	return m_edtDataFile.GetValue(false);
}