#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "AniDialog.h"
#include "FormulaParser2.h"
#include "SearchHelpDlg.h"
#include "DMFMultiSummaryDlg.h"
#include "SkinProgress.h"
#include "SearchDlg.h"


IMPLEMENT_DYNAMIC(CSearchDlg, CAniDialog)

BEGIN_MESSAGE_MAP(CSearchDlg, CAniDialog)
	ON_EN_CHANGE(IDC_CUTOFF1, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_CUTOFF2, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_CUTOFF3, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_CUTOFF4, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_CUTOFF5, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_CUTOFF6, OnUpdateSearchButton)
	ON_EN_CHANGE(IDC_SEARCH12, OnUpdateSearchButton)
	
	ON_LBN_DBLCLK(IDC_DATES, OnDoubleClick)

	ON_NOTIFY(DTN_DROPDOWN, IDC_DATESTART, OnFromDropDown)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATEEND, OnToDropDown)

	ON_BN_CLICKED(IDC_USEFIELD1, OnCheck1Clicked)
	ON_BN_CLICKED(IDC_USEFIELD2, OnCheck2Clicked)
	ON_BN_CLICKED(IDC_USEFIELD3, OnCheck3Clicked)
	ON_BN_CLICKED(IDC_USEFIELD4, OnCheck4Clicked)
	ON_BN_CLICKED(IDC_USEFIELD5, OnCheck5Clicked)
	ON_BN_CLICKED(IDC_USEFIELD6, OnCheck6Clicked)
	ON_BN_CLICKED(IDC_USEFIELD7, OnCheck7Clicked)
	ON_BN_CLICKED(IDC_USEFIELD8, OnCheck8Clicked)
	ON_BN_CLICKED(IDC_USEFIELD9, OnCheck9Clicked)
	ON_BN_CLICKED(IDC_USEFIELD10, OnCheck10Clicked)
	ON_BN_CLICKED(IDC_USEFIELD11, OnCheck11Clicked)
	ON_BN_CLICKED(IDC_USEFIELD12, OnCheck12Clicked)

	ON_BN_CLICKED(IDC_FIELD1, OnButton1Clicked)
	ON_BN_CLICKED(IDC_FIELD2, OnButton2Clicked)
	ON_BN_CLICKED(IDC_FIELD3, OnButton3Clicked)
	ON_BN_CLICKED(IDC_FIELD4, OnButton4Clicked)
	ON_BN_CLICKED(IDC_FIELD5, OnButton5Clicked)
	ON_BN_CLICKED(IDC_FIELD6, OnButton6Clicked)
	ON_BN_CLICKED(IDC_FIELD7, OnButton7Clicked)
	ON_BN_CLICKED(IDC_FIELD8, OnButton8Clicked)
	ON_BN_CLICKED(IDC_FIELD9, OnButton9Clicked)
	ON_BN_CLICKED(IDC_FIELD10, OnButton10Clicked)
	ON_BN_CLICKED(IDC_FIELD11, OnButton11Clicked)
	ON_BN_CLICKED(IDC_FIELD12, OnButton12Clicked)
	ON_BN_CLICKED(IDC_LPAREN, OnLParenClicked)
	ON_BN_CLICKED(IDC_AND, OnAndClicked)
	ON_BN_CLICKED(IDC_OR, OnOrClicked)
	ON_BN_CLICKED(IDC_NOT, OnNotClicked)
	ON_BN_CLICKED(IDC_XOR, OnXorClicked)
	ON_BN_CLICKED(IDC_RPAREN, OnRParenClicked)
	ON_BN_CLICKED(IDC_UNDO, OnUndoClicked)
	ON_BN_CLICKED(IDC_CLEAR, OnClearClicked)

	ON_BN_CLICKED(IDC_HOWTO, OnHowToButtonClicked)
	ON_BN_CLICKED(IDC_SEARCH, OnSearchButtonClicked)
	ON_BN_CLICKED(IDC_COPYLIST, OnCopyToClipboardButtonClicked)

	ON_CBN_SELCHANGE(IDC_SEARCHFOR, OnSearchForChanged)
	ON_BN_CLICKED(IDC_ALLDATES, OnAllDatesClicked)
	ON_BN_CLICKED(IDC_BETWEENDATES, OnBetweenDatesClicked)

	ON_CBN_SELCHANGE(IDC_SEARCH1, OnSearch1Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH2, OnSearch2Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH3, OnSearch3Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH4, OnSearch4Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH5, OnSearch5Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH6, OnSearch6Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH7, OnSearch7Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH8, OnSearch8Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH9, OnSearch9Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH10, OnSearch10Changed)
	ON_CBN_SELCHANGE(IDC_SEARCH11, OnSearch11Changed)
END_MESSAGE_MAP()


CSearchDlg::CSearchDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CSearchDlg::IDD, pParent)
{
	SetUser(NULL);
	SetLastSpanType(-1);
	m_pProgress = NULL;
}


CSearchDlg::~CSearchDlg()
{
}


BOOL CSearchDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtCutoff1.SubclassDlgItem(IDC_CUTOFF1, this);
	m_edtCutoff2.SubclassDlgItem(IDC_CUTOFF2, this);
	m_edtCutoff3.SubclassDlgItem(IDC_CUTOFF3, this);
	m_edtCutoff4.SubclassDlgItem(IDC_CUTOFF4, this);
	m_edtCutoff5.SubclassDlgItem(IDC_CUTOFF5, this);
	m_edtCutoff6.SubclassDlgItem(IDC_CUTOFF6, this);
	m_edtSearch12.SubclassDlgItem(IDC_SEARCH12, this);

	COleDateTime tmFrom = GetTimeFrom();
	CDateTimeCtrl* pFrom = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pFrom)
	{
		pFrom->SetTime(tmFrom);
	}
    
	COleDateTime tmTo = GetTimeTo();
	CDateTimeCtrl* pTo = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pTo)
	{
		pTo->SetTime(tmTo);
	}

	CComboBox* pSearch1Box = (CComboBox*)GetDlgItem(IDC_SEARCH1);
	if(NULL != pSearch1Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch1Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch1Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch1Box, false);
	}

	CComboBox* pRel1Box = (CComboBox*)GetDlgItem(IDC_RELATION1);
	if(NULL != pRel1Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel1Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel1Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel1Box, false);
	}


	CComboBox* pSearch2Box = (CComboBox*)GetDlgItem(IDC_SEARCH2);
	if(NULL != pSearch2Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch2Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch2Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch2Box, false);
	}

	CComboBox* pRel2Box = (CComboBox*)GetDlgItem(IDC_RELATION2);
	if(NULL != pRel2Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel2Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel2Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel2Box, false);
	}


	CComboBox* pSearch3Box = (CComboBox*)GetDlgItem(IDC_SEARCH3);
	if(NULL != pSearch3Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch3Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch3Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch3Box, false);
	}

	CComboBox* pRel3Box = (CComboBox*)GetDlgItem(IDC_RELATION3);
	if(NULL != pRel3Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel3Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel3Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel3Box, false);
	}

	CComboBox* pSearch4Box = (CComboBox*)GetDlgItem(IDC_SEARCH4);
	if(NULL != pSearch4Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch4Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch4Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch4Box, false);
	}

	CComboBox* pRel4Box = (CComboBox*)GetDlgItem(IDC_RELATION4);
	if(NULL != pRel4Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel4Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel4Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel4Box, false);
	}


	CComboBox* pSearch5Box = (CComboBox*)GetDlgItem(IDC_SEARCH5);
	if(NULL != pSearch5Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch5Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch5Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch5Box, false);
	}

	CComboBox* pRel5Box = (CComboBox*)GetDlgItem(IDC_RELATION5);
	if(NULL != pRel5Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel5Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel5Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel5Box, false);
	}


	CComboBox* pSearch6Box = (CComboBox*)GetDlgItem(IDC_SEARCH6);
	if(NULL != pSearch6Box)
	{
		for(int i = FIRST_SEARCHTYPE; i <= LAST_SEARCHTYPE; i++)
		{
			pSearch6Box->AddString(CUtil::SearchTypeToString(i));
		}
		pSearch6Box->SetCurSel(SEARCHTYPE_MINUTESRUN);
		CDlgHelper::ReadyComboBox(pSearch6Box, false);
	}

	CComboBox* pRel6Box = (CComboBox*)GetDlgItem(IDC_RELATION6);
	if(NULL != pRel6Box)
	{
		for(int i = FIRST_RELATIONTYPE; i <= LAST_RELATIONTYPE; i++)
		{
			pRel6Box->AddString(CUtil::RelationTypeToString(i));
		}
		pRel6Box->SetCurSel(RELATIONTYPE_GT);
		CDlgHelper::ReadyComboBox(pRel6Box, false);
	}


	CComboBox* pSearch7Box = (CComboBox*)GetDlgItem(IDC_SEARCH7);
	if(NULL != pSearch7Box)
	{
		for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
		{
			pSearch7Box->AddString(CUtil::ActivityToString(i));
		}
		pSearch7Box->SetCurSel(ACTIVITY_RUNNING);
		CDlgHelper::ReadyComboBox(pSearch7Box, false);
	}

	CComboBox* pSearch8Box = (CComboBox*)GetDlgItem(IDC_SEARCH8);
	if(NULL != pSearch8Box)
	{
		for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
		{
			pSearch8Box->AddString(CUtil::ActivityToString(i));
		}
		pSearch8Box->SetCurSel(ACTIVITY_RUNNING);
		CDlgHelper::ReadyComboBox(pSearch8Box, false);
	}

	CComboBox* pSearch9Box = (CComboBox*)GetDlgItem(IDC_SEARCH9);
	if(NULL != pSearch9Box)
	{
		for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
		{
			pSearch9Box->AddString(CUtil::ActivityToString(i));
		}
		pSearch9Box->SetCurSel(ACTIVITY_RUNNING);
		CDlgHelper::ReadyComboBox(pSearch9Box, false);
	}

	CComboBox* pSearch10Box = (CComboBox*)GetDlgItem(IDC_SEARCH10);
	if(NULL != pSearch10Box)
	{
		for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
		{
			pSearch10Box->AddString(CUtil::ActivityToString(i));
		}
		pSearch10Box->SetCurSel(ACTIVITY_RUNNING);
		CDlgHelper::ReadyComboBox(pSearch10Box, false);
	}

	CComboBox* pSearch11Box = (CComboBox*)GetDlgItem(IDC_SEARCH11);
	if(NULL != pSearch11Box)
	{
		for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
		{
			pSearch11Box->AddString(CUtil::ActivityToString(i));
		}
		pSearch11Box->SetCurSel(ACTIVITY_RUNNING);
		CDlgHelper::ReadyComboBox(pSearch11Box, false);
	}

	CComboBox* pSearchForBox = (CComboBox*)GetDlgItem(IDC_SEARCHFOR);
	if(NULL != pSearchForBox)
	{
		for(int i = FIRST_SEARCHFOR; i <= LAST_SEARCHFOR; i++)
		{
			pSearchForBox->AddString(CUtil::SearchForToString(i));
		}
		pSearchForBox->SetCurSel(SEARCHFOR_DAY);
		CDlgHelper::ReadyComboBox(pSearchForBox, false);
	}

	CComboBox* pSepBox = (CComboBox*)GetDlgItem(IDC_SEPARATEWITH);
	if(NULL != pSepBox)
	{
		pSepBox->AddString("Commas");
		pSepBox->AddString("Tabs");
		pSepBox->AddString("Spaces");
		pSepBox->AddString("Lines");
		pSepBox->SetCurSel(3);
		CDlgHelper::ReadyComboBox(pSepBox, false);
	}

	CheckDlgButton(IDC_USEFIELD1, BST_CHECKED);
	CheckDlgButton(IDC_ALLDATES, BST_CHECKED);

	OnCheck1Clicked();
	OnCheck2Clicked();
	OnCheck3Clicked();
	OnCheck4Clicked();
	OnCheck5Clicked();
	OnCheck6Clicked();
	OnCheck7Clicked();
	OnCheck8Clicked();
	OnCheck9Clicked();
	OnCheck10Clicked();
	OnCheck11Clicked();
	OnCheck12Clicked();
	OnSearchForChanged();
	OnAllDatesClicked();
	OnSearch1Changed();
	OnSearch2Changed();
	OnSearch3Changed();
	OnSearch4Changed();
	OnSearch5Changed();
	OnSearch6Changed();
	OnSearch7Changed();
	OnSearch8Changed();
	OnSearch9Changed();
	OnSearch10Changed();
	OnSearch11Changed();

	OnUpdateSearchButton();

    return TRUE;
}


void CSearchDlg::OnUpdateSearchButton(void)
{
    CString strText;
    bool fEnable = true;

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD1))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff1.IsInputValid(), m_edtCutoff1.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD2))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff2.IsInputValid(), m_edtCutoff2.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD3))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff3.IsInputValid(), m_edtCutoff3.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD4))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff4.IsInputValid(), m_edtCutoff4.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD5))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff5.IsInputValid(), m_edtCutoff5.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD6))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtCutoff6.IsInputValid(), m_edtCutoff6.IsInputEmpty());
	}

	if(BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD12))
	{
		fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSearch12.IsInputValid(), m_edtSearch12.IsInputEmpty());
	}

	if((BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD1)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD2)) &&
       (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD3)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD4)) &&
	   (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD5)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD6)) &&
	   (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD7)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD8)) &&
	   (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD9)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD10)) &&
	   (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD11)) && (BST_CHECKED != IsDlgButtonChecked(IDC_USEFIELD12)))
	{
		fEnable = false;
	}

    CWnd* pWnd = GetDlgItem(IDC_SEARCH);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}		


void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


void CSearchDlg::OnCheck1Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD1));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH1);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION1);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF1);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD1);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck2Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD2));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH2);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION2);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF2);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD2);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck3Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD3));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH3);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION3);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF3);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD3);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck4Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD4));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH4);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION4);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF4);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD4);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck5Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD5));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH5);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION5);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF5);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD5);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck6Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD6));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH6);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION6);
	CWnd* pWndCutoff = GetDlgItem(IDC_CUTOFF6);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD6);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndCutoff) || 
	   (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndCutoff->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck7Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD7));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH7);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION7);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD7);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck8Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD8));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH8);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION8);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD8);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck9Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD9));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH9);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION9);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD9);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck10Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD10));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH10);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION10);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD10);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck11Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD11));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH11);
	CWnd* pWndRelation = GetDlgItem(IDC_RELATION11);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD11);

	if((NULL == pWndSearch) || (NULL == pWndRelation) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndRelation->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnCheck12Clicked(void)
{
	bool bEnabled = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD12));

	CWnd* pWndSearch = GetDlgItem(IDC_SEARCH12);
	CWnd* pWndButton = GetDlgItem(IDC_FIELD12);

	if((NULL == pWndSearch) || (NULL == pWndButton))
	{
		return;
	}

	pWndSearch->EnableWindow(bEnabled);
	pWndButton->EnableWindow(bEnabled);

	OnUpdateSearchButton();
}


void CSearchDlg::OnButton1Clicked(void)
{
	CString strCur; 
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[1]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton2Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[2]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton3Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[3]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton4Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[4]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton5Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[5]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton6Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[6]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton7Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[7]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton8Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[8]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton9Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[9]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton10Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[10]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton11Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[11]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnButton12Clicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "[12]";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnLParenClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "(";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnAndClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += " and ";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnOrClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += " or ";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnNotClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += "not ";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnXorClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += " xor ";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnRParenClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	strCur += ")";
	SetDlgItemText(IDC_COMBINATION, strCur);
}


void CSearchDlg::OnUndoClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);

	SetDlgItemText(IDC_COMBINATION, m_strLast);

	m_strLast = strCur;
}


void CSearchDlg::OnClearClicked(void)
{
	CString strCur;
	GetDlgItemText(IDC_COMBINATION, strCur);
	m_strLast = strCur;
	
	SetDlgItemText(IDC_COMBINATION, "");
}


void CSearchDlg::OnHowToButtonClicked(void)
{
	CSearchHelpDlg dlg;
	dlg.DoModal();
}


void CSearchDlg::OnSearchButtonClicked(void)
{
	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return;
	}

	int nSpan = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCHFOR));

	COleDateTime tmStart;
	COleDateTime tmEnd;

	if(BST_CHECKED == IsDlgButtonChecked(IDC_ALLDATES))
	{
		FindExtremeDates(tmStart, tmEnd);
	}
	else
	{
		tmStart = GetStartDate();
		tmEnd = GetEndDate();

		if(!CUtil::IsDateValid(tmStart))
		{
			AfxMessageBox("Please enter a valid starting date.");
			return;
		}

		if(!CUtil::IsDateValid(tmEnd))
		{
			AfxMessageBox("Please enter a valid ending date.");
			return;
		}

		int nNum = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart);
		if(nNum <= 0)
		{
			AfxMessageBox("The start date must be earlier than the end date.");
			return;
		}
	}

	bool abUseSeries[NUM_FIELDS];
	int anType[NUM_COMBO];
	int anRel[NUM_COMBO];
	double adCutoff[NUM_CUTOFF];
	CString strSearch12;

	abUseSeries[0] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD1));
	anType[0] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH1));
	anRel[0] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION1));
	adCutoff[0] = m_edtCutoff1.GetValue();

	abUseSeries[1] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD2));
	anType[1] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH2));
	anRel[1] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION2));
	adCutoff[1] = m_edtCutoff2.GetValue();

	abUseSeries[2] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD3));
	anType[2] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH3));
	anRel[2] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION3));
	adCutoff[2] = m_edtCutoff3.GetValue();

	abUseSeries[3] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD4));
	anType[3] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH4));
	anRel[3] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION4));
	adCutoff[3] = m_edtCutoff4.GetValue();

	abUseSeries[4] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD5));
	anType[4] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH5));
	anRel[4] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION5));
	adCutoff[4] = m_edtCutoff5.GetValue();

	abUseSeries[5] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD6));
	anType[5] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH6));
	anRel[5] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION6));
	adCutoff[5] = m_edtCutoff6.GetValue();

	abUseSeries[6] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD7));
	anType[6] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH7));
	anRel[6] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION7));

	abUseSeries[7] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD8));
	anType[7] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH8));
	anRel[7] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION8));

	abUseSeries[8] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD9));
	anType[8] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH9));
	anRel[8] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION9));

	abUseSeries[9] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD10));
	anType[9] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH10));
	anRel[9] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION10));

	abUseSeries[10] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD11));
	anType[10] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SEARCH11));
	anRel[10] = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RELATION11));

	abUseSeries[11] = (BST_CHECKED == IsDlgButtonChecked(IDC_USEFIELD12));
	strSearch12 = m_edtSearch12.GetValue();

	CString strCombo;
	GetDlgItemText(IDC_COMBINATION, strCombo);
	if(strCombo.IsEmpty())
	{
		CString strString;
		bool bFirst = true;
		for(int i = 0; i < NUM_FIELDS; i++)
		{
			if(true == abUseSeries[i])
			{
				if(false == bFirst)
				{
					CString strTemp = strString;
					strString.Format("%s && [%d]", strTemp, i + 1);
				}
				else
				{
					bFirst = false;
					strString.Format("[%d]", i + 1);
				}
			}
		}

		CString strMessage;
		strMessage.Format("No combination method was entered for the search. \nTo use the default string\n\"%s\"\nthat requires all the fields, press retry.  \nOtherwise, press cancel and enter a combination method.", strString);

		int nRes = AfxMessageBox(strMessage, MB_RETRYCANCEL);
		if(IDRETRY == nRes)
		{
			SetDlgItemText(IDC_COMBINATION, strString);
			strCombo = strString;
		}
		else
		{
			return;
		}
	}

	if(false == IsCombinationValid(strCombo, abUseSeries))
	{
		return;
	}

	int nSize = 0;
	if(SEARCHFOR_DAY == nSpan)
	{
		nSize = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1;
	}
	else if(SEARCHFOR_WEEK == nSpan)
	{
		// walk it back until first day
		while(CUtil::GetDayOfWeek(tmStart) != pUser->GetFirstDayOfWeek())
		{
			tmStart = CUtil::OffsetDay(tmStart, -1);
		}
		// walk it forward until last day
		while(CUtil::GetDayOfWeek(tmEnd) != pUser->GetLastDayOfWeek())
		{
			tmEnd = CUtil::OffsetDay(tmEnd, 1);
		}

		nSize = (CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1) / 7;
	}
	else
	{
		tmStart.SetDate(tmStart.GetYear(), tmStart.GetMonth(), 1);
		tmEnd.SetDate(tmEnd.GetYear(), tmEnd.GetMonth(), CUtil::GetNumDaysInMonth(tmEnd.GetYear(), tmEnd.GetMonth()));

		COleDateTime tmCur = tmStart;
		while(CUtil::IsLaterDayThan(tmEnd, tmCur))
		{
			tmCur = CUtil::OffsetDay(tmCur, CUtil::GetNumDaysInMonth(tmCur.GetYear(), tmCur.GetMonth()));
			nSize++;
		}
	}

	int nNonzero = 0;
	bool* apbVals[NUM_FIELDS];
	for(int i = 0; i < NUM_FIELDS; i++)
	{
		if(true == abUseSeries[i])
		{
			nNonzero++;

			apbVals[i] = new bool[nSize];
			if(NULL == apbVals[i])
			{
				AfxMessageBox("There is not sufficient memory to complete this search");
				return;
			}
		}
	}

	m_pProgress = new CSkinProgress(GetDlgItem(IDC_PROGRESS), nSize * 2, NULL, FALSE, NULL, NULL, cSPT_PERCENT);
	// no check for failure here -- if it fails, we just don't use it

	for(int j = 0; j < nSize; j++)
	{
		for(int i = 0; i < NUM_FIELDS; i++)
		{
			if(true == abUseSeries[i])
			{
				COleDateTime tmCurStart = GetCurStart(tmStart, j, nSpan);
				COleDateTime tmCurEnd = GetCurEnd(tmStart, j, nSpan);

				if(i < NUM_CUTOFF)
				{
					apbVals[i][j] = Evaluate(tmCurStart, tmCurEnd, anType[i], anRel[i], adCutoff[i]);
				}
				else if(i < NUM_COMBO)
				{
					apbVals[i][j] = Evaluate(tmCurStart, tmCurEnd, anType[i], anRel[i]);
				}
				else
				{
					apbVals[i][j] = Evaluate(tmCurStart, tmCurEnd, strSearch12);
				}
			}
		}

		if(NULL != m_pProgress)
		{
			m_pProgress->StepIt();
			PeekAndPump3();
		}
	}

	CListBox* pDatesBox = (CListBox*)GetDlgItem(IDC_DATES);
	if(NULL == pDatesBox)
	{
		return;
	}
	pDatesBox->ResetContent();
	SetLastSpanType(-1);

	CFormulaParser2 fpParser2;
	fpParser2.SetFormula(strCombo);
	for(int j = 0; j < nSize; j++)
	{
		for(int i = 0; i < NUM_FIELDS; i++)
		{
			if(true == abUseSeries[i])
			{
				fpParser2.SetFunctConst(i, (true == apbVals[i][j] ? 1 : 0));
			}
		}

		CString strError;
		WORD wError;
		bool bFound = (0 != fpParser2.Calculation(strCombo, wError, strError));

		if(true == bFound)
		{
			COleDateTime tmCurStart = GetCurStart(tmStart, j, nSpan);
			CString str;

			if(SEARCHFOR_DAY == nSpan)
			{
				str.Format("%d/%d/%d", tmCurStart.GetMonth(), tmCurStart.GetDay(), tmCurStart.GetYear());
			}
			else if(SEARCHFOR_WEEK == nSpan)
			{
				str.Format("Week of %d/%d/%d", tmCurStart.GetMonth(), tmCurStart.GetDay(), tmCurStart.GetYear());
			}
			else
			{
				str.Format("%s %d", CUtil::MonthToString(tmCurStart.GetMonth()), tmCurStart.GetYear());
			}

			// add it if it's not already there
			if(LB_ERR == pDatesBox->FindString(0, str))
			{
				pDatesBox->AddString(str);
			}

			// only set it once we have found data
			SetLastSpanType(nSpan);
		}

		if(NULL != m_pProgress)
		{
			m_pProgress->StepIt();
			PeekAndPump3();
		}
	}

	for(int i = 0; i < NUM_FIELDS; i++)
	{
		if(true == abUseSeries[i])
		{
			delete[] apbVals[i];
		}
	}

	delete m_pProgress;
	m_pProgress = NULL;
}


void CSearchDlg::OnDoubleClick(void)
{
    CUser* pUser = GetUser();
    CListBox* pListBox = (CListBox*)GetDlgItem(IDC_DATES);
	CRunningLogView* pParent = (CRunningLogView*)GetParent();

    if((NULL != pUser) && (NULL != pListBox) && (NULL != pParent))
    {
		int nSel = pListBox->GetCurSel();
        if(CB_ERR != nSel)
		{
			CString strCur;
			pListBox->GetText(nSel, strCur);

			int nSpanType = GetLastSpanType();
			if(SEARCHFOR_DAY == nSpanType)
			{
				COleDateTime tmStart = CUtil::ExtractDateFromDay(strCur);

				pParent->MakeDaySummarySheet(tmStart, pUser, this, false);
			}
			else if(SEARCHFOR_WEEK == nSpanType)
			{
				// the 8 below is strlen("Week of ");
				COleDateTime tmStart = CUtil::ExtractDateFromDay(strCur.Right(strCur.GetLength() - 8));

				CDMFMultiSummaryDlg dlg;
				dlg.SetTimeFrom(tmStart);
				dlg.SetTimeTo(CUtil::OffsetDay(tmStart, 7));
				dlg.SetUser(GetUser());

				dlg.DoModal();
			}
			else
			{
				COleDateTime tmStart = CUtil::ExtractDateFromMonth(strCur);

				CDMFMultiSummaryDlg dlg;
				dlg.SetTimeFrom(tmStart);
				dlg.SetTimeTo(CUtil::OffsetDay(tmStart, CUtil::GetNumDaysInMonth(tmStart.GetYear(), tmStart.GetMonth()) - 1));
				dlg.SetUser(GetUser());

				dlg.DoModal();
			}
		}
	}
}


void CSearchDlg::OnFromDropDown(NMHDR* pNmHdr, LRESULT* pResult)
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


void CSearchDlg::OnToDropDown(NMHDR* pNmHdr, LRESULT* pResult)
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


bool CSearchDlg::Evaluate(COleDateTime tmStart, COleDateTime tmEnd, int nType, int nRel, double dCutoff)
{
	double dVal = 0.0;
	int nDays = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1;

	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return false;
	}

	switch(nType)
	{
    case SEARCHTYPE_MINUTESRUN:
        {
			dVal = pUser->SumMinutesRun(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_MINUTESBIKE:
        {
			dVal = pUser->SumMinutesBike(tmStart, nDays);
 			break;
        }

    case SEARCHTYPE_MINUTESSWIM:
        {
			dVal = pUser->SumMinutesSwim(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_MINUTESSTRENGTH:
        {
			dVal = pUser->SumMinutesStrength(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_MINUTESOVERALL:
        {
			dVal = pUser->SumMinutesRun(tmStart, nDays) + pUser->SumMinutesBike(tmStart, nDays) + 
				   pUser->SumMinutesSwim(tmStart, nDays) + pUser->SumMinutesStrength(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WORKOUTSRUN:
        {
			dVal = (double)pUser->SumWorkoutsRun(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WORKOUTSBIKE:
        {
			dVal = (double)pUser->SumWorkoutsBike(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WORKOUTSSWIM:
        {
			dVal = (double)pUser->SumWorkoutsSwim(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WORKOUTSSTRENGTH:
        {
			dVal = (double)pUser->SumWorkoutsStrength(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WORKOUTSOVERALL:
        {
			dVal = (double)pUser->SumWorkoutsRun(tmStart, nDays) + (double)pUser->SumWorkoutsBike(tmStart, nDays) + 
				   (double)pUser->SumWorkoutsSwim(tmStart, nDays) + (double)pUser->SumWorkoutsStrength(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_MILESRUN:
        {
			dVal = pUser->SumMilesRun(tmStart, nDays);
			break;
		}

    case SEARCHTYPE_MILESBIKE:
        {
			dVal = pUser->SumMilesBike(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_MILESSWIM:
        {
			dVal = pUser->SumMilesSwim(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_TEMP:
        {
			dVal = (double)pUser->GetAverageTemperature(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_HR:
        {
			dVal = (double)pUser->GetAverageHR(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_PACERUN:
        {
			dVal = pUser->GetAverageRunPace(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_PACEBIKE:
        {
			dVal = pUser->GetAverageBikePace(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_PACESWIM:
        {
			dVal = pUser->GetAverageSwimPace(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_SLEEP:
        {
			dVal = pUser->GetAverageSleep(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_WEIGHT:
        {
			dVal = pUser->GetAverageWeight(tmStart, nDays);
			break;
        }

    case SEARCHTYPE_POINTS:
        {
			dVal = pUser->GetAveragePoints(tmStart, nDays) * (double)nDays;
			break;
        }

 	case SEARCHTYPE_CALORIES:
		{
			dVal = pUser->GetAverageCalories(tmStart, nDays) * (double)nDays;
			break;
		}  

    default:
        {
            CUtil::Fatal("Bad parameter to CSearchDlg::Evaluate");
            return false;
        }
	}

	switch(nRel)
	{
	case RELATIONTYPE_LTE:
		{
			return (dVal <= dCutoff);
		}

	case RELATIONTYPE_LT:
		{
			return (dVal < dCutoff);
		}

	case RELATIONTYPE_EQ:
		{
			// give a little leeway for rounding errors
			return (fabs(dVal - dCutoff) < .0000003);
		}

	case RELATIONTYPE_GT:
		{
			return (dVal > dCutoff);
		}

	case RELATIONTYPE_GTE:
		{
			return (dVal >= dCutoff);
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CSearchDlg::Evaluate");
			return false;
		}
	}
}


bool CSearchDlg::Evaluate(COleDateTime tmStart, COleDateTime tmEnd, int nActivityType, int nWorkoutType)
{
	int nVal = 0;
	int nDays = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1;

	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return false;
	}

	switch(nActivityType)
	{
	case ACTIVITY_RUNNING:
		{
			if(nWorkoutType >= LAST_RUN_WORKOUT)
			{
				nWorkoutType = -1;
			}

			nVal = pUser->SumWorkoutsRun(tmStart, nDays, ACTIVITY_RUNNING, nWorkoutType);

			return (nVal > 0);
		}

	case ACTIVITY_BIKING:
		{
			if(nWorkoutType >= LAST_BIKE_WORKOUT)
			{
				nWorkoutType = -1;
			}

			nVal = pUser->SumWorkoutsBike(tmStart, nDays, ACTIVITY_BIKING, nWorkoutType);

			return (nVal > 0);
		}

	case ACTIVITY_SWIMMING:
		{
			if(nWorkoutType >= LAST_SWIM_WORKOUT)
			{
				nWorkoutType = -1;
			}

			nVal = pUser->SumWorkoutsSwim(tmStart, nDays, ACTIVITY_SWIMMING, nWorkoutType);

			return (nVal > 0);
		}

	case ACTIVITY_STRENGTH:
		{
			if(nWorkoutType >= LAST_STRENGTH_WORKOUT)
			{
				nWorkoutType = -1;
			}

			nVal = pUser->SumWorkoutsStrength(tmStart, nDays, ACTIVITY_STRENGTH, nWorkoutType);

			return (nVal > 0);
		}

	case ACTIVITY_RACE:
		{
			if(nWorkoutType >= LAST_RACE)
			{
				nWorkoutType = -1;
			}

			nVal = pUser->SumWorkoutsRace(tmStart, nDays, ACTIVITY_RACE, nWorkoutType);

			return (nVal > 0);
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CSearchDlg::Evaluate");
			return false;
		}
	}
}


bool CSearchDlg::Evaluate(COleDateTime tmStart, COleDateTime tmEnd, CString strSearch)
{
	int nVal = 0;
	int nDays = CUtil::GetNumberOfDaysLaterThan(tmEnd, tmStart) + 1;

	strSearch = strSearch.MakeLower();

	CUser* pUser = GetUser();
	if(NULL == pUser)
	{
		return false;
	}

	for(int i = 0; i < nDays; i++)
	{
		COleDateTime tmCur = CUtil::OffsetDay(tmStart, i);
		CDayLog* pDayLog = pUser->GetDayAt(tmCur);
		
		if(NULL != pDayLog)
		{
			WORKOUTARRAY& rarWorkouts = pDayLog->GetRefWorkoutArray();
			
			for(int j = 0; j < (int)rarWorkouts.GetCount(); j++)
			{
				CWorkout* pWorkout = rarWorkouts.GetAt(j);
				if(NULL != pWorkout)
				{
					CString strNotes = pWorkout->GetNotes().MakeLower();
					

					// if we can find the desired string in the notes, return true
					if(-1 != strNotes.Find(strSearch))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}


BOOL PeekAndPump3(void)
{
  static MSG msg;

  while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
  {
	  if(!AfxGetApp()->PumpMessage())
    {
		  ::PostQuitMessage(0);
		  return FALSE;
	  }	
  }

  return TRUE;
}


COleDateTime CSearchDlg::GetCurStart(COleDateTime tmStart, int nTimePeriod, int nSpan)
{
	switch(nSpan)
	{
	case SEARCHFOR_DAY:
		{
			return CUtil::OffsetDay(tmStart, nTimePeriod);
		}

	case SEARCHFOR_WEEK:
		{
			return CUtil::OffsetDay(tmStart, nTimePeriod * 7);
		}

	case SEARCHFOR_MONTH:
		{
			COleDateTime tmCur = tmStart;
			for(int i = nTimePeriod; i > 0; i--)
			{
				tmCur = CUtil::OffsetDay(tmCur, CUtil::GetNumDaysInMonth(tmCur.GetYear(), tmCur.GetMonth()));
			}

			return tmCur;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CSearchDlg::GetCurStart");
			return tmStart;
		}
	}
}


COleDateTime CSearchDlg::GetCurEnd(COleDateTime tmStart, int nTimePeriod, int nSpan)
{
	return CUtil::OffsetDay(GetCurStart(tmStart, nTimePeriod + 1, nSpan), -1);
}


bool CSearchDlg::IsCombinationValid(CString strCombo, bool abUseSeries[NUM_FIELDS]) const
{
    char cCur;
    int nOpenParen = 0;
	int nClosedParen = 0;

    // first check if parens match
	for(int i = 0; i < strCombo.GetLength(); i++)
    {
        cCur = strCombo.GetAt(i);

		if('(' == cCur)
        {
            nOpenParen++;
        }
		else if(')' == cCur)
        {
            nClosedParen++;
        }
    }

	if (nOpenParen > nClosedParen)
    {
		CString str;
		str.Format("The expression is missing %d closing %s", nOpenParen - nClosedParen, 
					nOpenParen - nClosedParen == 1 ? "parenthesis" : "parentheses");
        AfxMessageBox(str);
		return false;
    }
	if (nOpenParen < nClosedParen)
    {
		CString str;
		str.Format("The expression is missing %d opening %s", nClosedParen - nOpenParen,
					(nClosedParen - nOpenParen == 1 ? "parenthesis" : "parentheses"));
        AfxMessageBox(str);
		return false;
    }

	// search for some other disallowed strings
	if(-1 != strCombo.Find("  "))
	{
		AfxMessageBox("The expression should not contain 'and', 'or', or 'xor' after an 'and', 'or', 'xor', or 'not'");
		return false;
	}

	if(-1 != strCombo.Find("]["))
	{
		AfxMessageBox("The expression should not contain two numbers in a row");
		return false;
	}

	if(-1 != strCombo.Find("]("))
	{
		AfxMessageBox("The expression should not contain a number immediately followed by an opening parenthesis");
		return false;
	}

	if(-1 != strCombo.Find("()"))
	{
		AfxMessageBox("The expression should not contain an empty open-closed paranethesis pair");
		return false;
	}

	if(-1 != strCombo.Find("( "))
	{
		AfxMessageBox("The expression should not contain 'and', 'or', or 'xor' after an open parenthesis");
		return false;
	}

	if(-1 != strCombo.Find(" )"))
	{
		AfxMessageBox("The expression should not contain 'and', 'or', or 'xor' before a closed parenthesis");
		return false;
	}

	if(-1 != strCombo.Find("]n"))
	{
		AfxMessageBox("The operator 'not' should immediately precede, not follow, a number");
		return false;
	}

	for(int i = 0; i < NUM_FIELDS; i++)
	{
		CString strBad;
		strBad.Format("[%d]", i + 1);

		if(false == abUseSeries[i])
		{
			if(-1 != strCombo.Find(strBad))
			{
				CString strMsg;
				strMsg.Format("The expression should not contain %s because that field is not checked above", strBad);
				AfxMessageBox(strMsg);
				return false;
			}
		}
	}

    return TRUE;
}


void CSearchDlg::OnCopyToClipboardButtonClicked(void)
{
	CString strSep = "\n";
	CComboBox* pSepBox = (CComboBox*)GetDlgItem(IDC_SEPARATEWITH);
	if(NULL != pSepBox)
	{
		int nSel = pSepBox->GetCurSel();
		if(0 == nSel)
		{
			strSep = ", ";
		}
		else if(1 == nSel)
		{
			strSep = "\t";
		}
		else if(2 == nSel)
		{
			strSep = " ";
		}
		else if(3 == nSel)
		{
			strSep = "\n";
		}
	}

	CListBox* pDatesBox = (CListBox*)GetDlgItem(IDC_DATES);
	if(NULL == pDatesBox)
	{
		return;
	}

	int nNum = pDatesBox->GetCount();
	if(0 == nNum)
	{
		return;
	}

	CString str;
	for(int i = 0; i < nNum; i++)
	{
		if(0 != i)
		{
			str += strSep;
		}

		CString strCur;
		pDatesBox->GetText(i, strCur);
		str += strCur;
	}

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (str.GetLength() + 1) * sizeof(char));
	if(NULL == hGlobal)
	{
		AfxMessageBox("Unable to set clipboard data");
		return;
	}
	char* pcText = (char*)GlobalLock(hGlobal);
	memcpy(pcText, str.GetBuffer(str.GetLength()), (str.GetLength() * sizeof(char)));
	pcText[str.GetLength()] = NULL;
	GlobalUnlock(hGlobal);

	if(FALSE == OpenClipboard())
	{
		AfxMessageBox("Unable to set clipboard data");
        return;
	}
	// remove the current Clipboard contents  
	if(FALSE == EmptyClipboard())
	{
		AfxMessageBox("Unable to set clipboard data");
		return;  
	}

	if(NULL == ::SetClipboardData(CF_TEXT, hGlobal))
	{
		AfxMessageBox("Unable to set clipboard data");
		return;  
	}  

	CloseClipboard();
}


void CSearchDlg::OnSearchForChanged(void)
{
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_SEARCHFOR);
	if(NULL == pBox)
	{
		return;
	}

	int nSel = pBox->GetCurSel();
	if(CB_ERR == nSel)
	{
		return;
	}

	CString str = CUtil::SearchForToString(nSel) + " with";
	SetDlgItemText(IDC_SEARCHTYPETEXT1, str);
	SetDlgItemText(IDC_SEARCHTYPETEXT2, str);
	SetDlgItemText(IDC_SEARCHTYPETEXT3, str);
	SetDlgItemText(IDC_SEARCHTYPETEXT4, str);
	SetDlgItemText(IDC_SEARCHTYPETEXT5, str);
	SetDlgItemText(IDC_SEARCHTYPETEXT6, str);
}


void CSearchDlg::OnAllDatesClicked(void)
{
	CWnd* pWndStart = GetDlgItem(IDC_DATESTART);
	CWnd* pWndEnd = GetDlgItem(IDC_DATEEND);

	if((NULL == pWndStart) || (NULL == pWndEnd))
	{
		return;
	}

	pWndStart->EnableWindow(FALSE);
	pWndEnd->EnableWindow(FALSE);

	OnUpdateSearchButton();
}


void CSearchDlg::OnBetweenDatesClicked(void)
{
	CWnd* pWndStart = GetDlgItem(IDC_DATESTART);
	CWnd* pWndEnd = GetDlgItem(IDC_DATEEND);

	if((NULL == pWndStart) || (NULL == pWndEnd))
	{
		return;
	}

	pWndStart->EnableWindow(TRUE);
	pWndEnd->EnableWindow(TRUE);

	OnUpdateSearchButton();
}


void CSearchDlg::OnSearchChanged(int nIDCombo, int nIDText)
{
	CComboBox* pBox = (CComboBox*)GetDlgItem(nIDCombo);
	if(NULL == pBox)
	{
		return;
	}

	int nSel = pBox->GetCurSel();
	if(CB_ERR == nSel)
	{
		return;
	}

	CString str;
	switch(nSel)
	{
    case SEARCHTYPE_MINUTESRUN:
    case SEARCHTYPE_MINUTESBIKE:
    case SEARCHTYPE_MINUTESSWIM:
    case SEARCHTYPE_MINUTESSTRENGTH:
    case SEARCHTYPE_MINUTESOVERALL:
		{
            str = "mins";
			break;
        }

    case SEARCHTYPE_WORKOUTSRUN:
    case SEARCHTYPE_WORKOUTSBIKE:
    case SEARCHTYPE_WORKOUTSSWIM:
    case SEARCHTYPE_WORKOUTSSTRENGTH:
    case SEARCHTYPE_WORKOUTSOVERALL:
		{
            str = "wkts";
			break;
        }

    case SEARCHTYPE_MILESRUN:
        {
			str = CUtil::GetRunDistUnitString(true);
			str = str.MakeLower();
			break;
		}

    case SEARCHTYPE_MILESBIKE:
        {
			str = CUtil::GetBikeDistUnitString(true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_MILESSWIM:
        {
			str = CUtil::GetSwimDistUnitString(true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_TEMP:
        {
			str = CUtil::GetTemperatureString(true);
			break;
        }

    case SEARCHTYPE_HR:
        {
            str = "bpm";
			break;
        }

    case SEARCHTYPE_PACERUN:
        {
			str = CUtil::GetPaceString(FORMAT_RUN, "", true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_PACEBIKE:
        {
			str = CUtil::GetPaceString(FORMAT_BIKE, "", true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_PACESWIM:
        {
			str = CUtil::GetPaceString(FORMAT_SWIM, "", true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_SLEEP:
        {
            str = "hrs";
			break;
        }

    case SEARCHTYPE_WEIGHT:
        {
			str = CUtil::GetPWWeightUnitString(true);
			str = str.MakeLower();
			break;
        }

    case SEARCHTYPE_POINTS:
        {
            str = "pts";
 			break;
        }

 	case SEARCHTYPE_CALORIES:
		{
			str = "cal";
			break;
		}

	default:
		{
			CUtil::Fatal("Bad parameter to CSearchDlg::OnSearchChanged");
			break;
		}
	}

	SetDlgItemText(nIDText, str);
}


void CSearchDlg::FillWorkoutCombo(int nIDActivity, int nIDCombo)
{
    CComboBox* pActCombo = (CComboBox*)GetDlgItem(nIDActivity);
    CComboBox* pCombo = (CComboBox*)GetDlgItem(nIDCombo);
    if((NULL != pActCombo) && (NULL != pCombo))
    {
        int nSel = pActCombo->GetCurSel();
        if(CB_ERR == nSel)
        {
            CUtil::Fatal("Bad value selected in CWorkoutStartDlg::FillWorkoutCombo");
            return;
        }

        pCombo->ResetContent();
        switch(nSel)
        {
        case ACTIVITY_RUNNING:
            {
                for(int i = FIRST_RUN_WORKOUT; i < LAST_RUN_WORKOUT; i++)
                {
                    pCombo->AddString(CUtil::RunWorkoutToString(i));
                }
                pCombo->SetCurSel(RUNTYPE_NORMAL);
                break;
            }

        case ACTIVITY_BIKING:
            {
                for(int i = FIRST_BIKE_WORKOUT; i < LAST_BIKE_WORKOUT; i++)
                {
                    pCombo->AddString(CUtil::BikeWorkoutToString(i));
                }
                pCombo->SetCurSel(BIKETYPE_NORMAL);
                break;
            }

        case ACTIVITY_SWIMMING:
            {
                for(int i = FIRST_SWIM_WORKOUT; i < LAST_SWIM_WORKOUT; i++)
                {
                    pCombo->AddString(CUtil::SwimWorkoutToString(i));
                }
                pCombo->SetCurSel(SWIMTYPE_NORMAL);
                break;
            }

        case ACTIVITY_STRENGTH:
            {
                for(int i = FIRST_STRENGTH_WORKOUT; i < LAST_STRENGTH_WORKOUT; i++)
                {
                    pCombo->AddString(CUtil::StrengthWorkoutToString(i));
                }
                pCombo->SetCurSel(STRENGTHTYPE_ABS);
                break;
            }

        case ACTIVITY_RACE:
            {
                for(int i = FIRST_RACE; i < LAST_RACE; i++)
                {
                    pCombo->AddString(CUtil::RaceToString(i));
                }
                pCombo->SetCurSel(RACETYPE_RUN);
                break;
            }

        default:
            {
                CUtil::Fatal("Bad parameter to CWorkoutStartDlg::FillWorkoutCombo");
                return;
            }
        }

		pCombo->AddString("Any");
		pCombo->SetCurSel(pCombo->GetCount() - 1);

        CDlgHelper::ReadyComboBox(pCombo, false);
    }
}


COleDateTime CSearchDlg::GetStartDate(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

    CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATESTART);
	if(NULL != pDate)
	{
		pDate->GetTime(tm);
	}

    return tm;
}


COleDateTime CSearchDlg::GetEndDate(void) const
{
	COleDateTime tm;
	tm.SetStatus(COleDateTime::null);

    CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_DATEEND);
	if(NULL != pDate)
	{
		pDate->GetTime(tm);
	}

    return tm;
}


void CSearchDlg::FindExtremeDates(COleDateTime& rtmEarly, COleDateTime& rtmLate)
{
	rtmEarly.SetStatus(COleDateTime::null);
	rtmLate.SetStatus(COleDateTime::null);

    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        DAYARRAY& rarDays = pUser->GetRefDayArray();
        for(int i = 0; i < rarDays.GetCount(); i++)
        {
            CDayLog* pDay = rarDays.GetAt(i);
            if(NULL != pDay)
            {
				COleDateTime tmCur = pDay->GetDate();

                if((COleDateTime::null == rtmEarly.GetStatus()) || (true == CUtil::IsLaterThan(rtmEarly, tmCur)))
                {
                    rtmEarly.SetStatus(COleDateTime::valid);
                    rtmEarly = tmCur;
                }

                if((COleDateTime::null == rtmLate.GetStatus()) || (false == CUtil::IsLaterThan(rtmLate, tmCur)))
                {
                    rtmLate.SetStatus(COleDateTime::valid);
                    rtmLate = tmCur;
                }
            }
        }
    }

	if((false == CUtil::IsDateValid(rtmEarly)) || (false == CUtil::IsDateValid(rtmLate)))
	{
		CUtil::Fatal("Bad search result in CSearchDlg::FindExtremeDates");
		return;
	}
}


void CSearchDlg::OnSearch1Changed(void)
{
	OnSearchChanged(IDC_SEARCH1, IDC_UNITSTEXT1);
}


void CSearchDlg::OnSearch2Changed(void)
{
	OnSearchChanged(IDC_SEARCH2, IDC_UNITSTEXT2);
}


void CSearchDlg::OnSearch3Changed(void)
{
	OnSearchChanged(IDC_SEARCH3, IDC_UNITSTEXT3);
}


void CSearchDlg::OnSearch4Changed(void)
{
	OnSearchChanged(IDC_SEARCH4, IDC_UNITSTEXT4);
}


void CSearchDlg::OnSearch5Changed(void)
{
	OnSearchChanged(IDC_SEARCH5, IDC_UNITSTEXT5);
}


void CSearchDlg::OnSearch6Changed(void)
{
	OnSearchChanged(IDC_SEARCH6, IDC_UNITSTEXT6);
}


void CSearchDlg::OnSearch7Changed(void)
{
	FillWorkoutCombo(IDC_SEARCH7, IDC_RELATION7);
}


void CSearchDlg::OnSearch8Changed(void)
{
	FillWorkoutCombo(IDC_SEARCH8, IDC_RELATION8);
}


void CSearchDlg::OnSearch9Changed(void)
{
	FillWorkoutCombo(IDC_SEARCH9, IDC_RELATION9);
}


void CSearchDlg::OnSearch10Changed(void)
{
	FillWorkoutCombo(IDC_SEARCH10, IDC_RELATION10);
}


void CSearchDlg::OnSearch11Changed(void)
{
	FillWorkoutCombo(IDC_SEARCH11, IDC_RELATION11);
}


COleDateTime CSearchDlg::GetTimeFrom(void) const
{
    return m_tmFrom;
}


COleDateTime CSearchDlg::GetTimeTo(void) const
{
    return m_tmTo;
}


CUser* CSearchDlg::GetUser(void) const
{
	return m_pUser;
}


int CSearchDlg::GetLastSpanType(void) const
{
	return m_nLastSpanType;
}


void CSearchDlg::SetTimeFrom(COleDateTime tm)
{
    m_tmFrom = tm;
}


void CSearchDlg::SetTimeTo(COleDateTime tm)
{
    m_tmTo = tm;
}


void CSearchDlg::SetUser(CUser* pUser)
{
	m_pUser = pUser;
}


void CSearchDlg::SetLastSpanType(int nType)
{
	m_nLastSpanType = nType;
}