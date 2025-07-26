#pragma once

#include "AniDialog.h"

class CConvertWorkoutBikeDlg : public CAniDialog
{
public:
	CConvertWorkoutBikeDlg();

	enum { IDD = IDD_CONVERTRUNBIKEDLG };

    virtual BOOL OnInitDialog(void);
    virtual void OnOK(void);

    void SetResult(int nResult);
    int GetResult(void) const;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    int m_nResult; 
    DECLARE_MESSAGE_MAP()
};
