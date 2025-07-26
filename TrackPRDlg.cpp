#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "DlgHelper.h"
#include "Util.h"
#include "TrackPRDlg.h"


IMPLEMENT_DYNAMIC(CTrackPRDlg, CDialog)

BEGIN_MESSAGE_MAP(CTrackPRDlg, CDialog)
	ON_EN_CHANGE(IDC_400, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_800, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_1500, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_1600, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_1MILE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_3000, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_3200, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_2MILE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_5000, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_10000, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_STEEPLE, OnUpdateOKButton)
END_MESSAGE_MAP()


CTrackPRDlg::CTrackPRDlg(CWnd* pParent /* = NULL*/) : CDialog(CTrackPRDlg::IDD, pParent)
{
}


CTrackPRDlg::~CTrackPRDlg()
{
}


BOOL CTrackPRDlg::OnInitDialog(void)
{
	BOOL bRes = CDialog::OnInitDialog();

	m_edt400.SubclassDlgItem(IDC_400, this);
	m_edt800.SubclassDlgItem(IDC_800, this);
	m_edt1500.SubclassDlgItem(IDC_1500, this);
	m_edt1600.SubclassDlgItem(IDC_1600, this);
	m_edt1Mile.SubclassDlgItem(IDC_1MILE, this);
	m_edt3000.SubclassDlgItem(IDC_3000, this);
	m_edt3200.SubclassDlgItem(IDC_3200, this);
	m_edt2Mile.SubclassDlgItem(IDC_2MILE, this);
	m_edt5000.SubclassDlgItem(IDC_5000, this);
	m_edt10000.SubclassDlgItem(IDC_10000, this);
	m_edt3000Steeple.SubclassDlgItem(IDC_STEEPLE, this);

	return bRes;
}


void CTrackPRDlg::OnUpdateOKButton(void)
{    
	bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt400.IsInputValid(), m_edt400.IsInputEmpty(), false);
  	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt800.IsInputValid(), m_edt800.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt1500.IsInputValid(), m_edt1500.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt1600.IsInputValid(), m_edt1600.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt1Mile.IsInputValid(), m_edt1Mile.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt3000.IsInputValid(), m_edt3000.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt3200.IsInputValid(), m_edt3200.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt2Mile.IsInputValid(), m_edt2Mile.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt5000.IsInputValid(), m_edt5000.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt10000.IsInputValid(), m_edt10000.IsInputEmpty(), false);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edt3000Steeple.IsInputValid(), m_edt3000Steeple.IsInputEmpty(), false);
      
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CTrackPRDlg::OnOK(void)
{
    bool fResult = true;

    fResult &= MakeCourse(&m_edt400, "Track 400m", MetersToMiles(400));
    fResult &= MakeCourse(&m_edt800, "Track 800m", MetersToMiles(800));
    fResult &= MakeCourse(&m_edt1500, "Track 1500m", MetersToMiles(1500));
    fResult &= MakeCourse(&m_edt1600, "Track 1600m", MetersToMiles(1600));
    fResult &= MakeCourse(&m_edt1Mile, "Track Mile", 1.000);
    fResult &= MakeCourse(&m_edt3000, "Track 3000m", MetersToMiles(3000));
    fResult &= MakeCourse(&m_edt3200, "Track 3200m", MetersToMiles(3200));
    fResult &= MakeCourse(&m_edt2Mile, "Track 2 Mile", 2.000);
    fResult &= MakeCourse(&m_edt5000, "Track 5000m", MetersToMiles(5000));
    fResult &= MakeCourse(&m_edt10000, "Track 10000m", MetersToMiles(10000));
    fResult &= MakeCourse(&m_edt3000Steeple, "Track 3000m Steeple", MetersToMiles(3000));

    if(fResult)
    {
        CDialog::OnOK();
    }
}


bool CTrackPRDlg::MakeCourse(CTimeIntervalFilterEdit* pedtTime, CString strName, double dLen)
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

    CCourseRun* pCourse = new CCourseRun;
    CUser* pUser = GetUser();
    if((NULL != pCourse) && (NULL != pUser))
    {
        pCourse->SetCity("N/A");
        pCourse->SetState("N/A");
        pCourse->SetNotes("");
        pCourse->SetName(strName);
        pCourse->SetPRSeconds(dTime);
        pCourse->SetLength(dLen);

        pUser->AddCourseRun(pCourse);
        
        return true;
    }

    return false;
}


void CTrackPRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX); 
}


CUser* CTrackPRDlg::GetUser(void) const
{
    return m_pUser;
}


void CTrackPRDlg::SetUser(CUser* pUser)
{
    m_pUser = pUser;
}