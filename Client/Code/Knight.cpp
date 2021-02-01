#include "stdafx.h"
#include "Knight.h"
#include "Export_Function.h"
#include "DynamicCamera.h"


CKnight::CKnight(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{

}

CKnight::~CKnight(void)
{
	//for (auto& iterator = m_VecSphereCollider.begin(); iterator != m_VecSphereCollider.end();++iterator)
	//{
	//	//Engine::Safe_Delete_Array(*iterator);
	//		Engine::Safe_Release(*iterator);
	//}
}

Client::_vec3 Client::CKnight::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
}

HRESULT Client::CKnight::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	CMonster::Add_Component();

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Knight"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	
	//float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	//int i = rand() % 8;
	//m_pTransformCom->Set_Pos(&_vec3{23.f+i,0.f,23.f+i});
	//Engine::CGameObject::Update_Object(timeDelta);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	

	Load_ColliderFile(L"../Bin/saveKnight.dat", Engine::COLLID::ENEMY, Engine::COLLID::ENEMYATTACK);
	return S_OK;
}

HRESULT CKnight::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
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


void CKnight::Move(const _float& fTimeDelta)
{

	_vec3	vPos, vDir, vRight;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

	//�÷��̾ ���� ��ġ����
	_vec3 toPlayerDir = playerPos - vPos;

	//���� ������ �躤��
	D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
	D3DXVec3Normalize(&vDir, &vDir);

	//������ ���� ����
	float frontRadian = D3DXVec3Dot(&toPlayerDir, &vDir);
	float rightRadian = D3DXVec3Dot(&toPlayerDir, &vRight);



	//�÷��̾ �� ��? �� ��?
	float angle = D3DXToDegree(frontRadian);
	//�÷��̾ �� ����? ������?
	float angle2 = D3DXToDegree(rightRadian);
	//		45	56	60	52 45 	22.5
	//		0.78 0.98	0.7
	//			    ��
	//      0        ��		-0
	//		     (����)
	//
	//			-40 -60  -55
	//			-0.7 -0.9 -1
	// -10
	//�÷��̾ ���鿡�ִ�
	//������ �þ߰�
	float spinSpeed = 5.f;
	if (disPlayer < 1.f&&angle>0)
	{

		/*int i = rand() % 2;*/
		int i = 0;
		switch (i)
		{
		case 0:
			m_state = KnightState::STATE_Knight_Att;
			m_fAniSpeed = 1.5f;
			//delay = 4.2f;
			break;
			//case 1:
			//	m_state = KnightState::STATE_ATT;
			//	//delay = 3.2f;//3.13
			//	m_fAniSpeed = 1.f;

			//	break;
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
	else if (55.f <= angle && angle < 60.f)
	{
		m_state = KnightState::STATE_STAPFRONT;
		if (disPlayer < 1.5f)
		{

			/*int i = rand() % 2;*/
			int i = 0;
			switch (i)
			{
			case 0:
				m_state = KnightState::STATE_Knight_Att;
				m_fAniSpeed = 1.5f;
				//delay = 4.2f;
				break;
			//case 1:
			//	m_state = KnightState::STATE_ATT;
			//	//delay = 3.2f;//3.13
			//	m_fAniSpeed = 1.f;

			//	break;
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

	//������ ����
	else if (angle > 0)
	{

		//�������̴�
		if (angle2 > 0)
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
			m_state = KnightState::STATE_STAPFRONT;

		}

		//�����̴�.
		else
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
			m_state = KnightState::STATE_STAPFRONT;
		}

	}
	//�÷��̾ �ڿ� �ִ�.
	else
	{
		//�������̴�
		if (angle2 > 0)
		{

			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));

			//isAnimating = true;
			//m_state = titanState::STATE_TURNRIGHT;
		}
		//�����̴�.
		else
		{
			m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
			m_state = KnightState::STATE_STAPFRONT;
		}
		//m_state = titanState::STATE_ATTACKKICK;

	}
	m_fAniSpeed = 1.5f;
	m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
	if (Engine::Get_DIKeyState(DIK_Z) & 0x80)
	{
		m_pTransformCom->Set_Pos(102.f, 0.f, 6.5f);
	}
}

CKnight* CKnight::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CKnight*	pInstance = new CKnight(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

CKnight * CKnight::Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage)
{
	CKnight*	pInstance = new CKnight(pGraphicDev);
	pInstance->SetStageNum(_stage);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;

}

void CKnight::Free(void)
{
	CMonster::Free();
}


HRESULT Client::CKnight::Ready_Object(void)
{
	/*CMonster::Ready_Object();*/
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	
	m_pTransformCom->Set_Scale(0.015f, 0.015f, 0.015f);
	m_pMeshCom->Set_AnimationSet(KnightState::STATE_STAND);



	return S_OK;
}
Client::_int Client::CKnight::Update_Object(const _float& fTimeDelta)
{
	_vec3	vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	if (nullptr != m_pOptimizationCom)
	m_bDraw = m_pOptimizationCom->Is_InFrustumForObject(&vPos, 0.f);
	if (!initialize)
	{
		
		m_pStateCom->stat.maxHp = 10000.f;
		m_pStateCom->stat.hp = 10000.f;
		m_pStateCom->stat.damage = 100.f;
		m_pTransformCom->Set_Pos(&spawnPosition);
		if (nullptr != m_pNaviMeshCom)
		{
			_ulong i = m_pNaviMeshCom->GetdwIndex(&_vec2(spawnPosition.x, spawnPosition.z));
			m_pNaviMeshCom->Set_NaviIndex(i);
		}
		initialize = true;

	}
	
	CMonster::Update_Object(fTimeDelta);

	if (isDead)
		return 1;
	if (delay > 0)
	{
		delay -= fTimeDelta;
		reverseDelay += fTimeDelta;
	}
	if (!isDie)
	{
		isSearch = PlayerSearch(m_pTransformCom->m_vInfo[Engine::INFO_POS]);
		//m_state = titanState::STATE_IDLE;
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

				//�÷��̾ ���� ��ġ����
				_vec3 toPlayerDir = playerPos - vPos;

				D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
				float rightRadian = D3DXVec3Dot(&toPlayerDir, &vRight);
				//�÷��̾ �� ����? ������?
				float angle2 = D3DXToDegree(rightRadian);
				if (m_state == KnightState::STATE_Knight_Att)
				{
					_vec3	vPos, vDir, vRight;
					m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
					m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vDir);
					m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
					Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
					_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];

					//�÷��̾ ���� ��ġ����
					_vec3 toPlayerDir = playerPos - vPos;
					float spinSpeed = 1.f;
					//�������̴�
					if (angle2 > 0)
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(60.f * fTimeDelta * spinSpeed));
					}
					//�����̴�.
					else
					{
						m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-60.f * fTimeDelta * spinSpeed));
					}

					//���� ������ �躤��
					D3DXVec3Normalize(&toPlayerDir, &toPlayerDir);
					D3DXVec3Normalize(&vDir, &vDir);
					//6.13 

					//0.83 2.06
					if (reverseDelay > 3.26 / m_fAniSpeed && reverseDelay < 3.6 / m_fAniSpeed)
					{
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"mankind_shout_01.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
						m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed)));
					}
					else if (reverseDelay > 3.69 / m_fAniSpeed && reverseDelay < 4.17 / m_fAniSpeed)
					{

						m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed*1.5f)));
					}
					else if (reverseDelay > 5.02 / m_fAniSpeed && reverseDelay < 6.02 / m_fAniSpeed)
					{
						m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_pStateCom->stat.moveSpeed*1.5f)));
					}
					else
					{
						isSound = false;
					}
					if (reverseDelay > 3.47 / m_fAniSpeed && reverseDelay < 3.83 / m_fAniSpeed)
					{
						if (!isSound)
						{
							SoundManager::PlayOverlapSound(L"swing_lv4.wav", SoundChannel::MONSTER, 0.2f);
							isSound = true;
						}
						isColl = true;
					}
					else  if (reverseDelay > 5.09 / m_fAniSpeed && reverseDelay < 5.5 / m_fAniSpeed)
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
			
				//������ ����
				if (true == m_pMeshCom->Is_AnimationSetEnd())
				{

					isAnimating = false;
					m_pStateCom->stat.moveSpeed = TitanSpeed;
					delay = 0;
					isColl = false;

				}
			}
		}
	}
	else if (isDie)
	{
		m_state = KnightState::STATE_DOWNSTART;
		if (true == m_pMeshCom->Is_AnimationSetEnd())
		{
			isDead = true;
			return 1;
		}
	}
	m_pMeshCom->Set_AnimationSet(m_state);
	//SetUp_OnTerrain()



	//m_pMeshCom->Play_Animation(fTimeDelta * m_fAniSpeed * 1.5f);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CKnight::Render_Object(void)
{

	if (false == m_bDraw&&disPlayer > 2.f)
		return;

	CMonster::Render_Object();
	LPD3DXEFFECT	 pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	_uint	iMaxPass = 0;

	pEffect->Begin(&iMaxPass, 0);	// ���� ���̴� ������ ���� �ִ� �ִ� �н��� ������ ����, ����ϴ� ���
	pEffect->BeginPass(0);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );
	float fTimeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	m_pMeshCom->Render_Meshes(pEffect, fTimeDelta * m_fAniSpeed);
	
	pEffect->EndPass();
	pEffect->End();

	m_pNaviMeshCom->Render_NaviMeshes();


	Engine::Safe_Release(pEffect);
}
void CKnight::OnCollision(Engine::CGameObject* target)
{
	CMonster::OnCollision(target);
	if (m_state != STATE_DMGUP)
	{
		m_state = STATE_DMGUP;
		isAnimating = true;
	}
}
void Client::CKnight::SetUp_OnTerrain(void)
{
	_vec3	vPosition;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}
