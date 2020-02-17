
// AbduTextEditor.h : main header file for the AbduTextEditor application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAbduTextEditorApp:
// See AbduTextEditor.cpp for the implementation of this class
//

class CAbduTextEditorApp : public CWinAppEx
{
public:
	CAbduTextEditorApp() noexcept;
	CPath CurrPath;
	CString Buffer;
	CString buff;
	

	// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CAbduTextEditorApp theApp;
