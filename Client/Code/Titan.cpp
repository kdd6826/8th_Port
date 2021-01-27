#include "stdafx.h"
#include "Titan.h"
#include "ColliderMgr.h"
#include "Export_Function.h"


CTitan::CTitan(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{

}

CTitan::~CTitan(void)
{
	int i = 0;
}

Client::_vec3 Client::CTitan::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
}

HRESULT Client::CTitan::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Titan"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	CMonster::Add_Component();

	float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	m_pTransformCom->Set_Pos(&_vec3{ 17.f,0.f,17.f });
	Engine::CGameObject::Update_Object(timeDelta);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	Load_ColliderFile(L"../Bin/saveTitan.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);

	m_pStateCom->stat.maxHp = 100000.f;
	m_pStateCom->stat.hp = 100000.f;
	return S_OK;
}

HRESULT CTitan::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
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


void CTitan::Move(const _float& fTimeDelta)
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
	if (55.f <= angle && angle < 60.f)
	{
		m_state = titanState::STATE_RUN;
		if (disPlayer < 2.f)
		{

			int i = rand() % 8;
			//int i = 1;
			switch (i)
			{
			case 0:
				m_state = titanState::STATE_ATTACKBALLISTA;
				m_fAniSpeed = 3.5f;
				//delay = 4.2f;
				break;
			case 1:
				m_state = titanState::STATE_ATTACKHAMMER;
				//delay = 3.2f;//3.13
				m_fAniSpeed = 3.5f;

				break;
			case 2:
				m_state = titanState::STATE_ATTACKKICK;
				//delay = 2.9f; //2.82
				m_fAniSpeed = 3.5f;
				break;
			case 3:
				m_state = titanState::STATE_ATTACKRAGE;
				//delay = 8.3f;//8.28
				m_fAniSpeed = 2.5f;
				break;
			case 4:
				m_state = titanState::STATE_ATTACKSTOMP;
				//delay = 3.6f;//3.55
				m_fAniSpeed = 2.5f;
				break;
			case 5:
				m_state = titanState::STATE_ATTACKTURNLEFT;
				//delay = 2.3f;//2.2
				m_fAniSpeed = 3.5f;
				break;
			case 6:
				m_state = titanState::STATE_ATTACKTURNRIGHT;
				//delay = 2.2f;//2.1f
				m_fAniSpeed = 3.5f;
				break;
			case 7:
				m_state = titanState::STATE_ATTACKTWOSTEP;
				//delay = 1.9f;//1.8f
				m_fAniSpeed = 2.f;
				break;
			default:
				break;
			}
			_double temp = m_pMeshCom->Get_AnimationPeriod(m_state);
			temp = (temp / (m_fAniSpeed)) - 0.2f;
			delay = temp;
			isAnimating = true;
			reverseDelay = 0.f;
			return;
		}
	}

	//몬스터의 정면
	else if (angle > 0)
	{

		//오른쪽이다
		if (angle2 > 0)
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta* spinSpeed));
			m_state = titanState::STATE_RUN;

		}

		//왼쪽이다.
		else
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta* spinSpeed));
			m_state = titanState::STATE_RUN;
		}

	}
	//플레이어가 뒤에 있다.
	else
	{
		//오른쪽이다
		if (angle2 > 0)
		{

			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta* spinSpeed));

			//isAnimating = true;
			//m_state = titanState::STATE_TURNRIGHT;
		}
		//왼쪽이다.
		else
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta* spinSpeed));
			m_state = titanState::STATE_RUN;
		}
		//m_state = titanState::STATE_ATTACKKICK;

	}
	m_fAniSpeed = 1.5f;
	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

}

void CTitan::Attack(const _float& fTimeDelta)
{
}

CTitan* CTitan::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CTitan*	pInstance = new CTitan(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CTitan::Free(void)
{

	CMonster::Free();
}


HRESULT Client::CTitan::Ready_Object(void)
{
	CMonster::Ready_Object();

	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(0.05f, 0.05f, 0.05f);
	m_pStateCom->stat.moveSpeed = 2.f;
	m_pMeshCom->Set_AnimationSet(titanState::STATE_IDLE);



	return S_OK;
}
Client::_int Client::CTitan::Update_Object(const _float& fTimeDelta)
{
	CMonster::Update_Object(fTimeDelta);

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
		//m_state = titanState::STATE_IDLE;
#pragma region AI



		//if (isSearch == true)
		//{


		//	if (!isAnimating)
		//		Move(fTimeDelta);


		//	if (isAnimating)
		//	{
		//		_vec3	vPos, vDir, vRight;
		//		m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//		m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//		m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//		Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//		_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//		//플레이어를 향한 위치벡터
		//		_vec3 toPlayerDir = playerPos - vPos;

		//		D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//		float rightRadian = D3DXVec3Dot(&toPlayerDir, &vRight);
		//		//플레이어가 내 왼쪽? 오른쪽?
		//		float angle2 = D3DXToDegree(rightRadian);

		//		//몬스터의 정면

		//		//발리스타공격
		//		if (m_state == titanState::STATE_ATTACKBALLISTA)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			if (angle2 > 0)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			}
		//			//왼쪽이다.
		//			else
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			//6.13 

		//			//0.83 2.06
		//			if (reverseDelay > 0.8 / m_fAniSpeed && reverseDelay < 2.06 / m_fAniSpeed)
		//			{
		//				
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}
		//			//4 6.4
		//			if (reverseDelay > 4 / m_fAniSpeed && reverseDelay < 6.4 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}
		//			if (reverseDelay > 6 / m_fAniSpeed && reverseDelay < 6.3 / m_fAniSpeed)
		//			{

		//				isColl = true;
		//			}
		//			else
		//			isColl = false;
		//		}
		//		//주먹질
		//		else if (m_state == titanState::STATE_ATTACKHAMMER)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			if (angle2 > 0)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			}
		//			//왼쪽이다.
		//			else
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			//0.8 6.2
		//			if (reverseDelay > 0.8 / m_fAniSpeed && reverseDelay < 6.2 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}

		//			//충돌판정 2.27 2.98
		//			if (reverseDelay > 2.27 / m_fAniSpeed && reverseDelay < 2.7 / m_fAniSpeed)
		//			{

		//				isColl = true;
		//			}
		//			//충돌판정 4.1 4.6
		//			else if (reverseDelay > 4.1 / m_fAniSpeed && reverseDelay < 4.6 / m_fAniSpeed)
		//			{
		//				
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 5.3 / m_fAniSpeed && reverseDelay < 5.7 / m_fAniSpeed)
		//			{
		//				
		//				isColl = true;
		//			}
		//			else
		//				isColl = false;
		//		}
		//		//발차기
		//		else if (m_state == titanState::STATE_ATTACKKICK)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			//if (angle2 > 0)
		//			//{
		//			//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			//}
		//			////왼쪽이다.
		//			//else
		//			//{
		//			//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			//}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 5.f;

		//			if (reverseDelay > 2.6 / m_fAniSpeed && reverseDelay < 4 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}
		//			//if (reverseDelay > 7.56 / m_fAniSpeed && reverseDelay < 9.45 / m_fAniSpeed)
		//			//{
		//			//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			//}
		//			//충돌판정 4.2 5.5
		//			if (reverseDelay > 4.2 / m_fAniSpeed && reverseDelay < 5.5 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else
		//				isColl = false;

		//			}
		//		//분노의주먹질
		//		else if (m_state == titanState::STATE_ATTACKRAGE)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			if (angle2 > 0)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			}
		//			//왼쪽이다.
		//			else
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 5.f;
		//			////8.3f 스타트
		//			//if (delay > 5.5f && delay < 7.1f)
		//			//{
		//			//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			//	isColl = true;
		//			//}
		//			//else if (delay > 1.4f && delay < 3.8f)
		//			//{
		//			//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			//	isColl = true;
		//			//}
		//			//else
		//			//{
		//			//	isColl = false;
		//			//}

		//			if (reverseDelay > 3.5 / m_fAniSpeed && reverseDelay < 7.2 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}
		//			//12 16
		//			if (reverseDelay > 12.f / m_fAniSpeed && reverseDelay < 16.f / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}
		//			//if (reverseDelay > 7.56 / m_fAniSpeed && reverseDelay < 9.45 / m_fAniSpeed)
		//			//{
		//			//	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			//}
		//			//충돌판정 4.2 5.5
		//			if (reverseDelay > 4.98 / m_fAniSpeed && reverseDelay < 5.2f / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 6.9 / m_fAniSpeed && reverseDelay < 7.1f / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 8.6 / m_fAniSpeed && reverseDelay < 8.8f / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 10.6 / m_fAniSpeed && reverseDelay < 10.8f / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 12.9 / m_fAniSpeed && reverseDelay < 13.1 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 13.8 / m_fAniSpeed && reverseDelay < 14 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 14.7 / m_fAniSpeed && reverseDelay < 14.9 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 15.7 / m_fAniSpeed && reverseDelay < 15.9 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 16.5 / m_fAniSpeed && reverseDelay < 16.7 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//		
		//			//12.9 13.8 14.7 15.7	16.5
		//			else
		//				isColl = false;

		//			
		//		}
		//		//
		//		else if (m_state == titanState::STATE_ATTACKSTOMP)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			if (angle2 > 0)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			}
		//			//왼쪽이다.
		//			else
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 3.f;
		//			//3.5f 스타트
		//			//4.53 5.12

		//			if (reverseDelay > 4.35 / m_fAniSpeed && reverseDelay < 5.6 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
		//			}


		//			//move 4.35 5.6
		//			if (reverseDelay > 4.53 / m_fAniSpeed && reverseDelay < 5.12f / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}

		//			else
		//			{
		//				isColl = false;
		//			}
		//		}
		//		else if (m_state == titanState::STATE_ATTACKTURNLEFT)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 6.f;
		//			//오른쪽이다
		//			//if (angle2 > 0)
		//			//{
		//			//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			//}
		//			////왼쪽이다.
		//			//else
		//			//{
		//			//}


		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 3.f;

		//			/*if (delay > 1.3f && delay < 1.4f)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

		//			}*/
		//			if (reverseDelay > 2.5f / m_fAniSpeed && reverseDelay < 4.f / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

		//			}
		//			if (reverseDelay > 1.1 / m_fAniSpeed && reverseDelay < 2.8 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(20.f * fTimeDelta * spinSpeed));
		//				//isColl = true;
		//			}
		//			else if (reverseDelay > 3.3 / m_fAniSpeed && reverseDelay < 4.1 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-90.f * fTimeDelta * spinSpeed));
		//				isColl = true;
		//			}
		//			else
		//			{
		//				isColl = false;
		//			}
		//			/*else if (delay > 3.3f && delay < 4.3f)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-172.5f * fTimeDelta * spinSpeed));
		//				
		//			}*/
		//			//1.1 2.8
		//			//3.3 4.3
		//			//else if (delay > 1.5f && delay < 2.f)
		//			//{
		//			//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(20.f * fTimeDelta * spinSpeed));

		//			//}
		//			//else if (delay > 1.2f && delay < 1.35f)
		//			//{
		//			//	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-172.5f * fTimeDelta * spinSpeed));
		//			//	isColl = true;
		//			//}
		//		}
		//		else if (m_state == titanState::STATE_ATTACKTURNRIGHT)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 6.f;


		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 5.f;
		//			//8.3f 스타트
		//			if (reverseDelay > 2.5f / m_fAniSpeed && reverseDelay < 3.6f / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

		//			}
		//			if (reverseDelay > 1.4 / m_fAniSpeed && reverseDelay < 2.8 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-20.f * fTimeDelta * spinSpeed));
		//				//isColl = true;
		//			}
		//			else if (reverseDelay > 3.3 / m_fAniSpeed && reverseDelay < 3.6 / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(90.f * fTimeDelta * spinSpeed));
		//				isColl = true;
		//			}

		//			else
		//			{
		//				isColl = false;
		//			}

		//		}



		//		//}
		//		else if (m_state == titanState::STATE_ATTACKTWOSTEP)
		//		{
		//			_vec3	vPos, vDir, vRight;
		//			m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
		//			m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
		//			m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		//			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		//			_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

		//			//플레이어를 향한 위치벡터
		//			_vec3 toPlayerDir = playerPos - vPos;
		//			float spinSpeed = 1.f;
		//			//오른쪽이다
		//			if (angle2 > 0)
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
		//			}
		//			//왼쪽이다.
		//			else
		//			{
		//				m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
		//			}

		//			//기존 몬스터의 룩벡터
		//			D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
		//			D3DXVec3Normalize(&vDir, &vDir);
		//			m_pStateCom->stat.moveSpeed = 7.f;
		//			//1.8f 스타트
		//			if (reverseDelay > 1.6f / m_fAniSpeed && reverseDelay < 2.6f / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

		//			}
		//			if (reverseDelay > 2.8f / m_fAniSpeed && reverseDelay < 3.5f / m_fAniSpeed)
		//			{
		//				m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));

		//			}
		//			if (reverseDelay > 2.5 / m_fAniSpeed && reverseDelay < 2.8 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else if (reverseDelay > 3.5 / m_fAniSpeed && reverseDelay < 3.7 / m_fAniSpeed)
		//			{
		//				isColl = true;
		//			}
		//			else
		//				isColl = false;
		//		}

		//		if (true == m_pMeshCom->Is_AnimationSetEnd())
		//		{

		//			isAnimating = false;
		//			m_pStateCom->stat.moveSpeed = TitanSpeed;
		//			delay = 0;
		//			isColl = false;

		//		}
		//	}



		//	//이동
		//}
#pragma endregion
	}
	else if (isDie)
	{
		m_state = titanState::STATE_DYINGFRONT;
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
void Client::CTitan::Render_Object(void)
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

void Client::CTitan::SetUp_OnTerrain(void)
{
	_vec3	vPosition;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}

void CTitan::OnCollision(Engine::CGameObject* target)
{
	CMonster::OnCollision(target);

}
