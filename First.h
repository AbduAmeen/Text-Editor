#pragma once


// First dialog

class First : public CDialogEx
{
	DECLARE_DYNAMIC(First)

public:
	First(CWnd* pParent = nullptr);   // standard constructor
	virtual ~First();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = FirstDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton C_Create;
	CButton C_Open;
	CListBox C_List;
	CPath path;
	CStringArray rf;
	CFont font;
	afx_msg void OnBnClickedCreatebut();
	afx_msg void OnBnClickedOpenbut();
	afx_msg void OnLbnDblclkList1();
	virtual BOOL OnInitDialog();
};
