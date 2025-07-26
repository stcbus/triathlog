#include "stdafx.h"

#include "RexInterface.h"

REXI_Base::REXI_Base(TCHAR cEos)
:m_cEos(cEos),m_pszSource(_T("")),m_pszTokenBeg(_T("")),m_pszTokenEnd(_T(""))
,m_pStartState(REXA_DFAState::ms_pEosState)
{
}
REXI_Base::~REXI_Base()
{
    FreeMemory();
}
REXI_DefErr   REXI_Base::AddRegDefinition    (TString strName,TString strRegExp,
                                            int nIdAnswer)
{
    REXI_DefErr defErr;
    defErr.eErrCode=REXI_DefErr::eNoErr;
    defErr.strErrMsg=_T("");
    defErr.nErrOffset=0;
    try{
        m_regexpParser.AddRegDefinition(strName,strRegExp,nIdAnswer);
    }catch(REXA_Exception e){
        defErr.strErrMsg= e.m_strErrMsg;
        if( e.m_nErrPos>strName.size()+1){
            defErr.eErrCode= REXI_DefErr::eErrInRegExp;
            defErr.nErrOffset= e.m_nErrPos-(strName.size()+1);
        }else{
            defErr.eErrCode=REXI_DefErr::eErrInName;
            defErr.nErrOffset= e.m_nErrPos;
        }
    }
    return defErr;
}
void REXI_Base::GetRegDefinitions (vector<TString>& vecDefinitions)
{
    m_regexpParser.GetRegDefinitions (vecDefinitions);
}
void REXI_Base::RemoveRegDefinition (TString strName)
{
    m_regexpParser.RemoveRegDefinition (strName);
}


REXI_DefErr REXI_Base::SetRegexp (TString strRegExp)
{
    REXI_DefErr defErr;
    defErr.eErrCode=REXI_DefErr::eNoErr;
    defErr.strErrMsg=_T("");
    defErr.nErrOffset=0;
    try{
        REXA_DFAState *pStartState = m_regexpParser.ParseRegExp (strRegExp);
        FreeMemory();
        m_pStartState = pStartState;
    }catch (REXA_Exception e){
        defErr.eErrCode=REXI_DefErr::eErrInRegExp;
        defErr.strErrMsg= e.m_strErrMsg;
        defErr.nErrOffset= e.m_nErrPos;
    }
    return defErr;
}	


REXI_Search::REXI_Search(TCHAR cEos)
:REXI_Base(cEos),m_nIdAnswer(0)
{
}
REXI_DefErr  REXI_Search::AddRegDef(TString strName,TString strRegExp)
{
     return REXI_Base::AddRegDefinition(strName,strRegExp,m_nIdAnswer++);
}
bool REXI_Search::MatchHereImpl()
{
	if (!m_pStartState) return false;

	m_pszTokenBeg= m_pszTokenEnd;

    const REXA_DFAState* pState= m_pStartState;
    const TCHAR* pAccept=0;
	while( !(pState= pState->
                        aNext[*(_CHAR *)m_pszTokenEnd])->m_bIsFinal){
		m_pszTokenEnd++;
		if(pState->m_bIsAccepting){
            pAccept= m_pszTokenEnd;
        }
	}
//	m_pszTokenEnd--;
    if(!pState->m_bIsAccepting  ){
        if( pAccept ){
            m_pszTokenEnd= pAccept;
            return true;
        }
        return false;
    }
    return true;
}
bool REXI_Search::MatchHere(const TCHAR*& rpcszSrc, int& nMatchLen,bool& bEos)
{
    SetSource(rpcszSrc);
    bool bFound= MatchHereImpl();
    nMatchLen= static_cast<int> (m_pszTokenEnd-m_pszTokenBeg);
    rpcszSrc= m_pszTokenEnd;
    bEos= (*m_pszTokenEnd==m_cEos);
    rpcszSrc= m_pszTokenEnd;
    return bFound;
}

bool REXI_Search::Find(const TCHAR*& rpcszSrc, int& nMatchLen,bool& bEos)
{
    bool bFound;
    SetSource(rpcszSrc);
    for(;;){
        while(m_pStartState->aNext[*(_CHAR *)m_pszTokenEnd]==
                                                REXA_DFAState::ms_pIllegalState ){
            m_pszTokenEnd++;
        }
        if( MatchHereImpl() ){
            bFound= true;
            break;
        }
        bEos= (*m_pszTokenEnd==m_cEos);
        if( bEos ){
            bFound= false;
            break;
        }
        m_pszTokenEnd= m_pszTokenBeg+1;
    }
    bEos= (*m_pszTokenEnd==m_cEos);
    nMatchLen= static_cast<int> (m_pszTokenEnd-m_pszTokenBeg);
    rpcszSrc= m_pszTokenEnd;
	return bFound;
}