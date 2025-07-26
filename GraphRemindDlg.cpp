#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "GraphRemindDlg.h"


BEGIN_MESSAGE_MAP(CGraphRemindDlg, CAniDialog)
END_MESSAGE_MAP()


CGraphRemindDlg::CGraphRemindDlg() : CAniDialog(CGraphRemindDlg::IDD)
{
}


BOOL CGraphRemindDlg::OnInitDialog(void)
{
    CAniDialog::OnInitDialog();

    CString str = "1. To change any chart properties, right click anywhere on the chart area and select the \"Customization Dialog\" option (if it is not a 3D graph, double clicking will have the same effect -- see note 6).   This lets you modify all the parameters associated with any of the graphs you have made.";
    str += "\r\n\r\n";
    str += "2. Each chart can have up to twelve graphs on it.  There can only be one chart per window, but multiple chart windows can be open at the same time.";
    str += "\r\n\r\n";
    str += "3. To graph two things on the same axis, start by filling in the information about the first series under the \"Series 1\" tab.  Then click on one of the other series tabs (\"Series 2\" for example) and fill out that information, making sure to check the \"Use Series 2\" box.  Then click the graph button.  If it seems like only one series is showing, it may be that the values of the two series are very different (i.e. if calories and workouts are graphed, it will be tough to see the workout data, because calories is probably around 1000 and workouts is around 2 or 3).  One way to get around this is to use the \"Formula\" option instead, and use it to multiply the smaller value by an appropriate amount (so perhaps graph calories and 400 * n, where as below n stands for overall workouts in the formula dialog).";
    str += "\r\n\r\n";
    str += "4. For some reason, certain types of graphs do not accept date values for the axis.  For these, if you are graphing versus time, you will see five digit numbers on that axis.  These numbers are the elapsed days since midnight, December 30, 1899.";
    str += "\r\n\r\n";
    str += "5. In the formula dialog, each entity must be separated by an operand (eg + - * / ^).  Inputs like \"2sin(b)\" will not be parsed correctly -- write this instead as \"2*sin(b)\" or \"2 * sin(b)\" (spaces do not matter).";
    str += "\r\n\r\n";
	str += "6. Double-clicking a 3D graph will start it rotating, while double clicking any other type of graph will bring up the customization dialog.";
	str += "\r\n\r\n";
	str += "7. For normal 2D graphs, the cursor's (x, y) position is shown in the top left";
	str += "\r\n\r\n";
    str += "The associations between variables and data for the formula parser are as follows:";
    str += "\r\n";
    str += "B: Running minutes\r\n";
	str += "C: Calories\r\n";
    str += "F: Cycling minutes\r\n";
    str += "J: Swimming minutes\r\n";
    str += "K: Strength work minutes\r\n";
    str += "M: Overall minutes\r\n";
    str += "N: Running miles\r\n";
    str += "P: Cycling miles\r\n";
    str += "Q: Swimming miles\r\n";
    str += "X: Running pace (min per mile)\r\n";
    str += "Y: Cycling pace (mph)\r\n";
    str += "b: Swimming pace (min per 100m)\r\n";
    str += "f: Running workouts\r\n";
    str += "j: Cycling workouts\r\n";
    str += "k: Swimming workouts\r\n";
    str += "m: Strength workouts\r\n";
    str += "n: Overall workouts\r\n";
    str += "p: Sleep\r\n";
    str += "q: Weight\r\n";
    str += "x: Temperature\r\n";
    str += "y: Heartrate\r\n";
    str += "z: Points\r\n"; 
    
    SetDlgItemText(IDC_REMINDER, str);
    
    return TRUE;
}


void CGraphRemindDlg::DoDataExchange(CDataExchange* pDX)
{
    CAniDialog::DoDataExchange(pDX);
}