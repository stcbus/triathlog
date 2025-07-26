#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "TabCtrlEx.h"
#include "HelpMenuPage.h"
#include "HelpInformationPage.h"
#include "HelpExtrasPage.h"
#include "HelpIconPage.h"
#include "HelpDlg.h"

BEGIN_MESSAGE_MAP(CHelpDlg, CPropertySheet)
END_MESSAGE_MAP()


CHelpDlg::CHelpDlg(LPCTSTR pszCaption, CWnd* pParentWnd /* = NULL */) : CPropertySheet(pszCaption, pParentWnd)
{
    m_ppgMenu = NULL;
    m_ppgInfo = NULL;
    m_ppgExtras = NULL;
	m_ppgIcons = NULL;
}


CHelpDlg::~CHelpDlg(void)
{
    if(NULL != m_ppgMenu)
    {
        delete m_ppgMenu;
        m_ppgMenu = NULL;
    }

    if(NULL != m_ppgInfo)
    {
        delete m_ppgInfo;
        m_ppgInfo = NULL;
    }

    if(NULL != m_ppgExtras)
    {
        delete m_ppgExtras;
        m_ppgExtras = NULL;
    }

	if(NULL != m_ppgIcons)
	{
		delete m_ppgIcons;
		m_ppgIcons = NULL;
	}
}


BOOL CHelpDlg::OnInitDialog(void)
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
        pWndOK->SetWindowText("OK");
        pWndOK->SetFocus();
    }

    CString astrTitles[4];
    astrTitles[0] = "Menu Commands";
    astrTitles[1] = "Information";
	astrTitles[2] = "Icons";
    astrTitles[3] = "Extras";

    // set the tab names
    CTabCtrl* pTab = GetTabControl();
    if(NULL != pTab)
    {
        for(int i = 0; i < NUM_PAGES; i++)
        {
            TC_ITEM item;
            item.mask = TCIF_TEXT;
            item.pszText = astrTitles[i].GetBuffer();
            item.cchTextMax = astrTitles[i].GetLength();

            pTab->SetItem(i, &item);
        }
    }
    
	return fResult;
}



bool CHelpDlg::Initialize(void)
{
    if(!CreatePages())
    {
        return false;
    }

    AddPage(m_ppgMenu);
    AddPage(m_ppgInfo);
	AddPage(m_ppgIcons);
    AddPage(m_ppgExtras);

    return true;
}
    

bool CHelpDlg::CreatePages(void)
{
    m_ppgMenu = new CHelpMenuPage;
    m_ppgInfo = new CHelpInformationPage;
	m_ppgIcons = new CHelpIconPage;
    m_ppgExtras = new CHelpExtrasPage;
    
    bool fOK = true;
    fOK &= (NULL != m_ppgMenu);
    fOK &= (NULL != m_ppgInfo);
	fOK &= (NULL != m_ppgIcons);
    fOK &= (NULL != m_ppgExtras);

    return fOK;
}