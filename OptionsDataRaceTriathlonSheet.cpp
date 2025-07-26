#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRaceTriathlonSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRaceTriathlonSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRaceTriathlonSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_COURSEMANDATORY2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TRANSMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_PLACEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RACENUMMANDATORY, NotifyParentChanged)

    ON_BN_CLICKED(IDC_L1TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1SPECTIMEMANDATORY, NotifyParentChanged)

    ON_BN_CLICKED(IDC_L2BIKEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2SHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L2SPECSHOESMANDATORY, NotifyParentChanged)

    ON_BN_CLICKED(IDC_L3TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3SHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L3SPECSHOESMANDATORY, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsDataRaceTriathlonSheet::COptionsDataRaceTriathlonSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRaceTriathlonSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRaceTriathlonSheet::~COptionsDataRaceTriathlonSheet()
{
}


BOOL COptionsDataRaceTriathlonSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RACETRIFIELD_COURSE))
    {
        CheckDlgButton(IDC_COURSEMANDATORY2, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_OVERALLTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_TRANS))
    {
        CheckDlgButton(IDC_TRANSMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_RACENUM))
    {
        CheckDlgButton(IDC_RACENUMMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_PLACE))
    {
        CheckDlgButton(IDC_PLACEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L1TIME))
    {
        CheckDlgButton(IDC_L1TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L1DIST))
    {
        CheckDlgButton(IDC_L1DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L1HR))
    {
        CheckDlgButton(IDC_L1HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L1TEMP))
    {
        CheckDlgButton(IDC_L1TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L1SPECTIME))
    {
        CheckDlgButton(IDC_L1SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2BIKE))
    {
        CheckDlgButton(IDC_L2BIKEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2TIME))
    {
        CheckDlgButton(IDC_L2TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2DIST))
    {
        CheckDlgButton(IDC_L2DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2SHOES))
    {
        CheckDlgButton(IDC_L2SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2HR))
    {
        CheckDlgButton(IDC_L2HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2TEMP))
    {
        CheckDlgButton(IDC_L2TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2SPECTIME))
    {
        CheckDlgButton(IDC_L2SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L2SPECSHOES))
    {
        CheckDlgButton(IDC_L2SPECSHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3TIME))
    {
        CheckDlgButton(IDC_L3TIMEMANDATORY, BST_CHECKED);
	}

    if(IsFieldMandatory(RACETRIFIELD_L3DIST))
    {
        CheckDlgButton(IDC_L3DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3SHOES))
    {
        CheckDlgButton(IDC_L3SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3HR))
    {
        CheckDlgButton(IDC_L3HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3TEMP))
    {
        CheckDlgButton(IDC_L3TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3SPECTIME))
    {
        CheckDlgButton(IDC_L3SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACETRIFIELD_L3SPECSHOES))
    {
        CheckDlgButton(IDC_L3SPECSHOESMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRaceTriathlonSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRaceTriathlonFields());
    }
}


bool COptionsDataRaceTriathlonSheet::WriteContents(void)
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
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_COURSE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_OVERALLTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TRANSMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_TRANS, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_RACENUMMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_RACENUM, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_PLACEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_PLACE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1TIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L1TIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1DISTMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L1DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1HRMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L1HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1TEMPMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L1TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1SPECTIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L1SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2BIKEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2BIKE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2TIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2DISTMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SHOESMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2HRMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2TEMPMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SPECTIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SPECSHOESMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L2SPECSHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3TIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3DISTMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SHOESMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3HRMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3TEMPMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SPECTIMEMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SPECSHOESMANDATORY));
        pUser->SetRaceTriathlonFieldMandatory(RACETRIFIELD_L3SPECSHOES, bSet);

        return true;
    }

    return false;
}


void COptionsDataRaceTriathlonSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRaceTriathlonSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRaceTriathlonSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRaceTriathlonSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACETRIFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceTriathlonSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRaceTriathlonSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RACETRIFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceTriathlonSheet::SetFieldMandatory");
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