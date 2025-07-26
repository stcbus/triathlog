#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsSheet.h"
#include "DlgHelper.h"
#include "OptionsCalendarSheet.h"


IMPLEMENT_DYNAMIC(COptionsCalendarSheet, COptionsSheet)


BEGIN_MESSAGE_MAP(COptionsCalendarSheet, COptionsSheet)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ANIMSPIN, OnSpinUpDown)
    ON_BN_CLICKED(IDC_RUNBASETIME, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RUNBASEDIST, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEBASETIME, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEBASEDIST, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMBASETIME, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMBASEDIST, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISPLAYRUNNING, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISPLAYBIKING, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISPLAYSWIMMING, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISPLAYSTRENGTH, NotifyParentChanged)
    ON_BN_CLICKED(IDC_DISPLAYRACES, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RUNPACEMINDIST, NotifyParentChanged)
    ON_BN_CLICKED(IDC_RUNPACEDISTHR, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEPACEMINDIST, NotifyParentChanged)
    ON_BN_CLICKED(IDC_BIKEPACEDISTHR, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMPACEMINDIST2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMPACEDISTHR2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMPACEMIN100M2, NotifyParentChanged)
    ON_BN_CLICKED(IDC_SWIMPACEMIN100Y2, NotifyParentChanged)
	ON_EN_CHANGE(IDC_ANIMTIME, NotifyParentChanged)
	ON_CBN_SELCHANGE(IDC_RUNDECIMALS, OnRunDecimalsChanged)
	ON_CBN_SELCHANGE(IDC_BIKEDECIMALS, OnBikeDecimalsChanged)
	ON_CBN_SELCHANGE(IDC_SWIMDECIMALS, OnSwimDecimalsChanged)
END_MESSAGE_MAP()


COptionsCalendarSheet::COptionsCalendarSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsCalendarSheet::IDD, pParent)
{
    SetBaseTypeRun(CUtil::GetDefaultBaseTypeRun());
    SetBaseTypeBike(CUtil::GetDefaultBaseTypeBike());
    SetBaseTypeSwim(CUtil::GetDefaultBaseTypeSwim());
    SetDisplayInfoRun(CUtil::GetDefaultDisplayInfo(ACTIVITY_RUNNING));
    SetDisplayInfoBike(CUtil::GetDefaultDisplayInfo(ACTIVITY_BIKING));
    SetDisplayInfoSwim(CUtil::GetDefaultDisplayInfo(ACTIVITY_SWIMMING));
    SetDisplayInfoStrength(CUtil::GetDefaultDisplayInfo(ACTIVITY_STRENGTH));
    SetDisplayInfoRace(CUtil::GetDefaultDisplayInfo(ACTIVITY_RACE));
    SetPaceFormatRun(CUtil::GetDefaultPaceFormatRun());
    SetPaceFormatBike(CUtil::GetDefaultPaceFormatBike());
    SetPaceFormatSwim(CUtil::GetDefaultPaceFormatSwim());
	SetAnimTime(CUtil::GetDefaultDlgAnimationTime());
	SetRunDecimals(CUtil::GetDefaultRunDecimals());
	SetBikeDecimals(CUtil::GetDefaultBikeDecimals());
	SetSwimDecimals(CUtil::GetDefaultSwimDecimals());
}


COptionsCalendarSheet::~COptionsCalendarSheet()
{
}


BOOL COptionsCalendarSheet::OnInitDialog(void)
{
    COptionsSheet::OnInitDialog();

    InitDialogValues();

    int nType = (BASED_ON_TIME == GetBaseTypeRun()) ? IDC_RUNBASETIME : IDC_RUNBASEDIST;
    CheckRadioButton(IDC_RUNBASETIME, IDC_RUNBASEDIST, nType);

    nType = (BASED_ON_TIME == GetBaseTypeBike()) ? IDC_BIKEBASETIME : IDC_BIKEBASEDIST;
    CheckRadioButton(IDC_BIKEBASETIME, IDC_BIKEBASEDIST, nType);

    // for some reason, these were ordered backwards by VC so dist is before time
    nType = (BASED_ON_TIME == GetBaseTypeSwim()) ? IDC_SWIMBASETIME : IDC_SWIMBASEDIST;
    CheckRadioButton(IDC_SWIMBASEDIST, IDC_SWIMBASETIME, nType);

    nType = (PACEFORMAT_MINDIST == GetPaceFormatRun()) ? IDC_RUNPACEMINDIST : IDC_RUNPACEDISTHR;
    CheckRadioButton(IDC_RUNPACEMINDIST, IDC_RUNPACEDISTHR, nType);

    nType = (PACEFORMAT_MINDIST == GetPaceFormatBike()) ? IDC_BIKEPACEMINDIST : IDC_BIKEPACEDISTHR;
    CheckRadioButton(IDC_BIKEPACEMINDIST, IDC_BIKEPACEDISTHR, nType);

    int nFormat = GetPaceFormatSwim();
    if(PACEFORMAT_MINDIST == nFormat)
    {
        nType = IDC_SWIMPACEMINDIST2;
    }
    else if(PACEFORMAT_DISTHR == nFormat)
    {
        nType = IDC_SWIMPACEDISTHR2;
    }
    else if(PACEFORMAT_MIN100M == nFormat)
    {
        nType = IDC_SWIMPACEMIN100M2;
    }
    else
    {
        nType = IDC_SWIMPACEMIN100Y2;
    }

    CheckRadioButton(IDC_SWIMPACEMINDIST2, IDC_SWIMPACEMIN100Y2, nType);

    if(DisplayInfoRun())
    {
        CheckDlgButton(IDC_DISPLAYRUNNING, BST_CHECKED);
    }

    if(DisplayInfoBike())
    {
        CheckDlgButton(IDC_DISPLAYBIKING, BST_CHECKED);
    }

    if(DisplayInfoSwim())
    {
        CheckDlgButton(IDC_DISPLAYSWIMMING, BST_CHECKED);
    }

    if(DisplayInfoStrength())
    {
        CheckDlgButton(IDC_DISPLAYSTRENGTH, BST_CHECKED);
    }

    if(DisplayInfoRace())
    {
        CheckDlgButton(IDC_DISPLAYRACES, BST_CHECKED);
    }

	SetDlgItemInt(IDC_ANIMTIME, GetAnimTime());

	CComboBox* pRunDecBox = (CComboBox*)GetDlgItem(IDC_RUNDECIMALS);
	CComboBox* pBikeDecBox = (CComboBox*)GetDlgItem(IDC_BIKEDECIMALS);
	CComboBox* pSwimDecBox = (CComboBox*)GetDlgItem(IDC_SWIMDECIMALS);
	if((NULL != pRunDecBox) && (NULL != pBikeDecBox) && (NULL != pSwimDecBox))
	{
		for(int i = 0; i < 5; i++)
		{
			CString str;
			str.Format("%d", i);

			pRunDecBox->AddString(str);
			pBikeDecBox->AddString(str);
			pSwimDecBox->AddString(str);
		}

		CDlgHelper::ReadyComboBox(pRunDecBox, false);
		CDlgHelper::ReadyComboBox(pBikeDecBox, false);
		CDlgHelper::ReadyComboBox(pSwimDecBox, false);

		pRunDecBox->SetCurSel(GetRunDecimals());
		pBikeDecBox->SetCurSel(GetBikeDecimals());
		pSwimDecBox->SetCurSel(GetSwimDecimals());
	}

	OnRunDecimalsChanged();
	OnBikeDecimalsChanged();
	OnSwimDecimalsChanged();

    return TRUE;
}


void COptionsCalendarSheet::OnSpinUpDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	NMUPDOWN* pNmUpDown = (NMUPDOWN*) pNmHdr;
	int n = GetDlgItemInt(IDC_ANIMTIME);

	if(NULL != pNmHdr)
	{
		// these things run backwards, so you have to subtract
		n -= pNmUpDown->iDelta;
		
		if(n < 0)
		{
			n = 0;
		}
		if(n > 100)
		{
			n = 100;
		}
	}

	SetDlgItemInt(IDC_ANIMTIME, n);
}


void COptionsCalendarSheet::OnRunDecimalsChanged(void)
{
	NotifyParentChanged();

	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_RUNDECIMALS);
	if(NULL == pBox)
	{
		return;
	}

	CString strText = "decimals";

	int nSel = pBox->GetCurSel();
	if(1 == nSel)
	{
		strText = "decimal";
	}

	SetDlgItemText(IDT_RUNDECIMALS, strText);
}


void COptionsCalendarSheet::OnBikeDecimalsChanged(void)
{
	NotifyParentChanged();

	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_BIKEDECIMALS);
	if(NULL == pBox)
	{
		return;
	}

	CString strText = "decimals";

	int nSel = pBox->GetCurSel();
	if(1 == nSel)
	{
		strText = "decimal";
	}

	SetDlgItemText(IDT_BIKEDECIMALS, strText);
}


void COptionsCalendarSheet::OnSwimDecimalsChanged(void)
{
	NotifyParentChanged();

	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_SWIMDECIMALS);
	if(NULL == pBox)
	{
		return;
	}

	CString strText = "decimals";

	int nSel = pBox->GetCurSel();
	if(1 == nSel)
	{
		strText = "decimal";
	}

	SetDlgItemText(IDT_SWIMDECIMALS, strText);
}

		
void COptionsCalendarSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetBaseTypeRun(pUser->GetBaseTypeRun());
        SetBaseTypeBike(pUser->GetBaseTypeBike());
        SetBaseTypeSwim(pUser->GetBaseTypeSwim());
        SetDisplayInfoRun(pUser->DisplayInfoRun());
        SetDisplayInfoBike(pUser->DisplayInfoBike());
        SetDisplayInfoSwim(pUser->DisplayInfoSwim());
        SetDisplayInfoStrength(pUser->DisplayInfoStrength());
        SetDisplayInfoRace(pUser->DisplayInfoRace());
        SetPaceFormatRun(pUser->GetPaceFormatRun());
        SetPaceFormatBike(pUser->GetPaceFormatBike());
        SetPaceFormatSwim(pUser->GetPaceFormatSwim());
		SetAnimTime(pUser->GetDlgAnimationTime());
		SetRunDecimals(pUser->GetRunDecimals());
		SetBikeDecimals(pUser->GetBikeDecimals());
		SetSwimDecimals(pUser->GetSwimDecimals());
    }
}


bool COptionsCalendarSheet::WriteContents(void)
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

    if(BST_CHECKED == IsDlgButtonChecked(IDC_RUNBASETIME))
    {
        pUser->SetBaseTypeRun(BASED_ON_TIME);
    }
    else
    {
        pUser->SetBaseTypeRun(BASED_ON_DISTANCE);
    }

    if(BST_CHECKED == IsDlgButtonChecked(IDC_BIKEBASETIME))
    {
        pUser->SetBaseTypeBike(BASED_ON_TIME);
    }
    else
    {
        pUser->SetBaseTypeBike(BASED_ON_DISTANCE);
    }

    if(BST_CHECKED == IsDlgButtonChecked(IDC_SWIMBASETIME))
    {
        pUser->SetBaseTypeSwim(BASED_ON_TIME);
    }
    else
    {
        pUser->SetBaseTypeSwim(BASED_ON_DISTANCE);
    }

    if(BST_CHECKED == IsDlgButtonChecked(IDC_RUNPACEMINDIST))
    {
        pUser->SetPaceFormatRun(PACEFORMAT_MINDIST);
    }
    else
    {
        pUser->SetPaceFormatRun(PACEFORMAT_DISTHR);
    }

    if(BST_CHECKED == IsDlgButtonChecked(IDC_BIKEPACEMINDIST))
    {
        pUser->SetPaceFormatBike(PACEFORMAT_MINDIST);
    }
    else
    {
        pUser->SetPaceFormatBike(PACEFORMAT_DISTHR);
    }

    if(BST_CHECKED == IsDlgButtonChecked(IDC_SWIMPACEMINDIST2))
    {
        pUser->SetPaceFormatSwim(PACEFORMAT_MINDIST);
    }
    else if(BST_CHECKED == IsDlgButtonChecked(IDC_SWIMPACEDISTHR2))
    {
        pUser->SetPaceFormatSwim(PACEFORMAT_DISTHR);
    }
    else if(BST_CHECKED == IsDlgButtonChecked(IDC_SWIMPACEMIN100M2))
    {
        pUser->SetPaceFormatSwim(PACEFORMAT_MIN100M);
    }
	else
	{
		pUser->SetPaceFormatSwim(PACEFORMAT_MIN100Y);
	}

    pUser->SetDisplayInfoRun(BST_CHECKED == IsDlgButtonChecked(IDC_DISPLAYRUNNING));
    pUser->SetDisplayInfoBike(BST_CHECKED == IsDlgButtonChecked(IDC_DISPLAYBIKING));
    pUser->SetDisplayInfoSwim(BST_CHECKED == IsDlgButtonChecked(IDC_DISPLAYSWIMMING));
    pUser->SetDisplayInfoStrength(BST_CHECKED == IsDlgButtonChecked(IDC_DISPLAYSTRENGTH));
    pUser->SetDisplayInfoRace(BST_CHECKED == IsDlgButtonChecked(IDC_DISPLAYRACES));

	pUser->SetDlgAnimationTime(GetDlgItemInt(IDC_ANIMTIME));

	CComboBox* pRunDecBox = (CComboBox*)GetDlgItem(IDC_RUNDECIMALS);
	CComboBox* pBikeDecBox = (CComboBox*)GetDlgItem(IDC_BIKEDECIMALS);
	CComboBox* pSwimDecBox = (CComboBox*)GetDlgItem(IDC_SWIMDECIMALS);
	if((NULL != pRunDecBox) && (NULL != pBikeDecBox) && (NULL != pSwimDecBox))
	{
		int nSel = pRunDecBox->GetCurSel();
		if(CB_ERR != nSel)
		{
			pUser->SetRunDecimals(nSel);
		}

		nSel = pBikeDecBox->GetCurSel();
		if(CB_ERR != nSel)
		{
			pUser->SetBikeDecimals(nSel);
		}

		nSel = pSwimDecBox->GetCurSel();
		if(CB_ERR != nSel)
		{
			pUser->SetSwimDecimals(nSel);
		}
	}

    return true;
}


void COptionsCalendarSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


int COptionsCalendarSheet::GetBaseTypeRun(void) const
{
    return m_nBaseTypeRun;
}


int COptionsCalendarSheet::GetBaseTypeBike(void) const
{
    return m_nBaseTypeBike;
}


int COptionsCalendarSheet::GetBaseTypeSwim(void) const
{
    return m_nBaseTypeSwim;
}


bool COptionsCalendarSheet::DisplayInfoRun(void) const
{
    return m_fDispInfoRun;
}


bool COptionsCalendarSheet::DisplayInfoBike(void) const
{
    return m_fDispInfoBike;
}


bool COptionsCalendarSheet::DisplayInfoSwim(void) const
{
    return m_fDispInfoSwim;
}


int COptionsCalendarSheet::GetPaceFormatRun(void) const
{
    return m_nPaceFormatRun;
}


int COptionsCalendarSheet::GetPaceFormatBike(void) const
{
    return m_nPaceFormatBike;
}


int COptionsCalendarSheet::GetPaceFormatSwim(void) const
{
    return m_nPaceFormatSwim;
}


bool COptionsCalendarSheet::DisplayInfoStrength(void) const
{
    return m_fDispInfoStrength;
}


bool COptionsCalendarSheet::DisplayInfoRace(void) const
{
    return m_fDispInfoRace;
}


int COptionsCalendarSheet::GetAnimTime(void) const
{
	return m_nAnimTime;
}


int COptionsCalendarSheet::GetRunDecimals(void) const
{
	return m_nRunDecimals;
}


int COptionsCalendarSheet::GetBikeDecimals(void) const
{
	return m_nBikeDecimals;
}


int COptionsCalendarSheet::GetSwimDecimals(void) const
{
	return m_nSwimDecimals;
}


void COptionsCalendarSheet::SetBaseTypeRun(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetBaseTypeRun");
        return;
    }

    m_nBaseTypeRun = nType;
}


void COptionsCalendarSheet::SetBaseTypeBike(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetBaseTypeBike");
        return;
    }

    m_nBaseTypeBike = nType;
}


void COptionsCalendarSheet::SetBaseTypeSwim(int nType)
{
    if((BASED_ON_TIME != nType) && (BASED_ON_DISTANCE != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetBaseTypeSwim");
        return;
    }

    m_nBaseTypeSwim = nType;
}


void COptionsCalendarSheet::SetDisplayInfoRun(bool fDisp)
{
    m_fDispInfoRun = fDisp;
}


void COptionsCalendarSheet::SetDisplayInfoBike(bool fDisp)
{
    m_fDispInfoBike = fDisp;
}


void COptionsCalendarSheet::SetDisplayInfoSwim(bool fDisp)
{
    m_fDispInfoSwim = fDisp;
}


void COptionsCalendarSheet::SetDisplayInfoStrength(bool fDisp)
{
    m_fDispInfoStrength = fDisp;
}


void COptionsCalendarSheet::SetDisplayInfoRace(bool fDisp)
{
    m_fDispInfoRace = fDisp;
}


void COptionsCalendarSheet::SetPaceFormatRun(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetPaceFormatRun");
        return;
    }

    m_nPaceFormatRun = nType;
}


void COptionsCalendarSheet::SetPaceFormatBike(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetPaceFormatBike");
        return;
    }

    m_nPaceFormatBike = nType;
}


void COptionsCalendarSheet::SetPaceFormatSwim(int nType)
{
    if((PACEFORMAT_MINDIST != nType) && (PACEFORMAT_DISTHR != nType) && (PACEFORMAT_MIN100M != nType) && (PACEFORMAT_MIN100Y != nType))
    {
        CUtil::Fatal("Bad parameter to COptionsCalendarSheet::SetPaceFormatSwim");
        return;
    }

    m_nPaceFormatSwim = nType;
}


void COptionsCalendarSheet::SetAnimTime(int nTime)
{
	m_nAnimTime = nTime;
}


void COptionsCalendarSheet::SetRunDecimals(int nNum)
{
	m_nRunDecimals = nNum;
}


void COptionsCalendarSheet::SetBikeDecimals(int nNum)
{
	m_nBikeDecimals = nNum;
}


void COptionsCalendarSheet::SetSwimDecimals(int nNum)
{
	m_nSwimDecimals = nNum;
}