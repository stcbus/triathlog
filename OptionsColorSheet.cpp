#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "OptionsDlg.h"
#include "OptionsColorSheet.h"


IMPLEMENT_DYNAMIC(COptionsColorSheet, COptionsSheet)


BEGIN_MESSAGE_MAP(COptionsColorSheet, COptionsSheet)
    ON_WM_LBUTTONDBLCLK()
    ON_WM_PAINT()

    ON_COMMAND(IDC_RESETDEFAULT, OnResetToDefaults)
	ON_COMMAND(IDC_RANDOMCOLORS, OnRandomColors)
END_MESSAGE_MAP()


COptionsColorSheet::COptionsColorSheet(CWnd* pParent /* = NULL*/) : COptionsSheet(COptionsColorSheet::IDD, pParent)
{
    ResetDefaults();
}


COptionsColorSheet::~COptionsColorSheet()
{
}


BOOL COptionsColorSheet::OnInitDialog(void)
{
    BOOL bRet = COptionsSheet::OnInitDialog();

    InitDialogValues();

    return bRet;
}


void COptionsColorSheet::InitDialogValues(void)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        SetDayColor(DAYTYPE_NORMAL, pUser->GetDayColor(DAYTYPE_NORMAL));
        SetDayColor(DAYTYPE_GRAYED, pUser->GetDayColor(DAYTYPE_GRAYED));
        SetDayColor(DAYTYPE_WEEKSUM, pUser->GetDayColor(DAYTYPE_WEEKSUM));
        SetDayColor(DAYTYPE_MONTHSUM, pUser->GetDayColor(DAYTYPE_MONTHSUM));

        SetHighlightColor(pUser->GetHighlightColor());
        SetBgColor(pUser->GetBgColor());
        SetButtonColor(pUser->GetButtonColor());

        SetHeadingTextColor(pUser->GetHeadingTextColor());
        SetDayTextColor(pUser->GetDayTextColor());
        SetAnnotationTextColor(pUser->GetAnnotationTextColor());

        SetGradientColor(true, pUser->GetGradientColor(true));
        SetGradientColor(false, pUser->GetGradientColor(false));

		SetRaceDayColor(pUser->GetRaceDayColor());
		SetUpcomingRaceDayColor(pUser->GetUpcomingRaceDayColor());
		SetUpcomingWorkoutDayColor(pUser->GetUpcomingWorkoutDayColor());
		SetEditBgColor(pUser->GetEditBgColor());
    }
}


bool COptionsColorSheet::WriteContents(void)
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

    pUser->SetDayColor(DAYTYPE_NORMAL, GetDayColor(DAYTYPE_NORMAL));
    pUser->SetDayColor(DAYTYPE_GRAYED, GetDayColor(DAYTYPE_GRAYED));
    pUser->SetDayColor(DAYTYPE_WEEKSUM, GetDayColor(DAYTYPE_WEEKSUM));
    pUser->SetDayColor(DAYTYPE_MONTHSUM, GetDayColor(DAYTYPE_MONTHSUM));

    pUser->SetHighlightColor(GetHighlightColor());
    pUser->SetBgColor(GetBgColor());
    pUser->SetButtonColor(GetButtonColor());

    pUser->SetHeadingTextColor(GetHeadingTextColor());
    pUser->SetDayTextColor(GetDayTextColor());
    pUser->SetAnnotationTextColor(GetAnnotationTextColor());

    pUser->SetGradientColor(true, GetGradientColor(true));
    pUser->SetGradientColor(false, GetGradientColor(false));

	pUser->SetRaceDayColor(GetRaceDayColor());
	pUser->SetUpcomingRaceDayColor(GetUpcomingRaceDayColor());
	pUser->SetUpcomingWorkoutDayColor(GetUpcomingWorkoutDayColor());
	pUser->SetEditBgColor(GetEditBgColor());

    return true;
}


void COptionsColorSheet::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    COLORREF crPicked = RGB(0, 0, 0);
    bool fRedraw = false;

    if(IsPointInRect(point, IDC_COLORNORMALDAY))
    {
        if(ChooseNewColor(GetDayColor(DAYTYPE_NORMAL), &crPicked))
        {
            SetDayColor(DAYTYPE_NORMAL, crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORRACEDAY))
    {
        if(ChooseNewColor(GetRaceDayColor(), &crPicked))
        {
            SetRaceDayColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORUPCOMINGRACEDAY))
    {
        if(ChooseNewColor(GetUpcomingRaceDayColor(), &crPicked))
        {
            SetUpcomingRaceDayColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORUPCOMINGWORKOUTDAY))
    {
        if(ChooseNewColor(GetUpcomingWorkoutDayColor(), &crPicked))
        {
            SetUpcomingWorkoutDayColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLOROUTOFMONTH))
    {
        if(ChooseNewColor(GetDayColor(DAYTYPE_GRAYED), &crPicked))
        {
            SetDayColor(DAYTYPE_GRAYED, crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORWEEKSUMMARY))
    {
        if(ChooseNewColor(GetDayColor(DAYTYPE_WEEKSUM), &crPicked))
        {
            SetDayColor(DAYTYPE_WEEKSUM, crPicked);
            fRedraw = true;
        }
    }
    
    else if(IsPointInRect(point, IDC_COLORMONTHSUMMARY))
    {
        if(ChooseNewColor(GetDayColor(DAYTYPE_MONTHSUM), &crPicked))
        {
            SetDayColor(DAYTYPE_MONTHSUM, crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORHILITEDAY))
    {
        if(ChooseNewColor(GetHighlightColor(), &crPicked))
        {
            SetHighlightColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORCALBG))
    {
        if(ChooseNewColor(GetBgColor(), &crPicked))
        {
            SetBgColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORBUTTON))
    {
        if(ChooseNewColor(GetButtonColor(), &crPicked))
        {
            SetButtonColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORDAYOFWEEKTEXT))
    {
        if(ChooseNewColor(GetHeadingTextColor(), &crPicked))
        {
            SetHeadingTextColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORDAYOFMONTHTEXT))
    {
        if(ChooseNewColor(GetDayTextColor(), &crPicked))
        {
            SetDayTextColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORANNOTATIONTEXT))
    {
        if(ChooseNewColor(GetAnnotationTextColor(), &crPicked))
        {
            SetAnnotationTextColor(crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORGRADSTART))
    {
        if(ChooseNewColor(GetGradientColor(true), &crPicked))
        {
            SetGradientColor(true, crPicked);
            fRedraw = true;
        }
    }

    else if(IsPointInRect(point, IDC_COLORGRADEND))
    {
        if(ChooseNewColor(GetGradientColor(false), &crPicked))
        {
            SetGradientColor(false, crPicked);
            fRedraw = true;
        }
    }
   
    else if(IsPointInRect(point, IDC_COLOREDITBG))
    {
        if(ChooseNewColor(GetEditBgColor(), &crPicked))
        {
            SetEditBgColor(crPicked);
            fRedraw = true;
        }
    }

    if(fRedraw)
    {
        NotifyParentChanged();
        InvalidateRect(NULL);
    }
}


void COptionsColorSheet::OnPaint(void)
{
    CPaintDC dc(this);

    PaintColor(&dc, IDC_COLORNORMALDAY, GetDayColor(DAYTYPE_NORMAL));
    PaintColor(&dc, IDC_COLOROUTOFMONTH, GetDayColor(DAYTYPE_GRAYED));
    PaintColor(&dc, IDC_COLORWEEKSUMMARY, GetDayColor(DAYTYPE_WEEKSUM));
    PaintColor(&dc, IDC_COLORMONTHSUMMARY, GetDayColor(DAYTYPE_MONTHSUM));

    PaintColor(&dc, IDC_COLORHILITEDAY, GetHighlightColor());
    PaintColor(&dc, IDC_COLORCALBG, GetBgColor());
    PaintColor(&dc, IDC_COLORBUTTON, GetButtonColor());

    PaintColor(&dc, IDC_COLORDAYOFWEEKTEXT, GetHeadingTextColor());
    PaintColor(&dc, IDC_COLORDAYOFMONTHTEXT, GetDayTextColor());
    PaintColor(&dc, IDC_COLORANNOTATIONTEXT, GetAnnotationTextColor());

    PaintColor(&dc, IDC_COLORGRADSTART, GetGradientColor(true));
    PaintColor(&dc, IDC_COLORGRADEND, GetGradientColor(false));

    PaintColor(&dc, IDC_COLORRACEDAY, GetRaceDayColor());
    PaintColor(&dc, IDC_COLORUPCOMINGRACEDAY, GetUpcomingRaceDayColor());
    PaintColor(&dc, IDC_COLORUPCOMINGWORKOUTDAY, GetUpcomingWorkoutDayColor());
    PaintColor(&dc, IDC_COLOREDITBG, GetEditBgColor());
}


void COptionsColorSheet::OnResetToDefaults(void)
{
    ResetDefaults();
    InvalidateRect(NULL);
    NotifyParentChanged();
}


void COptionsColorSheet::OnRandomColors(void)
{
	SetBgColor(CUtil::GetRandomColor2());
    SetDayColor(DAYTYPE_NORMAL, CUtil::GetRandomColor2());
    SetDayColor(DAYTYPE_GRAYED, CUtil::GetRandomColor2());
    SetDayColor(DAYTYPE_MONTHSUM, CUtil::GetRandomColor2());
    SetDayColor(DAYTYPE_WEEKSUM, CUtil::GetRandomColor2());
    SetButtonColor(CUtil::GetRandomColor2());  
    SetHighlightColor(CUtil::GetRandomColor2());
    SetHeadingTextColor(CUtil::GetRandomColor2());
    SetDayTextColor(CUtil::GetRandomColor2());
    SetAnnotationTextColor(CUtil::GetRandomColor2());
    SetGradientColor(true, CUtil::GetRandomColor2());
    SetGradientColor(false, CUtil::GetRandomColor2());
	SetRaceDayColor(CUtil::GetRandomColor2());
	SetUpcomingRaceDayColor(CUtil::GetRandomColor2());
	SetUpcomingWorkoutDayColor(CUtil::GetRandomColor2());
	SetEditBgColor(CUtil::GetRandomColor2());

	InvalidateRect(NULL);
	NotifyParentChanged();
}

void COptionsColorSheet::DoDataExchange(CDataExchange* pDX)
{
	COptionsSheet::DoDataExchange(pDX); 
}


void COptionsColorSheet::PaintColor(CDC* pDC, UINT nID, COLORREF crColor)
{
    if(NULL == pDC)
    {
        return;
    }

    COLORREF crShadow1 = CUtil::GetDefaultShadowColor(true);
    COLORREF crShadow2 = CUtil::GetDefaultShadowColor(false);

    CWnd* pWnd = GetDlgItem(nID);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        pDC->FillSolidRect(&rc, crColor);
        pDC->Draw3dRect(&rc, crShadow1, crShadow2);
    }
}


bool COptionsColorSheet::IsPointInRect(CPoint point, UINT nID)
{
    CWnd* pWnd = GetDlgItem(nID);
    if(NULL != pWnd)
    {
        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);
        if(rc.PtInRect(point))
        {
            return true;
        }
    }

    return false;
}


bool COptionsColorSheet::ChooseNewColor(COLORREF crInitial, COLORREF* pcrRes)
{
    if(NULL == pcrRes)
    {
        return false;
    }

    CColorDialog dlgColor(crInitial, CC_FULLOPEN);

    if(IDOK == dlgColor.DoModal())
    {
        (*pcrRes) = dlgColor.GetColor();
        return true;
    }

    return false;
}


void COptionsColorSheet::ResetDefaults(void)
{
    SetBgColor(CUtil::GetDefaultBgColor());
    SetDayColor(DAYTYPE_NORMAL, CUtil::GetDefaultDayColor(DAYTYPE_NORMAL));
    SetDayColor(DAYTYPE_GRAYED, CUtil::GetDefaultDayColor(DAYTYPE_GRAYED));
    SetDayColor(DAYTYPE_MONTHSUM, CUtil::GetDefaultDayColor(DAYTYPE_MONTHSUM));
    SetDayColor(DAYTYPE_WEEKSUM, CUtil::GetDefaultDayColor(DAYTYPE_WEEKSUM));
    SetButtonColor(CUtil::GetDefaultButtonColor());  
    SetHighlightColor(CUtil::GetDefaultHighlightColor());
    SetHeadingTextColor(CUtil::GetDefaultHeadingTextColor());
    SetDayTextColor(CUtil::GetDefaultDayTextColor());
    SetAnnotationTextColor(CUtil::GetDefaultAnnotationTextColor());
    SetGradientColor(true, CUtil::GetDefaultGradientColor(true));
    SetGradientColor(false, CUtil::GetDefaultGradientColor(false));
	SetRaceDayColor(CUtil::GetDefaultRaceDayColor());
	SetUpcomingRaceDayColor(CUtil::GetDefaultUpcomingRaceDayColor());
	SetUpcomingWorkoutDayColor(CUtil::GetDefaultUpcomingWorkoutDayColor());
	SetEditBgColor(CUtil::GetDefaultEditBgColor());
}


COLORREF COptionsColorSheet::GetBgColor(void) const
{
    return m_crBg;
}


COLORREF COptionsColorSheet::GetDayColor(int nType) const
{
    switch(nType)
    {
    case DAYTYPE_NORMAL:
        {
            return m_acrDay[0];
        }

    case DAYTYPE_GRAYED:
        {
            return m_acrDay[1];
        }

    case DAYTYPE_MONTHSUM:
        {
            return m_acrDay[2];
        }

    case DAYTYPE_WEEKSUM:
        {
            return m_acrDay[3];
        }

    default:
        {
            CUtil::Fatal("Bad parameter to COptionsColorSheet::GetDayColor");
            return RGB(0, 0, 0);
        }
    }
}


COLORREF COptionsColorSheet::GetButtonColor(void) const
{
    return m_crButton;
}


COLORREF COptionsColorSheet::GetHighlightColor(void) const
{
    return m_crHighlight;
}


COLORREF COptionsColorSheet::GetGradientColor(bool bBegin) const
{
    if(bBegin)
    {
        return m_acrGrad[0];
    }
    else
    {
        return m_acrGrad[1];
    }
}


COLORREF COptionsColorSheet::GetHeadingTextColor(void) const
{
    return m_crHeadingText;
}


COLORREF COptionsColorSheet::GetDayTextColor(void) const
{
    return m_crDayText;
}


COLORREF COptionsColorSheet::GetAnnotationTextColor(void) const
{
    return m_crAnnotation;
}


COLORREF COptionsColorSheet::GetRaceDayColor(void) const
{
    return m_crRaceDay;
}


COLORREF COptionsColorSheet::GetUpcomingRaceDayColor(void) const
{
    return m_crUpcomingRaceDay;
}


COLORREF COptionsColorSheet::GetUpcomingWorkoutDayColor(void) const
{
    return m_crUpcomingWorkoutDay;
}


COLORREF COptionsColorSheet::GetEditBgColor(void) const
{
    return m_crEditBg;
}


void COptionsColorSheet::SetBgColor(COLORREF cr)
{
    m_crBg = cr;
}


void COptionsColorSheet::SetDayColor(int nType, COLORREF cr)
{
    switch(nType)
    {
    case DAYTYPE_NORMAL:
        {
            m_acrDay[0] = cr;
            break;
        }

    case DAYTYPE_GRAYED:
        {
            m_acrDay[1] = cr;
            break;
        }

    case DAYTYPE_MONTHSUM:
        {
            m_acrDay[2] = cr;
            break;
        }

    case DAYTYPE_WEEKSUM:
        {
            m_acrDay[3] = cr;
            break;
        }

    default:
        {
            CUtil::Fatal("Bad parameter to COptionsColorSheet::SetDayColor");
        }
    }
}


void COptionsColorSheet::SetButtonColor(COLORREF cr)
{
    m_crButton = cr;
}


void COptionsColorSheet::SetHighlightColor(COLORREF cr)
{
    m_crHighlight = cr;
}


void COptionsColorSheet::SetGradientColor(bool bBegin, COLORREF cr)
{
    if(bBegin)
    {
        m_acrGrad[0] = cr;
    }
    else
    {
        m_acrGrad[1] = cr;
    }
}


void COptionsColorSheet::SetHeadingTextColor(COLORREF cr)
{
    m_crHeadingText = cr;
}


void COptionsColorSheet::SetDayTextColor(COLORREF cr)
{
    m_crDayText = cr;
}


void COptionsColorSheet::SetAnnotationTextColor(COLORREF cr)
{
    m_crAnnotation = cr;
}


void COptionsColorSheet::SetRaceDayColor(COLORREF cr)
{
    m_crRaceDay = cr;
}


void COptionsColorSheet::SetUpcomingRaceDayColor(COLORREF cr)
{
    m_crUpcomingRaceDay = cr;
}


void COptionsColorSheet::SetUpcomingWorkoutDayColor(COLORREF cr)
{
    m_crUpcomingWorkoutDay = cr;
}


void COptionsColorSheet::SetEditBgColor(COLORREF cr)
{
    m_crEditBg = cr;
}