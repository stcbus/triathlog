#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CDMFSwimSummaryDlg : public CAniDialog
{
public:
	CDMFSwimSummaryDlg(CWnd* pParent = NULL);   
	virtual ~CDMFSwimSummaryDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_DMFSWIMSUMMARYDLG };

    COleDateTime GetTimeFrom(void) const;
    COleDateTime GetTimeTo(void) const;
    CUser* GetUser(void) const;

    void SetTimeFrom(COleDateTime tm);
    void SetTimeTo(COleDateTime tm);
    void SetUser(CUser* pUser);

    virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CDMFSwimSummaryDlg)

    // data
    COleDateTime m_tmFrom;
    COleDateTime m_tmTo;
    CUser* m_pUser;
};