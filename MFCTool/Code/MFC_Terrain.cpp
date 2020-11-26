#include "stdafx.h"
#include "MFC_Terrain.h"
#include "Export_Function.h"

CMFC_Terrain::CMFC_Terrain(LPDIRECT3DDEVICE9 pGraphicDev)
	:Engine::CGameObject(pGraphicDev)
{
}

CMFC_Terrain::~CMFC_Terrain()
{
}

HRESULT CMFC_Terrain::Ready_Object(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_TerrainTex"));
	NULL_CHECK_RETURN(m_pBufferCom, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_Terrain"));
	NULL_CHECK_RETURN(m_pTextureCom, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(m_pRendererCom, E_FAIL);
	Engine::Safe_AddRef(m_pRendererCom);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", m_pRendererCom);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(m_pTransformCom, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	return S_OK;
}

_int CMFC_Terrain::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}

void CMFC_Terrain::Render_Object()
{

	m_pTransformCom->Set_Transform(m_pGraphicDev);

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);

	m_pTextureCom->Render_Texture(0);

	FAILED_CHECK_RETURN(SetUpMaterial(), );

	m_pBufferCom->Render_Buffer();

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
}

HRESULT CMFC_Terrain::SetUpMaterial()
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

CMFC_Terrain* CMFC_Terrain::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CMFC_Terrain* pInstance = new CMFC_Terrain(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CMFC_Terrain::Free(void)
{
	Engine::CGameObject::Free();
}