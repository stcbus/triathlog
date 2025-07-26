#pragma once

#include "FilterEdit.h"

class CSleepTimeIntervalFilterEdit : public CFilterEdit
{
public:
	CSleepTimeIntervalFilterEdit();
	~CSleepTimeIntervalFilterEdit();
	double GetValue(bool bComplainIfInvalid = true) const;
};