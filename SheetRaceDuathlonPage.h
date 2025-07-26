#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSheetRaceDuathlonPage : public CSheetTriathLogPage
{
public:
    CSheetRaceDuathlonPage(void);
    
    enum {IDD = IDD_SHEETRACEDUATHLONPAGE};

    virtual void InitDialogValues(void);
    virtual bool IsChangeAllowed(void);
    virtual bool WriteContents(void);

    virtual BOOL OnInitDialog(void);
    virtual void OnUpdateOKButton(void);

    DECLARE_MESSAGE_MAP()
protected:
    virtual void OnUpdatePaces(void);

	CStringFilterEdit m_edtDisp;
	CTimeIntervalFilterEdit m_edtOverallSeconds;
	CTimeIntervalFilterEdit m_edtTrans1Seconds;
	CTimeIntervalFilterEdit m_edtTrans2Seconds;
	CEmptyStringFilterEdit m_edtNotes;
	CUIntFilterEdit m_edtPlace;
	CUIntFilterEdit m_edtRaceNumber;

	CUIntFilterEdit m_edtL1Temp;
	CUIntFilterEdit m_edtL1HR;
	CDoubleFilterEdit m_edtL1Dist;
	CTimeIntervalFilterEdit m_edtL1Seconds;
	CTimeIntervalFilterEdit m_edtL1SpecialSeconds;
	CUIntFilterEdit m_edtL2Temp;
	CUIntFilterEdit m_edtL2HR;
	CDoubleFilterEdit m_edtL2Dist;
	CTimeIntervalFilterEdit m_edtL2Seconds;
	CTimeIntervalFilterEdit m_edtL2SpecialSeconds;
	CUIntFilterEdit m_edtL3Temp;
	CUIntFilterEdit m_edtL3HR;
	CDoubleFilterEdit m_edtL3Dist;
	CTimeIntervalFilterEdit m_edtL3Seconds;
	CTimeIntervalFilterEdit m_edtL3SpecialSeconds;
};
