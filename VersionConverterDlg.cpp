#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "SkinProgress.h"
#include "MainFrm.h"
#include "User.h"
#include "Util.h"
#include "XMLConverter.h"
#include "VersionSuccessDlg.h"
#include "VersionConverterDlg.h"

#define dCSP_DIALOG_PROGRESS
#define dCSP_TIMED_REDRAW

BEGIN_MESSAGE_MAP(CVersionConverterDlg, CAniDialog)
    ON_BN_CLICKED(IDC_OPENFILE, OnOpenFile)
    ON_BN_CLICKED(IDC_CONVERT, OnConvert)
    ON_WM_TIMER()
END_MESSAGE_MAP()


CVersionConverterDlg::CVersionConverterDlg() : CAniDialog(CVersionConverterDlg::IDD)
{
    m_pProgress = NULL;
}


BOOL CVersionConverterDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();
 
    ShowHideMiddle(false);

    EnableConvert(false);  

    return TRUE;
}


void CVersionConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_PROGRESS, m_stcProgress);

    CAniDialog::DoDataExchange(pDX);
}


void CVersionConverterDlg::OnOpenFile(void)
{
    CString strFilter = "RunningLog 1.0 Files (*.xml)|*.xml||";
    CFileDialog dlg(true, ".xml", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, strFilter, this); 
    if(IDOK == dlg.DoModal())
    {
        CString strFile = dlg.GetPathName();
        SetDlgItemText(IDC_OPENFILENAME, strFile);

        CString strNew = strFile.Left(strFile.GetLength() - 4) + " 2.xml";
        SetDlgItemText(IDC_NEWFILENAME, strNew);

        EnableConvert(true);
    }
}


void CVersionConverterDlg::OnConvert(void)
{
    ShowHideMiddle(true);

    CString strOld;
    GetDlgItemText(IDC_OPENFILENAME, strOld);
    CString strNew;
    GetDlgItemText(IDC_NEWFILENAME, strNew);

    bool bSuccess = false;

    CUser* pUser = new CUser;
    if(m_xmlConv.ReadOldFile(pUser, strOld, this))
    {
        bool bRes = CUtil::SaveXML(pUser, strNew);
        if(bRes)
        {
            ShowHideMiddle(false);
            CVersionSuccessDlg dlg;
            dlg.DoModal();
            bSuccess = true;
        }
    }
    delete pUser;   
    ShowHideMiddle(false);

    if(!bSuccess)
    {
        AfxMessageBox("The conversion failed -- please check that the file format of the original file is correct.");
    }
}


void CVersionConverterDlg::SetNotes(CString str)
{
    SetDlgItemText(IDC_NOTES, str);
}


void CVersionConverterDlg::CreateProgress(CString strMessage, int nSteps)
{
    CWnd* pProgressWnd = GetDlgItem(IDC_PROGRESS);
    CWnd* pCurrentWnd = GetDlgItem(IDC_CURRENTWORK);
    
    if(NULL != m_pProgress)
    {
        return;
    }

    m_pProgress = new CSkinProgress(pProgressWnd, nSteps, NULL, 0, pCurrentWnd, strMessage, cSPT_PERCENT);
}


void CVersionConverterDlg::DestroyProgress(void)
{
    if(NULL != m_pProgress)
    {
        delete m_pProgress;
        m_pProgress = NULL;
    }
}


void CVersionConverterDlg::StepProgress(void)
{
    if(NULL != m_pProgress)
    {
        m_pProgress->StepIt();
        PeekAndPump();
    }
}


void CVersionConverterDlg::EnableConvert(bool bShow)
{
    CWnd* pWnd = GetDlgItem(IDC_CONVERT);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(bShow);
    }
}


void CVersionConverterDlg::ShowHideMiddle(bool bShow)
{
    int nShow = bShow ? SW_SHOW : SW_HIDE;

    CWnd* pWnd = GetDlgItem(IDC_CONVERT);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(!bShow);
    }

    pWnd = GetDlgItem(IDCANCEL);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(!bShow);
    }

    pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(!bShow);
    }

    pWnd = GetDlgItem(IDC_PROGRESSLEFT);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(nShow);
    }

    pWnd = GetDlgItem(IDC_CURRENTWORK);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(nShow);
    }

    pWnd = GetDlgItem(IDC_PROGRESS);
    if(NULL != pWnd)
    {
        pWnd->ShowWindow(nShow);
    }
}  


BOOL PeekAndPump(void)
{
  static MSG msg;

  while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
  {
	  if(!AfxGetApp()->PumpMessage())
    {
		  ::PostQuitMessage(0);
		  return FALSE;
	  }	
  }

  return TRUE;
}