#ifndef REX_ALGORITHM_INCLUDED_
#define REX_ALGORITHM_INCLUDED_

#pragma warning(disable:4786)
#pragma warning(disable:4503)
#include <utility>
#include <vector>
#include <set>
#include <string>
using namespace std;

typedef basic_string<TCHAR> TString;

struct REXA_DFAState{
    enum{eEos=-1,eNoAnswer=-2,eAccepting=-3};
    REXA_DFAState(int nAnwserId=eNoAnswer,bool bIsFinal=false);
    static void			CollectStates   (REXA_DFAState* pState,
											set<REXA_DFAState*>& rsetStates);
    void				DeleteAll();
	REXA_DFAState*	aNext[256 * sizeof (TCHAR)];
	int 		m_nAnwserId;
	bool 		m_bIsFinal;
    bool        m_bIsAccepting;
    static REXA_DFAState* ms_pIllegalState;
    static REXA_DFAState* ms_pEosState;
};





#if 0

$2 RegExp= Term {"|" Term}.
$3 Term= Factor {Factor}.
$4 Factor= Atom ["*"|"+"|"?"].
$5 Atom= "[" REXA_CharSet "]" | Ident | "(" RegExp ").
$6 REXA_CharSet= <Zeichenketten, Metazeichen sind ^(Komplement),-(Range-Zeichen),
	\ als Escapezeichen fuer Metazeichen, . (bedeutet alle Zeichen.

#endif



enum REXA_ESymbols{
	eEof=1,
	eIllegal=2,
	eIdent=4,
	eStar=32,
	ePlus=64,
    eAssign=128,
	eOpt=256,
	eAlternative=512,
	eCharSet=1024,
	eLParen=2048,
	eRParen=4096,
    eIgnoreCase=8192
};


typedef pair<const TCHAR*,const TCHAR*> REXA_BegEnd;

class REXA_Exception{
public:
    REXA_Exception(
        const TCHAR* pPos,
        const TCHAR* pRegExp,
        TString strMsg);
	REXA_Exception(
		REXA_ESymbols eExpectedSymbol,
		REXA_BegEnd    token,
		const TCHAR*   pRegExp,
		TString		  strMsg=_T(""));

	TString      m_strErrMsg;
    unsigned int         m_nErrPos;
};
class REXA_Parser{
public:
    REXA_Parser     (TCHAR cEos=0);
    ~REXA_Parser    ();

    REXA_DFAState*      ParseRegExp     (TString strRegExp);
    void                AddRegDefinition (   TString strDefName,
                                                TString strDefExpression,
                                                int nAnswer);
    void                RemoveRegDefinition (   TString strDefName);
    void                GetRegDefinitions   (vector<TString>& vecDefinitions); 
private:
    class REXA_ParserImpl*   m_pParserImp;
};

#endif


