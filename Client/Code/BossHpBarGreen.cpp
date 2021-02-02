#include "stdafx.h"
#include "BossHpBarGreen.h"
#include "Export_Function.h"

CBossHpBarGreen::CBossHpBarGreen(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CBossHpBarGreen::~CBossHpBarGreen(void)
{

}


HRESULT Client::CBossHpBarGreen::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_BossHpBarGreen"));
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

CBossHpBarGreen* CBossHpBarGreen::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CBossHpBarGreen*	pInstance = new CBossHpBarGreen(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CBossHpBarGreen::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CBossHpBarGreen::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	m_fSizeX = 1100.f;
	m_fSizeY = 128.f;
	m_fX = 1050;
	m_fY = 120.f;

	return S_OK;
}
Client::_int Client::CBossHpBarGreen::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);

	Engine::CMonsterState* pTitanStateCom = dynamic_cast<Engine::CMonsterState*>(Engine::Get_Component(L"GameLogic", L"Titan", L"Com_MonsterState", Engine::ID_DYNAMIC));
	Engine::CMonsterState* pIngkellsStateCom = dynamic_cast<Engine::CMonsterState*>(Engine::Get_Component(L"GameLogic", L"Ingkells", L"Com_MonsterState", Engine::ID_DYNAMIC));
	if (pIngkellsStateCom == nullptr && pTitanStateCom == nullptr)
		return 0;
	/*if (pMonsterStateCom->stat.hp >= pMonsterStateCom->stat.maxHp * 0.6)
	{*/
	if (pTitanStateCom != nullptr)
	{
		/*m_fX = 160 + 390 * ((pTitanStateCom->stat.hp - pTitanStateCom->stat.maxHp * 0.6) / (pTitanStateCom->stat.maxHp - pTitanStateCom->stat.maxHp * 0.6));*/
		m_fX = 500 + 550 * ((pTitanStateCom->stat.hp - pTitanStateCom->stat.maxHp * 0.6) / (pTitanStateCom->stat.maxHp - pTitanStateCom->stat.maxHp * 0.6)); 
		m_fSizeX = 1100 * (pTitanStateCom->stat.hp - pTitanStateCom->stat.maxHp * 0.6) / (pTitanStateCom->stat.maxHp - pTitanStateCom->stat.maxHp * 0.6);
		if (m_fSizeX < 0)
			m_fSizeX = 0;
	}
	else if (pIngkellsStateCom != nullptr)
	{
		//m_fX = 160 + 390 * ((pIngkellsStateCom->stat.hp - pIngkellsStateCom->stat.maxHp * 0.6) / (pIngkellsStateCom->stat.maxHp - pIngkellsStateCom->stat.maxHp * 0.6));
		m_fX = 500 + 550 * ((pIngkellsStateCom->stat.hp - pIngkellsStateCom->stat.maxHp * 0.6) / (pIngkellsStateCom->stat.maxHp - pIngkellsStateCom->stat.maxHp * 0.6));
		m_fSizeX = 1100 * (pIngkellsStateCom->stat.hp - pIngkellsStateCom->stat.maxHp * 0.6) / (pIngkellsStateCom->stat.maxHp - pIngkellsStateCom->stat.maxHp * 0.6);
		if (m_fSizeX < 0)
			m_fSizeX = 0;
	}
	/*}*/
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	D3DXMatrixOrthoLH(&m_matProj, WINCX, WINCY, 0.f, 1.f);

	return 0;
}
void Client::CBossHpBarGreen::Render_Object(void)
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
