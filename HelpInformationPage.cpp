#include "StdAfx.h"
#include "RunningLog.h"
#include "HelpDlg.h"
#include "HelpInformationPage.h"


BEGIN_MESSAGE_MAP(CHelpInformationPage, CPropertyPage)
END_MESSAGE_MAP()


CHelpInformationPage::CHelpInformationPage() : CPropertyPage(CHelpInformationPage::IDD)
{
}


BOOL CHelpInformationPage::OnInitDialog(void)
{
    CPropertyPage::OnInitDialog();

    CString str;

    str += "Things to remember\r\n";
    str += "------------------------\r\n\r\n";
    str += "o  You can switch between seeing distance and seeing minutes for each of running, cycling, and swimming in the calendar window by selecting Options | User Options and going to the calendar tab\r\n\r\n";
    str += "o  You can change the way pace is formatted for each of running, cycling and swimming in the same tab as above.\r\n\r\n";
    str += "o  You can change the units for running distance, cycling distance, swimming distance, height, weight, and temperature in the units tab of the same dialog.\r\n\r\n";
    str += "o  You can set which fields are mandatory when you enter a workout by unsetting the corresponding checkbox in correct tab of the options dialog.  For example, if you wanted to make it non-mandatory to enter heartrate information after a running or cycling workout, but you did want it to be mandatory after a swim workout, you would uncheck the heartrate checkbox in the \"Running Fields\" and \"Cycling Fields\" tabs, and check the heartrate checkbox in the \"Swimming Fields\" tab.  Note that there is also a \"Strength Work Fields\" tab, as well as tabs for each of the five different races that you can configure.\r\n\r\n";
    str += "o  You can right click to see a menu of some often-used options.  If you want the action you select to be applied to a certain day, your right click needs to be on that day in the calendar window.\r\n\r\n";
    str += "o  You can only add a workout if the selected day is on or before the current date\r\n\r\n";
    str += "o  You can only add an upcoming race if the selected day is on or later than the current date\r\n\r\n";
    str += "o  You can double click or hit enter on a selected day to add a workout/race/upcoming race for that day\r\n\r\n";
    str += "o  You can click the middle mouse button/wheel on a day to get a quick expanded view of the information for that day (left or right click or move the mouse away to make it disappear)\r\n\r\n";
    str += "o  You can move the selected day around on the current month using the arrow keys\r\n\r\n";
    str += "o  You can edit workouts that are already entered by looking at a day summary of the desired day.  Just change the information as desired and hit the save button on the lower left\r\n\r\n";
    str += "o  If you only want to see information from one or two sports, you can disable the display of information from the various categories in the calendar tab of the options dialog\r\n\r\n";
    str += "o  The program must be in the same directory as the file you want to open - make sure it is, or your file will not be found\r\n\r\n";
	str += "o  You can reference any kind of file in the data file associated to a given workout - heart rate monitor files, pictures, website links, anything\r\n\r\n";
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_HELPNOTES);
    if(NULL != pEdit)
    {
        pEdit->SetWindowText(str);
        pEdit->SetSel(-1, 0);
    }
    
    return TRUE;
}


void CHelpInformationPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}