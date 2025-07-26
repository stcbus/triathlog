#pragma once

class COptionsDlg;
class CUser;

class COptionsSheet : public CPropertyPage
{
public:
    COptionsSheet(int nID, CWnd* pParent = NULL);

    COptionsDlg* GetParentDlg(void) const;
    CUser* GetUser(void) const;

    void SetParentDlg(COptionsDlg* pDlg);
    void SetUser(CUser* pUser);

    virtual void OnOK(void);
    virtual BOOL OnApply(void);

    void NotifyParentChanged(void);
    void NotifyParentUnitsChanged(void);

    virtual void InitDialogValues(void) = 0;
    virtual bool WriteContents(void) = 0;

    DECLARE_DYNAMIC(COptionsSheet);
    DECLARE_MESSAGE_MAP()
    
protected:
    COptionsDlg* m_pParentDlg;
    CUser* m_pUser;
};