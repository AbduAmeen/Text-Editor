
// AbduTextEditorView.h : interface of the CAbduTextEditorView class
//

#pragma once
#include "resource.h"

class CAbduTextEditorView : public CFormView
{
protected: // create from serialization only
	CAbduTextEditorView() noexcept;
	DECLARE_DYNCREATE(CAbduTextEditorView)
	enum { IDD = IDDFORMVIEW };
#ifdef _DEBUG
// Attributes
public:
	CAbduTextEditorDoc* GetDocument() const;

// Operations
public:
	
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CAbduTextEditorView();
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	
	
#endif

protected:
	
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	virtual ~CAbduTextEditorView();
	/*virtual CAbduTextEditorDoc* GetDocument() ;*/
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnEnChangeRichedit1();
	afx_msg void OnEnUpdateRichedit1();
	void SetText(CString string);
};

#ifndef _DEBUG  // debug version in AbduTextEditorView.cpp
//inline CAbduTextEditorDoc* CAbduTextEditorView::GetDocument() const
//   { return reinterpret_cast<CAbduTextEditorDoc*>(m_pDocument); }
#endif

