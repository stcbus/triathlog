#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CSheetBikeMiscPage : public CSheetTriathLogPage
{
public:
    CSheetBikeMiscPage(void);
    
    enum {IDD = IDD_SHEETBIKEMISCPAGE};

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
	CEmptyStringFilterEdit m_edtNotes;
};
