#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "AniDialog.h"
#include "CurrentNotesDlg.h"


IMPLEMENT_DYNAMIC(CCurrentNotesDlg, CAniDialog)


BEGIN_MESSAGE_MAP(CCurrentNotesDlg, CAniDialog)
    ON_COMMAND(ID_EDITNOTES, OnEditNotes)
END_MESSAGE_MAP()


CCurrentNotesDlg::CCurrentNotesDlg(CWnd* pParent /* = NULL*/) : CAniDialog(CCurrentNotesDlg::IDD, pParent)
{
    SetReadOnly(true);
}


CCurrentNotesDlg::~CCurrentNotesDlg()
{
}


BOOL CCurrentNotesDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();
    
	m_edtNotes.SubclassDlgItem(IDC_NOTES, this);

    SetDlgItemText(IDC_NOTES, GetNotes());
    HandleEditButton();

    return TRUE;
}


void CCurrentNotesDlg::HandleEditButton(void)
{
    CWnd* pWndEdit = GetDlgItem(ID_EDITNOTES);
    CEdit* pWndNotes = (CEdit*)GetDlgItem(IDC_NOTES);

    if((NULL == pWndEdit) || (NULL == pWndNotes))
    {
        return;
    }

    if(IsReadOnly())
    {
        pWndEdit->EnableWindow();
        pWndNotes->SetReadOnly();
    }

    else
    {
        pWndEdit->EnableWindow(false);
        pWndNotes->SetReadOnly(false);
    }
}


void CCurrentNotesDlg::OnEditNotes(void)
{
    SetReadOnly(!IsReadOnly());
    HandleEditButton();
}


void CCurrentNotesDlg::OnOK(void)
{
	SetNotes(m_edtNotes.GetValue());

    CAniDialog::OnOK();
}


CString CCurrentNotesDlg::GetNotes(void) const
{
    return m_strNotes;
}


bool CCurrentNotesDlg::IsReadOnly(void) const
{
    return m_fReadOnly;
}


void CCurrentNotesDlg::SetNotes(CString str)
{
    m_strNotes = str;
}


void CCurrentNotesDlg::SetReadOnly(bool fReadOnly)
{
    m_fReadOnly = fReadOnly;
}