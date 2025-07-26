#pragma once

#include "FilterEdit.h"

class CTimeOfDayFilterEdit : public CFilterEdit
{
public:
	CTimeOfDayFilterEdit();
	~CTimeOfDayFilterEdit();
	COleDateTime GetValue(bool bComplainIfInvalid = true) const;
};