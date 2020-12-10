#include "stdafx.h"
#include "MFCDynamicMesh.h"
#include "Export_Function.h"

CMFCDynamicMesh::CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{

}

CMFCDynamicMesh::CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev, CString _mesh)
	: Engine::CGameObject(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{
}

CMFCDynamicMesh::~CMFCDynamicMesh(void)
{

}

_vec3 CMFCDynamicMesh::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
}

HRESULT CMFCDynamicMesh::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_MFCDynamicMesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	//pComponent = m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Navi"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

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
	//pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}

HRESULT CMFCDynamicMesh::Add_Component(CString _mesh)
{
	Engine::CComponent*		pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, _mesh));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	pComponent = m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

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
	//pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}

void CMFCDynamicMesh::Key_Input(const _float& fTimeDelta)
{
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &m_vDir);

	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//{
	//	_vec3	vPos, vDir;
	//	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	//	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
	//	D3DXVec3Normalize(&vDir, &vDir);

	//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_fSpeed)));
	//	
	//	m_pMeshCom->Set_AnimationSet(0);

	//}

	//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//{
	//	D3DXVec3Normalize(&m_vDir, &m_vDir);
	//	m_pTransformCom->Move_Pos(&(m_vDir * -m_fSpeed * fTimeDelta));
	//}

	//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(90.f * fTimeDelta));

	//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-90.f * fTimeDelta));

	//if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	//{
	//	_vec3	vPickPos = PickUp_OnTerrain();
	//	m_pTransformCom->Pick_Pos(&vPickPos, m_fSpeed, fTimeDelta);
	//}

	//if (Engine::Get_DIMouseState(Engine::DIM_RB) & 0x80)
	//{
	//	m_pMeshCom->Set_AnimationSet(0);
	//}

	//if(true == m_pMeshCom->Is_AnimationSetEnd())
	//	m_pMeshCom->Set_AnimationSet(0);


}

CMFCDynamicMesh* CMFCDynamicMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CMFCDynamicMesh*	pInstance = new CMFCDynamicMesh(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

CMFCDynamicMesh * CMFCDynamicMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev, CString _mesh)
{
	CMFCDynamicMesh*	pInstance = new CMFCDynamicMesh(pGraphicDev,_mesh);

	if (FAILED(pInstance->Ready_Object(_mesh)))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CMFCDynamicMesh::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT CMFCDynamicMesh::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	
	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);
	m_pMeshCom->Set_AnimationSet(0);

	m_pNaviMeshCom->Set_NaviIndex(0);

	return S_OK;
}
HRESULT CMFCDynamicMesh::Ready_Object(CString _mesh)
{
	FAILED_CHECK_RETURN(Add_Component(_mesh), E_FAIL);


	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);
	m_pMeshCom->Set_AnimationSet(0);

	m_pNaviMeshCom->Set_NaviIndex(0);

	return S_OK;
}
_int CMFCDynamicMesh::Update_Object(const _float& fTimeDelta)
{

	SetUp_OnTerrain();
	Key_Input(fTimeDelta);

	Engine::CGameObject::Update_Object(fTimeDelta);

	m_pMeshCom->Play_Animation(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void CMFCDynamicMesh::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);
	
	m_pNaviMeshCom->Render_NaviMeshes();

	m_pMeshCom->Render_Meshes();
	/*_matrix matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderCom->Render_Collider(Engine::COL_TRUE, &matWorld);*/
}
void CMFCDynamicMesh::SetUp_OnTerrain(void)
{
	//_vec3	vPosition;
	//m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	//Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	//NULL_CHECK(pTerrainBufferCom);

	//_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	//m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}