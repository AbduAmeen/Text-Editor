
// AbduTextEditor.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "AbduTextEditor.h"
#include "MainFrm.h"

#include "AbduTextEditorDoc.h"
#include "AbduTextEditorView.h"
#include "Name.h"
#include "First.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAbduTextEditorApp

BEGIN_MESSAGE_MAP(CAbduTextEditorApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CAbduTextEditorApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	
END_MESSAGE_MAP()


// CAbduTextEditorApp construction

CAbduTextEditorApp::CAbduTextEditorApp() noexcept
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("AbduTextEditor.AppID.1"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CAbduTextEditorApp object

CAbduTextEditorApp theApp;


// CAbduTextEditorApp initialization

BOOL CAbduTextEditorApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	if (!AfxOleInit())
	{
		AfxMessageBox(_T("Error"));
		return FALSE;
	}
	AfxEnableControlContainer();
	
	EnableTaskbarInteraction(FALSE);
	
	AfxInitRichEdit2();
	
	SetRegistryKey(_T("AbduTextEditor"));
	LoadStdProfileSettings(5);  
	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CAbduTextEditorDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CAbduTextEditorView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	First dlg;

	for (auto i = 0; i <= 4; i++) {
		dlg.rf.Add(m_pRecentFileList->operator[](i));
		
	}

	switch (dlg.DoModal()) {
	case 1:
		CurrPath = dlg.path;
		DeleteObject(dlg);
		break;
	default:
		return FALSE;
	}
	
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->DragAcceptFiles();
	
	OpenDocumentFile(CurrPath);

	return TRUE;
}

// CAbduTextEditorApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CAbduTextEditorApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CAbduTextEditorApp message handlers



int CAbduTextEditorApp::ExitInstance()
{
	//m_pRecentFileList->WriteList();

	return CWinAppEx::ExitInstance();
}

