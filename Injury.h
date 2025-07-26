#pragma once

class CInjury
{
public:
    CInjury(void);
    ~CInjury();

    CString GetName(void) const;
    COleDateTime GetStartDate(void) const;
    COleDateTime GetEndDate(void) const;
	bool IsFinished(void) const;
    CString GetDescription(void) const;
    CString GetTreatment(void) const;

    void SetName(CString str);
    void SetStartDate(COleDateTime tm);
    void SetEndDate(COleDateTime tm);
    void SetFinished(bool fFinished);
    void SetDescription(CString str);
    void SetTreatment(CString str);

protected:
    // data
    CString m_strName;
    COleDateTime m_tmStart;
    COleDateTime m_tmEnd;
	bool m_bFinished;
    CString m_strDescription;
    CString m_strTreatment;
};