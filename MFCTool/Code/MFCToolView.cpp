
// MFCToolView.cpp : CMFCToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCTool.h"
#endif

#include "MFCToolDoc.h"
#include "MFCToolView.h"
#include "Texture_Manager.h"
#include "SingleTex.h"
#include "Terrain.h"
#include "MainFrm.h"

#include "Form.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCToolView
HWND g_hWND; 
IMPLEMENT_DYNCREATE(CMFCToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCToolView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCToolView 생성/소멸

CMFCToolView::CMFCToolView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CMFCToolView::~CMFCToolView()
{
	CGraphic_Device::DestroyInstance(); 
	CTexture_Manager::DestroyInstance(); 
	Safe_Delete(m_pTerrain);
}

BOOL CMFCToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCToolView 그리기

void CMFCToolView::OnDraw(CDC* /*pDC*/)
{
	CMFCToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CGraphic_Device::GetInstance()->Render_Begin(); 
	m_pTerrain->Render_Terrain();
	CGraphic_Device::GetInstance()->Render_End(); 
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
// 	pDC->Rectangle(100, 100, 200, 200);
// 	pDC->Ellipse(100, 100, 200, 200);
}


// CMFCToolView 인쇄

BOOL CMFCToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCToolView 진단

#ifdef _DEBUG
void CMFCToolView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCToolDoc* CMFCToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCToolDoc)));
	return (CMFCToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCToolView 메시지 처리기


void CMFCToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	
	SetScrollSizes(MM_TEXT,CSize(TILECX * TILEX, (TILECY >> 1) * TILEY));
	CMainFrame* pMain = dynamic_cast<CMainFrame*>(::AfxGetApp()->GetMainWnd());
	RECT rcMain = {}; 

	pMain->GetWindowRect(&rcMain);

	SetRect(&rcMain, 0, 0, rcMain.right - rcMain.left, rcMain.bottom - rcMain.top);

	//View 
	RECT rcView = {}; 
	GetClientRect(&rcView); ; 
	//1440, 760
	//1420, 698
	float fXGap = rcMain.right - float(rcView.right); 
	float fYGap =  WINCY+ (float(rcMain.bottom) - rcView.bottom); 
	
	pMain->SetWindowPos(nullptr, 0, 0, LONG(WINCX + fXGap),LONG(fYGap), SWP_NOZORDER);

	


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	g_hWND = m_hWnd; 
	if (FAILED(CGraphic_Device::GetInstance()->Ready_Graphic_Device()))
	{
		ERR_MSG(L"그래픽 디바이스 생성 실패..."); 
		return; 
	}
	//if (FAILED(CTexture_Manager::GetInstance()->Insert_Texture(CTexture_Manager::TEX_SINGLE, L"../Bin/Texture/Cube.png", L"Cube")))
	//	return; 

	//if (FAILED(CTexture_Manager::GetInstance()->Insert_Texture(CTexture_Manager::TEX_MULTI, L"../Bin/Texture/Stage/Terrain/Tile/Tile%d.png", L"Terrain", L"Tile", 38)))
	//	return;

	if (nullptr == m_pTerrain)
	{
		m_pTerrain = new CTerrain; 
		m_pTerrain->Ready_Terrain(); 
		m_pTerrain->Set_View(this);
	}
}


void CMFCToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int i = 0; 
// 	TCHAR szMouseBuf[54]= L""; 
// 	swprintf_s(szMouseBuf, L"Point.x : %d, Point.y : %d", point.x, point.y);
// 	ERR_MSG(szMouseBuf);
	CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CForm* pForm = dynamic_cast<CForm*>(pMain->m_SecondSplitter.GetPane(1, 0));
	_int iDrawID = pForm->m_tMapTool.m_iDrawID;
	_vec3 vMouse = { float(point.x) + GetScrollPos(0), float(point.y) + GetScrollPos(1), 0.f }; 

	m_pTerrain->TileChange(vMouse, iDrawID,1);

	InvalidateRect(nullptr, 0);
	CScrollView::OnLButtonDown(nFlags, point);
}
