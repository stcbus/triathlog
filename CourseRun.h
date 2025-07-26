#pragma once

class CCourse;

class CCourseRun : public CCourse
{
public:
    CCourseRun(void);
    ~CCourseRun();

    bool OptionallySetPR(double dSec);

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    double GetLength(void) const;
    CString GetNotes(void) const;
    double GetPRSeconds(void) const;

    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);
    void SetLength(double dLen);
    void SetNotes(CString str);
    void SetPRSeconds(double dPR);

    void AdjustUnits(int nOldDistUnits, int nNewDistUnits);

protected:

    CString m_strName;
    CString m_strCity;
    CString m_strState;
    double m_dLength;
    double m_dPRSeconds;
    CString m_strNotes;
};