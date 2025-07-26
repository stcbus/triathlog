#include "AniDialog.h"

#include "DoubleFilterEdit.h"
#include "TimeIntervalFilterEdit.h"
#include "TimeOfDayFilterEdit.h"
#include "StringFilterEdit.h"
#include "EmptyStringFilterEdit.h"
#include "UIntFilterEdit.h"
#include "SleepTimeIntervalFilterEdit.h"

#pragma once

class CAddCourseDuathlonDlg : public CAniDialog
{
public:
	CAddCourseDuathlonDlg(CWnd* pParent = NULL);   
	virtual ~CAddCourseDuathlonDlg();

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

	enum { IDD = IDD_ADDCOURSEDUATHLONDLG };

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    double GetL1Length(void) const;
    double GetL1PRSeconds(void) const;
    CString GetL1Notes(void) const;
    double GetL2Length(void) const;
    double GetL2PRSeconds(void) const;
    CString GetL2Notes(void) const;
    double GetL3Length(void) const;
    double GetL3PRSeconds(void) const;
    CString GetL3Notes(void) const;
    double GetTransition1PRSeconds(void) const;
    double GetTransition2PRSeconds(void) const;
    CString GetOverallNotes(void) const;
    double GetOverallPRSeconds(void) const;

protected:
    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);

    void SetL1Length(double dLen);
    void SetL1PRSeconds(double dSec);
    void SetL1Notes(CString str);
    void SetL2Length(double dLen);
    void SetL2PRSeconds(double dSec);
    void SetL2Notes(CString str);
    void SetL3Length(double dLen);
    void SetL3PRSeconds(double dSec);
    void SetL3Notes(CString str);
    void SetTransition1PRSeconds(double dSec);
    void SetTransition2PRSeconds(double dSec);
    void SetOverallNotes(CString str);
    void SetOverallPRSeconds(double dSec);

    afx_msg void OnUpdateOKButton(void);
    afx_msg void OnConvert(void);
    
    void UpdatePace(void);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddCourseDuathlonDlg)

    // data
    CString m_strName;
    CString m_strCity;
    CString m_strState;
    CString m_strNotes;
    double m_dL1Length;
    double m_dL1PRSeconds;
    CString m_strL1Notes;
    double m_dL2Length;
    double m_dL2PRSeconds;
    CString m_strL2Notes;
    double m_dL3Length;
    double m_dL3PRSeconds;
    CString m_strL3Notes;
    double m_dTransition1PRSeconds;
    double m_dTransition2PRSeconds;
    double m_dOverallPRSeconds;

	CStringFilterEdit m_edtName;
	CStringFilterEdit m_edtCity;
	CStringFilterEdit m_edtState;
	CDoubleFilterEdit m_edtL1Length;
	CDoubleFilterEdit m_edtL2Length;
	CDoubleFilterEdit m_edtL3Length;
	CTimeIntervalFilterEdit m_edtL1PR;
	CTimeIntervalFilterEdit m_edtL2PR;
	CTimeIntervalFilterEdit m_edtL3PR;
	CTimeIntervalFilterEdit m_edtTrans1PR;
	CTimeIntervalFilterEdit m_edtTrans2PR;
	CTimeIntervalFilterEdit m_edtOverallPR;
	CEmptyStringFilterEdit m_edtL1Notes;
	CEmptyStringFilterEdit m_edtL2Notes;
	CEmptyStringFilterEdit m_edtL3Notes;
	CEmptyStringFilterEdit m_edtOverallNotes;
};
