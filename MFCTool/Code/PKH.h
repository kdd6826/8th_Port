#pragma once


// PKH ��ȭ �����Դϴ�.

class PKH : public CDialogEx
{
	DECLARE_DYNAMIC(PKH)

public:
	PKH(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PKH();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
