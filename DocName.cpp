// DocName.cpp : implementation file
//

#include "stdafx.h"
#include "AbduTextEditor.h"
#include "DocName.h"
#include "afxdialogex.h"


// DocName dialog

IMPLEMENT_DYNAMIC(DocName, CDialogEx)

DocName::DocName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(NameDlg, pParent)
{

}

DocName::~DocName()
{
}

void DocName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DocName, CDialogEx)
END_MESSAGE_MAP()


// DocName message handlers
