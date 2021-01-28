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

HRESULT CMonster::Ready_Object(void)
{
	

	
	return S_OK;
}

_int CMonster::Update_Object(const _float& fTimeDelta)
{
	CUnit::Update_Object(fTimeDelta);

	_vec3	vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	if(m_pOptimizationCom!=nullptr)
	m_bDraw = m_pOptimizationCom->Is_InFrustumForObject(&vPos, 0.f);
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

void CMonster::Render_Object(void)
{
	if (false == m_bDraw)
		return;
}

void CMonster::OnCollision(Engine::CGameObject* target)
{
	_vec3 hitDir = dynamic_cast<CUnit*>(target)->m_pTransformCom->m_vInfo[Engine::INFO_LOOK];
	/*float damage;*/
	//if (dynamic_cast<CPlayer*>(target)->m_pStateCom != nullptr)
	//{
	//	damage = dynamic_cast<CPlayer*>(target)->m_pStateCom->stat.damage;
	//}
	//else
	//{
		Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
		NULL_CHECK_RETURN(pPlayerStateCom, );
		
		float damage = pPlayerStateCom->stat.damage;
	/*}*/

	float damageRange = damage*0.1f;
	int random = rand() % int(damageRange);
	damage = damage - damageRange*0.5f + random;
	int fontCount = 0;
	//무적이아닐때
	if (!isInvincible)
	{
		m_pTransformCom->m_vInfo[Engine::INFO_POS] += hitDir * 0.1;
		m_pStateCom->stat.hp -= pPlayerStateCom->stat.damage;
		//Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));

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
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].x += -0.3f + i*0.06;
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].y += -0.3f + i*0.06;
		slashPoint->m_pTransformCom->m_vInfo[Engine::INFO_POS].z += -0.3f + i*0.06;
		m_vecSlashPoint.emplace_back(slashPoint);
		//

		if (damage < 10.f)
		{
			fontCount = 1;
		}
		else if (damage < 100.f)
		{
			fontCount = 2;
		}
		else if (damage < 1000.f)
		{
			fontCount = 3;
		}
		else if (damage < 10000.f)
		{
			fontCount = 4;
		}
		else if (damage < 100000.f)
		{
			fontCount = 5;
		}

		// Damagefont
		CFontParent* fontParent = CFontParent::Create(m_pGraphicDev);
		fontParent->GetTransform()->m_vInfo[Engine::INFO_POS] = vMonsterPos;
		m_vecFontParent.emplace_back(fontParent);
		if (fontCount >= 5)
		{
			CDamageFont* damageFont = CDamageFont::Create(m_pGraphicDev);
			int oi = rand() % 10;
			damageFont->m_pFontParent = fontParent;
			damageFont->offsetX += (fontCount - 4 - (int)(fontCount*0.5f))*0.12f;
			damageFont->count = (int(damage) % 100000) / 10000;
			fontParent->m_vecDamageFont.emplace_back(damageFont);
		}
		if (fontCount >= 4)
		{
			CDamageFont*damageFont = CDamageFont::Create(m_pGraphicDev);
			damageFont->m_pFontParent = fontParent;
			damageFont->offsetX += (fontCount - 3 - (int)(fontCount*0.5f))*0.12f;

			damageFont->count = (int(damage) % 10000) / 1000;
			fontParent->m_vecDamageFont.emplace_back(damageFont);
		}
		if (fontCount >= 3)
		{
			CDamageFont*damageFont = CDamageFont::Create(m_pGraphicDev);
			damageFont->m_pFontParent = fontParent;
			damageFont->offsetX += (fontCount - 2 - (int)(fontCount*0.5f))*0.12f;

			damageFont->count = (int(damage) % 1000) / 100;
			fontParent->m_vecDamageFont.emplace_back(damageFont);
		}

		if (fontCount >= 2)
		{
			CDamageFont*damageFont = CDamageFont::Create(m_pGraphicDev);

			damageFont->m_pFontParent = fontParent;
			damageFont->offsetX += (fontCount - 1 - (int)(fontCount*0.5f))*0.12f;

			damageFont->count = (int(damage) % 100) / 10;
			fontParent->m_vecDamageFont.emplace_back(damageFont);
		}

		if (fontCount >= 1)
		{
			CDamageFont*damageFont = CDamageFont::Create(m_pGraphicDev);
			damageFont->m_pFontParent = fontParent;
			damageFont->offsetX += (fontCount - (int)(fontCount*0.5f))*0.12f;
			damageFont->count = int(damage) % 10;
			fontParent->m_vecDamageFont.emplace_back(damageFont);
		}
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

	// Optimization
	pComponent = m_pOptimizationCom = dynamic_cast<Engine::COptimization*>(Engine::Clone(L"Proto_Optimization"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Optimization", pComponent);

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

