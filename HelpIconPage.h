#pragma once

class CHelpIconPage : public CPropertyPage
{
public:
	CHelpIconPage();

// Dialog Data
	enum { IDD = IDD_HELPICONSPAGE };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
