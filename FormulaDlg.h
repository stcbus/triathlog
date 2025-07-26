#if !defined(AFX_SIMPLEXPARSERDLG_H__98EEC303_BFC2_11D1_B0F3_08002BBFDDC1__INCLUDED_)
#define AFX_SIMPLEXPARSERDLG_H__98EEC303_BFC2_11D1_B0F3_08002BBFDDC1__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SimplexParserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFormulaDlg dialog

class CFormulaDlg : public CAniDialog
{
// Construction
public:
	CFormulaDlg(CWnd* pParent = NULL);   // standard constructor

	enum { IDD = IDD_FORMULADLG };
	CString	m_strFormulainput;

	CString	m_strFormulainput_vorher;
	CString m_strFileName;
    CEdit m_EditInputControl; 

    CString GetFormula(void) const;
    
// Overrides
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog(void);

// Implementation
protected:
    bool IsOwnChange(void) const;
    void UpdateOKButton(void);

	void SetEingabe(CString str);
	void SaveParameter();
	void LoadParameter();

	// Generated message map functions
    afx_msg void OnFormulaChanged(void);
	afx_msg void OnClickedNumber(UINT nID);
	afx_msg void OnSin();
	afx_msg void OnPlus();
	afx_msg void OnMinus();
	afx_msg void OnMal();
	afx_msg void OnGeteilt();
	afx_msg void OnHoch();
	afx_msg void OnPkt();
	afx_msg void OnKlammerAuf();
	afx_msg void OnKlammerZu();
	afx_msg void OnArcsin();
	afx_msg void OnSinh();
	afx_msg void OnArsinh();
	afx_msg void OnCos();
	afx_msg void OnArccos();
	afx_msg void OnCosh();
	afx_msg void OnArcosh();
	afx_msg void OnTan();
	afx_msg void OnArctan();
	afx_msg void OnTanh();
	afx_msg void OnArtanh();
	afx_msg void OnExp();
	afx_msg void OnLn();
	afx_msg void OnInt();
	afx_msg void OnAbs();
	afx_msg void On10x();
	afx_msg void OnLog();
    afx_msg void OnPi();
	afx_msg void OnRad();
	afx_msg void OnDeg();
	afx_msg void OnX2();
	afx_msg void OnSqr();
	afx_msg void OnDelete();
	afx_msg void OnUndo();
	afx_msg void OnB();
	afx_msg void OnF();
	afx_msg void OnJ();
	afx_msg void OnK();
	afx_msg void OnM();
	afx_msg void OnN();
	afx_msg void OnP();
	afx_msg void OnQ();
	afx_msg void OnX();
	afx_msg void OnY();
	afx_msg void OnC();
	afx_msg void OnBLower();
	afx_msg void OnFLower();
	afx_msg void OnJLower();
	afx_msg void OnKLower();
	afx_msg void OnMLower();
	afx_msg void OnNLower();
	afx_msg void OnPLower();
	afx_msg void OnQLower();
	afx_msg void OnXLower();
	afx_msg void OnYLower();
    afx_msg void OnZLower();    
	afx_msg void OnSaveParameter();
	afx_msg void OnLoadParameter();
    
	DECLARE_MESSAGE_MAP()
    
    // data
    COLORREF m_crNum;
    COLORREF m_crFunc;
    COLORREF m_crParam;
    COLORREF m_crOther;
    COLORREF m_crHot;
	CButtonST m_btn0;
 	CButtonST m_btn1;
	CButtonST m_btn2;
	CButtonST m_btn3;
	CButtonST m_btn4;
	CButtonST m_btn5;
	CButtonST m_btn6;
	CButtonST m_btn7;
	CButtonST m_btn8;
	CButtonST m_btn9;    
	CButtonST m_btnSin;
	CButtonST m_btnPlus;
	CButtonST m_btnMinus;
	CButtonST m_btnMal;
	CButtonST m_btnGeteilt;
	CButtonST m_btnHoch;
	CButtonST m_btnPkt;
	CButtonST m_btnKlammerAuf;
	CButtonST m_btnKlammerZu;
	CButtonST m_btnArcsin;
	CButtonST m_btnSinh;
	CButtonST m_btnArsinh;
	CButtonST m_btnCos;
	CButtonST m_btnArccos;
	CButtonST m_btnCosh;
	CButtonST m_btnArcosh;
	CButtonST m_btnTan;
	CButtonST m_btnArctan;
	CButtonST m_btnTanh;
	CButtonST m_btnArtanh;
	CButtonST m_btnExp;
	CButtonST m_btnLn;
	CButtonST m_btnInt;
	CButtonST m_btnAbs;
	CButtonST m_btn10x;
	CButtonST m_btnLog;
	CButtonST m_btnRad;
	CButtonST m_btnDeg;
	CButtonST m_btnX2;
    CButtonST m_btnPi;
	CButtonST m_btnSqr;
	CButtonST m_btnDelete;
	CButtonST m_btnUndo;
	CButtonST m_btnB;
	CButtonST m_btnF;
	CButtonST m_btnJ;
	CButtonST m_btnK;
	CButtonST m_btnM;
	CButtonST m_btnN;
	CButtonST m_btnP;
	CButtonST m_btnQ;
	CButtonST m_btnX;
	CButtonST m_btnY;
	CButtonST m_btnC;
	CButtonST m_btnBLower;
	CButtonST m_btnFLower;
	CButtonST m_btnJLower;
	CButtonST m_btnKLower;
	CButtonST m_btnMLower;
	CButtonST m_btnNLower;
	CButtonST m_btnPLower;
	CButtonST m_btnQLower;
	CButtonST m_btnXLower;
	CButtonST m_btnYLower;
    CButtonST m_btnZLower;    
	CButtonST m_btnSave;
	CButtonST m_btnLoad;
    CButtonST m_btnCancel;
    CButtonST m_btnOK;
};

#endif // !defined(AFX_SIMPLEXPARSERDLG_H__98EEC303_BFC2_11D1_B0F3_08002BBFDDC1__INCLUDED_)
