#include "stdafx.h"
#include "Monster.h"
#include "Export_Function.h"
#include "ColliderMgr.h"
#include "Player.h"
#include "DynamicCamera.h"
CMonster::CMonster(LPDIRECT3DDEVICE9 pGraphicDev)
	: CUnit(pGraphicDev)
{

}

CMonster::~CMonster(void)
{
	for (auto& iterator = m_vecSlashPoint.begin(); iterator != m_vecSlashPoint.end(); ++iterator)
	{
		//Engine::Safe_Delete_Array(*iterator);
		Engine::Safe_Release(*iterator);
	}
	for (auto& iterator = m_vecDamageFont.begin(); iterator != m_vecDamageFont.end(); ++iterator)
	{
		//Engine::Safe_Delete_Array(*iterator);
		Engine::Safe_Release(*iterator);
	}
	for (auto& iterator = m_vecFontParent.begin(); iterator != m_vecFontParent.end(); ++iterator)
	{
		//Engine::Safe_Delete_Array(*iterator);
		Engine::Safe_Release(*iterator);
	}
}

_int CMonster::Update_Object(const _float& fTimeDelta)
{
	CUnit::Update_Object(fTimeDelta);
	for (auto& slash : m_vecSlashPoint)
	{
		slash->Update_Object(fTimeDelta);
	}
	for (auto& font : m_vecDamageFont)
	{
		font->Update_Object(fTimeDelta);
	}
	for (auto& font : m_vecFontParent)
	{
		font->Update_Object(fTimeDelta);
	}
	return S_OK;
}

void CMonster::OnCollision(Engine::CGameObject* target)
{
	_vec3 hitDir = dynamic_cast<CUnit*>(target)->m_pTransformCom->m_vInfo[Engine::INFO_LOOK];
	dynamic_cast<CPlayer*>(target)->m_pStateCom->stat.damage;
	//무적이아닐때
	if (!isInvincible)
	{
		m_pTransformCom->m_vInfo[Engine::INFO_POS] += hitDir * 0.1;
		m_pStateCom->stat.hp -= dynamic_cast<CPlayer*>(target)->m_pStateCom->stat.damage;
		Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
		
		pPlayerStateCom->stat.sp += 20.f;
		if (pPlayerStateCom->stat.sp > pPlayerStateCom->stat.maxSp)
			pPlayerStateCom->stat.sp = pPlayerStateCom->stat.maxSp;

		// 피격효과
		CSlashPoint* slashPoint = CSlashPoint::Create(m_pGraphicDev);
		_vec3 vMonsterPos;
		int i = rand() % 10;
		m_pTransformCom->Get_Info(Engine::INFO_POS, &vMonsterPos);
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS] = vMonsterPos;
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 0.5f;
		//rand
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].x += -0.3f+i*0.06;
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].y += -0.3f + i*0.06;
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].z += -0.3f + i*0.06;
		m_vecSlashPoint.emplace_back(slashPoint);
		//

		// Damagefont
		CFontParent* fontParent = CFontParent::Create(m_pGraphicDev);

		fontParent->GetTransform()->m_vInfo[Engine::INFO_POS] = vMonsterPos;
		
		m_vecFontParent.emplace_back(fontParent);

		CDamageFont* damageFont = CDamageFont::Create(m_pGraphicDev);
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].x += 0.5f;
		damageFont->m_pFontParent = fontParent;
		damageFont->offsetX = 0.1f;
		damageFont->count = 1;
		/*m_vecDamageFont.emplace_back(damageFont);*/
		fontParent->m_vecDamageFont.emplace_back(damageFont);

		damageFont = CDamageFont::Create(m_pGraphicDev);
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].x += 0.5f;

		damageFont->m_pFontParent = fontParent;
		damageFont->offsetX = -0.1f;
		damageFont->count = 0;
		/*m_vecDamageFont.emplace_back(damageFont);*/
		fontParent->m_vecDamageFont.emplace_back(damageFont);
		//CDynamicCamera* pCamera = dynamic_cast<CDynamicCamera*>(Engine::Get_GameObject(L"UI", L"DynamicCamera"));
		//_vec3 pCamAt = pCamera->Get_At();
		//_vec3 pCamEye = pCamera->Get_Eye();
		//_vec3 pCamLook = pCamAt - pCamEye;
		//_vec3 worldUp = { 0.f,1.f,0.f };
		//_vec3 vCamRight;
		//D3DXVec3Normalize(&pCamLook, &pCamLook);
		//D3DXVec3Cross(&vCamRight, &pCamLook, &worldUp);
		//
		//damageFont = CDamageFont::Create(m_pGraphicDev);
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS] = vMonsterPos+vCamRight*0.2f;
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].y += 0.5f;
		///*damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].x -= 0.2f;*/
		//m_vecDamageFont.emplace_back(damageFont);

		//damageFont = CDamageFont::Create(m_pGraphicDev);
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS] = vMonsterPos - vCamRight*0.2f;
		//damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].y += 0.5f;
		///*damageFont->GetTransform()->m_vInfo[Engine::INFO_POS].x += 0.2f;*/
		//m_vecDamageFont.emplace_back(damageFont);
		//
	}
	//사망
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

