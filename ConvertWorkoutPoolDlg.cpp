#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "ConvertWorkoutPoolDlg.h"


BEGIN_MESSAGE_MAP(CConvertWorkoutPoolDlg, CAniDialog)
END_MESSAGE_MAP()


CConvertWorkoutPoolDlg::CConvertWorkoutPoolDlg() : CAniDialog(CConvertWorkoutPoolDlg::IDD)
{
}


BOOL CConvertWorkoutPoolDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    return TRUE;
}


void CConvertWorkoutPoolDlg::OnOK(void)
{
    SetResult(GetCheckedRadioButton(IDC_RUNPOOL, IDC_SWIMOPENWATER));

    CAniDialog::OnOK();
}


void CConvertWorkoutPoolDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}


void CConvertWorkoutPoolDlg::SetResult(int nResult)
{
    m_nResult = nResult;
}


int CConvertWorkoutPoolDlg::GetResult(void) const
{
    return m_nResult;
}