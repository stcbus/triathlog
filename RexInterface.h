#ifndef REX_INTERFACE_INCLUDED_
#define REX_INTERFACE_INCLUDED_

#include "RexAlgorithm.h"

#ifdef _UNICODE
#define _CHAR TCHAR
#else
#define _CHAR unsigned char
#endif

struct REXI_DefErr{
        enum{eNoErr,eErrInName,eErrInRegExp} eErrCode;
        TString  strErrMsg;
        int     nErrOffset;
};

class REXI_Base{
public:

	REXI_Base(TCHAR cEos='\0');
    virtual ~REXI_Base()=0;

    inline void			SetSource			(const TCHAR* pszSource);
    inline const TCHAR*  GetSource    ()const;

    
    REXI_DefErr          AddRegDefinition    (TString strName,TString strRegExp,
                                            int nIdAnswer);
    void            GetRegDefinitions   (vector<TString>& vecDefinitions);
    void            RemoveRegDefinition (TString strName);

	REXI_DefErr			SetRegexp			(TString strRegExp);


protected:

    inline void FreeMemory    ();          

//source,source position and end of string character
	TCHAR				m_cEos;
	const TCHAR*			m_pszSource;
    const TCHAR*         m_pszTokenBeg;
    const TCHAR*         m_pszTokenEnd;

//algorithmic objects
	REXA_Parser		    m_regexpParser;

	REXA_DFAState*      m_pStartState;

};

class REXI_Search : public REXI_Base
{ 
public:
    REXI_Search(TCHAR cEos='\0');

    REXI_DefErr
            AddRegDef   (TString strName,TString strRegExp);
    inline  REXI_DefErr  
            SetRegexp	(TString strRegExp);
    bool    MatchHere   (const TCHAR*& rpcszSrc, int& nMatchLen,bool& bEos);
    bool    Find        (const TCHAR*& rpcszSrc, int& nMatchLen,bool& bEos);
private:
    bool    MatchHereImpl();
    int     m_nIdAnswer;
};

inline const TCHAR*     REXI_Base::GetSource()const  {return m_pszSource;}
inline void			   REXI_Base::SetSource(const TCHAR* pszSource)
{
    m_pszSource= pszSource;m_pszTokenBeg= m_pszTokenEnd=pszSource;
}
inline REXI_DefErr	        REXI_Search::SetRegexp	(TString strRegExp)
{
    return REXI_Base::SetRegexp(strRegExp);
}
inline void             REXI_Base::FreeMemory()     {m_pStartState->DeleteAll();}
#endif
