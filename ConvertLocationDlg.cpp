#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "ConvertLocationDlg.h"


BEGIN_MESSAGE_MAP(CConvertLocationDlg, CAniDialog)
    ON_BN_CLICKED(IDC_RUNNLOC, OnUpdateOK)
    ON_BN_CLICKED(IDC_BIKELOC, OnUpdateOK)
    ON_BN_CLICKED(IDC_SWIMLOC, OnUpdateOK)
    ON_BN_CLICKED(IDC_STRLOC, OnUpdateOK)
END_MESSAGE_MAP()


CConvertLocationDlg::CConvertLocationDlg() : CAniDialog(CConvertLocationDlg::IDD)
{
}


BOOL CConvertLocationDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CheckDlgButton(IDC_RUNNLOC, BST_CHECKED);

    SetDlgItemText(IDC_NOTES, GetNotes());

    return TRUE;
}


void CConvertLocationDlg::OnOK(void)
{
    FillData();

    CAniDialog::OnOK();
}


void CConvertLocationDlg::OnUpdateOK(void)
{
    FillData();
    
    bool bOK = IsRunLocation() || IsBikeLocation() || IsSwimLocation() || IsStrengthLocation();

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(bOK);
    }
}


void CConvertLocationDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}


void CConvertLocationDlg::FillData(void)
{
    SetRunLocation(BST_CHECKED == IsDlgButtonChecked(IDC_RUNNLOC));
    SetBikeLocation(BST_CHECKED == IsDlgButtonChecked(IDC_BIKELOC));
    SetSwimLocation(BST_CHECKED == IsDlgButtonChecked(IDC_SWIMLOC));
    SetStrengthLocation(BST_CHECKED == IsDlgButtonChecked(IDC_STRLOC));
}


void CConvertLocationDlg::SetRunLocation(bool bRun)
{
    m_bRun = bRun;
}


bool CConvertLocationDlg::IsRunLocation(void) const
{
    return m_bRun;;
}


void CConvertLocationDlg::SetBikeLocation(bool bBike)
{
    m_bBike = bBike;
}


bool CConvertLocationDlg::IsBikeLocation(void) const
{
    return m_bBike;;
}


void CConvertLocationDlg::SetSwimLocation(bool bSwim)
{
    m_bSwim = bSwim;
}


bool CConvertLocationDlg::IsSwimLocation(void) const
{
    return m_bSwim;
}


void CConvertLocationDlg::SetStrengthLocation(bool bStr)
{
    m_bStr = bStr;
}


bool CConvertLocationDlg::IsStrengthLocation(void) const
{
    return m_bStr;
}


CString CConvertLocationDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CConvertLocationDlg::SetNotes(CString str)
{
    m_strNotes = str;
}