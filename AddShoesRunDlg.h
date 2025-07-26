#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CAddShoesRunDlg : public CAniDialog
{
public:
	CAddShoesRunDlg(CWnd* pParent = NULL);   
	virtual ~CAddShoesRunDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDSHOESRUNDLG };

    CString GetBrand(void) const;
    CString GetType(void) const;
    COleDateTime GetFirstUse(void) const;
    double GetSize(void) const;
    CString GetNotes(void) const;

protected:
    void SetBrand(CString str);
    void SetType(CString str);
    void SetFirstUse(COleDateTime tm);
    void SetSize(double dSize);
    void SetNotes(CString str);

    afx_msg void OnUpdateOKButton(void);
	afx_msg void OnDropDown(NMHDR* pNmHdr, LRESULT* pResult);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddShoesRunDlg)

    // data
    CString m_strBrand;
    CString m_strType;
    COleDateTime m_tmFirst;
    double m_dSize;
    CString m_strNotes;

	CStringFilterEdit m_edtBrand;
	CDoubleFilterEdit m_edtSize;
	CStringFilterEdit m_edtModel;
	CEmptyStringFilterEdit m_edtNotes;
};
