#include "StdAfx.h"
#include "RunningLog.h"
#include "User.h"
#include "Util.h"
#include "RunningLogDoc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CUser* g_pUser;


IMPLEMENT_DYNCREATE(CRunningLogDoc, CDocument)


BEGIN_MESSAGE_MAP(CRunningLogDoc, CDocument)
END_MESSAGE_MAP()


CRunningLogDoc::CRunningLogDoc()
{
    SetUser(NULL);

    CUser* pUser = new CUser;
    SetUser(pUser);
}


CRunningLogDoc::~CRunningLogDoc()
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        delete pUser;
        pUser = NULL;
    }
}


CUser* CRunningLogDoc::GetUser(void) const
{
    return g_pUser;
}


void CRunningLogDoc::SetUser(CUser* pUser)
{
    CUser* pCur = GetUser();
    if((NULL != pCur) && (pCur != pUser))
    {
        delete pCur;
        pCur = NULL;
    }

    g_pUser = pUser;
}


CString CRunningLogDoc::GetFirstName(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetFirstName");
        return NULL;
    }

    return pUser->GetFirstName();
}


CString CRunningLogDoc::GetLastName(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetLastName");
        return NULL;
    }
        
    return pUser->GetLastName();
}


int CRunningLogDoc::GetSex(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetFirstName");
        return SEX_MALE;
    }
        
    return pUser->GetSex();
}


int CRunningLogDoc::GetHeight(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetHeight");
        return 0;
    }
    
    return pUser->GetHeight();
}


int CRunningLogDoc::GetRestingHR(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetRestingHR");
        return 0;
    }

    return pUser->GetRestingHR();
}


int CRunningLogDoc::GetBaseTypeRun(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetBaseTypeRun");
        return CUtil::GetDefaultBaseTypeRun();
    }
        
    return pUser->GetBaseTypeRun();
}


int CRunningLogDoc::GetBaseTypeBike(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetBaseTypeBike");
        return CUtil::GetDefaultBaseTypeBike();
    }
        
    return pUser->GetBaseTypeBike();
}


int CRunningLogDoc::GetBaseTypeSwim(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetBaseTypeSwim");
        return CUtil::GetDefaultBaseTypeSwim();
    }
        
    return pUser->GetBaseTypeSwim();
}


int CRunningLogDoc::GetFirstDayOfWeek(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetFirstDayOfWeek");
        return MONDAY;
    }

    return pUser->GetFirstDayOfWeek();
}


bool CRunningLogDoc::DisplayInfoRun(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::DisplayInfoRun");
        return true;
    }
        
    return pUser->DisplayInfoRun();
}


bool CRunningLogDoc::DisplayInfoBike(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::DisplayInfoBike");
        return true;
    }
        
    return pUser->DisplayInfoBike();
}


bool CRunningLogDoc::DisplayInfoSwim(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::DisplayInfoSwim");
        return true;
    }
        
    return pUser->DisplayInfoSwim();
}


bool CRunningLogDoc::DisplayInfoStrength(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::DisplayInfoStrength");
        return true;
    }
        
    return pUser->DisplayInfoStrength();
}


bool CRunningLogDoc::DisplayInfoRace(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::DisplayInfoRace");
        return true;
    }
        
    return pUser->DisplayInfoRace();
}


COleDateTime CRunningLogDoc::GetCurrentDate(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetCurrentDate");
        return COleDateTime::GetCurrentTime();
    }
        
    return pUser->GetCurrentDate();
}


int CRunningLogDoc::GetHighlightDay(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetHighlightDay");
        return 0;
    }

    return pUser->GetHighlightDay();
}


COLORREF CRunningLogDoc::GetBgColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetBgColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetBgColor();
}


COLORREF CRunningLogDoc::GetDayColor(int nType) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetDayColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetDayColor(nType);
}


COLORREF CRunningLogDoc::GetButtonColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetButtonColor");
        return RGB(0, 0, 0);
    }
   
    return pUser->GetButtonColor();
}


COLORREF CRunningLogDoc::GetHighlightColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetHighlightColor");
        return RGB(0, 0, 0);
    }
        
    return pUser->GetHighlightColor();
}


COLORREF CRunningLogDoc::GetShadowColor(bool bOne) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetShadowColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetShadowColor(bOne);
}


COLORREF CRunningLogDoc::GetGradientColor(bool bBegin) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetGradientColor");
        return RGB(0, 0, 0);
    }
        
    return pUser->GetGradientColor(bBegin);
}


COLORREF CRunningLogDoc::GetHeadingTextColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetHeadingTextColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetHeadingTextColor();
}


COLORREF CRunningLogDoc::GetDayTextColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetDayTextColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetDayTextColor();
}


COLORREF CRunningLogDoc::GetAnnotationTextColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetAnnotationTextColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetAnnotationTextColor();
}


COLORREF CRunningLogDoc::GetRaceDayColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetRaceDayColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetRaceDayColor();
}


COLORREF CRunningLogDoc::GetUpcomingRaceDayColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetUpcomingRaceDayColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetUpcomingRaceDayColor();
}


COLORREF CRunningLogDoc::GetUpcomingWorkoutDayColor(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetUpcomingWorkoutDayColor");
        return RGB(0, 0, 0);
    }

    return pUser->GetUpcomingWorkoutDayColor();
}


CFont* CRunningLogDoc::GetDayFont(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetDayFont");
        return NULL;
    }

    return pUser->GetDayFont();
}


CFont* CRunningLogDoc::GetHeadingFont(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetHeadingFont");
        return NULL;
    }

    return pUser->GetHeadingFont();
}


CFont* CRunningLogDoc::GetTitleFont(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetTitleFont");
        return NULL;
    }

    return pUser->GetTitleFont();
}


CFont* CRunningLogDoc::GetAnnotationFont(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetAnnotationFont");
        return NULL;
    }

    return pUser->GetAnnotationFont();
}


CFont* CRunningLogDoc::GetAnnotationFontBold(void) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetAnnotationFontBold");
        return NULL;
    }

    return pUser->GetAnnotationFontBold();
}


CDayLog* CRunningLogDoc::GetDayAt(COleDateTime tmDay) const
{
    CUser* pUser = GetUser();
    if(NULL == pUser)
    {
        CUtil::Fatal("NULL user in CRunningLogDoc::GetDayAt");
        return NULL;
    }

    return pUser->GetDayAt(tmDay);
}

void CRunningLogDoc::SetFirstName(CString str)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetFirstName(str);
    }
}


void CRunningLogDoc::SetLastName(CString str)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetLastName(str);
    }
}


void CRunningLogDoc::SetSex(int nSex)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetSex(nSex);
    }
}


void CRunningLogDoc::SetHeight(int nHeight)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetHeight(nHeight);
    }
}


void CRunningLogDoc::SetRestingHR(int nHR)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetRestingHR(nHR);
    }
}


void CRunningLogDoc::SetBaseTypeRun(int nType)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetBaseTypeRun(nType);
    }
}


void CRunningLogDoc::SetBaseTypeBike(int nType)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetBaseTypeBike(nType);
    }
}


void CRunningLogDoc::SetBaseTypeSwim(int nType)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetBaseTypeSwim(nType);
    }
}


void CRunningLogDoc::SetFirstDayOfWeek(int nDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetFirstDayOfWeek(nDay);
    }
}


void CRunningLogDoc::SetDisplayInfoRun(bool fDisp)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDisplayInfoRun(fDisp);
    }
}    


void CRunningLogDoc::SetDisplayInfoBike(bool fDisp)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDisplayInfoBike(fDisp);
    }
}    


void CRunningLogDoc::SetDisplayInfoSwim(bool fDisp)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDisplayInfoSwim(fDisp);
    }
}    


void CRunningLogDoc::SetDisplayInfoStrength(bool fDisp)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDisplayInfoStrength(fDisp);
    }
}    


void CRunningLogDoc::SetDisplayInfoRace(bool fDisp)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDisplayInfoRace(fDisp);
    }
}    


void CRunningLogDoc::SetCurrentDate(COleDateTime tmCur)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetCurrentDate(tmCur);
    }
}


void CRunningLogDoc::SetHighlightDay(int nDay)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetHighlightDay(nDay);
    }
}


void CRunningLogDoc::SetBgColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetBgColor(cr);
    }
}


void CRunningLogDoc::SetDayColor(int nType, COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDayColor(nType, cr);
    }
}


void CRunningLogDoc::SetButtonColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetButtonColor(cr);
    }
}


void CRunningLogDoc::SetHighlightColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetHighlightColor(cr);
    }
}


void CRunningLogDoc::SetShadowColor(bool bOne, COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetShadowColor(bOne, cr);
    }
}


void CRunningLogDoc::SetGradientColor(bool bBegin, COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetGradientColor(bBegin, cr);
    }
}


void CRunningLogDoc::SetRaceDayColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetRaceDayColor(cr);
    }
}


void CRunningLogDoc::SetUpcomingRaceDayColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetUpcomingRaceDayColor(cr);
    }
}


void CRunningLogDoc::SetUpcomingWorkoutDayColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetUpcomingWorkoutDayColor(cr);
    }
}


void CRunningLogDoc::SetHeadingTextColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetHeadingTextColor(cr);
    }
}


void CRunningLogDoc::SetDayTextColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDayTextColor(cr);
    }
}


void CRunningLogDoc::SetAnnotationTextColor(COLORREF cr)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetAnnotationTextColor(cr);
    }
}


void CRunningLogDoc::SetDayFont(CFont* pfnt)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetDayFont(pfnt);
    }
}


void CRunningLogDoc::SetHeadingFont(CFont* pfnt)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetHeadingFont(pfnt);
    }
}


void CRunningLogDoc::SetTitleFont(CFont* pfnt)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetTitleFont(pfnt);
    }
}


void CRunningLogDoc::SetAnnotationFont(CFont* pfnt)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetAnnotationFont(pfnt);
    }
}


void CRunningLogDoc::SetAnnotationFontBold(CFont* pfnt)
{
    CUser* pUser = GetUser();
    if(NULL != pUser)
    {
        pUser->SetAnnotationFontBold(pfnt);
    }
}


BOOL CRunningLogDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
    {
        return FALSE;
    }

    // add any reinitialization here

	return TRUE;
}


BOOL CRunningLogDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
    {
        return FALSE;
    }

    // add any reinitialization here

	return TRUE;
}


void CRunningLogDoc::Serialize(CArchive& rArchive)
{
	if (rArchive.IsStoring())
	{
	}
	else
    {
    }
}


#ifdef _DEBUG
void CRunningLogDoc::AssertValid() const
{
	CDocument::AssertValid();
}


void CRunningLogDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG