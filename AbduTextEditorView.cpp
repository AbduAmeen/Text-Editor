
// AbduTextEditorView.cpp : implementation of the CAbduTextEditorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AbduTextEditor.h"
#endif

#include "AbduTextEditorDoc.h"
#include "AbduTextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAbduTextEditorView

IMPLEMENT_DYNCREATE(CAbduTextEditorView, CFormView)

BEGIN_MESSAGE_MAP(CAbduTextEditorView, CFormView)
	// Standard printing commands
	ON_EN_CHANGE(IDC_RICHEDIT1, &CAbduTextEditorView::OnEnChangeRichedit1)
	ON_EN_UPDATE(IDC_RICHEDIT1, &CAbduTextEditorView::OnEnUpdateRichedit1)
END_MESSAGE_MAP()

// CAbduTextEditorView construction/destruction

CAbduTextEditorView::CAbduTextEditorView() noexcept: CFormView(IDD) {
	// TODO: add construction code here

}

CAbduTextEditorView::~CAbduTextEditorView()
{
}



BOOL CAbduTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

// CAbduTextEditorView drawing

void CAbduTextEditorView::OnDraw(CDC* /*pDC*/)
{
	CAbduTextEditorDoc* pDoc = (CAbduTextEditorDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
}

// CAbduTextEditorView diagnostics

#ifdef _DEBUG
void CAbduTextEditorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAbduTextEditorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}


	

CAbduTextEditorDoc* CAbduTextEditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAbduTextEditorDoc)));
	return dynamic_cast<CAbduTextEditorDoc*>(m_pDocument);
}
#endif //_DEBUG


// CAbduTextEditorView message handlers

void CAbduTextEditorView::SetText(CString string) {
	GetDlgItem(IDC_RICHEDIT1)->SetWindowTextW(string);
}
void CAbduTextEditorView::OnEnChangeRichedit1()
{
}


void CAbduTextEditorView::OnEnUpdateRichedit1()
{
	GetDlgItem(IDC_RICHEDIT1)->GetWindowTextW(theApp.buff);
	
	if (theApp.buff.Compare(theApp.Buffer) != 0) {
		CAbduTextEditorDoc* doc = (CAbduTextEditorDoc*) GetDocument();
	GetDocument()->SetModifiedFlag(1);
	}	
}
