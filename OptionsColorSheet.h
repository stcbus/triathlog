#include "OptionsSheet.h"

#pragma once


class COptionsColorSheet : public COptionsSheet
{
public:
	COptionsColorSheet(CWnd* pParent = NULL);   
	virtual ~COptionsColorSheet();

    virtual void InitDialogValues(void);
    virtual bool WriteContents(void);

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_OPTIONSCOLORSDLG };

    COLORREF GetBgColor(void) const;
    COLORREF GetDayColor(int nType) const;
    COLORREF GetButtonColor(void) const;
    COLORREF GetHighlightColor(void) const;
    COLORREF GetGradientColor(bool bBegin) const;
    COLORREF GetHeadingTextColor(void) const;
    COLORREF GetDayTextColor(void) const;
    COLORREF GetAnnotationTextColor(void) const;
    COLORREF GetRaceDayColor(void) const;
    COLORREF GetUpcomingRaceDayColor(void) const;
    COLORREF GetUpcomingWorkoutDayColor(void) const;
    COLORREF GetEditBgColor(void) const;

    void SetBgColor(COLORREF cr);
    void SetDayColor(int nType, COLORREF cr);
    void SetButtonColor(COLORREF cr);
    void SetHighlightColor(COLORREF cr);
    void SetGradientColor(bool bBegin, COLORREF cr);
    void SetHeadingTextColor(COLORREF cr);
    void SetDayTextColor(COLORREF cr);
    void SetAnnotationTextColor(COLORREF cr);
    void SetRaceDayColor(COLORREF cr);
    void SetUpcomingRaceDayColor(COLORREF cr);
    void SetUpcomingWorkoutDayColor(COLORREF cr);
    void SetEditBgColor(COLORREF cr);

protected:
    void ResetDefaults(void);
    void PaintColor(CDC* pDC, UINT nID, COLORREF crColor);
    bool IsPointInRect(CPoint point, UINT nID);
    bool ChooseNewColor(COLORREF crInitial, COLORREF* pcrRes);

	virtual void DoDataExchange(CDataExchange* pDX);  
    afx_msg void OnResetToDefaults(void);
	afx_msg void OnRandomColors(void);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnPaint(void);

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(COptionsColorSheet)

    COLORREF m_crBg;
    COLORREF m_crButton;
    COLORREF m_acrDay[4];
    COLORREF m_crHeadingText;
    COLORREF m_crDayText;
    COLORREF m_crAnnotation;
    COLORREF m_crHighlight;
    COLORREF m_acrGrad[2];
	COLORREF m_crRaceDay;
	COLORREF m_crUpcomingRaceDay;
	COLORREF m_crUpcomingWorkoutDay;
	COLORREF m_crEditBg;
};
