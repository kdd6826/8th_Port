
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
#include "SphereMesh.h"
#include "Layer.h"
#include "NaviMesh.h"
#include "VertexManager.h"
#include "TerrainTri.h"
#include "MFCStaticMesh.h"
#include "MFCDynamicMesh.h"


#include "MeshPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCToolView
HWND g_hWnd;
HINSTANCE g_hInst;
IMPLEMENT_DYNCREATE(CMFCToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCToolView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

CMFCToolView* CMFCToolView::m_pInstance = nullptr;
// CMFCToolView 생성/소멸
CMFCToolView::CMFCToolView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	if (nullptr == m_pInstance) {
		m_pInstance = this;
	}
	
}

CMFCToolView::~CMFCToolView()
{
	
	CTexture_Manager::DestroyInstance();
	Engine::CRenderer::GetInstance()->Clear_RenderGroup();
	Engine::Release_Utility();
	Engine::Release_Resoures();
	Safe_Release(m_pGraphicDev);

	VertexManager::DestroyInstance();
	auto& iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), Engine::CTag_Finder(L"Environment"));
	if (iter == m_mapLayer.end())
		return;
	for (auto& obj : iter->second->m_mapObject)
	{
		obj.second->Release();
	}
	Engine::Safe_Release(m_Camera);
	iter->second->m_mapObject.clear();

	//Engine::Release_System(); //이게 안되서 안에꺼에서 일부분만 처리해줌
	{
		Engine::CInputDev::GetInstance()->DestroyInstance();
		Engine::CFontMgr::GetInstance()->DestroyInstance();
		Engine::CFrameMgr::GetInstance()->DestroyInstance();
		Engine::CTimerMgr::GetInstance()->DestroyInstance();
		
	}
	
}

BOOL CMFCToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCToolView 그리기

HRESULT CMFCToolView::SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev)
{

	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd, Engine::MODE_WIN, WINCX, WINCY, &m_pDeviceClass), E_FAIL);
	Engine::Safe_AddRef(m_pDeviceClass);

	*ppGraphicDev = m_pDeviceClass->Get_GraphicDev();
	Engine::Safe_AddRef(*ppGraphicDev);

	// InputDev 설치
	FAILED_CHECK_RETURN(Engine::Ready_InputDev(AfxGetInstanceHandle(), g_hWnd), E_FAIL);

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

	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	return S_OK;
}

HRESULT CMFCToolView::Ready_Environment_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	
	Engine::CGameObject*		pGameObject = nullptr;

	//pGameObject = CSkyBox::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkyBox", pGameObject), E_FAIL);

	pGameObject = new CMFC_Terrain(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Terrain", pGameObject), E_FAIL);
	m_pTerrain = dynamic_cast<CMFC_Terrain*>(pGameObject);
	m_pTerrain->Ready_Object();
	
	//pGameObject = new CNaviMesh(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Navi", pGameObject), E_FAIL);
	//pGameObject = CTerrain::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Terrain", pGameObject), E_FAIL);
	//pGameObject->Ready_Object();
	//list_Object.emplace_back(pGameObject);

	m_Camera = CDynamicCamera::Create(m_pGraphicDev, &_vec3(1.f, 5.f, -1.f),
		&_vec3(10.f, 0.f, 10.f),
		&_vec3(0.f, 1.f, 0.f));
	pGameObject = m_Camera;
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DynamicCamera", pGameObject), E_FAIL);

	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CMFCToolView::Ready_GameLogic_Layer(const _tchar* pLayerTag)
{
	Engine::CLayer* pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject* pGameObject = nullptr;
		
	//pGameObject = CStaticMesh::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Stone", pGameObject), E_FAIL);
	


	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}






void CMFCToolView::LoadStaticMesh(CString _mesh, _vec3 pos, _vec3 scal, _vec3 angle)
{
	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CMFCStaticMesh::Create(m_pGraphicDev, _mesh);
	NULL_CHECK_RETURN(pGameObject, );
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Pos(&pos);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Scale(scal.x, scal.y, scal.z);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_X, angle.x);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Y, angle.y);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Z, angle.z);
	vectorObjStatic.emplace_back(dynamic_cast<CMFCStaticMesh*>(pGameObject));
	//LayerAddObject(L"Environment", _mesh, pGameObject);
}

void CMFCToolView::LoadDynamicMesh(CString _mesh, _vec3 pos, _vec3 scal, _vec3 angle)
{
	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CMFCDynamicMesh::Create(m_pGraphicDev, _mesh);
	NULL_CHECK_RETURN(pGameObject, );
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Pos(&pos);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Scale(scal.x, scal.y, scal.z);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_X, angle.x);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Y, angle.y);
	dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Z, angle.z);
	vectorObjDynamic.emplace_back(dynamic_cast<CMFCDynamicMesh*>(pGameObject));
}

void CMFCToolView::CreateStaticMesh(CString _mesh)
{
	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CMFCStaticMesh::Create(m_pGraphicDev,_mesh);
	NULL_CHECK_RETURN(pGameObject, );
	vectorObjStatic.emplace_back(dynamic_cast<CMFCStaticMesh*>(pGameObject));
	//LayerAddObject(L"Environment", _mesh, pGameObject);
}

void CMFCToolView::CreateDynamicMesh(CString _mesh)
{
	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CMFCDynamicMesh::Create(m_pGraphicDev, _mesh);
	NULL_CHECK_RETURN(pGameObject, );
	vectorObjDynamic.emplace_back(dynamic_cast<CMFCDynamicMesh*>(pGameObject));
	//LayerAddObject(L"Environment", _mesh, pGameObject);
}

void CMFCToolView::CreateDynamicMesh_OfCollider(CString _mesh)
{
	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CMFCDynamicMesh::Create(m_pGraphicDev, _mesh);
	NULL_CHECK_RETURN(pGameObject, );
	vectorObjDynamic_Collider.emplace_back(dynamic_cast<CMFCDynamicMesh*>(pGameObject));
	//LayerAddObject(L"Environment", _mesh, pGameObject);
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	FAILED_CHECK_RETURN(SetUp_DefaultSetting(&m_pGraphicDev), );
	/*FAILED_CHECK_RETURN(Ready_Scene(m_pGraphicDev, &m_pManagementClass), );*/

	Client::Safe_Release(m_pDeviceClass);

	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Default", L"바탕", 15, 20, FW_HEAVY), );
	FAILED_CHECK_RETURN(Engine::Ready_Font(m_pGraphicDev, L"Font_Jinji", L"궁서", 30, 30, FW_HEAVY), );


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
	////////
	FAILED_CHECK_RETURN(Ready_Environment_Layer(L"Environment"));
	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"));
	// Calculator
	Engine::CComponent* pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	NULL_CHECK_RETURN(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);



	//m_Camera->m_vEye = { 0.f, 5.f, -10.f };
	//m_Camera->m_vAt = { -1.6f, 4.1f, -5.3f };
	//RenderLine();
}

/////////////////////////////////////////////////////////////////////////////////////////////////// Update

void CMFCToolView::Update(float deltaTime)
{	
	

	Key_Input(deltaTime);

	///////////////// Update
	//auto&	iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), Engine::CTag_Finder(L"Environment"));
	//if (iter == m_mapLayer.end())
	//	return;
	////iter->second->Get_mapObject();
	for (auto& iter = m_mapLayer.begin(); iter != m_mapLayer.end(); iter++)
	{
		for (auto iter2 = iter->second->m_mapObject.begin(); iter2 != iter->second->m_mapObject.end();)
		{
			int dead = iter2->second->Update_Object(deltaTime);
			if (dead == 1) {
				Engine::Safe_Release(iter2->second);
				if (0 == lstrcmpW(L"TerrainTri", iter2->first))
				{
					iter2 = iter->second->m_mapObject.erase(iter2);
					Sort_TriNumber();
				}
				else
				{
					iter2 = iter->second->m_mapObject.erase(iter2);
				}
			}
			else {
				iter2++;
			}
		}
	}
	m_Camera->Update_Object(deltaTime);

	//스태틱매쉬
	for (auto& iterator = vectorObjStatic.begin(); iterator != vectorObjStatic.end();)
	{
		if (dynamic_cast<CMFCStaticMesh*>(*iterator)->isDead == true)
		{
			//Engine::Safe_Release(*iterator);
			iterator = vectorObjStatic.erase(iterator);
		}
		else
		{
			(*iterator)->Update_Object(deltaTime);
			iterator++;
		}
	}
	//다이나믹매쉬
	for (auto& iterator = vectorObjDynamic.begin(); iterator != vectorObjDynamic.end();)
	{
		if (dynamic_cast<CMFCDynamicMesh*>(*iterator)->isDead == true)
		{
			//Engine::Safe_Release(*iterator);
			iterator = vectorObjDynamic.erase(iterator);
		}
		else
		{
			(*iterator)->Update_Object(deltaTime);
			iterator++;
		}
	}
	/////다이나믹매쉬 콜라이더
	for (auto& iterator = vectorObjDynamic_Collider.begin(); iterator != vectorObjDynamic_Collider.end();)
	{
		if (dynamic_cast<CMFCDynamicMesh*>(*iterator)->isDead == true)
		{
			Engine::Safe_Release(*iterator);
			iterator = vectorObjDynamic_Collider.erase(iterator);
		}
		else
		{
			(*iterator)->Update_Object(deltaTime);
			iterator++;
		}
	}
	//

	///////////////// Render
	Engine::Render_Begin(D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.f));
	if (wireFrame) {
		m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	}
	else {
		m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}
	Engine::CRenderer* r = Engine::CRenderer::GetInstance();

	r->Render_GameObject(m_pGraphicDev);
	/*for (auto& obj : iter->second->m_mapObject)
	{
		obj.second->Render_Object();
		Engine::Safe_Release(iter);
	}*/
	
	Engine::Render_End();

	RenderLine();
}

void CMFCToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	

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

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_Sphere",
		Engine::BUFFER_SPHERE),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_ObjSphere",
		Engine::BUFFER_OBJSPHERE),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_CollSphere",
		Engine::BUFFER_COLLSPHERE),
		E_FAIL);
	//Cube
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_CubeTex",
		Engine::BUFFER_CUBETEX),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_TriCol",
		Engine::BUFFER_TRICOL),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Stone",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
		L"TombStone.X"),
		E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//	Engine::RESOURCE_STAGE,
	//	L"Mesh_Navi",
	//	Engine::TYPE_NAVI,
	//	NULL,
	//	NULL),
	//	E_FAIL);








	//Component
	Engine::CComponent* pComponent = nullptr;

	pComponent = Engine::CTransform::Create();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Transform", pComponent);

	pComponent = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Calculator", pComponent);

	pComponent = Engine::COptimization::Create(m_pGraphicDev, true, VTXCNTX, VTXCNTZ);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Optimization", pComponent);




	return S_OK;
}

void CMFCToolView::RenderLine() {
	_matrix		matView, matProj;

	// 뷰 스페이스 변환 행렬 생성 함수(즉, 카메라 월드 행렬의 역 행렬을 만들어주는 함수)
	D3DXMatrixLookAtLH(&matView, // 행렬 결과
		&m_Camera->m_vEye, // eye(카메라 위치)
		&m_Camera->m_vAt,	// at(카메라가 바라보는 위치)
		&_vec3(0.f, 1.f, 0.f)); // up(카메라와 수직을 이루는 방향)

								// 원근 투영 행렬 생성 함수
	D3DXMatrixPerspectiveFovLH(&matProj, // 행렬 결과
		D3DXToRadian(60.f),		// fovY
		(_float)WINCX / WINCY,	// 종횡비
		0.1f,	// 절두체의 near 평면의 z값
		1000.f); // 절두체의 far 평면의 z값

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &matProj);
}

Engine::CComponent* CMFCToolView::Get_Component(const _tchar* pLayerTag, const _tchar* pObjTag, const _tchar* pComponentTag, Engine::COMPONENTID eID)
{
	auto	iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), Engine::CTag_Finder(pLayerTag));

	if (iter == m_mapLayer.end())
		return nullptr;

	return iter->second->Get_Component(pObjTag, pComponentTag, eID);
}

_vec3 CMFCToolView::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));
	_vec3 Temp = m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
	return Temp;
	//return{ 0.f, 0.f, 0.f };
}


void CMFCToolView::LayerAddObject(const _tchar* pLayerTag, const _tchar* pObjTag, Engine::CGameObject* pGameObject) {
	auto	iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), Engine::CTag_Finder(pLayerTag));

	if (iter == m_mapLayer.end())
		return;

	iter->second->Add_GameObject(pObjTag, pGameObject);
}

void CMFCToolView::Key_Input(float deltaTime) {
	Engine::Set_InputDev();
	//m_Camera->Update_Object(deltaTime);
	
	VertexManager::GetInstance()->Key_Input(deltaTime);
	
}

CTerrainTri* CMFCToolView::PickUp_Tri(void)
{
	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, nullptr);

	POINT		ptMouse{ 0 };

	GetCursorPos(&ptMouse);
	::ScreenToClient(g_hWnd, &ptMouse);

	Engine::_vec3	vMousePos;

	D3DVIEWPORT9		ViewPort;
	ZeroMemory(&ViewPort, sizeof(D3DVIEWPORT9));
	m_pGraphicDev->GetViewport(&ViewPort);

	// 뷰포트 -> 투영

	vMousePos.x = (ptMouse.x / (ViewPort.Width * 0.5f)) - 1.f;
	vMousePos.y = (ptMouse.y / -(ViewPort.Height * 0.5f)) + 1.f;
	vMousePos.z = 0.f;

	// L * W * V * P * (P^-1)
	// L * W * V

	// 투영 -> 뷰 스페이스
	Engine::_matrix	matProj;
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	D3DXMatrixInverse(&matProj, NULL, &matProj);
	D3DXVec3TransformCoord(&vMousePos, &vMousePos, &matProj);

	// 뷰 스페이스 -> 월드
	Engine::_matrix	matView;
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	D3DXMatrixInverse(&matView, NULL, &matView);

	Engine::_vec3	vRayPos, vRayDir;


	vRayPos = Engine::_vec3(0.f, 0.f, 0.f);
	vRayDir = vMousePos - vRayPos;

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matView);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matView);

	// 월드 -> 로컬
	Engine::_matrix	matWorld;
	pTerrainTransformCom->Get_WorldMatrix(&matWorld);
	D3DXMatrixInverse(&matWorld, NULL, &matWorld);

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matWorld);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matWorld);

	///////
	map<const Engine::_tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return nullptr;
	multimap<const Engine::_tchar*, Engine::CGameObject*>* m_mapObject = &dynamic_cast<Engine::CLayer*>(iter->second)->m_mapObject;
	for (auto& iter2 = (*m_mapObject).begin(); iter2 != (*m_mapObject).end();)
	{
		if (0 == lstrcmpW(L"TerrainTri", (*iter2).first))
		{
			Engine::_float	fU, fV, fDist;
			CTerrainTri* tri = dynamic_cast<CTerrainTri*>((*iter2).second);
			if (D3DXIntersectTri(tri->m_Cell->Get_Point(Engine::CCell::POINT_A),
				tri->m_Cell->Get_Point(Engine::CCell::POINT_B),
				tri->m_Cell->Get_Point(Engine::CCell::POINT_C), &vRayPos, &vRayDir, &fU, &fV, &fDist))
			{
				return tri;
			}
		}
		iter2++;
		

	}
	return nullptr;
}

void CMFCToolView::Sort_TriNumber()
{
	map<const Engine::_tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return;

	int triCount = 0;
	for (auto& iter2 = iter->second->m_mapObject.begin(); iter2 != iter->second->m_mapObject.end();)
	{
		if (0 == lstrcmpW(L"TerrainTri", iter2->first))
		{
			dynamic_cast<CTerrainTri*>(iter2->second)->m_Cell->Set_Index(triCount);
			triCount++;
		}
		iter2++;
	}
}

CTerrainTri* CMFCToolView::Get_TriOfNumber(int number)
{
	Sort_TriNumber();

	map<const Engine::_tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return nullptr;

	for (auto& iter2 = iter->second->m_mapObject.begin(); iter2 != iter->second->m_mapObject.end();)
	{
		if (0 == lstrcmpW(L"TerrainTri", iter2->first))
		{
			if (*dynamic_cast<CTerrainTri*>(iter2->second)->m_Cell->Get_Index() == number)
			{
				return dynamic_cast<CTerrainTri*>(iter2->second);
			}
		}
		iter2++;
	}

	return nullptr;
}

vector<Engine::CCell*> CMFCToolView::Get_VectorTri(int* _triNumber)
{
	Sort_TriNumber();
	vector<Engine::CCell*> vec_tri;

	map<const Engine::_tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return vec_tri;

	for (auto& iter2 = iter->second->m_mapObject.begin(); iter2 != iter->second->m_mapObject.end();)
	{
		if (0 == lstrcmpW(L"TerrainTri", iter2->first))
		{
			//////
			CTerrainTri* tri =  dynamic_cast<CTerrainTri*>(iter2->second);
			vec_tri.emplace_back(tri->m_Cell);
			*_triNumber++;
			//////
		}
		iter2++;
	}

	return vec_tri;
}

void CMFCToolView::CreateTerrain(int _countX, int _countZ, int _interval, int _detail)
{
	


	////Buffer
	//FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
	//	Engine::RESOURCE_STATIC,
	//	L"Buffer_TerrainTex",
	//	Engine::BUFFER_TERRAINTEX,
	//	VTXCNTX,
	//	VTXCNTZ,
	//	VTXITV),
	//	E_FAIL);

	CString createNum;
	createNum.Format(_T("%d"), CreateTerrainCount);
	Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		createNum,
		Engine::BUFFER_TERRAINTEX,
		_countX,
		_countZ,
		1);
		

	Engine::CGameObject* pGameObject = nullptr;

	//pGameObject = CSkyBox::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkyBox", pGameObject), E_FAIL);

	pGameObject = new CMFC_Terrain(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, );
	LayerAddObject(L"Environment", createNum, pGameObject);
	
	m_pTerrain = dynamic_cast<CMFC_Terrain*>(pGameObject);
	m_pTerrain->Ready_Object(CreateTerrainCount);
	CreateTerrainCount++;
}
