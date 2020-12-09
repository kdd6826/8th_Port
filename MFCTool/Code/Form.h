#pragma once



// CForm 폼 뷰입니다.
#include "MapTool.h"
#include "afxcmn.h"


class TerrainPage;
class MeshPage;
class ColliderPage;
class CForm : public CFormView
{
	DECLARE_DYNCREATE(CForm)

protected:
	CForm();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CForm();
public:
	CMapTool m_tMapTool; 

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMapTool();
	

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

	TerrainPage	 *tab1;
	MeshPage	 *tab2;
	ColliderPage	  		 *tab3;


	CTabCtrl m_Tab;
	bool isInitMeshPage = false;
	virtual void OnInitialUpdate();
};

