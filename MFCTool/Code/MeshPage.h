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
public:
	CButton Render_Solid;
	CButton Render_WireFrame;
//	CButton mouse_Objcet;
	CButton mouseObject;
	CButton mouseNaviMesh;
//	CButton typeDynamic;
	CButton typeStatic;
	CButton typeDynamic;
	CButton vertexTogetther;
	CButton vertexOnly;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};