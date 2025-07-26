#include "StdAfx.h"
#include "RunningLog.h"
#include "RunningLogDoc.h"
#include "RunEZWorkout.h"
#include "RunNormalWorkout.h"
#include "RunHardWorkout.h"
#include "RunTempoWorkout.h"
#include "RunIntervalWorkout.h"
#include "RunHillWorkout.h"
#include "RunTreadmillWorkout.h"
#include "RunPoolWorkout.h"
#include "RunMiscWorkout.h"
#include "BikeEZWorkout.h"
#include "BikeNormalWorkout.h"
#include "BikeHardWorkout.h"
#include "BikeIntervalWorkout.h"
#include "BikeHillWorkout.h"
#include "BikeTrainerWorkout.h"
#include "BikeMiscWorkout.h"
#include "SwimEZWorkout.h"
#include "SwimNormalWorkout.h"
#include "SwimHardWorkout.h"
#include "SwimIntervalWorkout.h"
#include "SwimOpenWaterWorkout.h"
#include "SwimDrillWorkout.h"
#include "SwimMiscWorkout.h"
#include "StrengthAbsWorkout.h"
#include "StrengthWeightsWorkout.h"
#include "StrengthMiscWorkout.h"
#include "RaceRunWorkout.h"
#include "RaceBikeWorkout.h"
#include "RaceSwimWorkout.h"
#include "RaceDuathlonWorkout.h"
#include "RaceTriathlonWorkout.h"
#include "Course.h"
#include "CourseRun.h"
#include "CourseBike.h"
#include "CourseSwim.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "Location.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "UpcomingRace.h"
#include "VersionConverterDlg.h"
#include "ConvertLocationDlg.h"
#include "ConvertWorkoutBikeDlg.h"
#include "ConvertWorkoutPoolDlg.h"
#include "ConvertWorkoutWeightsDlg.h"
#include "XMLConverter.h"


CXMLConverter::CXMLConverter(void)
{
    m_strPrepend = "Currently reading from file: ";
    m_strSpaces = "    ";
    m_piRunIndex = NULL;
    m_piStrIndex = NULL;    
    m_piBikeIndex = NULL;
    m_piSwimIndex = NULL;
}


CXMLConverter::~CXMLConverter()
{
    if(m_piRunIndex)
    {
        delete[] m_piRunIndex;
        m_piRunIndex = NULL;
    }
    if(m_piStrIndex)
    {
        delete[] m_piStrIndex;
        m_piStrIndex = NULL;
    }    
    if(m_piBikeIndex)
    {
        delete[] m_piBikeIndex;
        m_piBikeIndex = NULL;
    }    
    if(m_piSwimIndex)
    {
        delete[] m_piSwimIndex;
        m_piSwimIndex = NULL;
    }
}


bool CXMLConverter::ReadOldFile(CUser* pUser, CString strRead, CVersionConverterDlg* pDlg)
{
    if((NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadOldFile");
        return false;
    }

    FILE* fp = fopen(strRead, "r+");
    if(NULL == fp)
    {
        return false;
    }

    bool fRes = true;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nCur2 = 0;
    CString strCur;
    COleDateTime tmCur;

    // skip the <xml version .../> stuff
    ReadSingleLine(fp);

    pDlg->CreateProgress(m_strPrepend + "general information" + m_strSpaces, 25);

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dCur1);
    if(2.0 == dCur1)
    {
        // skip over <User>
        ReadSingleLine(fp);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetFirstName(strCur);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetLastName(strCur);
  
        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetSex(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHeight(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBaseTypeRun(nCur1);
        pUser->SetBaseTypeBike(nCur1);
        pUser->SetBaseTypeSwim(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetFirstDayOfWeek(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetRestingHR(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        pUser->SetNotes(strCur);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHighlightDay(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, tmCur);
        pUser->SetCurrentDate(tmCur);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_NORMAL, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_GRAYED, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_WEEKSUM, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayColor(DAYTYPE_MONTHSUM, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHighlightColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetBgColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetButtonColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetHeadingTextColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetDayTextColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetAnnotationTextColor(nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetGradientColor(true, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetGradientColor(false, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetShadowColor(true, nCur1);

        pDlg->StepProgress();

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);
        pUser->SetShadowColor(false, nCur1);

        pDlg->StepProgress();
        pDlg->DestroyProgress();

        fRes &= ReadHashMap(pUser, fp, pDlg);
        fRes &= ReadCourses(pUser, fp, pDlg);
        fRes &= ReadLocations(pUser, fp, pDlg);
        fRes &= ReadShoes(pUser, fp, pDlg);
        fRes &= ReadDays(pUser, fp, pDlg);
        fRes &= ReadUpcomingRaces(pUser, fp, pDlg);
    }
    else
    {
        fRes = false;
    }

    pDlg->SetNotes("");
    
    fclose(fp);
    return fRes;
}


CString CXMLConverter::ReadSingleLine(FILE* fp)
{
    if(NULL == fp)
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadSingleLine");
        return NULL;
    }

    CString strRet;
    
    char ch = fgetc(fp);
    while(0 == feof(fp))
    {
        strRet += ch;

        if('>' == ch)
        {
            break;
        }

        ch = fgetc(fp);
    }

    return strRet;
}


bool CXMLConverter::ParseXML(CString str, int& rnVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rnVal = atoi(str);
    return true;
}


bool CXMLConverter::ParseXML(CString str, bool& rfVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    int nVal = atoi(str);
    if(nVal == 1)
    {
        rfVal = true;
    }
    else
    {
        rfVal = false;
    }
    return true;
}


bool CXMLConverter::ParseXML(CString str, int& rnVal1, int& rnVal2)
{
    int n = -1;
    CString astrVals[2];

    for(int i = 0; i < 2; i++)
    {
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');

        astrVals[i] = str.Left(n);
    }

    rnVal1 = atoi(astrVals[0]);
    rnVal2 = atoi(astrVals[1]);

    return true;
}


bool CXMLConverter::ParseXML(CString str, double& rdVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rdVal = atof(str);
    return true;
}


bool CXMLConverter::ParseXML(CString str, COleDateTime& rtmVal)
{
    int n = -1;
    CString astrVals[6];

    for(int i = 0; i < 6; i++)
    {
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');
        str = str.Right(str.GetLength() - n - 1);
        n = str.Find('"');

        astrVals[i] = str.Left(n);
    }

    int nYear = atoi(astrVals[0]);
    int nMonth = atoi(astrVals[1]);
    int nDay = atoi(astrVals[2]);
    int nHour = atoi(astrVals[3]);
    int nMinute = atoi(astrVals[4]);
    int nSecond = atoi(astrVals[5]);

    rtmVal = COleDateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
    return true;
}


bool CXMLConverter::ParseXML(CString str, CString& rstrVal)
{
    int n = str.Find('"');
    str = str.Right(str.GetLength() - n - 1);
    
    n = str.Find('"');
    str = str.Left(n);

    rstrVal = str;
    return true;
}


bool CXMLConverter::ReadHashMap(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadHashMap");
        return NULL;
    }

    bool fRes = true;
    int nCur1 = 0;
    int nCur2 = 0;
    int nNum = 0;
    CMap<int, int, int, int> mapHash;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);

    pDlg->CreateProgress(m_strPrepend + "hash table" + m_strSpaces, max(1, nNum));
    
    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1, nCur2);
        mapHash[nCur1] = nCur2;
        pDlg->StepProgress();
    }
    pUser->SetHashMap(mapHash);

    pDlg->DestroyProgress();
    
    ReadSingleLine(fp);

    return fRes;
}


bool CXMLConverter::ReadCourses(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadCourses");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    CString strName;
    CString strCity;
    CString strState;
    CString strNotes;
    double dLength;
    double dPRSeconds;

    pDlg->CreateProgress(m_strPrepend + "courses" + m_strSpaces, max(1, nNum));

    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strName = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, dCur1);
        dLength = dCur1;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, dCur1);
        dPRSeconds = dCur1;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strCity = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strState = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strNotes = strCur;

        ReadSingleLine(fp);

        pDlg->SetNotes(ToString(strName, strCity, strState, strNotes, dLength, dPRSeconds));

        CCourseRun* pCourse = new CCourseRun;
        if(NULL != pCourse)
        {
            pCourse->SetName(strName);
            pCourse->SetLength(dLength);
            pCourse->SetPRSeconds(dPRSeconds);
            pCourse->SetCity(strCity);
            pCourse->SetState(strState);
            pCourse->SetNotes(strNotes);

            pUser->AddCourseRun(pCourse);
        }

        pDlg->StepProgress();
    }

    pDlg->DestroyProgress();

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLConverter::ReadLocations(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadLocations");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);

    m_piRunIndex = new int[nNum];
    m_piStrIndex = new int[nNum];
    m_piSwimIndex = new int[nNum];
    m_piBikeIndex = new int[nNum];
    int nTotalStrength = 0;
    int nTotalRunning = 0;
    int nTotalSwimming = 0;
    int nTotalBiking = 0;

    if((NULL == m_piRunIndex) || (NULL == m_piStrIndex) || (NULL == m_piBikeIndex) || (NULL == m_piSwimIndex))
    {
        CUtil::Fatal("Could not complete reading locations -- no memory available.");
        return false;
    }

    CString strName;
    CString strCity;
    CString strState;
    CString strNotes;

    pDlg->CreateProgress(m_strPrepend + "locations" + m_strSpaces, max(1, nNum));

    for(int i = 0; i < nNum; i++)
    {
        m_piRunIndex[i] = 0;
        m_piStrIndex[i] = 0;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strName = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strCity = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strState = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strNotes = strCur;

        ReadSingleLine(fp);

        CString strStr = ToString(strName, strCity, strState, strNotes);
        pDlg->SetNotes(strStr);

        CConvertLocationDlg dlg;
        dlg.SetNotes(strStr);
        dlg.DoModal();
        if(dlg.IsRunLocation())
        {
            CLocationRun* pLocation = new CLocationRun;
            if(NULL != pLocation)
            {
                pLocation->SetName(strName);
                pLocation->SetCity(strCity);
                pLocation->SetState(strState);
                pLocation->SetNotes(strNotes);

                pUser->AddLocationRun(pLocation);
                m_piRunIndex[i] = nTotalRunning;
                nTotalRunning++;
            }
        }
        
        if(dlg.IsBikeLocation())
        {
            CLocationBike* pLocation = new CLocationBike;
            if(NULL != pLocation)
            {
                pLocation->SetName(strName);
                pLocation->SetCity(strCity);
                pLocation->SetState(strState);
                pLocation->SetNotes(strNotes);

                pUser->AddLocationBike(pLocation);
                m_piBikeIndex[i] = nTotalBiking;
                nTotalBiking++;
            }
        }
        
        if(dlg.IsSwimLocation())
        {
            CLocationSwim* pLocation = new CLocationSwim;
            if(NULL != pLocation)
            {
                pLocation->SetName(strName);
                pLocation->SetCity(strCity);
                pLocation->SetState(strState);
                pLocation->SetNotes(strNotes);

                pUser->AddLocationSwim(pLocation);
                m_piSwimIndex[i] = nTotalSwimming;
                nTotalSwimming++;
            }
        }
        
        if(dlg.IsStrengthLocation())
        {
            CLocationStrength* pLocation = new CLocationStrength;
            if(NULL != pLocation)
            {
                pLocation->SetName(strName);
                pLocation->SetCity(strCity);
                pLocation->SetState(strState);
                pLocation->SetNotes(strNotes);

                pUser->AddLocationStrength(pLocation);
                m_piStrIndex[i] = nTotalStrength;
                nTotalStrength++;
            }
        }

        pDlg->StepProgress();
    }

    pDlg->DestroyProgress();

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLConverter::ReadShoes(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadShoes");
        return NULL;
    }

    bool fRes = true;
    CString strCur;
    double dCur1 = 0.0;
    int nCur1 = 0;
    COleDateTime tmCur;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    pDlg->CreateProgress(m_strPrepend + "shoes" + m_strSpaces, max(1, nNum));

    CString strBrand;
    CString strType;
    double dSize;
    COleDateTime tmFirstDay;
    CString strNotes;

    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur1);

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strBrand = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strType = strCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, dCur1);
        dSize = dCur1;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, tmCur);
        tmFirstDay = tmCur;

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strNotes = strCur;

        ReadSingleLine(fp);
            
        pDlg->SetNotes(ToString(strBrand, strType, dSize, tmFirstDay, strNotes));

        CShoesRun* pShoes = new CShoesRun;
        if(NULL != pShoes)
        {
            pShoes->SetBrand(strBrand);
            pShoes->SetType(strType);
            pShoes->SetSize(dSize);
            pShoes->SetFirstDay(tmFirstDay);
            pShoes->SetNotes(strNotes);

            pUser->AddShoesRun(pShoes);
        }

        pDlg->StepProgress();
    }

    pDlg->DestroyProgress();

    ReadSingleLine(fp);
    
    return fRes;
}


bool CXMLConverter::ReadUpcomingRaces(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadUpcomingRaces");
        return NULL;
    }

    bool fRes = true;
    COleDateTime tmCur;
    int nNum = 0;
    CString strCur;

    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);

    pDlg->CreateProgress(m_strPrepend + "upcoming races" + m_strSpaces, max(1, nNum));

    COleDateTime tmDate;
    CString strLineOne;
    CString strLineTwo;
    
    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);

        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, tmCur);
        tmDate = tmCur;
        
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strLineOne = strCur;
        
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, strCur);
        strLineTwo = strCur;

        ReadSingleLine(fp);
            
        pDlg->SetNotes(ToString(tmCur, strLineOne, strLineTwo));

        CUpcomingRace* pRace = new CUpcomingRace;
        if(NULL != pRace)
        {
            pRace->SetDate(tmCur);
            pRace->SetLineOne(strLineOne);
            pRace->SetLineTwo(strLineTwo);

            // only add the race if it is in not in the past
            if(!CUtil::IsLaterDayThan(COleDateTime::GetCurrentTime(), pRace->GetDate()))
            {
                pUser->AddUpcomingRace(pRace);
            }

            pDlg->StepProgress();
        }
    }

    pDlg->DestroyProgress();

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLConverter::ReadDays(CUser* pUser, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadDays");
        return NULL;
    }

    bool fRes = true;
    COleDateTime tmCur;
    int nCur1 = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);

    pDlg->CreateProgress(m_strPrepend + "days" + m_strSpaces, max(1, nNum));
    
    for(int i = 0; i < nNum; i++)
    {
        CDayLog* pDay = new CDayLog;
        if(NULL != pDay)
        {
            strLine = ReadSingleLine(fp);

            strLine = ReadSingleLine(fp);
            fRes &= ParseXML(strLine, tmCur);
            pDay->SetDate(tmCur);
            
            fRes &= ReadWorkouts(pUser, pDay, fp, pDlg);

            ReadSingleLine(fp);

            pUser->SetDayAt(tmCur, pDay);
        }

        pDlg->StepProgress();
    }

    pDlg->DestroyProgress();

    ReadSingleLine(fp);

    return fRes;
}


bool CXMLConverter::ReadWorkouts(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        CUtil::Fatal("Bad parameter to CXMLConverter::ReadWorkouts");
        return NULL;
    }

    bool fRes = true;
    int nCur = 0;
    int nNum = 0;
    CString strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNum);
    
    for(int i = 0; i < nNum; i++)
    {
        strLine = ReadSingleLine(fp);
        fRes &= ParseXML(strLine, nCur);

        switch(nCur)
        {
        case TYPE_WEIGHTS:
            {
                fRes &= ReadWorkoutWeights(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_POOL:
            {
                fRes &= ReadWorkoutPool(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_BIKE:
            {
                fRes &= ReadWorkoutBike(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_EZ:
            {
                fRes &= ReadWorkoutEZ(pUser, pDay, fp, pDlg);
                break;
         }

        case TYPE_NORMAL:
            {
                fRes &= ReadWorkoutNormal(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_TEMPO:
            {
                fRes &= ReadWorkoutTempo(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_INTERVALS:
            {
                fRes &= ReadWorkoutIntervals(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_HILLS:
            {
                fRes &= ReadWorkoutHills(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_RACE:
            {
                fRes &= ReadWorkoutRace(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_TREADMILL:
            {
                fRes &= ReadWorkoutTreadmill(pUser, pDay, fp, pDlg);
                break;
            }

        case TYPE_OTHER:
            {
                fRes &= ReadWorkoutMisc(pUser, pDay, fp, pDlg);
                break;
            }

        default:
            {
                fRes = false;
                break;
            }
        }

        ReadSingleLine(fp);
    }

    ReadSingleLine(fp);

    return fRes;
}
         

bool CXMLConverter::ReadWorkoutWeights(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Strength";
    CLocationStrength* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationStrengthArray().ElementAt(m_piStrIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    CString strStr = ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes);
    pDlg->SetNotes(strStr);

    CConvertWorkoutWeightsDlg dlg;
    dlg.SetNotes(strStr);
    dlg.DoModal();
    switch(dlg.GetResult())
    {
    case IDC_STRENGTHABS:
        {
            CStrengthAbsWorkout* pWorkout = new CStrengthAbsWorkout;
            if(NULL != pWorkout)
            {
                pWorkout->SetDisplayName(CUtil::StrengthWorkoutToString(STRENGTHTYPE_ABS));
                pWorkout->SetLocationStrength(pLocation);
                pWorkout->SetWeight(dWeight);
                pWorkout->SetPrevNightSleep(dPrevSleep);
                pWorkout->SetTemperature(nTemp);
                pWorkout->SetHR(nHR);
                pWorkout->SetTimeStart(tmStart);
                pWorkout->SetSeconds(dSeconds);
                pWorkout->SetLong(fLong);
                pWorkout->SetInjured(fInjured);
                pWorkout->SetNotes(strNotes);

                pDay->AddWorkout(pWorkout);
            }

            break;
        }

    case IDC_STRENGTHOTHER:
        {
            CStrengthMiscWorkout* pWorkout = new CStrengthMiscWorkout;
            if(NULL != pWorkout)
            {
                pWorkout->SetDisplayName(CUtil::StrengthWorkoutToString(STRENGTHTYPE_OTHER));
                pWorkout->SetLocationStrength(pLocation);
                pWorkout->SetWeight(dWeight);
                pWorkout->SetPrevNightSleep(dPrevSleep);
                pWorkout->SetTemperature(nTemp);
                pWorkout->SetHR(nHR);
                pWorkout->SetTimeStart(tmStart);
                pWorkout->SetSeconds(dSeconds);
                pWorkout->SetLong(fLong);
                pWorkout->SetInjured(fInjured);
                pWorkout->SetNotes(strNotes);

                pDay->AddWorkout(pWorkout);
            }

            break;
        }

    case IDC_STRENGTHWEIGHTS:
        {
            CStrengthWeightsWorkout* pWorkout = new CStrengthWeightsWorkout;
            if(NULL != pWorkout)
            {
                pWorkout->SetDisplayName(CUtil::StrengthWorkoutToString(STRENGTHTYPE_WEIGHTS));
                pWorkout->SetLocationStrength(pLocation);
                pWorkout->SetWeight(dWeight);
                pWorkout->SetPrevNightSleep(dPrevSleep);
                pWorkout->SetTemperature(nTemp);
                pWorkout->SetHR(nHR);
                pWorkout->SetTimeStart(tmStart);
                pWorkout->SetSeconds(dSeconds);
                pWorkout->SetLong(fLong);
                pWorkout->SetInjured(fInjured);
                pWorkout->SetNotes(strNotes);

                pDay->AddWorkout(pWorkout);
            }

            break;
        }

    default:
        {
            CUtil::Fatal("Bad return value in CXMLConverter::ReadWeightsWorkout");
            return false;
        }
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutIntervals(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Intervals";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pSpecialShoes = pUser->GetShoesRunFromID(nCur);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunIntervalWorkout* pWorkout = new CRunIntervalWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_INTERVALS));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);
        pWorkout->SetSpecialMiles(dSpecialMiles);
        pWorkout->SetSpecialSeconds(dSpecialSeconds);
        pWorkout->SetSpecialShoesRun(pSpecialShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutHills(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Hills";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialSeconds);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunHillWorkout* pWorkout = new CRunHillWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_HILLS));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);
        pWorkout->SetSpecialMiles(dSpecialMiles);
        pWorkout->SetSpecialSeconds(dSpecialSeconds);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutTempo(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Tempo";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialSeconds);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunTempoWorkout* pWorkout = new CRunTempoWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_TEMPO));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);
        pWorkout->SetSpecialMiles(dSpecialMiles);
        pWorkout->SetSpecialSeconds(dSpecialSeconds);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutEZ(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Easy";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunEZWorkout* pWorkout = new CRunEZWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_EZ));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutMisc(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;
    int nCur = 0;

    CString strLine;

    CString strName = "Other";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunMiscWorkout* pWorkout = new CRunMiscWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_OTHER));
        pWorkout->SetCountedOnShoes(true);
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutNormal(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;

    CString strLine;
    int nCur;

    CString strName = "Normal";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunNormalWorkout* pWorkout = new CRunNormalWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_NORMAL));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutBike(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;

    CString strLine;
    int nCur;

    CString strName = "Bike";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    pShoes = pUser->GetShoesRunFromID(0);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunMiscWorkout* pWorkout = new CRunMiscWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_OTHER));
        pWorkout->SetCountedOnShoes(false);
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutPool(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;

    CString strLine;
    int nCur;

    CString strName = "Pool";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunPoolWorkout* pWorkout = new CRunPoolWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_POOL));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutTreadmill(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;

    CString strLine;
    int nCur;

    CString strName = "Treadmill";
    CLocationRun* pLocation = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pLocation = pUser->GetRefLocationRunArray().ElementAt(m_piRunIndex[nCur]);
    if(NULL != pLocation)
    {
        strLoc = pLocation->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRunTreadmillWorkout* pWorkout = new CRunTreadmillWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RunWorkoutToString(RUNTYPE_TREADMILL));
        pWorkout->SetLocationRun(pLocation);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetShoesRun(pShoes);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


bool CXMLConverter::ReadWorkoutRace(CUser* pUser, CDayLog* pDay, FILE* fp, CVersionConverterDlg* pDlg)
{
    if((NULL == fp) || (NULL == pDay) || (NULL == pUser) || (NULL == pDlg))
    {
        return false;
    }

    bool fRes = true;

    CString strLine;
    int nCur;

    CString strName = "Race";
    CCourseRun* pCourse = NULL;
    CString strLoc = "";
    double dWeight = 0.0;
    double dPrevSleep = 0.0;
    int nTemp = 0;
    int nHR = 0;
    COleDateTime tmStart;
    double dSeconds = 0.0;
    double dMiles = 0.0;
    bool fLong = false;
    bool fInjured = false;
    double dSpecialSeconds = 0.0;
    double dSpecialMiles = 0.0;
    CString strNotes;

    int nWind = 0;
    CShoesRun* pShoes = NULL;
    CShoesRun* pSpecialShoes = NULL;

    int nNumber = 0;
    int nPosition = 0;

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dWeight);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, tmStart);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dPrevSleep);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pCourse = pUser->GetRefCourseRunArray().ElementAt(nCur);
    if(NULL != pCourse)
    {
        strLoc = pCourse->GetName();
    }

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nTemp);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nHR);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fLong);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, fInjured);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, strNotes);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dMiles);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nWind);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pShoes = pUser->GetShoesRunFromID(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, dSpecialSeconds);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nCur);
    pSpecialShoes = pUser->GetShoesRunFromID(nCur);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nNumber);

    strLine = ReadSingleLine(fp);
    fRes &= ParseXML(strLine, nPosition);

    pDlg->SetNotes(ToString(strName, strLoc, dWeight, dPrevSleep, nTemp, nHR, tmStart, dSeconds, 
                            dMiles, fLong, fInjured, dSpecialSeconds, dSpecialMiles, strNotes));


    CRaceRunWorkout* pWorkout = new CRaceRunWorkout;
    if(NULL != pWorkout)
    {
        pWorkout->SetDisplayName(CUtil::RaceToString(RACETYPE_RUN));
        pWorkout->SetCourseRun(pCourse);
        pWorkout->SetWeight(dWeight);
        pWorkout->SetPrevNightSleep(dPrevSleep);
        pWorkout->SetTemperature(nTemp);
        pWorkout->SetHR(nHR);
        pWorkout->SetTimeStart(tmStart);
        pWorkout->SetSeconds(dSeconds);
        pWorkout->SetLong(fLong);
        pWorkout->SetInjured(fInjured);
        pWorkout->SetNotes(strNotes);
        pWorkout->SetMiles(dMiles);
        pWorkout->SetWind(nWind);
        pWorkout->SetShoesRun(pShoes);
        pWorkout->SetSpecialSeconds(dSpecialSeconds);
        pWorkout->SetSpecialShoesRun(pSpecialShoes);
        pWorkout->SetRaceNumber(nNumber);
        pWorkout->SetRacePosition(nPosition);

        pDay->AddWorkout(pWorkout);
    }

    return fRes;
}


CString CXMLConverter::ToString(COleDateTime tmCur, CString strLineOne, CString strLineTwo)
{
    CString str;
    CString strTemp;

    str = "Upcoming race";
    str += "\r\n";
    strTemp.Format("Date: %d/%d/%d", tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetYear());
    str = strTemp;
    str += "\r\n";
    str += "Line One: " + strLineOne;
    str += "\r\n";
    str += "Line Two: " + strLineTwo;

    return str;
}


CString CXMLConverter::ToString(CString strBrand, CString strType, double dSize,
                                COleDateTime tmFirstDay, CString strNotes)
{
    CString str;
    CString strTemp;

    str = "Shoes";
    str += "\r\n";
    str += "Brand: " + strBrand;
    str += "\r\n";
    str = "Type: " + strType;
    str += "\r\n";
    strTemp.Format("Size: %.1lf", dSize);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Date: %d/%d/%d", tmFirstDay.GetMonth(), tmFirstDay.GetDay(), tmFirstDay.GetYear());
    str += strTemp;
    str += "\r\n";
    str += "Notes: " + strNotes;

    return str;
}


CString CXMLConverter::ToString(CString strName, CString strLoc, double dWeight, double dSleep,
                                int nTemp, int nHR, COleDateTime tmStart, double dSeconds,
                                double dMiles, bool fLong, bool fInjured, double dSpecialSeconds,
                                double dSpecialMiles, CString strNotes)
{
    CString str;
    CString strTemp;

    str = "Workout";
    str += "\r\n";
    str += "Name: " + strName;
    str += "\r\n";
    str += "Location/Course: " + strLoc;
    str += "\r\n";
    strTemp.Format("Weight: %.1lf", dWeight);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Previous night's sleep: %.1lf", dSleep);
    str += strTemp;
    str += "\r\n";
     strTemp.Format("Temperature: %d", nTemp);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Heartrate: %d", nHR);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Date: %d/%d/%d", tmStart.GetMonth(), tmStart.GetDay(), tmStart.GetYear());
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Minutes: %.1lf", dSeconds / 60.0);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Miles: %.1lf", dMiles);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Long: %s", fLong ? "yes" : "no");
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Injured: %s", fInjured ? "yes" : "no");
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Special Minutes: %.1lf", dSpecialSeconds / 60.0);
    str += strTemp;
    str += "\r\n";
    strTemp.Format("Special Miles: %.1lf", dSpecialMiles);
    str += strTemp;
    str += "\r\n";
    str += "Notes: " + strNotes;

    return str;
}


CString CXMLConverter::ToString(CString strName, CString strCity, CString strState, CString strNotes)
{
    CString str;

    str = "Location";
    str += "\r\n";
    str += "Name: " + strName;
    str += "\r\n";
    str += "City: " + strCity;
    str += "\r\n";
    str += "State: " + strState;
    str += "\r\n";
    str += "Notes: " + strNotes;

    return str;
}


CString CXMLConverter::ToString(CString strName, CString strCity, CString strState, CString strNotes,
                                double dLength, double dPRSeconds)
{
    CString str;
    CString strTemp;

    str = "Course";
    str += "\r\n";
    str += "Name: " + strName;
    str += "\r\n";
    strTemp.Format("Length: %.1lf", dLength);
    str += strTemp;
    str += "\r\n";
	if(CUtil::HasData(dPRSeconds) && (dPRSeconds > 0))
    {
        strTemp.Format("PR (mins): %.1lf", dPRSeconds / 60.0);
    }
    else
    {
        strTemp = "PR (mins): none";
    }
    str += strTemp;
    str += "\r\n";
    str += "City: " + strCity;
    str += "\r\n";
    str += "State: " + strState;
    str += "\r\n";
    str += "Notes: " + strNotes;

    return str;
}