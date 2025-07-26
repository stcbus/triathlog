#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"
#include "SheetTriathLogPage.h"
#include "SheetRunEZPage.h"
#include "SheetRunNormalPage.h"
#include "SheetRunHardPage.h"
#include "SheetRunTempoPage.h"
#include "SheetRunIntervalsPage.h"
#include "SheetRunHillsPage.h"
#include "SheetRunTreadmillPage.h"
#include "SheetRunPoolPage.h"
#include "SheetRunMiscPage.h"
#include "SheetBikeEZPage.h"
#include "SheetBikeNormalPage.h"
#include "SheetBikeHardPage.h"
#include "SheetBikeIntervalsPage.h"
#include "SheetBikeHillsPage.h"
#include "SheetBikeTrainerPage.h"
#include "SheetBikeMiscPage.h"
#include "SheetBikeMountainBikePage.h"
#include "SheetBikeTimeTrialPage.h"
#include "SheetSwimEZPage.h"
#include "SheetSwimNormalPage.h"
#include "SheetSwimHardPage.h"
#include "SheetSwimIntervalsPage.h"
#include "SheetSwimOpenWaterPage.h"
#include "SheetSwimDrillsPage.h"
#include "SheetSwimMiscPage.h"
#include "SheetStrengthAbsPage.h"
#include "SheetStrengthWeightsPage.h"
#include "SheetStrengthMiscPage.h"
#include "SheetRaceRunPage.h"
#include "SheetRaceBikePage.h"
#include "SheetRaceSwimPage.h"
#include "SheetRaceDuathlonPage.h"
#include "SheetRaceTriathlonPage.h"
#include "TabCtrlEx.h"
#include "DayLog.h"


class CDaySummarySheet : public CPropertySheet
{
public:
    CDaySummarySheet(LPCTSTR pszCaption, bool bAllowSave, CWnd* pParentWnd = NULL);
    ~CDaySummarySheet();

    CDayLog* GetDay(void) const;
    void SetDay(CDayLog* pDay);
    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
    bool IsModified(void) const;
    void SetModified(bool fMod);
	bool AllowingSave(void) const;

    BOOL OnInitDialog(void);
    virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

    void OnSaveData(void);
	void OnOpenDataFile(void);
    void UpdateOK(bool bValid);

    bool Initialize(void);

protected:
    void GetWorkoutTypes(int& rnRunEZ, int& rnRunHard, int& rnRunHills, int& rnRunIntervals,
                         int& rnRunMisc, int& rnRunNormal, int& rnRunPool, int& rnRunTempo,
                         int& rnRunTreadmill, int& rnBikeEZ, int& rnBikeHard, int& rnBikeHills, 
                         int& rnBikeIntervals, int& rnBikeMisc, int& rnBikeNormal, int& rnBikeTrainer, int& rnBikeMountainBike, int& rnBikeTimeTrial,
                         int& rnSwimDrills, int& rnSwimEZ, int& rnSwimHard, int& rnSwimIntervals,
                         int& rnSwimMisc, int& rnSwimNormal, int& rnSwimOpenWater, int& rnStrengthAbs,
                         int& rnStrengthMisc, int& rnStrengthWeights, int& rnRaceRun, int& rnRaceBike,
                         int& rnRaceSwim, int& rnRaceDuathlon, int& rnRaceTriathlon);
    bool CreatePages(void);
    void EnableTabs(bool fEnable);

    DECLARE_MESSAGE_MAP()

    CTabCtrlEx m_tabExCtrl;

    CSheetRunEZPage* m_pRunEZ; 
    CSheetRunHardPage* m_pRunHard; 
    CSheetRunHillsPage* m_pRunHills; 
    CSheetRunIntervalsPage* m_pRunIntervals;
    CSheetRunMiscPage* m_pRunMisc; 
    CSheetRunNormalPage* m_pRunNormal; 
    CSheetRunPoolPage* m_pRunPool; 
    CSheetRunTempoPage* m_pRunTempo;
    CSheetRunTreadmillPage* m_pRunTreadmill; 
    CSheetBikeEZPage* m_pBikeEZ; 
    CSheetBikeHardPage* m_pBikeHard; 
    CSheetBikeHillsPage* m_pBikeHills; 
    CSheetBikeIntervalsPage* m_pBikeIntervals; 
    CSheetBikeMiscPage* m_pBikeMisc; 
    CSheetBikeNormalPage* m_pBikeNormal; 
    CSheetBikeTrainerPage* m_pBikeTrainer;
	CSheetBikeMountainBikePage* m_pBikeMountainBike;
	CSheetBikeTimeTrialPage* m_pBikeTimeTrial;
    CSheetSwimDrillsPage* m_pSwimDrills; 
    CSheetSwimEZPage* m_pSwimEZ; 
    CSheetSwimHardPage* m_pSwimHard; 
    CSheetSwimIntervalsPage* m_pSwimIntervals;
    CSheetSwimMiscPage* m_pSwimMisc; 
    CSheetSwimNormalPage* m_pSwimNormal;
    CSheetSwimOpenWaterPage* m_pSwimOpenWater; 
    CSheetStrengthAbsPage* m_pStrengthAbs;
    CSheetStrengthMiscPage* m_pStrengthMisc; 
    CSheetStrengthWeightsPage* m_pStrengthWeights; 
    CSheetRaceRunPage* m_pRaceRun; 
    CSheetRaceBikePage* m_pRaceBike;
    CSheetRaceSwimPage* m_pRaceSwim; 
    CSheetRaceDuathlonPage* m_pRaceDuathlon;
    CSheetRaceTriathlonPage* m_pRaceTriathlon;
    CDayLog* m_pDay;
    CButton m_btnSave;
	CButton m_btnOpenDataFile;
    CUser* m_pUser;
    bool m_fModified;
    int m_nRunEZ; 
    int m_nRunHard; 
    int m_nRunHills; 
    int m_nRunIntervals;
    int m_nRunMisc; 
    int m_nRunNormal; 
    int m_nRunPool; 
    int m_nRunTempo;
    int m_nRunTreadmill; 
    int m_nBikeEZ; 
    int m_nBikeHard; 
    int m_nBikeHills; 
    int m_nBikeIntervals; 
    int m_nBikeMisc; 
    int m_nBikeNormal; 
    int m_nBikeTrainer;
	int m_nBikeMountainBike;
	int m_nBikeTimeTrial;
    int m_nSwimDrills; 
    int m_nSwimEZ; 
    int m_nSwimHard; 
    int m_nSwimIntervals;
    int m_nSwimMisc; 
    int m_nSwimNormal;
    int m_nSwimOpenWater; 
    int m_nStrengthAbs;
    int m_nStrengthMisc; 
    int m_nStrengthWeights; 
    int m_nRaceRun; 
    int m_nRaceBike;
    int m_nRaceSwim; 
    int m_nRaceDuathlon;
    int m_nRaceTriathlon;

	bool m_bAllowSave;
};