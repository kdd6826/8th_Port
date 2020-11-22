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

HRESULT CMFC_Terrain::Ready()
{
	m_pBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_TerrainTex"));
	NULL_CHECK_RETURN(m_pBufferCom, E_FAIL);

	// texture
	m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_Terrain"));
	NULL_CHECK_RETURN(m_pTextureCom, E_FAIL);

	// Transform
	m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(m_pTransformCom, E_FAIL);

	return S_OK;
}

void CMFC_Terrain::Render()
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
