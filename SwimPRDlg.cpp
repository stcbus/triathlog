#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "SwimPRDlg.h"


IMPLEMENT_DYNAMIC(CSwimPRDlg, CDialog)

BEGIN_MESSAGE_MAP(CSwimPRDlg, CDialog)
	ON_EN_CHANGE(IDC_50, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_100, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_200, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_400, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_800, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_1500, OnUpdateOKButton)
END_MESSAGE_MAP()


CSwimPRDlg::CSwimPRDlg(CWnd* pParent /* = NULL*/) : CDialog(CSwimPRDlg::IDD, pParent)
{
}


CSwimPRDlg::~CSwimPRDlg()
{
}


BOOL CSwimPRDlg::OnInitDialog(void)
{
    BOOL bRes = CDialog::OnInitDialog();

	m_edt50.SubclassDlgItem(IDC_50, this);
	m_edt100.SubclassDlgItem(IDC_100, this);
	m_edt200.SubclassDlgItem(IDC_200, this);
	m_edt400.SubclassDlgItem(IDC_400, this);
	m_edt800.SubclassDlgItem(IDC_800, this);
	m_edt1500.SubclassDlgItem(IDC_1500, this);

	return bRes;
}


void CSwimPRDlg::OnUpdateOKButton(void)
{    
	bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt50.IsInputValid(), m_edt50.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt100.IsInputValid(), m_edt100.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt200.IsInputValid(), m_edt200.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt400.IsInputValid(), m_edt400.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt800.IsInputValid(), m_edt800.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt1500.IsInputValid(), m_edt1500.IsInputEmpty(), false);
        
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CSwimPRDlg::OnOK(void)
{
    bool fResult = true;

    fResult &= MakeCourse(&m_edt50, "50m Freestyle", MetersToMiles(50));
    fResult &= MakeCourse(&m_edt100, "100m Freestyle", MetersToMiles(100));
    fResult &= MakeCourse(&m_edt200, "200m Freestyle", MetersToMiles(200));
    fResult &= MakeCourse(&m_edt400, "400m Freestyle", MetersToMiles(400));
    fResult &= MakeCourse(&m_edt800, "800m Freestyle", MetersToMiles(800));
    fResult &= MakeCourse(&m_edt1500, "1500m Freestyle", MetersToMiles(1500));

    if(fResult)
    {
        CDialog::OnOK();
    }
}


bool CSwimPRDlg::MakeCourse(CTimeIntervalFilterEdit* pedtTime, CString strName, double dLen)
{
	if(NULL == pedtTime)
	{
		return false;
	}

    double dTime = pedtTime->GetValue(false);
	if((0.0 == dTime) || (false == pedtTime->IsInputValid()) || (true == pedtTime->IsInputEmpty()))
	{
		dTime = PRS_NOPR;
	}

    CCourseSwim* pCourse = new CCourseSwim;
    CUser* pUser = GetUser();
    if((NULL != pCourse) && (NULL != pUser))
    {
        pCourse->SetCity("N/A");
        pCourse->SetState("N/A");
        pCourse->SetNotes("");
        pCourse->SetName(strName);
        pCourse->SetPRSeconds(dTime);
        pCourse->SetLength(dLen);

        pUser->AddCourseSwim(pCourse);
        
        return true;
    }

    return false;
}


void CSwimPRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX); 
}


CUser* CSwimPRDlg::GetUser(void) const
{
    return m_pUser;
}


void CSwimPRDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}