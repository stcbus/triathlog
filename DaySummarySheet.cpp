#include "StdAfx.h"
#include "RunningLog.h"
#include "RunningLogView.h"
#include "Util.h"
#include "Workout.h"
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
#include "DayLog.h"
#include "TabCtrlEx.h"
#include "DaySummarySheet.h"

BEGIN_MESSAGE_MAP(CDaySummarySheet, CPropertySheet)
    ON_BN_CLICKED(IDB_SAVE, OnSaveData)
	ON_BN_CLICKED(IDB_OPENDATAFILE, OnOpenDataFile)
END_MESSAGE_MAP()


CDaySummarySheet::CDaySummarySheet(LPCTSTR pszCaption, bool bAllowSave, CWnd* pParentWnd /* = NULL */) : CPropertySheet(pszCaption, pParentWnd)
{
    SetModified(false);
    m_pRunEZ = NULL; 
    m_pRunHard = NULL; 
    m_pRunHills = NULL; 
    m_pRunIntervals = NULL;
    m_pRunMisc = NULL; 
    m_pRunNormal = NULL; 
    m_pRunPool = NULL; 
    m_pRunTempo = NULL;
    m_pRunTreadmill = NULL; 
    m_pBikeEZ = NULL; 
    m_pBikeHard = NULL; 
    m_pBikeHills = NULL; 
    m_pBikeIntervals = NULL; 
    m_pBikeMisc = NULL; 
    m_pBikeNormal = NULL; 
    m_pBikeTrainer = NULL;
	m_pBikeMountainBike = NULL;
	m_pBikeTimeTrial = NULL;
    m_pSwimDrills = NULL; 
    m_pSwimEZ = NULL; 
    m_pSwimHard = NULL; 
    m_pSwimIntervals = NULL;
    m_pSwimMisc = NULL; 
    m_pSwimNormal = NULL;
    m_pSwimOpenWater = NULL; 
    m_pStrengthAbs = NULL;
    m_pStrengthMisc = NULL; 
    m_pStrengthWeights = NULL; 
    m_pRaceRun = NULL; 
    m_pRaceBike = NULL;
    m_pRaceSwim = NULL; 
    m_pRaceDuathlon = NULL;
    m_pRaceTriathlon = NULL;
    m_pDay = NULL;
    m_nRunEZ = 0; 
    m_nRunHard = 0; 
    m_nRunHills = 0; 
    m_nRunIntervals = 0;
    m_nRunMisc = 0; 
    m_nRunNormal = 0; 
    m_nRunPool = 0; 
    m_nRunTempo = 0;
    m_nRunTreadmill = 0; 
    m_nBikeEZ = 0; 
    m_nBikeHard = 0; 
    m_nBikeHills = 0; 
    m_nBikeIntervals = 0; 
    m_nBikeMisc = 0; 
    m_nBikeNormal = 0; 
    m_nBikeTrainer = 0;
	m_nBikeMountainBike = 0;
	m_nBikeTimeTrial = 0;
    m_nSwimDrills = 0; 
    m_nSwimEZ = 0; 
    m_nSwimHard = 0; 
    m_nSwimIntervals = 0;
    m_nSwimMisc = 0; 
    m_nSwimNormal = 0;
    m_nSwimOpenWater = 0; 
    m_nStrengthAbs = 0;
    m_nStrengthMisc = 0; 
    m_nStrengthWeights = 0; 
    m_nRaceRun = 0; 
    m_nRaceBike = 0;
    m_nRaceSwim = 0; 
    m_nRaceDuathlon = 0;
    m_nRaceTriathlon = 0;

	m_bAllowSave = bAllowSave;
}


CDaySummarySheet::~CDaySummarySheet(void)
{
    if(NULL != m_pRunEZ)
    {
        delete[] m_pRunEZ;
        m_pRunEZ = NULL;
    }

    if(NULL != m_pRunHard)
    {
        delete[] m_pRunHard;
        m_pRunHard = NULL;
    }

    if(NULL != m_pRunHills)
    {
        delete[] m_pRunHills;
        m_pRunHills = NULL;
    }

    if(NULL != m_pRunIntervals)
    {
        delete[] m_pRunIntervals;
        m_pRunIntervals = NULL;
    }

    if(NULL != m_pRunMisc)
    {
        delete[] m_pRunMisc;
        m_pRunMisc = NULL;
    }

    if(NULL != m_pRunNormal)
    {
        delete[] m_pRunNormal;
        m_pRunNormal = NULL;
    }

    if(NULL != m_pRunPool)
    {
        delete[] m_pRunPool;
        m_pRunPool = NULL;
    }

    if(NULL != m_pRunTempo)
    {
        delete[] m_pRunTempo;
        m_pRunTempo = NULL;
    }

    if(NULL != m_pRunTreadmill)
    {
        delete[] m_pRunTreadmill;
        m_pRunTreadmill = NULL;
    }

    if(NULL != m_pBikeEZ)
    {
        delete[] m_pBikeEZ;
        m_pBikeEZ = NULL;
    }

    if(NULL != m_pBikeHard)
    {
        delete[] m_pBikeHard;
        m_pBikeHard = NULL;
    }

    if(NULL != m_pBikeHills)
    {
        delete[] m_pBikeHills;
        m_pBikeHills = NULL;
    }

    if(NULL != m_pBikeIntervals)
    {
        delete[] m_pBikeIntervals;
        m_pBikeIntervals = NULL;
    }

    if(NULL != m_pBikeMisc)
    {
        delete[] m_pBikeMisc;
        m_pBikeMisc = NULL;
    }

    if(NULL != m_pBikeNormal)
    {
        delete[] m_pBikeNormal;
        m_pBikeNormal = NULL;
    }

    if(NULL != m_pBikeTrainer)
    {
        delete[] m_pBikeTrainer;
        m_pBikeTrainer = NULL;
    }

    if(NULL != m_pBikeMountainBike)
    {
        delete[] m_pBikeMountainBike;
        m_pBikeMountainBike = NULL;
    }

    if(NULL != m_pBikeTimeTrial)
    {
        delete[] m_pBikeTimeTrial;
        m_pBikeTimeTrial = NULL;
    }

    if(NULL != m_pSwimDrills)
    {
        delete[] m_pSwimDrills;
        m_pSwimDrills = NULL;
    }

    if(NULL != m_pSwimEZ)
    {
        delete[] m_pSwimEZ;
        m_pSwimEZ = NULL;
    }

    if(NULL != m_pSwimHard)
    {
        delete[] m_pSwimHard;
        m_pSwimHard = NULL;
    }

    if(NULL != m_pSwimIntervals)
    {
        delete[] m_pSwimIntervals;
        m_pSwimIntervals = NULL;
    }

    if(NULL != m_pSwimMisc)
    {
        delete[] m_pSwimMisc;
        m_pSwimMisc = NULL;
    }

    if(NULL != m_pSwimNormal)
    {
        delete[] m_pSwimNormal;
        m_pSwimNormal = NULL;
    }

    if(NULL != m_pSwimOpenWater)
    {
        delete[] m_pSwimOpenWater;
        m_pSwimOpenWater = NULL;
    }

    if(NULL != m_pStrengthAbs)
    {
        delete[] m_pStrengthAbs;
        m_pStrengthAbs = NULL;
    }

    if(NULL != m_pStrengthMisc)
    {
        delete[] m_pStrengthMisc;
        m_pStrengthMisc = NULL;
    }

    if(NULL != m_pStrengthWeights)
    {
        delete[] m_pStrengthWeights;
        m_pStrengthWeights = NULL;
    }

    if(NULL != m_pRaceRun)
    {
        delete[] m_pRaceRun;
        m_pRaceRun = NULL;
    }

    if(NULL != m_pRaceBike)
    {
        delete[] m_pRaceBike;
        m_pRaceBike = NULL;
    }

    if(NULL != m_pRaceSwim)
    {
        delete[] m_pRaceSwim;
        m_pRaceSwim = NULL;
    }

    if(NULL != m_pRaceDuathlon)
    {
        delete[] m_pRaceDuathlon;
        m_pRaceDuathlon = NULL;
    }

    if(NULL != m_pRaceTriathlon)
    {
        delete[] m_pRaceTriathlon;
        m_pRaceTriathlon = NULL;
    }

    if(m_btnSave.m_hWnd != NULL)
    {
        m_btnSave.DestroyWindow();
    }
}


BOOL CDaySummarySheet::OnInitDialog(void)
{
    BOOL fResult = CPropertySheet::OnInitDialog(); 
	        
    m_tabExCtrl.Install(this);

    CWnd *pWnd = GetDlgItem(ID_APPLY_NOW);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(SW_HIDE);
    }

    pWnd = GetDlgItem(IDHELP);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(SW_HIDE);
    }

    pWnd = GetDlgItem(IDCANCEL);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(SW_HIDE);
    }

    CRect rcButton;
    int nSpacing = 6;     
    CWnd* pWndOK = GetDlgItem(IDOK);
    if(NULL != pWndOK)
    {
        // move ok to the right and rename
        pWndOK->GetWindowRect(&rcButton);  
        int nWidth = rcButton.Width();
        ScreenToClient(&rcButton);
        int nRight = (rcButton.Width() + nSpacing) * 2;
        rcButton.OffsetRect(nRight, 0);        
        pWndOK->MoveWindow(&rcButton);
        pWndOK->SetWindowText("Close");
        pWndOK->SetFocus();

        // add edit button
        CRect rcTab;
        GetTabControl()->GetWindowRect(&rcTab);
        ScreenToClient(&rcTab);

        rcButton.left = rcTab.left;
        rcButton.right = rcTab.left + nWidth;

		if(true == AllowingSave())
		{
			m_btnSave.Create("Save", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, rcButton,
							this, IDB_SAVE);
			m_btnSave.SetFont(GetFont());
		}

        // add open data file button
		int nOffset = rcButton.Width() + 3 * nSpacing;
		rcButton.OffsetRect(nOffset, 0);
		rcButton.InflateRect(nSpacing, 0, nSpacing, 0);

		m_btnOpenDataFile.Create("Open data file", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, rcButton,
						this, IDB_OPENDATAFILE);
		m_btnOpenDataFile.SetFont(GetFont());
    }

    // set the tab names
    CTabCtrl* pTab = GetTabControl();
    CDayLog* pDay = GetDay();
    if((NULL != pDay) && (NULL != pTab))
    {
        WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
        for(int i = 0; i < rarWorkouts.GetCount(); i++)
        {
            CWorkout* pWorkout = rarWorkouts.GetAt(i);
            if(NULL != pWorkout)
            {
                CString strText = CUtil::ActivityToString(pWorkout->GetActivityType()) + ": " + 
                                  CUtil::WorkoutToString(pWorkout);
                TC_ITEM item;
                item.mask = TCIF_TEXT;
                item.pszText = strText.GetBuffer();
                item.cchTextMax = strText.GetLength();

                pTab->SetItem(i, &item);
            }
        }
    }
    
	return fResult;
}


BOOL CDaySummarySheet::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	NMHDR* pNMHdr = (NMHDR*)lParam;

	BOOL bRet = CPropertySheet::OnNotify(wParam, lParam, pResult);
    bool fRet = (0 != bRet);
	if(TCN_SELCHANGING == pNMHdr->code)
	{
        CSheetTriathLogPage *pActive = (CSheetTriathLogPage*)GetActivePage();
        if(NULL != pActive)
        {
            fRet &= pActive->IsChangeAllowed();
            *pResult = !fRet;
            return TRUE;
        }
	}

    return CPropertySheet::OnNotify(wParam, lParam, pResult);
}


void CDaySummarySheet::OnSaveData(void)
{
    bool fRes = true;
    for(int i = 0; i < m_nRunEZ; i++)
    {
        fRes &= m_pRunEZ[i].WriteContents();
    }

    for(int i = 0; i < m_nRunHard; i++)
    {
        fRes &= m_pRunHard[i].WriteContents();
    }

    for(int i = 0; i < m_nRunHills; i++)
    {
        fRes &= m_pRunHills[i].WriteContents();
    }

    for(int i = 0; i < m_nRunIntervals; i++)
    {
        fRes &= m_pRunIntervals[i].WriteContents();
    }

    for(int i = 0; i < m_nRunMisc; i++)
    {
        fRes &= m_pRunMisc[i].WriteContents();
    }

    for(int i = 0; i < m_nRunNormal; i++)
    {
        fRes &= m_pRunNormal[i].WriteContents();
    }

    for(int i = 0; i < m_nRunPool; i++)
    {
        fRes &= m_pRunPool[i].WriteContents();
    }

    for(int i = 0; i < m_nRunTempo; i++)
    {
        fRes &= m_pRunTempo[i].WriteContents();
    }

    for(int i = 0; i < m_nRunTreadmill; i++)
    {
        fRes &= m_pRunTreadmill[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeEZ; i++)
    {
        fRes &= m_pBikeEZ[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeHard; i++)
    {
        fRes &= m_pBikeHard[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeHills; i++)
    {
        fRes &= m_pBikeHills[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeIntervals; i++)
    {
        fRes &= m_pBikeIntervals[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeMisc; i++)
    {
        fRes &= m_pBikeMisc[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeNormal; i++)
    {
        fRes &= m_pBikeNormal[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeTrainer; i++)
    {
        fRes &= m_pBikeTrainer[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeMountainBike; i++)
    {
        fRes &= m_pBikeMountainBike[i].WriteContents();
    }

    for(int i = 0; i < m_nBikeTimeTrial; i++)
    {
        fRes &= m_pBikeTimeTrial[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimDrills; i++)
    {
        fRes &= m_pSwimDrills[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimEZ; i++)
    {
        fRes &= m_pSwimEZ[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimHard; i++)
    {
        fRes &= m_pSwimHard[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimIntervals; i++)
    {
        fRes &= m_pSwimIntervals[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimMisc; i++)
    {
        fRes &= m_pSwimMisc[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimNormal; i++)
    {
        fRes &= m_pSwimNormal[i].WriteContents();
    }

    for(int i = 0; i < m_nSwimOpenWater; i++)
    {
        fRes &= m_pSwimOpenWater[i].WriteContents();
    }

    for(int i = 0; i < m_nStrengthAbs; i++)
    {
        fRes &= m_pStrengthAbs[i].WriteContents();
    }

    for(int i = 0; i < m_nStrengthMisc; i++)
    {
        fRes &= m_pStrengthMisc[i].WriteContents();
    }

    for(int i = 0; i < m_nStrengthWeights; i++)
    {
        fRes &= m_pStrengthWeights[i].WriteContents();
    }

    for(int i = 0; i < m_nRaceRun; i++)
    {
        fRes &= m_pRaceRun[i].WriteContents();
    }

    for(int i = 0; i < m_nRaceBike; i++)
    {
        fRes &= m_pRaceBike[i].WriteContents();
    }

    for(int i = 0; i < m_nRaceSwim; i++)
    {
        fRes &= m_pRaceSwim[i].WriteContents();
    }

    for(int i = 0; i < m_nRaceDuathlon; i++)
    {
        fRes &= m_pRaceDuathlon[i].WriteContents();
    }

    for(int i = 0; i < m_nRaceTriathlon; i++)
    {
        fRes &= m_pRaceTriathlon[i].WriteContents();
    }

    SetModified(true);
}


void CDaySummarySheet::OnOpenDataFile(void)
{
    CSheetTriathLogPage *pActive = (CSheetTriathLogPage*)GetActivePage();
    if(NULL != pActive)
    {
		CString strFile = pActive->GetDataFilename();

		if(true == strFile.IsEmpty())
		{
			AfxMessageBox("There is no data file currently associated with this workout");
			return;
		}

		HINSTANCE hResult = ShellExecute(NULL, _T("open"), strFile, NULL, NULL, SW_SHOW);

		// if it failed, nothing to do
		if((UINT)hResult <= HINSTANCE_ERROR) 
		{
			CString strMessage;
			strMessage.Format("Could not find the program that opens the file %s", strFile);
			AfxMessageBox(strMessage);
			return;
		}
	}
}


void CDaySummarySheet::UpdateOK(bool bValid)
{
    CWnd* pWnd = GetDlgItem(IDB_SAVE);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(bValid);
    }

    EnableTabs(bValid);
}


void CDaySummarySheet::EnableTabs(bool fEnable)
{
    if(::IsWindow(m_tabExCtrl.m_hWnd))
    {
        int iSel = m_tabExCtrl.GetCurSel();
        for(int i = 0; i < m_tabExCtrl.GetItemCount(); i++)
        {
            if(iSel != i)
            {
                m_tabExCtrl.EnableItem(i, fEnable);
            }
        }
    }
}


bool CDaySummarySheet::Initialize(void)
{
    CDayLog* pDay = GetDay();
    if(NULL == pDay)
    {
        return false;
    }

    GetWorkoutTypes(m_nRunEZ, m_nRunHard, m_nRunHills, m_nRunIntervals, m_nRunMisc, m_nRunNormal, m_nRunPool, m_nRunTempo,
                    m_nRunTreadmill, m_nBikeEZ, m_nBikeHard, m_nBikeHills, m_nBikeIntervals, m_nBikeMisc, m_nBikeNormal, m_nBikeTrainer, m_nBikeMountainBike,m_nBikeTimeTrial,
                    m_nSwimDrills, m_nSwimEZ, m_nSwimHard, m_nSwimIntervals, m_nSwimMisc, m_nSwimNormal, m_nSwimOpenWater, m_nStrengthAbs,
                    m_nStrengthMisc, m_nStrengthWeights, m_nRaceRun, m_nRaceBike, m_nRaceSwim, m_nRaceDuathlon, m_nRaceTriathlon); 

    if(CreatePages())
    {
        int nRunEZAdded = 0; 
        int nRunHardAdded = 0; 
        int nRunHillsAdded = 0; 
        int nRunIntervalsAdded = 0;
        int nRunMiscAdded = 0; 
        int nRunNormalAdded = 0; 
        int nRunPoolAdded = 0; 
        int nRunTempoAdded = 0;
        int nRunTreadmillAdded = 0; 
        int nBikeEZAdded = 0; 
        int nBikeHardAdded = 0; 
        int nBikeHillsAdded = 0; 
        int nBikeIntervalsAdded = 0; 
        int nBikeMiscAdded = 0; 
        int nBikeNormalAdded = 0; 
        int nBikeTrainerAdded = 0;
		int nBikeMountainBikeAdded = 0;
		int nBikeTimeTrialAdded = 0;
        int nSwimDrillsAdded = 0; 
        int nSwimEZAdded = 0; 
        int nSwimHardAdded = 0; 
        int nSwimIntervalsAdded = 0;
        int nSwimMiscAdded = 0; 
        int nSwimNormalAdded = 0;
        int nSwimOpenWaterAdded = 0; 
        int nStrengthAbsAdded = 0;
        int nStrengthMiscAdded = 0; 
        int nStrengthWeightsAdded = 0; 
        int nRaceRunAdded = 0; 
        int nRaceBikeAdded = 0;
        int nRaceSwimAdded = 0; 
        int nRaceDuathlonAdded = 0;
        int nRaceTriathlonAdded = 0;

        WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
        for(int i = 0; i < rarWorkouts.GetCount(); i++)
        {
            CWorkout* pWorkout = rarWorkouts.GetAt(i);
            if(NULL != pWorkout)
            {
                switch(pWorkout->GetActivityType())
                {
                case ACTIVITY_RUNNING:
                    {
                        switch(pWorkout->GetType())
                        {
                        case RUNTYPE_EZ:
                            {
                                m_pRunEZ[nRunEZAdded].SetParentSheet(this);
                                m_pRunEZ[nRunEZAdded].SetUser(GetUser());
                                m_pRunEZ[nRunEZAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunEZ[nRunEZAdded]);
                                nRunEZAdded++;;
                                break;
                            }

                        case RUNTYPE_HARD:
                            {
                                m_pRunHard[nRunHardAdded].SetParentSheet(this);
                                m_pRunHard[nRunHardAdded].SetUser(GetUser());
                                m_pRunHard[nRunHardAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunHard[nRunHardAdded]);
                                nRunHardAdded++;;
                                break;
                            }

                        case RUNTYPE_HILLS:
                            {
                                m_pRunHills[nRunHillsAdded].SetParentSheet(this);
                                m_pRunHills[nRunHillsAdded].SetUser(GetUser());
                                m_pRunHills[nRunHillsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunHills[nRunHillsAdded]);
                                nRunHillsAdded++;;
                                break;
                            }

                        case RUNTYPE_INTERVALS:
                            {
                                m_pRunIntervals[nRunIntervalsAdded].SetParentSheet(this);
                                m_pRunIntervals[nRunIntervalsAdded].SetUser(GetUser());
                                m_pRunIntervals[nRunIntervalsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunIntervals[nRunIntervalsAdded]);
                                nRunIntervalsAdded++;;
                                break;
                            }

                        case RUNTYPE_OTHER:
                            {
                                m_pRunMisc[nRunMiscAdded].SetParentSheet(this);
                                m_pRunMisc[nRunMiscAdded].SetUser(GetUser());
                                m_pRunMisc[nRunMiscAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunMisc[nRunMiscAdded]);
                                nRunMiscAdded++;;
                                break;
                            }

                        case RUNTYPE_NORMAL:
                            {
                                m_pRunNormal[nRunNormalAdded].SetParentSheet(this);
                                m_pRunNormal[nRunNormalAdded].SetUser(GetUser());
                                m_pRunNormal[nRunNormalAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunNormal[nRunNormalAdded]);
                                nRunNormalAdded++;;
                                break;
                            }

                        case RUNTYPE_POOL:
                            {
                                m_pRunPool[nRunPoolAdded].SetParentSheet(this);
                                m_pRunPool[nRunPoolAdded].SetUser(GetUser());
                                m_pRunPool[nRunPoolAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunPool[nRunPoolAdded]);
                                nRunPoolAdded++;;
                                break;
                            }

                        case RUNTYPE_TEMPO:
                            {
                                m_pRunTempo[nRunTempoAdded].SetParentSheet(this);
                                m_pRunTempo[nRunTempoAdded].SetUser(GetUser());
                                m_pRunTempo[nRunTempoAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunTempo[nRunTempoAdded]);
                                nRunTempoAdded++;;
                                break;
                            }

                        case RUNTYPE_TREADMILL:
                            {
                                m_pRunTreadmill[nRunTreadmillAdded].SetParentSheet(this);
                                m_pRunTreadmill[nRunTreadmillAdded].SetUser(GetUser());
                                m_pRunTreadmill[nRunTreadmillAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRunTreadmill[nRunTreadmillAdded]);
                                nRunTreadmillAdded++;;
                                break;
                            }
                        }

                        break;
                    }

                case ACTIVITY_BIKING:
                    {
                    switch(pWorkout->GetType())
                        {
                        case BIKETYPE_EZ:
                            {
                                m_pBikeEZ[nBikeEZAdded].SetParentSheet(this);
                                m_pBikeEZ[nBikeEZAdded].SetUser(GetUser());
                                m_pBikeEZ[nBikeEZAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeEZ[nBikeEZAdded]);
                                nBikeEZAdded++;;
                                break;
                            }

                        case BIKETYPE_HARD:
                            {
                                m_pBikeHard[nBikeHardAdded].SetParentSheet(this);
                                m_pBikeHard[nBikeHardAdded].SetUser(GetUser());
                                m_pBikeHard[nBikeHardAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeHard[nBikeHardAdded]);
                                nBikeHillsAdded++;;
                                break;
                            }

                        case BIKETYPE_HILLS:
                            {
                                m_pBikeHills[nBikeHillsAdded].SetParentSheet(this);
                                m_pBikeHills[nBikeHillsAdded].SetUser(GetUser());
                                m_pBikeHills[nBikeHillsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeHills[nBikeHillsAdded]);
                                nBikeHillsAdded++;;
                                break;
                            }

                        case BIKETYPE_INTERVALS:
                            {
                                m_pBikeIntervals[nBikeIntervalsAdded].SetParentSheet(this);
                                m_pBikeIntervals[nBikeIntervalsAdded].SetUser(GetUser());
                                m_pBikeIntervals[nBikeIntervalsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeIntervals[nBikeIntervalsAdded]);
                                nBikeIntervalsAdded++;;
                                break;
                            }

                        case BIKETYPE_OTHER:
                            {
                                m_pBikeMisc[nBikeMiscAdded].SetParentSheet(this);
                                m_pBikeMisc[nBikeMiscAdded].SetUser(GetUser());
                                m_pBikeMisc[nBikeMiscAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeMisc[nBikeMiscAdded]);
                                nBikeMiscAdded++;;
                                break;
                            }

                        case BIKETYPE_NORMAL:
                            {
                                m_pBikeNormal[nBikeNormalAdded].SetParentSheet(this);
                                m_pBikeNormal[nBikeNormalAdded].SetUser(GetUser());
                                m_pBikeNormal[nBikeNormalAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeNormal[nBikeNormalAdded]);
                                nBikeNormalAdded++;;
                                break;
                            }

                        case BIKETYPE_TRAINER:
                            {
                                m_pBikeTrainer[nBikeTrainerAdded].SetParentSheet(this);
                                m_pBikeTrainer[nBikeTrainerAdded].SetUser(GetUser());
                                m_pBikeTrainer[nBikeTrainerAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeTrainer[nBikeTrainerAdded]);
                                nBikeTrainerAdded++;;
                                break;
                            }
							
                        case BIKETYPE_MOUNTAINBIKE:
                            {
                                m_pBikeMountainBike[nBikeMountainBikeAdded].SetParentSheet(this);
                                m_pBikeMountainBike[nBikeMountainBikeAdded].SetUser(GetUser());
                                m_pBikeMountainBike[nBikeMountainBikeAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeMountainBike[nBikeMountainBikeAdded]);
                                nBikeMountainBikeAdded++;;
                                break;
                            }

                        case BIKETYPE_TIMETRIAL:
                            {
                                m_pBikeTimeTrial[nBikeTimeTrialAdded].SetParentSheet(this);
                                m_pBikeTimeTrial[nBikeTimeTrialAdded].SetUser(GetUser());
                                m_pBikeTimeTrial[nBikeTimeTrialAdded].SetWorkout(pWorkout);
                                AddPage(&m_pBikeTimeTrial[nBikeTimeTrialAdded]);
                                nBikeTimeTrialAdded++;;
                                break;
                            }
                        }

                        break;
                    }

                case ACTIVITY_SWIMMING:
                    {
                    switch(pWorkout->GetType())
                        {
                        case SWIMTYPE_DRILLS:
                            {
                                m_pSwimDrills[nSwimDrillsAdded].SetParentSheet(this);
                                m_pSwimDrills[nSwimDrillsAdded].SetUser(GetUser());
                                m_pSwimDrills[nSwimDrillsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimDrills[nSwimDrillsAdded]);
                                nSwimDrillsAdded++;;
                                break;
                            }

                        case SWIMTYPE_EZ:
                            {
                                m_pSwimEZ[nSwimEZAdded].SetParentSheet(this);
                                m_pSwimEZ[nSwimEZAdded].SetUser(GetUser());
                                m_pSwimEZ[nSwimEZAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimEZ[nSwimEZAdded]);
                                nSwimEZAdded++;;
                                break;
                            }

                        case SWIMTYPE_HARD:
                            {
                                m_pSwimHard[nSwimHardAdded].SetParentSheet(this);
                                m_pSwimHard[nSwimHardAdded].SetUser(GetUser());
                                m_pSwimHard[nSwimHardAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimHard[nSwimHardAdded]);
                                nSwimHardAdded++;;
                                break;
                            }

                        case SWIMTYPE_INTERVALS:
                            {
                                m_pSwimIntervals[nSwimIntervalsAdded].SetParentSheet(this);
                                m_pSwimIntervals[nSwimIntervalsAdded].SetUser(GetUser());
                                m_pSwimIntervals[nSwimIntervalsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimIntervals[nSwimIntervalsAdded]);
                                nSwimIntervalsAdded++;;
                                break;
                            }

                        case SWIMTYPE_OTHER:
                            {
                                m_pSwimMisc[nSwimMiscAdded].SetParentSheet(this);
                                m_pSwimMisc[nSwimMiscAdded].SetUser(GetUser());
                                m_pSwimMisc[nSwimMiscAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimMisc[nSwimMiscAdded]);
                                nSwimMiscAdded++;;
                                break;
                            }

                        case SWIMTYPE_NORMAL:
                            {
                                m_pSwimNormal[nSwimNormalAdded].SetParentSheet(this);
                                m_pSwimNormal[nSwimNormalAdded].SetUser(GetUser());
                                m_pSwimNormal[nSwimNormalAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimNormal[nSwimNormalAdded]);
                                nSwimNormalAdded++;;
                                break;
                            }

                        case SWIMTYPE_OPENWATER:
                            {
                                m_pSwimOpenWater[nSwimOpenWaterAdded].SetParentSheet(this);
                                m_pSwimOpenWater[nSwimOpenWaterAdded].SetUser(GetUser());
                                m_pSwimOpenWater[nSwimOpenWaterAdded].SetWorkout(pWorkout);
                                AddPage(&m_pSwimOpenWater[nSwimOpenWaterAdded]);
                                nSwimOpenWaterAdded++;;
                                break;
                            }
                        }
                        
                        break;
                    }

                case ACTIVITY_STRENGTH:
                    {
                    switch(pWorkout->GetType())
                        {
                        case STRENGTHTYPE_ABS:
                            {
                                m_pStrengthAbs[nStrengthAbsAdded].SetParentSheet(this);
                                m_pStrengthAbs[nStrengthAbsAdded].SetUser(GetUser());
                                m_pStrengthAbs[nStrengthAbsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pStrengthAbs[nStrengthAbsAdded]);
                                nStrengthAbsAdded++;;
                                break;
                            }

                        case STRENGTHTYPE_OTHER:
                            {
                                m_pStrengthMisc[nStrengthMiscAdded].SetParentSheet(this);
                                m_pStrengthMisc[nStrengthMiscAdded].SetUser(GetUser());
                                m_pStrengthMisc[nStrengthMiscAdded].SetWorkout(pWorkout);
                                AddPage(&m_pStrengthMisc[nStrengthMiscAdded]);
                                nStrengthMiscAdded++;;
                                break;
                            }

                        case STRENGTHTYPE_WEIGHTS:
                            {
                                m_pStrengthWeights[nStrengthWeightsAdded].SetParentSheet(this);
                                m_pStrengthWeights[nStrengthWeightsAdded].SetUser(GetUser());
                                m_pStrengthWeights[nStrengthWeightsAdded].SetWorkout(pWorkout);
                                AddPage(&m_pStrengthWeights[nStrengthWeightsAdded]);
                                nStrengthWeightsAdded++;;
                                break;
                            }
                        }
                        
                        break;
                    }

                case ACTIVITY_RACE:
                    {
                        switch(pWorkout->GetType())
                        {
                        case RACETYPE_RUN:
                            {
                                m_pRaceRun[nRaceRunAdded].SetParentSheet(this);
                                m_pRaceRun[nRaceRunAdded].SetUser(GetUser());
                                m_pRaceRun[nRaceRunAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRaceRun[nRaceRunAdded]);
                                nRaceRunAdded++;;
                                break;
                            }

                        case RACETYPE_BIKE:
                            {
                                m_pRaceBike[nRaceBikeAdded].SetParentSheet(this);
                                m_pRaceBike[nRaceBikeAdded].SetUser(GetUser());
                                m_pRaceBike[nRaceBikeAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRaceBike[nRaceBikeAdded]);
                                nRaceBikeAdded++;;
                                break;
                            }

                        case RACETYPE_SWIM:
                            {
                                m_pRaceSwim[nRaceSwimAdded].SetParentSheet(this);
                                m_pRaceSwim[nRaceSwimAdded].SetUser(GetUser());
                                m_pRaceSwim[nRaceSwimAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRaceSwim[nRaceSwimAdded]);
                                nRaceSwimAdded++;;
                                break;
                            }

                        case RACETYPE_DUATHLON:
                            {
                                m_pRaceDuathlon[nRaceDuathlonAdded].SetParentSheet(this);
                                m_pRaceDuathlon[nRaceDuathlonAdded].SetUser(GetUser());
                                m_pRaceDuathlon[nRaceDuathlonAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRaceDuathlon[nRaceDuathlonAdded]);
                                nRaceDuathlonAdded++;;
                                break;
                            }

                        case RACETYPE_TRIATHLON:
                            {
                                m_pRaceTriathlon[nRaceTriathlonAdded].SetParentSheet(this);
                                m_pRaceTriathlon[nRaceTriathlonAdded].SetUser(GetUser());
                                m_pRaceTriathlon[nRaceTriathlonAdded].SetWorkout(pWorkout);
                                AddPage(&m_pRaceTriathlon[nRaceTriathlonAdded]);
                                nRaceTriathlonAdded++;;
                                break;
                            }
                        }

                        break;
                    }
                }
            }
        }
    
        return true;
     }

     return false;
}


void CDaySummarySheet::GetWorkoutTypes(int& rnRunEZ, int& rnRunHard, int& rnRunHills, int& rnRunIntervals,
                                       int& rnRunMisc, int& rnRunNormal, int& rnRunPool, int& rnRunTempo,
                                       int& rnRunTreadmill, int& rnBikeEZ, int& rnBikeHard, int& rnBikeHills, 
                                       int& rnBikeIntervals, int& rnBikeMisc, int& rnBikeNormal, int& rnBikeTrainer, int& rnBikeMountainBike, int& rnBikeTimeTrial,
                                       int& rnSwimDrills, int& rnSwimEZ, int& rnSwimHard, int& rnSwimIntervals,
                                       int& rnSwimMisc, int& rnSwimNormal, int& rnSwimOpenWater, int& rnStrengthAbs,
                                       int& rnStrengthMisc, int& rnStrengthWeights, int& rnRaceRun, int& rnRaceBike,
                                       int& rnRaceSwim, int& rnRaceDuathlon, int& rnRaceTriathlon)
{
    CDayLog* pDay = GetDay();
    if(NULL == pDay)
    {
        return;
    }

    WORKOUTARRAY& rarWorkouts = pDay->GetRefWorkoutArray();
    for(int i = 0; i < rarWorkouts.GetCount(); i++)
    {
        CWorkout* pWorkout = rarWorkouts.GetAt(i);
        if(NULL != pWorkout)
        {
            switch(pWorkout->GetActivityType())
            {
            case ACTIVITY_RUNNING:
                {
                    switch(pWorkout->GetType())
                    {
                    case RUNTYPE_EZ:
                        {
                            rnRunEZ++;
                            break;
                        }

                    case RUNTYPE_HARD:
                        {
                            rnRunHard++;
                            break;
                        }

                    case RUNTYPE_HILLS:
                        {
                            rnRunHills++;
                            break;
                        }

                    case RUNTYPE_INTERVALS:
                        {
                            rnRunIntervals++;
                            break;
                        }

                    case RUNTYPE_OTHER:
                        {
                            rnRunMisc++;
                            break;
                        }

                    case RUNTYPE_NORMAL:
                        {
                            rnRunNormal++;
                            break;
                        }

                    case RUNTYPE_POOL:
                        {
                            rnRunPool++;
                            break;
                        }

                    case RUNTYPE_TEMPO:
                        {
                            rnRunTempo++;
                            break;
                        }

                    case RUNTYPE_TREADMILL:
                        {
                            rnRunTreadmill++;
                            break;
                        }
                    }

                    break;
                }

            case ACTIVITY_BIKING:
                {
                switch(pWorkout->GetType())
                    {
                    case BIKETYPE_EZ:
                        {
                            rnBikeEZ++;
                            break;
                        }

                    case BIKETYPE_HARD:
                        {
                            rnBikeHard++;
                            break;
                        }

                    case BIKETYPE_HILLS:
                        {
                            rnBikeHills++;
                            break;
                        }

                    case BIKETYPE_INTERVALS:
                        {
                            rnBikeIntervals++;
                            break;
                        }

                    case BIKETYPE_OTHER:
                        {
                            rnBikeMisc++;
                            break;
                        }

                    case BIKETYPE_NORMAL:
                        {
                            rnBikeNormal++;
                            break;
                        }

                    case BIKETYPE_TRAINER:
                        {
                            rnBikeTrainer++;
                            break;
                        }

					case BIKETYPE_MOUNTAINBIKE:
						{
							rnBikeMountainBike++;
							break;
						}

					case BIKETYPE_TIMETRIAL:
						{
							rnBikeTimeTrial++;
							break;
						}
                    }

                    break;
                }

            case ACTIVITY_SWIMMING:
                {
                switch(pWorkout->GetType())
                    {
                    case SWIMTYPE_DRILLS:
                        {
                            rnSwimDrills++;
                            break;
                        }

                    case SWIMTYPE_EZ:
                        {
                            rnSwimEZ++;
                            break;
                        }

                    case SWIMTYPE_HARD:
                        {
                            rnSwimHard++;
                            break;
                        }

                    case SWIMTYPE_INTERVALS:
                        {
                            rnSwimIntervals++;
                            break;
                        }

                    case SWIMTYPE_OTHER:
                        {
                            rnSwimMisc++;
                            break;
                        }

                    case SWIMTYPE_NORMAL:
                        {
                            rnSwimNormal++;
                            break;
                        }

                    case SWIMTYPE_OPENWATER:
                        {
                            rnSwimOpenWater++;
                            break;
                        }
                    }
                    
                    break;
                }

            case ACTIVITY_STRENGTH:
                {
                switch(pWorkout->GetType())
                    {
                    case STRENGTHTYPE_ABS:
                        {
                            rnStrengthAbs++;
                            break;
                        }

                    case STRENGTHTYPE_OTHER:
                        {
                            rnStrengthMisc++;
                            break;
                        }

                    case STRENGTHTYPE_WEIGHTS:
                        {
                            rnStrengthWeights++;
                            break;
                        }
                    }
                    
                    break;
                }

            case ACTIVITY_RACE:
                {
                    switch(pWorkout->GetType())
                    {
                    case RACETYPE_RUN:
                        {
                            rnRaceRun++;
                            break;
                        }

                    case RACETYPE_BIKE:
                        {
                            rnRaceBike++;
                            break;
                        }

                    case RACETYPE_SWIM:
                        {
                            rnRaceSwim++;
                            break;
                        }

                    case RACETYPE_DUATHLON:
                        {
                            rnRaceDuathlon++;
                            break;
                        }

                    case RACETYPE_TRIATHLON:
                        {
                            rnRaceTriathlon++;
                            break;
                        }
                    }

                    break;
                }
            }
        }
    }
}


bool CDaySummarySheet::CreatePages(void)
{
    if(m_nRunEZ != 0)
    {
        m_pRunEZ = new CSheetRunEZPage[m_nRunEZ];
        if(NULL == m_pRunEZ)
        {
            return false;
        }
    }

    if(m_nRunHard != 0)
    {
        m_pRunHard = new CSheetRunHardPage[m_nRunHard];
        if(NULL == m_pRunHard)
        {
            return false;
        }
    }

    if(m_nRunHills != 0)
    {
        m_pRunHills = new CSheetRunHillsPage[m_nRunHills];
        if(NULL == m_pRunHills)
        {
            return false;
        }
    }

    if(m_nRunIntervals != 0)
    {
        m_pRunIntervals = new CSheetRunIntervalsPage[m_nRunIntervals];
        if(NULL == m_pRunIntervals)
        {
            return false;
        }
    }

    if(m_nRunMisc != 0)
    {
        m_pRunMisc = new CSheetRunMiscPage[m_nRunMisc];
        if(NULL == m_pRunMisc)
        {
            return false;
        }
    }

    if(m_nRunNormal != 0)
    {
        m_pRunNormal = new CSheetRunNormalPage[m_nRunNormal];
        if(NULL == m_pRunNormal)
        {
            return false;
        }
    }

    if(m_nRunPool != 0)
    {
        m_pRunPool = new CSheetRunPoolPage[m_nRunPool];
        if(NULL == m_pRunPool)
        {
            return false;
        }
    }

    if(m_nRunTempo != 0)
    {
        m_pRunTempo = new CSheetRunTempoPage[m_nRunTempo];
        if(NULL == m_pRunTempo)
        {
            return false;
        }
    }

    if(m_nRunTreadmill != 0)
    {
        m_pRunTreadmill = new CSheetRunTreadmillPage[m_nRunTreadmill];
        if(NULL == m_pRunTreadmill)
        {
            return false;
        }
    }

    if(m_nBikeEZ != 0)
    {
        m_pBikeEZ = new CSheetBikeEZPage[m_nBikeEZ];
        if(NULL == m_pBikeEZ)
        {
            return false;
        }
    }

    if(m_nBikeHard != 0)
    {
        m_pBikeHard = new CSheetBikeHardPage[m_nBikeHard];
        if(NULL == m_pBikeHard)
        {
            return false;
        }
    }

    if(m_nBikeHills != 0)
    {
        m_pBikeHills = new CSheetBikeHillsPage[m_nBikeHills];
        if(NULL == m_pBikeHills)
        {
            return false;
        }
    }

    if(m_nBikeIntervals != 0)
    {
        m_pBikeIntervals = new CSheetBikeIntervalsPage[m_nBikeIntervals];
        if(NULL == m_pBikeIntervals)
        {
            return false;
        }
    }

    if(m_nBikeMisc != 0)
    {
        m_pBikeMisc = new CSheetBikeMiscPage[m_nBikeMisc];
        if(NULL == m_pBikeMisc)
        {
            return false;
        }
    }

    if(m_nBikeNormal != 0)
    {
        m_pBikeNormal = new CSheetBikeNormalPage[m_nBikeNormal];
        if(NULL == m_pBikeNormal)
        {
            return false;
        }
    }

    if(m_nBikeTrainer != 0)
    {
        m_pBikeTrainer = new CSheetBikeTrainerPage[m_nBikeTrainer];
        if(NULL == m_pBikeTrainer)
        {
            return false;
        }
    }

    if(m_nBikeMountainBike != 0)
    {
        m_pBikeMountainBike = new CSheetBikeMountainBikePage[m_nBikeMountainBike];
        if(NULL == m_pBikeMountainBike)
        {
            return false;
        }
    }

	if(m_nBikeTimeTrial != 0)
	{
        m_pBikeTimeTrial = new CSheetBikeTimeTrialPage[m_nBikeTimeTrial];
        if(NULL == m_pBikeTimeTrial)
        {
            return false;
        }
    }

    if(m_nSwimDrills != 0)
    {
        m_pSwimDrills = new CSheetSwimDrillsPage[m_nSwimDrills];
        if(NULL == m_pSwimDrills)
        {
            return false;
        }
    }

    if(m_nSwimEZ != 0)
    {
        m_pSwimEZ = new CSheetSwimEZPage[m_nSwimEZ];
        if(NULL == m_pSwimEZ)
        {
            return false;
        }
    }

    if(m_nSwimHard != 0)
    {
        m_pSwimHard = new CSheetSwimHardPage[m_nSwimHard];
        if(NULL == m_pSwimHard)
        {
            return false;
        }
    }

    if(m_nSwimIntervals != 0)
    {
        m_pSwimIntervals = new CSheetSwimIntervalsPage[m_nSwimIntervals];
        if(NULL == m_pSwimIntervals)
        {
            return false;
        }
    }

    if(m_nSwimMisc != 0)
    {
        m_pSwimMisc = new CSheetSwimMiscPage[m_nSwimMisc];
        if(NULL == m_pSwimMisc)
        {
            return false;
        }
    }

    if(m_nSwimNormal != 0)
    {
        m_pSwimNormal = new CSheetSwimNormalPage[m_nSwimNormal];
        if(NULL == m_pSwimNormal)
        {
            return false;
        }
    }

    if(m_nSwimOpenWater != 0)
    {
        m_pSwimOpenWater = new CSheetSwimOpenWaterPage[m_nSwimOpenWater];
        if(NULL == m_pSwimOpenWater)
        {
            return false;
        }
    }

    if(m_nStrengthAbs != 0)
    {
        m_pStrengthAbs = new CSheetStrengthAbsPage[m_nStrengthAbs];
        if(NULL == m_pStrengthAbs)
        {
            return false;
        }
    }

    if(m_nStrengthMisc != 0)
    {
        m_pStrengthMisc = new CSheetStrengthMiscPage[m_nStrengthMisc];
        if(NULL == m_pStrengthMisc)
        {
            return false;
        }
    }

    if(m_nStrengthWeights != 0)
    {
        m_pStrengthWeights = new CSheetStrengthWeightsPage[m_nStrengthWeights];
        if(NULL == m_pStrengthWeights)
        {
            return false;
        }
    }

    if(m_nRaceRun != 0)
    {
        m_pRaceRun = new CSheetRaceRunPage[m_nRaceRun];
        if(NULL == m_pRaceRun)
        {
            return false;
        }
    }

    if(m_nRaceBike != 0)
    {
        m_pRaceBike = new CSheetRaceBikePage[m_nRaceBike];
        if(NULL == m_pRaceBike)
        {
            return false;
        }
    }

    if(m_nRaceSwim != 0)
    {
        m_pRaceSwim = new CSheetRaceSwimPage[m_nRaceSwim];
        if(NULL == m_pRaceSwim)
        {
            return false;
        }
    }

    if(m_nRaceDuathlon != 0)
    {
        m_pRaceDuathlon = new CSheetRaceDuathlonPage[m_nRaceDuathlon];
        if(NULL == m_pRaceDuathlon)
        {
            return false;
        }
    }

    if(m_nRaceTriathlon != 0)
    {
        m_pRaceTriathlon = new CSheetRaceTriathlonPage[m_nRaceTriathlon];
        if(NULL == m_pRaceTriathlon)
        {
            return false;
        }
    }

    return true;
}


CDayLog* CDaySummarySheet::GetDay(void) const
{
    return m_pDay;
}


void CDaySummarySheet::SetDay(CDayLog* pDay)
{
    m_pDay = pDay;
}



CUser* CDaySummarySheet::GetUser(void) const
{
    return m_pUser;
}


void CDaySummarySheet::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}


bool CDaySummarySheet::IsModified(void) const
{
    return m_fModified;
}


void CDaySummarySheet::SetModified(bool fMod)
{
    m_fModified = fMod;
}


bool CDaySummarySheet::AllowingSave(void) const
{
	return m_bAllowSave;
}