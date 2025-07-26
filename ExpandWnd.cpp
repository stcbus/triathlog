#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "CalendarCtl.h"
#include "ExpandWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CExpandWnd, CWnd)
    ON_WM_PAINT()
    ON_WM_MOUSEMOVE()
    ON_WM_KEYDOWN()
    ON_WM_CAPTURECHANGED()
    ON_WM_MOUSEWHEEL()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MBUTTONUP()
END_MESSAGE_MAP()


IMPLEMENT_DYNAMIC(CExpandWnd, CWnd)


// disallowed, must use the one parameter constructor
CExpandWnd::CExpandWnd()
{
}


CExpandWnd::CExpandWnd(CWnd* pParentWnd, CCalendarCtl* pCalendar,
                       DWORD dwExStyle, /* = 0 */
                       DWORD dwStyle, /* = WS_POPUP */ 
                       LPCSTR lpszClassName, /* = NULL */ 
                       LPCSTR lpszWindowName /* = NULL */ )
{
    m_pCalendar = pCalendar;
    m_pParentWnd = pParentWnd;
    m_rcShow = CRect(0, 0, 1, 1);
    m_pPen = new CPen(PS_SOLID, 2, RGB(0, 0, 0)); // RGB(128, 128, 255));

    SetShadowColor(RGB(80, 80, 80));
    SetMainColor(CUtil::GetDefaultHighlightColor());

    LPCTSTR pszWndClass = AfxRegisterWndClass(0);
    m_wndOwner.CreateEx(0, pszWndClass, _T(""), WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, 0);

    pszWndClass = AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW));
    CreateEx(WS_EX_TOPMOST, pszWndClass, _T(""), WS_POPUP | WS_VISIBLE, 0, 0, 1, 1, m_wndOwner.GetSafeHwnd(), NULL);

    Hide();
}


CExpandWnd::~CExpandWnd()
{
    if(NULL != m_wndOwner.m_hWnd)
    {
        m_wndOwner.DestroyWindow();
    }

    if(m_pPen)
    {
        delete m_pPen;
    }

    DestroyWindow();
}


void CExpandWnd::Show(COleDateTime tmDay, COLORREF crFill, 
                      CRect rc, CPoint ptTopLeft, int nOffset, int nShadowXOffset, int nShadowYOffset)
{
    m_tmDay = tmDay;
    m_rcMouseRect = rc;
    m_nTextOffset = nOffset;
    m_nShadowXOffset = nShadowXOffset;
    m_nShadowYOffset = nShadowYOffset;
    CDC* pDC = GetDC();

    SetMainColor(crFill);

    CSize sizTxt = m_pCalendar->GetTextSize(pDC, tmDay, DAYTYPE_NORMAL);

    m_rcShow.left = ptTopLeft.x;
    m_rcShow.top = ptTopLeft.y;
    m_rcShow.bottom = ptTopLeft.y + m_nShadowYOffset + sizTxt.cy;
    m_rcShow.right = ptTopLeft.x + m_nShadowXOffset + sizTxt.cx;
    
    m_pParentWnd->ClientToScreen(&m_rcShow.TopLeft());
    m_pParentWnd->ClientToScreen(&m_rcShow.BottomRight());
    SetWindowPos(&wndTopMost, m_rcShow.left, m_rcShow.top, m_rcShow.Width(), m_rcShow.Height(), 
                 SWP_SHOWWINDOW | SWP_NOACTIVATE);
    MakeWindowRgn(m_rcShow.Width(), m_rcShow.Height());
    SetCapture();
    ReleaseDC(pDC);
}


void CExpandWnd::MakeWindowRgn(int nWidth, int nHeight)
{
    CPoint pts[7];
    pts[0].SetPoint(0, 0);
    pts[1].SetPoint(nWidth, 0);
    pts[2].SetPoint(nWidth, nHeight);
    pts[3].SetPoint(m_nShadowXOffset, nHeight);
    pts[4].SetPoint(m_nShadowXOffset, nHeight - m_nShadowYOffset);
    pts[5].SetPoint(0, nHeight - m_nShadowYOffset);
    pts[6] = pts[0];

    CRgn rgnWindow;
    rgnWindow.CreatePolygonRgn(pts, 7, WINDING);
    SetWindowRgn(rgnWindow, TRUE);
}


void CExpandWnd::Hide(void)
{
    if(GetCapture() == this)
        ReleaseCapture();
}


void CExpandWnd::OnPaint(void)
{
    CRect rcClient;
    CPaintDC dc(this);
    CPen* pOldPen = dc.SelectObject(m_pPen);
    GetClientRect(&rcClient);
 
    CRect rcDrawRect(rcClient.left, rcClient.top, rcClient.right - m_nShadowXOffset, rcClient.bottom - m_nShadowYOffset);
    CRect rcText(rcDrawRect.left + m_nTextOffset, rcDrawRect.top, rcDrawRect.right, rcDrawRect.bottom); 
    CRect rcShadow(rcClient.left + m_nShadowXOffset, rcClient.top + m_nShadowYOffset, rcClient.right, rcClient.bottom);

    dc.FillSolidRect(&rcShadow, m_crShadow);

    dc.FillSolidRect(&rcDrawRect, m_crFill);
 
    CRect rcDay = m_rcMouseRect;
    rcDay.OffsetRect(-rcDay.left, -rcDay.top);
    m_pCalendar->AnnotateDay(&dc, rcDay, rcDrawRect, m_tmDay, DAYTYPE_NORMAL);

    dc.SelectObject(pOldPen);
}


void CExpandWnd::OnMouseMove(UINT nFlags, CPoint point)
{
    point.x += m_rcMouseRect.left;
    point.y += m_rcMouseRect.top;
    if(!PtInRect(&m_rcMouseRect, point))
        Hide();
}


void CExpandWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    Hide();
    CRect rcRect = m_rcShow;
    m_pParentWnd->ScreenToClient(&rcRect.TopLeft());
    m_pParentWnd->ScreenToClient(&rcRect.BottomRight());
    m_pParentWnd->SendMessage(WM_LBUTTONDBLCLK, (WPARAM)nFlags, MAKELPARAM(rcRect.left + point.x, rcRect.top + point.y));
}


void CExpandWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
    Hide();
    CRect rcRect = m_rcShow;
    m_pParentWnd->ScreenToClient(&rcRect.TopLeft());
    m_pParentWnd->ScreenToClient(&rcRect.BottomRight());
    m_pParentWnd->SendMessage(WM_LBUTTONDOWN, (WPARAM)nFlags, MAKELPARAM(rcRect.left + point.x, rcRect.top + point.y));
}


void CExpandWnd::OnRButtonDown(UINT nFlags, CPoint point)
{
    Hide();
    CRect rcRect = m_rcShow;
    m_pParentWnd->ScreenToClient(&rcRect.TopLeft());
    m_pParentWnd->ScreenToClient(&rcRect.BottomRight());
    m_pParentWnd->SendMessage(WM_RBUTTONDOWN, (WPARAM)nFlags, MAKELPARAM(rcRect.left + point.x, rcRect.top + point.y));
}


void CExpandWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
    Hide();
    CRect rcRect = m_rcShow;
    m_pParentWnd->ScreenToClient(&rcRect.TopLeft());
    m_pParentWnd->ScreenToClient(&rcRect.BottomRight());
    m_pParentWnd->SendMessage(WM_LBUTTONUP, (WPARAM)nFlags, MAKELPARAM(rcRect.left + point.x, rcRect.top + point.y));
}


void CExpandWnd::OnMButtonUp(UINT nFlags, CPoint point)
{
    Hide();
    CRect rcRect = m_rcShow;
    m_pParentWnd->ScreenToClient(&rcRect.TopLeft());
    m_pParentWnd->ScreenToClient(&rcRect.BottomRight());
    m_pParentWnd->SendMessage(WM_LBUTTONUP, (WPARAM)nFlags, MAKELPARAM(rcRect.left + point.x, rcRect.top + point.y));
}


void CExpandWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    Hide();
}


void CExpandWnd::OnCaptureChanged(CWnd* pWnd)
{
    SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | 
                    SWP_HIDEWINDOW | SWP_NOACTIVATE); 
}


BOOL CExpandWnd::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
    Hide();
    return TRUE;
}


void CExpandWnd::SetMainColor(COLORREF cr)
{
    m_crFill = cr;
}


void CExpandWnd::SetShadowColor(COLORREF cr)
{
    m_crShadow = cr;
}