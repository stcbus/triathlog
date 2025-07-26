#pragma once

#include "MenuXP.h"

class CMainFrame : public CFrameWnd
{
protected: 
    // create from serialization only
	CMainFrame();
public:
    virtual ~CMainFrame();

public:
    // overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    // message handlers
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
    afx_msg void OnClose(void);

	DECLARE_MESSAGE_MAP()
    DECLARE_MENUXP()
	DECLARE_DYNCREATE(CMainFrame)

    // data
    CStatusBar  m_wndStatusBar;
};