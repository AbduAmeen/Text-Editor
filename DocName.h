#pragma once


// DocName dialog

class DocName : public CDialogEx
{
	DECLARE_DYNAMIC(DocName)

public:
	DocName(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DocName();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = NameDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
