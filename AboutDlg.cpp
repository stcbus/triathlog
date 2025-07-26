#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "AboutDlg.h"


BEGIN_MESSAGE_MAP(CAboutDlg, CAniDialog)
END_MESSAGE_MAP()


CAboutDlg::CAboutDlg() : CAniDialog(CAboutDlg::IDD)
{
}


BOOL CAboutDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CString str = "Please give me feedback.  If you find any bugs, think of any features you would like me to add, etc, just drop me an email.  I will be updating this as time allows.  Also, if you use it consistently, I'd love to know!";
    str += "\r\n\r\n";
    str += "Thank you to my beta testers and bug fixers: TJ, TJ, TJ, TJ, TJ, Heidi, Illya, Jon, David, Curtis, Kristin, and TJ.";
    str += "\r\n\r\n";
    str += "Also, thank you to the following people whose free MFC components are available at www.codeproject.com:";
    str += "\r\n";
    str += "Davide Calabro -- ButtonST, eXDib";
    str += "\r\n";
    str += "Chris Maunder -- TabCtrlEx, HyperLink";
    str += "\r\n";
    str += "Abin -- AniDialog";
    str += "\r\n";
    str += "John O'Byrne - SplashScreenEx";
    str += "\r\n";
    str += "Jean Michael LaFol -- MenuXP";
    str += "\r\n";
    str += "David Koch - SkinProgress";
    str += "\r\n";
    str += "Johann Nadalutti - RollupCtrl";
    str += "\r\n";
    str += "Ralf Wirtz - FormulaParser";
    str += "\r\n";
    str += "Keith Rule - MemDC";
    str += "\r\n";
    str += "Eugene Pustovoyt -- PPToolTip";
	str += "\r\n";
	str += "PJ Naughter -- SingleInstance";
    str += "\r\n\r\n";
    str += "Happy training!";

    SetDlgItemText(IDC_NOTES, str);
    
	m_lnkEmail.SetURL(_T("mailto:weil@fas.harvard.edu"));
    m_lnkWebsite.SetURL(_T("http://www.people.fas.harvard.edu/~weil/"));
	m_lnkPayPal.SetURL(_T("https://www.paypal.com/xclick/business=weil%40fas.harvard.edu&item_name=TriathLog&no_shipping=1&cn=Optional+Note&tax=0&currency_code=USD"));

    return TRUE;
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_EMAIL, m_lnkEmail);
	DDX_Control(pDX, IDC_WEBSITE, m_lnkWebsite);
	DDX_Control(pDX, IDC_PAYPAL, m_lnkPayPal);

    CAniDialog::DoDataExchange(pDX);
}