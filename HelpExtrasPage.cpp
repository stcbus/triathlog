#include "StdAfx.h"
#include "RunningLog.h"
#include "HelpDlg.h"
#include "HelpExtrasPage.h"


BEGIN_MESSAGE_MAP(CHelpExtrasPage, CPropertyPage)
END_MESSAGE_MAP()


CHelpExtrasPage::CHelpExtrasPage() : CPropertyPage(CHelpExtrasPage::IDD)
{
}


BOOL CHelpExtrasPage::OnInitDialog(void)
{
    CPropertyPage::OnInitDialog();

    CString str;

    str += "Extras\r\n";
    str += "--------\r\n\r\n";
    str += "o  If you want to change something in your file that the program doesn't allow you to change, you can edit the file directly.  First, check the menu tab of this dialog and make sure that the program doesn't already to what you're looking for.  If it doesn't, you can also try contacting me -- I may be able to add that feature quickly for you.  If you want to edit the file, though, the file format is pretty human-readable.  Open the file in Wordpad, MS Word, Internet Explorer, or some other program that is good at displaying formatted text (Notepad is not good enough).  Then, for example, if you want to change the height you entered when you first started your log, scroll down to the line that says \"<Height value=\"73\"/>\" and just change the 73 (or whatever you entered) to whatever you want.  You can change workout information too by first finding the day the workout is on, looking in the workouts for that day (grouped right after that day), finding the workout you're after based on the information you entered for it, and changing the desired field.\r\n\r\n";
    str += "o  If you do choose to change parts of your file, DO NOT change anything in the \"Hash Map\" section, as it can have unpredictable results.  Also, do not attempt to change the type of workout (i.e. from Run | Easy to Run | Hills) unless you really know what you're doing.  If you don't fill out the fields correctly, the file will no longer be readable.  Editing the file directly is possible, it's just dangerous and not recommended.\r\n\r\n";
    str += "o  If you need to change your file directly and are unsure of how to do it, you can email your file to me and I can make small changes for you (it should take less than 5 minutes and I'll send it right back).  Unless this starts happening every day, I won't mind at all.\r\n\r\n";

    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_HELPNOTES);
    if(NULL != pEdit)
    {
        pEdit->SetWindowText(str);
        pEdit->SetSel(-1, 0);
    }
    
    return TRUE;
}


void CHelpExtrasPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}