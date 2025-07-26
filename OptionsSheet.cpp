#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "OptionsDlg.h"
#include "User.h"
#include "OptionsSheet.h"


IMPLEMENT_DYNAMIC(COptionsSheet, CPropertyPage)

BEGIN_MESSAGE_MAP(COptionsSheet, CPropertyPage)
END_MESSAGE_MAP()


COptionsSheet::COptionsSheet(int nID, CWnd* pParent /* = NULL */) : CPropertyPage(nID)
{
}


void COptionsSheet::OnOK(void)
{
    COptionsDlg* pDlg = GetParentDlg();
    if(NULL != pDlg)
    {
        pDlg->HandleOK();
    }

    CPropertyPage::OnOK();
}


BOOL COptionsSheet::OnApply(void)
{
    COptionsDlg* pDlg = GetParentDlg();
    if(NULL != pDlg)
    {
        pDlg->HandleApply();
    }

    SetModified(FALSE);
    return TRUE;
}        


void COptionsSheet::NotifyParentChanged(void)
{
    SetModified(TRUE);

    COptionsDlg* pDlg = GetParentDlg();
    if(NULL != pDlg)
    {
        pDlg->SetModified(TRUE);
    }
}
  

void COptionsSheet::NotifyParentUnitsChanged(void)
{
    SetModified(TRUE);

    COptionsDlg* pDlg = GetParentDlg();
    if(NULL != pDlg)
    {
        pDlg->SetModified(TRUE);
        pDlg->SetUnitsModified(TRUE);
    }
}


COptionsDlg* COptionsSheet::GetParentDlg(void) const
{
    return m_pParentDlg;
}


void COptionsSheet::SetParentDlg(COptionsDlg* pDlg)
{
    m_pParentDlg = pDlg;
}


CUser* COptionsSheet::GetUser(void) const
{
    return m_pUser;
}


void COptionsSheet::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}