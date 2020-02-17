// Name.cpp : implementation file
//

#include "stdafx.h"
#include "AbduTextEditor.h"
#include "Name.h"
#include "afxdialogex.h"


// Name dialog

IMPLEMENT_DYNAMIC(Name, CDialogEx)

Name::Name(CWnd* pParent /*=nullptr*/)
	: CDialogEx(NameDlg, pParent)
	, m_Text(_T(""))
{

}

Name::~Name()
{
}

void Name::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, NameEdit, m_ENameBox);
	DDX_Text(pDX, NameEdit, m_Text);
	DDV_MaxChars(pDX, m_Text, 24);
	DDX_Control(pDX, CreateBut, m_BCreate);
}


BEGIN_MESSAGE_MAP(Name, CDialogEx)
	ON_BN_CLICKED(CreateBut, &Name::OnBnClickedCreatebut)
END_MESSAGE_MAP()


// Name message handlers


void Name::OnBnClickedCreatebut()
{
	bool trip = true;
	m_ENameBox.GetWindowText(m_Text);

	if (m_Text.GetLength() == 0) {
		AfxMessageBox(_T("Field Cannot be Left Blank"));
		trip = false;
	}

	for (unsigned int i = 0; i <= m_Text.GetAllocLength(); i++) {
		WCHAR ch = m_Text.GetAt(i);

		switch (ch) {
		case '\\':
			AfxMessageBox(_T("Cannot have \\ in filename"));
			trip = false;
			break;
		case '/':
			AfxMessageBox(_T("Cannot have / in filename"));
			trip = false;
			break;
		case '?':
			AfxMessageBox(_T("Cannot have ? in filename"));
			trip = false;
			break;
		case '"':
			AfxMessageBox(_T("Cannot have \" in filename"));
			trip = false;
			break;
		case ':':
			AfxMessageBox(_T("Cannot have : in filename"));
			trip = false;
			break;
		case '*':
			AfxMessageBox(_T("Cannot have * in filename"));
			trip = false;
			break;
		case '|':
			AfxMessageBox(_T("Cannot have | in filename"));
			trip = false;
			break;
		case '<':
			AfxMessageBox(_T("Cannot have < in filename"));
			trip = false;
			break;
		case '>':
			AfxMessageBox(_T("Cannot have > in filename"));
			trip = false;
			break;
		default:
			trip = true;
			break;
		}
	}
	if (trip)
		EndDialog(1);
}
