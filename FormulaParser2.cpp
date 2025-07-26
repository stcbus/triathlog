//////////////////////////////////////////////////////////////////////
// FormulaParser2.cpp: implementation of the CFormulaParser2 class.
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "math.h"
#include "Util.h"
#include "FormulaParser2.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFormulaParser2::CFormulaParser2()
{	
}


CFormulaParser2::~CFormulaParser2()
{

}

//////////////////////////////////////////////////////////////////////
// Methoden
//////////////////////////////////////////////////////////////////////


unsigned int CFormulaParser2::Calculation(CString strFormula, WORD& ErrorPosition, CString& Errortext)
{
	strFormula = GetFormula();

    WORD nPosition;
	CString strCharacter;
	unsigned int ergebnis;
	char buffer[32];

	m_strErrortext.Empty();

    if (!CheckParenthesis())
    {
        // Formula has an error in parenthesis
        ErrorPosition = 0;
        Errortext = m_strErrortext;
        return 0;
    } 
	try
	{
		strFormula.TrimLeft();
		strFormula.TrimRight();
		m_strFunction = strFormula + strChar_(0);
		nPosition = 0;
		Char_n(nPosition, strCharacter);
		ergebnis = Expression(nPosition, strCharacter);
		if (strCharacter == strChar_(0))
		{
			Errortext = m_strErrortext;
			ErrorPosition = 0;
		}
		else
		{
			ErrorPosition = nPosition;
			sprintf(buffer, "error at position %d: ", (int) ErrorPosition);
			Errortext = buffer;
			Errortext += m_strErrortext;
		}

		return ergebnis;
	}
	catch (CException* ex)
	{
		TCHAR szCause[255];        
		ex->GetErrorMessage(szCause, 255);
		Errortext = _T("error in calculation because ");
		Errortext += szCause;        
		return 0;
	}
}


CString CFormulaParser2::strChar_(WORD w)
{
    CString str;
    str.Format("%c", w);
    return str;
}


BOOL CFormulaParser2::CheckParenthesis()
{
    // Count open and close parenthesis to check correctness and forget about it
    // for the rest of the process.
    char cInput;
    int iOpenPar = 0, iClosePar = 0;
    // Go through all characters in the expression and check each char
    for( int ii=0; ii<m_strFormula.GetLength();ii++)
    {
        // Get current char
        cInput = m_strFormula.GetAt(ii);
        // register parenthesis number and avoid tokenize it
        if (cInput == '(')
        {
            iOpenPar++;
        }
        else if (cInput == ')')
        {
            iClosePar++;
        }
    }
    // Check number of open parenthesys is OK
    if (iOpenPar > iClosePar)
    {
        // missing close parenthesys
        m_strErrortext = "missing a closing parenthesis";
        return FALSE;
    }
    // Check number of close parenthesys is OK
    else if (iOpenPar < iClosePar)
    {
        // missing open parenthesys
        m_strErrortext = "missing an open parenthesis";
        return FALSE;
    }
    return TRUE;
}


unsigned int CFormulaParser2::NotFactor(WORD& nPosition, CString& strCharacter)
{
  if (strCharacter == "~")
	{
	  Char_n(nPosition, strCharacter);
    return Not(Factor(nPosition, strCharacter));
	}
  else return Factor(nPosition, strCharacter);
}

unsigned int CFormulaParser2::Expression(WORD& nPosition, CString& strCharacter)
{
	CString strOperator;
	unsigned int erg = SimpleExpression(nPosition, strCharacter);
	while (strCharacter == "&" || strCharacter == "|" || strCharacter == "^")
	{
		strOperator = strCharacter;
		Char_n(nPosition, strCharacter);
		if (strOperator == "&")
			erg = And(erg, SimpleExpression(nPosition, strCharacter));
		else if(strOperator == "|")
			erg = Or(erg, SimpleExpression(nPosition, strCharacter));
		else if(strOperator == "^")
			erg = Xor(erg, SimpleExpression(nPosition, strCharacter));
	}
	return erg;
}

unsigned int CFormulaParser2::SimpleExpression(WORD& nPosition, CString& strCharacter)
{
	unsigned int s;
	CString strOperator;
	s = Term(nPosition, strCharacter);
	return s;
}

unsigned int CFormulaParser2::Term(WORD& nPosition, CString& strCharacter)
{
  unsigned int t;
  t = NotFactor(nPosition, strCharacter);

  return t;
}

unsigned int CFormulaParser2::Char_n(WORD& nPosition, CString& strCharacter)
{
  do
	{
    nPosition ++;	// evtl. nach strCharacter
		if (nPosition <= m_strFunction.GetLength())
			//war geändert auf:  strCharacter = MID(m_strFunction, nPosition, 1);
			strCharacter = m_strFunction.Mid(nPosition - 1, 1);			
		else 
			strCharacter = strChar_(0);

	//	TRACE("strCharacter= "+ strCharacter);
 	}
  while (strCharacter == " "); 

	return nPosition;
}

void CFormulaParser2::SetFormula(CString Formula)
{
	m_strFormula = Formula;

	m_strFormula.Replace("and", "&");
	m_strFormula.Replace("xor", "^");
	m_strFormula.Replace("or", "|");
	m_strFormula.Replace("not", "~");

	m_strFormula.Replace("[1]", "a");
	m_strFormula.Replace("[2]", "b");
	m_strFormula.Replace("[3]", "c");
	m_strFormula.Replace("[4]", "d");
	m_strFormula.Replace("[5]", "e");
	m_strFormula.Replace("[6]", "f");
	m_strFormula.Replace("[7]", "g");
	m_strFormula.Replace("[8]", "h");
	m_strFormula.Replace("[9]", "i");
	m_strFormula.Replace("[10]", "j");
	m_strFormula.Replace("[11]", "k");
	m_strFormula.Replace("[12]", "l");
}

CString CFormulaParser2::GetFormula()
{
	return m_strFormula;
}

unsigned int CFormulaParser2::Factor(WORD& nPosition, CString& strCharacter)
{
  unsigned int f = 0;
	BOOL erfolg = false;
	WORD wI=0, wL=0, wBeginn=0, wError=0;
	wError = 0;

//	if	(strCharacter == strChar_(0)) return 0.0;

	//if ((BYTE) strCharacter[0] >= (BYTE) "0" && (BYTE) strCharacter[0] <= (BYTE) "9" || strCharacter == ".")
	if (strCharacter >= "0" && strCharacter <= "9" || strCharacter == ".")
	{
		wBeginn = nPosition;

		do
		{
			Char_n(nPosition, strCharacter);
		} 
		while ((strCharacter >= "0" && strCharacter <= "9" || strCharacter == "."));
			// while (!((BYTE) strCharacter[0] >= (BYTE) "0") && ((BYTE) strCharacter[0] <= (BYTE) "9") || (strCharacter == "."));
			
		if (strCharacter == ".") // Abfrage wird nie abgearbeitet
		{
			do
			{
				Char_n(nPosition, strCharacter);
			} 
			while (!((BYTE)strCharacter[0] >= (BYTE)"0") && ((BYTE)strCharacter[0] <=  (BYTE)"9")  || ((BYTE)strCharacter[0] == (BYTE)"."));
		}
		f = atoi(m_strFunction.Mid(wBeginn - 1, nPosition - wBeginn ));
//original aus VB:            f = Val(Mid$(funktion$, beginn%, position% - beginn%))

	} 
	else
	{
		CString strCharacterUpper = strCharacter;
		strCharacterUpper.MakeUpper();
		if (strCharacter == "(")
		{
			Char_n(nPosition, strCharacter);
			f = Expression(nPosition, strCharacter);
			if (strCharacter == ")")
				Char_n(nPosition, strCharacter);
		}
		else if (strCharacter == "a")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[0];
		}
		else if (strCharacter == "b")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[1];
		}
		else if (strCharacter == "c")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[2];
		}
		else if (strCharacter == "d")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[3];
		}
		else if (strCharacter == "e")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[4];
		}
		else if (strCharacter == "f")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[5];
		}
		else if (strCharacter == "g")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[6];
		}
		else if (strCharacter == "h")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[7];
		}
		else if (strCharacter == "i")	
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[8];
		}
		else if (strCharacter == "j")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[9];
		}
		else if (strCharacter == "k")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[10];
		}
		else if (strCharacter == "l")
		{
			Char_n(nPosition, strCharacter);
			f = m_uiFunctionConstant[11];
		}
	}
	
	if (wError == -1) 
		m_strErrortext = "an error was found -- check input for divide by zero and overflow errors)";

  return f;
}

void CFormulaParser2::SetFunctConst(int index, unsigned int val)
{
	if (index >= 0 && index < ANZFUNKTKONST) 
		m_uiFunctionConstant[index] = val;
	else
		CUtil::Fatal("Bad parameter to CFormulaParser2::SetFunctConst");
}


unsigned int CFormulaParser2::And(unsigned int uiA, unsigned int uiB)
{
	if(uiA > 0 && uiB > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


unsigned int CFormulaParser2::Or(unsigned int uiA, unsigned int uiB)
{
	if(uiA > 0 || uiB > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


unsigned int CFormulaParser2::Xor(unsigned int uiA, unsigned int uiB)
{
	if((uiA > 0 && uiB > 0) || (uiA == 0 && uiB == 0))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


unsigned int CFormulaParser2::Not(unsigned int uiA)
{
	if(uiA > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}