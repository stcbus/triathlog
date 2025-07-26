#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "ConvertWorkoutBikeDlg.h"


BEGIN_MESSAGE_MAP(CConvertWorkoutBikeDlg, CAniDialog)
END_MESSAGE_MAP()


CConvertWorkoutBikeDlg::CConvertWorkoutBikeDlg() : CAniDialog(CConvertWorkoutBikeDlg::IDD)
{
}


BOOL CConvertWorkoutBikeDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    return TRUE;
}


void CConvertWorkoutBikeDlg::OnOK(void)
{
    SetResult(GetCheckedRadioButton(IDC_RUNOTHER, IDC_BIKETRAINER));

    CAniDialog::OnOK();
}


void CConvertWorkoutBikeDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}


void CConvertWorkoutBikeDlg::SetResult(int nResult)
{
    m_nResult = nResult;
}


int CConvertWorkoutBikeDlg::GetResult(void) const
{
    return m_nResult;
}