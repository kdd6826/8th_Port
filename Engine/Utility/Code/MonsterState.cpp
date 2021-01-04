#include "MonsterState.h"

USING(Engine)

Engine::CMonsterState::CMonsterState(void)
{
}

Engine::CMonsterState::CMonsterState(const CMonsterState& rhs)
{
}

Engine::CMonsterState::~CMonsterState(void)
{

}

HRESULT CMonsterState::Ready_MonsterState(void)
{
	return S_OK;
}

_int CMonsterState::Update_Component(const _float & fTimeDelta)
{
	
	return _int();
}

Engine::CComponent* Engine::CMonsterState::Clone(void)
{
	return new CMonsterState(*this);
}

void Engine::CMonsterState::Free(void)
{

}

Engine::CMonsterState* Engine::CMonsterState::Create(void)
{
	CMonsterState*	pInstance = new CMonsterState;

	if (FAILED(pInstance->Ready_MonsterState()))
		Safe_Release(pInstance);

	return pInstance;
}
