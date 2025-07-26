#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRaceSwimSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRaceSwimSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRaceSwimSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_COURSEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_PLACEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RACENUMMANDATORY, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataRaceSwimSheet::COptionsDataRaceSwimSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRaceSwimSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRaceSwimSheet::~COptionsDataRaceSwimSheet()
{
}


BOOL COptionsDataRaceSwimSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RACESWIMFIELD_COURSE))
    {
        CheckDlgButton(IDC_COURSEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_RACENUM))
    {
        CheckDlgButton(IDC_RACENUMMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACESWIMFIELD_PLACE))
    {
        CheckDlgButton(IDC_PLACEMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRaceSwimSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRaceSwimFields());
    }
}


bool COptionsDataRaceSwimSheet::WriteContents(void)
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

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_COURSEMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_COURSE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_DIST, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_RACENUMMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_RACENUM, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_PLACEMANDATORY));
        pUser->SetRaceSwimFieldMandatory(RACESWIMFIELD_PLACE, bSet);

        return true;
    }

    return false;
}


void COptionsDataRaceSwimSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRaceSwimSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRaceSwimSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRaceSwimSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACESWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceSwimSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRaceSwimSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RACESWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceSwimSheet::SetFieldMandatory");
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