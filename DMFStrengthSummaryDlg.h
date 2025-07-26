#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CDMFStrengthSummaryDlg : public CAniDialog
{
public:
	CDMFStrengthSummaryDlg(CWnd* pParent = NULL);   
	virtual ~CDMFStrengthSummaryDlg();

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_DMFSTRENGTHSUMMARYDLG };

    COleDateTime GetTimeFrom(void) const;
    COleDateTime GetTimeTo(void) const;
    CUser* GetUser(void) const;

    void SetTimeFrom(COleDateTime tm);
    void SetTimeTo(COleDateTime tm);
    void SetUser(CUser* pUser);

    virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CDMFStrengthSummaryDlg)

    // data
    COleDateTime m_tmFrom;
    COleDateTime m_tmTo;
    CUser* m_pUser;
};