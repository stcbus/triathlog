#pragma once

class CHelpMenuPage : public CPropertyPage
{
public:
	CHelpMenuPage();

// Dialog Data
	enum { IDD = IDD_HELPPAGE };

    virtual BOOL OnInitDialog(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
