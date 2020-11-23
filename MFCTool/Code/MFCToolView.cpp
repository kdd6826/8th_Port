
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
#include "MainFrm.h"

#include "Form.h"

#include "Stage.h"
#include "Terrain.h"
#include "MFC_Terrain.h"

#include "GameObject.h"
#include "DynamicMesh.h"
#include "DynamicCamera.h"
#include "TimerMgr.h"
#include "Renderer.h"
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
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

CMFCToolView* CMFCToolView::m_pInstance = nullptr;
// CMFCToolView ����/�Ҹ�
CMFCToolView::CMFCToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	if (nullptr == m_pInstance) {
		m_pInstance = this;
	}
	
}

CMFCToolView::~CMFCToolView()
{
	CGraphic_Device::DestroyInstance();
	CTexture_Manager::DestroyInstance();
	Engine::CRenderer::GetInstance()->Clear_RenderGroup();
	Engine::Release_Utility();
	Engine::Release_Resoures();
	Safe_Release(m_pGraphicDev);
	
	for (auto& obj : list_Object) {
		obj->Release();
	}
	list_Object.clear();

	//Engine::Release_System(); //�̰� �ȵǼ� �ȿ������� �Ϻκи� ó������
	{
		//Engine::CInputDev::GetInstance()->DestroyInstance();
		Engine::CFontMgr::GetInstance()->DestroyInstance();
		Engine::CFrameMgr::GetInstance()->DestroyInstance();
		Engine::CTimerMgr::GetInstance()->DestroyInstance();
		//Engine::CGraphicDev::GetInstance()->DestroyInstance();
	}
	
}

BOOL CMFCToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCToolView �׸���

HRESULT CMFCToolView::SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev)
{

	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd, Engine::MODE_WIN, WINCX, WINCY, &m_pDeviceClass), E_FAIL);
	Engine::Safe_AddRef(m_pDeviceClass);

	*ppGraphicDev = m_pDeviceClass->Get_GraphicDev();
	Engine::Safe_AddRef(*ppGraphicDev);

	// InputDev ��ġ
	/*FAILED_CHECK_RETURN(Engine::Ready_InputDev(g_hInst, g_hWnd), E_FAIL);*/

	return S_OK;
}

HRESULT CMFCToolView::Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::CManagement** ppManagement)
{
	Engine::CScene* pScene = nullptr;

	FAILED_CHECK_RETURN(Engine::Create_Management(ppManagement), E_FAIL);
	Safe_AddRef(*ppManagement);

	pScene = CStage::Create(pGraphicDev);
	NULL_CHECK_RETURN(pScene, E_FAIL);

	FAILED_CHECK_RETURN((*ppManagement)->SetUp_Scene(pScene), E_FAIL);

	return S_OK;
}

void CMFCToolView::OnDraw(CDC* /*pDC*/)
{
	CMFCToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	Engine::Render_Begin(D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.f));

	//m_pTerrain->Render_Object();

	Engine::Render_End();

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

	SetScrollSizes(MM_TEXT, CSize(TILECX * TILEX, (TILECY >> 1) * TILEY));
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
	float fYGap = WINCY + (float(rcMain.bottom) - rcView.bottom);

	pMain->SetWindowPos(nullptr, 0, 0, LONG(WINCX + fXGap), LONG(fYGap), SWP_NOZORDER);






	g_hWnd = m_hWnd;
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	FAILED_CHECK_RETURN(SetUp_DefaultSetting(&m_pGraphicDev), );
	/*FAILED_CHECK_RETURN(Ready_Scene(m_pGraphicDev, &m_pManagementClass), );*/

	Client::Safe_Release(m_pDeviceClass);

	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Default", L"����", 15, 20, FW_HEAVY), );
	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Jinji", L"�ü�", 30, 30, FW_HEAVY), );

	Engine::CLayer* pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, );

	//if (nullptr == m_pTerrain)
	//{
	//	Engine::CGameObject*		pGameObject = nullptr;
	//	pGameObject = CTerrain::Create(m_pGraphicDev);
	//	NULL_CHECK_RETURN(pGameObject, );
	//	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Terrain", pGameObject), );
	//}

	if (FAILED(Loading()))
	{
		MessageBox(L"Loading Failed in View");
		return;
	}

	////
	Engine::CGameObject* obj = new CMFC_Terrain(m_pGraphicDev);
	m_pTerrain = dynamic_cast<CMFC_Terrain*>(obj);
	m_pTerrain->Ready_Object();
	list_Object.emplace_back(obj);

	m_Camera = CDynamicCamera::Create(m_pGraphicDev, &_vec3(1.f, 5.f, -1.f),
		&_vec3(10.f, 0.f, 10.f),
		&_vec3(0.f, 1.f, 0.f));
	Engine::CGameObject* pGameObject = m_Camera;
	NULL_CHECK_RETURN(pGameObject);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DynamicCamera", pGameObject));
	list_Object.emplace_back(pGameObject);


	m_Camera->m_vEye = { 0.f, 5.f, -10.f };
	m_Camera->m_vAt = {0.f, 5.f, -10.f};
	RenderLine();
}


void CMFCToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//int i = 0; 
 //	TCHAR szMouseBuf[54]= L""; 
 //	swprintf_s(szMouseBuf, L"Point.x : %d, Point.y : %d", point.x, point.y);
 //	ERR_MSG(szMouseBuf);
	//CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	//CForm* pForm = dynamic_cast<CForm*>(pMain->m_SecondSplitter.GetPane(1, 0));
	//_int iDrawID = pForm->m_tMapTool.m_iDrawID;
	//_vec3 vMouse = { float(point.x) + GetScrollPos(0), float(point.y) + GetScrollPos(1), 0.f }; 

	//m_pTerrain->TileChange(vMouse, iDrawID,1);

	//CScrollView::OnLButtonDown(nFlags, point);



}

void CMFCToolView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	float iTemp = 0.2f;
	if (!m_bCameraAddX) {
		if (m_CameraAtDir.x >= 1.f) {
			m_CameraAtDir.x -= iTemp;
			m_bCameraAddX = true;
		}
		else
			m_CameraAtDir.x += iTemp;
	}
	else {
		if (m_CameraAtDir.x <= -1.f) {
			m_CameraAtDir.x += iTemp;
			m_bCameraAddX = false;
		}
		else
			m_CameraAtDir.x -= iTemp;
	}

	if (!m_bCameraAddZ) {
		if (m_CameraAtDir.z >= 1.f) {
			m_CameraAtDir.z -= iTemp;
			m_bCameraAddZ = true;
		}
		else
			m_CameraAtDir.z += iTemp;
	}
	else {
		if (m_CameraAtDir.z <= -1.f) {
			m_CameraAtDir.z += iTemp;
			m_bCameraAddZ = false;
		}
		else
			m_CameraAtDir.z -= iTemp;
	}
	D3DXVec3Normalize(&m_Camera->m_vAt, &m_CameraAtDir);
	m_Camera->m_vAt *= 5.f;
	m_Camera->m_vAt += m_Camera->m_vEye;


}

void CMFCToolView::Update(float deltaTime)
{
	CameraMove(deltaTime);

	/// Update
	for (auto& obj : list_Object) {
		obj->Update_Object(deltaTime);
	}



	/// Render
	Engine::Render_Begin(D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.f));

	Engine::CRenderer* r = Engine::CRenderer::GetInstance();
	r->Render_GameObject();
	Engine::Render_End();

	RenderLine();
}

HRESULT CMFCToolView::Loading()
{
	FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);

	//Buffer
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_TerrainTex",
		Engine::BUFFER_TERRAINTEX,
		VTXCNTX,
		VTXCNTZ,
		VTXITV),
		E_FAIL);

	//Texture
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Terrain",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Texture/Terrain/Grass_%d.tga", 2),
		E_FAIL);

	//Component
	Engine::CComponent* pComponent = nullptr;

	pComponent = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Transform", pComponent);

	return S_OK;
}

void CMFCToolView::RenderLine() {
	_matrix		matView, matProj;

	// �� �����̽� ��ȯ ��� ���� �Լ�(��, ī�޶� ���� ����� �� ����� ������ִ� �Լ�)
	D3DXMatrixLookAtLH(&matView, // ��� ���
		&m_Camera->m_vEye, // eye(ī�޶� ��ġ)
		&m_Camera->m_vAt,	// at(ī�޶� �ٶ󺸴� ��ġ)
		&_vec3(0.f, 1.f, 0.f)); // up(ī�޶�� ������ �̷�� ����)

								// ���� ���� ��� ���� �Լ�
	D3DXMatrixPerspectiveFovLH(&matProj, // ��� ���
		D3DXToRadian(60.f),		// fovY
		(_float)WINCX / WINCY,	// ��Ⱦ��
		0.1f,	// ����ü�� near ����� z��
		1000.f); // ����ü�� far ����� z��

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &matProj);
}

void CMFCToolView::CameraMove(float deltaTime) {
	if (GetAsyncKeyState('W') & 0x8000) {
		m_Camera->m_vEye.x += m_CameraAtDir.x * moveSpeed * deltaTime;
		m_Camera->m_vEye.z += m_CameraAtDir.z * moveSpeed * deltaTime;
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		m_Camera->m_vEye.x -= m_CameraAtDir.x * moveSpeed * deltaTime;
		m_Camera->m_vEye.z -= m_CameraAtDir.z * moveSpeed * deltaTime;
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		m_Camera->m_vEye.x -= m_CameraAtDir.z * moveSpeed * deltaTime;
		m_Camera->m_vEye.z += m_CameraAtDir.x * moveSpeed * deltaTime;
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		m_Camera->m_vEye.x += m_CameraAtDir.z * moveSpeed * deltaTime;
		m_Camera->m_vEye.z -= m_CameraAtDir.x * moveSpeed * deltaTime;
	}


	m_Camera->m_vAt.x = m_Camera->m_vEye.x + m_CameraAtDir.x * moveSpeed * deltaTime;
	m_Camera->m_vAt.z = m_Camera->m_vEye.z + m_CameraAtDir.z * moveSpeed * deltaTime;
}