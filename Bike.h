#pragma once

class CBike
{
public:
    CBike(void);
    ~CBike();

    CString GetBrand(void) const;
    CString GetType(void) const;
    double GetSize(void) const;
    COleDateTime GetFirstDay(void) const;
    CString GetNotes(void) const;
    bool IsRetired(void) const;

    void SetBrand(CString str);
    void SetType(CString str);
    void SetSize(double dSize);
    void SetFirstDay(COleDateTime tm);
    void SetNotes(CString str);
    void SetRetired(bool fRetired);

protected:
    
    // data
    CString m_strBrand;
    CString m_strType;
    double m_dSize;
    bool m_fRetired;
    COleDateTime m_tmFirstDay;
    CString m_strNotes;
};