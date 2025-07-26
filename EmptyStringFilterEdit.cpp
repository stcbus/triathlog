#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "EmptyStringFilterEdit.h"


CEmptyStringFilterEdit::CEmptyStringFilterEdit(void)
{
    SetRegEx(_T(".*"));
    SetRegEx2(_T(".*"));
    SetRegEx3(_T(".*"));
}


CEmptyStringFilterEdit::~CEmptyStringFilterEdit()
{
}


CString CEmptyStringFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
{
	if(!::IsWindow(m_hWnd))
	{
		return "";
	}

	CString str;
	GetWindowText(str);

	return str;
}

