#pragma once

#include "RexInterface.h"

// CFilterEdit
class CFilterEdit : public CEdit
{
	DECLARE_DYNAMIC (CFilterEdit)

public:
	CFilterEdit (/*const unsigned int uiMaxChars,*/
		const bool bProcessChars = true, REXI_Search *pRegEx = 0, REXI_Search *pRegEx2 = 0, REXI_Search *pRegEx3 = 0);
	virtual ~CFilterEdit ();
	bool SetRegEx (const TCHAR *pszRegEx);
	bool SetRegEx2 (const TCHAR *pszRegEx);
	bool SetRegEx3 (const TCHAR *pszRegEx);
	void SetAutoValidate (const bool bAutoValidate, const bool bModal);
	void SetShowInvalid (const bool bShowInvalid, const bool bSetBkOnError,
		const bool bWavyLineOnError);
	void SetBeepOnInvalid (const bool bBeepOnInvalid);
	void SetBackgroundColourOK (const COLORREF crFgOK);
	void SetForegroundColourOK (const COLORREF crBkOK);
	void SetBackgroundColourError (const COLORREF crFgError);
	void SetForegroundColourError (COLORREF crBkError);
	bool IsCharValid ();
	// Read this to further process text from derived class
	const CString &GetProposedText () const;
	bool IsInputValidSetError ();
	bool IsInputValid ();
	bool IsInputEmpty ();

protected:
	bool ValidateChar (UINT nChar);
	bool Match (const CString &strText);
	void ResetValid ();
	virtual LRESULT WindowProc (UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP ()
	afx_msg void OnChar (UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown (UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp (UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg HBRUSH CtlColor (CDC *pDC, UINT /*nCtlColor*/);
	afx_msg void OnKillFocus (CWnd *pNewWnd);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnKillFocusReflect();
	afx_msg BOOL OnSetFocusReflect();

private:
	// Set this to false to call CEdit::OnChar in derived class
//	unsigned int m_uiMaxChars;
	bool m_bProcessChars;
	REXI_Search *m_pRegEx;
	REXI_Search *m_pRegEx2;
	REXI_Search *m_pRegEx3;
	bool m_bRegExOwner;
	bool m_bRegExOwner2;
	bool m_bRegExOwner3;

	// Does the text completely match the regex
	bool m_bValid;
	// Set to true or false each time a char is typed
	// (read from derived class
	bool m_bCharValid;
	// Latest proposed string (can be read by a derived class)
	CString m_strProposedText;

	// These two flags go together
	bool m_bAutoValidate;
	bool m_bModal;

	// These three flags go together
	bool m_bShowInvalid;
	bool m_bSetBkOnError;
	bool m_bWavyLineOnError;

	bool m_bBeepOnInvalid;

	bool m_bControlDown;

	COLORREF m_crFgOK;
	COLORREF m_crBkOK;
	COLORREF m_crFgError;
	COLORREF m_crBkError;
	COLORREF m_crDisabled;
	CBrush m_brOK;
	CBrush m_brError;
	CBrush m_brDisabled;

	bool CanDelete ();
	bool CanPaste ();

	CFilterEdit (CFilterEdit const &); // No copy construction.
    CFilterEdit& operator = (CFilterEdit const &); // No assignment.
};
