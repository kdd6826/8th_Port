#pragma once


// TerrainPage 대화 상자입니다.

class TerrainPage : public CDialogEx
{
	DECLARE_DYNAMIC(TerrainPage)

public:
	TerrainPage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TerrainPage();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
