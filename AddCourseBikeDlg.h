#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CAddCourseBikeDlg : public CAniDialog
{
public:
	CAddCourseBikeDlg(CWnd* pParent = NULL);   
	virtual ~CAddCourseBikeDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDCOURSEBIKEDLG };

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    double GetLength(void) const;
    double GetPRSeconds(void) const;
    CString GetNotes(void) const;

protected:
    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);
    void SetLength(double dLen);
    void SetPRSeconds(double dSec);
    void SetNotes(CString str);

    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnConvert(void);

    void UpdatePace(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddCourseBikeDlg)

    // data
    CString m_strName;
    CString m_strCity;
    CString m_strState;
    double m_dLength;
    double m_dPRSeconds;
    CString m_strNotes;

	CStringFilterEdit m_edtName;
	CStringFilterEdit m_edtCity;
	CStringFilterEdit m_edtState;
	CDoubleFilterEdit m_edtLength;
	CTimeIntervalFilterEdit m_edtPR;
	CEmptyStringFilterEdit m_edtNotes;
};
