#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSheetRaceRunPage : public CSheetTriathLogPage
{
public:
    CSheetRaceRunPage(void);
    
    enum {IDD = IDD_SHEETRACERUNPAGE};

    virtual void InitDialogValues(void);
    virtual bool IsChangeAllowed(void);
    virtual bool WriteContents(void);

    virtual BOOL OnInitDialog(void);
    virtual void OnUpdateOKButton(void);

    DECLARE_MESSAGE_MAP()
protected:
    virtual void OnUpdatePaces(void);

	CStringFilterEdit m_edtDisp;
	CUIntFilterEdit m_edtTemp;
	CUIntFilterEdit m_edtHR;
	CDoubleFilterEdit m_edtDist;
	CTimeIntervalFilterEdit m_edtSeconds;
	CTimeIntervalFilterEdit m_edtSpecialSeconds;
	CEmptyStringFilterEdit m_edtNotes;
	CUIntFilterEdit m_edtPlace;
	CUIntFilterEdit m_edtRaceNumber;
};
