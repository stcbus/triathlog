#include "StdAfx.h"
#include "Util.h"
#include "RunningLog.h"
#include "StringFilterEdit.h"


CStringFilterEdit::CStringFilterEdit(void)
{
    SetRegEx(_T(".+"));
    SetRegEx2(_T(".+"));
    SetRegEx3(_T(".+"));
}


CStringFilterEdit::~CStringFilterEdit()
{
}


CString CStringFilterEdit::GetValue(bool bComplainIfInvalid /* = true */) const
{
	if(!::IsWindow(m_hWnd))
	{
		return "";
	}

	CString str;
	GetWindowText(str);

	return str;
}

