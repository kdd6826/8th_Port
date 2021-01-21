#include "stdafx.h"
#include "Monster.h"
#include "Export_Function.h"
#include "ColliderMgr.h"
#include "Player.h"
CMonster::CMonster(LPDIRECT3DDEVICE9 pGraphicDev)
	: CUnit(pGraphicDev)
{

}

CMonster::~CMonster(void)
{
}

_int CMonster::Update_Object(const _float& fTimeDelta)
{
	CUnit::Update_Object(fTimeDelta);
	return S_OK;
}

void CMonster::OnCollision(Engine::CGameObject* target)
{
	_vec3 hitDir = dynamic_cast<CUnit*>(target)->m_pTransformCom->m_vInfo[Engine::INFO_LOOK];
	dynamic_cast<CPlayer*>(target)->m_pStateCom->stat.damage;
	//¹«ÀûÀÌ¾Æ´Ò¶§
	if (!isInvincible)
	{
		m_pTransformCom->m_vInfo[Engine::INFO_POS] += hitDir * 0.1;
		m_pStateCom->stat.hp -= dynamic_cast<CPlayer*>(target)->m_pStateCom->stat.damage;
		Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
		
		pPlayerStateCom->stat.sp += 20.f;
		if (pPlayerStateCom->stat.sp > pPlayerStateCom->stat.maxSp)
			pPlayerStateCom->stat.sp = pPlayerStateCom->stat.maxSp;
	}
	//»ç¸Á
	if (m_pStateCom->stat.hp <= 0 && isDie == false)
	{
		
		isDie = true;
		
	}

}

HRESULT CMonster::Add_Component(void)
{
	CUnit::Add_Component();
	Engine::CComponent* pComponent = nullptr;


	// state
	pComponent = m_pStateCom = dynamic_cast<Engine::CMonsterState*>(Engine::Clone(L"Proto_MonsterState"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_MonsterState", pComponent);
	return S_OK;
}

bool CMonster::PlayerSearch(_vec3 _MonsterPos)
{
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];
	if (pPlayerTransCom == nullptr)
		return false;
	_float distX = playerPos.x - _MonsterPos.x;
	_float distZ = playerPos.z - _MonsterPos.z;

	disPlayer = sqrt(distX * distX + distZ * distZ);

	if (isSearch == true)
		return true;
	if (disPlayer < 2.f)
		return true;
	



	return false;
}




void CMonster::Free(void)
{
	CUnit::Free();
}

