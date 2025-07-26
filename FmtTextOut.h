#ifndef FMTTEXTOUT_H
#define FMTTEXTOUT_H

#include <stack> 

class CFmtUtil
{
private:

	class CColorStack 
	{ 
	private: 
		std::stack<COLORREF> m_sColor; 
		CDC             *m_pDC; 

	public: 
		CColorStack(CDC *pDC, int nCode=0); 
		~CColorStack(); 

		void Push(COLORREF clr); 
		void Pop(); 
	}; 


	class CFontStack 
	{ 
	private: 
		std::stack<LOGFONT>	m_sFont; 
		CFont           *m_pCurrFont;
		CFont			*m_pOldFont;
		CDC             *m_pDC;

	public:
		enum {Bold, Underline, Italic};

	private:
		void FreeResource();
		void ChangeFont(LOGFONT *plf);

	public: 
		CFontStack(CDC *pDC, LOGFONT *plf); 
		~CFontStack(); 

		void Push(int fs); 
		void Pop(); 
	};

	typedef struct _FSM
	{
		int		curr;
		char	ch;
		int		next;
	} FSM, *PFSM;

private:
	CFmtUtil() {}

	void PrintBuffer(CDC *pDC, CString &strBuffer, int &sc) 
	{ 
		pDC->TextOut(0, 0, strBuffer); 
		strBuffer = ""; 
		sc = 0; 
	}

	int GetHexaValue(char ch);
	int FsmColor(CString &str, int idx, COLORREF *pClr);

public:
	~CFmtUtil() {}

	int TextOut(CDC *pDC, CString &str, int x=0, int y=0, int nSpace=0);

    friend CFmtUtil *FmtUtil();
};

inline CFmtUtil *FmtUtil()
{
	static CFmtUtil	 instance;
	return &instance;
}

#endif