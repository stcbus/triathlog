// FormulaParser.h: interface for the CFormulaParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMELPARSER_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_)
#define AFX_FORMELPARSER_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define ANZFUNKTKONST 22

class CFormulaParser  
{
private:
	//Implementation
	CString m_strFormula;
	CString m_strFunction;
	CString m_strErrortext;
	double m_dFunctionConstant[ANZFUNKTKONST];
	CStringArray m_strStandardFunction;

	double SignFactor(WORD& nPosition, CString& strCharacter);
	double Expression(WORD& nPosition, CString& strCharacter);
	double SimpleExpression(WORD& nPosition, CString& strCharacter);
	double Term(WORD& nPosition, CString& strCharacter);
	double Factor(WORD& nPosition, CString& strCharacter);
	double Char_n(WORD& nPosition, CString& strCharacter);
    CString strChar_(WORD w);

    double MyArctanh(double dVal);
    double MyArcsinh(double dVal);
    double MyArccosh(double dVal);
    double MyRad(double dVal);
    double MyDeg(double dVal);
    double GetPi(void);
				 
public:
    BOOL CheckParenthesis(void);
	CString GetFormula();
	void SetFormula(CString Formula);
	void SetFunctConst(int index, double val);
	
	CFormulaParser();
	virtual ~CFormulaParser();

	//Interface
	double Calculation(CString strFormula, WORD& ErrorPosition, CString& Errortext);
};

#endif // !defined(AFX_FORMELPARSER_H__F802A742_8772_11D1_BD24_0000C02FB5AC__INCLUDED_)
