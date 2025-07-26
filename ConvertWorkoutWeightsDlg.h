#pragma once

#include "AniDialog.h"

class CConvertWorkoutWeightsDlg : public CAniDialog
{
public:
	CConvertWorkoutWeightsDlg();

	enum { IDD = IDD_CONVERTRUNWEIGHTSDLG };

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

    void SetResult(int nResult);
    int GetResult(void) const;

    CString GetNotes(void) const;
    void SetNotes(CString str);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    CString m_strNotes;
    int m_nResult; 
    DECLARE_MESSAGE_MAP()
};
