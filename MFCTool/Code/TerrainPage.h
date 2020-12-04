#pragma once


// TerrainPage ��ȭ �����Դϴ�.

class TerrainPage : public CDialogEx
{
	DECLARE_DYNAMIC(TerrainPage)

public:
	TerrainPage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TerrainPage();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio1();
//	CButton Render_Solid;
//	CButton Render_WireFrame;
	afx_msg void OnBnClickedRadio2();
	
	CButton Render_Solid;
	CButton Render_WireFrame;
	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedTerrainApply();
	CEdit xCount;
	CEdit zCount;
	CEdit interval;
	CEdit detail;
	int iXCount=2, iZCount=2, iInterval, iDetail;
	afx_msg void OnXCountSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnZCountSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin5(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedLoad();
};
