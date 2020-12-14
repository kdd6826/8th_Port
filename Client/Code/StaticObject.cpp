#include "stdafx.h"
#include "StaticObject.h"
#include "Export_Function.h"

CStaticObject::CStaticObject(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CStaticObject::~CStaticObject(void)
{

}

HRESULT Client::CStaticObject::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;
	
	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_StaticObject"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

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

	// Collider 
	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	// Optimization
	pComponent = m_pOptimizationCom = dynamic_cast<Engine::COptimization*>(Engine::Clone(L"Proto_Optimization"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Optimization", pComponent);

	return S_OK;
}

HRESULT CStaticObject::Add_Component(wstring _wstring)
{
	Engine::CComponent* pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, _wstring.c_str()));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

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

	// Collider 
	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	// Optimization
	pComponent = m_pOptimizationCom = dynamic_cast<Engine::COptimization*>(Engine::Clone(L"Proto_Optimization"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Optimization", pComponent);

	return S_OK;
}


CStaticObject* CStaticObject::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStaticObject*	pInstance = new CStaticObject(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

CStaticObject* CStaticObject::Create(LPDIRECT3DDEVICE9 pGraphicDev, wstring _wstring)
{
	CStaticObject* pInstance = new CStaticObject(pGraphicDev);

	if (FAILED(pInstance->Ready_Object(_wstring)))
		Client::Safe_Release(pInstance);

	return pInstance;
}


void CStaticObject::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CStaticObject::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Pos(&_vec3(5.f, 0.f, 5.f));
	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(45.f));

	return S_OK;
}
HRESULT CStaticObject::Ready_Object(wstring _wstring)
{
	FAILED_CHECK_RETURN(Add_Component(_wstring), E_FAIL);

	m_pTransformCom->Set_Pos(&_vec3(5.f, 0.f, 5.f));
	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(45.f));

	return S_OK;
}
Client::_int Client::CStaticObject::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);

	SetUp_OnTerrain();

	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	_vec3	vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);

	m_bDraw = m_pOptimizationCom->Is_InFrustumForObject(&vPos, 0.f);


	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CStaticObject::Render_Object(void)
{
	if (false == m_bDraw)
		return;


	m_pTransformCom->Set_Transform(m_pGraphicDev);

	m_pMeshCom->Render_Meshes();

	//_matrix matWorld;
		// m_pTransformCom->Get_WorldMatrix(&matWorld);
	//	m_pTransformCom->Get_NRotWorldMatrix(&matWorld);

	//m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);


}
void Client::CStaticObject::SetUp_OnTerrain(void)
{
	_vec3	vPosition;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}

_bool CStaticObject::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CCollider*	pPlayerColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	
	/*return m_pCalculatorCom->Collision_AABB(pPlayerColliderCom->Get_Min(),
											pPlayerColliderCom->Get_Max(),
											pPlayerColliderCom->Get_CollMatrix(),
											m_pColliderCom->Get_Min(), 
											m_pColliderCom->Get_Max(),
											m_pColliderCom->Get_CollMatrix());*/

	return m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
		pPlayerColliderCom->Get_Max(),
		pPlayerColliderCom->Get_CollMatrix(),
		m_pColliderCom->Get_Min(),
		m_pColliderCom->Get_Max(),
		m_pColliderCom->Get_CollMatrix());
}
