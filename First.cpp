// First.cpp : implementation file
//

#include "stdafx.h"
#include "AbduTextEditor.h"
#include "First.h"
#include "afxdialogex.h"
#include "Name.h"


// First dialog

IMPLEMENT_DYNAMIC(First, CDialogEx)

First::First(CWnd* pParent /*=nullptr*/)
	: CDialogEx(FirstDlg, pParent)
{

}

First::~First()
{
}

void First::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, CreateBut, C_Create);
	DDX_Control(pDX, OpenBut, C_Open);
	DDX_Control(pDX, IDC_LIST1, C_List);
}


BEGIN_MESSAGE_MAP(First, CDialogEx)
	ON_BN_CLICKED(CreateBut, &First::OnBnClickedCreatebut)
	ON_BN_CLICKED(OpenBut, &First::OnBnClickedOpenbut)
	ON_LBN_DBLCLK(IDC_LIST1, &First::OnLbnDblclkList1)
END_MESSAGE_MAP()


// First message handlers


void First::OnBnClickedCreatebut()
{
	Name newdlg;
	CFileException pError;
	CFile file;

	INT_PTR result = newdlg.DoModal();

	switch (result) {

	case 1: {
		path.Append(path + _T("\\") + newdlg.m_Text + _T(".txt"));

		BOOL result2 = path.FileExists();

		if (result2 == FALSE) {

			if (!file.Open(path, CFile::modeCreate, &pError)) {
				TCHAR errormsg[256];
				CString string;

				pError.GetErrorMessage(errormsg, 256);

				string.Append(_T("Error: "));
				string.Append(errormsg);

				AfxMessageBox(string);
				return;
			}
			EndDialog(1);
			break;
		}
		if ((AfxMessageBox(_T("File Already Exists. Do You Want to Open it?"), MB_YESNO), MB_APPLMODAL) == IDYES) {

			if (!file.Open(path, CFile::modeNoTruncate, &pError)) {
				AfxMessageBox(_T("Error"));
				return;
			}

			EndDialog(1);
			break;
		}
	}
	case 0: {
		break;
	}
	default: {
		AfxMessageBox(_T("Error"));
	}
	}
}


void First::OnBnClickedOpenbut()
{
	
	CString string = _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
	CFileDialog filedlg(TRUE, nullptr, nullptr, OFN_FILEMUSTEXIST | OFN_ENABLEINCLUDENOTIFY, string, this);

	filedlg.m_ofn.lpstrInitialDir = path;
	INT_PTR pInt = filedlg.DoModal();

	if (pInt == IDOK) {
		path.Append(filedlg.GetPathName());
		EndDialog(1);
	}
}


void First::OnLbnDblclkList1()
{
	int x = C_List.GetCurSel();
	CString ItemSelected;
	CString random = _T("| ");

	C_List.GetText(x, ItemSelected);

	ItemSelected.Delete(0, ItemSelected.Find(random) + 2);

	for (int i = 0; i <= 4; i++) {
		int y = ItemSelected.CompareNoCase(rf[i]);

		if (y == 0) {
			path = static_cast<CPath>(ItemSelected);
			EndDialog(1);
			return;
		}
	}

AfxMessageBox(_T("Error"));
EndDialog(-1);
}


BOOL First::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PWSTR string;
	DWORD word;

	font.CreatePointFont(120, _T("Segoe UI"));
	C_List.SetFont(&font);

	SHGetKnownFolderPath(FOLDERID_Documents, 0, nullptr, &string);

	path.Append(static_cast<CString>(string));
	path.Append(_T("\\AbduTextEditor"));

	if (CreateDirectory(path, nullptr) == 0) {
		word = GetLastError();

		if (word == ERROR_PATH_NOT_FOUND) {
			AfxMessageBox(_T("Documents folder is missing"));
			EndDialog(-1);
		}
	}

	INT_PTR hope = rf.GetSize();
	
	BOOL burnout[5];
	
	if (hope != 0) {
		for (int i = 0; i <= 4; i++) {
			CPath peace = rf[i];
			if (peace.FileExists() == FALSE)
				burnout[i] = FALSE;
			else {
				burnout[i] = TRUE;
			}
		}
	}
	else {
		for (int i = 0; i <= 4; i++) {
			burnout[i] = FALSE;
		}
	}

	CString txt = _T(".txt");
	CPath laps;
	for (int i = 0; i <= 4; i++) {

		if (burnout[i] == TRUE) {
			
			laps.Append(rf[i]);
			laps.StripPath();
			laps.RemoveExtension();

			CString extra = laps + _T(" | ") + rf[i];

			C_List.InsertString(i, extra);
			C_List.SetItemHeight(i, 32);
		}
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	          	  // EXCEPTION: OCX Property Pages should return FALSE
}
