#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "TimeOfDayFilterEdit.h"


CTimeOfDayFilterEdit::CTimeOfDayFilterEdit(void)
{
	SetRegEx(_T("[0-9]?[0-9]:[0-9][0-9]\\ (a|A|p|P)(m|M)")); //\\:[0-9][0-9]\\")); //[0-9]:[0-9][0-9] (\\i(a|p)m"));	
	SetRegEx2(_T("[0-9]?[0-9]:[0-9][0-9] "));	
	SetRegEx2(_T("[0-9]?[0-9]:[0-9][0-9]"));	
}


CTimeOfDayFilterEdit::~CTimeOfDayFilterEdit()
{
}


COleDateTime CTimeOfDayFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
{
	if(!::IsWindow(m_hWnd))
	{
		return COleDateTime::GetCurrentTime();
	}

	CString str;
	GetWindowText(str);

	int nHours = 0;
	int nMinutes = 0;
	bool bAM = true;
	bool b24Hour = false;

	int nColon = str.Find(':');
	if(-1 == nColon)
	{
		if(true == bComplainIfInvalid)
		{
			CUtil::Fatal("Bad string in CTimeOfDayFilter::GetValue");
		}
		return COleDateTime::GetCurrentTime();
	}

	CString strLeft = str.Left(nColon + 1);
	nHours = atoi(strLeft);

	CString strRight = str.Right(str.GetLength() - nColon - 1);

	int nSpace = strRight.Find(' ');
	if(-1 == nSpace)
	{
		bAM = true;
		b24Hour = true;
		nMinutes = atoi(strRight);
	}
	else
	{
		CString strLeft2 = strRight.Left(strRight.GetLength() - nSpace - 1);
		nMinutes = atoi(strLeft2);
		b24Hour = false;

		if(0 == strRight.Right(2).CompareNoCase("pm"))
		{
			bAM = false;
		}
		else
		{
			bAM = true;
		}
	}

	COleDateTime tm = COleDateTime::GetCurrentTime();
	if(true == b24Hour)
	{
		tm.SetTime(nHours, nMinutes, 0);
	}
	else
	{
		if((12 == nHours) && (true == bAM))
		{
			nHours = 0;
		}

		if(false == bAM)
		{
			if(nHours != 12)
			{
				nHours += 12;
			}
		}

		tm.SetTime(nHours, nMinutes, 0);
	}
	
	return tm;
}