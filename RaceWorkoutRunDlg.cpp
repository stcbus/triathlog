#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RaceWorkoutRunDlg.h"


IMPLEMENT_DYNAMIC(CRaceWorkoutRunDlg, CDialog)


BEGIN_MESSAGE_MAP(CRaceWorkoutRunDlg, CDialog)
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


CRaceWorkoutRunDlg::CRaceWorkoutRunDlg(COURSERUNARRAY& rarCourses, SHOESRUNARRAY& rarShoes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRaceWorkoutRunDlg::IDD, pParent), 
                m_rarCourses(rarCourses), 
                m_rarShoes(rarShoes)
{
}


CRaceWorkoutRunDlg::~CRaceWorkoutRunDlg()
{
}


BOOL CRaceWorkoutRunDlg::OnInitDialog(void)
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

    SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_RUN));

    SetDlgItemText(IDC_DISPLAYNAME, "Run");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RACERUN, RACERUNFIELD_SHOES);
    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, true, false, true, SPORT_RACERUN, RACERUNFIELD_SPECSHOES);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);

    OnUpdateOKButton();
    UpdatePR();

    return TRUE;
}


void CRaceWorkoutRunDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesRun* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CShoesRun* pSpecShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, fOK);
        CCourseRun* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RACERUN, RACERUNFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, true, false, true, SPORT_RACERUN, RACERUNFIELD_SPECSHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, pSpecShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, pCourse);

            OnUpdatePaces();
        }
    }
}


void CRaceWorkoutRunDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRaceWorkoutRunDlg::OnOK(void)
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
	
	CCourseRun* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);

    SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetSpecialShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_RACESHOES), m_rarShoes, false, fOK));
    SetCourse(pCourse);

    if(NULL != pCourse)
    {
        pCourse->OptionallySetPR(dSpecialSeconds);
    }

    CDialog::OnOK();
}



void CRaceWorkoutRunDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_HR);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtPlace.IsInputValid(), m_edtPlace.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_PLACE);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtRaceNumber.IsInputValid(), m_edtRaceNumber.IsInputEmpty(), SPORT_RACERUN, RACERUNFIELD_RACENUM);
	
    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRaceWorkoutRunDlg::UpdatePR(void)
{
    bool fOK;
    CCourseRun* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((fOK) && (NULL != pCourse))
    {
		CDlgHelper::HandleDlgPROneTime(this, pCourse->GetPRSeconds(), IDC_PR);
    }
}


void CRaceWorkoutRunDlg::OnUpdatePaces(void)
{
    bool fOK;
    CCourseRun* pCourse = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_COURSE), m_rarCourses, fOK);
    if((!fOK) || (NULL == pCourse))
    {
        return;
    }

    double dLength = pCourse->GetLength();
    CString strText;
    strText.Format("%.2lf", dLength);
    SetDlgItemText(IDC_RACEDISTANCE, strText);
    
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_RUN);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), dLength, IDC_RACEPACE, FORMAT_RUN);

    UpdatePR();
}


double CRaceWorkoutRunDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRaceWorkoutRunDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRaceWorkoutRunDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRaceWorkoutRunDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRaceWorkoutRunDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRaceWorkoutRunDlg::GetDisplayName(void) const
{
    return m_strDisplay;
}


double CRaceWorkoutRunDlg::GetMiles(void) const
{
    return m_dMiles;
}


CCourseRun* CRaceWorkoutRunDlg::GetCourse(void) const
{
    return m_pCourse;
}


CShoesRun* CRaceWorkoutRunDlg::GetShoes(void) const
{
    return m_pShoes;
}


int CRaceWorkoutRunDlg::GetWind(void) const
{
    return m_nWind;
}


int CRaceWorkoutRunDlg::GetRacePosition(void) const
{
    return m_nPlace;
}


int CRaceWorkoutRunDlg::GetRaceNumber(void) const
{
    return m_nRaceNumber;
}


double CRaceWorkoutRunDlg::GetSpecialSeconds(void) const
{
    return m_dRaceSeconds;
}


CShoesRun* CRaceWorkoutRunDlg::GetSpecialShoes(void) const
{
    return m_pSpikes;
}


void CRaceWorkoutRunDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRaceWorkoutRunDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRaceWorkoutRunDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRaceWorkoutRunDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRaceWorkoutRunDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRaceWorkoutRunDlg::SetDisplayName(CString str)
{
    m_strDisplay = str;
}


void CRaceWorkoutRunDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRaceWorkoutRunDlg::SetCourse(CCourseRun* pCourse)
{
    m_pCourse = pCourse;
}


void CRaceWorkoutRunDlg::SetShoes(CShoesRun* pShoes)
{
    m_pShoes = pShoes;
}


void CRaceWorkoutRunDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRaceWorkoutRunDlg::SetRacePosition(int nPlace)
{
    m_nPlace = nPlace;
}


void CRaceWorkoutRunDlg::SetRaceNumber(int nNum)
{
    m_nRaceNumber = nNum;
}


void CRaceWorkoutRunDlg::SetSpecialSeconds(double dSec)
{
    m_dRaceSeconds = dSec;
}


void CRaceWorkoutRunDlg::SetSpecialShoes(CShoesRun* pShoes)
{
    m_pSpikes = pShoes;
}