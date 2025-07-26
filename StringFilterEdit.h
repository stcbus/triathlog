#pragma once

#include "FilterEdit.h"

class CStringFilterEdit : public CFilterEdit
{
public:
	CStringFilterEdit();
	~CStringFilterEdit();
	CString GetValue(bool bComplainIfInvalid = true) const;
};