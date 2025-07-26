#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "DlgHelper.h"
#include "User.h"
#include "AniDialog.h"
#include "WorkoutStartDlg.h"


BEGIN_MESSAGE_MAP(CWorkoutStartDlg, CAniDialog)
    ON_EN_CHANGE(IDC_STARTTIME, OnUpdateNextButton)
    ON_EN_CHANGE(IDC_PREVNIGHT, OnUpdateNextButton)
    ON_EN_CHANGE(IDC_WEIGHT, OnUpdateNextButton)
    ON_CBN_SELCHANGE(IDC_ACTIVITYTYPE, OnUpdateActivityType)
	ON_BN_CLICKED(IDB_CHOOSEDATAFILE, OnChooseDataFile)
END_MESSAGE_MAP()


CWorkoutStartDlg::CWorkoutStartDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CWorkoutStartDlg::IDD, pParent)
{
    SetWorkoutType(RUNTYPE_NORMAL);
    SetDate(COleDateTime::GetCurrentTime());
    SetActivityType(ACTIVITY_RUNNING);

    SetPrevNightSleep(0.0);
    SetWeight(0);
    SetInjured(false);
	SetSick(false);
	SetPreset(false);
}


CWorkoutStartDlg::~CWorkoutStartDlg()
{
}


BOOL CWorkoutStartDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

	m_edtTime.SubclassDlgItem(IDC_STARTTIME, this);
	m_edtWeight.SubclassDlgItem(IDC_WEIGHT, this);
	m_edtSleep.SubclassDlgItem(IDC_PREVNIGHT, this);
	m_edtDataFile.SubclassDlgItem(IDC_DATAFILE, this);

    SetDlgItemText(IDT_WEIGHT, CUtil::GetPWWeightString());

    COleDateTime tm = GetDate();

    CString str;
    str.Format("%d/%d/%d", tm.GetMonth(), tm.GetDay(), tm.GetYear());
    CWnd* pWnd = GetDlgItem(IDC_DATE);
    if(NULL != pWnd)
    {
        pWnd->SetWindowText(str);
    }

    CComboBox* pActCombo = (CComboBox*)GetDlgItem(IDC_ACTIVITYTYPE);
    if(NULL != pActCombo)
    {
        for(int i = FIRST_ACTIVITY_TYPE; i <= LAST_ACTIVITY_TYPE; i++)
        {
            pActCombo->AddString(CUtil::ActivityToString(i));
        }
        pActCombo->SetCurSel(GetActivityType());
        CDlgHelper::ReadyComboBox(pActCombo, false);
    }

    FillWorkoutCombo();

    if(IsPreset())
    {
		CDlgHelper::SetDlgTimeStart(this, IDC_STARTTIME, GetStartTime());
		CDlgHelper::SetDlgDouble(this, IDC_WEIGHT, GetWeight(), 1);
		CDlgHelper::SetDlgTimeSleep(this, IDC_PREVNIGHT, GetPrevNightSleep());

        if(IsInjured())
        {
            CheckDlgButton(IDC_INJURED, BST_CHECKED);
        }

		if(IsSick())
		{
			CheckDlgButton(IDC_SICK, BST_CHECKED);
		}
    }

    OnUpdateNextButton();
    return TRUE;
}


void CWorkoutStartDlg::OnOK(void)
{
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_WORKOUTTYPE);
    if(NULL != pCombo)
    {
        int nSel = pCombo->GetCurSel();
        if(CB_ERR == nSel)
        {
            AfxMessageBox("Please select a valid workout type.");
            return;
        }
        SetWorkoutType(nSel);
    }

    CComboBox* pActCombo = (CComboBox*)GetDlgItem(IDC_ACTIVITYTYPE);
    if(NULL != pActCombo)
    {
        int nSel = pActCombo->GetCurSel();
        if(CB_ERR == nSel)
        {
            AfxMessageBox("Please select a valid activity type.");
            return;
        }
        SetActivityType(nSel);
    }

	COleDateTime tm = m_edtTime.GetValue();
	if(COleDateTime::valid != tm.GetStatus())
	{
		AfxMessageBox("Please enter a valid start time");
		return;
	}

	SetTime(tm);
    SetPrevNightSleep(m_edtSleep.GetValue());
    SetWeight(m_edtWeight.GetValue());
	SetDataFile(m_edtDataFile.GetValue());

    SetInjured(BST_CHECKED == IsDlgButtonChecked(IDC_INJURED));
    SetSick(BST_CHECKED == IsDlgButtonChecked(IDC_SICK));

    CAniDialog::OnOK();
}


void CWorkoutStartDlg::OnUpdateNextButton(void)
{
    bool fEnable = true;
    
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtTime.IsInputValid(), m_edtTime.IsInputEmpty());
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtSleep.IsInputValid(), m_edtSleep.IsInputEmpty(), SPORT_START, STARTFIELD_SLEEP);
	fEnable &= CDlgHelper::HelpUpdateOKButton(m_edtWeight.IsInputValid(), m_edtWeight.IsInputEmpty(), SPORT_START, STARTFIELD_WEIGHT);

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(fEnable);
    }
}


void CWorkoutStartDlg::OnChooseDataFile(void)
{
	CString strFilter = "Polar HRM files (*.hrm)|*.hrm|All files (*.*)|*.*||";
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, strFilter, this);

	if(IDOK == dlg.DoModal())
	{
		m_edtDataFile.SetWindowText(dlg.GetPathName());
	}
}


void CWorkoutStartDlg::OnUpdateActivityType(void)
{
    FillWorkoutCombo();
}


void CWorkoutStartDlg::FillWorkoutCombo(void)
{
    CComboBox* pActCombo = (CComboBox*)GetDlgItem(IDC_ACTIVITYTYPE);
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_WORKOUTTYPE);
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
        CDlgHelper::ReadyComboBox(pCombo, false);
    }
}
        

int CWorkoutStartDlg::GetActivityType(void) const
{
    return m_nActivityType;
}


int CWorkoutStartDlg::GetWorkoutType(void) const
{
    return m_nWorkoutType;
}


COleDateTime CWorkoutStartDlg::GetStartTime(void) const
{
    COleDateTime tm = GetDate();
	COleDateTime tmTime = GetTime();
    return COleDateTime(tm.GetYear(), tm.GetMonth(), tm.GetDay(), tmTime.GetHour(), tmTime.GetMinute(), 0);
}


bool CWorkoutStartDlg::IsInjured(void) const
{
    return m_fInjured;
}


bool CWorkoutStartDlg::IsSick(void) const
{
    return m_fSick;
}


double CWorkoutStartDlg::GetPrevNightSleep(void) const
{
    return m_dPrevSleep;
}


double CWorkoutStartDlg::GetWeight(void) const
{
    return m_dWeight;
}


COleDateTime CWorkoutStartDlg::GetDate(void) const
{
    return m_tmDate;
}


COleDateTime CWorkoutStartDlg::GetTime(void) const
{
    return m_tmTime;
}


bool CWorkoutStartDlg::IsPreset(void) const
{
    return m_fPreset;
}


CString CWorkoutStartDlg::GetDataFile(void) const
{
	return m_strDataFile;
}


void CWorkoutStartDlg::SetActivityType(int nType)
{
    m_nActivityType = nType;
}


void CWorkoutStartDlg::SetWorkoutType(int nType)
{
    m_nWorkoutType = nType;
}


void CWorkoutStartDlg::SetInjured(bool fInjured)
{
    m_fInjured = fInjured;
}


void CWorkoutStartDlg::SetSick(bool fSick)
{
    m_fSick = fSick;
}


void CWorkoutStartDlg::SetPrevNightSleep(double dSleep)
{
    m_dPrevSleep = dSleep;
}


void CWorkoutStartDlg::SetWeight(double dWeight)
{
    m_dWeight = dWeight;
}


void CWorkoutStartDlg::SetDate(COleDateTime tmDate)
{
    m_tmDate = tmDate;
}


void CWorkoutStartDlg::SetTime(COleDateTime tmTime)
{
	m_tmTime = tmTime;
}


void CWorkoutStartDlg::SetPreset(bool fPreset)
{
    m_fPreset = fPreset;
}


void CWorkoutStartDlg::SetDataFile(CString str)
{
	m_strDataFile = str;
}