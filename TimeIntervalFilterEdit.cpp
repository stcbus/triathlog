#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "TimeIntervalFilterEdit.h"


CTimeIntervalFilterEdit::CTimeIntervalFilterEdit(void)
{
	SetRegEx(_T("[0-9]+:[0-9][0-9]:[0-9][0-9](\\.[0-9]*)?"));	
	SetRegEx2(_T("[0-9]+:[0-9][0-9](\\.[0-9]*)?"));
	SetRegEx3(_T("[0-9]+:[0-9][0-9](\\.[0-9]*)?"));
}


CTimeIntervalFilterEdit::~CTimeIntervalFilterEdit()
{
}


double CTimeIntervalFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
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

	CString strTemp = str;
	CString strToken;
	CString strCur;
	CString strFrac;
	int nCurPos = 0;
	int nCurIndex = 0;

	int nVals[4] = {0, 0, 0, 0};
	
	int nColons = strTemp.Remove(':');

	if(1 == nColons)
	{
		nCurIndex = 1;
	}
	else if(2 == nColons)
	{
		nCurIndex = 0;
	}
	else
	{
		if(true == bComplainIfInvalid)
		{
			CUtil::Fatal("Bad string in CTimeIntervalFilter::GetValue");
		}
		return NOGRAPHDATA;
	}

	strToken = ":.";

	strCur = str.Tokenize(strToken, nCurPos);

	while(strCur != "")
	{
		nVals[nCurIndex] = atoi(strCur);
		nCurIndex++;

		if(4 == nCurIndex)
		{
			strFrac = strCur;
			break;
		}

		strCur = str.Tokenize(strToken, nCurPos);
	}
    
	double dRes = (double)nVals[2];
    
    CString strNew = _T(".");
    strNew += strFrac;

    double dFrac = atof(strNew);

    return (3600 * nVals[0] + 60 * nVals[1] + dRes + dFrac);
}