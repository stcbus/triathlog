//////////////////////////////////////////////////////////////////////
// FormulaParser.cpp: implementation of the CFormulaParser class.
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "math.h"
#include "Util.h"
#include "FormulaParser.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFormulaParser::CFormulaParser()
{	
	m_strStandardFunction.Add("");
	m_strStandardFunction.Add("ABS");
	m_strStandardFunction.Add("SQRT");
	m_strStandardFunction.Add("SINH");
	m_strStandardFunction.Add("COSH");
	m_strStandardFunction.Add("TANH");
	m_strStandardFunction.Add("ARCTAN");
	m_strStandardFunction.Add("LN");
	m_strStandardFunction.Add("LOG");
	m_strStandardFunction.Add("EXP");
	m_strStandardFunction.Add("SIN");
	m_strStandardFunction.Add("COS");
	m_strStandardFunction.Add("TAN");
	m_strStandardFunction.Add("ARCSIN");
	m_strStandardFunction.Add("ARCCOS");
	m_strStandardFunction.Add("INT");
	m_strStandardFunction.Add("RAD");
	m_strStandardFunction.Add("DEG");
	m_strStandardFunction.Add("ARCSINH");
	m_strStandardFunction.Add("ARCCOSH");
	m_strStandardFunction.Add("ARCTANH");
}

CFormulaParser::~CFormulaParser()
{

}

//////////////////////////////////////////////////////////////////////
// Methoden
//////////////////////////////////////////////////////////////////////

double CFormulaParser::SignFactor(WORD& nPosition, CString& strCharacter)
{
  if (strCharacter == "-")
	{
	  Char_n(nPosition, strCharacter);
    return (-1.0) * Factor(nPosition, strCharacter);
	}
  else return Factor(nPosition, strCharacter);
}

double CFormulaParser::Calculation(CString strFormula, WORD& ErrorPosition, CString& Errortext)
{
    WORD nPosition;
	CString strCharacter;
	double	ergebnis;
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


CString CFormulaParser::strChar_(WORD w)
{
    CString str;
    str.Format("%c", w);
    return str;
}


BOOL CFormulaParser::CheckParenthesis()
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

double CFormulaParser::Expression(WORD& nPosition, CString& strCharacter)
{
  CString strOperator;
  double erg = SimpleExpression(nPosition, strCharacter);
  while (strCharacter == "+" || strCharacter == "-")
  {
    strOperator = strCharacter;
    Char_n(nPosition, strCharacter);
    if (strOperator == "+")
		  erg += SimpleExpression(nPosition, strCharacter);
		else if (strOperator == "-")
		  erg -= SimpleExpression(nPosition, strCharacter);
	}
  return erg;
}

double CFormulaParser::SimpleExpression(WORD& nPosition, CString& strCharacter)
{
  double s,dum;
	CString strOperator;
  s = Term(nPosition, strCharacter);
  while (strCharacter == "*" || strCharacter == "/")
	{
    strOperator = strCharacter;
    Char_n(nPosition, strCharacter);
    if (strOperator == "*")
			s = s * Term(nPosition, strCharacter);
    else if (strOperator == "/") 
		{
			dum = Term(nPosition, strCharacter);
			if (dum != 0)  
				s = s / dum;
			else
				m_strErrortext = "division by zero";
		}  
	}
  return s;
}

double CFormulaParser::Term(WORD& nPosition, CString& strCharacter)
{
  double t,vz;
  t = SignFactor(nPosition, strCharacter);
  while (strCharacter == "^")
  {
	  Char_n(nPosition, strCharacter);
    vz = SignFactor(nPosition, strCharacter);
    
		if ((t <= 0 && fabs(vz) <= 1) || (t <= 0 && vz != int(vz)))
			m_strErrortext = "non-real result";
    else 
			t = pow(t,vz);		
	}
  return t;
}

double CFormulaParser::Char_n(WORD& nPosition, CString& strCharacter)
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

void CFormulaParser::SetFormula(CString Formula)
{
	m_strFormula = Formula;
}

CString CFormulaParser::GetFormula()
{
	return m_strFormula;
}

double CFormulaParser::Factor(WORD& nPosition, CString& strCharacter)
{
  double f = 0.0;
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
		f = atof(m_strFunction.Mid(wBeginn - 1, nPosition - wBeginn ));
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
		else if (strCharacter == "B")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[0];
		}
		else if (strCharacter == "F")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[1];
		}
		else if (strCharacter == "J")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[2];
		}
		else if (strCharacter == "K")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[3];
		}
		else if (strCharacter == "M")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[4];
		}
		else if (strCharacter == "N")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[5];
		}
		else if (strCharacter == "P")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[6];
		}
		else if (strCharacter == "Q")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[7];
		}
		else if (strCharacter == "X")	
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[8];
		}
		else if (strCharacter == "Y")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[9];
		}
		else if (strCharacter == "b")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[10];
		}
		else if (strCharacter == "f")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[11];
		}
		else if (strCharacter == "j")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[12];
		}
		else if (strCharacter == "k")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[13];
		}
		else if (strCharacter == "m")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[14];
		}
		else if (strCharacter == "n")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[15];
		}
		else if (strCharacter == "p")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[16];
		}
		else if (strCharacter == "q")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[17];
		}
		else if (strCharacter == "x")	
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[18];
		}
		else if (strCharacter == "y")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[19];
		}     
		else if (strCharacter == "z")
        {
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[20];
		}  
		else if (strCharacter == "C")
		{
			Char_n(nPosition, strCharacter);
			f = m_dFunctionConstant[21];
		}
		else
		{
			erfolg = false;
			int AnzStdFunctions = (int)m_strStandardFunction.GetSize() - 1;
			for (wI = 1; wI <= AnzStdFunctions; wI++)
			{
				if (!erfolg)
				{ 
					wL = m_strStandardFunction[wI].GetLength();
					CString strFunktionUpper = m_strFunction.Mid(nPosition - 1, wL);
					strFunktionUpper.MakeUpper();
					if (strFunktionUpper == m_strStandardFunction[wI])
					{
						nPosition = nPosition + wL - 1;
						Char_n(nPosition, strCharacter);
						f = Factor(nPosition, strCharacter);
						if (strFunktionUpper == "ABS")
							f = fabs(f);
						else if (strFunktionUpper == "SQRT")
							if (f >= 0)
								f = sqrt(f);
							else
								wError = -1;
						else if (strFunktionUpper == "SINH")
							f = sinh(f);
						else if (strFunktionUpper == "COSH")
							f = cosh(f);
						else if (strFunktionUpper == "TANH")
							f = tanh(f);
						else if (strFunktionUpper == "ARCTAN")
							f = atan(f);
						else if (strFunktionUpper == "LN")
						{
							if (f > 0)
								f = log(f);
							else
								wError = -1;
						}
						else if (strFunktionUpper == "LOG")
						{
							if (f > 0)
								f = log10(f);
							else
								wError = -1;
						}
						else if (strFunktionUpper == "EXP")
						{
							if (f <= 41)
								f = exp(f);
							else
								wError = -1;
						}
						else if (strFunktionUpper == "SIN")
							f = sin(f);
						else if (strFunktionUpper == "COS")
							f = cos(f);
						else if (strFunktionUpper == "TAN")
						{
							if (cos(f) != 0)
								f = tan(f);
							else 
								wError = -1;
						}
						else if (strFunktionUpper == "ARCSIN")
						{
							if (fabs(f) < 1) 
								f = asin(f);
							else
								wError = -1;
						}
						else if (strFunktionUpper == "ARCCOS")
						{
							if (fabs(f) <= 1)
								f = acos(f);
							else 
								wError = -1;
						}
						else if (strFunktionUpper == "INT") 
							f = int(f);
						else if (strFunktionUpper == "RAD") 
							f = MyRad(f);
						else if (strFunktionUpper == "DEG") 
							f = MyDeg(f);
						else if (strFunktionUpper == "ARCSINH") 
							f = MyArcsinh(f);
						else if (strFunktionUpper == "ARCCOSH")
						{
							if (f >= 1)
								f = MyArccosh(f);
							else 
								wError = -1;
						}					
						else if (strFunktionUpper == "ARCTANH")
						{
							if (fabs(f) < 1)
								f = MyArctanh(f);
							else 
								wError = -1;
						}
						erfolg = true;
					}
				}
			}
		}
	}
	
	if (wError == -1) 
		m_strErrortext = "an error was found -- check input for divide by zero and overflow errors)";

  return f;
}

void CFormulaParser::SetFunctConst(int index, double val)
{
	if (index >= 0 && index < ANZFUNKTKONST) 
		m_dFunctionConstant[index] = val;
	else
		CUtil::Fatal("Bad parameter to CFormulaParser::SetFunctConst");
}


double CFormulaParser::MyArcsinh(double dVal)
{
    return log(dVal + sqrt(dVal * dVal + 1.0));
}


double CFormulaParser::MyArccosh(double dVal)
{
    return log(dVal + sqrt(dVal * dVal - 1.0));
}


double CFormulaParser::MyArctanh(double dVal)
{
    return 0.5 * (log(1.0 + dVal) - log(1.0 - dVal));
}


double CFormulaParser::MyRad(double dVal)
{
    return dVal;
}


double CFormulaParser::MyDeg(double dVal)
{
    return dVal * (GetPi() / 180.0);
}


double CFormulaParser::GetPi(void)
{
    return 3.1415926535;
}
