#pragma once

class CHelpExtrasPage : public CPropertyPage
{
public:
	CHelpExtrasPage();

// Dialog Data
	enum { IDD = IDD_HELPPAGE };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
