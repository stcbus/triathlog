#include "OptionsSheet.h"

#pragma once


class COptionsUnitsSheet : public COptionsSheet
{
public:
	COptionsUnitsSheet(CWnd* pParent = NULL);   
	virtual ~COptionsUnitsSheet();

    virtual void InitDialogValues(void);
    virtual bool WriteContents(void);

    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_OPTIONSUNITDLG };

    int GetRunDistUnits(void) const;
    int GetBikeDistUnits(void) const;
    int GetSwimDistUnits(void) const;
    int GetHeightUnits(void) const;
    int GetWeightUnits(void) const;
    int GetTempUnits(void) const;

    void SetRunDistUnits(int nUnits);
    void SetBikeDistUnits(int nUnits);
    void SetSwimDistUnits(int nUnits);
    void SetHeightUnits(int nUnits);
    void SetWeightUnits(int nUnits);
    void SetTempUnits(int nUnits);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(COptionsUnitsSheet)

    int m_nRunDistUnits;
    int m_nBikeDistUnits;
    int m_nSwimDistUnits;
    int m_nHeightUnits;
    int m_nWeightUnits;
    int m_nTempUnits;
};
