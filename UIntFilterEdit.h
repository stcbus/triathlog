#pragma once

#include "FilterEdit.h"

class CUIntFilterEdit : public CFilterEdit
{
public:
	CUIntFilterEdit();
	~CUIntFilterEdit();
	int GetValue(bool bComplainIfInvalid = true) const;
};