#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once


class CCurrentNotesDlg : public CAniDialog
{
public:
	CCurrentNotesDlg(CWnd* pParent = NULL);   
	virtual ~CCurrentNotesDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_CURRENTNOTESDLG };

    CString GetNotes(void) const;
    bool IsReadOnly(void) const;

    void SetNotes(CString str);
    void SetReadOnly(bool fReadOnly);

protected:
    afx_msg void OnEditNotes(void);
    
    void HandleEditButton(void);

    DECLARE_DYNAMIC(CCurrentNotesDlg)
    DECLARE_MESSAGE_MAP()

    // data
    CString m_strNotes;
    bool m_fReadOnly;

	CEmptyStringFilterEdit m_edtNotes;
};