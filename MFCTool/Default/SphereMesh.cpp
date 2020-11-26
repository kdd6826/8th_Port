#include "stdafx.h"
#include "SphereMesh.h"
#include "Export_Function.h"

CSphereMesh::CSphereMesh(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CSphereMesh::~CSphereMesh(void)
{

}

//Engine::_vec3 CSphereMesh::PickUp_OnTerrain(void)
//{
//	Engine::CTerrainTex* pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
//	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));
//
//	Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
//	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));
//
//	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
//}

HRESULT CSphereMesh::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;


	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CSphere*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_Sphere"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	//// texture
	//pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_Monster"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

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

CSphereMesh* CSphereMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSphereMesh* pInstance = new CSphereMesh(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CSphereMesh::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT CSphereMesh::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	m_pTransformCom->Set_Pos(_vec3(rand() % 100 + 1.f, 0.f, rand() % 100 + 1.f));

	return S_OK;
}
_int CSphereMesh::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);


	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void CSphereMesh::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);
	m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	m_pBufferCom->Render_Buffer();
	//m_pTextureCom->Render_Texture(0);
	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

}
//void CSphereMesh::SetUp_OnTerrain(void)
//{
//	_vec3	vPosition;
//	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);
//
//	Engine::CTerrainTex* pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
//	NULL_CHECK(pTerrainBufferCom);
//
//	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);
//
//	m_pTransformCom->Move_Pos(vPosition.x, fHeight + 1.f, vPosition.z);
//}
