#include "OptionsSheet.h"

#pragma once

class COptionsDataStrengthSheet : public COptionsSheet
{
public:
	COptionsDataStrengthSheet(CWnd* pParent = NULL);   
	virtual ~COptionsDataStrengthSheet();

    void InitDialogValues(void);
    bool WriteContents(void);

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_OPTIONSDATASTRDLG };

    bool IsFieldMandatory(int nField) const;
    void SetFieldMandatory(int nField, bool fMandatory);

    unsigned __int64 GetMandatoryFields(void) const;
    void SetMandatoryFields(unsigned __int64 i64Fields);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

	DECLARE_DYNAMIC(COptionsDataStrengthSheet)
    DECLARE_MESSAGE_MAP()

    unsigned __int64 m_i64Fields;
};
