#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "GoToDayDlg.h"

extern CUser* g_pUser;

IMPLEMENT_DYNAMIC(CGoToDayDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CGoToDayDlg, CAniDialog)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATE, OnDropDown)
END_MESSAGE_MAP()


CGoToDayDlg::CGoToDayDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CGoToDayDlg::IDD, pParent)
{
}


CGoToDayDlg::~CGoToDayDlg()
{
}


BOOL CGoToDayDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();
    COleDateTime tmCur = GetDate();
    OnUpdateOKButton();

	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATE);
	if(NULL != pDate)
	{
		pDate->SetTime(tmCur);
	}

    return TRUE;
}


void CGoToDayDlg::OnOK(void)
{
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATE);
	if(NULL != pDate)
	{
		COleDateTime tm;
		pDate->GetTime(tm);
		SetDate(tm);
	}

    CAniDialog::OnOK();
}


void CGoToDayDlg::OnUpdateOKButton(void)
{
}


void CGoToDayDlg::OnDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATE);
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


void CGoToDayDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CGoToDayDlg::GetDate(void) const
{
    return m_tmDate;
}


void CGoToDayDlg::SetDate(COleDateTime tm)
{
    m_tmDate = tm;
}