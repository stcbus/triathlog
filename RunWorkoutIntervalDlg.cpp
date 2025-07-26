#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RunWorkoutIntervalDlg.h"


IMPLEMENT_DYNAMIC(CRunWorkoutIntervalDlg, CDialog)


BEGIN_MESSAGE_MAP(CRunWorkoutIntervalDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_SPECIALTIME, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
	ON_EN_CHANGE(IDC_SPECIALDIST, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRunWorkoutIntervalDlg::CRunWorkoutIntervalDlg(LOCATIONRUNARRAY& rarLocations, SHOESRUNARRAY& rarShoes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRunWorkoutIntervalDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes)
{
}


CRunWorkoutIntervalDlg::~CRunWorkoutIntervalDlg()
{
}


BOOL CRunWorkoutIntervalDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSpecialDist.SubclassDlgItem(IDC_SPECIALDIST, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtSpecialSeconds.SubclassDlgItem(IDC_SPECIALTIME, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());
    SetDlgItemText(IDT_SPECIALDIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_SPECIALPACE, CUtil::GetPaceString(FORMAT_RUN));

    SetDlgItemText(IDC_DISPLAYNAME, "Intervals");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SPECSHOES);

    CDlgHelper::FillComboBoxWind((CComboBox*)GetDlgItem(IDC_WIND), false);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CRunWorkoutIntervalDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesRun* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CShoesRun* pSpecShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, fOK);
        CLocationRun* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, pSpecShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CRunWorkoutIntervalDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRunWorkoutIntervalDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
	SetSpecialSeconds(m_edtSpecialSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
	SetSpecialMiles(m_edtSpecialDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());

    SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetWind(CDlgHelper::GetComboSelWind((CComboBox*)GetDlgItem(IDC_WIND), fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));
    SetSpecialShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SPECIALSHOES), m_rarShoes, false, fOK));

    CDialog::OnOK();
}


void CRunWorkoutIntervalDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RUN, RUNFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialSeconds.IsInputValid(), m_edtSpecialSeconds.IsInputEmpty(), SPORT_RUN, RUNFIELD_SPECTIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RUN, RUNFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSpecialDist.IsInputValid(), m_edtSpecialDist.IsInputEmpty(), SPORT_RUN, RUNFIELD_SPECDIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RUN, RUNFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RUN, RUNFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRunWorkoutIntervalDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_RUN);
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSpecialSeconds.GetValue(false), m_edtSpecialDist.GetValue(false), IDC_SPECIALPACE, FORMAT_RUN);
}


double CRunWorkoutIntervalDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRunWorkoutIntervalDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRunWorkoutIntervalDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRunWorkoutIntervalDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRunWorkoutIntervalDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRunWorkoutIntervalDlg::GetDispName(void) const
{
    return m_strDisp;
}


double CRunWorkoutIntervalDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationRun* CRunWorkoutIntervalDlg::GetLocation(void) const
{
    return m_pLocation;
}


CShoesRun* CRunWorkoutIntervalDlg::GetShoes(void) const
{
    return m_pShoes;
}


CShoesRun* CRunWorkoutIntervalDlg::GetSpecialShoes(void) const
{
    return m_pSpikes;
}


int CRunWorkoutIntervalDlg::GetWind(void) const
{
    return m_nWind;
}


double CRunWorkoutIntervalDlg::GetSpecialSeconds(void) const
{
    return m_dIntervalSeconds;
}


double CRunWorkoutIntervalDlg::GetSpecialMiles(void) const
{
    return m_dIntervalMiles;
}


void CRunWorkoutIntervalDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRunWorkoutIntervalDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRunWorkoutIntervalDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRunWorkoutIntervalDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRunWorkoutIntervalDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRunWorkoutIntervalDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CRunWorkoutIntervalDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRunWorkoutIntervalDlg::SetLocation(CLocationRun* pLocation)
{
    m_pLocation = pLocation;
}


void CRunWorkoutIntervalDlg::SetShoes(CShoesRun* pShoes)
{
    m_pShoes = pShoes;
}


void CRunWorkoutIntervalDlg::SetSpecialShoes(CShoesRun* pShoes)
{
    m_pSpikes = pShoes;
}


void CRunWorkoutIntervalDlg::SetWind(int nWind)
{
    m_nWind = nWind;
}


void CRunWorkoutIntervalDlg::SetSpecialSeconds(double dSec)
{
    m_dIntervalSeconds = dSec;
}


void CRunWorkoutIntervalDlg::SetSpecialMiles(double dMiles)
{
    m_dIntervalMiles = dMiles;
}