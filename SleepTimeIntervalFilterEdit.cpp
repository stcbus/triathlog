#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "SleepTimeIntervalFilterEdit.h"


CSleepTimeIntervalFilterEdit::CSleepTimeIntervalFilterEdit(void)
{
	SetRegEx(_T("[0-9]?[0-9]:[0-9][0-9]"));;	
	SetRegEx2(_T("[0-9]?[0-9]"));;	
	SetRegEx3(_T("[0-9]?[0-9]"));;	
}


CSleepTimeIntervalFilterEdit::~CSleepTimeIntervalFilterEdit()
{
}


double CSleepTimeIntervalFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
{
	if(!::IsWindow(m_hWnd))
	{
		return NOGRAPHDATA;
	}

	CString str;
	GetWindowText(str);

	if(str.IsEmpty())
	{
		return NOGRAPHDATA;
	}

	int nHours = 0;
	int nMinutes = 0;

	int nColon = str.Find(':');
	if(-1 == nColon)
	{
		nHours = atoi(str);
		nMinutes = 0;		
	}
	else
	{
		CString strLeft = str.Left(nColon + 1);
		nHours = atoi(strLeft);

		CString strRight = str.Right(str.GetLength() - nColon - 1);
		nMinutes = atoi(strRight);
	}

	double dSleep = double(nHours) + (double)nMinutes / 60.0;

	return dSleep;
}