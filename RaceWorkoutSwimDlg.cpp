#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RaceWorkoutSwimDlg.h"


IMPLEMENT_DYNAMIC(CRaceWorkoutSwimDlg, CDialog)


BEGIN_MESSAGE_MAP(CRaceWorkoutSwimDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_TIMERACE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_PLACE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_RACENUMBER, OnUpdateOKButton)

    ON_CBN_SELCHANGE(IDC_COURSE, OnUpdatePaces)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRaceWorkoutSwimDlg::CRaceWorkoutSwimDlg(COURSESWIMARRAY& rarCourses, CWnd* pParent /* = NULL*/) 
                : CDialog(CRaceWorkoutSwimDlg::IDD, pParent), 
                m_rarCourses(rarCourses)
{
}


CRaceWorkoutSwimDlg::~CRaceWorkoutSwimDlg()
{
}


BOOL CRaceWorkoutSwimDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtSpecialSeconds.SubclassDlgItem(IDC_TIMERACE, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtPlace.SubclassDlgItem(IDC_PLACE, this);
	m_edtRaceNumber.SubclassDlgItem(IDC_RACENUMBER, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_SWIM));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetSwimDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_SWIM));

    SetDlgItemText(IDC_DISPLAYNAME, "Swim");

    CDlgHelper::FillComboBoxChoppiness((CComboBox*)GetDlgItem(IDC_CHOPPINESS), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);

    OnUpdateOKButton();
    UpdatePR();

    return TRUE;
}


void CRaceWorkoutSwimDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CCourseSwim* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, pCourse);

            OnUpdatePaces();
        }
    }
}


void CRaceWorkoutSwimDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRaceWorkoutSwimDlg::OnOK(void)
{
    bool fOK;

	double dSpecialSeconds = m_edtSpecialSeconds.GetValue();

    SetSeconds(m_edtSeconds.GetValue());
	SetSpecialSeconds(dSpecialSeconds);
	SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDisplayName(m_edtDisp.GetValue());
	SetRacePosition(m_edtPlace.GetValue());
	SetRaceNumber(m_edtRaceNumber.GetValue());

	CCourseSwim* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

    SetChoppiness(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_CHOPPINESS), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetCourse(pCourse);

    if(NULL != pCourse)
    {
        pCourse->OptionallySetPR(dSpecialSeconds);
    }

    CDialog::OnOK();
}


void CRaceWorkoutSwimDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPlace.IsInputValid(), m_edtPlace.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_PLACE);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtRaceNumber.IsInputValid(), m_edtRaceNumber.IsInputEmpty(), SPORT_RACESWIM, RACESWIMFIELD_RACENUM);
    
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRaceWorkoutSwimDlg::UpdatePR(void)
{
    bool fOK;
    CCourseSwim* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((fOK) && (NULL != pCourse))
    {
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
    }
}


void CRaceWorkoutSwimDlg::OnUpdatePaces(void)
{
    bool fOK;
    CCourseSwim* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((!fOK) || (NULL == pCourse))
    {
        return;
    }

    double dLength = pCourse->GetLength();
    CString strText;
    strText.Format("%.2lf", dLength);
    SetDlgItemText(IDC_RACEDISTANCE, strText);
    
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_SWIM);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), dLength, IDC_RACEPACE, FORMAT_SWIM);

    UpdatePR();
}


double CRaceWorkoutSwimDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRaceWorkoutSwimDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRaceWorkoutSwimDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRaceWorkoutSwimDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRaceWorkoutSwimDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRaceWorkoutSwimDlg::GetDisplayName(void) const
{
    return m_strDisplay;
}


double CRaceWorkoutSwimDlg::GetMiles(void) const
{
    return m_dMiles;
}


CCourseSwim* CRaceWorkoutSwimDlg::GetCourse(void) const
{
    return m_pCourse;
}


int CRaceWorkoutSwimDlg::GetChoppiness(void) const
{
    return m_nChoppiness;
}


int CRaceWorkoutSwimDlg::GetRacePosition(void) const
{
    return m_nPlace;
}


int CRaceWorkoutSwimDlg::GetRaceNumber(void) const
{
    return m_nRaceNumber;
}


double CRaceWorkoutSwimDlg::GetSpecialSeconds(void) const
{
    return m_dRaceSeconds;
}


void CRaceWorkoutSwimDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRaceWorkoutSwimDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRaceWorkoutSwimDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRaceWorkoutSwimDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRaceWorkoutSwimDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRaceWorkoutSwimDlg::SetDisplayName(CString str)
{
    m_strDisplay = str;
}


void CRaceWorkoutSwimDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceWorkoutSwimDlg::SetCourse(CCourseSwim* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceWorkoutSwimDlg::SetChoppiness(int nAmount)
{
    m_nChoppiness = nAmount;
}


void CRaceWorkoutSwimDlg::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CRaceWorkoutSwimDlg::SetRaceNumber(int nNum)
{
    m_nRaceNumber = nNum;
}


void CRaceWorkoutSwimDlg::SetSpecialSeconds(double dSec)
{
    m_dRaceSeconds = dSec;
}