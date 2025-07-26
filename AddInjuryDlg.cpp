#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddInjuryDlg.h"

extern CUser* g_pUser;

IMPLEMENT_DYNAMIC(CAddInjuryDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddInjuryDlg, CAniDialog)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATESTART, OnDropDown)
	ON_EN_CHANGE(IDC_NAME, OnUpdateOKButton)
END_MESSAGE_MAP()


CAddInjuryDlg::CAddInjuryDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddInjuryDlg::IDD, pParent)
{
}


CAddInjuryDlg::~CAddInjuryDlg()
{
}


BOOL CAddInjuryDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();
    COleDateTime tmCur = GetDate();
    OnUpdateOKButton();

	m_edtName.SubclassDlgItem(IDC_NAME, this);

	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pDate)
	{
		pDate->SetTime(tmCur);
	}

    return TRUE;
}


void CAddInjuryDlg::OnOK(void)
{
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pDate)
	{
		COleDateTime tm;
		pDate->GetTime(tm);
		SetDate(tm);
	}

	SetName(m_edtName.GetValue());

    CAniDialog::OnOK();
}


void CAddInjuryDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtName.IsInputValid(), m_edtName.IsInputEmpty());

	CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CAddInjuryDlg::OnDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pDate)
	{
		CMonthCalCtrl* pMonthCtrl = pDate->GetMonthCalCtrl();
		if(NULL != pMonthCtrl)
		{
			pMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);

			CUser* pUser = g_pUser;
			if(NULL != pUser)
			{
				int nStartDay = pUser->GetFirstDayOfWeek();
				if(SUNDAY == nStartDay)
				{
					nStartDay = 8;
				}
				nStartDay -= 2;

				pMonthCtrl->SetFirstDayOfWeek(nStartDay);
			}
		}

		pDate->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pDate->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pDate->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pDate->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pDate->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pDate->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CAddInjuryDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddInjuryDlg::GetName(void) const
{
	return m_strName;
}


COleDateTime CAddInjuryDlg::GetDate(void) const
{
    return m_tmDate;
}


void CAddInjuryDlg::SetName(CString str)
{
	m_strName = str;
}


void CAddInjuryDlg::SetDate(COleDateTime tm)
{
    m_tmDate = tm;
}