#pragma once


// Name dialog

class Name : public CDialogEx
{
	DECLARE_DYNAMIC(Name)

public:
	Name(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Name();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = NameDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ENameBox;
	CString m_Text;
	CButton m_BCreate;
	afx_msg void OnBnClickedCreatebut();
};
