#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "DoubleFilterEdit.h"


CDoubleFilterEdit::CDoubleFilterEdit(void)
{
    SetRegEx(_T("[0-9]+\\.[0-9]*"));
	SetRegEx2(_T("\\.[0-9]+"));
	SetRegEx3(_T("[0-9]+"));
}


CDoubleFilterEdit::~CDoubleFilterEdit()
{
}


double CDoubleFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
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

	return atof(str);
}

