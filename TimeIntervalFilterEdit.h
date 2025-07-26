#pragma once

#include "FilterEdit.h"

class CTimeIntervalFilterEdit : public CFilterEdit
{
public:
	CTimeIntervalFilterEdit();
	~CTimeIntervalFilterEdit();

	double GetValue(bool bComplainIfInvalid = true) const;
};