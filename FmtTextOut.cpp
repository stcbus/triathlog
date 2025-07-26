#include "stdafx.h"
#include "fmttextout.h"

CFmtUtil::CColorStack::CColorStack(CDC *pDC, int nCode) 
{ 
    m_pDC = pDC; 
    Push(nCode); 
} 

CFmtUtil::CColorStack::~CColorStack() 
{ 
	while(m_sColor.size() > 1) 
        Pop(); 

	m_pDC->SetTextColor(m_sColor.top());
	m_sColor.pop();
} 

void CFmtUtil::CColorStack::Push(COLORREF clr) 
{ 
    m_sColor.push(clr); 
    m_pDC->SetTextColor(clr); 
} 

void CFmtUtil::CColorStack::Pop() 
{ 
	if(m_sColor.size() > 1)
	{
		m_sColor.pop(); 

		if(!m_sColor.empty()) 
			m_pDC->SetTextColor(m_sColor.top()); 
	}
} 


CFmtUtil::CFontStack::CFontStack(CDC *pDC, LOGFONT *plf) 
{ 
	m_pCurrFont = NULL;
	m_pOldFont = NULL;
	m_pDC = pDC;

    m_sFont.push(*plf);
    ChangeFont(plf);   
} 

CFmtUtil::CFontStack::~CFontStack() 
{ 
    while(m_sFont.size() > 1) 
        Pop(); 

	m_sFont.pop();

	FreeResource();
}

void CFmtUtil::CFontStack::FreeResource()
{
	if(m_pCurrFont)
	{
		m_pDC->SelectObject(m_pOldFont);
		m_pCurrFont->DeleteObject();
		delete m_pCurrFont;
	}
}

void CFmtUtil::CFontStack::ChangeFont(LOGFONT *plf)
{
	CFont	*pFont;

	pFont = new CFont;
	pFont->CreateFontIndirect(plf);
	
	if(m_pCurrFont)
		FreeResource();

	m_pOldFont = m_pDC->SelectObject(pFont);
	m_pCurrFont = pFont;
}

void CFmtUtil::CFontStack::Push(int fs) 
{
	if(!m_sFont.empty())
	{
		LOGFONT lf; 

		lf = m_sFont.top(); 
		switch(fs) 
		{ 
		case Bold: 
			lf.lfWeight = FW_BOLD;
			m_sFont.push(lf);
	        
			ChangeFont(&lf);
			break; 

		case Underline: 
			lf.lfUnderline = TRUE; 
			m_sFont.push(lf); 

			ChangeFont(&lf);
			break; 

		case Italic: 
			lf.lfItalic = TRUE; 
			m_sFont.push(lf); 

			ChangeFont(&lf);
			break; 
		} 
	}
} 

void CFmtUtil::CFontStack::Pop() 
{ 
	if(m_sFont.size() > 1)
	{
		m_sFont.pop(); 

		if(!m_sFont.empty()) 
		{ 
			LOGFONT lf; 

			lf = m_sFont.top(); 
			ChangeFont(&lf);
		} 
	}
} 

int CFmtUtil::GetHexaValue(char ch)
{
	int	nRet = 0;

	switch(ch)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		nRet = ch - '0';
		break;

	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		nRet = ch - 'A' + 10;
		break;

	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		nRet = ch - 'a' + 10;
		break;
	}

	return nRet;
}

int CFmtUtil::FsmColor(CString &str, int idx, COLORREF *pClr)
{
	BOOL	bValid = TRUE;
	char	ch;
	int		nRet;
	int		i;

    for(i=0; i<6; ++i)
	{
		ch = str.GetAt(idx+i);
		if((ch < '0' || ch > '9') && (ch < 'a'  || ch > 'f') && (ch < 'A' || ch > 'F'))
		{
			bValid = FALSE;
			break;
		}
	}

	if(bValid && str[idx+6] == ']')
	{
		int		r, g, b;
		CString strColor = str.Mid(idx, 6);

		r = GetHexaValue(strColor.GetAt(0)) * 16 + GetHexaValue(strColor.GetAt(1));
		g = GetHexaValue(strColor.GetAt(2)) * 16 + GetHexaValue(strColor.GetAt(3));
		b = GetHexaValue(strColor.GetAt(4)) * 16 + GetHexaValue(strColor.GetAt(5));

        *pClr = RGB(r,g,b);
		nRet = 7;
	}
	else
		nRet = i;

	return nRet;
}

int CFmtUtil::TextOut(CDC *pDC, CString &str, int x, int y, int nSpace) 
{ 
    CString strBuffer = ""; 
    char    ch; 
    int     j; 
    CPoint  pt; 
    int     sc = 0; 
    int     ret = 18; 
    COLORREF     nColorCode = 0; 
    int     nFontCode = 0; 
	TEXTMETRIC	tm;

    CColorStack ColorStack(pDC); 

    LOGFONT lf; 
    
    // 0x1030 --> Start Of Font 
    // 0x1040 --> Start Of Color 
    // 0x1130 --> End Of Font 
    // 0x1140 --> End Of Color 
    // 0x0022 --> \r 
    // 0x0023 --> \n 

    // 0x0020 --> determine font 
    // 0x0030 --> determine color 

    FSM _fsm[] = { 
                    {0x0000, '[', 0x0010}, 

                    {0x0010, 'B', 0x0020}, 
                    {0x0010, 'U', 0x0020}, 
                    {0x0010, 'I', 0x0020}, 
                    {0x0010, 'b', 0x0020}, 
                    {0x0010, 'u', 0x0020}, 
                    {0x0010, 'i', 0x0020}, 
                    {0x0020, ']', 0x1030}, 

                    {0x0010, 'C', 0x0021}, 
                    {0x0010, 'c', 0x0021}, 
                    
                    {0x0030, ']', 0x1040}, 

                    {0x0010, '/', 0x0110}, 

                    {0x0110, 'B', 0x0120}, 
                    {0x0110, 'U', 0x0120}, 
                    {0x0110, 'I', 0x0120}, 
                    {0x0110, 'b', 0x0120}, 
                    {0x0110, 'u', 0x0120}, 
                    {0x0110, 'i', 0x0120}, 
                    {0x0120, ']', 0x1130}, 

                    {0x0110, 'C', 0x0121}, 
                    {0x0110, 'c', 0x0121}, 
 
                    {0x0121, ']', 0x1140}, 

                    {0x0000, '\r', 0x0022}, 
                    {0x0000, '\n', 0x0023}, 
                    {0x0010, '[', 0x0024}, 
                    
                    {0x0000, ']', 0x0011}, 
                    {0x0011, ']', 0x0025} 
    }; 

    int nFsmSize = sizeof _fsm / sizeof _fsm[0]; 
        

    pDC->SetTextAlign(TA_UPDATECP | TA_BOTTOM); 
    pDC->MoveTo(x, y + ret); 

	CFont fntDefault;
	fntDefault.CreateStockObject(DEFAULT_GUI_FONT);
	CFont* pfnt = pDC->SelectObject(&fntDefault);
	pfnt->GetLogFont(&lf);
	pDC->SelectObject(pfnt);
	fntDefault.DeleteObject();

    //CFont fntDefault; 
    //fntDefault.CreateStockObject(DEFAULT_GUI_FONT); 
    //fntDefault.GetLogFont(&lf); 
	
    CFontStack Font(pDC, &lf); 

	pDC->GetTextMetrics(&tm);

    for(int i=0; i<str.GetLength(); ++i) 
    { 
        ch = str.GetAt(i); 

        for(j=0; j<nFsmSize; ++j) 
        { 
            if(_fsm[j].curr == sc && _fsm[j].ch == ch) 
            { 
                sc = _fsm[j].next; 
                break; 
            } 
        } 

        if(j >= nFsmSize) 
        { 
            switch(sc) 
            { 
            case 0x0000: 
            case 0x0010: 
            case 0x0011: 
            case 0x1030: 
            case 0x1040: 
            case 0x1130: 
            case 0x1140: 
                strBuffer += ch; 
                break; 
            } 
        } 
        // 0x1030 --> Start Of Font 
        // 0x1040 --> Start Of Color 
        // 0x1130 --> End Of Font 
        // 0x1140 --> End Of Color 
        // 0x0022 --> \r 
        // 0x0023 --> \n 

        // 0x0020 --> determine font 
        // 0x0030 --> determine color 
        switch(sc) 
        { 
        case 0x0020: 
            switch(ch) 
            { 
            case 'B': 
			case 'b':
				nFontCode = CFontStack::Bold; 
                break; 

            case 'I': 
			case 'i':
                nFontCode = CFontStack::Italic; 
                break; 

            case 'U': 
			case 'u':
                nFontCode = CFontStack::Underline; 
                break; 
            } 
            break; 

		case 0x0021:
			if(FsmColor(str, i+1, &nColorCode) == 7)
			{
				PrintBuffer(pDC, strBuffer, sc); 
				ColorStack.Push(nColorCode); 
				sc = 0x0000;
				i += 7;
			}
			else
			{
				strBuffer += ch;
				sc = 0x0000;
			}
			break;

			/*
        case 0x0030: 
            nColorCode = ch - 'A'; 
            break; 
			*/

        case 0x1030: 
            PrintBuffer(pDC, strBuffer, sc); 
            Font.Push(nFontCode); 
            break; 

        case 0x1040:            
            
            break; 

        case 0x1130: 
            PrintBuffer(pDC, strBuffer, sc); 
            Font.Pop(); 
            break; 

        case 0x1140: 
            PrintBuffer(pDC, strBuffer, sc); 
            ColorStack.Pop(); 
            break; 

        case 0x0022: 
            PrintBuffer(pDC, strBuffer, sc); 

            pt = pDC->GetCurrentPosition(); 
            pt.x = x; 
            pDC->MoveTo(pt); 
            break; 

        case 0x0023: 
            PrintBuffer(pDC, strBuffer, sc); 

            pt = pDC->GetCurrentPosition(); 
			pt.y += tm.tmHeight + nSpace; 
            pDC->MoveTo(pt); 

			ret += tm.tmHeight + nSpace; 
            break; 

        case 0x0024: 
        case 0x0025: 
            strBuffer += ch; 
            sc = 0; 
            break; 
        } 
    } 

    pDC->TextOut(0, 0, strBuffer); 
    return ret; 
}