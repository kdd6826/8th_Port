#include "PlayerState.h"

USING(Engine)

Engine::CPlayerState::CPlayerState(void)
{
}

Engine::CPlayerState::CPlayerState(const CPlayerState& rhs)
{
}

Engine::CPlayerState::~CPlayerState(void)
{

}

HRESULT CPlayerState::Ready_PlayerState(void)
{
	return S_OK;
}

_int CPlayerState::Update_Component(const _float & fTimeDelta)
{
	
	return _int();
}

Engine::CComponent* Engine::CPlayerState::Clone(void)
{
	return new CPlayerState(*this);
}

void Engine::CPlayerState::Free(void)
{

}

Engine::CPlayerState* Engine::CPlayerState::Create(void)
{
	CPlayerState*	pInstance = new CPlayerState;

	if (FAILED(pInstance->Ready_PlayerState()))
		Safe_Release(pInstance);

	return pInstance;
}
