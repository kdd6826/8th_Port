#pragma once


// ColliderPage ��ȭ �����Դϴ�.

class ColliderPage : public CDialogEx
{
	DECLARE_DYNAMIC(ColliderPage)

public:
	ColliderPage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ColliderPage();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
