#pragma once

#include "BtnST.h"
#include "MenuXP.h"
#include "RunningLogDoc.h"
#include "User.h"
#include "WorkoutStartDlg.h"

class CCalendarCtl;
class CExpandWnd;

class CRunningLogView : public CView
{
protected: 
    // create from serialization only
	CRunningLogView();
public:
	virtual ~CRunningLogView();

public:
	CRunningLogDoc* GetDocument() const;

    static CRunningLogView* GetView(void);
    bool PromptToSave(void);
    bool IsModified(void) const;

    // overrides
	virtual void OnDraw(CDC* pDC); 
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void OnInitialUpdate(void);

    // for the calendar
    bool IsHighlightDay(int nType, COleDateTime tmTime, int nWeek) const;
    bool IsInjuryDay(COleDateTime tmDay);
	bool IsSickDay(COleDateTime tmDay);
    bool IsBrickDay(COleDateTime tmDay);
    bool IsLongDay(COleDateTime tmDay);
	bool IsRaceDay(COleDateTime tmDay);
    bool IsJambaDay(COleDateTime tmDay);
    bool MarkAsUpcomingRaceDay(COleDateTime tmDay);
    bool MarkAsUpcomingWorkoutDay(COleDateTime tmDay);
    CString GetAnnotationRun(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout);
    CString GetAnnotationBike(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout);
    CString GetAnnotationSwim(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout);
    CString GetAnnotationStrength(int nType, COleDateTime tmTime, bool& rfUpcomingRace, bool& rfUpcomingWorkout);
    CString GetAnnotationRace(int nType, COleDateTime tmTime);

    CUser* GetUser(void);
    void SetUser(CUser* pUser);

    int GetFirstDayOfWeek(void) const;
    COleDateTime GetCurrentDate(void) const;
    int GetHighlightDay(void) const;
    int GetBaseTypeRun(void) const;
    int GetBaseTypeBike(void) const;
    int GetBaseTypeSwim(void) const;
    bool DisplayInfoRun(void) const;
    bool DisplayInfoBike(void) const;
    bool DisplayInfoSwim(void) const;
    bool DisplayInfoStrength(void) const;
    bool DisplayInfoRace(void) const;
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
    int GetLastMouseDay(void) const;
    bool IsDoingContextMenu(void) const;

	void MakeDaySummarySheet(COleDateTime tmStart, CUser* pUser, CWnd* pParent, bool bAllowSave = true);

    void OptionsDlgNotifyApply(void);
    void RedoUnits(int nDistRunUnitsOld, int nDistBikeUnitsOld, int nDistSwimUnitsOld,
                   int nHeightUnitsOld, int nWeightUnitsOld, int nTempUnitsOld);
	void MakeOpenUserDialog(CString strFile = "");

protected:
    void SetFirstDayOfWeek(int nDay);
    void SetCurrentDate(COleDateTime tmCur);
    void SetHighlightDay(int nDay);
    void SetBaseTypeRun(int nType);
    void SetBaseTypeBike(int nType);
    void SetBaseTypeSwim(int nType);
    void SetDisplayInfoRun(bool fDisp);
    void SetDisplayInfoBike(bool fDisp);
    void SetDisplayInfoSwim(bool fDisp);
    void SetDisplayInfoStrength(bool fDisp);
    void SetDisplayInfoRace(bool fDisp);
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
    void SetLastMouseDay(int nDay);
    void SetDoingContextMenu(bool bDoing);

    CSize GetLastSize(bool fFirst) const;
    void SetLastSize(bool fFirst, CSize sz);
    void AdjustTitleFontSize(void);
    void AdjustHighlightDay(void);
    void MakeGradient(int nWidth, int nHeight);
    void GetOffsets(int* pXLOffset, int* pXROffset, int* pYTOffset, int* pYBOffset) const;
    int HitTest(CPoint point) const;
    CRect GetDayRect(int nDay) const;

    bool IsUserOpen(void) const;
    void SetUserOpen(bool fOpen);

    void SetModified(bool fModified);

    bool MakeWorkoutDialog(void);
    bool MakeUpcomingRaceDialog(void);
    bool MakeUpcomingWorkoutDialog(void);
    bool MakeCorrectDialog(void);

    void MakeMenuReady(CMenu* pMenu);
    int BoolToMenuID(bool fEnable);

    void SetWindowTitle(void);
    void SetButtonColors(CButtonST* pButton);

    bool GetDayData(COleDateTime tmCur, CWorkoutStartDlg& rdlgOld);
	
	CString FormatDecimals(int nDecimals, double dVal);
    
    void MakeGraphWindow(int nID);

    void DoRegistryData(bool fSave);

    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnFileOpenUser(void);
    afx_msg void OnFileCloseUser(void);
    afx_msg void OnFileSaveUser(void);
	afx_msg void OnFilePrintToFile(void);
    afx_msg void OnFileExit(void);
    afx_msg void OnFileConvert1(void);
    afx_msg void OnFileConvert3(void);
    afx_msg void OnOptionsGoToDay(void);
    afx_msg void OnOptionsUserOptions(void);
    afx_msg void OnPrevMonth(void);
    afx_msg void OnNextMonth(void);
    afx_msg void OnOptionsAddShoesRun(void);
    afx_msg void OnOptionsAddShoesBike(void);
    afx_msg void OnOptionsAddBike(void);
    afx_msg void OnOptionsAddLocationRun(void);
    afx_msg void OnOptionsAddLocationBike(void);
    afx_msg void OnOptionsAddLocationSwim(void);
    afx_msg void OnOptionsAddLocationStrength(void);
    afx_msg void OnOptionsAddCourseRun(void);
    afx_msg void OnOptionsAddCourseBike(void);
    afx_msg void OnOptionsAddCourseSwim(void);
    afx_msg void OnOptionsAddCourseDuathlon(void);
    afx_msg void OnOptionsAddCourseTriathlon(void);
    afx_msg void OnOptionsAddWorkout(void);
	afx_msg void OnOptionsEditUser(void);
    afx_msg void OnOptionsDeleteWorkout(void);
	afx_msg void OnOptionsDeleteUpcomingWorkout(void);
	afx_msg void OnOptionsDeleteUpcomingRace(void);
    afx_msg void OnOptionsAddUpcomingRace(void);
    afx_msg void OnOptionsAddUpcomingWorkout(void);
    afx_msg void OnOptionsAddMultipleItems(void);
    afx_msg void OnViewDaySummary(void);
    afx_msg void OnViewWeekSummaryRun(void);
    afx_msg void OnViewMonthSummaryRun(void);
    afx_msg void OnViewFullSummaryRun(void);
    afx_msg void OnViewCustomSummaryRun(void);
    afx_msg void OnViewWeekSummaryBike(void);
    afx_msg void OnViewMonthSummaryBike(void);
    afx_msg void OnViewFullSummaryBike(void);
    afx_msg void OnViewCustomSummaryBike(void);
    afx_msg void OnViewWeekSummarySwim(void);
    afx_msg void OnViewMonthSummarySwim(void);
    afx_msg void OnViewFullSummarySwim(void);
    afx_msg void OnViewCustomSummarySwim(void);
    afx_msg void OnViewWeekSummaryStrength(void);
    afx_msg void OnViewMonthSummaryStrength(void);
    afx_msg void OnViewFullSummaryStrength(void);
    afx_msg void OnViewCustomSummaryStrength(void);
    afx_msg void OnViewWeekSummaryMulti(void);
    afx_msg void OnViewMonthSummaryMulti(void);
    afx_msg void OnViewFullSummaryMulti(void);
    afx_msg void OnViewCustomSummaryMulti(void);
    afx_msg void OnViewShoeSummaryRun(void);
    afx_msg void OnViewShoeSummaryBike(void);
    afx_msg void OnViewBikeSummary(void);
    afx_msg void OnViewCurrentNotes(void);
    afx_msg void OnViewPersonalRecordsRun(void);
    afx_msg void OnViewPersonalRecordsBike(void);
    afx_msg void OnViewPersonalRecordsSwim(void);
    afx_msg void OnViewPersonalRecordsDuathlon(void);
    afx_msg void OnViewPersonalRecordsTriathlon(void);
    afx_msg void OnViewRaceSummaryRun(void);
    afx_msg void OnViewRaceSummaryBike(void);
    afx_msg void OnViewRaceSummarySwim(void);
    afx_msg void OnViewRaceSummaryDuathlon(void);
    afx_msg void OnViewRaceSummaryTriathlon(void);
    afx_msg void OnViewLocationSummaryRun(void);
    afx_msg void OnViewLocationSummaryBike(void);
    afx_msg void OnViewLocationSummarySwim(void);
    afx_msg void OnViewLocationSummaryStrength(void);
    afx_msg void OnViewPoolPersonalRecords(void);
    afx_msg void OnViewTrackPersonalRecords(void);
	afx_msg void OnViewInjuryTracker(void);
    afx_msg void OnViewGraphLarge(void);
    afx_msg void OnViewGraphMedium(void);
    afx_msg void OnViewGraphSmall(void);
    afx_msg void OnMiscPaceCalc(void);
    afx_msg void OnMiscDistConvert(void);
	afx_msg void OnMiscCalories(void);
	afx_msg void OnMiscSearch(void);
    afx_msg void OnHelpHelpTopics(void);
	afx_msg void OnHelpDonate(void);
    afx_msg void OnHelpAbout(void);
    afx_msg void OnTimer(UINT unID);

    afx_msg void OnUpdateOpenUser(CCmdUI* pCmdUI);
    afx_msg void OnUpdateSaveUser(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCloseUser(CCmdUI* pCmdUI);
    afx_msg void OnUpdateConvert1(CCmdUI* pCmdUI);
    afx_msg void OnUpdateConvert3(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePrintToFile(CCmdUI* pCmdUI);
    afx_msg void OnUpdateUserOptions(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUser(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddLocationRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddMultipleItems(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddLocationBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddLocationSwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddLocationStrength(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddCourseRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddCourseBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddCourseSwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddCourseDuathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddCourseTriathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddShoesRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddShoesBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddWorkout(CCmdUI* pCmdUI);
    afx_msg void OnUpdateDeleteWorkout(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeleteUpcomingWorkout(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeleteUpcomingRace(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddUpcomingRace(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAddUpcomingWorkout(CCmdUI* pCmdUI);
    afx_msg void OnUpdateGoToDay(CCmdUI* pCmdUI);
    afx_msg void OnUpdateDaySummary(CCmdUI* pCmdUI);
    afx_msg void OnUpdateWeekSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateMonthSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateFullSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCustomSummaryRun(CCmdUI* pCmdUI);    
    afx_msg void OnUpdateWeekSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateMonthSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateFullSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCustomSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateWeekSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateMonthSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateFullSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCustomSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateWeekSummaryStrength(CCmdUI* pCmdUI);
    afx_msg void OnUpdateMonthSummaryStrength(CCmdUI* pCmdUI);
    afx_msg void OnUpdateFullSummaryStrength(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCustomSummaryStrength(CCmdUI* pCmdUI);
    afx_msg void OnUpdateWeekSummaryMulti(CCmdUI* pCmdUI);
    afx_msg void OnUpdateMonthSummaryMulti(CCmdUI* pCmdUI);
    afx_msg void OnUpdateFullSummaryMulti(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCustomSummaryMulti(CCmdUI* pCmdUI);
    afx_msg void OnUpdateShoeSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateShoeSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateBikeSummary(CCmdUI* pCmdUI);
    afx_msg void OnUpdateRaceSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateRaceSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateRaceSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateRaceSummaryDuathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdateRaceSummaryTriathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdateLocationSummaryRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdateLocationSummaryBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdateLocationSummarySwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdateLocationSummaryStrength(CCmdUI* pCmdUI);
	afx_msg void OnUpdateInjuryTracker(CCmdUI* pCmdUI);
    afx_msg void OnUpdateCurrentNotes(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePersonalRecordsRun(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePersonalRecordsBike(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePersonalRecordsSwim(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePersonalRecordsDuathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePersonalRecordsTriathlon(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePoolPersonalRecords(CCmdUI* pCmdUI);
    afx_msg void OnUpdateTrackPersonalRecords(CCmdUI* pCmdUI);
    afx_msg void OnUpdateViewGraphLarge(CCmdUI* pCmdUI);
    afx_msg void OnUpdateViewGraphMedium(CCmdUI* pCmdUI);
    afx_msg void OnUpdateViewGraphSmall(CCmdUI* pCmdUI);
    afx_msg void OnUpdatePaceCalc(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalories(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSearch(CCmdUI* pCmdUI);
    afx_msg void OnUpdateHelpTopics(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDonate(CCmdUI* pCmdUI);
    afx_msg void OnUpdateAbout(CCmdUI* pCmdUI);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DYNCREATE(CRunningLogView)
    DECLARE_MENUXP()

    // data
    CCalendarCtl* m_pCalendar;
    CBitmap m_bmpGrad;
    CButtonST* m_pButtonPrev;
    CButtonST* m_pButtonNext;

    CDC* m_pDCBmp;
    CBitmap* m_pBmpOld;
    
    bool m_bDoingContextMenu;
    CExpandWnd* m_pExpando;
    int m_nTimerID;
    bool m_fModified;
    bool m_fUserOpen;
    CSize m_aszWindow[2];
    int m_nLastMouseDay;
};


#ifndef _DEBUG  // debug version in RunningLogView.cpp
inline CRunningLogDoc* CRunningLogView::GetDocument() const
   { return reinterpret_cast<CRunningLogDoc*>(m_pDocument); }
#endif