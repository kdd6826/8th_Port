#pragma once


// NaviPage ��ȭ �����Դϴ�.

class NaviPage : public CDialogEx
{
	DECLARE_DYNAMIC(NaviPage)

public:
	NaviPage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~NaviPage();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
