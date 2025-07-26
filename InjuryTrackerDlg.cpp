#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddInjuryDlg.h"
#include "InjuryTrackerDlg.h"


IMPLEMENT_DYNAMIC(CInjuryTrackerDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CInjuryTrackerDlg, CAniDialog)
    ON_CBN_SELCHANGE(IDC_INJURYNAME, OnSelChange)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATESTART, OnStartDropDown)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATEEND, OnEndDropDown)
	ON_BN_CLICKED(IDC_HEALED, OnFinishedClicked)
	ON_BN_CLICKED(IDC_ADDDATA, OnAddInjury)
END_MESSAGE_MAP()


CInjuryTrackerDlg::CInjuryTrackerDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CInjuryTrackerDlg::IDD, pParent)
{
	SetLastSel(-1);
}


CInjuryTrackerDlg::~CInjuryTrackerDlg()
{
}


BOOL CInjuryTrackerDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtDescription.SubclassDlgItem(IDC_DESCRIPTION, this);
	m_edtTreatment.SubclassDlgItem(IDC_TREATMENT, this);

    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        return FALSE;
    }

	FillCombo();
    OnSelChange();

    return TRUE;
}


void CInjuryTrackerDlg::OnOK(void)
{
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_INJURYNAME);
	if(NULL == pBox)
	{
		return;
	}

	int nSel = pBox->GetCurSel();
	SaveCurrentInfo(nSel);

	CAniDialog::OnOK();
}


void CInjuryTrackerDlg::OnFinishedClicked(void)
{
	bool bChecked = (BST_CHECKED == IsDlgButtonChecked(IDC_HEALED));

	CWnd* pWnd = GetDlgItem(IDC_DATEEND);
	if(NULL == pWnd)
	{
		return;
	}

	if(true == bChecked)
	{
		pWnd->EnableWindow(true);
	}
	else
	{
		pWnd->EnableWindow(false);
	}
}


void CInjuryTrackerDlg::OnAddInjury(void)
{
	CUser* pUser = GetUser();
	if(NULL != pUser)
	{
		CAddInjuryDlg dlg;
		dlg.SetDate(COleDateTime::GetCurrentTime());
		if(IDOK == dlg.DoModal())
		{
			CInjury* pInjury = new CInjury;
			if(NULL != pInjury)
			{
				pInjury->SetStartDate(dlg.GetDate());
				pInjury->SetEndDate(dlg.GetDate());
				pInjury->SetName(dlg.GetName());
				pInjury->SetFinished(false);
			
				pUser->GetRefInjuryArray().Add(pInjury);

				FillCombo();
			}
		}
	}
}
		

void CInjuryTrackerDlg::FillCombo(void)
{
	CUser* pUser = GetUser();
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_INJURYNAME);
	if((NULL == pBox) || (NULL == pUser))
	{
		return;
	}
	pBox->ResetContent();

	INJURYARRAY& rarInjuries = pUser->GetRefInjuryArray();

	int nNum = (int)rarInjuries.GetCount();

	for(int i = 0; i < nNum; i++)
	{
		CInjury* pInjury = rarInjuries.GetAt(i);
		if(NULL != pInjury)
		{
			CString str;
			COleDateTime tmStart = pInjury->GetStartDate();
			COleDateTime tmEnd = pInjury->GetEndDate();
			
			CString strEnd;
			if(true == pInjury->IsFinished())
			{
				strEnd.Format("%d/%d/%d", tmEnd.GetMonth(), tmEnd.GetDay(), tmEnd.GetYear());
			}
			else
			{
				strEnd = "present";
			}

			str.Format("%s (%d/%d/%d to %s)", pInjury->GetName(), tmStart.GetMonth(), tmStart.GetDay(), tmStart.GetYear(), strEnd);

			pBox->AddString(str);
		}
	}

	CDlgHelper::ReadyComboBox(pBox, false);

	pBox->SetCurSel(nNum - 1);
	OnSelChange();
}


void CInjuryTrackerDlg::OnSelChange(void)
{
	CUser* pUser = GetUser();
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_INJURYNAME);
	if((NULL == pBox) || (NULL == pUser))
	{
		return;
	}

	SaveCurrentInfo(GetLastSel());

	int nSel = pBox->GetCurSel();
	if(CB_ERR == nSel)
	{
		EnableWindows(false);
		return;
	}

	EnableWindows(true);

	INJURYARRAY& rarInjuries = pUser->GetRefInjuryArray();

	CInjury* pInjury = rarInjuries.GetAt(nSel);
	if(NULL != pInjury)
	{
		CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
		if(NULL != pFrom)
		{
			pFrom->SetTime(pInjury->GetStartDate());
		}
	
		CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
		if(NULL != pTo)
		{
			pTo->SetTime(pInjury->GetEndDate());
		}
		
		CheckDlgButton(IDC_HEALED, pInjury->IsFinished() ? BST_CHECKED : BST_UNCHECKED);

		OnFinishedClicked();

		SetDlgItemText(IDC_DESCRIPTION, pInjury->GetDescription());
		SetDlgItemText(IDC_TREATMENT, pInjury->GetTreatment());
	}

	SetLastSel(nSel);
}


void CInjuryTrackerDlg::SaveCurrentInfo(int nSel)
{
	CUser* pUser = GetUser();
	if((nSel < 0) || (NULL == pUser))
	{
		return;
	}

	INJURYARRAY& rarInjuries = pUser->GetRefInjuryArray();

	CInjury* pInjury = rarInjuries.GetAt(nSel);
	if(NULL != pInjury)
	{
		CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
		if(NULL != pFrom)
		{
			COleDateTime tm;
			pFrom->GetTime(tm);
			pInjury->SetStartDate(tm);
		}		

		CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
		if(NULL != pTo)
		{
			COleDateTime tm;
			pTo->GetTime(tm);
			pInjury->SetEndDate(tm);
		}		

		pInjury->SetFinished(BST_CHECKED == IsDlgButtonChecked(IDC_HEALED));
		pInjury->SetDescription(m_edtDescription.GetValue());
		pInjury->SetTreatment(m_edtTreatment.GetValue());
	}
}


void CInjuryTrackerDlg::OnStartDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pFrom)
	{
		CMonthCalCtrl* pFromMonthCtrl = pFrom->GetMonthCalCtrl();
		if(NULL != pFromMonthCtrl)
		{
			pFromMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);
			
			CUser* pUser = GetUser();
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


void CInjuryTrackerDlg::OnEndDropDown(NMHDR* pNmHdr, LRESULT* pResult)
{
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pTo)
	{
		CMonthCalCtrl* pToMonthCtrl = pTo->GetMonthCalCtrl();
		if(NULL != pToMonthCtrl)
		{
			pToMonthCtrl->ModifyStyle(0, MCS_NOTODAYCIRCLE);

			CUser* pUser = GetUser();
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


void CInjuryTrackerDlg::EnableWindows(bool bEnable)
{
	CWnd* pWnd;

	pWnd = GetDlgItem(IDC_DATESTART);
	if(NULL != pWnd)
	{
		pWnd->EnableWindow(bEnable);
	}

	pWnd = GetDlgItem(IDC_DATEEND);
	if(NULL != pWnd)
	{
		pWnd->EnableWindow(bEnable);
	}

	pWnd = GetDlgItem(IDC_HEALED);
	if(NULL != pWnd)
	{
		pWnd->EnableWindow(bEnable);
	}

	pWnd = GetDlgItem(IDC_DESCRIPTION);
	if(NULL != pWnd)
	{
		pWnd->EnableWindow(bEnable);
	}

	pWnd = GetDlgItem(IDC_TREATMENT);
	if(NULL != pWnd)
	{
		pWnd->EnableWindow(bEnable);
	}
}


void CInjuryTrackerDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


int CInjuryTrackerDlg::GetLastSel(void) const
{
	return m_nLastSel;
}


CUser* CInjuryTrackerDlg::GetUser(void) const
{
    return m_pUser;
}


void CInjuryTrackerDlg::SetLastSel(int nSel)
{
	m_nLastSel = nSel;
}


void CInjuryTrackerDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}