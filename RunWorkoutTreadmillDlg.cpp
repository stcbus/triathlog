#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "ConverterDlg.h"
#include "AddAllDataDlg.h"
#include "RunWorkoutTreadmillDlg.h"


IMPLEMENT_DYNAMIC(CRunWorkoutTreadmillDlg, CDialog)


BEGIN_MESSAGE_MAP(CRunWorkoutTreadmillDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISTANCE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CRunWorkoutTreadmillDlg::CRunWorkoutTreadmillDlg(LOCATIONRUNARRAY& rarLocations, SHOESRUNARRAY& rarShoes, CWnd* pParent /* = NULL*/) 
                : CDialog(CRunWorkoutTreadmillDlg::IDD, pParent), 
                m_rarLocations(rarLocations), 
                m_rarShoes(rarShoes)
{
}


CRunWorkoutTreadmillDlg::~CRunWorkoutTreadmillDlg()
{
}


BOOL CRunWorkoutTreadmillDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtDist.SubclassDlgItem(IDC_DISTANCE, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);
	
	SetDlgItemText(IDT_DIST, CUtil::GetRunDistString());
    SetDlgItemText(IDT_PACE, CUtil::GetPaceString(FORMAT_RUN));
    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Treadmill");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CRunWorkoutTreadmillDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CShoesRun* pShoes = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK);
        CLocationRun* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, true, false, true, SPORT_RUN, RUNFIELD_SHOES);
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, pShoes);
            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CRunWorkoutTreadmillDlg::OnConvert(void)
{
    CConverterDlg dlg;
    dlg.DoModal();
}


void CRunWorkoutTreadmillDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetMiles(m_edtDist.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());

    SetShoes(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_SHOES), m_rarShoes, false, fOK));
    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CRunWorkoutTreadmillDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_RUN, RUNFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDist.IsInputValid(), m_edtDist.IsInputEmpty(), SPORT_RUN, RUNFIELD_DIST);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_RUN, RUNFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_RUN, RUNFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }

    OnUpdatePaces();
}


void CRunWorkoutTreadmillDlg::OnUpdatePaces(void)
{
    CDlgHelper::HandleDlgPaceOneTime(this, m_edtSeconds.GetValue(false), m_edtDist.GetValue(false), IDC_PACE, FORMAT_RUN);
}


double CRunWorkoutTreadmillDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CRunWorkoutTreadmillDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CRunWorkoutTreadmillDlg::GetHR(void) const
{
    return m_nHR;
}


bool CRunWorkoutTreadmillDlg::IsLong(void) const
{
    return m_fLong;
}


CString CRunWorkoutTreadmillDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CRunWorkoutTreadmillDlg::GetDispName(void) const
{
    return m_strDisp;
}

double CRunWorkoutTreadmillDlg::GetMiles(void) const
{
    return m_dMiles;
}


CLocationRun* CRunWorkoutTreadmillDlg::GetLocation(void) const
{
    return m_pLocation;
}


CShoesRun* CRunWorkoutTreadmillDlg::GetShoes(void) const
{
    return m_pShoes;
}


void CRunWorkoutTreadmillDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CRunWorkoutTreadmillDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CRunWorkoutTreadmillDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CRunWorkoutTreadmillDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CRunWorkoutTreadmillDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CRunWorkoutTreadmillDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CRunWorkoutTreadmillDlg::SetMiles(double dMiles)
{
    m_dMiles = dMiles;
}


void CRunWorkoutTreadmillDlg::SetLocation(CLocationRun* pLocation)
{
    m_pLocation = pLocation;
}


void CRunWorkoutTreadmillDlg::SetShoes(CShoesRun* pShoes)
{
    m_pShoes = pShoes;
}