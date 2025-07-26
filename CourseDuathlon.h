#pragma once

class CCourse;

class CCourseDuathlon : public CCourse
{
public:
    CCourseDuathlon(void);
    ~CCourseDuathlon();

    bool OptionallySetPR(double dSec);
    bool OptionallySetLeg1PR(double dSec);
    bool OptionallySetLeg2PR(double dSec);
    bool OptionallySetLeg3PR(double dSec);
    bool OptionallySetTransition1PR(double dSec);
    bool OptionallySetTransition2PR(double dSec);

    CString GetName(void) const;
    CString GetCity(void) const;
    CString GetState(void) const;
    CString GetNotes(void) const;
    double GetPRSeconds(void) const;
    double GetLeg1PRSeconds(void) const;
    double GetLeg2PRSeconds(void) const;
    double GetLeg3PRSeconds(void) const;
    double GetTransition1PRSeconds(void) const;
    double GetTransition2PRSeconds(void) const;
    double GetLeg1Length(void) const;
    double GetLeg2Length(void) const;
    double GetLeg3Length(void) const;
    CString GetLeg1Notes(void) const;
    CString GetLeg2Notes(void) const;
    CString GetLeg3Notes(void) const;

    void SetName(CString str);
    void SetCity(CString str);
    void SetState(CString str);
    void SetNotes(CString str);
    void SetPRSeconds(double dPR);
    void SetLeg1PRSeconds(double dPR);
    void SetLeg2PRSeconds(double dPR);
    void SetLeg3PRSeconds(double dPR);
    void SetTransition1PRSeconds(double dPR);
    void SetTransition2PRSeconds(double dPR);
    void SetLeg1Length(double dLen);
    void SetLeg2Length(double dLen);
    void SetLeg3Length(double dLen);
    void SetLeg1Notes(CString str);
    void SetLeg2Notes(CString str);
    void SetLeg3Notes(CString str);

    void AdjustUnits(int nOldDistRunUnits, int nOldDistBikeUnits, int nNewDistRunUnits, int nNewDistBikeUnits);

protected:
    // data
    CString m_strName;
    CString m_strCity;
    CString m_strState;
    double m_dPRSeconds;
    CString m_strNotes;
    double m_dLeg1Length;
    double m_dLeg2Length;
    double m_dLeg3Length;
    double m_dLeg1PRSeconds;
    double m_dLeg2PRSeconds;
    double m_dLeg3PRSeconds;
    double m_dTransition1PRSeconds;
    double m_dTransition2PRSeconds;
    CString m_strLeg1Notes;
    CString m_strLeg2Notes;
    CString m_strLeg3Notes;
};