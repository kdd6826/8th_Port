#pragma once


// MeshPage ��ȭ �����Դϴ�.

class MeshPage : public CDialogEx
{
	DECLARE_DYNAMIC(MeshPage)

public:
	MeshPage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~MeshPage();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
