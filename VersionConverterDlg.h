#pragma once
#include "StdAfx.h"
#include "RunningLog.h"
#include "AniDialog.h"
#include "SkinProgress.h"
#include "XMLConverter.h"

class CVersionConverterDlg : public CAniDialog
{
public:
	CVersionConverterDlg();

	enum { IDD = IDD_VERSIONCONVERTERDLG };

    virtual BOOL OnInitDialog(void);

    void SetNotes(CString str);
    void CreateProgress(CString strMessage, int nSteps);
    void DestroyProgress(void);
    void StepProgress(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    afx_msg void OnOpenFile(void);
    afx_msg void OnConvert(void);

    void ShowHideMiddle(bool bShow);
    void EnableConvert(bool bShow);

    CXMLConverter m_xmlConv;
    CStatic m_stcProgress;
    CSkinProgress* m_pProgress;
	DECLARE_MESSAGE_MAP()
};


BOOL PeekAndPump(void);
