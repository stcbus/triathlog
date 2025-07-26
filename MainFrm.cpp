#include "StdAfx.h"
#include "RunningLog.h"
#include "RunningLogDoc.h"
#include "RunningLogView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

IMPLEMENT_MENUXP(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_WM_GETMINMAXINFO()
    ON_WM_CLOSE()
    ON_MENUXP_MESSAGES()
END_MESSAGE_MAP()


static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
    ID_INDICATOR_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


CMainFrame::CMainFrame()
{
}


CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (-1 == CFrameWnd::OnCreate(lpCreateStruct))
    {
        return -1;
    }

	if ((!m_wndStatusBar.Create(this)) || (!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT))))
	{
		TRACE0("Failed to create status bar\n");
		return -1;     
	}

    CRect rc;
    GetClientRect(&rc);
    m_wndStatusBar.SetPaneInfo(1, ID_INDICATOR_PROGRESS, SBPS_NORMAL, 250);
    m_wndStatusBar.SetPaneText(1, "");

    CMenuXP::SetXPLookNFeel(this);

	return 0;
}


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    lpMMI->ptMinTrackSize.x = 875;
    lpMMI->ptMinTrackSize.y = 540;
}


void CMainFrame::OnClose(void)
{
    CRunningLogView* pView = CRunningLogView::GetView();
    if(NULL != pView)
    {
        bool fExit = true;
        if(pView->IsModified())
        {
            fExit = pView->PromptToSave();
        }

        if(fExit)
        {
            CFrameWnd::OnClose();
        }
    }
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if(!CFrameWnd::PreCreateWindow(cs))
    {
        return FALSE;
    }

	return TRUE;
}


#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}


void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG