#include "stdafx.h"
#include "NaviMesh.h"

#include "Export_Function.h"
#include "MFCToolView.h"

CNaviMesh::CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev)
	:Engine::CGameObject(pGraphicDev)
{
}

CNaviMesh::~CNaviMesh()
{
}

HRESULT CNaviMesh::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	//pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);
	
	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CCubeTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_CubeTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_LOGO, L"Texture_Player"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Calculator
	pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	return S_OK;
}

HRESULT CNaviMesh::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//m_pTransformCom->m_vScale = _vec3(4.f, 2.f, 1.f);

	return S_OK;
}

_int CNaviMesh::Update_Object(const _float & fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

//	_vec3	vPickPos = PickUp_OnTerrain();
//	m_pTransformCom->Pick_Pos(&vPickPos, 5.f, fTimeDelta);

	return 0;
}

void CNaviMesh::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);

	m_pTextureCom->Render_Texture(0);

	FAILED_CHECK_RETURN(SetUp_Material(), );

	m_pBufferCom->Render_Buffer();

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
}

_vec3 CNaviMesh::PickUp_OnTerrain(void)
{
	
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(CMFCToolView::GetInstance()->Get_Component(L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	//return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
	return _vec3{ 0.f,0.f,0.f };
}

HRESULT CNaviMesh::SetUp_Material(void)
{
	D3DMATERIAL9			tMtrlInfo;
	ZeroMemory(&tMtrlInfo, sizeof(D3DMATERIAL9));


	tMtrlInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tMtrlInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tMtrlInfo.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.f);
	tMtrlInfo.Emissive = D3DXCOLOR(0.f, 0.f, 0.f, 1.f);
	tMtrlInfo.Power = 0.f;

	m_pGraphicDev->SetMaterial(&tMtrlInfo);

	return S_OK;
}

CNaviMesh * CNaviMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CNaviMesh*	pInstance = new CNaviMesh(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}
