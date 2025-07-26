#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "Util.h"
#include "AddUserDlg.h"
#include "TrackPRDlg.h"
#include "SwimPRDlg.h"
#include "GettingStartedDlg.h"
#include "AniDialog.h"
#include "AddAllDataDlg.h"
#include "OpenUserDlg.h"


IMPLEMENT_DYNAMIC(COpenUserDlg, CAniDialog)

BEGIN_MESSAGE_MAP(COpenUserDlg, CAniDialog)
    ON_COMMAND(ID_ADDUSER, OnAddUser)
    ON_COMMAND(ID_DELETEUSER, OnDeleteUser)

    ON_LBN_SELCHANGE(IDC_USERNAME, OnUpdateOKDelete)
END_MESSAGE_MAP()


COpenUserDlg::COpenUserDlg(CWnd* pParent /* = NULL*/) : CAniDialog(COpenUserDlg::IDD, pParent)
{
}

COpenUserDlg::~COpenUserDlg()
{
}


BOOL COpenUserDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();
    
    RefreshListbox();

    CListBox* pList = (CListBox*)GetDlgItem(IDC_USERNAME);
    if(NULL == pList)
    {
        return FALSE;
    }
    pList->SetCurSel(0);

    OnUpdateOKDelete();
    return TRUE;
}


void COpenUserDlg::OnOK(void)
{
    CListBox* pList = (CListBox*)GetDlgItem(IDC_USERNAME);
    if(NULL == pList)
    {
        return;
    }

    int nSel = pList->GetCurSel();
    CString str = m_strlstFiles.GetAt(m_strlstFiles.FindIndex(nSel));
    SetSelectedFile(str);
    if("" == str)
    {
        AfxMessageBox("Please select a file to open.  If the list is empty, hit the \"Add User...\" button.");
        return;
    }

    CAniDialog::OnOK();
}


void COpenUserDlg::OnUpdateOKDelete(void)
{
    bool fEnable = true;

    CListBox* pList = (CListBox*)GetDlgItem(IDC_USERNAME);
    if(NULL != pList)
    {
        int nSel = pList->GetCurSel();
        if(CB_ERR == nSel)
        {
            fEnable = false;
        }
    }

    CWnd* pWndOK = GetDlgItem(IDOK);
    CWnd* pWndDel = GetDlgItem(ID_DELETEUSER);
    if((NULL != pWndOK) || (NULL != pWndDel))
    {
        pWndOK->EnableWindow(fEnable);
        pWndDel->EnableWindow(fEnable);
    }
}  


void COpenUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX); 
}


void COpenUserDlg::OnAddUser(void)
{
    CAddUserDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        CUser usrNew;
        CTrackPRDlg dlgPRTrack;
        CSwimPRDlg dlgPRSwim;
        CAddAllDataDlg dlgData;
		CGettingStartedDlg dlgGettingStarted;
        dlgPRTrack.SetUser(&usrNew);
        dlgPRSwim.SetUser(&usrNew);
        dlgData.SetUser(&usrNew);
		if((IDOK == dlgPRTrack.DoModal()) && (IDOK == dlgPRSwim.DoModal()) && (IDOK == dlgGettingStarted.DoModal()) && (IDOK == dlgData.DoModal()))
        {
            usrNew.SetFirstName(dlg.GetFirstName());
            usrNew.SetLastName(dlg.GetLastName());
            usrNew.SetSex(dlg.GetSex());
            usrNew.SetHeight(dlg.GetHeight());
            usrNew.SetRestingHR(dlg.GetRestHR());
            usrNew.SetFirstDayOfWeek(dlg.GetFirstDay());

            if(dlg.AreUnitsAmerican())
            {
                usrNew.SetRunDistUnits(DISTUNITS_MI);
                usrNew.SetBikeDistUnits(DISTUNITS_MI);
                usrNew.SetSwimDistUnits(DISTUNITS_MI);
                usrNew.SetHeightUnits(HEIGHTUNITS_IN);
                usrNew.SetWeightUnits(WEIGHTUNITS_LBS);
                usrNew.SetTempUnits(TEMPUNITS_DEG);
            }
            else
            {
                usrNew.SetRunDistUnits(DISTUNITS_KM);
                usrNew.SetBikeDistUnits(DISTUNITS_KM);
                usrNew.SetSwimDistUnits(DISTUNITS_KM);
                usrNew.SetHeightUnits(HEIGHTUNITS_CM);
                usrNew.SetWeightUnits(WEIGHTUNITS_KG);
                usrNew.SetTempUnits(TEMPUNITS_CELSIUS);
            }

            CUtil::SaveXML(&usrNew);
            
            RefreshListbox();
        }
    }
}


void COpenUserDlg::OnDeleteUser(void)
{
    CListBox* pList = (CListBox*)GetDlgItem(IDC_USERNAME);
    if(NULL != pList)
    {
        int nSel = pList->GetCurSel();
        if(-1 == nSel)
        {
            AfxMessageBox("Please select a file to delete.");
            return;
        }

        CString str = m_strlstFiles.GetAt(m_strlstFiles.FindIndex(nSel));
        CString strMessage = "Are you sure you want to delete the entire log for ";
        strMessage += str;
        strMessage += "?";
        
        if(IDYES == AfxMessageBox(strMessage, MB_YESNO | MB_ICONQUESTION))
        {
            CUtil::DeleteLocalFile(str);
            RefreshListbox();
        }
    }
}
 

void COpenUserDlg::RefreshListbox(void)
{
    m_strlstFiles.RemoveAll();

    CString strFiles = CUtil::GetExeDirectory();
    strFiles += "*";
    strFiles += CUtil::GetFileExtension();

    CFileFind fndFiles;
	BOOL fWorking = fndFiles.FindFile(strFiles);
	while(fWorking) 
	{
		fWorking = fndFiles.FindNextFile();
        if((fndFiles.IsDots()) || (fndFiles.IsDirectory()))
        {
	   		continue;
        }

        CString str = fndFiles.GetFileName();
        int n = str.ReverseFind('.');
        str = str.Left(n);
	
        m_strlstFiles.AddHead(str);
    }

    CListBox* pList = (CListBox*)GetDlgItem(IDC_USERNAME);
    if(NULL != pList)
    {
        pList->ResetContent();
        for(POSITION pos = m_strlstFiles.GetHeadPosition(); NULL != pos;)
        {
            pList->AddString(m_strlstFiles.GetNext(pos));
        }
    }
}


CString COpenUserDlg::GetSelectedFile(void) const
{
    return m_strSelected;
}


void COpenUserDlg::SetSelectedFile(CString str)
{
    m_strSelected = str;
}