#include "StdAfx.h"
#include "RunningLog.h"
#include "MainFrm.h"
#include "Util.h"
#include "RunningLogDoc.h"
#include "SingleInstance.h"
#include "RunningLogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CRunningLogApp, CWinApp)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// the global app
CRunningLogApp theApp;


CRunningLogApp::CRunningLogApp(void)
{
    m_pSplashThread = NULL;
}


CRunningLogApp::~CRunningLogApp(void)
{
}


BOOL CRunningLogApp::InitInstance(void)
{
    // only allow one instance of runninglog
	CInstanceChecker icChecker(_T("Triathlog App Instance Checker"));
	icChecker.ActivateChecker();
	if(icChecker.PreviousInstanceRunning())
	{
		AfxMessageBox(_T("There is already an instance of TriathLog running"), MB_OK);
		icChecker.ActivatePreviousInstance();
		return FALSE;
	}

	InitCommonControls();

	CWinApp::InitInstance();

	// load standard INI file options
	LoadStdProfileSettings(0);  

    CMenuXP::InitializeHook();

    /*
    // bring up the splash screen in a secondary UI thread
    m_pSplashThread = (CSplashThread*) AfxBeginThread(RUNTIME_CLASS(CSplashThread), THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
    if (m_pSplashThread == NULL)
    {
        CUtil::Fatal("Could not create splash screen");
        return FALSE;
    }
    m_pSplashThread->SetBitmapToUse(IDB_SPLASH);  
    m_pSplashThread->ResumeThread();
    */

	// register the application's document templates
	CSingleDocTemplate* pDocTemplate = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(CRunningLogDoc),
															  RUNTIME_CLASS(CMainFrame), RUNTIME_CLASS(CRunningLogView));
	AddDocTemplate(pDocTemplate);

	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

    m_nCmdShow = SW_HIDE;

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo); 
	// dispatch commands specified on the command line.  will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister
	if(CCommandLineInfo::FileOpen == cmdInfo.m_nShellCommand)
	{
		SetFileToOpen(cmdInfo.m_strFileName);
	}
	
	if(!ProcessShellCommand(cmdInfo))
    {
        return FALSE;
    }

	m_pMainWnd->ShowWindow(SW_HIDE);

    m_pSplashEx = new CSplashScreenEx();
	m_pSplashEx->Create(m_pMainWnd, NULL, 0, CSS_FADE | CSS_CENTERSCREEN | CSS_SHADOW);
	m_pSplashEx->SetBitmap(IDB_SPLASH3, 255, 0, 255);
	m_pSplashEx->SetTextFont("Impact", 120, CSS_TEXT_NORMAL);
	m_pSplashEx->SetTextRect(CRect(143, 185, 273, 221));
	m_pSplashEx->SetTextColor(RGB(0, 0, 0));
	m_pSplashEx->SetTextFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	m_pSplashEx->Show();

	m_pSplashEx->SetText("Loading...");

    Sleep(CUtil::GetSplashSleep());

    m_pMainWnd->SetIcon(LoadIcon(IDR_MAINFRAME), false);
	// the window has been initialized, so show and update it
	m_pMainWnd->UpdateWindow();

	// if this is the first instance then track it so any other instances can find us
	icChecker.TrackFirstInstanceRunning();

//	RegisterShellAssociation();
//	UnregisterShellAssociation();
	NotifyAssociationChanged();

    return TRUE;
}


int CRunningLogApp::ExitInstance(void)
{
    CMenuXP::UninitializeHook();

    return CWinApp::ExitInstance();
}


CSplashThread* CRunningLogApp::GetSplashThread(void) const
{
    return m_pSplashThread;
}


CSplashScreenEx* CRunningLogApp::GetSplashEx(void) const
{
    return m_pSplashEx;
}


void CRunningLogApp::SetFileToOpen(CString str)
{
	m_strOpenFile = str;
}


CString CRunningLogApp::GetFileToOpen(void) const
{
	return m_strOpenFile;
}


// the registration/unregistration code is from the KeePass application source
BOOL CRunningLogApp::RegisterShellAssociation(void)
{
	LONG l;
	HKEY hBase, hShell, hTemp, hTemp2;
	TCHAR tszTemp[MAX_PATH * 2];
	TCHAR tszMe[MAX_PATH * 2];
	DWORD dw;

	VERIFY(GetModuleFileName(NULL, tszMe, MAX_PATH * 2 - 2) != 0);

	// HKEY_CLASSES_ROOT/.tlg

	l = RegCreateKey(HKEY_CLASSES_ROOT, _T(".tlg"), &hBase);
	if(l != ERROR_SUCCESS) return FALSE;

	_tcscpy(tszTemp, _T("tlgfile"));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hBase, _T(""), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hBase); return FALSE; }

	RegCloseKey(hBase);

	// HKEY_CLASSES_ROOT/kdbfile

	l = RegCreateKey(HKEY_CLASSES_ROOT, _T("tlgfile"), &hBase);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) return FALSE;

	_tcscpy(tszTemp, _T("TriathLog Data File"));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hBase, _T(""), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hBase); return FALSE; }

	_tcscpy(tszTemp, _T(""));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hBase, _T("AlwaysShowExt"), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hBase); return FALSE; }

	l = RegCreateKey(hBase, _T("DefaultIcon"), &hTemp);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) return FALSE;

	_tcscpy(tszTemp, tszMe);
	_tcscat(tszTemp, _T(",0"));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hTemp, _T(""), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hTemp); RegCloseKey(hBase); return FALSE; }

	RegCloseKey(hTemp);

	// HKEY_CLASSES_ROOT/tlgfile/shell

	l = RegCreateKey(hBase, _T("shell"), &hShell);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) return FALSE;

	// HKEY_CLASSES_ROOT/tlgfile/shell/open

	l = RegCreateKey(hShell, _T("open"), &hTemp);

	_tcscpy(tszTemp, _T("&Open with TriathLog"));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hTemp, _T(""), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hTemp); RegCloseKey(hShell); RegCloseKey(hBase); return FALSE; }

	l = RegCreateKey(hTemp, _T("command"), &hTemp2);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) return FALSE;

	_tcscpy(tszTemp, _T("\""));
	_tcscat(tszTemp, tszMe);
	_tcscat(tszTemp, _T("\" \"%1\""));
	dw = (_tcslen(tszTemp) + 1) * sizeof(TCHAR);
	l = RegSetValueEx(hTemp2, _T(""), 0, REG_SZ, (CONST BYTE *)tszTemp, dw);
	ASSERT(l == ERROR_SUCCESS); if(l != ERROR_SUCCESS) { RegCloseKey(hTemp); RegCloseKey(hShell); RegCloseKey(hBase); return FALSE; }

	VERIFY(RegCloseKey(hTemp2) == ERROR_SUCCESS);
	VERIFY(RegCloseKey(hTemp) == ERROR_SUCCESS);

	VERIFY(RegCloseKey(hShell) == ERROR_SUCCESS);

	VERIFY(RegCloseKey(hBase) == ERROR_SUCCESS);

	return TRUE;
}

BOOL CRunningLogApp::UnregisterShellAssociation(void)
{
	HKEY hBase, hShell, hOpen, hCommand;
	LONG l;

	l = RegOpenKeyEx(HKEY_CLASSES_ROOT, _T(".tlg"), 0, KEY_WRITE, &hBase);
	if(l != ERROR_SUCCESS) return FALSE;

	RegDeleteValue(hBase, _T(""));
	VERIFY(RegCloseKey(hBase) == ERROR_SUCCESS);

	VERIFY(RegDeleteKey(HKEY_CLASSES_ROOT, _T(".tlg")) == ERROR_SUCCESS);

	l = RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("tlgfile"), 0, KEY_WRITE, &hBase);
	if(l != ERROR_SUCCESS) return FALSE;

	l = RegOpenKeyEx(hBase, _T("shell"), 0, KEY_WRITE, &hShell);
	if(l != ERROR_SUCCESS) return FALSE;

	l = RegOpenKeyEx(hShell, _T("open"), 0, KEY_WRITE, &hOpen);
	if(l != ERROR_SUCCESS) return FALSE;

	l = RegOpenKeyEx(hOpen, _T("command"), 0, KEY_WRITE, &hCommand);
	if(l != ERROR_SUCCESS) return FALSE;

	RegDeleteValue(hCommand, _T(""));
	VERIFY(RegCloseKey(hCommand) == ERROR_SUCCESS);

	RegDeleteValue(hOpen, _T(""));
	VERIFY(RegCloseKey(hOpen) == ERROR_SUCCESS);

	RegDeleteValue(hShell, _T(""));
	VERIFY(RegCloseKey(hShell) == ERROR_SUCCESS);

	RegDeleteValue(hBase, _T(""));
	RegDeleteValue(hBase, _T("AlwaysShowExt"));
	VERIFY(RegCloseKey(hBase) == ERROR_SUCCESS);

	return TRUE;
}


void CRunningLogApp::NotifyAssociationChanged(void)
{
	LPSHCHANGENOTIFY lpSHChangeNotify;
	HINSTANCE hShell32;

	hShell32 = LoadLibrary(_T("Shell32.dll"));
	if(hShell32 != NULL)
	{
		lpSHChangeNotify = (LPSHCHANGENOTIFY)GetProcAddress(hShell32, _T("SHChangeNotify"));

		if(lpSHChangeNotify != NULL)
		{
			lpSHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
		}
		else { ASSERT(FALSE); }

		FreeLibrary(hShell32);
	}
	else { ASSERT(FALSE); }
}
