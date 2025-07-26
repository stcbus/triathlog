#include "StdAfx.h"
#include "RunningLog.h"
#include "DlgHelper.h"
#include "Util.h"
#include "User.h"
#include "AddAllDataDlg.h"
#include "StrengthWorkoutAbsDlg.h"


IMPLEMENT_DYNAMIC(CStrengthWorkoutAbsDlg, CDialog)


BEGIN_MESSAGE_MAP(CStrengthWorkoutAbsDlg, CDialog)
    ON_EN_CHANGE(IDC_TIMEOVERALL, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_TEMPERATURE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_HEARTRATE, OnUpdateOKButton)
    ON_EN_CHANGE(IDC_DISPLAYNAME, OnUpdateOKButton)
    ON_BN_CLICKED(ID_ADDDATA, OnAddData)
END_MESSAGE_MAP()


CStrengthWorkoutAbsDlg::CStrengthWorkoutAbsDlg(LOCATIONSTRENGTHARRAY& rarLocations, CWnd* pParent /* = NULL*/) 
                : CDialog(CStrengthWorkoutAbsDlg::IDD, pParent), 
                m_rarLocations(rarLocations)
{
}


CStrengthWorkoutAbsDlg::~CStrengthWorkoutAbsDlg()
{
}


BOOL CStrengthWorkoutAbsDlg::OnInitDialog(void)
{
    CDialog::OnInitDialog();

	m_edtDisp.SubclassDlgItem(IDC_DISPLAYNAME, this);
	m_edtSeconds.SubclassDlgItem(IDC_TIMEOVERALL, this);
	m_edtTemp.SubclassDlgItem(IDC_TEMPERATURE, this);
	m_edtHR.SubclassDlgItem(IDC_HEARTRATE, this);
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDT_TEMP, CUtil::GetTemperatureString());

    SetDlgItemText(IDC_DISPLAYNAME, "Abs");

    CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

    OnUpdateOKButton();

    return TRUE;
}


void CStrengthWorkoutAbsDlg::OnAddData(void)
{
    CUser* pUser = CUtil::GetUser();

    if(NULL != pUser)
    {
        CAddAllDataDlg dlg;
        dlg.SetUser(pUser);

        bool fOK;

        CLocationStrength* pLoc = CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK);
        
        if(IDOK == dlg.DoModal())
        {
            CDlgHelper::FillComboBox((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, true, true);

            CDlgHelper::SetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, pLoc);
        }
    }
}


void CStrengthWorkoutAbsDlg::OnOK(void)
{
    bool fOK;

    SetSeconds(m_edtSeconds.GetValue());
    SetTemperature(m_edtTemp.GetValue());
    SetHR(m_edtHR.GetValue());
    SetNotes(m_edtNotes.GetValue());
    SetDispName(m_edtDisp.GetValue());

    SetLong(BST_CHECKED == IsDlgButtonChecked(IDC_LONG));
    SetLocation(CDlgHelper::GetComboSel((CComboBox*)GetDlgItem(IDC_LOCATION), m_rarLocations, fOK));

    CDialog::OnOK();
}


void CStrengthWorkoutAbsDlg::OnUpdateOKButton(void)
{
    bool fEnable = true;

	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtDisp.IsInputValid(), m_edtDisp.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSeconds.IsInputValid(), m_edtSeconds.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_TIME);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTemp.IsInputValid(), m_edtTemp.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_TEMP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtHR.IsInputValid(), m_edtHR.IsInputEmpty(), SPORT_STRENGTH, STRFIELD_HR);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


double CStrengthWorkoutAbsDlg::GetSeconds(void) const
{
    return m_dSeconds;
}


int CStrengthWorkoutAbsDlg::GetTemperature(void) const
{
    return m_nTemp;
}


int CStrengthWorkoutAbsDlg::GetHR(void) const
{
    return m_nHR;
}


bool CStrengthWorkoutAbsDlg::IsLong(void) const
{
    return m_fLong;
}


CString CStrengthWorkoutAbsDlg::GetNotes(void) const
{
    return m_strNotes;
}


CString CStrengthWorkoutAbsDlg::GetDispName(void) const
{
    return m_strDisp;
}


CLocationStrength* CStrengthWorkoutAbsDlg::GetLocation(void) const
{
    return m_pLocation;
}


void CStrengthWorkoutAbsDlg::SetSeconds(double dSec)
{
    m_dSeconds = dSec;
}


void CStrengthWorkoutAbsDlg::SetTemperature(int nTemp)
{
    m_nTemp = nTemp;
}


void CStrengthWorkoutAbsDlg::SetHR(int nHR)
{
    m_nHR = nHR;
}


void CStrengthWorkoutAbsDlg::SetLong(bool fLong)
{
    m_fLong = fLong;
}


void CStrengthWorkoutAbsDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CStrengthWorkoutAbsDlg::SetDispName(CString str)
{
    m_strDisp = str;
}


void CStrengthWorkoutAbsDlg::SetLocation(CLocationStrength* pLocation)
{
    m_pLocation = pLocation;
}