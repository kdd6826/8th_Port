#include "stdafx.h"
#include "Monster.h"
#include "Export_Function.h"
#include "ColliderMgr.h"
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
	//¹«ÀûÀÌ¾Æ´Ò¶§
	if (!isInvincible)
	{
		m_pTransformCom->m_vInfo[Engine::INFO_POS] += hitDir * 0.1;
		m_pTransformCom->stat.hp -= 1.f;
	}
	//»ç¸Á
	if (m_pTransformCom->stat.hp <= 0 && isDie == false)
	{
		
		isDie = true;
		
	}

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

