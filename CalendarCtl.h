#pragma once

class CRunningLogView;

class CCalendarCtl
{
public:
    CCalendarCtl(CRunningLogView* pParent);
    virtual ~CCalendarCtl();

    void DrawCalendar(CDC* pDC, CRect rcDraw);
    void DrawMonthSummary(CDC* pDC, CRect rcDraw) const;
    void DrawWeekSummaries(CDC* pDC, CRect rcDraw) const;
    
    CSize GetBoxSize(void) const;
    int GetMinWidthOffset(void) const;
    int GetMinHeightOffset(void) const;
    int GetHorzSpacing(void) const;
    int GetVertSpacing(void) const;
    int GetDayVertSpacing(void) const;
    int GetDayHorzSpacing(void) const;
    CSize GetTextSize(CDC* pDC, COleDateTime tmDay, int nType);
 
    void AnnotateDay(CDC* pDC, CRect rcDay, CRect rcAllowedDraw, COleDateTime tmDay, int nType) const;

protected:
    void SetParent(CRunningLogView* pParent);
    CRunningLogView* GetParent(void) const;
    void SetBoxSize(CSize sz);

    void DrawDay(CDC* pDC, CPoint ptTopLeft, COleDateTime tmDay, int nType, int nWeek) const;
    int GetNumAnnotations(int nType, COleDateTime tmDay) const;
    int ReadyDisplayStrings(CDC* pDC, CString& rstr1, CString& rstr2, CString& rstr3, CString& rstr4, CString& rstr5, int nWidth,
                            int nHeight, bool afIndent[5], int nLeft) const;
    void CutString(CDC* pDC, CString& rstrCut, CString& rstrLine1, int nWidth) const;
    void MoveStringsDown(CString astrLines[5], int nNoMove) const;
    void DrawDayString(CDC* pDC, CRect& rect, CString str, int nLeft, bool fIndentMe, bool fIndentNext, 
                       int nHeight, int nHeightIndent, CFont* pFntNormal, CFont* pFntBold) const;

    // data
    CRunningLogView* m_pParent;
    CSize m_szBox;
};