#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataSwimSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataSwimSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataSwimSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_LOCATIONMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECDISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECSHOESMANDATORY, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataSwimSheet::COptionsDataSwimSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataSwimSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataSwimSheet::~COptionsDataSwimSheet()
{
}


BOOL COptionsDataSwimSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(SWIMFIELD_LOCATION))
    {
        CheckDlgButton(IDC_LOCATIONMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(SWIMFIELD_SPECDIST))
    {
        CheckDlgButton(IDC_SPECDISTMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataSwimSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatorySwimFields());
    }
}


bool COptionsDataSwimSheet::WriteContents(void)
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
        pUser->SetSwimFieldMandatory(SWIMFIELD_LOCATION, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_SPECTIME, bSet);
        
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECDISTMANDATORY));
        pUser->SetSwimFieldMandatory(SWIMFIELD_SPECDIST, bSet);

        return true;
    }

    return false;
}


void COptionsDataSwimSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataSwimSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataSwimSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataSwimSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > SWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataSwimSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataSwimSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > SWIMFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataSwimSheet::SetFieldMandatory");
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