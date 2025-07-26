#include "StdAfx.h"
#include "RunningLog.h"
#include "HelpDlg.h"
#include "HelpIconPage.h"


BEGIN_MESSAGE_MAP(CHelpIconPage, CPropertyPage)
END_MESSAGE_MAP()


CHelpIconPage::CHelpIconPage() : CPropertyPage(CHelpIconPage::IDD)
{
}


BOOL CHelpIconPage::OnInitDialog(void)
{
    CPropertyPage::OnInitDialog();

    return TRUE;
}


void CHelpIconPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}