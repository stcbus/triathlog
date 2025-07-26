#pragma once

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

class CDaySummarySheet;
class CWorkout;
class CUser;
class CDayLog;

class CSheetTriathLogPage : public CPropertyPage
{
public:
    CSheetTriathLogPage(int nID);

    CWorkout* GetWorkout(void) const;
    CDaySummarySheet* GetParentSheet(void) const;
    CUser* GetUser(void) const;
    CDayLog* GetDay(void) const;

    void SetWorkout(CWorkout* pWorkout);
    void SetParentSheet(CDaySummarySheet* pSheet);
    void SetUser(CUser* pUser);

    virtual BOOL OnInitDialog(void);

    bool BaseWriteContents(bool bIs2 = false);
    bool BaseUpdateOKButton(bool bIs2 = false);
	void BaseInitDialogValues(bool bIs2 = false);

    virtual void InitDialogValues(void) = 0;
    virtual bool IsChangeAllowed(void) = 0;
    virtual bool WriteContents(void) = 0;

	afx_msg void OnConvert(void);
	afx_msg void OnChooseDataFile(void);

	CString GetDataFilename(void);

    DECLARE_DYNAMIC(CSheetTriathLogPage);
    DECLARE_MESSAGE_MAP()
    
protected:
    CWorkout* m_pWorkout;
    CDaySummarySheet* m_pParentSheet;
    CUser* m_pUser;

	CDoubleFilterEdit m_edtWeight;
	CSleepTimeIntervalFilterEdit m_edtSleep;
	CTimeOfDayFilterEdit m_edtTime;
	CEmptyStringFilterEdit m_edtDataFile;
};