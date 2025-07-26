#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "UIntFilterEdit.h"


CUIntFilterEdit::CUIntFilterEdit(void)
{
    SetRegEx(_T("[0-9]+"));
    SetRegEx2(_T("[0-9]+"));
    SetRegEx3(_T("[0-9]+"));
}


CUIntFilterEdit::~CUIntFilterEdit()
{
}


int CUIntFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
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

	return atoi(str);
}

