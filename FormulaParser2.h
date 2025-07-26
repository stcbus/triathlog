// FormulaParser2.h: interface for the CFormulaParser2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMELPARSER2_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_)
#define AFX_FORMELPARSER2_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define ANZFUNKTKONST 12

class CFormulaParser2  
{
private:
	//Implementation
	CString m_strFormula;
	CString m_strFunction;
	CString m_strErrortext;
	unsigned int m_uiFunctionConstant[ANZFUNKTKONST];

	unsigned int NotFactor(WORD& nPosition, CString& strCharacter);
	unsigned int Expression(WORD& nPosition, CString& strCharacter);
	unsigned int SimpleExpression(WORD& nPosition, CString& strCharacter);
	unsigned int Term(WORD& nPosition, CString& strCharacter);
	unsigned int Factor(WORD& nPosition, CString& strCharacter);
	unsigned int Char_n(WORD& nPosition, CString& strCharacter);
    CString strChar_(WORD w);

	unsigned int And(unsigned int uiA, unsigned int uiB);
	unsigned int Or(unsigned int uiA, unsigned int uiB);
	unsigned int Xor(unsigned int uiA, unsigned int uiB);
	unsigned int Not(unsigned int uiA);
				 
public:
    BOOL CheckParenthesis(void);
	CString GetFormula();
	void SetFormula(CString Formula);
	void SetFunctConst(int index, unsigned int val);
	
	CFormulaParser2();
	virtual ~CFormulaParser2();

	//Interface
	unsigned int Calculation(CString strFormula, WORD& ErrorPosition, CString& Errortext);
};

#endif // !defined(AFX_FORMELPARSER2_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_)
