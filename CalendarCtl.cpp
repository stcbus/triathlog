#include "StdAfx.h"
#include "RunningLog.h"
#include "RunningLogDoc.h"
#include "RunningLogView.h"
#include "Util.h"
#include "FmtTextOut.h"
#include "DrawHTML.h"
#include "CalendarCtl.h"


CCalendarCtl::CCalendarCtl(CRunningLogView* pParent)
{
    SetParent(pParent);
}


CCalendarCtl::~CCalendarCtl()
{
}


void CCalendarCtl::DrawCalendar(CDC* pDC, CRect rcDraw)
{
    CRunningLogView* pParent = GetParent();
    if((NULL == pParent) || (NULL == pDC))
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::DrawCalendar");
        return;
    }

    CBrush brBg(pParent->GetBgColor());

    pDC->FillRect(&rcDraw, &brBg);

    int nHeight = rcDraw.Height();
    int nWidth = rcDraw.Width();

    int nXOffset = GetMinWidthOffset();
    int nYOffset = GetMinHeightOffset();
    // the distance we start from the side - a min plus however many pixels 
    // are left over after the days are drawn
    int nWidthOffset = nXOffset + ((nWidth % 7) / 2);
    COleDateTime tmDate = pParent->GetCurrentDate();
    int nWeeks = CUtil::GetNumWeeks(tmDate, pParent->GetFirstDayOfWeek());

    CSize szBox((nWidth - (2 * nWidthOffset) - (7 * GetHorzSpacing())) / 7, (nHeight - nYOffset - nWeeks * GetVertSpacing()) / nWeeks);
    SetBoxSize(szBox);

    CPoint ptTopLeft(rcDraw.left + nWidthOffset, rcDraw.top + nYOffset);

    COleDateTime tmCur = CUtil::GetFirstVisibleDay(tmDate, pParent->GetFirstDayOfWeek());
    for(int j = 0; j < nWeeks; j++)
    {
        ptTopLeft.x = rcDraw.left + nWidthOffset;

        for(int i = 0; i < 7; i++)
        {
            int nType = (tmDate.GetMonth() == tmCur.GetMonth()) ? DAYTYPE_NORMAL : DAYTYPE_GRAYED;
            DrawDay(pDC, ptTopLeft, tmCur, nType, 0);

            if(j == 0)
            {
                int nTitleDay = (pParent->GetFirstDayOfWeek() + i) % 7;
                if(0 == nTitleDay)
                {
                    nTitleDay = SATURDAY;
                }

                CRect rcText(ptTopLeft.x, rcDraw.top, ptTopLeft.x + szBox.cx, rcDraw.top + nYOffset);

                CFont* pfntOrig = pDC->SelectObject(pParent->GetHeadingFont());
                COLORREF crOld = pDC->SetTextColor(pParent->GetHeadingTextColor());
                int nMode = pDC->SetBkMode(TRANSPARENT);

                pDC->DrawText(CUtil::DayToString(nTitleDay), &rcText, DT_SINGLELINE | DT_CENTER | DT_VCENTER); 
                
                pDC->SetTextColor(crOld);
                pDC->SelectObject(pfntOrig);
                pDC->SetBkMode(nMode);
            }

            ptTopLeft.x += szBox.cx + GetHorzSpacing();
            tmCur = CUtil::AddDay(tmCur);
        }

        ptTopLeft.y += szBox.cy + GetVertSpacing();
    }
}


void CCalendarCtl::DrawDay(CDC* pDC, CPoint ptTopLeft, COleDateTime tmDay, int nType, int nWeek) const
{
    CRunningLogView* pParent = GetParent();
    if((NULL == pDC) || (NULL == pParent))
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::DrawDay");
        return;
    }

    CSize szBox = GetBoxSize();
    CRect rcDraw(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x + szBox.cx, ptTopLeft.y + szBox.cy);

    CBrush brBg;
    if(pParent->IsHighlightDay(nType, tmDay, nWeek))
    {
        brBg.CreateSolidBrush(pParent->GetHighlightColor());
    }
    else if(pParent->IsRaceDay(tmDay))
    {
        brBg.CreateSolidBrush(pParent->GetRaceDayColor());
    }
	else if(pParent->MarkAsUpcomingRaceDay(tmDay))
	{
		brBg.CreateSolidBrush(pParent->GetUpcomingRaceDayColor());
	}
	else if(pParent->MarkAsUpcomingWorkoutDay(tmDay))
	{
		brBg.CreateSolidBrush(pParent->GetUpcomingWorkoutDayColor());
	}
    else
    {
        brBg.CreateSolidBrush(pParent->GetDayColor(nType));
    }

    pDC->FillRect(rcDraw, &brBg);  
    pDC->Draw3dRect(rcDraw, pParent->GetShadowColor(true), pParent->GetShadowColor(false));

    AnnotateDay(pDC, rcDraw, rcDraw, tmDay, nType);
}


void CCalendarCtl::AnnotateDay(CDC* pDC, CRect rcDay, CRect rcAllowedDraw, COleDateTime tmDay, int nType) const
{
    bool fUpcomingRace = false;
    bool fUpcomingWorkout = false;
    CRunningLogView* pParent = GetParent();
    if((NULL == pParent) || (NULL == pDC))
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::AnnotateDay");
        return;
    }

    int nLeft = 5;

    CString strText;
    CRect rect;

    CFont* pfntOrig = pDC->SelectObject(pParent->GetDayFont());
    COLORREF crOrig = pDC->SetTextColor(pParent->GetDayTextColor());
    int nMode = pDC->SetBkMode(TRANSPARENT);

    int nNum = GetNumAnnotations(nType, tmDay);
    if(nNum < 3)
    {
        nNum = 3;
    }

    int nHeight = (rcDay.Height() - GetDayVertSpacing()) / nNum;
   
    switch(nType)
    {
    case DAYTYPE_NORMAL:
    case DAYTYPE_GRAYED:
        {
            strText.Format("%d", tmDay.GetDay());

            rect.SetRect(rcDay.left, rcDay.top, rcDay.left + GetDayHorzSpacing(), rcDay.top + GetDayVertSpacing());

            pDC->DrawText(strText, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
  
            CWinApp* pApp = AfxGetApp();

            int iCurX = 28;
            if(CUtil::IsSameDay(tmDay, COleDateTime::GetCurrentTime()))
            {
                if(NULL != pApp)
                {
                    HICON hIcon = pApp->LoadIcon(IDI_CURRENTDAY);
                    pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                }
            }
            iCurX += 28;

            if(pParent->MarkAsUpcomingRaceDay(tmDay))
            {
                if(NULL != pApp)
                {
                    HICON hIcon = pApp->LoadIcon(IDI_UPCOMINGRACE);
                    pDC->DrawIcon(CPoint(rcDay.right - 60, rcDay.top), hIcon);
					iCurX += 28;
                }
            }
            else
            {
                if(pParent->IsInjuryDay(tmDay))
                {
                    if(NULL != pApp)
                    {
                        HICON hIcon = pApp->LoadIcon(IDI_INJURY2);    
                        pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                        iCurX += 28;
                    }
                }

                if(pParent->IsSickDay(tmDay))
                {
                    if(NULL != pApp)
                    {
                        HICON hIcon = pApp->LoadIcon(IDI_SICK);    
                        pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                        iCurX += 28;
                    }
                }

                if(pParent->IsLongDay(tmDay))
                {
                    if(NULL != pApp)
                    {
                        HICON hIcon = pApp->LoadIcon(IDI_LONGDAY);    
                        pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                        iCurX += 28;
                    }
                }
                if(pParent->IsBrickDay(tmDay))
                {
                    if(NULL != pApp)
                    {
                        HICON hIcon = pApp->LoadIcon(IDI_BRICK);
                        pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                        iCurX += 28;
                    }
                }
                if(pParent->IsJambaDay(tmDay))
                {
                    if(NULL != pApp)
                    {
                        HICON hIcon = pApp->LoadIcon(IDI_JAMBAJUICE);
                        pDC->DrawIcon(CPoint(rcDay.right - iCurX, rcDay.top), hIcon);
                        iCurX += 28;
                    }
                }
            }

			CFont* pFntNormal = pParent->GetAnnotationFont();
			CFont* pFntBold = pParent->GetAnnotationFontBold();

            COLORREF crOrig2 = pDC->SetTextColor(pParent->GetAnnotationTextColor());
            CFont* pfntOrig2 = pDC->SelectObject(pFntNormal);
            
            // GetAnnotationRun also gets the first line of the upcoming race stuff
            CString str1 = pParent->GetAnnotationRun(nType, tmDay, fUpcomingRace, fUpcomingWorkout);
            if((false == pParent->DisplayInfoRun()) && (false == fUpcomingRace) && (false == fUpcomingWorkout))
            {
                str1 = "";
            }

            CString str2 = pParent->GetAnnotationBike(nType, tmDay, fUpcomingRace, fUpcomingWorkout);
            if((false == pParent->DisplayInfoBike()) && (false == fUpcomingRace) && (false == fUpcomingWorkout))
            {
                str2 = "";
            }
            
            CString str3 = pParent->GetAnnotationSwim(nType, tmDay, fUpcomingRace, fUpcomingWorkout);
            if((false == pParent->DisplayInfoSwim()) && (false == fUpcomingRace) && (false == fUpcomingWorkout))
            {
                str3 = "";
            }

            CString str4 = pParent->GetAnnotationStrength(nType, tmDay, fUpcomingRace, fUpcomingWorkout);
            if((false == pParent->DisplayInfoStrength()) && (false == fUpcomingRace) && (false == fUpcomingWorkout))
            {
                str3 = "";
            }

            CString str5 = pParent->DisplayInfoRace() ? pParent->GetAnnotationRace(nType, tmDay) : "";

            rect.SetRect(rcAllowedDraw.left, rcAllowedDraw.top, rcAllowedDraw.left + GetDayHorzSpacing(), rcAllowedDraw.top + GetDayVertSpacing());

            rect.left += nLeft;
            rect.top = rect.bottom;
            rect.bottom = rect.top + nHeight;
            rect.right = rcAllowedDraw.right;

            if((pParent->MarkAsUpcomingRaceDay(tmDay)) || (pParent->MarkAsUpcomingWorkoutDay(tmDay)))
            {
                pDC->DrawText(str1, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
                pDC->DrawText(str2, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
                pDC->DrawText(str3, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
                pDC->DrawText(str4, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }
            else
            {
                bool afIndent[5];
                nNum = ReadyDisplayStrings(pDC, str1, str2, str3, str4, str5, rcAllowedDraw.Width() - nLeft, 
                                 rcAllowedDraw.Height() - GetDayVertSpacing(), afIndent, nLeft);
                if(nNum < 3)
                {
                    nNum = 3;
                }

                int nCurIndent = 0;
                nHeight = (rcAllowedDraw.Height() - GetDayVertSpacing()) / nNum;
                int nHeightIndent = (3 * nHeight) / 4;
                if(!str1.IsEmpty())
                {
                    DrawDayString(pDC, rect, str1, nLeft, afIndent[0], afIndent[1], nHeight, nHeightIndent, pFntNormal, pFntBold);
                }

                if(!str2.IsEmpty())
                {
                    DrawDayString(pDC, rect, str2, nLeft, afIndent[1], afIndent[2], nHeight, nHeightIndent, pFntNormal, pFntBold);
                }

                if(!str3.IsEmpty())
                {
                    DrawDayString(pDC, rect, str3, nLeft, afIndent[2], afIndent[3], nHeight, nHeightIndent, pFntNormal, pFntBold);
                }

                if(!str4.IsEmpty())
                {
                    DrawDayString(pDC, rect, str4, nLeft, afIndent[3], afIndent[4], nHeight, nHeightIndent, pFntNormal, pFntBold);
                }

                if(!str5.IsEmpty())
                {
                    DrawDayString(pDC, rect, str5, nLeft, afIndent[4], false, nHeight, nHeightIndent, pFntNormal, pFntBold);
                }
            }

            pDC->SetTextColor(crOrig2);
            pDC->SelectObject(pfntOrig2);

            break;
        }

    case DAYTYPE_MONTHSUM:
        {
            bool fTemp;
			bool fTemp2;
            strText = "Month:";
            rect.SetRect(rcDay.left, rcDay.top, rcDay.right, rcDay.top + GetDayVertSpacing());

            pDC->DrawText(strText, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

            COLORREF crOrig2 = pDC->SetTextColor(pParent->GetAnnotationTextColor());
            CFont* pfntOrig2 = pDC->SelectObject(pParent->GetAnnotationFont());
            
            CString str1 = pParent->GetAnnotationRun(nType, tmDay, fTemp, fTemp2);
            CString str2 = pParent->GetAnnotationBike(nType, tmDay, fTemp, fTemp2);
            CString str3 = pParent->GetAnnotationSwim(nType, tmDay, fTemp, fTemp2);
            CString str4 = pParent->GetAnnotationStrength(nType, tmDay, fTemp, fTemp2);

            rect.left += nLeft;
            rect.top = rect.bottom;
            rect.bottom = rect.top + nHeight;
            rect.right = rcDay.right;

            if((pParent->DisplayInfoRun()) && (!str1.IsEmpty()))
            {
                pDC->DrawText(str1, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }
            
            if((pParent->DisplayInfoBike()) && (!str2.IsEmpty()))
            {
                pDC->DrawText(str2, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            if((pParent->DisplayInfoSwim()) && (!str3.IsEmpty()))
            {
                pDC->DrawText(str3, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            if((pParent->DisplayInfoStrength()) && (!str4.IsEmpty()))
            {
                pDC->DrawText(str4, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            pDC->SetTextColor(crOrig2);
            pDC->SelectObject(pfntOrig2);

            break;
        }
        
    case DAYTYPE_WEEKSUM:
        {
            bool fTemp;
			bool fTemp2;
            strText = "Week:";
            rect.SetRect(rcDay.left, rcDay.top, rcDay.right, rcDay.top + GetDayVertSpacing());

            pDC->DrawText(strText, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

            COLORREF crOrig2 = pDC->SetTextColor(pParent->GetAnnotationTextColor());
            CFont* pfntOrig2 = pDC->SelectObject(pParent->GetAnnotationFont());

            CString str1 = pParent->GetAnnotationRun(nType, tmDay, fTemp, fTemp2);
            CString str2 = pParent->GetAnnotationBike(nType, tmDay, fTemp, fTemp2);
            CString str3 = pParent->GetAnnotationSwim(nType, tmDay, fTemp, fTemp2);
            CString str4 = pParent->GetAnnotationStrength(nType, tmDay, fTemp, fTemp2);

            rect.left += nLeft;
            rect.top = rect.bottom;
            rect.bottom = rect.top + nHeight;
            rect.right = rcDay.right;

            if((pParent->DisplayInfoRun()) && (!str1.IsEmpty()))
            {
                pDC->DrawText(str1, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }
            
            if((pParent->DisplayInfoBike()) && (!str2.IsEmpty()))
            {
                pDC->DrawText(str2, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            if((pParent->DisplayInfoSwim()) && (!str3.IsEmpty()))
            {
                pDC->DrawText(str3, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            if((pParent->DisplayInfoStrength()) && (!str4.IsEmpty()))
            {
                pDC->DrawText(str4, &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
                rect.top = rect.bottom;
                rect.bottom = rect.top + nHeight;
            }

            pDC->SetTextColor(crOrig2);
            pDC->SelectObject(pfntOrig2);

            break;
        }
    }

    pDC->SetBkMode(nMode);
    pDC->SelectObject(pfntOrig);
    pDC->SetTextColor(crOrig);
}


CSize CCalendarCtl::GetTextSize(CDC* pDC, COleDateTime tmDay, int nType)
{
    CSize sz;
    bool fUpcoming;
	bool fUpcoming2;
    CRunningLogView* pParent = GetParent();

    if((NULL != pParent) && (NULL != pDC))
    {
        CFont* pfntOrig = pDC->SelectObject(pParent->GetDayFont());

        CString str1 = pParent->DisplayInfoRun() ? pParent->GetAnnotationRun(nType, tmDay, fUpcoming, fUpcoming2) : "";
        int n1 = pDC->GetTextExtent(str1).cx;
        CString str2 = pParent->DisplayInfoBike() ? pParent->GetAnnotationBike(nType, tmDay, fUpcoming, fUpcoming2) : "";
        int n2 = pDC->GetTextExtent(str2).cx;
        CString str3 = pParent->DisplayInfoSwim() ? pParent->GetAnnotationSwim(nType, tmDay, fUpcoming, fUpcoming2) : "";
        int n3 = pDC->GetTextExtent(str3).cx;
        CString str4 = pParent->DisplayInfoStrength() ? pParent->GetAnnotationStrength(nType, tmDay, fUpcoming, fUpcoming2) : "";
        int n4 = pDC->GetTextExtent(str4).cx;
        CString str5 = pParent->DisplayInfoRace() ? pParent->GetAnnotationRace(nType, tmDay) : "";
        int n5 = pDC->GetTextExtent(str5).cx;

        CSize szBox = GetBoxSize();
        int nSize = max(n1, max(n2, max(n3, max(n4, n5))));
        if(nSize > szBox.cx)
        {
            sz.cx = nSize + 5;
        }
        else
        {
            sz.cx = szBox.cx;
        }
        sz.cy = max(szBox.cy, 100);

        pDC->SelectObject(pfntOrig);
    }

    return sz;
}


void CCalendarCtl::DrawDayString(CDC* pDC, CRect& rect, CString str, int nLeft, bool fIndentMe, 
                                 bool fIndentNext, int nHeight, int nHeightIndent, CFont* pFntNormal, CFont* pFntBold) const
{
    int nCurIndent = 0;
    if(fIndentMe)
    {
        rect.left += nLeft;
        nCurIndent = nLeft;
    }
    rect.bottom = rect.top + pDC->GetTextExtent(str).cy;

	CRect rcCur = rect;
	CString strCur = str;

	//CFont* pfntOld = pDC->SelectObject(pFntNormal);
	//DrawHTML(pDC->GetSafeHdc(), str, str.GetLength(), &rcCur, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_WORD_ELLIPSIS);
	//pDC->SelectObject(pfntOld);
	
    pDC->DrawText(strCur, &rcCur, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_WORD_ELLIPSIS);

    if(fIndentNext)
    {
        rect.top += nHeightIndent;
    }
    else
    {
        rect.top += nHeight;
    }
    rect.left -= nCurIndent;
}


int CCalendarCtl::ReadyDisplayStrings(CDC* pDC, CString& rstr1, CString& rstr2, CString& rstr3, CString& rstr4, CString& rstr5, 
                                      int nWidth, int nHeight, bool afIndent[5], int nLeft) const
{
    if(NULL == pDC)
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::ReadyDisplayStrings");
        return 0;
    }
    int nTextHeight = pDC->GetTextExtent("l").cy;
    int nMaxLines = nHeight / nTextHeight + 1;

    CString astrLinesIn[5];
    astrLinesIn[0] = rstr1;
    astrLinesIn[1] = rstr2;
    astrLinesIn[2] = rstr3;
    astrLinesIn[3] = rstr4;
    astrLinesIn[4] = rstr5;

	CString astrLinesOut[5];

    int nCurLines = 0;
    for(int i = 0; i < 5; i++)
    {
        afIndent[i] = false;
        if(!astrLinesIn[i].IsEmpty())
        {
            nCurLines++;
        }
    }

	int nCurIn = 0;
	int nCurOut = 0;
	
	for(nCurIn = 0; (nCurIn < 5) && (nCurOut < min(5, nMaxLines)); nCurIn++)
	{
		if(astrLinesIn[nCurIn].IsEmpty())
		{
			continue;
		}

		CString strTemp = astrLinesIn[nCurIn];
		CString strFirst;
		CString strOldTemp;

		bool bIndent = false;
		while(false == strTemp.IsEmpty())
		{
			afIndent[nCurOut] = bIndent;

			int nTotalWidth = nWidth;
			if(true == bIndent)
			{
				nTotalWidth -= nLeft;
			}

			strOldTemp = strTemp;
			CutString(pDC, strTemp, strFirst, nTotalWidth);

			astrLinesOut[nCurOut] = strFirst;
			nCurOut++;

			if(nCurOut >= min(5, nMaxLines))
			{
				astrLinesOut[nCurOut - 1] = strOldTemp;
				break;
			}

			bIndent = true;
		}
	}

    for(int i = nCurOut; i < 5; i++)
    {
        astrLinesOut[i] = "";
    }

    rstr1 = astrLinesOut[0];
    rstr2 = astrLinesOut[1];
    rstr3 = astrLinesOut[2];
    rstr4 = astrLinesOut[3];
    rstr5 = astrLinesOut[4];

    return nCurOut;
}


void CCalendarCtl::CutString(CDC* pDC, CString& rstrCut, CString& rstrLine1, int nWidth) const
{
    if(NULL == pDC)
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::CutString");
        return;
    }

    int iCur = 0;
    int iLast = 0;
    while(true)
    {
        iCur = rstrCut.Find(' ', iLast + 1);
        
        if((iCur > 0) && (pDC->GetTextExtent(rstrCut.Left(iCur)).cx > nWidth))
        {
            break;
        }
		else if(iCur == -1)
		{
			if(pDC->GetTextExtent(rstrCut).cx > nWidth)
			{
				break;
			}
			else
			{
				iLast = 0;
				break;
			}
		}

        iLast = iCur;
    }

    if(0 == iLast)
    {
        rstrLine1 = rstrCut;
        rstrCut = "";
    }
    else
    {
        rstrLine1 = rstrCut.Left(iLast);
        rstrCut = rstrCut.Right(rstrCut.GetLength() - iLast - 1);
    }
}


void CCalendarCtl::MoveStringsDown(CString astrLines[5], int nNoMove) const
{
    for(int i = 3; i > nNoMove; i--)
    {
        if(astrLines[i + 1].IsEmpty())
        {
            astrLines[i + 1] = astrLines[i];
            astrLines[i] = "";
        }
    }
}

    
int CCalendarCtl::GetNumAnnotations(int nType, COleDateTime tmDay) const
{
    bool fTemp = false;
	bool fTemp2 = false;
    int nNum = 0;
    CRunningLogView* pParent = GetParent();
    if(NULL != pParent)
    {
        CString str1 = pParent->GetAnnotationRun(nType, tmDay, fTemp, fTemp2);
        CString str2 = pParent->GetAnnotationBike(nType, tmDay, fTemp, fTemp2);
        CString str3 = pParent->GetAnnotationSwim(nType, tmDay, fTemp, fTemp2);
        CString str4 = pParent->GetAnnotationStrength(nType, tmDay, fTemp, fTemp2);
        CString str5 = pParent->GetAnnotationRace(nType, tmDay);

		if((true == fTemp) || (true == fTemp2))
        {
            return 4;
        }

        if((pParent->DisplayInfoRun()) && (!str1.IsEmpty()))
        {
            nNum++;
        }

        if((pParent->DisplayInfoBike()) && (!str2.IsEmpty()))
        {
            nNum++;
        }

        if((pParent->DisplayInfoSwim()) && (!str3.IsEmpty()))
        {
            nNum++;
        }

        if((pParent->DisplayInfoStrength()) && (!str4.IsEmpty()))
        {
            nNum++;
        }

        if((DAYTYPE_NORMAL == nType) || (DAYTYPE_GRAYED == nType))
        {
            if((pParent->DisplayInfoRace()) && (!str5.IsEmpty()))
            {
                nNum++;
            }
        }
    }

    return nNum;
}


void CCalendarCtl::DrawMonthSummary(CDC* pDC, CRect rcDraw) const
{
    CRunningLogView* pParent = GetParent();
    if((NULL == pParent) || (NULL == pDC))
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::DrawDay");
        return;
    }

    CBrush brBg(pParent->GetBgColor());
    pDC->FillRect(&rcDraw, &brBg);

    COleDateTime tmTime = CUtil::GetFirstOfMonth(pParent->GetCurrentDate());
    CPoint ptTopLeft(rcDraw.left, rcDraw.top);

    DrawDay(pDC, ptTopLeft, tmTime, DAYTYPE_MONTHSUM, 0);
}


void CCalendarCtl::DrawWeekSummaries(CDC* pDC, CRect rcDraw) const
{
    CRunningLogView* pParent = GetParent();
    if((NULL == pParent) || (NULL == pDC))
    {
        CUtil::Fatal("Bad parameter to CCalendarCtl::DrawDay");
        return;
    }

    rcDraw.top += GetMinHeightOffset();
    CBrush brBg(pParent->GetBgColor());
    pDC->FillRect(&rcDraw, &brBg);

    COleDateTime tmTime = CUtil::GetFirstOfMonth(pParent->GetCurrentDate());
    CPoint ptTopLeft(rcDraw.left, rcDraw.top);

    CSize szBox = GetBoxSize();
    int nWeeks = CUtil::GetNumWeeks(tmTime, pParent->GetFirstDayOfWeek());

    COleDateTime tmFirst = CUtil::GetFirstVisibleDay(tmTime, pParent->GetFirstDayOfWeek());

    for(int i = 0; i < nWeeks; i++)
    {
        DrawDay(pDC, ptTopLeft, tmFirst, DAYTYPE_WEEKSUM, i);
        ptTopLeft.y += szBox.cy + GetVertSpacing();
        tmFirst = CUtil::OffsetDay(tmFirst, 7);
    }        
}


int CCalendarCtl::GetMinWidthOffset(void) const
{
    return 1;
}


int CCalendarCtl::GetMinHeightOffset(void) const
{
    return 20;
}


int CCalendarCtl::GetDayHorzSpacing(void) const
{
    return 30;
}


int CCalendarCtl::GetDayVertSpacing(void) const
{
    return 30;
}


int CCalendarCtl::GetHorzSpacing(void) const
{
    return 1;
}


int CCalendarCtl::GetVertSpacing(void) const
{
    return 1;
}


void CCalendarCtl::SetParent(CRunningLogView* pParent)
{
    m_pParent = pParent;
}


CRunningLogView* CCalendarCtl::GetParent(void) const
{
    return m_pParent;
}


void CCalendarCtl::SetBoxSize(CSize sz)
{
    m_szBox = sz;
}


CSize CCalendarCtl::GetBoxSize(void) const
{
    return m_szBox;
}