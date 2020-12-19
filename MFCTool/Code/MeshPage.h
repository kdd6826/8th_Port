#pragma once
#include "afxwin.h"
#include "NaviMesh.h"
#include "afxcmn.h"

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

	HTREEITEM objDynamic,objStatic, tri[128] , vertex[128][3], objCreateItem, objCreateItemSon[3][128];
	int objStaticCreateCount = 0;
	int objDynamicCreateCount = 0;
	int objCreateItemSonCount=0;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int staticLoadCount = 0;
	int dynamicLoadCount = 0;
	void treeControl(int triCount);

	CTreeCtrl treeNavi;
	HTREEITEM selectItem,lastStaticObjSelectItem, lastDynamicObjSelectItem, lastNaviMeshSelectItem;
	int lastSphereIndex = -1;
	afx_msg void OnBnClickedButton10();

	void InitTreeCtrl();

	afx_msg void OnNMClickNaviTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickObjCreateTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickObjStaticTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickObjDynamicTree(NMHDR *pNMHDR, LRESULT *pResult);

	void CheckChildItems(HTREEITEM _hItem);
	void UnCheckChildItems(HTREEITEM _hItem);

	
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
	float m_fTransformScalX = 0;
	float m_fTransformScalY=0;
	float m_fTransformScalZ=0;
	float m_fTransformRotX=0;
	float m_fTransformRotY=0;
	float m_fTransformRotZ=0;

	int vertexCount = 0;
	int indexCount = 0;

	afx_msg void TransformPosXSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformPosYSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformPosZSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformRotXSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformRotYSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformRotZSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformScalXSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformScalYSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void TransformScalZSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void ObjectRadioBnClicked();
	afx_msg void NaviRadioBnClicked();
	//스태틱
	afx_msg void OnBnClickedRadio7();
	//다이나믹
	afx_msg void OnBnClickedRadio8();

	afx_msg void OnBnClickedStaticSave();
	afx_msg void OnBnClickedStaticLoad();
	afx_msg void OnBnClickedDynamicSave();
	afx_msg void OnBnClickedDynamicLoad();
	//SAVE
	afx_msg void OnBnClickedNaviSave();
	//LOAD
	afx_msg void OnBnClickedNaviLoad();
	CTreeCtrl treeObjCreate;
	CTreeCtrl treeObjStatic;
	CTreeCtrl treeObjDynamic;
	

	afx_msg void OnBnClickedObjStaticDelete();
	//transformScalX
	afx_msg void OnEnChangeTransformScalX();
	afx_msg void OnEnChangeTransformScalY();
	afx_msg void OnEnChangeTransformScalZ();
	afx_msg void OnEnChangeTransformRotX();
	afx_msg void OnEnChangeTransformRotY();
	afx_msg void OnEnChangeTransformRotZ();
	afx_msg void OnEnChangeTransformPosX();
	afx_msg void OnEnChangeTransformPosY();
	afx_msg void OnEnChangeTransformPosZ();

	void LockOnTree();
	bool lockOnCheck = false;
};
