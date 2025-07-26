#pragma once

#include "AniDialog.h"

class CConvertLocationDlg : public CAniDialog
{
public:
	CConvertLocationDlg();

	enum { IDD = IDD_CONVERTLOCATIONDLG };

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

    afx_msg void OnUpdateOK(void);

    void SetRunLocation(bool bRun);
    bool IsRunLocation(void) const;

    void SetBikeLocation(bool bRun);
    bool IsBikeLocation(void) const;

    void SetSwimLocation(bool bRun);
    bool IsSwimLocation(void) const;

    void SetStrengthLocation(bool bRun);
    bool IsStrengthLocation(void) const;

    CString GetNotes(void) const;
    void SetNotes(CString str);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    void FillData(void);

    CString m_strNotes;
    bool m_bRun;
    bool m_bStr;
    bool m_bBike;
    bool m_bSwim;
    DECLARE_MESSAGE_MAP()
};
