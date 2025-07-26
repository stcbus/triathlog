#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "GetDatesDlg.h"

extern CUser* g_pUser;

IMPLEMENT_DYNAMIC(CGetDatesDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CGetDatesDlg, CAniDialog)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATEFROM, OnFromDropDown)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATETO, OnToDropDown)
END_MESSAGE_MAP()


CGetDatesDlg::CGetDatesDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CGetDatesDlg::IDD, pParent)
{
}


CGetDatesDlg::~CGetDatesDlg()
{
}


BOOL CGetDatesDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    OnUpdateOKButton();

    COleDateTime tmFrom = GetTimeFrom();
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		pFrom->SetTime(tmFrom);
	}
    
	COleDateTime tmTo = GetTimeTo();
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		pTo->SetTime(tmTo);
	}

    return TRUE;
}


void CGetDatesDlg::OnOK(void)
{
	COleDateTime tmFrom;
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		pFrom->GetTime(tmFrom);
		SetTimeFrom(tmFrom);
	}

	COleDateTime tmTo;
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		pTo->GetTime(tmTo);
		SetTimeTo(tmTo);
	}

    if(!CUtil::IsDateValid(tmFrom))
    {
        AfxMessageBox("Please enter a valid starting date.");
        return;
    }

    if(!CUtil::IsDateValid(tmTo))
    {
        AfxMessageBox("Please enter a valid ending date.");
        return;
    }

    int nNum = CUtil::GetNumberOfDaysLaterThan(tmTo, tmFrom);
    if(nNum < 0)
    {
        AfxMessageBox("The start date must be earlier than the end date.");
        return;
    }

    CAniDialog::OnOK();
}


void CGetDatesDlg::OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATEFROM);
	if(NULL != pFrom)
	{
		CMonthCalCtrl* pFromMonthCtrl = pFrom->GetMonthCalCtrl();
		if(NULL != pFromMonthCtrl)
		{
			pFromMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);
			
			CUser* pUser = g_pUser;
			if(NULL != pUser)
			{
				int nStartDay = pUser->GetFirstDayOfWeek();
				if(SUNDAY == nStartDay)
				{
					nStartDay = 8;
				}
				nStartDay -= 2;

				pFromMonthCtrl->SetFirstDayOfWeek(nStartDay);
			}
		}

		pFrom->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pFrom->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pFrom->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pFrom->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pFrom->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CGetDatesDlg::OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATETO);
	if(NULL != pTo)
	{
		CMonthCalCtrl* pToMonthCtrl = pTo->GetMonthCalCtrl();
		if(NULL != pToMonthCtrl)
		{
			pToMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);

			CUser* pUser = g_pUser;
			if(NULL != pUser)
			{
				int nStartDay = pUser->GetFirstDayOfWeek();
				if(SUNDAY == nStartDay)
				{
					nStartDay = 8;
				}
				nStartDay -= 2;

				pToMonthCtrl->SetFirstDayOfWeek(nStartDay);
			}
		}

		pTo->SetMonthCalColor(MCSC_BACKGROUND, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_MONTHBK, CUtil::GetDefaultMonthCtrlBgColor());
		pTo->SetMonthCalColor(MCSC_TEXT, CUtil::GetDefaultMonthCtrlTextColor());
		pTo->SetMonthCalColor(MCSC_TITLEBK, CUtil::GetDefaultMonthCtrlHeadingColor());
		pTo->SetMonthCalColor(MCSC_TITLETEXT, CUtil::GetDefaultMonthCtrlTitleTextColor());
		pTo->SetMonthCalColor(MCSC_TRAILINGTEXT, CUtil::GetDefaultMonthCtrlTrailingTextColor());
	}
}


void CGetDatesDlg::OnUpdateOKButton(void)
{
}


void CGetDatesDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


COleDateTime CGetDatesDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CGetDatesDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


void CGetDatesDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CGetDatesDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}