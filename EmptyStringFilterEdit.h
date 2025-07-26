#pragma once

#include "FilterEdit.h"

class CEmptyStringFilterEdit : public CFilterEdit
{
public:
	CEmptyStringFilterEdit();
	~CEmptyStringFilterEdit();
	CString GetValue(bool bComplainIfInvalid = true) const;
};