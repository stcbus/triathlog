#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "User.h"
#include "Util.h"
#include "AniDialog.h"
#include "AddShoesBikeDlg.h"

extern CUser* g_pUser;

IMPLEMENT_DYNAMIC(CAddShoesBikeDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CAddShoesBikeDlg, CAniDialog)
    ON_EN_CHANGE(IDC_BRANDNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_MODELNAME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_SHOESIZE, OnUpdateOKButton)

	ON_NOTIFY(DTN_DROPDOWN, IDC_DATE, OnDropDown)
END_MESSAGE_MAP()


CAddShoesBikeDlg::CAddShoesBikeDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CAddShoesBikeDlg::IDD, pParent)
{
}


CAddShoesBikeDlg::~CAddShoesBikeDlg()
{
}


BOOL CAddShoesBikeDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtBrand.SubclassDlgItem(IDC_BRANDNAME, this);
	m_edtSize.SubclassDlgItem(IDC_SHOESIZE, this);
	m_edtModel.SubclassDlgItem(IDC_MODELNAME, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    OnUpdateOKButton();

	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATE);
	if(NULL != pDate)
	{
		COleDateTime tm(COleDateTime::GetCurrentTime());
		pDate->SetTime(tm);
	}

    return TRUE;
}


void CAddShoesBikeDlg::OnOK(void)
{
	SetBrand(m_edtBrand.GetValue());  
    SetType(m_edtModel.GetValue());    
	SetSize(m_edtSize.GetValue());

	COleDateTime tmDate;
	tmDate.SetStatus(COleDateTime::null);
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATE);
	if(NULL != pDate)
	{
		pDate->GetTime(tmDate);
	}
	SetFirstUse(tmDate);

    if(!CUtil::IsDateValid(tmDate))
    {
        AfxMessageBox("Please enter a valid date");
        return;
    }

	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


void CAddShoesBikeDlg::OnDropDown(NMHDR* pNmHdr, LRESULT* pResult)
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


void CAddShoesBikeDlg::OnUpdateOKButton(void)
{
    CString strText;
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtBrand.IsInputValid(), m_edtBrand.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtModel.IsInputValid(), m_edtModel.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSize.IsInputValid(), m_edtSize.IsInputEmpty());

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CAddShoesBikeDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


CString CAddShoesBikeDlg::GetBrand(void) const
{
    return m_strBrand;
}


CString CAddShoesBikeDlg::GetType(void) const
{
    return m_strType;
}


COleDateTime CAddShoesBikeDlg::GetFirstUse(void) const
{
    return m_tmFirst;
}


double CAddShoesBikeDlg::GetSize(void) const
{
    return m_dSize;
}


CString CAddShoesBikeDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CAddShoesBikeDlg::SetBrand(CString str)
{
    m_strBrand = str;
}


void CAddShoesBikeDlg::SetType(CString str)
{
    m_strType = str;
}


void CAddShoesBikeDlg::SetFirstUse(COleDateTime tm)
{
    m_tmFirst = tm;
}


void CAddShoesBikeDlg::SetSize(double dSize)
{
    m_dSize = dSize;
}


void CAddShoesBikeDlg::SetNotes(CString str)
{
    m_strNotes = str;
}