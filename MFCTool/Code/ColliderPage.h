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
	//�� �̸� ����Ʈ
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
	//frame ����
	afx_msg void OnBnClickedButton17();
};
