#pragma once

#include "User.h"

class CRunningLogDoc : public CDocument
{
protected: 
    // create from serialization only
	CRunningLogDoc();
public:
	virtual ~CRunningLogDoc();

// overrides
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

    CString GetFirstName(void) const;
    CString GetLastName(void) const;
    int GetSex(void) const;
    int GetHeight(void) const;
    int GetRestingHR(void) const;
    int GetBaseTypeRun(void) const;
    int GetBaseTypeBike(void) const;
    int GetBaseTypeSwim(void) const;
    int GetFirstDayOfWeek(void) const;
    bool DisplayInfoRun(void) const;
    bool DisplayInfoBike(void) const;
    bool DisplayInfoSwim(void) const;
    bool DisplayInfoStrength(void) const;
    bool DisplayInfoRace(void) const;
    COleDateTime GetCurrentDate(void) const;
    int GetHighlightDay(void) const;
    COLORREF GetBgColor(void) const;
    COLORREF GetDayColor(int nType) const;
    COLORREF GetButtonColor(void) const;
    COLORREF GetHighlightColor(void) const;
    COLORREF GetShadowColor(bool bOne) const;
    COLORREF GetGradientColor(bool bBegin) const;
    COLORREF GetHeadingTextColor(void) const;
    COLORREF GetDayTextColor(void) const;
    COLORREF GetAnnotationTextColor(void) const;
    COLORREF GetRaceDayColor(void) const;
    COLORREF GetUpcomingRaceDayColor(void) const;
    COLORREF GetUpcomingWorkoutDayColor(void) const;
    CFont* GetDayFont(void) const;
    CFont* GetHeadingFont(void) const;
    CFont* GetTitleFont(void) const;
    CFont* GetAnnotationFont(void) const;
    CFont* GetAnnotationFontBold(void) const;
    CDayLog* GetDayAt(COleDateTime tmDay) const;

    void SetFirstName(CString str);
    void SetLastName(CString str);
    void SetSex(int nSex);
    void SetHeight(int nHeight);
    void SetRestingHR(int nHR);
    void SetBaseTypeRun(int nType);
    void SetBaseTypeBike(int nType);
    void SetBaseTypeSwim(int nType);
    void SetFirstDayOfWeek(int nDay);
    void SetDisplayInfoRun(bool fDisp);
    void SetDisplayInfoBike(bool fDisp);
    void SetDisplayInfoSwim(bool fDisp);
    void SetDisplayInfoStrength(bool fDisp);
    void SetDisplayInfoRace(bool fDisp);
    void SetCurrentDate(COleDateTime tmCur);
    void SetHighlightDay(int nDay);
    void SetBgColor(COLORREF cr);
    void SetDayColor(int nType, COLORREF cr);
    void SetButtonColor(COLORREF cr);
    void SetHighlightColor(COLORREF cr);
    void SetShadowColor(bool bOne, COLORREF cr);
    void SetGradientColor(bool bBegin, COLORREF cr);
	void SetRaceDayColor(COLORREF cr);
	void SetUpcomingRaceDayColor(COLORREF cr);
	void SetUpcomingWorkoutDayColor(COLORREF cr);
    void SetHeadingTextColor(COLORREF cr);
    void SetDayTextColor(COLORREF cr);
    void SetAnnotationTextColor(COLORREF cr);
    void SetDayFont(CFont* pfnt);
    void SetHeadingFont(CFont* pfnt);
    void SetTitleFont(CFont* pfnt); 
    void SetAnnotationFont(CFont* pfnt);
    void SetAnnotationFontBold(CFont* pfnt);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DYNCREATE(CRunningLogDoc)

//    CUser* m_pUser;
};


