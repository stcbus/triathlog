#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "DlgHelper.h"
#include "UpcomingWorkoutDlg.h"


IMPLEMENT_DYNAMIC(CUpcomingWorkoutDlg, CDialog)


BEGIN_MESSAGE_MAP(CUpcomingWorkoutDlg, CDialog)
    ON_EN_CHANGE(IDC_LINE1, OnUpdateOKButton)
END_MESSAGE_MAP()


CUpcomingWorkoutDlg::CUpcomingWorkoutDlg(CWnd* pParent /* = NULL*/) : CDialog(CUpcomingWorkoutDlg::IDD, pParent)
{
    SetDate(COleDateTime::GetCurrentTime());
}


CUpcomingWorkoutDlg::~CUpcomingWorkoutDlg()
{
}


BOOL CUpcomingWorkoutDlg::OnInitDialog(void)
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


void CUpcomingWorkoutDlg::OnOK(void)
{
	SetLineOne(m_edtLine1.GetValue());
	SetLineTwo(m_edtLine2.GetValue());
	SetLineThree(m_edtLine3.GetValue());

    CDialog::OnOK();
}


void CUpcomingWorkoutDlg::OnUpdateOKButton(void)
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


COleDateTime CUpcomingWorkoutDlg::GetDate(void) const
{
    return m_tmDate;
}


CString CUpcomingWorkoutDlg::GetLineOne(void) const
{
    return m_strLine1;
}


CString CUpcomingWorkoutDlg::GetLineTwo(void) const
{
    return m_strLine2;
}


CString CUpcomingWorkoutDlg::GetLineThree(void) const
{
    return m_strLine3;
}


void CUpcomingWorkoutDlg::SetDate(COleDateTime tm)
{
    m_tmDate = tm;
}


void CUpcomingWorkoutDlg::SetLineOne(CString str)
{
    m_strLine1 = str;
}


void CUpcomingWorkoutDlg::SetLineTwo(CString str)
{
    m_strLine2 = str;
}


void CUpcomingWorkoutDlg::SetLineThree(CString str)
{
    m_strLine3 = str;
}