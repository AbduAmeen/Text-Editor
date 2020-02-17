
// AbduTextEditorDoc.cpp : implementation of the CAbduTextEditorDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AbduTextEditor.h"
#endif

#include "AbduTextEditorDoc.h"

#include <propkey.h>
#include "AbduTextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAbduTextEditorDoc

IMPLEMENT_DYNCREATE(CAbduTextEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CAbduTextEditorDoc, CDocument)
	/*ON_COMMAND(ID_FILE_SAVE, &CDocument::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CDocument::OnFileSaveAs)*/
END_MESSAGE_MAP()


// CAbduTextEditorDoc construction/destruction

CAbduTextEditorDoc::CAbduTextEditorDoc() noexcept
{
	// TODO: add one-time construction code here

}

CAbduTextEditorDoc::~CAbduTextEditorDoc()
{
}

BOOL CAbduTextEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CAbduTextEditorDoc serialization

void CAbduTextEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << theApp.buff;
	}
	else
	{
		ar >> theApp.Buffer;
		POSITION pos = GetFirstViewPosition();
		CAbduTextEditorView* pView = static_cast<CAbduTextEditorView*>(GetNextView(pos));
		pView->SetText(theApp.Buffer);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CAbduTextEditorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CAbduTextEditorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CAbduTextEditorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAbduTextEditorDoc diagnostics

#ifdef _DEBUG
void CAbduTextEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAbduTextEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAbduTextEditorDoc commands


BOOL CAbduTextEditorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	CStdioFile file(theApp.CurrPath,CFile::modeReadWrite);
	

	UpdateAllViews(nullptr);
	
	return TRUE;
}


BOOL CAbduTextEditorDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return CDocument::OnSaveDocument(lpszPathName);
}
