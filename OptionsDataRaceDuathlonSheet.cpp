#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsDataRaceDuathlonSheet.h"


IMPLEMENT_DYNAMIC(COptionsDataRaceDuathlonSheet, COptionsSheet)

BEGIN_MESSAGE_MAP(COptionsDataRaceDuathlonSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_COURSEMANDATORY2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TRANSMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_PLACEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RACENUMMANDATORY, NotifyParentChanged)

    ON_BN_CLICKED(IDC_L1TIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1DISTMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1SHOESMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1HRMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1TEMPMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1SPECTIMEMANDATORY, NotifyParentChanged)
    ON_BN_CLICKED(IDC_L1SPECSHOESMANDATORY, NotifyParentChanged)

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


COptionsDataRaceDuathlonSheet::COptionsDataRaceDuathlonSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsDataRaceDuathlonSheet::IDD, pParent)
{
   SetMandatoryFields(0xffffffffffffffff);
}


COptionsDataRaceDuathlonSheet::~COptionsDataRaceDuathlonSheet()
{
}


BOOL COptionsDataRaceDuathlonSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    if(IsFieldMandatory(RACEDUFIELD_COURSE))
    {
        CheckDlgButton(IDC_COURSEMANDATORY2, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_OVERALLTIME))
    {
        CheckDlgButton(IDC_SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_TRANS))
    {
        CheckDlgButton(IDC_TRANSMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_RACENUM))
    {
        CheckDlgButton(IDC_RACENUMMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_PLACE))
    {
        CheckDlgButton(IDC_PLACEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1TIME))
    {
        CheckDlgButton(IDC_L1TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1DIST))
    {
        CheckDlgButton(IDC_L1DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1SHOES))
    {
        CheckDlgButton(IDC_L1SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1HR))
    {
        CheckDlgButton(IDC_L1HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1TEMP))
    {
        CheckDlgButton(IDC_L1TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1SPECTIME))
    {
        CheckDlgButton(IDC_L1SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L1SPECSHOES))
    {
        CheckDlgButton(IDC_L1SPECSHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2BIKE))
    {
        CheckDlgButton(IDC_L2BIKEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2TIME))
    {
        CheckDlgButton(IDC_L2TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2DIST))
    {
        CheckDlgButton(IDC_L2DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2SHOES))
    {
        CheckDlgButton(IDC_L2SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2HR))
    {
        CheckDlgButton(IDC_L2HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2TEMP))
    {
        CheckDlgButton(IDC_L2TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2SPECTIME))
    {
        CheckDlgButton(IDC_L2SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L2SPECSHOES))
    {
        CheckDlgButton(IDC_L2SPECSHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3TIME))
    {
        CheckDlgButton(IDC_L3TIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3DIST))
    {
        CheckDlgButton(IDC_L3DISTMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3SHOES))
    {
        CheckDlgButton(IDC_L3SHOESMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3HR))
    {
        CheckDlgButton(IDC_L3HRMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3TEMP))
    {
        CheckDlgButton(IDC_L3TEMPMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3SPECTIME))
    {
        CheckDlgButton(IDC_L3SPECTIMEMANDATORY, BST_CHECKED);
    }

    if(IsFieldMandatory(RACEDUFIELD_L3SPECSHOES))
    {
        CheckDlgButton(IDC_L3SPECSHOESMANDATORY, BST_CHECKED);
    }

    return TRUE;
}


void COptionsDataRaceDuathlonSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetMandatoryFields(pUser->GetMandatoryRaceDuathlonFields());
    }
}


bool COptionsDataRaceDuathlonSheet::WriteContents(void)
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
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_COURSE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_SPECTIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_OVERALLTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_TRANSMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_TRANS, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_RACENUMMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_RACENUM, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_PLACEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_PLACE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1TIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1DISTMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1SHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1HRMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1TEMPMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1SPECTIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L1SPECSHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L1SPECSHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2BIKEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2BIKE, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2TIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2DISTMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2HRMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2TEMPMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SPECTIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L2SPECSHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L2SPECSHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3TIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3TIME, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3DISTMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3DIST, bSet);
    
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3SHOES, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3HRMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3HR, bSet);
  
        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3TEMPMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3TEMP, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SPECTIMEMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3SPECTIME, bSet);

        bSet = (BST_CHECKED == IsDlgButtonChecked(IDC_L3SPECSHOESMANDATORY));
        pUser->SetRaceDuathlonFieldMandatory(RACEDUFIELD_L3SPECSHOES, bSet);

        return true;
    }

    return false;
}


void COptionsDataRaceDuathlonSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


unsigned __int64 COptionsDataRaceDuathlonSheet::GetMandatoryFields(void) const
{
    return m_i64Fields;
}


void COptionsDataRaceDuathlonSheet::SetMandatoryFields(unsigned __int64 i64Fields)
{
    m_i64Fields = i64Fields;
}


bool COptionsDataRaceDuathlonSheet::IsFieldMandatory(int nField) const
{
    if((nField < 0) || (nField > RACEDUFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceDuathlonSheet::IsFieldMandatory");
    }

    unsigned __int64 i64Mask = ((unsigned __int64)1) << nField;
    unsigned __int64 i64Field = GetMandatoryFields();

    return (0 != (i64Field & i64Mask));
}


void COptionsDataRaceDuathlonSheet::SetFieldMandatory(int nField, bool fMandatory)
{
    if((nField < 0) || (nField > RACEDUFIELD_MAX))
    {
        CUtil::Fatal("Bad parameter to COptionsDataRaceDuathlonSheet::SetFieldMandatory");
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