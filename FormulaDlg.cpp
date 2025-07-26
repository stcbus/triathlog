// FormulaDlg.cpp : implementation file

#include "stdafx.h"
#include "AniDialog.h"
#include "Util.h"
#include "FormulaDlg.h"
#include "FormulaParser.h"
#include "BtnST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;

#endif


BEGIN_MESSAGE_MAP(CFormulaDlg, CAniDialog)
    ON_EN_CHANGE(IDC_FORMELEINGABE, OnFormulaChanged)
	ON_BN_CLICKED(IDC_SIN, OnSin)
    ON_BN_CLICKED(IDC_PLUS, OnPlus)
	ON_BN_CLICKED(IDC_MINUS, OnMinus)
	ON_BN_CLICKED(IDC_MAL, OnMal)
	ON_BN_CLICKED(IDC_GETEILT, OnGeteilt)
	ON_BN_CLICKED(IDC_HOCH, OnHoch)
	ON_BN_CLICKED(IDC_PKT, OnPkt)
	ON_BN_CLICKED(IDC_KLAMMER_AUF, OnKlammerAuf)
	ON_BN_CLICKED(IDC_KLAMMER_ZU, OnKlammerZu)
	ON_BN_CLICKED(IDC_ARCSIN, OnArcsin)
	ON_BN_CLICKED(IDC_SINH, OnSinh)
	ON_BN_CLICKED(IDC_ARSINH, OnArsinh)
	ON_BN_CLICKED(IDC_COS, OnCos)
	ON_BN_CLICKED(IDC_ARCCOS, OnArccos)
	ON_BN_CLICKED(IDC_COSH, OnCosh)
	ON_BN_CLICKED(IDC_ARCOSH, OnArcosh)
	ON_BN_CLICKED(IDC_TAN, OnTan)
	ON_BN_CLICKED(IDC_ARCTAN, OnArctan)
	ON_BN_CLICKED(IDC_TANH, OnTanh)
	ON_BN_CLICKED(IDC_ARTANH, OnArtanh)
	ON_BN_CLICKED(IDC_EXP, OnExp)
	ON_BN_CLICKED(IDC_LN, OnLn)
	ON_BN_CLICKED(IDC_INT, OnInt)
	ON_BN_CLICKED(IDC_ABS, OnAbs)
	ON_BN_CLICKED(IDC_10X, On10x)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_RAD, OnRad)
	ON_BN_CLICKED(IDC_DEG, OnDeg)
	ON_BN_CLICKED(IDC_X2, OnX2)
    ON_BN_CLICKED(IDC_PI, OnPi)
	ON_BN_CLICKED(IDC_SQR, OnSqr)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_UNDO, OnUndo)
	ON_BN_CLICKED(IDC_B, OnB)
	ON_BN_CLICKED(IDC_F, OnF)
	ON_BN_CLICKED(IDC_J, OnJ)
	ON_BN_CLICKED(IDC_K, OnK)
	ON_BN_CLICKED(IDC_M, OnM)
	ON_BN_CLICKED(IDC_N, OnN)
	ON_BN_CLICKED(IDC_P, OnP)
	ON_BN_CLICKED(IDC_Q, OnQ)
	ON_BN_CLICKED(IDC_X, OnX)
	ON_BN_CLICKED(IDC_Y, OnY)
	ON_BN_CLICKED(IDC_C, OnC)
	ON_BN_CLICKED(IDC_BLOWER, OnBLower)
	ON_BN_CLICKED(IDC_FLOWER, OnFLower)
	ON_BN_CLICKED(IDC_JLOWER, OnJLower)
	ON_BN_CLICKED(IDC_KLOWER, OnKLower)
	ON_BN_CLICKED(IDC_MLOWER, OnMLower)
	ON_BN_CLICKED(IDC_NLOWER, OnNLower)
	ON_BN_CLICKED(IDC_PLOWER, OnPLower)
	ON_BN_CLICKED(IDC_QLOWER, OnQLower)
	ON_BN_CLICKED(IDC_XLOWER, OnXLower)
	ON_BN_CLICKED(IDC_YLOWER, OnYLower)    
	ON_BN_CLICKED(IDC_ZLOWER, OnZLower)        
	ON_BN_CLICKED(IDC_SAVE, OnSaveParameter)
	ON_BN_CLICKED(IDC_LOAD, OnLoadParameter)
    ON_COMMAND_RANGE(IDC_0, IDC_9, OnClickedNumber)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormulaDlg dialog

CFormulaDlg::CFormulaDlg(CWnd* pParent /*=NULL*/)
	: CAniDialog(CFormulaDlg::IDD, pParent)
{
	m_strFormulainput = _T("");
	m_strFormulainput_vorher = m_strFormulainput;
	m_strFileName = "";
}


void CFormulaDlg::DoDataExchange(CDataExchange* pDX)
{
	CAniDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_FORMELEINGABE, m_EditInputControl); 

	DDX_Control(pDX, IDC_SIN, m_btnSin);
	DDX_Control(pDX, IDC_PLUS, m_btnPlus);
	DDX_Control(pDX, IDC_MINUS, m_btnMinus);
	DDX_Control(pDX, IDC_MAL, m_btnMal);
	DDX_Control(pDX, IDC_GETEILT, m_btnGeteilt);
	DDX_Control(pDX, IDC_HOCH, m_btnHoch);
	DDX_Control(pDX, IDC_PKT, m_btnPkt);
	DDX_Control(pDX, IDC_KLAMMER_AUF, m_btnKlammerAuf);
	DDX_Control(pDX, IDC_KLAMMER_ZU, m_btnKlammerZu);
	DDX_Control(pDX, IDC_ARCSIN, m_btnArcsin);
	DDX_Control(pDX, IDC_SINH, m_btnSinh);
	DDX_Control(pDX, IDC_ARSINH, m_btnArsinh);
	DDX_Control(pDX, IDC_COS, m_btnCos);
	DDX_Control(pDX, IDC_ARCCOS, m_btnArccos);
	DDX_Control(pDX, IDC_COSH, m_btnCosh);
	DDX_Control(pDX, IDC_ARCOSH, m_btnArcosh);
	DDX_Control(pDX, IDC_TAN, m_btnTan);
	DDX_Control(pDX, IDC_ARCTAN, m_btnArctan);
	DDX_Control(pDX, IDC_TANH, m_btnTanh);
	DDX_Control(pDX, IDC_ARTANH, m_btnArtanh);
	DDX_Control(pDX, IDC_EXP, m_btnExp);
	DDX_Control(pDX, IDC_LN, m_btnLn);
	DDX_Control(pDX, IDC_INT, m_btnInt);
	DDX_Control(pDX, IDC_ABS, m_btnAbs);
	DDX_Control(pDX, IDC_10X, m_btn10x);
	DDX_Control(pDX, IDC_LOG, m_btnLog);
	DDX_Control(pDX, IDC_RAD, m_btnRad);
	DDX_Control(pDX, IDC_DEG, m_btnDeg);
	DDX_Control(pDX, IDC_X2, m_btnX2);
    DDX_Control(pDX, IDC_PI, m_btnPi);;
	DDX_Control(pDX, IDC_SQR, m_btnSqr);
	DDX_Control(pDX, IDC_DELETE, m_btnDelete);
	DDX_Control(pDX, IDC_UNDO, m_btnUndo);
	DDX_Control(pDX, IDC_B, m_btnB);
	DDX_Control(pDX, IDC_F, m_btnF);
	DDX_Control(pDX, IDC_J, m_btnJ);
	DDX_Control(pDX, IDC_K, m_btnK);
	DDX_Control(pDX, IDC_M, m_btnM);
	DDX_Control(pDX, IDC_N, m_btnN);
	DDX_Control(pDX, IDC_P, m_btnP);
	DDX_Control(pDX, IDC_Q, m_btnQ);
	DDX_Control(pDX, IDC_X, m_btnX);
	DDX_Control(pDX, IDC_Y, m_btnY);
	DDX_Control(pDX, IDC_C, m_btnC);
	DDX_Control(pDX, IDC_BLOWER, m_btnBLower);
	DDX_Control(pDX, IDC_FLOWER, m_btnFLower);
	DDX_Control(pDX, IDC_JLOWER, m_btnJLower);
	DDX_Control(pDX, IDC_KLOWER, m_btnKLower);
	DDX_Control(pDX, IDC_MLOWER, m_btnMLower);
	DDX_Control(pDX, IDC_NLOWER, m_btnNLower);
	DDX_Control(pDX, IDC_PLOWER, m_btnPLower);
	DDX_Control(pDX, IDC_QLOWER, m_btnQLower);
	DDX_Control(pDX, IDC_XLOWER, m_btnXLower);
	DDX_Control(pDX, IDC_YLOWER, m_btnYLower);    
	DDX_Control(pDX, IDC_ZLOWER, m_btnZLower);        
	DDX_Control(pDX, IDC_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_LOAD, m_btnLoad);
	DDX_Control(pDX, IDC_0, m_btn0);
	DDX_Control(pDX, IDC_1, m_btn1);
	DDX_Control(pDX, IDC_2, m_btn2); 	
    DDX_Control(pDX, IDC_3, m_btn3);   
    DDX_Control(pDX, IDC_4, m_btn4);
	DDX_Control(pDX, IDC_5, m_btn5);
	DDX_Control(pDX, IDC_6, m_btn6);
	DDX_Control(pDX, IDC_7, m_btn7);
	DDX_Control(pDX, IDC_8, m_btn8);
	DDX_Control(pDX, IDC_9, m_btn9);
    DDX_Control(pDX, IDCANCEL, m_btnCancel);
    DDX_Control(pDX, IDOK, m_btnOK);  
}

/////////////////////////////////////////////////////////////////////////////
// CFormulaDlg message handlers


BOOL CFormulaDlg::OnInitDialog(void)
{
    BOOL bRes = CAniDialog::OnInitDialog();
    
    SetDlgItemText(IDC_EDIT_B, "Running Minutes");
    SetDlgItemText(IDC_EDIT_F, "Cycling Minutes");
    SetDlgItemText(IDC_EDIT_J, "Swimming Minutes");
    SetDlgItemText(IDC_EDIT_K, "Strength Work Minutes");
    SetDlgItemText(IDC_EDIT_M, "Overall Minutes");
    SetDlgItemText(IDC_EDIT_N, CUtil::GetRunDistString("Running Distance"));
    SetDlgItemText(IDC_EDIT_P, CUtil::GetBikeDistString("Cycling Distance"));
    SetDlgItemText(IDC_EDIT_Q, CUtil::GetSwimDistString("Swimming Distance"));
    SetDlgItemText(IDC_EDIT_X, CUtil::GetPaceString(FORMAT_RUN, "Running Pace"));
    SetDlgItemText(IDC_EDIT_Y, CUtil::GetPaceString(FORMAT_BIKE, "Cycling Pace")); 
	SetDlgItemText(IDC_EDIT_C, "Calories");
    SetDlgItemText(IDC_EDIT_BLOWER, CUtil::GetPaceString(FORMAT_SWIM, "Swimming Pace"));
    SetDlgItemText(IDC_EDIT_FLOWER, "Running Workouts");
    SetDlgItemText(IDC_EDIT_JLOWER, "Cycling Workouts");
    SetDlgItemText(IDC_EDIT_KLOWER, "Swimming Workouts");
    SetDlgItemText(IDC_EDIT_MLOWER, "Strength Workouts");
    SetDlgItemText(IDC_EDIT_NLOWER, "Overall Workouts");
    SetDlgItemText(IDC_EDIT_LOWERP, "Sleep");
    SetDlgItemText(IDC_EDIT_QLOWER, "Weight");
    SetDlgItemText(IDC_EDIT_XLOWER, "Temperature");
    SetDlgItemText(IDC_EDIT_YLOWER, "Heartrate");
    SetDlgItemText(IDC_EDIT_ZLOWER, "Points");

    COLORREF m_crNum = RGB(97, 23, 232);
    COLORREF m_crFunc = RGB(55, 151, 45);
    COLORREF m_crParam = RGB(243, 120, 64);
    COLORREF m_crOther =  RGB(36, 72, 72);
    COLORREF m_crHot = RGB(233, 22, 22);
    m_btn0.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
 	m_btn1.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn2.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn3.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn4.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn5.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn6.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn7.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn8.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btn9.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);    
	m_btnSin.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnPlus.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnMinus.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnMal.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnGeteilt.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnHoch.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnPkt.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnKlammerAuf.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnKlammerZu.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crNum, TRUE);
	m_btnArcsin.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnSinh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnArsinh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnCos.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnArccos.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnCosh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnArcosh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnTan.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnArctan.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnTanh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnArtanh.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnExp.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnLn.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnInt.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnAbs.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btn10x.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnLog.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnRad.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnDeg.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnX2.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnPi.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);    
	m_btnSqr.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crFunc, TRUE);
	m_btnDelete.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);
	m_btnUndo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);
	m_btnB.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnF.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnJ.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnK.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnM.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnN.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnP.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnQ.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnX.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnY.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnC.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnBLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnFLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnJLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnKLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnMLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnNLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnPLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnQLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnXLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
	m_btnYLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);
    m_btnZLower.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crParam, TRUE);    
	m_btnSave.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);
	m_btnLoad.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);
    m_btnCancel.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);
    m_btnOK.SetColor(CButtonST::BTNST_COLOR_FG_OUT, m_crOther, TRUE);    

	m_btn0.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
 	m_btn1.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn2.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn3.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn4.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn5.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn6.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn7.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn8.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn9.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);    
	m_btnSin.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnPlus.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnMinus.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnMal.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnGeteilt.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnHoch.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnPkt.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnKlammerAuf.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnKlammerZu.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArcsin.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnSinh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArsinh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnCos.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArccos.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnCosh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArcosh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnTan.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArctan.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnTanh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnArtanh.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnExp.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnLn.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnInt.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnAbs.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btn10x.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnLog.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnRad.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnDeg.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnX2.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnPi.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);    
	m_btnSqr.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnDelete.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnUndo.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnB.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnF.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnJ.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnK.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnM.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnN.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnP.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnC.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnQ.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnX.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnY.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnBLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnFLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnJLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnKLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnMLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnNLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnPLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnQLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnXLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnYLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
    m_btnZLower.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);    
	m_btnSave.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
	m_btnLoad.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
    m_btnCancel.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE);
    m_btnOK.SetColor(CButtonST::BTNST_COLOR_FG_IN, m_crHot, TRUE); 

 	m_btn0.SetFlat(false);
 	m_btn1.SetFlat(false);
	m_btn2.SetFlat(false);
	m_btn3.SetFlat(false);
	m_btn4.SetFlat(false);
	m_btn5.SetFlat(false);
	m_btn6.SetFlat(false);
	m_btn7.SetFlat(false);
	m_btn8.SetFlat(false);
	m_btn9.SetFlat(false);    
	m_btnSin.SetFlat(false);
	m_btnPlus.SetFlat(false);
	m_btnMinus.SetFlat(false);
	m_btnMal.SetFlat(false);
	m_btnGeteilt.SetFlat(false);
	m_btnHoch.SetFlat(false);
	m_btnPkt.SetFlat(false);
	m_btnKlammerAuf.SetFlat(false);
	m_btnKlammerZu.SetFlat(false);
	m_btnArcsin.SetFlat(false);
	m_btnSinh.SetFlat(false);
	m_btnArsinh.SetFlat(false);
	m_btnCos.SetFlat(false);
	m_btnArccos.SetFlat(false);
	m_btnCosh.SetFlat(false);
	m_btnArcosh.SetFlat(false);
	m_btnTan.SetFlat(false);
	m_btnArctan.SetFlat(false);
	m_btnTanh.SetFlat(false);
	m_btnArtanh.SetFlat(false);
	m_btnExp.SetFlat(false);
	m_btnLn.SetFlat(false);
	m_btnInt.SetFlat(false);
	m_btnAbs.SetFlat(false);
	m_btn10x.SetFlat(false);
	m_btnLog.SetFlat(false);
	m_btnRad.SetFlat(false);
	m_btnDeg.SetFlat(false);
	m_btnX2.SetFlat(false);
	m_btnPi.SetFlat(false);    
	m_btnSqr.SetFlat(false);
	m_btnDelete.SetFlat(false);
	m_btnUndo.SetFlat(false);
	m_btnB.SetFlat(false);
	m_btnF.SetFlat(false);
	m_btnJ.SetFlat(false);
	m_btnK.SetFlat(false);
	m_btnM.SetFlat(false);
	m_btnN.SetFlat(false);
	m_btnP.SetFlat(false);
	m_btnC.SetFlat(false);
	m_btnQ.SetFlat(false);
	m_btnX.SetFlat(false);
	m_btnY.SetFlat(false);
	m_btnBLower.SetFlat(false);
	m_btnFLower.SetFlat(false);
	m_btnJLower.SetFlat(false);
	m_btnKLower.SetFlat(false);
	m_btnMLower.SetFlat(false);
	m_btnNLower.SetFlat(false);
	m_btnPLower.SetFlat(false);
	m_btnQLower.SetFlat(false);
	m_btnXLower.SetFlat(false);
	m_btnYLower.SetFlat(false);
    m_btnZLower.SetFlat(false);    
	m_btnSave.SetFlat(false);
	m_btnLoad.SetFlat(false);
    m_btnCancel.SetFlat(false);
    m_btnOK.SetFlat(false); 

    return bRes;
}


//Klicks auf Buttons auswerten
void CFormulaDlg::OnSin()			{	SetEingabe("sin("); }
void CFormulaDlg::OnPlus()		{	SetEingabe("+"); }
void CFormulaDlg::OnMinus()  	{	SetEingabe("-"); }
void CFormulaDlg::OnMal() 		{	SetEingabe("*"); }
void CFormulaDlg::OnGeteilt() {	SetEingabe("/"); }
void CFormulaDlg::OnHoch() 		{	SetEingabe("^"); }
void CFormulaDlg::OnPkt() 		{	SetEingabe("."); }
void CFormulaDlg::OnKlammerAuf() 	{	SetEingabe("("); }
void CFormulaDlg::OnKlammerZu() 	{	SetEingabe(")"); }
void CFormulaDlg::OnArcsin() 	{	SetEingabe("arcsin("); }
void CFormulaDlg::OnSinh() 		{	SetEingabe("sinh("); }
void CFormulaDlg::OnArsinh() 	{	SetEingabe("arcsinh("); }
void CFormulaDlg::OnCos() 		{	SetEingabe("cos("); }
void CFormulaDlg::OnArccos() 	{	SetEingabe("arccos("); }
void CFormulaDlg::OnCosh() 		{	SetEingabe("cosh("); }
void CFormulaDlg::OnArcosh() 	{	SetEingabe("arccosh("); }
void CFormulaDlg::OnTan() 		{	SetEingabe("tan("); }
void CFormulaDlg::OnArctan() 	{	SetEingabe("arctan("); }
void CFormulaDlg::OnTanh()		{	SetEingabe("tanh("); }
void CFormulaDlg::OnArtanh() 	{	SetEingabe("arctanh("); }
void CFormulaDlg::OnExp() 		{	SetEingabe("exp("); }
void CFormulaDlg::OnLn() 			{	SetEingabe("ln("); }
void CFormulaDlg::OnInt() 		{	SetEingabe("int("); }
void CFormulaDlg::OnAbs()			{	SetEingabe("abs("); }
void CFormulaDlg::On10x() 		{	SetEingabe("10^"); }
void CFormulaDlg::OnLog() 		{	SetEingabe("log("); }
void CFormulaDlg::OnRad() 		{	SetEingabe("rad("); }
void CFormulaDlg::OnDeg() 		{	SetEingabe("deg("); }
void CFormulaDlg::OnX2() 			{	SetEingabe("^2"); }
void CFormulaDlg::OnPi()            {   SetEingabe("3.14159"); }
void CFormulaDlg::OnSqr() 		{	SetEingabe("sqrt("); }
void CFormulaDlg::OnB()  			{	SetEingabe("B"); } 
void CFormulaDlg::OnF()  			{	SetEingabe("F"); } 
void CFormulaDlg::OnJ()  			{	SetEingabe("J"); } 
void CFormulaDlg::OnK()  			{	SetEingabe("K"); } 
void CFormulaDlg::OnM()  			{	SetEingabe("M"); } 
void CFormulaDlg::OnN()  			{	SetEingabe("N"); } 
void CFormulaDlg::OnP()  			{	SetEingabe("P"); } 
void CFormulaDlg::OnC()  			{	SetEingabe("C"); } 
void CFormulaDlg::OnQ()  			{	SetEingabe("Q"); } 
void CFormulaDlg::OnX()  			{	SetEingabe("X"); } 
void CFormulaDlg::OnY()  		    {	SetEingabe("Y"); } 
void CFormulaDlg::OnBLower()  			{	SetEingabe("b"); } 
void CFormulaDlg::OnFLower()  			{	SetEingabe("f"); } 
void CFormulaDlg::OnJLower()  			{	SetEingabe("j"); } 
void CFormulaDlg::OnKLower()  			{	SetEingabe("k"); } 
void CFormulaDlg::OnMLower()  			{	SetEingabe("m"); } 
void CFormulaDlg::OnNLower()  			{	SetEingabe("n"); } 
void CFormulaDlg::OnPLower()  			{	SetEingabe("p"); } 
void CFormulaDlg::OnQLower()  			{	SetEingabe("q"); } 
void CFormulaDlg::OnXLower()  			{	SetEingabe("x"); } 
void CFormulaDlg::OnYLower()  		    {	SetEingabe("y"); } 
void CFormulaDlg::OnZLower()  		    {	SetEingabe("z"); } 


void CFormulaDlg::OnClickedNumber(UINT nID) 
{
	ASSERT(nID >= IDC_0 && nID <= IDC_9);
	char buffer[20];   
	_itoa(nID - IDC_0, buffer, 10);
	SetEingabe(buffer);
}


void CFormulaDlg::OnFormulaChanged(void)
{
    GetDlgItemText(IDC_FORMELEINGABE, m_strFormulainput);

    UpdateData(false);

    UpdateOKButton();
}


void CFormulaDlg::SetEingabe(CString str)
{
    UpdateData(true);
    
    int nStart = -1, nEnd = -1;
    m_EditInputControl.GetSel(nStart, nEnd);
    
    CString strExistingText(m_strFormulainput);
    m_strFormulainput_vorher = strExistingText;
    
    int nLength = strExistingText.GetLength();
    
    if (nLength > 0)
    {
        strExistingText = strExistingText.Mid(0, nStart) + str + strExistingText.Mid(nEnd);
    }
    else
    {
        strExistingText += str;
    }
    
    nStart += str.GetLength();
    nEnd = nStart;
    
    m_strFormulainput = strExistingText;
    UpdateData(false);

    UpdateOKButton();
    m_EditInputControl.SetWindowText(m_strFormulainput);
    m_EditInputControl.SetFocus();
    m_EditInputControl.SetSel(nStart, nEnd);
}


void CFormulaDlg::OnDelete() 
{
	UpdateData(true);

	m_strFormulainput_vorher = m_strFormulainput;
	m_strFormulainput.Empty();
	UpdateData(false);

    UpdateOKButton();
    m_EditInputControl.SetFocus();
    m_EditInputControl.SetWindowText(m_strFormulainput); 
    m_EditInputControl.SetSel(0, 0);
}

void CFormulaDlg::OnUndo() 
{
	UpdateData(true);
    int nStart = -1, nEnd = -1;
    m_EditInputControl.GetSel(nStart, nEnd);

    CString dummy;
	dummy = m_strFormulainput;
	m_strFormulainput = m_strFormulainput_vorher;
	m_strFormulainput_vorher = dummy;
	UpdateData(false);

    nStart = m_strFormulainput.GetLength();
    nEnd = nStart;
    UpdateOKButton();
    m_EditInputControl.SetFocus();
    m_EditInputControl.SetWindowText(m_strFormulainput);    
    m_EditInputControl.SetSel(nStart, nEnd);
}

void CFormulaDlg::OnSaveParameter() 
{
	UpdateData(true);
	SaveParameter();
    m_EditInputControl.SetFocus();    
}

void CFormulaDlg::OnLoadParameter() 
{
	LoadParameter();	
	UpdateData(false);
    m_EditInputControl.SetFocus();
//  SetOwnChange(true);    happens in LoadParameter()
    m_EditInputControl.SetWindowText(m_strFormulainput);    
}

void CFormulaDlg::SaveParameter()
{
    BOOL bOpenFileDialog = false;  				//TRUE: <File Open>, FALSE: <File Save As> 
    const char* szDefExt = "fkt";  				//default extension
    const char* szFileName = (const char*) m_strFileName;  //default filename            
    //DWORD style = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;   //for load
    DWORD style = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT; 	//for save    
    const char* lpszFilter = "Formula Parser Files (*.fkt)|*.fkt||";  
	CWnd* pParent = NULL;                                       
    
    CFileDialog dlgFile(bOpenFileDialog,szDefExt,szFileName,style,lpszFilter,pParent);
  
    if (dlgFile.DoModal() != IDOK) 
        return;
  	
    m_strFileName = dlgFile.GetPathName();
	  		
    FILE* stream;
    if ((stream = fopen(m_strFileName, "w" )) == NULL)    
    {
        AfxMessageBox("Cannot save the file " + m_strFileName);    
        fclose(stream); 
        return;
    }
    
    /////////////////////////////////////////////////////////////////////////
    fputs("Formula Parser\n",stream);
    fputs("\n",stream);

    fputs("\n[FORMULA]\n",stream);
    fputs((LPCSTR) (m_strFormulainput + "\n"),stream);

    fputs("\n",stream); 
    fputs("[END]\n",stream);                       	

	fclose(stream); 	 
}

void CFormulaDlg::LoadParameter() 
{
	BOOL bOpenFileDialog = true;  				//TRUE: <File Open>, FALSE: <File Save As> 
    const char* szDefExt = "fkt";  				//default extension
    const char* szFileName = (const char*) m_strFileName;  //default filename            
    DWORD style = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;   //for load
    //DWORD style = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT; 	//for save    
    const char* lpszFilter = "Formula Parser Files (*.fkt)|*.fkt||";  
    CWnd* pParent = NULL;                                       
    
    CFileDialog dlgFile(bOpenFileDialog,szDefExt,szFileName,style,lpszFilter,pParent);
  
    if (dlgFile.DoModal() != IDOK) 
        return;
  	
	m_strFileName = dlgFile.GetPathName();
	CString FileName = m_strFileName.GetBuffer(128);
		
	FILE* stream;
    if ((stream = fopen(FileName, "r" )) == NULL)    
    {
        AfxMessageBox("Cannot open the file " + FileName);    
        fclose(stream); 
        return;   
    }

	char buffer[256];       
	
    UpdateOKButton();

    //////////////////////////////////////////////////////
    //fputs("SimplexNumerica Formulaparser\n",stream);
    if (fgets( buffer, 256, stream ) == NULL)
	{
		TRACE("fgets error\n");
        fclose(stream); 
        return;   
	}
	else
    {
        m_strFormulainput.Empty(); 
    }
    while (fgets(buffer, 256, stream) != NULL)
    {
	  	TRACE("%s\n", buffer);		
        if (strcmp(buffer,"[FORMULA]\n") == 0) 
            break; //then equal
    }
	if (fgets(buffer, 256, stream) != NULL)
	{      
		m_strFormulainput = buffer;  
		m_strFormulainput = m_strFormulainput.Left(m_strFormulainput.GetLength() - 1); //Remove CR
	}  
    
	TRACE("Formula: %s\n",m_strFormulainput);

    fclose(stream);
}


CString CFormulaDlg::GetFormula(void) const
{
    return m_strFormulainput;
}


void CFormulaDlg::UpdateOKButton(void)
{
    CFormulaParser p;
    p.SetFormula(m_strFormulainput);
    BOOL bOK = p.CheckParenthesis();

    CWnd* pWnd = GetDlgItem(IDOK);
    if(NULL != pWnd)
    {
        pWnd->EnableWindow(bOK);
    }
}