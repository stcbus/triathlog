#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRaceBikeSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRaceBikeSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRaceBikeSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_COURSEMANDATORY2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECSHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_PLACEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RACENUMMANDATORY, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataRaceBikeSheet::COptionsDataRaceBikeSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRaceBikeSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRaceBikeSheet::~COptionsDataRaceBikeSheet()
{
}


BOOL COptionsDataRaceBikeSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RACEBIKEFIELD_COURSE))
    {
        CheckDlgButton(IDC_COURSEMANDATORY2, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_BIKE))
    {
        CheckDlgButton(IDC_BIKEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_SHOES))
    {
        CheckDlgButton(IDC_SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_SPECSHOES))
    {
        CheckDlgButton(IDC_SPECSHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_RACENUM))
    {
        CheckDlgButton(IDC_RACENUMMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEBIKEFIELD_PLACE))
    {
        CheckDlgButton(IDC_PLACEMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRaceBikeSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRaceBikeFields());
    }
}


bool COptionsDataRaceBikeSheet::WriteContents(void)
{
    if(!::IsWindow(m_hWnd))
    {
        // if we haven't been initialized, we couldn't have been changed yet
        return true;
    }

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        bool bSet;

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_COURSEMANDATORY2));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_COURSE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_BIKEMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_BIKE, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));  
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_DIST, bSet);
        
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SHOESMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECSHOESMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_SPECSHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_RACENUMMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_RACENUM, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_PLACEMANDATORY));
        pUser->SetRaceBikeFieldMandatory(RACEBIKEFIELD_PLACE, bSet);

        return true;
    }

    return false;
}


void COptionsDataRaceBikeSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRaceBikeSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRaceBikeSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRaceBikeSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACEBIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceBikeSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRaceBikeSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RACEBIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceBikeSheet::SetFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    if(fMandatory)
    {
        i64Field |= i64Mask;
    }
    else
    {
        i64Field &= ~i64Mask;
    }

    SetMandatoryFields(i64Field);
}