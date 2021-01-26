#include "stdafx.h"
#include "BossHpBarRed.h"
#include "Export_Function.h"

CBossHpBarRed::CBossHpBarRed(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CBossHpBarRed::~CBossHpBarRed(void)
{

}


HRESULT Client::CBossHpBarRed::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_BossHpBarRed"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	return S_OK;
}

CBossHpBarRed* CBossHpBarRed::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CBossHpBarRed*	pInstance = new CBossHpBarRed(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CBossHpBarRed::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CBossHpBarRed::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_fSizeX = 800.f;
	m_fSizeY = 64.f;
	m_fX = 550.f;
	m_fY = 120.f;
	return S_OK;
}
Client::_int Client::CBossHpBarRed::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);
		
	Engine::CMonsterState* pTitanStateCom = dynamic_cast<Engine::CMonsterState*>(Engine::Get_Component(L"GameLogic", L"Titan", L"Com_MonsterState", Engine::ID_DYNAMIC));
	Engine::CMonsterState* pIngkellsStateCom = dynamic_cast<Engine::CMonsterState*>(Engine::Get_Component(L"GameLogic", L"Ingkells", L"Com_MonsterState", Engine::ID_DYNAMIC));
	if (pTitanStateCom == nullptr && pTitanStateCom == nullptr)
		return 0;

	if (pTitanStateCom !=nullptr&&pTitanStateCom->stat.hp <= pTitanStateCom->stat.maxHp * 0.31)
	{
		m_fX = 160 + 390 * ((pTitanStateCom->stat.hp) / (pTitanStateCom->stat.maxHp - pTitanStateCom->stat.maxHp * 0.7));
		m_fSizeX = 800 * (pTitanStateCom->stat.hp) / (pTitanStateCom->stat.maxHp - pTitanStateCom->stat.maxHp * 0.7);
		if (m_fSizeX < 0)
			m_fSizeX = 0;
	}
	else 	if (pIngkellsStateCom != nullptr && pIngkellsStateCom->stat.hp <= pIngkellsStateCom->stat.maxHp * 0.31)
	{
		m_fX = 160 + 390 * ((pIngkellsStateCom->stat.hp) / (pIngkellsStateCom->stat.maxHp - pIngkellsStateCom->stat.maxHp * 0.7));
		m_fSizeX = 800 * (pIngkellsStateCom->stat.hp) / (pIngkellsStateCom->stat.maxHp - pIngkellsStateCom->stat.maxHp * 0.7);
		if (m_fSizeX < 0)
			m_fSizeX = 0;
	}

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	D3DXMatrixOrthoLH(&m_matProj, WINCX, WINCY, 0.f, 1.f);

	return 0;
}
void Client::CBossHpBarRed::Render_Object(void)
{
	_matrix		matWorld, matView, matOriginView, matOriginProj;

	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matOriginView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matOriginProj);

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matView);

	matWorld._11 = m_fSizeX;
	matWorld._22 = m_fSizeY;
	matWorld._33 = 1.f;
	matWorld._41 = m_fX - WINCX * 0.5f;
	matWorld._42 = -m_fY + WINCY * 0.5f;

	m_pGraphicDev->SetTransform(D3DTS_WORLD, &matWorld);
	m_pGraphicDev->SetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &m_matProj);

	m_pTextureCom->Render_Texture();
	m_pBufferCom->Render_Buffer();

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &matOriginView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &matOriginProj);
}
