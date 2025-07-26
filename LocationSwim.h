#pragma once

class CLocation;

class CLocationSwim : public CLocation
{
public:
    CLocationSwim(void);
    ~CLocationSwim();

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    CString GetNotes(void) const;

    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);
    void SetNotes(CString str);

protected:

    CString m_strName;
    CString m_strCity;
    CString m_strState;
    CString m_strNotes;
};