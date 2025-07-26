#include "StdAfx.h"
#include "RunningLog.h"
#include "RunningLogView.h"
#include "Util.h"
#include "TabCtrlEx.h"
#include "OptionsColorSheet.h"
#include "OptionsCalendarSheet.h"
#include "OptionsDataStartSheet.h"
#include "OptionsUnitsSheet.h"
#include "OptionsDataRunSheet.h"
#include "OptionsDataBikeSheet.h"
#include "OptionsDataSwimSheet.h"
#include "OptionsDataStrengthSheet.h"
#include "OptionsDataRaceRunSheet.h"
#include "OptionsDataRaceBikeSheet.h"
#include "OptionsDataRaceSwimSheet.h"
#include "OptionsDataRaceDuathlonSheet.h"
#include "OptionsDataRaceTriathlonSheet.h"
#include "OptionsDlg.h"

BEGIN_MESSAGE_MAP(COptionsDlg, CPropertySheet)
END_MESSAGE_MAP()


COptionsDlg::COptionsDlg(LPCTSTR pszCaption, CWnd* pParentWnd /* = NULL */) : CPropertySheet(pszCaption, pParentWnd)
{
    SetUser(NULL);
    SetParentView(NULL);
    SetModified(false);
    SetUnitsModified(false);

    for(int i = 0; i < NUM_PAGES; i++)
    {
        m_arpSheets[i] = NULL;
    }

    m_astrTitles[0] = "Colors";
    m_astrTitles[1] = "Display";
    m_astrTitles[2] = "Units";
    m_astrTitles[3] = "Start Fields";
    m_astrTitles[4] = "Running Fields";
    m_astrTitles[5] = "Cycling Fields";
    m_astrTitles[6] = "Swimming Fields";
    m_astrTitles[7] = "Strength Work Fields";
    m_astrTitles[8] = "Running Race Fields";
    m_astrTitles[9] = "Cycling Race Fields";
    m_astrTitles[10] = "Swimming Race Fields";
    m_astrTitles[11] = "Duathlon Race Fields";
    m_astrTitles[12] = "Triathlon Race Fields";
}


COptionsDlg::~COptionsDlg(void)
{
    for(int i = 0; i < NUM_PAGES; i++)
    {
        if(NULL != m_arpSheets[i])
        {
            delete m_arpSheets[i];
            m_arpSheets[i] = NULL;
        }
    }
}


BOOL COptionsDlg::OnInitDialog(void)
{
    BOOL fResult = CPropertySheet::OnInitDialog(); 
	        
    m_tabExCtrl.Install(this);

    CWnd* pWnd = GetDlgItem(IDHELP);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(SW_HIDE);
    }

    // set the tab names
    CTabCtrl* pTab = GetTabControl();
    if(NULL != pTab)
    {
        for(int i = 0; i < NUM_PAGES; i++)
        {
            TC_ITEM item;
            item.mask = TCIF_TEXT;
            item.pszText = m_astrTitles[i].GetBuffer();
            item.cchTextMax = m_astrTitles[i].GetLength();

            pTab->SetItem(i, &item);
        }
    }
    
	return fResult;
}



bool COptionsDlg::Initialize(void)
{
    CUser* pUser = GetUser();
    if((!CreatePages()) || (NULL == pUser))
    {
        return false;
    }

    for(int i = 0; i < NUM_PAGES; i++)
    {
        m_arpSheets[i]->SetParentDlg(this);
        m_arpSheets[i]->SetUser(pUser);
        AddPage(m_arpSheets[i]);
    }

    m_nDistRunUnitsOld = pUser->GetRunDistUnits();
    m_nDistBikeUnitsOld = pUser->GetBikeDistUnits();
    m_nDistSwimUnitsOld = pUser->GetSwimDistUnits();
    m_nHeightUnitsOld = pUser->GetHeightUnits();
    m_nWeightUnitsOld = pUser->GetWeightUnits();
    m_nTempUnitsOld = pUser->GetTempUnits();

    return true;
}
    

bool COptionsDlg::CreatePages(void)
{
    m_arpSheets[0] = new COptionsColorSheet;
    m_arpSheets[1] = new COptionsCalendarSheet;
    m_arpSheets[2] = new COptionsUnitsSheet;
    m_arpSheets[3] = new COptionsDataStartSheet;
    m_arpSheets[4] = new COptionsDataRunSheet;
    m_arpSheets[5] = new COptionsDataBikeSheet;
    m_arpSheets[6] = new COptionsDataSwimSheet;
    m_arpSheets[7] = new COptionsDataStrengthSheet;
    m_arpSheets[8] = new COptionsDataRaceRunSheet;
    m_arpSheets[9] = new COptionsDataRaceBikeSheet;
    m_arpSheets[10] = new COptionsDataRaceSwimSheet;
    m_arpSheets[11] = new COptionsDataRaceDuathlonSheet;
    m_arpSheets[12] = new COptionsDataRaceTriathlonSheet;

    bool bOK = true;
    for(int i = 0; i < NUM_PAGES; i++)
    {
        if(NULL == m_arpSheets[i])
        {
            bOK = false;
        }
    }

    return bOK;
}


void COptionsDlg::HandleOK(void)
{
    // apply automatically gets called here, so we don't need to do anything
}


void COptionsDlg::HandleApply(void)
{
    SaveData();
    OptionallyRedoUnits();
    RedrawView();

    SetUnitsModified(false);

    // now the units may have changed... keep track of it
    // we need to know the last set of units for changing between them
    COptionsUnitsSheet* pUnitsSheet = (COptionsUnitsSheet*)m_arpSheets[2];

    if(NULL != pUnitsSheet)
    {
        m_nDistRunUnitsOld = pUnitsSheet->GetRunDistUnits();
        m_nDistBikeUnitsOld = pUnitsSheet->GetBikeDistUnits();
        m_nDistSwimUnitsOld = pUnitsSheet->GetSwimDistUnits();
        m_nHeightUnitsOld = pUnitsSheet->GetHeightUnits();
        m_nWeightUnitsOld = pUnitsSheet->GetWeightUnits();
        m_nTempUnitsOld = pUnitsSheet->GetTempUnits();       
    }
}


void COptionsDlg::SaveData(void)
{
    for(int i = 0; i < NUM_PAGES; i++)
    {
        if(NULL != m_arpSheets[i])
        {
            m_arpSheets[i]->WriteContents();
        }
    }
}


void COptionsDlg::RedrawView(void)
{
    CRunningLogView* pView = GetParentView();
    if(NULL != pView)
    {
        pView->OptionsDlgNotifyApply();
    }
}


void COptionsDlg::OptionallyRedoUnits(void)
{
    CRunningLogView* pView = GetParentView();

    // see if the units have changed
    COptionsUnitsSheet* pUnitsSheet = (COptionsUnitsSheet*)m_arpSheets[2];
    if(NULL != pUnitsSheet)
    {
        if((m_nDistRunUnitsOld != pUnitsSheet->GetRunDistUnits()) ||
           (m_nDistBikeUnitsOld != pUnitsSheet->GetBikeDistUnits()) || 
           (m_nDistSwimUnitsOld != pUnitsSheet->GetSwimDistUnits()) ||
           (m_nHeightUnitsOld != pUnitsSheet->GetHeightUnits()) || 
           (m_nWeightUnitsOld != pUnitsSheet->GetWeightUnits()) ||
           (m_nTempUnitsOld != pUnitsSheet->GetTempUnits()))
        {
            SetUnitsModified(true);
        }
    }

    if((NULL != pView) && AreUnitsModified())
    {
        pView->RedoUnits(m_nDistRunUnitsOld, m_nDistBikeUnitsOld, m_nDistSwimUnitsOld,
                         m_nHeightUnitsOld, m_nWeightUnitsOld, m_nTempUnitsOld);
    }
}


bool COptionsDlg::IsModified(void) const
{
    return m_bModified;
}


void COptionsDlg::SetModified(bool bModified)
{
    m_bModified = bModified;
}


bool COptionsDlg::AreUnitsModified(void) const
{
    return m_bUnitsModified;
}


void COptionsDlg::SetUnitsModified(bool bUnitsModified)
{
    m_bUnitsModified = bUnitsModified;
}


CUser* COptionsDlg::GetUser(void) const
{
    return m_pUser;
}


void COptionsDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}


CRunningLogView* COptionsDlg::GetParentView(void) const
{
    return m_pParentView;
}


void COptionsDlg::SetParentView(CRunningLogView* pParent)
{
    m_pParentView = pParent;
}