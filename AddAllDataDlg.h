#pragma once

#include "PPToolTip.h"

class CAniDialog;
class CPPToolTip;
class CUser;

class CAddAllDataDlg : public CAniDialog
{
public:
	CAddAllDataDlg(CWnd* pParent = NULL);   
	virtual ~CAddAllDataDlg();

    virtual void OnOK(void);
    virtual BOOL OnInitDialog(void);

	enum { IDD = IDD_ADDALLTYPESDLG };

    CUser* GetUser(void) const;
    void SetUser(CUser* pUser);

    bool IsModified(void) const;
    void SetModified(bool bMod);

    virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
    void OnLocationRun(void);
    void OnLocationBike(void);
    void OnLocationSwim(void);
    void OnLocationStrength(void);
    void OnCourseRun(void);
    void OnCourseBike(void);
    void OnCourseSwim(void);
    void OnCourseDuathlon(void);
    void OnCourseTriathlon(void);
    void OnShoesRun(void);
    void OnShoesBike(void);
    void OnBike(void);

    void UpdateText(void);
    void UpdateTextItem(int nTotal, int nAdded, int nID1, int nID2);

	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CAddAllDataDlg)

    // data
    CPPToolTip m_ttpToolTip;
    CUser* m_pUser;
    bool m_bModified;

    int m_nOldLocRun;
    int m_nOldLocBike;
    int m_nOldLocSwim;
    int m_nOldLocStrength;
    int m_nOldCourseRun;
    int m_nOldCourseBike;
    int m_nOldCourseSwim;
    int m_nOldCourseDuathlon;
    int m_nOldCourseTriathlon;
    int m_nOldShoesRun;
    int m_nOldShoesBike;
    int m_nOldBikes;
};
