#pragma once

#include "StdAfx.h"
#include "RunningLog.h"
#include "Util.h"
#include "User.h"
#include "DayLog.h"


class CVersionConverterDlg;


class CXMLConverter
{
public:

    CXMLConverter(void);
    ~CXMLConverter();

    bool ReadOldFile(CUser* pUser, CString strRead, CVersionConverterDlg* pDlg);

protected:
    CString ReadSingleLine(FILE* fp);

    bool ParseXML(CString str, int& rnVal);
    bool ParseXML(CString str, bool& rfVal);
    bool ParseXML(CString str, int& rnVal1, int& rnVal2);
    bool ParseXML(CString str, double& rdVal);
    bool ParseXML(CString str, COleDateTime& rtmVal);
    bool ParseXML(CString str, CString& rstrVal);
    bool ReadHashMap(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadUpcomingRaces(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadCourses(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadLocations(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadShoes(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadDays(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkouts(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutWeights(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutIntervals(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutHills(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutTempo(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutNormal(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutMisc(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutEZ(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutBike(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutPool(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutTreadmill(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);
    bool ReadWorkoutRace(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg);

    CString ToString(CString strName, CString strCity, CString strState, 
                     CString strNotes, double dLength, double dPRSeconds);
    CString ToString(CString strName, CString strCity, CString strState, CString strNotes);
    CString ToString(CString strName, CString strLoc, double dWeight, double dSleep, int nTemp, int nHR,
                     COleDateTime tmStart, double dSeconds, double dMiles, bool fLong, 
                     bool fInjured, double dSpecialSeconds, double dSpecialMiles, CString strNotes);
    CString ToString(CString strBrand, CString strType, double dSize, COleDateTime tmFirstDay,
                     CString strNotes);
    CString ToString(COleDateTime tmCur, CString strLineOne, CString strLineTwo);

    // data
    int* m_piRunIndex;
    int* m_piStrIndex;
    int* m_piSwimIndex;
    int* m_piBikeIndex;
    CString m_strSpaces;
    CString m_strPrepend;
};