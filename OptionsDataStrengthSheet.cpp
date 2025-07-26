#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataStrengthSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataStrengthSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataStrengthSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_LOCATIONMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SECONDSMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPMANDATORY, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataStrengthSheet::COptionsDataStrengthSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataStrengthSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataStrengthSheet::~COptionsDataStrengthSheet()
{
}


BOOL COptionsDataStrengthSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(STRFIELD_LOCATION))
    {
        CheckDlgButton(IDC_LOCATIONMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(STRFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(STRFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(STRFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataStrengthSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryStrengthFields());
    }
}


bool COptionsDataStrengthSheet::WriteContents(void)
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

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_LOCATIONMANDATORY));
        pUser->SetStrengthFieldMandatory(STRFIELD_LOCATION, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetStrengthFieldMandatory(STRFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetStrengthFieldMandatory(STRFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetStrengthFieldMandatory(STRFIELD_TEMP, bSet);

        return true;
    }

    return false;
}


void COptionsDataStrengthSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataStrengthSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataStrengthSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataStrengthSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataStrengthSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataStrengthSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataStrengthSheet::SetFieldMandatory");
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