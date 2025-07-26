#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRunSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRunSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRunSheet, COptionsSheet)
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


COptionsDataRunSheet::COptionsDataRunSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRunSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRunSheet::~COptionsDataRunSheet()
{
}


BOOL COptionsDataRunSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RUNFIELD_LOCATION))
    {
        CheckDlgButton(IDC_LOCATIONMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_TIME))
    {
        CheckDlgButton(IDC_TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_DIST))
    {
        CheckDlgButton(IDC_DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_SHOES))
    {
        CheckDlgButton(IDC_SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_HR))
    {
        CheckDlgButton(IDC_HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_TEMP))
    {
        CheckDlgButton(IDC_TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_SPECTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_SPECDIST))
    {
        CheckDlgButton(IDC_SPECDISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RUNFIELD_SPECSHOES))
    {
        CheckDlgButton(IDC_SPECSHOESMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRunSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRunFields());
    }
}


bool COptionsDataRunSheet::WriteContents(void)
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
        pUser->SetRunFieldMandatory(RUNFIELD_LOCATION, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TIMEMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_DISTMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SHOESMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_HRMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TEMPMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECDISTMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_SPECDIST, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECSHOESMANDATORY));
        pUser->SetRunFieldMandatory(RUNFIELD_SPECSHOES, bSet);

        return true;
    }

    return false;
}


void COptionsDataRunSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRunSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRunSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRunSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRunSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRunSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RUNFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRunSheet::SetFieldMandatory");
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