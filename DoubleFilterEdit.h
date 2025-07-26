#pragma once

#include "FilterEdit.h"

class CDoubleFilterEdit : public CFilterEdit
{
public:
	CDoubleFilterEdit();
	~CDoubleFilterEdit();
	double GetValue(bool bComplainIfInvalid = true) const;
};