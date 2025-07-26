#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "ConvertWorkoutWeightsDlg.h"


BEGIN_MESSAGE_MAP(CConvertWorkoutWeightsDlg, CAniDialog)
END_MESSAGE_MAP()


CConvertWorkoutWeightsDlg::CConvertWorkoutWeightsDlg() : CAniDialog(CConvertWorkoutWeightsDlg::IDD)
{
}


BOOL CConvertWorkoutWeightsDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CheckDlgButton(IDC_STRENGTHABS, BST_CHECKED);

    SetDlgItemText(IDC_NOTES, GetNotes());

    return TRUE;
}


void CConvertWorkoutWeightsDlg::OnOK(void)
{
    SetResult(GetCheckedRadioButton(IDC_STRENGTHABS, IDC_STRENGTHWEIGHTS));

    CAniDialog::OnOK();
}


void CConvertWorkoutWeightsDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}


void CConvertWorkoutWeightsDlg::SetResult(int nResult)
{
    m_nResult = nResult;
}


int CConvertWorkoutWeightsDlg::GetResult(void) const
{
    return m_nResult;
}


CString CConvertWorkoutWeightsDlg::GetNotes(void) const
{
    return m_strNotes;
}


void CConvertWorkoutWeightsDlg::SetNotes(CString str)
{
    m_strNotes = str;
}