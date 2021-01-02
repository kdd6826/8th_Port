#pragma once


// ColliderPage 대화 상자입니다.

class ColliderPage : public CDialogEx
{
	DECLARE_DYNAMIC(ColliderPage)

public:
	ColliderPage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ColliderPage();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	HTREEITEM objDynamic, objStatic, m_DynamicObjItem, objCreateItemSon[3][128];
	HTREEITEM selectItem;
	CTreeCtrl treeObjCreate;
	//CTreeCtrl treeObjStatic;
	//CTreeCtrl treeObjDynamic;
	int objStaticCreateCount = 0;
	int objDynamricCreateCount = 0;
	int objCreateItemSonCount = 0;
	int staticLoadCount = 0;
	int dynamicLoadCount = 0;
	afx_msg void OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//뼈 이름 리스트
	CListBox m_BoneList;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	void BoneColliderList_Renewal();
	int m_AniClip;
	CListBox m_BoneColliderList;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	float m_Radius;
	afx_msg void OnLbnSelchangeList2();
	
	float m_PosX;
	float m_PosY;
	float m_PosZ;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnDeltaposSpin13(NMHDR* pNMHDR, LRESULT* pResult);
	int meshRotY;
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	float m_fFrame;
	float m_fMaxFrame;
	//frame 변경
	afx_msg void OnBnClickedButton17();
};
