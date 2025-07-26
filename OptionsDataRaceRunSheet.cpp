#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRaceRunSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRaceRunSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRaceRunSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_COURSEMANDATORY2, NotifyParentChanged)
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


COptionsDataRaceRunSheet::COptionsDataRaceRunSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRaceRunSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRaceRunSheet::~COptionsDataRaceRunSheet()
{
}


BOOL COptionsDataRaceRunSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RACERUNFIELD_COURSE))
    {
        CheckDlgButton(IDC_COURSEMANDATORY2, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_SHOES))
    {
        CheckDlgButton(IDC_SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_SPECSHOES))
    {
        CheckDlgButton(IDC_SPECSHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_RACENUM))
    {
        CheckDlgButton(IDC_RACENUMMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACERUNFIELD_PLACE))
    {
        CheckDlgButton(IDC_PLACEMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRaceRunSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRaceRunFields());
    }
}


bool COptionsDataRaceRunSheet::WriteContents(void)
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
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_COURSE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SHOESMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECSHOESMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_SPECSHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_RACENUMMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_RACENUM, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_PLACEMANDATORY));
        pUser->SetRaceRunFieldMandatory(RACERUNFIELD_PLACE, bSet);

        return true;
    }

    return false;
}


void COptionsDataRaceRunSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRaceRunSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRaceRunSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRaceRunSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACERUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceRunSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRaceRunSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RACERUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceRunSheet::SetFieldMandatory");
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