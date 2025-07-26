#pragma once

#include "OptionsSheet.h"
#include "OptionsColorSheet.h"
#include "OptionsCalendarSheet.h"
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
#include "TabCtrlEx.h"

class CRunningLogView;

class COptionsDlg : public CPropertySheet
{
public:
    COptionsDlg(LPCTSTR pszCaption, CWnd* pParentWnd = NULL);
    ~COptionsDlg();

    bool IsModified(void) const;
    bool AreUnitsModified(void) const;
    void SetModified(bool bModified);
    void SetUnitsModified(bool bUnitsModified);
    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);
    CRunningLogView* GetParentView(void) const;
    void SetParentView(CRunningLogView* pParent);

    BOOL OnInitDialog(void);

    void HandleOK(void);
    void HandleApply(void);

    bool Initialize(void);

protected:
    bool CreatePages(void);
    void SaveData(void);
    void RedrawView(void);
    void OptionallyRedoUnits(void);

    DECLARE_MESSAGE_MAP()

    enum
    {
        NUM_PAGES = 13
    };

    CTabCtrlEx m_tabExCtrl;
    CUser* m_pUser;
    bool m_bModified;
    bool m_bUnitsModified;
    CRunningLogView* m_pParentView;
    COptionsSheet* m_arpSheets[NUM_PAGES];
    CString m_astrTitles[NUM_PAGES];

    int m_nDistRunUnitsOld;
    int m_nDistBikeUnitsOld;
    int m_nDistSwimUnitsOld;
    int m_nHeightUnitsOld;
    int m_nWeightUnitsOld;
    int m_nTempUnitsOld;
};