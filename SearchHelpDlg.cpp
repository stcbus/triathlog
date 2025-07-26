#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "SearchHelpDlg.h"


BEGIN_MESSAGE_MAP(CSearchHelpDlg, CAniDialog)
END_MESSAGE_MAP()


CSearchHelpDlg::CSearchHelpDlg() : CAniDialog(CSearchHelpDlg::IDD)
{
}


BOOL CSearchHelpDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CString str = "1. First select what type of time span you are looking for.  If, for example, you want to find all the days you rode over 100 miles, select \"Days\" in the drop down next to the \"Searching for\" text.  If you want to see all the weeks you ran over 100 miles, then you would select \"Weeks\" instead, and so on.";
    str += "\r\n\r\n";
    str += "2. Select the time span over which the search will run.";
	str += "\r\n\r\n";
	str += "3. Select the properties you are searching for from the \"Search Fields\" area.  For example, if you are searching for weeks, and you want to find all weeks where you ran over 60 miles and swam less than half an hour, you would select in the first row \"Running Distance\" and \">\", and enter \"60\" and \"0\" (although the zero is not necessary), then check the box that says \"Use field two\", and select in the second row \"Swimming Minutes\" and \"<\", and enter \"30\" and \"0\" (again though, the zero is not necessary).";
    str += "\r\n\r\n";
	str += "4. Select the properties you are searching for from the \"Search Workout Types\" area.  For example, if you are searching for weeks, and you want to find all weeks where you raced a triathlon, check the box that says \"Use field seven\" and select in the same row \"Race\" and \"Triathlon\".  If you want to find all the days that you raced, select instead \"Race\" and \"Any\".";
	str += "\r\n\r\n";
	str += "5. Now you need to select how to combine the properties you entered.  If you have the data entered as in 3 and 4 (i.e. you have entered the properties \"running over 60 miles\", \"swimming less than half an hour\", and \"raced a triathlon\"), and you want to find weeks in which you did the first two, but not the third , you would enter \"1 and 2 and not 7\".  If you wanted to find weeks where you did all three, you would enter \"1 and 2 and 7\".  If you wanted to find weeks where you did any one of the three, you would enter \"1 or 2 or 7\".  If you wanted to find weeks where you ran 60 miles or swam more than a half hour, you would enter \"1 or not 2\" (it is \"not 2\" because we are looking for swimming more than a half hour, and 2 represents swimming less than a half hour).  Use parentheses as needed; for example, to find weeks where you either ran at least 60 miles and swam less than a half hour, or where you raced a triathlon, you would enter \"(1 and 2) or 7\".";
	str += "\r\n\r\n";
	str += "6. Hit the search button.";
	str += "\r\n\r\n";
	str += "7. The dates that satisfy the search will display in the list on the right.  Double click any of them to see a quick summary of the information for that day, week, or month.";
	str += "\r\n\r\n";

	SetDlgItemText(IDC_REMINDER, str);
    
    return TRUE;
}


void CSearchHelpDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}