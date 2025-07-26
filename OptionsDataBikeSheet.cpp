#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataBikeSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataBikeSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataBikeSheet, COptionsSheet)
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


COptionsDataBikeSheet::COptionsDataBikeSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataBikeSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataBikeSheet::~COptionsDataBikeSheet()
{
}


BOOL COptionsDataBikeSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(BIKEFIELD_LOCATION))
    {
        CheckDlgButton(IDC_LOCATIONMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_BIKE))
    {
        CheckDlgButton(IDC_BIKEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_SHOES))
    {
        CheckDlgButton(IDC_SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_SPECDIST))
    {
        CheckDlgButton(IDC_SPECDISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(BIKEFIELD_SPECSHOES))
    {
        CheckDlgButton(IDC_SPECSHOESMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataBikeSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryBikeFields());
    }
}


bool COptionsDataBikeSheet::WriteContents(void)
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
        pUser->SetBikeFieldMandatory(BIKEFIELD_LOCATION, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_BIKEMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_BIKE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_TIME, bSet);
        
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_DIST, bSet);
        
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SHOESMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_SPECTIME, bSet);
        
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECDISTMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_SPECDIST, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECSHOESMANDATORY));
        pUser->SetBikeFieldMandatory(BIKEFIELD_SPECSHOES, bSet);

        return true;
    }

    return false;
}


void COptionsDataBikeSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataBikeSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataBikeSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataBikeSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > BIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataBikeSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataBikeSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > BIKEFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataBikeSheet::SetFieldMandatory");
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