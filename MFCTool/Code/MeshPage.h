#pragma once
#include "afxwin.h"
#include "NaviMesh.h"

// MeshPage 대화 상자입니다.

class MeshPage : public CDialogEx
{
	DECLARE_DYNAMIC(MeshPage)
	DECLARE_SINGLETON(MeshPage)
public:
	MeshPage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~MeshPage();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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

	HTREEITEM tri[128] , vertex[128][3];
	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	
	void treeControl(int triCount);

	CTreeCtrl treeNavi;
	HTREEITEM selectItem;
	int lastSphereIndex=-1;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnNMClickTree4(NMHDR *pNMHDR, LRESULT *pResult);
	void CheckChildItems(HTREEITEM _hItem);
	void UnCheckChildItems(HTREEITEM _hItem);

	afx_msg void OnEnChangeEdit14();
	CEdit transformPosX;
	CEdit transformPosY;
	CEdit transformPosZ;
	CEdit transformScalX;
	CEdit transformScalY;
	CEdit transformScalZ;
	CEdit transformRotX;
	CEdit transformRotY;
	CEdit transformRotZ;
	float m_fTransformPosX=0;
	float m_fTransformPosY=0;
	float m_fTransformPosZ=0;
	float m_fTransformScalX=0;
	float m_fTransformScalY=0;
	float m_fTransformScalZ=0;
	float m_fTransformRotX=0;
	float m_fTransformRotY=0;
	float m_fTransformRotZ=0;

	int vertexCount = 0;
	int indexCount = 0;

	afx_msg void OnDeltaposSpin12(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin14(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin13(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin9(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin11(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin10(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin6(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin8(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin7(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio5();

	//SAVE
	afx_msg void OnBnClickedButton7();
	//LOAD
	afx_msg void OnBnClickedButton8();
};
