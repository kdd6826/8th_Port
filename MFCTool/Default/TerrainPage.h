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
};
