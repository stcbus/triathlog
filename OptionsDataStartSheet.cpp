#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataStartSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataStartSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataStartSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_WEIGHT, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SLEEP, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataStartSheet::COptionsDataStartSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataStartSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataStartSheet::~COptionsDataStartSheet()
{
}


BOOL COptionsDataStartSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(STARTFIELD_SLEEP))
    {
        CheckDlgButton(IDC_SLEEP, BST_CHECKED);
    }

    if(IsFieldMandatory(STARTFIELD_WEIGHT))
    {
        CheckDlgButton(IDC_WEIGHT, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataStartSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryStartFields());
    }
}


bool COptionsDataStartSheet::WriteContents(void)
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

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SLEEP));
        pUser->SetStartFieldMandatory(STARTFIELD_SLEEP, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_WEIGHT));  
        pUser->SetStartFieldMandatory(STARTFIELD_WEIGHT, bSet);
  
        return true;
    }

    return false;
}


void COptionsDataStartSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataStartSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataStartSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataStartSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataStartSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataStartSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > STRFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataStartSheet::SetFieldMandatory");
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