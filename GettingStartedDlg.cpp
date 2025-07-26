#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "GettingStartedDlg.h"


BEGIN_MESSAGE_MAP(CGettingStartedDlg, CAniDialog)
END_MESSAGE_MAP()


CGettingStartedDlg::CGettingStartedDlg() : CAniDialog(CGettingStartedDlg::IDD)
{
}


BOOL CGettingStartedDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CString str = "TriathLog tracks a multitude of data, including mileage, workout time, paces, temperature, heartrate, and windiness.  It also tracks information about the shoes and bikes you use, so that with one click you can look (for example) at the total mileage on a pair of shoes to see if you need to get a new pair.  Finally, it tracks the locations you work out at and courses you race on, so that with one click you can look at all the days you worked out at a given location, or raced a certain course.\r\n\r\n";
	str += "All of this data is initially required, but it can be made optional through the options dialog.  When you are finished creating your file, select \"Options | User Options\" from the menu to open the dialog and customize your experience with TriathLog.  In the tabs of the options dialog, you can uncheck any checkboxes for data that you do not want to be mandatory each time you enter a workout.  So, for example, if you do not want it to be mandatory to enter heartrate information for swimming workouts, go to the tab called \"Swimming Fields\" and uncheck the box next to \"Heartrate\".  If you do this, TriathLog will still track your swimming heartrate if you enter it for a workout, but it will not be mandatory to enter it.\r\n\r\n";
	str += "To track information about locations, courses, shoes, and bikes, that data must first be entered into TriathLog.  The dialog following this one lets you enter that information.  You do not have to do it now, but unless you make it non-mandatory as described above, you will need to enter that data before you enter a workout that uses it (so before you enter a running workout, you will need to enter at least one run location and at least one pair of running shoes, though you will not need to add a bike or a course).  So enter some information in the next dialog, and then start tracking your training!\r\n\r\n";
   	str += "A quick note about entering data.  Times of the day are entered in 12 hour format as hh:mm am/pm, or in 24 hour format as hh:mm.  Sleep is entered as hh:mm.  Decimal quantities like weight or distance and integer quantities like temperature or heartrate are entered the usual way.  Finally, time intervals like overall workout time can be entered as hh:mm:ss.ms or mm:ss.ms, where the millisecond value is optional in both cases.";
    SetDlgItemText(IDC_REMINDER, str);
    
    return TRUE;
}


void CGettingStartedDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}