// TerrainPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "TerrainPage.h"
#include "afxdialogex.h"
#include "MFCToolView.h"

// TerrainPage 대화 상자입니다.

IMPLEMENT_DYNAMIC(TerrainPage, CDialogEx)

TerrainPage::TerrainPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

TerrainPage::~TerrainPage()
{
}

void TerrainPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, Render_Solid);
	//  DDX_Control(pDX, IDC_BUTTON1, Render_WireFrame);
	DDX_Control(pDX, IDC_RADIO1, Render_Solid);
	DDX_Control(pDX, IDC_RADIO2, Render_WireFrame);
	DDX_Control(pDX, IDC_EDIT1, xCount);
	DDX_Control(pDX, IDC_EDIT2, zCount);
	DDX_Control(pDX, IDC_EDIT3, interval);
	DDX_Control(pDX, IDC_EDIT4, detail);
}


BEGIN_MESSAGE_MAP(TerrainPage, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &TerrainPage::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &TerrainPage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &TerrainPage::OnBnClickedRadio2)
	
	ON_BN_CLICKED(IDC_BUTTON1, &TerrainPage::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &TerrainPage::OnBnClickedRadio1)
END_MESSAGE_MAP()


// TerrainPage 메시지 처리기입니다.


void TerrainPage::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TerrainPage::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TerrainPage::OnBnClickedRadio1()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCToolView::GetInstance()->wireFrame = false;
}


void TerrainPage::OnBnClickedRadio2()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCToolView::GetInstance()->wireFrame = true;
}


BOOL TerrainPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Render_Solid.SetCheck(BST_CHECKED);
	CMFCToolView::GetInstance()->wireFrame = true;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void TerrainPage::OnBnClickedButton1()
{

	// TODO: 해야함
	//map<const _tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;

	//auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Terrain"));
	//if (iter == (*m_map).end())
	//	return;
	//for (auto& obj : iter->second->m_mapObject)
	//{
	//	obj.second->Release();
	//}
	//iter->second->m_mapObject.clear();

	CString xNum = L"";
	CString zNum = L"";
	CString intervalNum = L"";
	CString detailNum = L"";

	xCount.GetWindowTextW(xNum);
	zCount.GetWindowTextW(zNum);
	interval.GetWindowTextW(intervalNum);
	detail.GetWindowTextW(detailNum);



}

