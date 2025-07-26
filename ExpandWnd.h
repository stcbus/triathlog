#pragma once


class CExpandWnd : public CWnd
{
	DECLARE_DYNAMIC(CExpandWnd)

public:
	CExpandWnd(CWnd* pParentWnd, CCalendarCtl* pCalendar, DWORD dwExStyle = 0,
               DWORD dwStyle = WS_VISIBLE | WS_POPUP, 
               LPCSTR lpszClassName = NULL, LPCSTR lpszWindowName = NULL);
	virtual ~CExpandWnd();
    void Show(COleDateTime tmDay, COLORREF crFill, CRect rc, CPoint ptTopLeft, int nOffset, 
              int nShadowXOffset, int nShadowYOffset);
    void Hide(void);

    CSize Draw( CDC *pDC, void *pv, CRect *prc );
    
    void SetMainColor(COLORREF cr);
    void SetShadowColor(COLORREF cr);
protected:
    // don't allow default constructor
    CExpandWnd();
    void MakeWindowRgn(int nWidth, int nHeight);

    afx_msg void OnPaint(void);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnCaptureChanged(CWnd* pWnd);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

    CCalendarCtl* m_pCalendar;
    COleDateTime m_tmDay;

    COLORREF m_crFill;
    COLORREF m_crShadow;

    CWnd m_wndOwner;
    CWnd* m_pParentWnd;
    CRect m_rcMouseRect;
    CRect m_rcShow;
    CPen* m_pPen;
    int m_nTextOffset;
    int m_nShadowXOffset;
    int m_nShadowYOffset;
};


