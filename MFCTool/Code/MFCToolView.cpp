
// MFCToolView.cpp : CMFCToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
HWND g_hWnd; 
HINSTANCE g_hInst;
IMPLEMENT_DYNCREATE(CMFCToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCToolView ����/�Ҹ�
CMFCToolView::CMFCToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCToolView::~CMFCToolView()
{
	CGraphic_Device::DestroyInstance(); 
	CTexture_Manager::DestroyInstance(); 

}

BOOL CMFCToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCToolView �׸���

HRESULT CMFCToolView::SetUp_DefaultSetting(LPDIRECT3DDEVICE9 * ppGraphicDev)
{
	
	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd, Engine::MODE_WIN, WINCX, WINCY, &m_pDeviceClass), E_FAIL);
	Engine::Safe_AddRef(m_pDeviceClass);

	*ppGraphicDev = m_pDeviceClass->Get_GraphicDev();
	Engine::Safe_AddRef(*ppGraphicDev);

	// InputDev ��ġ
	/*FAILED_CHECK_RETURN(Engine::Ready_InputDev(g_hInst, g_hWnd), E_FAIL);*/

	return S_OK;
}

HRESULT CMFCToolView::Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::CManagement ** ppManagement)
{
	//Engine::CScene*		pScene = nullptr;

	//FAILED_CHECK_RETURN(Engine::Create_Management(ppManagement), E_FAIL);
	//Safe_AddRef(*ppManagement);

	//pScene = CLogo::Create(pGraphicDev);
	//NULL_CHECK_RETURN(pScene, E_FAIL);

	//FAILED_CHECK_RETURN((*ppManagement)->SetUp_Scene(pScene), E_FAIL);

	return S_OK;
}

void CMFCToolView::OnDraw(CDC* /*pDC*/)
{
	CMFCToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CGraphic_Device::GetInstance()->Render_Begin();
	
	m_pTerrain->Render_Terrain();
	
	CGraphic_Device::GetInstance()->Render_End();
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
// 	pDC->Rectangle(100, 100, 200, 200);
// 	pDC->Ellipse(100, 100, 200, 200);
}


// CMFCToolView �μ�

BOOL CMFCToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCToolView ����

#ifdef _DEBUG
void CMFCToolView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCToolDoc* CMFCToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCToolDoc)));
	return (CMFCToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCToolView �޽��� ó����


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

	


	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	FAILED_CHECK_RETURN(SetUp_DefaultSetting(&m_pGraphicDev), );
	//FAILED_CHECK_RETURN(Ready_Scene(m_pGraphicDev, &m_pManagementClass), );

	Client::Safe_Release(m_pDeviceClass);

	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Default", L"����", 15, 20, FW_HEAVY), );
	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Jinji", L"�ü�", 30, 30, FW_HEAVY), );

	g_hWnd = m_hWnd; 
	if (FAILED(CGraphic_Device::GetInstance()->Ready_Graphic_Device()))
	{
		ERR_MSG(L"�׷��� ����̽� ���� ����..."); 
		return; 
	}
	if (FAILED(CTexture_Manager::GetInstance()->Insert_Texture(CTexture_Manager::TEX_SINGLE, L"../Bin/Texture/Cube.png", L"Cube")))
		return; 

	if (FAILED(CTexture_Manager::GetInstance()->Insert_Texture(CTexture_Manager::TEX_MULTI, L"../Bin/Texture/Stage/Terrain/Tile/Tile%d.png", L"Terrain", L"Tile", 38)))
		return;

	if (nullptr == m_pTerrain)
	{
		m_pTerrain = new CTerrain; 
		m_pTerrain->Ready_Terrain(); 
		m_pTerrain->Set_View(this);
	}
}


void CMFCToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
