#pragma once

#include "HelpMenuPage.h"
#include "HelpInformationPage.h"
#include "HelpExtrasPage.h"
#include "HelpIconPage.h"
#include "TabCtrlEx.h"

class CRunningLogView;

class CHelpDlg : public CPropertySheet
{
public:
    CHelpDlg(LPCTSTR pszCaption, CWnd* pParentWnd = NULL);
    ~CHelpDlg();

    BOOL OnInitDialog(void);

    bool Initialize(void);

protected:
    bool CreatePages(void);

    enum  { NUM_PAGES = 4 };

    DECLARE_MESSAGE_MAP()

    CTabCtrlEx m_tabExCtrl;
    CHelpMenuPage* m_ppgMenu;
    CHelpInformationPage* m_ppgInfo;
    CHelpExtrasPage* m_ppgExtras;
	CHelpIconPage* m_ppgIcons;
};