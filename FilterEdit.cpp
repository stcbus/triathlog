// FilterEdit.cpp : implementation file
//

#include "stdafx.h"
#include <afxtempl.h>
#include "Course.h"
#include "CourseRun.h"
#include "CourseSwim.h"
#include "CourseBike.h"
#include "CourseDuathlon.h"
#include "CourseTriathlon.h"
#include "Location.h"
#include "LocationRun.h"
#include "LocationBike.h"
#include "LocationSwim.h"
#include "LocationStrength.h"
#include "Shoes.h"
#include "ShoesRun.h"
#include "ShoesBike.h"
#include "Workout.h"
#include "DayLog.h"
#include "RunningLog.h"
#include "Util.h"
#include "Bike.h"
#include "UpcomingWorkout.h"
#include "UpcomingRace.h"
#include "User.h"
#include "FilterEdit.h"

extern CUser* g_pUser;
// NOTE: Be very careful how you specify your regular expressions.
// For strictly formatted data, you will want a rigid regex
// and rely on automatic formatting in a derived class to make
// data entry easier (see the CDateEdit example to see this approach
// in action). For easier validations (say unsigned int) a much looser
// regex can be used without problems.

// CFilterEdit
IMPLEMENT_DYNAMIC (CFilterEdit, CEdit)
CFilterEdit::CFilterEdit (/*const unsigned int uiMaxChars,*/
	const bool bProcessChars/* = true*/, REXI_Search *pRegEx/* = 0*/, REXI_Search *pRegEx2 /* = 0 */, REXI_Search *pRegEx3 /* = 0 */) :
//	m_uiMaxChars (uiMaxChars),
	m_bProcessChars (bProcessChars),
	m_pRegEx (pRegEx),
	m_pRegEx2 (pRegEx2),
	m_pRegEx3 (pRegEx3),
	m_bRegExOwner (false),
	m_bRegExOwner2 (false),
	m_bRegExOwner3 (false),
	m_bValid (true),
	m_bCharValid (false),
	m_bAutoValidate (true),
	m_bModal (false),
	m_bShowInvalid (true),
	m_bSetBkOnError (false),
	m_bWavyLineOnError (true),
	m_bBeepOnInvalid (false),
	m_bControlDown (false),
	m_crFgOK (RGB (0, 0, 0)),
	m_crBkOK (RGB (255, 255 , 255)),
	m_crFgError (RGB (255, 0, 0)),
	m_crBkError (RGB (228, 249, 190))
{
	if (m_pRegEx == 0)
	{
		m_pRegEx = new REXI_Search;

		if (m_pRegEx == 0)
		{
			AfxThrowMemoryException ();
		}
		else
		{
			m_bRegExOwner = true;
		}
	}

	if (m_pRegEx2 == 0)
	{
		m_pRegEx2 = new REXI_Search;

		if (m_pRegEx2 == 0)
		{
			AfxThrowMemoryException ();
		}
		else
		{
			m_bRegExOwner2 = true;
		}
	}

	if (m_pRegEx3 == 0)
	{
		m_pRegEx3 = new REXI_Search;

		if (m_pRegEx3 == 0)
		{
			AfxThrowMemoryException ();
		}
		else
		{
			m_bRegExOwner3 = true;
		}
	}

	if(NULL != g_pUser)
	{
		m_crBkError = g_pUser->GetEditBgColor();
	}
	else
	{
		m_crBkError = CUtil::GetDefaultEditBgColor();
	}

	m_crDisabled = RGB(233, 236, 216);

	m_brDisabled.CreateSolidBrush(m_crDisabled);

	m_brOK.CreateSolidBrush (m_crBkOK);
	m_brError.CreateSolidBrush (m_crBkError);
}

CFilterEdit::~CFilterEdit ()
{
	if (m_bRegExOwner)
	{
		delete m_pRegEx;
		m_pRegEx = 0;
	}	
	if (m_bRegExOwner2)
	{
		delete m_pRegEx2;
		m_pRegEx2 = 0;
	}
	if (m_bRegExOwner3)
	{
		delete m_pRegEx3;
		m_pRegEx3 = 0;
	}
}

// TODO:
// Tooltip with friendly description of format.
bool CFilterEdit::SetRegEx (const TCHAR *pszRegEx)
{
	bool bSuccess = m_bRegExOwner;

	if (bSuccess)
	{
		REXI_DefErr Err = m_pRegEx->SetRegexp (pszRegEx);
		//eErrCode {eNoErr,eErrInName,eErrInRegExp}, strErrMsg, nErrOffset

		bSuccess = Err.eErrCode == REXI_DefErr::eNoErr;
	}

	return bSuccess;
}


bool CFilterEdit::SetRegEx2 (const TCHAR *pszRegEx)
{
	bool bSuccess = m_bRegExOwner2;

	if (bSuccess)
	{
		REXI_DefErr Err = m_pRegEx2->SetRegexp (pszRegEx);
		//eErrCode {eNoErr,eErrInName,eErrInRegExp}, strErrMsg, nErrOffset

		bSuccess = Err.eErrCode == REXI_DefErr::eNoErr;
	}

	return bSuccess;
}


bool CFilterEdit::SetRegEx3 (const TCHAR *pszRegEx)
{
	bool bSuccess = m_bRegExOwner3;

	if (bSuccess)
	{
		REXI_DefErr Err = m_pRegEx3->SetRegexp (pszRegEx);
		//eErrCode {eNoErr,eErrInName,eErrInRegExp}, strErrMsg, nErrOffset

		bSuccess = Err.eErrCode == REXI_DefErr::eNoErr;
	}

	return bSuccess;
}


void CFilterEdit::SetAutoValidate (const bool bAutoValidate, const bool bModal)
{
	m_bAutoValidate = bAutoValidate;
	m_bModal = bModal;
}

void CFilterEdit::SetShowInvalid (const bool bShowInvalid,
	const bool bSetBkOnError, const bool bWavyLineOnError)
{
	m_bShowInvalid = bShowInvalid;
	m_bSetBkOnError = bSetBkOnError;
	m_bWavyLineOnError = bWavyLineOnError;

	// Sanity Check: There is no point in setting both error
	// display types to false if bShowInvalid is true.
	if (m_bShowInvalid && !m_bSetBkOnError && !m_bWavyLineOnError)
	{
		m_bWavyLineOnError = true;
	}
}

void CFilterEdit::SetBeepOnInvalid (const bool bBeepOnInvalid)
{
	m_bBeepOnInvalid = bBeepOnInvalid;
}

void CFilterEdit::SetBackgroundColourOK (const COLORREF crBkOK)
{
	m_crBkOK = crBkOK;
	m_brOK.DeleteObject ();
	m_brOK.CreateSolidBrush (m_crBkOK);
}

void CFilterEdit::SetForegroundColourOK (const COLORREF crFgOK)
{
	m_crFgOK = crFgOK;
}

void CFilterEdit::SetBackgroundColourError (COLORREF crBkError)
{
	m_crBkError = crBkError;
	m_brError.DeleteObject ();
	m_brError.CreateSolidBrush (m_crBkError);
}

void CFilterEdit::SetForegroundColourError (const COLORREF crFgError)
{
	m_crFgError = crFgError;
}

bool CFilterEdit::IsCharValid ()
{
	return m_bCharValid;
}

const CString &CFilterEdit::GetProposedText () const
{
	return m_strProposedText;
}

bool CFilterEdit::IsInputValid()
{
	if(!::IsWindow(m_hWnd))
	{
		return false;
	}

	CString str;
	const TCHAR *psz = 0;
	const TCHAR *psz2 = 0;
	const TCHAR *psz3 = 0;
	int iLen = 0;
	int iLen2 = 0;
	int iLen3 = 0;
	bool bEos;
	bool bEos2;
	bool bEos3;

	bool bOk;
	bool bOk2;
	bool bOk3;

	GetWindowText (str);
	psz = str;
	psz2 = str;
	psz3 = str;
	bOk = m_pRegEx->MatchHere (psz, iLen, bEos) && bEos;
	bOk2 = m_pRegEx2->MatchHere (psz2, iLen2, bEos2) && bEos2;
	bOk3 = m_pRegEx3->MatchHere (psz3, iLen3, bEos3) && bEos3;

	return (bOk || bOk2 || bOk3);
}


bool CFilterEdit::IsInputValidSetError()
{
	if(!::IsWindow(m_hWnd))
	{
		return false;
	}

	CString str;
	const TCHAR *psz = 0;
	const TCHAR *psz2 = 0;
	const TCHAR *psz3 = 0;
	int iLen = 0;
	int iLen2 = 0;
	int iLen3 = 0;
	bool bEos;
	bool bEos2;
	bool bEos3;

	bool bOk;
	bool bOk2;
	bool bOk3;

	GetWindowText (str);
	psz = str;
	psz2 = str;
	psz3 = str;
	bOk = m_pRegEx->MatchHere (psz, iLen, bEos) && bEos;
	bOk2 = m_pRegEx2->MatchHere (psz2, iLen2, bEos2) && bEos2;
	bOk3 = m_pRegEx3->MatchHere (psz3, iLen3, bEos3) && bEos3;

	m_bValid = (bOk || bOk2 || bOk3);

	Invalidate ();

	if (!m_bValid && m_bBeepOnInvalid)
	{
		::MessageBeep (MB_ICONEXCLAMATION);
	}

	return m_bValid;
}


bool CFilterEdit::IsInputEmpty ()
{	
	if(!::IsWindow(m_hWnd))
	{
		return false;
	}

	CString str;
	GetWindowText(str);

	return str.IsEmpty();
}


BEGIN_MESSAGE_MAP (CFilterEdit, CEdit)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_KILLFOCUS()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT_EX(EN_KILLFOCUS, OnKillFocusReflect)
	ON_CONTROL_REFLECT_EX(EN_SETFOCUS, OnSetFocusReflect)
END_MESSAGE_MAP()

bool CFilterEdit::ValidateChar (UINT nChar)
{
	int iStartIndex = -1;
	int iEndIndex = -1;
	bool bCharValid = true;

	GetSel (iStartIndex, iEndIndex);
	GetWindowText (m_strProposedText);

	if (nChar == VK_BACK)
	{
		if (iStartIndex == iEndIndex)
		{
			iStartIndex--;
		}

		// remove char
		m_strProposedText.Delete (iStartIndex, iEndIndex - iStartIndex);
		bCharValid = Match (m_strProposedText);
	}
	else
	{
		// haven't reached text limit
		m_strProposedText.Delete (iStartIndex, iEndIndex - iStartIndex);
		m_strProposedText.Insert (iStartIndex, static_cast<TCHAR> (nChar));
		bCharValid = Match (m_strProposedText);
	}

	return bCharValid;
}

bool CFilterEdit::Match (const CString &strText)
{
	bool bSuccess = true;
	bool bSuccess2 = true;
	bool bSuccess3 = true;

	const TCHAR *psz = strText;
	const TCHAR *psz2 = strText;
	const TCHAR *psz3 = strText;
	int iLen = 0;
	int iLen2 = 0;
	int iLen3 = 0;
	bool bEos = false;
	bool bEos2 = false;
	bool bEos3 = false;

	bSuccess = m_pRegEx->MatchHere (psz, iLen, bEos);

	if (bSuccess)
	{
		bSuccess = bEos;
	}
	else
	{
		// A failed match that consumed all the input
		// characters is a success.
		bSuccess = !*psz;
	}

	bSuccess2 = m_pRegEx2->MatchHere (psz2, iLen2, bEos2);

	if (bSuccess2)
	{
		bSuccess2 = bEos2;
	}
	else
	{
		// A failed match that consumed all the input
		// characters is a success.
		bSuccess2 = !*psz2;
	}

	bSuccess3 = m_pRegEx3->MatchHere (psz3, iLen3, bEos3);

	if (bSuccess3)
	{
		bSuccess3 = bEos3;
	}
	else
	{
		// A failed match that consumed all the input
		// characters is a success.
		bSuccess3 = !*psz3;
	}

	return (bSuccess || bSuccess2 || bSuccess3);
}


void CFilterEdit::ResetValid ()
{
	if (!m_bValid)
	{
		m_bValid = true;
		Invalidate ();
	}
}


LRESULT CFilterEdit::WindowProc (UINT message, WPARAM wParam, LPARAM lParam)
{
	bool bExecute = true;
	bool bResetValid = false;
	LRESULT lResult = 0;

	if (m_bProcessChars)
	{
		switch (message)
		{
			case EM_REPLACESEL:
			{
				int iStartIndex = -1;
				int iEndIndex = -1;
				CString strReplace;

				GetSel (iStartIndex, iEndIndex);
				strReplace = reinterpret_cast<LPCTSTR> (lParam);
				GetWindowText (m_strProposedText);
				m_strProposedText.Delete (iStartIndex, iEndIndex - iStartIndex);
				m_strProposedText.Insert (iStartIndex, strReplace);
				// Don't set m_bCharValid as OnChar not called
				bExecute = Match (m_strProposedText);
				bResetValid = bExecute;
				break;
			}
	/*
			case EM_SETLIMITTEXT:
				m_uiMaxChars = static_cast<unsigned int> (wParam);
				break;
	*/

			case WM_CLEAR:
				bExecute = CanDelete ();
				bResetValid = bExecute;
				break;

			case WM_CUT:
				bExecute = CanDelete ();
				bResetValid = bExecute;
				break;

			case WM_PASTE:
				bExecute = CanPaste ();
				bResetValid = bExecute;
				break;

			case WM_SETTEXT:
			{
				const TCHAR *psz = reinterpret_cast<const TCHAR *>
					(lParam);

				bExecute = Match (psz);
				bResetValid = bExecute;
				break;
			}

			default:
				break;
		}
	}

	if (bExecute)
	{
		lResult = CEdit::WindowProc (message, wParam, lParam);

		if (bResetValid)
		{
			ResetValid ();
		}
	}

	return lResult;
}

bool CFilterEdit::CanDelete ()
{
	CString strText;
	int iStartIndex = -1;
	int iEndIndex = -1;

	GetWindowText (strText);
	GetSel (iStartIndex, iEndIndex);

	if (iStartIndex == iEndIndex)
	{
		iEndIndex++;
	}

	strText.Delete (iStartIndex, iEndIndex - iStartIndex);
	return Match (strText);
}

bool CFilterEdit::CanPaste ()
{
	bool bSuccess = OpenClipboard () != 0;

	if (bSuccess)
	{
#ifdef _UNICODE
		HANDLE hClipMem = ::GetClipboardData (CF_UNICODETEXT);
#else
		HANDLE hClipMem = ::GetClipboardData (CF_TEXT);
#endif

		bSuccess = hClipMem != 0;

		if (bSuccess)
		{
			const TCHAR *lpClipMem = (const TCHAR *) ::GlobalLock (hClipMem);

			bSuccess = lpClipMem != 0;

			if (bSuccess)
			{
				CString strClipText;
				CString strText;
				int iStartIndex = -1;
				int iEndIndex = -1;

				strClipText.Format (_T("%s"), lpClipMem);
				GetWindowText (strText);
				GetSel (iStartIndex, iEndIndex);
				strText.Delete (iStartIndex, iEndIndex - iStartIndex);
				strText.Insert (iStartIndex, strClipText);

				if (strText.GetLength () > static_cast<int> (GetLimitText ()))
//				if (strText.GetLength () > static_cast<int> (m_uiMaxChars))
				{
					strText = strText.Left (GetLimitText ());
//					strText = strText.Left (m_uiMaxChars);
				}

				bSuccess = Match (strText);
				::GlobalUnlock (hClipMem);
			}
		}

		::CloseClipboard ();
	}

	return bSuccess;
}

void CFilterEdit::OnChar (UINT nChar, UINT nRepCnt, UINT nFlags)
{
	m_bCharValid = !m_bProcessChars || ValidateChar (nChar);

	if (m_bCharValid)
	{
		CEdit::OnChar (nChar, nRepCnt, nFlags);
	}

	//IsInputValid();
}

void CFilterEdit::OnKeyDown (UINT nChar, UINT nRepCnt, UINT nFlags)
{
	bool bExecute = true;

	ResetValid();

	if (nChar == VK_CONTROL)
	{
		m_bControlDown = true;
	}
	else if (nChar == VK_DELETE)
	{
		if (m_bProcessChars)
		{
			bExecute = CanDelete ();
		}
	}
	else if ((nChar == 'x' || nChar == 'X') && m_bControlDown)
	{
		if (m_bProcessChars)
		{
			bExecute = CanDelete ();

			if (bExecute)
			{
				// Will handle cut ourselves, so don't pass char on...
				bExecute = false;
				SendMessage (WM_CUT, 0, 0);
			}
		}
	}
	// Test for Paste keyboard short-cut
	else if ((nChar == 'v' || nChar == 'V') && m_bControlDown)
	{
		SendMessage (WM_PASTE, 0, 0); 
	}

	if (bExecute)
	{
		CEdit::OnKeyDown (nChar, nRepCnt, nFlags);
	}
}

void CFilterEdit::OnKeyUp (UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_CONTROL)
	{
		m_bControlDown = false;
	}

	CEdit::OnKeyUp (nChar, nRepCnt, nFlags);
}

// the below is somewhat taken from James Twine's FocusEditCtrl example

HBRUSH CFilterEdit::CtlColor (CDC *pDC, UINT /*nCtlColor*/)
{
	HBRUSH hbr = m_brOK;

	/*
	// If m_bSetBkOnError is not set, then
	// use the 'OK' colours to draw anyway.
	if (m_bValid || !m_bSetBkOnError)
	{
		pDC->SetBkColor (m_crBkOK);
		pDC->SetTextColor (m_crFgOK);
	}
	else if (m_bShowInvalid && m_bSetBkOnError)
	{
		// If m_bSetBkOnError is set, then change
		// all the colours.
		hbr = m_brError;
		pDC->SetBkColor (m_crBkError);
		pDC->SetTextColor (m_crFgError);
	}
	*/
	DWORD	dwStyle = GetStyle();

	if( ( GetFocus() == this ) && ( !( dwStyle &			// If We Have The Focus
			WS_DISABLED ) ) && ( !( dwStyle & 				// And Control Is Not Disabled
			ES_READONLY ) ) )								// And Control Is Not ReadOnly
	{
		pDC -> SetBkColor( m_crBkError );					// Set Background Color

		return( (HBRUSH)m_brError );						// Return Custom BG Brush
	}

	else if(dwStyle & WS_DISABLED)
	{
		pDC->SetBkColor(m_crDisabled);
	
		return (HBRUSH)m_brDisabled;
	}

	return hbr;
}

void CFilterEdit::OnKillFocus (CWnd *pNewWnd)
{
	bool bValid = true;

	if (m_bAutoValidate)
	{
		// Don't beep on exit...
		if (pNewWnd && pNewWnd != GetParent () &&
			pNewWnd->GetDlgCtrlID () != IDCANCEL)
		{
			bValid = IsInputValidSetError ();
		}
		else
		{
			bValid = true;
		}
	}

	if (bValid || !m_bModal)
	{
		Invalidate();
		CEdit::OnKillFocus (pNewWnd);
	}
	else
	{
		SetFocus ();
	}
}


BOOL CFilterEdit::OnEraseBkgnd(CDC* pDC) 
{
	DWORD	dwStyle = GetStyle();
	CRect	rClient;
	BOOL	bStatus = TRUE;

	if( ( GetFocus() == this ) && ( !( dwStyle &			// If We Have The Focus
			WS_DISABLED ) ) && ( !( dwStyle & 				// And Control Is Not Disabled
			ES_READONLY ) ) )								// And Control Is Not ReadOnly
	{
		GetClientRect( &rClient );							// Get Our Area
		pDC -> FillSolidRect( rClient, m_crBkError );		// Repaint Background
	}
	else
	{
		bStatus = CEdit::OnEraseBkgnd( pDC );				// Do Default
	}
	return( bStatus );										// Return Status
}


BOOL	CFilterEdit::OnKillFocusReflect( void ) 
{
	Invalidate();											// Cause Background To Repaint

	return( FALSE );											// Pass On To Parent
}


BOOL	CFilterEdit::OnSetFocusReflect() 
{
	Invalidate();											// Cause Background To Repaint

	return( FALSE );											// Pass On To Parent
}


void CFilterEdit::OnPaint ()
{
	CClientDC dc (this);

	//  This stops the control from going grey
	Default ();

	if (!m_bValid && m_bShowInvalid && m_bWavyLineOnError)
	{
		CFont *pFont = GetFont ();
		CPen *pPen = dc.GetCurrentPen ();
		LOGPEN lp;
		CPen MyPen;
		CRect rect;
		CString strText;
		CSize size;
		int iX = 0;
		const int iIncrement = 2;

		// We must use the correct font when using GetTextExtent..!
		dc.SelectObject (pFont);
		// We have to create a new pen to set a new colour...
		pPen->GetLogPen (&lp);
		lp.lopnColor = m_crFgError;
		MyPen.CreatePenIndirect (&lp);
		dc.SelectObject (&MyPen);
		// Get the rect for the entire edit control
		GetRect (&rect);
		rect.bottom -= 1;
		GetWindowText (strText);
		// This part deals with the *displayed* Text Extent
		size = dc.GetTextExtent (strText.
			Mid (CharFromPos (CPoint (rect.left + 1, rect.top))));

		// Check for case of empty string
		if (size.cx == 0) return;
		// Dont draw off the end of the edit control
		else if (size.cx > rect.right) size.cx = rect.right;

		// Starting x co-ordinate to start drawing from
		iX = rect.left;
		// Start at the bottom left of the edit control
		dc.MoveTo (rect.left, rect.bottom);

		// Draw the wavy line like in Microsoft Word
		while (iX < size.cx + rect.left)
		{
			iX += iIncrement;

			if (iX > size.cx + rect.left) break;

			dc.LineTo (iX, rect.bottom + iIncrement);
			iX += iIncrement;

			if (iX > size.cx + rect.left) break;

			dc.LineTo (iX, rect.bottom);
		}
	}

	// Do not call CEdit::OnPaint() for painting messages
}
