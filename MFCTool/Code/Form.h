#pragma once



// CForm �� ���Դϴ�.
#include "MapTool.h"
#include "afxcmn.h"


class TerrainPage;
class MeshPage;
class PKH;
class CForm : public CFormView
{
	DECLARE_DYNCREATE(CForm)

protected:
	CForm();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMapTool();
	

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

	TerrainPage	 *tab1;
	MeshPage	 *tab2;
	PKH	  		 *tab3;


	CTabCtrl m_Tab;
	virtual void OnInitialUpdate();
};

