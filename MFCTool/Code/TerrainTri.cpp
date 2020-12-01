#include "stdafx.h"
#include "TerrainTri.h"
#include "Export_Function.h"
#include "Cell.h"
#include "SphereMesh.h"
#include "MFCToolView.h"

CTerrainTri::CTerrainTri(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CTerrainTri::~CTerrainTri(void)
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

HRESULT CTerrainTri::Add_Component(_vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3)
{
	Engine::CComponent* pComponent = nullptr;


	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CTerrainTriCol*>(Engine::Create_TerrainCol(m_pGraphicDev, vtxPos1, vtxPos2, vtxPos3));
	//pComponent = m_pBufferCom = dynamic_cast<Engine::CTerrainTriCol*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_TriCol"));
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

	//m_pTransformCom->m_vInfo[Engine::INFO_POS].x += 0.01f;
	m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 0.01f;
	//m_pTransformCom->m_vInfo[Engine::INFO_POS].z += 0.01f;
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

CTerrainTri* CTerrainTri::Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3)
{
	CTerrainTri* pInstance = new CTerrainTri(pGraphicDev);

	if (FAILED(pInstance->Ready_Object(vtxPos1, vtxPos2, vtxPos3)))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CTerrainTri::Free(void)
{
	Engine::CGameObject::Free();
	Engine::Safe_Release(m_Cell);
	//for (auto& vtx : list_pVtx) {
	//	delete vtx;
	//	vtx = nullptr;
	//}
}

HRESULT CTerrainTri::Ready_Object(_vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3)
{
	FAILED_CHECK_RETURN(Add_Component(vtxPos1, vtxPos2, vtxPos3), E_FAIL);

	m_Cell = Engine::CCell::Create(m_pGraphicDev, &vtxPos1, &vtxPos2, &vtxPos3);

	return S_OK;
}

HRESULT CTerrainTri::Ready_Object(void)
{
	//FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//Engine::VTXCOL* vtx = new Engine::VTXCOL;
	//vtx->vPos = m_pTransformCom->m_vInfo[Engine::INFO_POS];
	//vtx->dwColor = D3DXCOLOR{ 255.f, 0.f, 0.f, 255.f };
	//list_pVtx.emplace_back(vtx);

	return S_OK;
}
_int CTerrainTri::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);

	if (!CMFCToolView::GetInstance()->wireFrame) {
		m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);
	}

	return 0;
}
void CTerrainTri::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);
	m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	m_pBufferCom->Render_Buffer();
	//m_pTextureCom->Render_Texture(0);
	m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

}
void CTerrainTri::Set_InitBuffer()
{
	int sphereCount = 0;
	Engine::VTXCOL* pVertex = NULL;
	m_pBufferCom->m_pVB->Lock(0, 0, (void**)&pVertex, NULL);

	for (auto& sphere : list_SphereMesh)
	{
		pVertex[sphereCount].vPos = sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS];
		sphereCount++;
	}


	m_pBufferCom->m_pVB->Unlock();
}
//void CTerrainTri::Set_VtxPos()
//{
//	for (auto& vtx : list_pVtx)
//	{
//		vtx->vPos = m_pTransformCom->m_vInfo[Engine::INFO_POS];
//	}
//}