#include "stdafx.h"
#include "Ingkells.h"
#include "ColliderMgr.h"
#include "Export_Function.h"


CIngkells::CIngkells(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{

}

CIngkells::~CIngkells(void)
{
	int i = 0;
}

Client::_vec3 Client::CIngkells::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex* pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
}

HRESULT Client::CIngkells::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Ingkells"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);
	m_pMeshCom->m_fRot = -90.f;
	
	CMonster::Add_Component();

	float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	
	Engine::CGameObject::Update_Object(timeDelta);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	Load_ColliderFile(L"../Bin/saveInkellsSave.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	Load_ColliderFile(L"../Bin/saveInkellsWeapon.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	Load_ColliderFile(L"../Bin/saveInkellsWeapon1.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	Load_ColliderFile(L"../Bin/saveInkellsWeapon2.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	Load_ColliderFile(L"../Bin/saveInkellsWeapon3.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	Load_ColliderFile(L"../Bin/saveInkellsWeapon4.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);



	return S_OK;
}

HRESULT CIngkells::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;
}


void CIngkells::Move(const _float& fTimeDelta)
{

	_vec3	vPos, vDir, vRight;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

	//플레이어를 향한 위치벡터
	_vec3 toPlayerDir = playerPos - vPos;

	//기존 몬스터의 룩벡터
	D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
	D3DXVec3Normalize(&vDir, &vDir);

	//내적을 통한 각도
	float frontRadian = D3DXVec3Dot(&toPlayerDir, &vDir);
	float rightRadian = D3DXVec3Dot(&toPlayerDir, &vRight);
	//플레이어가 내 앞? 내 뒤?
	float angle = D3DXToDegree(frontRadian);
	//플레이어가 내 왼쪽? 오른쪽?
	float angle2 = D3DXToDegree(rightRadian);
	//		45	56	60	52 45 	22.5
	//		0.78 0.98	0.7
	//			    ↑
	//      0        ㅇ		-0
	//		     (몬스터)
	//
	//			-40 -60  -55
	//			-0.7 -0.9 -1
	// -10
	//플레이어가 정면에있다
	//몬스터의 시야각
	float spinSpeed = 5.f;
	if (disPlayer < 1.f)
	{
		int i = rand() % 2;
		switch (i)
		{
		case 0:
			m_state = IngkellsState::STATE_TURNRIGHT_ATK;
			//delay = 2.9f; //2.82
			m_fAniSpeed = 2.f;
			break;
		case 1:
			m_state = IngkellsState::STATE_TURNLEFT_ATK;
			m_fAniSpeed = 2.f;
			break;

		default:
			break;
		}
		_double temp = m_pMeshCom->Get_AnimationPeriod(m_state);
		temp = (temp / (m_fAniSpeed)) - 0.1f;
		delay = temp;
		isAnimating = true;
		reverseDelay = 0.f;
		return;
	}
	else if (55.f <= angle && angle < 60.f)
	{
		m_state = IngkellsState::STATE_RUN;
		if (disPlayer < 5.f)
		{
			if (disPlayer < 2.5f)
			{
				//int i = rand() % 2;
				int i = 1;
				switch (i)
				{


				case 0:
					m_state = IngkellsState::STATE_SWING_TRIPLE;
					m_fAniSpeed = 2.f;
					break;

				case 1:
					m_state = IngkellsState::STATE_DOUBLESMASH;
					m_fAniSpeed = 2.f;
					break;

				default:
					break;
				}
			}

			else if (disPlayer < 3.5f)
			{
				int i = rand() % 1;
				switch (i)
				{
				case 0:
					m_state = IngkellsState::STATE_SWORDWAVE;
					m_fAniSpeed = 2.5f;
					break;

				default:
					break;
				}
			}
			else if (disPlayer < 5.f)
			{
				int i = rand() % 2;
				switch (i)
				{
				case 0:
					m_state = IngkellsState::STATE_THRUST_TO_WHIRLWIND;
					m_fAniSpeed = 2.f;
					break;
				case 1:
					m_state = IngkellsState::STATE_TAUNT;
					m_fAniSpeed = 1.5f;
					//delay = 4.2f;
					break;
				default:
					break;
				}
			}
			_double temp = m_pMeshCom->Get_AnimationPeriod(m_state);
			temp = (temp / (m_fAniSpeed)) - 0.1f;
			delay = temp;
			isAnimating = true;
			reverseDelay = 0.f;
			return;
		}
	}
	else if (disPlayer < 1.5f)
	{
		int i = rand() % 2;
		switch (i)
		{
		case 0:
			m_state = IngkellsState::STATE_SWORDWAVE;
			m_fAniSpeed = 2.5f;
			break;
		case 1:
			m_state = IngkellsState::STATE_DOUBLESMASH;
			m_fAniSpeed = 2.f;
			break;

		default:
			break;
		}
		_double temp = m_pMeshCom->Get_AnimationPeriod(m_state);
		temp = (temp / (m_fAniSpeed)) - 0.1f;
		delay = temp;
		isAnimating = true;
		reverseDelay = 0.f;
		return;
	}
	//몬스터의 정면
	else if (angle > 0)
	{

		//오른쪽이다
		if (angle2 > 0)
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(130.f * fTimeDelta * spinSpeed));
			m_state = IngkellsState::STATE_RUN;
		}

		//왼쪽이다.
		else
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-130.f * fTimeDelta * spinSpeed));
			m_state = IngkellsState::STATE_RUN;
		}

	}
	//플레이어가 뒤에 있다.
	else
	{
		//오른쪽이다
		if (angle2 > 0)
		{
			m_state = IngkellsState::STATE_RUN;
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(130.f * fTimeDelta * spinSpeed));
		}
		//왼쪽이다.
		else
		{
			m_state = IngkellsState::STATE_RUN;
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-130.f * fTimeDelta * spinSpeed));
		}

	}
	m_fAniSpeed = 2.f;
	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

}

void CIngkells::Attack(const _float& fTimeDelta)
{
}

CIngkells* CIngkells::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CIngkells* pInstance = new CIngkells(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

CIngkells * CIngkells::Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage)
{
	CIngkells*	pInstance = new CIngkells(pGraphicDev);
	pInstance->SetStageNum(_stage);


	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CIngkells::Free(void)
{

	CMonster::Free();
}


HRESULT Client::CIngkells::Ready_Object(void)
{
	CMonster::Ready_Object();

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	m_pTransformCom->Set_Scale(0.02f, 0.02f, 0.02f);
	m_pStateCom->stat.moveSpeed = 2.f;
	m_pMeshCom->Set_AnimationSet(IngkellsState::STATE_IDLE);

	

	return S_OK;
}
Client::_int Client::CIngkells::Update_Object(const _float& fTimeDelta)
{
	CMonster::Update_Object(fTimeDelta);

	if (!initialize)
	{
		m_pStateCom->stat.maxHp = 100000.f;
		m_pStateCom->stat.hp = 100000.f;
		m_pStateCom->stat.damage = 100.f;
		m_pTransformCom->Set_Pos(&spawnPosition);
		_ulong i = m_pNaviMeshCom->GetdwIndex(&_vec2(spawnPosition.x, spawnPosition.z));
		m_pNaviMeshCom->Set_NaviIndex(i);
		initialize = true;

	}

	if (isDead)
	{
		return 1;
	}

 	if (delay > 0)
	{
		delay -= fTimeDelta;
	reverseDelay += fTimeDelta;
	}
	if (!isDie)
	{

		isSearch = PlayerSearch(m_pTransformCom->m_vInfo[Engine::INFO_POS]);
		//m_state = IngkellsState::STATE_IDLE;
		if (isSearch == true)
		{


			if (!isAnimating)
				Move(fTimeDelta);


			if (isAnimating)
			{
				_vec3	vPos, vDir, vRight;
				m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
				m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
				m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
				Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
				_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];
				float a = delay;
				//플레이어를 향한 위치벡터
				_vec3 toPlayerDir = playerPos - vPos;

				D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
				float rightRadian = D3DXVec3Dot(&toPlayerDir, &vRight);
				//플레이어가 내 왼쪽? 오른쪽?
				float angle2 = D3DXToDegree(rightRadian);

				//몬스터의 정면

				//발리스타공격
				if (m_state == STATE_TAUNT)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"CS_inkels_4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
					//플레이어를 향한 위치벡터
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 1.f;
					//오른쪽이다
					if (angle2 > 0)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
					}
					//왼쪽이다.
					else
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
					}
				}
				//주먹질
				else if (m_state == IngkellsState::STATE_WHIRLWIND)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

					//플레이어를 향한 위치벡터
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 1.f;
					//오른쪽이다
					if (angle2 > 0)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
					}
					//왼쪽이다.
					else
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
					}

					//기존 몬스터의 룩벡터
					D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
					D3DXVec3Normalize(&vDir, &vDir);
					//0.8 6.2
					if (reverseDelay > 0.59 / m_fAniSpeed && reverseDelay < 1.75 / m_fAniSpeed)
					{

						m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
					}

					//충돌판정 2.27 2.98
					if (reverseDelay > 0.59 / m_fAniSpeed && reverseDelay < 1.75 / m_fAniSpeed)
					{
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
						isColl = true;
					}
					else
					{
						isColl = false;
						isSound = false;
					}
				}
				

				//
				else if (m_state == IngkellsState::STATE_TURNRIGHT_ATK)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

					//플레이어를 향한 위치벡터
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 6.f;


					//기존 몬스터의 룩벡터
					D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
					D3DXVec3Normalize(&vDir, &vDir);
					m_pStateCom->stat.moveSpeed = 3.f;

					
					//if (reverseDelay > 1.67 / m_fAniSpeed && reverseDelay < 2.2 / m_fAniSpeed)
					//{
					//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

					//}
					//if (reverseDelay > 1.1 / m_fAniSpeed && reverseDelay < 2.8 / m_fAniSpeed)
					//{
					//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(20.f * fTimeDelta * spinSpeed));
					//	//isColl = true;
					//}
					//if (reverseDelay > 0.1)
					//{
					//	int i = 0;
					//}
					if (reverseDelay > 1.2 / m_fAniSpeed && reverseDelay < 1.35 / m_fAniSpeed)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-90.f * fTimeDelta * spinSpeed));
					}
					if (reverseDelay > 1.7 / m_fAniSpeed && reverseDelay < 1.85 / m_fAniSpeed)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(90.f * fTimeDelta * spinSpeed));
					}
					if (reverseDelay > 1.3 / m_fAniSpeed && reverseDelay < 1.87 / m_fAniSpeed)
					{
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
						isColl = true;
					}
					else
					{
						isSound = false;
						isColl = false;
					}
				}
				else if (m_state == IngkellsState::STATE_TURNLEFT_ATK)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

					//플레이어를 향한 위치벡터
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 6.f;


					//기존 몬스터의 룩벡터
					D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
					D3DXVec3Normalize(&vDir, &vDir);
					m_pStateCom->stat.moveSpeed = 5.f;

					//if (reverseDelay > 1.67 / m_fAniSpeed && reverseDelay < 2.2 / m_fAniSpeed)
					//{
					//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

					//}
					//if (reverseDelay > 1.1 / m_fAniSpeed && reverseDelay < 2.8 / m_fAniSpeed)
					//{
					//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-20.f * fTimeDelta * spinSpeed));
					//	//isColl = true;
					//}
					if (reverseDelay > 1.3 / m_fAniSpeed && reverseDelay < 1.87 / m_fAniSpeed)
					{
						/*m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(90.f * fTimeDelta * spinSpeed));*/
						isColl = true;
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
					}
					else
					{
						isColl = false;
						isSound = false;
					}
					if (true == m_pMeshCom->Is_AnimationSetEnd())
					{
						isAnimating = false;
						m_pStateCom->stat.moveSpeed = IngkellsSpeed;
						delay = 0;
						isColl = false;
						m_state = IngkellsState::STATE_IDLE;

					}
				}

				else if (m_state == IngkellsState::STATE_SWORDWAVE)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

					//플레이어를 향한 위치벡터
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 1.f;
					//오른쪽이다
					if (angle2 > 0)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
					}
					//왼쪽이다.
					else
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
					}

					//기존 몬스터의 룩벡터
					D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
					D3DXVec3Normalize(&vDir, &vDir);
					m_pStateCom->stat.moveSpeed = 4.f;
					float a = reverseDelay;
					//1.8f 스타트
					if (reverseDelay > 3.36 / m_fAniSpeed && reverseDelay < 5.31 / m_fAniSpeed)
					{
						m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

					}

					if (reverseDelay > 4.02 / m_fAniSpeed && reverseDelay < 5.5 / m_fAniSpeed)
					{
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
						isColl = true;
					}
					else
					{
						isColl = false;
						isSound = false;
					}
					if (true == m_pMeshCom->Is_AnimationSetEnd())
					{
						isAnimating = false;
						m_pStateCom->stat.moveSpeed = IngkellsSpeed;
						delay = 0;
						isColl = false;
						m_state = IngkellsState::STATE_IDLE;

					}
				}
				else if (m_state == IngkellsState::STATE_SWING_TRIPLE)
				{
				_vec3	vPos, vDir, vRight;
				m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
				m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
				m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
				Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
				_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

				//플레이어를 향한 위치벡터
				_vec3 toPlayerDir = playerPos - vPos;
				float spinSpeed = 1.f;
				//오른쪽이다
				if (angle2 > 0)
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
				}
				//왼쪽이다.
				else
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
				}

				//기존 몬스터의 룩벡터
				D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
				D3DXVec3Normalize(&vDir, &vDir);
				m_pStateCom->stat.moveSpeed = 2.f;
				//1.8f 스타트
				if (reverseDelay > 1.89 / m_fAniSpeed && reverseDelay < 2.9 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}
				else if (reverseDelay > 3.07 / m_fAniSpeed && reverseDelay < 3.79 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}

				else if (reverseDelay > 3.91 / m_fAniSpeed && reverseDelay < 5.27 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}

				else if (reverseDelay > 6.4 / m_fAniSpeed && reverseDelay < 7.45 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}
				if (reverseDelay > 2.87 / m_fAniSpeed && reverseDelay < 3.46 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else if (reverseDelay > 4.19 / m_fAniSpeed && reverseDelay < 5 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else if (reverseDelay > 6.45 / m_fAniSpeed && reverseDelay < 7.12 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else
				{
					isColl = false;
					isSound = false;
				}
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					isAnimating = false;
					m_pStateCom->stat.moveSpeed = IngkellsSpeed;
					delay = 0;
					isColl = false;
					m_state = IngkellsState::STATE_IDLE;

				}
				}
				else if (m_state == IngkellsState::STATE_THRUST_TO_WHIRLWIND)
				{
				_vec3	vPos, vDir, vRight;
				m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
				m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
				m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
				Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
				_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

				//플레이어를 향한 위치벡터
				_vec3 toPlayerDir = playerPos - vPos;
				float spinSpeed = 1.f;
				//오른쪽이다
				if (angle2 > 0)
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
				}
				//왼쪽이다.
				else
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
				}

				//기존 몬스터의 룩벡터
				D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
				D3DXVec3Normalize(&vDir, &vDir);
				m_pStateCom->stat.moveSpeed = 5.f;
				//1.8f 스타트
				if (reverseDelay > 1.95 / m_fAniSpeed && reverseDelay < 3.54 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}

				if (reverseDelay > 4.95 / m_fAniSpeed && reverseDelay < 6 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}

				if (reverseDelay > 3.24 / m_fAniSpeed && reverseDelay < 3.68 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else if (reverseDelay > 4.72 / m_fAniSpeed && reverseDelay < 6.33 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else
				{
					isColl = false;
					isSound = false;
				}
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					isAnimating = false;
					m_pStateCom->stat.moveSpeed = IngkellsSpeed;
					delay = 0;
					isColl = false;
					m_state = IngkellsState::STATE_IDLE;

				}
				}
				else if (m_state == IngkellsState::STATE_DOUBLESMASH)
				{
				_vec3	vPos, vDir, vRight;
				m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
				m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
				m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
				Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
				_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

				//플레이어를 향한 위치벡터
				_vec3 toPlayerDir = playerPos - vPos;
				float spinSpeed = 1.f;
				//오른쪽이다
				if (angle2 > 0)
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
				}
				//왼쪽이다.
				else
				{
					m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
				}

				//기존 몬스터의 룩벡터
				D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
				D3DXVec3Normalize(&vDir, &vDir);
				m_pStateCom->stat.moveSpeed = 2.f;
				//1.8f 스타트
				if (reverseDelay > 1.38 / m_fAniSpeed && reverseDelay < 1.95 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}
				else if (reverseDelay > 3.01 / m_fAniSpeed && reverseDelay < 3.99 / m_fAniSpeed)
				{
					m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

				}
				if (reverseDelay > 2.32 / m_fAniSpeed && reverseDelay < 2.56 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else if (reverseDelay > 3.93 / m_fAniSpeed && reverseDelay < 4.3 / m_fAniSpeed)
				{
					isColl = true;
					if (!isSound)
					{
						SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
						isSound = true;
					}
				}
				else
				{
					isColl = false;
					isSound = false;
				}
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{
					isAnimating = false;
					m_pStateCom->stat.moveSpeed = IngkellsSpeed;
					delay = 0;
					isColl = false;
					m_state = IngkellsState::STATE_IDLE;

				}
				}
				if (
					m_state == IngkellsState::STATE_WHIRLWIND ||
					m_state == IngkellsState::STATE_TURNRIGHT_ATK ||
					m_state == IngkellsState::STATE_TURNLEFT_ATK ||
					m_state == IngkellsState::STATE_SWORDWAVE ||
					m_state == IngkellsState::STATE_SWING_TRIPLE ||
					m_state == IngkellsState::STATE_THRUST_TO_WHIRLWIND ||
					m_state == IngkellsState::STATE_DOUBLESMASH||
					m_state != IngkellsState::STATE_RUN
					) {
					if (true == m_pMeshCom->Is_AnimationSetEnd())
					{
						SoundManager::PlayOverlapSound(L"mankind_shout_boss_01.wav", SoundChannel::MONSTER, 0.2f);
							isAnimating = false;
							m_pStateCom->stat.moveSpeed = IngkellsSpeed;
							delay = 0;
							isColl = false;
							isSound = false;
	
					}
				}
				float delay3 = delay;
			}


			float  delay2 = delay;
			int i = 0;
			//이동
		}
	}
	else if (isDie)
	{
	if (!dieSound)
	{
		SoundManager::PlayOverlapSound(L"mankind_low_health_01.wav", SoundChannel::MONSTER, 0.2f);
		dieSound = true;
	}
		m_state = IngkellsState::STATE_DYING_FRONT;
		if (true == m_pMeshCom->Is_AnimationSetEnd())
		{
			isDead = true;
			return 1;
		}
	}
	m_pMeshCom->Set_AnimationSet(m_state);


	//SetUp_OnTerrain()
	//Engine::CGameObject::Update_Object(fTimeDelta);	

	_vec3 vLook, vUp, vRight, vLeft, vDir, vPos, vScale, vRot, vMyPos;

	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vLook);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	m_pTransformCom->Get_Info(Engine::INFO_UP, &vUp);
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vMyPos);

	//m_pMeshCom->Play_Animation(fTimeDelta * m_fAniSpeed);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CIngkells::Render_Object(void)
{
	CMonster::Render_Object();
	LPD3DXEFFECT	 pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	_uint	iMaxPass = 0;

	pEffect->Begin(&iMaxPass, 0);	// 현재 쉐이더 파일이 갖고 있는 최대 패스의 개수를 리턴, 사용하는 방식
	pEffect->BeginPass(0);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	float fTimeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	m_pMeshCom->Render_Meshes(pEffect, fTimeDelta * m_fAniSpeed);

	pEffect->EndPass();
	pEffect->End();

	m_pNaviMeshCom->Render_NaviMeshes();


	Engine::Safe_Release(pEffect);
}

void Client::CIngkells::SetUp_OnTerrain(void)
{
	_vec3	vPosition;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	Engine::CTerrainTex* pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}

void CIngkells::OnCollision(Engine::CGameObject* target)
{
	CMonster::OnCollision(target);

}
