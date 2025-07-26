#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "OptionsUnitsSheet.h"


IMPLEMENT_DYNAMIC(COptionsUnitsSheet, COptionsSheet)


BEGIN_MESSAGE_MAP(COptionsUnitsSheet, COptionsSheet)
    ON_BN_CLICKED(IDC_RUNDISTMILES, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RUNDISTKM, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEDISTMILES, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEDISTKM, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMDISTMILES, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMDISTKM, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HEIGHTINCHES, NotifyParentChanged)
    ON_BN_CLICKED(IDC_HEIGHTCM, NotifyParentChanged)
    ON_BN_CLICKED(IDC_WEIGHTPOUNDS, NotifyParentChanged)
    ON_BN_CLICKED(IDC_WEIGHTKG, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPDEG, NotifyParentChanged)
    ON_BN_CLICKED(IDC_TEMPCELSIUS, NotifyParentChanged)
END_MESSAGE_MAP()


COptionsUnitsSheet::COptionsUnitsSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsUnitsSheet::IDD, pParent)
{
    SetRunDistUnits(DISTUNITS_MI);
    SetBikeDistUnits(DISTUNITS_MI);
    SetSwimDistUnits(DISTUNITS_MI);

    SetHeightUnits(HEIGHTUNITS_IN);
    SetWeightUnits(WEIGHTUNITS_LBS);
}


COptionsUnitsSheet::~COptionsUnitsSheet()
{
}


BOOL COptionsUnitsSheet::OnInitDialog(void)
{
    BOOL bRet = COptionsSheet::OnInitDialog();
    
    InitDialogValues();

    int nType = (DISTUNITS_MI == GetRunDistUnits()) ? IDC_RUNDISTMILES : IDC_RUNDISTKM;
    CheckRadioButton(IDC_RUNDISTMILES, IDC_RUNDISTKM, nType);

    nType = (DISTUNITS_MI == GetBikeDistUnits()) ? IDC_BIKEDISTMILES : IDC_BIKEDISTKM;
    CheckRadioButton(IDC_BIKEDISTMILES, IDC_BIKEDISTKM, nType);

    nType = (DISTUNITS_MI == GetSwimDistUnits()) ? IDC_SWIMDISTMILES : IDC_SWIMDISTKM;
    CheckRadioButton(IDC_SWIMDISTMILES, IDC_SWIMDISTKM, nType);

    nType = (HEIGHTUNITS_IN == GetHeightUnits()) ? IDC_HEIGHTINCHES : IDC_HEIGHTCM;
    CheckRadioButton(IDC_HEIGHTINCHES, IDC_HEIGHTCM, nType);

    nType = (WEIGHTUNITS_LBS == GetWeightUnits()) ? IDC_WEIGHTPOUNDS : IDC_WEIGHTKG;
    CheckRadioButton(IDC_WEIGHTPOUNDS, IDC_WEIGHTKG, nType);

    nType = (TEMPUNITS_DEG == GetTempUnits()) ? IDC_TEMPDEG : IDC_TEMPCELSIUS;
    CheckRadioButton(IDC_TEMPDEG, IDC_TEMPCELSIUS, nType);

    return bRet;
}


void COptionsUnitsSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetRunDistUnits(pUser->GetRunDistUnits());
        SetBikeDistUnits(pUser->GetBikeDistUnits());
        SetSwimDistUnits(pUser->GetSwimDistUnits());
        SetHeightUnits(pUser->GetHeightUnits());
        SetWeightUnits(pUser->GetWeightUnits());
        SetTempUnits(pUser->GetTempUnits());
    }
}


bool COptionsUnitsSheet::WriteContents(void)
{
    if(!::IsWindow(m_hWnd))
    {
        // if we haven't been initialized, we couldn't have been changed yet
        return true;
    }

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return false;
    }

    if(IsDlgButtonChecked(IDC_RUNDISTMILES))
    {
        pUser->SetRunDistUnits(DISTUNITS_MI);
        SetRunDistUnits(DISTUNITS_MI);
    }
    else
    {
        pUser->SetRunDistUnits(DISTUNITS_KM);
        SetRunDistUnits(DISTUNITS_KM);
    }

    if(IsDlgButtonChecked(IDC_BIKEDISTMILES))
    {
        pUser->SetBikeDistUnits(DISTUNITS_MI);
        SetBikeDistUnits(DISTUNITS_MI);
    }
    else
    {
        pUser->SetBikeDistUnits(DISTUNITS_KM);
        SetBikeDistUnits(DISTUNITS_KM);
    }

    if(IsDlgButtonChecked(IDC_SWIMDISTMILES))
    {
        pUser->SetSwimDistUnits(DISTUNITS_MI);
        SetSwimDistUnits(DISTUNITS_MI);
    }
    else
    {
        pUser->SetSwimDistUnits(DISTUNITS_KM);
        SetSwimDistUnits(DISTUNITS_KM);
    }

    if(IsDlgButtonChecked(IDC_HEIGHTINCHES))
    {
        pUser->SetHeightUnits(HEIGHTUNITS_IN);
        SetHeightUnits(HEIGHTUNITS_IN);
    }
    else
    {
        pUser->SetHeightUnits(HEIGHTUNITS_CM);
        SetHeightUnits(HEIGHTUNITS_CM);
    }

    if(IsDlgButtonChecked(IDC_WEIGHTPOUNDS))
    {
        pUser->SetWeightUnits(WEIGHTUNITS_LBS);
        SetWeightUnits(WEIGHTUNITS_LBS);
    }
    else
    {
        pUser->SetWeightUnits(WEIGHTUNITS_KG);
        SetWeightUnits(WEIGHTUNITS_KG);
    }

    if(IsDlgButtonChecked(IDC_TEMPDEG))
    {
        pUser->SetTempUnits(TEMPUNITS_DEG);
        SetTempUnits(TEMPUNITS_DEG);
    }
    else
    {
        pUser->SetTempUnits(TEMPUNITS_CELSIUS);
        SetTempUnits(TEMPUNITS_CELSIUS);
    }

    return true;
}


void COptionsUnitsSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


int COptionsUnitsSheet::GetRunDistUnits(void) const
{
    return m_nRunDistUnits;
}


int COptionsUnitsSheet::GetBikeDistUnits(void) const
{
    return m_nBikeDistUnits;
}


int COptionsUnitsSheet::GetSwimDistUnits(void) const
{
    return m_nSwimDistUnits;
}


int COptionsUnitsSheet::GetHeightUnits(void) const
{
    return m_nHeightUnits;
}


int COptionsUnitsSheet::GetWeightUnits(void) const
{
    return m_nWeightUnits;
}


int COptionsUnitsSheet::GetTempUnits(void) const
{
    return m_nTempUnits;
}


void COptionsUnitsSheet::SetRunDistUnits(int nUnits) 
{
    m_nRunDistUnits = nUnits;
}


void COptionsUnitsSheet::SetBikeDistUnits(int nUnits) 
{
    m_nBikeDistUnits = nUnits;
}


void COptionsUnitsSheet::SetSwimDistUnits(int nUnits) 
{
    m_nSwimDistUnits = nUnits;
}


void COptionsUnitsSheet::SetHeightUnits(int nUnits) 
{
    m_nHeightUnits = nUnits;
}


void COptionsUnitsSheet::SetWeightUnits(int nUnits) 
{
    m_nWeightUnits = nUnits;
}


void COptionsUnitsSheet::SetTempUnits(int nUnits)
{
    m_nTempUnits = nUnits;
}