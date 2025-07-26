#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "DlgHelper.h"
#include "UpcomingRaceDlg.h"


IMPLEMENT_DYNAMIC(CUpcomingRaceDlg, CDialog)


BEGIN_MESSAGE_MAP(CUpcomingRaceDlg, CDialog)
    ON_EN_CHANGE(IDC_LINE1, OnUpdateOKButton)
END_MESSAGE_MAP()


CUpcomingRaceDlg::CUpcomingRaceDlg(CWnd* pParent /* = NULL*/) : CDialog(CUpcomingRaceDlg::IDD, pParent)
{
    SetDate(COleDateTime::GetCurrentTime());
}


CUpcomingRaceDlg::~CUpcomingRaceDlg()
{
}


BOOL CUpcomingRaceDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtLine1.SubclassDlgItem(IDC_LINE1, this);
	m_edtLine2.SubclassDlgItem(IDC_LINE2, this);
	m_edtLine3.SubclassDlgItem(IDC_LINE3, this);

    COleDateTime tm = GetDate();

    CString str;
    str.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
    CWnd* pWnd = GetDlgItem(IDC_DATE);
    if(NULL != pWnd)
    {
        pWnd->SetWindowText(str);
    }

    OnUpdateOKButton();
    return TRUE;
}


void CUpcomingRaceDlg::OnOK(void)
{
	SetLineOne(m_edtLine1.GetValue());
	SetLineTwo(m_edtLine2.GetValue());
	SetLineThree(m_edtLine3.GetValue());

    CDialog::OnOK();
}


void CUpcomingRaceDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtLine1.IsInputValid(), m_edtLine1.IsInputEmpty());

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


COleDateTime CUpcomingRaceDlg::GetDate(void) const
{
    return m_tmDate;
}


CString CUpcomingRaceDlg::GetLineOne(void) const
{
    return m_strLine1;
}


CString CUpcomingRaceDlg::GetLineTwo(void) const
{
    return m_strLine2;
}


CString CUpcomingRaceDlg::GetLineThree(void) const
{
    return m_strLine3;
}


void CUpcomingRaceDlg::SetDate(COleDateTime tm)
{
    m_tmDate = tm;
}


void CUpcomingRaceDlg::SetLineOne(CString str)
{
    m_strLine1 = str;
}


void CUpcomingRaceDlg::SetLineTwo(CString str)
{
    m_strLine2 = str;
}


void CUpcomingRaceDlg::SetLineThree(CString str)
{
    m_strLine3 = str;
}