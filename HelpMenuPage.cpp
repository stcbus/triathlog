#include "StdAfx.h"
#include "RunningLog.h"
#include "HelpDlg.h"
#include "HelpMenuPage.h"


BEGIN_MESSAGE_MAP(CHelpMenuPage, CPropertyPage)
END_MESSAGE_MAP()


CHelpMenuPage::CHelpMenuPage() : CPropertyPage(CHelpMenuPage::IDD)
{
}


BOOL CHelpMenuPage::OnInitDialog(void)
{
    CPropertyPage::OnInitDialog();

    CString str;

    str += "Menu functions\r\n";
    str += "-------------------\r\n\r\n";
    str += "File\r\n";
    str += "\tOpen User - opens a previously created TriathLog file (must be in the same directory as TriathLog.exe)\r\n";
    str += "\tClose User - closes the current file, prompting to save if it has changed\r\n";
    str += "\tSave User - saves the current file\r\n";
    str += "\tConvert RunningLog 1.0 File - converts a file from the first version of this program to a format readable by this version\r\n";
    str += "\tConvert RunningLog 3.x File - converts a file from version 3.0 or 3.1 of this program to a format readable by this version\r\n";
    str += "\tPrint to File - prints the data to a readable text file that can be opened in any text editor\r\n";
	str += "\tExit - closes the program, prompting to save if the currently open file has changed\r\n\r\n";
    str += "Options\r\n";
    str += "\tAdd Workout - add a workout on the day that is highlighted (this day must be on or before the current date)\r\n";
    str += "\tAdd Planned Workout - mark on the calendar that you are planning a workout on the day that is highlighted (this day must be on or later than the current date)\r\n";
    str += "\tAdd Upcoming Race - mark on the calendar that you are planning to race on the day that is highlighted (this day must be on or later than the current date)\r\n";
    str += "\tAdd Multiple Items - add locations, courses, shoes, and bikes, all from a single dialog\r\n";
    str += "\tAdd Course\r\n";
    str += "\t\tRun - add information about a running course (must be done before adding a running race)\r\n";
    str += "\t\tBike - add information about a cycling course (must be done before adding a cycling race)\r\n";
    str += "\t\tSwim - add information about a swimming course (must be done before adding a swimming race)\r\n";
    str += "\t\tDuathlon - add information about a duathlon (run, bike, run) course (must be done before adding a duathlon race)\r\n";
    str += "\t\tTriathlon - add information about a triathlon (swim, bike, run) course (must be done before adding a triathlon race)\r\n";
    str += "\tAdd Location\r\n";
    str += "\t\tRun - add information about a running location (must be done before adding a run workout)\r\n";
    str += "\t\tBike - add information about a cycling location (must be done before adding a bike workout)\r\n";
    str += "\t\tSwim - add information about a swimming location (must be done before adding a swim workout)\r\n";
    str += "\t\tStrength - add information about a strength work location (must be done before adding a strength workout)\r\n";
    str += "\tAdd Shoes\r\n";
    str += "\t\tRun - add information about a pair of running shoes (must be done before adding most run workouts)\r\n";
    str += "\t\tBike - add information about a pair of cycling shoes (must be done before adding any bike workouts)\r\n";
    str += "\tAdd Bike - add information about a bike (must be done before adding any bike workouts)\r\n";
    str += "\tDelete Workout - delete a workout from the day that is highlighted\r\n";
    str += "\tDelete Planned Workout - delete a planned workout from the day that is highlighted\r\n";
    str += "\tDelete Upcoming Race - delete an upcoming race from the day that is highlighted\r\n";
    str += "\tGo To Day - move the calendar to a given day\r\n";
    str += "\tEdit User Information - edit the information you entered when you created your file, such as height and resting heart rate\r\n\r\n";
    str += "\tUser Options - customize your personal options, including the colors used\r\n\r\n";
    str += "View\r\n";
    str += "\tDay Summary - view a summary of the workouts on the day that is highlighted\r\n";
    str += "\tRunning Summary\r\n";
    str += "\t\tWeek Summary - view a summary of the running information for the week containing the highlighted day\r\n";
    str += "\t\tMonth Summary - view a summary of the running information for the month containing the highlighted day\r\n";
    str += "\t\tFull Summary - view a summary of the running information for all the days ever entered\r\n";
    str += "\t\tCustom Summary - view a summary of the running information from a given start day to a given end day\r\n";
    str += "\tBiking Summary\r\n";
    str += "\t\tWeek Summary - view a summary of the cycling information for the week containing the highlighted day\r\n";
    str += "\t\tMonth Summary - view a summary of the cycling information for the month containing the highlighted day\r\n";
    str += "\t\tFull Summary - view a summary of the cycling information for all the days ever entered\r\n";
    str += "\t\tCustom Summary - view a summary of the cycling information from a given start day to a given end day\r\n";
    str += "\tSwimming Summary\r\n";
    str += "\t\tWeek Summary - view a summary of the swimming information for the week containing the highlighted day\r\n";
    str += "\t\tMonth Summary - view a summary of the swimming information for the month containing the highlighted day\r\n";
    str += "\t\tFull Summary - view a summary of the swimming information for all the days ever entered\r\n";
    str += "\t\tCustom Summary - view a summary of the swimming information from a given start day to a given end day\r\n";
    str += "\tStrength Work Summary\r\n";
    str += "\t\tWeek Summary - view a summary of the strength work information for the week containing the highlighted day\r\n";
    str += "\t\tMonth Summary - view a summary of the strength work information for the month containing the highlighted day\r\n";
    str += "\t\tFull Summary - view a summary of the strength work information for all the days ever entered\r\n";
    str += "\t\tCustom Summary - view a summary of the strength work information from a given start day to a given end day\r\n";
    str += "\tMulti Summary\r\n";
    str += "\t\tWeek Summary - view a summary of all the information for the week containing the highlighted day\r\n";
    str += "\t\tMonth Summary - view a summary of all the information for the month containing the highlighted day\r\n";
    str += "\t\tFull Summary - view a summary of all the information for all the days ever entered\r\n";
    str += "\t\tCustom Summary - view a summary of all the information from a given start day to a given end day\r\n";
    str += "\tLocation Summary\r\n";
    str += "\t\tRun - view a summary of information entered at a given running location\r\n";
    str += "\t\tBike - view a summary of information entered at a given cycling location\r\n";
    str += "\t\tSwim - view a summary of information entered at a given swimming location\r\n";
    str += "\t\tStrength - view a summary of information entered at a given strength location\r\n";
    str += "\tRace Summary\r\n";
    str += "\t\tRun - view all the races entered for a given running course\r\n";
    str += "\t\tBike - view all the races entered for a given cycling course\r\n";
    str += "\t\tSwim - view all the races entered for a given swimming course\r\n";
    str += "\t\tDuathlon - view all the races entered for a given duathlon course\r\n";
    str += "\t\tTriathlon - view all the races entered for a given triathlon course\r\n";
    str += "\tShoe Summary\r\n";
    str += "\t\tRun - view information about the running shoes that you have added\r\n";
    str += "\t\tBike - view information about the cycling shoes that you have added\r\n";
    str += "\tBike Summary - view information about the bikes that you have added\r\n";
	str += "\tInjury Tracker - view descriptions and treatments for the injuries that you have had\r\n";
    str += "\tCurrent Notes - view and edit the current notes that pertain to your running\r\n";
    str += "\tPersonal Records\r\n";
    str += "\t\tRun - view your best times on all the running courses you have entered\r\n";
    str += "\t\tTrack - simultaneously view all of your best times for the various track distances\r\n";
    str += "\t\tBike - view your best times on all the cycling courses you have entered\r\n";
    str += "\t\tSwim - view your best times on all the swimming courses you have entered\r\n";
    str += "\t\tPool - simultaneously view all of your best times for the various indoor freestyle distances\r\n";
    str += "\t\tDuathlon - view your best times on all the duathlon courses you have entered\r\n";
    str += "\t\tTriathlon - view your best times on all the triathlon courses you have entered\r\n";
    str += "\tStatus Bar - show or hide the status bar at the bottom of the window\r\n\r\n";
    str += "Misc\r\n";
    str += "\tGraph\r\n";
    str += "\t\tLarge - in a large window, graph a variety of workout variables between any two days\r\n";
    str += "\t\tMedium - in a medium window, graph a variety of workout variables between any two days\r\n";
    str += "\t\tSmall - in a small window, graph a variety of workout variables between any two days\r\n";
	str += "\tSearch - search all entered workout data between any two dates in a sophisticated way\r\n";
	str += "\tCalories - compute the approximate calories burned in any workout\r\n";
    str += "\tPace Calculator - calculate your pace for a recent race, or for a future run based on a past time\r\n";
    str += "\tDistance Converter - convert distances from one set of units to another\r\n\r\n";
    str += "Help\r\n";
    str += "\tHelp Topics - this list\r\n";
	str += "\tDonate - donate any amount (no matter how small) to support this program and help it continue to improve\r\n";
    str += "\tAbout - an about dialog with a picture of the coolest dog in the world\r\n";
    str += "\r\n\r\n\r\n";
    str += "Be privy to the most recent updates and news via the subscriber list: simply email me (address below) with the words \"TriathLog subscribe\" in the subject.\r\n";
    str += "And if something is misleading, wrong, poorly explained, or anything like that, please email me at weil@fas.harvard.edu\r\n";

    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_HELPNOTES);
    if(NULL != pEdit)
    {
        pEdit->SetWindowText(str);
        pEdit->SetSel(-1, 0);
    }
    
    return TRUE;
}


void CHelpMenuPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}