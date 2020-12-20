#include "stdafx.h"
#include "Player.h"
#include "Export_Function.h"
#include "DynamicCamera.h"

CPlayer::CPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
	, m_vDir(0.f, 0.f, 0.f)
{

}

CPlayer::~CPlayer(void)
{

}

Client::_vec3 Client::CPlayer::PickUp_OnTerrain(void)
{
	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pTerrainBufferCom, _vec3(0.f, 0.f, 0.f));

	Engine::CTransform*		pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom, _vec3(0.f, 0.f, 0.f));

	return m_pCalculatorCom->Picking_OnTerrain(g_hWnd, pTerrainBufferCom, pTerrainTransformCom);
}

HRESULT Client::CPlayer::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Player"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);

	pComponent = m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Calculator
	pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	m_pTransformCom->Set_Pos(&PlayerSpawnPosition);
	Engine::CGameObject::Update_Object(timeDelta);
	// Collider 
	//pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

HRESULT CPlayer::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
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

void Client::CPlayer::Key_Input(const _float& fTimeDelta)
{

	if (delay > 0)
	{
		delay -= fTimeDelta;
	}

	if (m_state == playerState::STATE_ATT1 ||
		m_state == playerState::STATE_ATT2 ||
		m_state == playerState::STATE_ATT3 ||
		m_state == playerState::STATE_ATT4 ||
		m_state == playerState::STATE_ATT5 ||
		m_state == playerState::STATE_MB_ATT1 ||
		m_state == playerState::STATE_MB_ATT2 ||
		m_state == playerState::STATE_MB_ATT3 ||
		m_state == playerState::STATE_MB_ATT4 ||
		m_state == playerState::STATE_MB_ATT5 ||
		m_state == playerState::STATE_MB_ATT6 ||
		m_state == playerState::STATE_THROW_BALL ||
		m_state == playerState::STATE_RUINBLADE ||
		m_state == playerState::STATE_LORDOFMANA ||
		m_state == playerState::STATE_DOOMSAYER ||
		m_state == playerState::STATE_DIFUSION
		)
	{
		isAttack = true;
	}

	else
	{
		isAttack = false;
	}

	if (m_state == playerState::STATE_FIELD_RUN ||
		m_state == playerState::STATE_FIELD_SPRINT ||
		m_state == playerState::STATE_FIELD_SPRINTSTOP ||
		m_state == playerState::STATE_TIRED_RUN ||
		m_state == playerState::STATE_DASH
		)
	{
		isMove = true;
	}
	else
	{
		isMove = false;
	}
	if (m_fBattleCount > 0.f)
	{
		isBattle = true;
		m_fBattleCount -= fTimeDelta;
	}
	else
	{
		isBattle = false;
	}

	if (delay <= 0)
	{
		m_fAniSpeed = 1.f;
		if (isBattle == false)
		{
			m_state = playerState::STATE_IDLE;
		}
		else if (isBattle == true)
		{
			if (isManaBlade == true)
			{
				m_state = playerState::STATE_MANA_IDLE;
				m_fBattleCount = 5.f;
			}
			else if (isManaBlade == false)
			{
				m_state = playerState::STATE_BATTLE_IDLE;
			}
		}

		if (Engine::Get_DIKeyState(DIK_LSHIFT) & 0x80)
		{
			isRunning = true;
		}
		else
		{
			isRunning = false;
		}
		if (isSkill == false)
		{
			MovePlayer(fTimeDelta);

			if (Engine::Get_DIKeyState(DIK_TAB) & 0x80)
			{

				if (isManaBlade == true)
				{
					isManaBlade = false;
					m_state = STATE_NORMAlBLADE;
					delay = 1.2f;
					m_fBattleCount = 5.f;
					isSkill = true;
				}
				else if (isManaBlade == false)
				{
					isManaBlade = true;
					m_state = STATE_MANABLADE;
					m_fBattleCount = 5.f;
					delay = 1.60f;
					m_fAniSpeed = 1.1f;
					isSkill = true;
				}
			}
		}
	}

	if (isSkill == false)
	{
		//가드
		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{
			if (delay <= 0.f)
			{
				m_state = playerState::STATE_CONFUSIONHOLE;
				delay = 1.f;
				m_fBattleCount = 5.f;
			}
		}
	}
	if (isSkill == false)
	{
		if (m_state == playerState::STATE_CONFUSIONHOLE && delay < 0.3f)
			Attack(fTimeDelta);
		else if (m_state == playerState::STATE_DIFUSION && delay < 0.5f)
			Attack(fTimeDelta);
		else if (m_state != playerState::STATE_CONFUSIONHOLE && m_state != playerState::STATE_DIFUSION)
			Attack(fTimeDelta);
	}
	//대쉬상태
	if (m_state == playerState::STATE_DIFUSION && delay > 0.75f)
	{
		_vec3 vLook, vUp, vRight, vLeft, vDir, vPos, vCamPos, vMyPos;
		_float fCamAngle;
		m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vLook);
		m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
		m_pTransformCom->Get_Info(Engine::INFO_UP, &vUp);
		m_pTransformCom->Get_Info(Engine::INFO_POS, &vMyPos);

		D3DXVec3Normalize(&vLook, &vLook);
		m_fSpeed = 5.f;
		m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed)));

	}
	if (m_state == playerState::STATE_DIFUSION && delay <= 0.8f)
	{
		//대쉬가드
		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{

			m_state = playerState::STATE_CONFUSIONHOLE;
			delay = 1.f;
			m_fBattleCount = 5.f;

		}
	}
	if (isSkill == false)
	{
		//어택중 가드
		if (delay <= 0.8f && isAttack)
		{
			if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
			{

				m_state = playerState::STATE_CONFUSIONHOLE;
				delay = 1.f;
				m_fBattleCount = 5.f;

			}
		}
	}
	if (isSkill)
	{
		if (m_state == playerState::STATE_IDLE ||
			m_state == playerState::STATE_BATTLE_IDLE ||
			m_state == playerState::STATE_MANA_IDLE ||
			m_state == playerState::STATE_DOWN_IDLE
			)
		{
			isSkill = false;

		}
		else if (true == m_pMeshCom->Is_AnimationSetEnd())
		{
			isSkill = false;
		}
	}

	m_pMeshCom->Set_AnimationSet(m_state);

}

void CPlayer::MovePlayer(const _float& fTimeDelta)
{

	_vec3 vLook, vUp, vRight, vLeft, vDir, vPos, vCamPos, vMyPos;
	_float fCamAngle;
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vLook);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	m_pTransformCom->Get_Info(Engine::INFO_UP, &vUp);
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vMyPos);

	Engine::CTerrainTex* pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	Engine::CCamera* pCamera = dynamic_cast<Engine::CCamera*>(Engine::Get_GameObject(L"UI", L"DynamicCamera"));
	vCamPos = pCamera->Get_Eye();
	fCamAngle = pCamera->Get_Angle();




	if (Engine::Get_DIKeyState(DIK_W) & 0x80)
	{
		if (isRunning)
		{
			m_state = playerState::STATE_FIELD_SPRINT;
			m_fSpeed = 5.f;

		}
		else if (!isRunning)
		{
			m_state = playerState::STATE_FIELD_RUN;
			m_fSpeed = 3.f;
		}

		//m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));
		m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));
		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle);

		if (Engine::Get_DIKeyState(DIK_A) & 0x80)
		{

			m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));
			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-45));
		}
		else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
		{


			//m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));
			m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));
			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(45));
		}

		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{
			if (delay <= 0.f)
			{
				m_state = playerState::STATE_DIFUSION;
				delay = 1.2f;
				m_fBattleCount = 6.2f;

				m_fAniSpeed = 1.2f;
			}
		}


	}

	else if (Engine::Get_DIKeyState(DIK_S) & 0x80)
	{
		if (isRunning)
		{
			m_state = playerState::STATE_FIELD_SPRINT;
			m_fSpeed = 5.f;
		}
		else if (!isRunning)
		{
			m_state = playerState::STATE_FIELD_RUN;
			m_fSpeed = 3.f;
		}
		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{
			if (delay <= 0.f)
			{
				m_state = playerState::STATE_DIFUSION;
				delay = 1.2f;
				m_fBattleCount = 6.2f;
				m_fAniSpeed = 1.2f;
			}
		}

		m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(180));
		if (Engine::Get_DIKeyState(DIK_A) & 0x80)
		{
			m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));
			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-135));
		}
		else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
		{

			m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vLook * fTimeDelta * m_fSpeed * 100.f)));

			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(135));
		}
	}

	else if (Engine::Get_DIKeyState(DIK_A) & 0x80)
	{
		if (isRunning)
		{
			m_state = playerState::STATE_FIELD_SPRINT;
			m_fSpeed = 5.f;
		}
		else if (!isRunning)
		{
			m_state = playerState::STATE_FIELD_RUN;
			m_fSpeed = 3.f;
		}
		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{
			if (delay <= 0.f)
			{
				m_state = playerState::STATE_DIFUSION;
				delay = 1.2f;
				m_fBattleCount = 6.2f;
				m_fAniSpeed = 1.2f;
			}
		}

		vDir = (vCamPos - vMyPos);
		_vec3 up;
		up = { 0.f,1.f,0.f };
		D3DXVec3Cross(&vDir, &up, &vDir);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vDir * fTimeDelta * m_fSpeed)));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-90));
	}
	else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
	{
		if (isRunning)
		{
			m_state = playerState::STATE_FIELD_SPRINT;
			m_fSpeed = 5.f;
		}
		else if (!isRunning)
		{
			m_state = playerState::STATE_FIELD_RUN;
			m_fSpeed = 3.f;
		}
		if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
		{
			if (delay <= 0.f)
			{
				m_state = playerState::STATE_DIFUSION;
				delay = 1.2f;
				m_fBattleCount = 6.2f;
				m_fAniSpeed = 1.2f;
			}
		}
		vDir = (vCamPos - vMyPos);
		_vec3 up;
		up = { 0.f,1.f,0.f };
		D3DXVec3Cross(&vDir, &vDir, &up);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vMyPos, &(vDir * fTimeDelta * m_fSpeed)));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(90));
	}


}

void CPlayer::Attack(const _float& fTimeDelta)
{

	if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	{
#pragma region NormalBladeAttack
		if (isManaBlade == false)
		{

			if (delay <= 1.2f)
			{
				if (m_state == playerState::STATE_ATT4)
				{
					m_state = playerState::STATE_ATT5;
					delay = 1.8f;
				}
			}
			if (delay <= 0.9f)
			{
				if (m_state == playerState::STATE_ATT3)
				{
					m_state = playerState::STATE_ATT4;
					delay = 1.9f;
				}
			}
			if (delay <= 0.8f)
			{
				if (m_state == playerState::STATE_ATT2)
				{
					m_state = playerState::STATE_ATT3;
					delay = 1.2f;
				}
				else if (m_state == playerState::STATE_ATT1)
				{
					m_state = playerState::STATE_ATT2;
					delay = 1.1f;
				}
				else
				{
					if (m_state == playerState::STATE_ATT5)
					{
						m_state = playerState::STATE_ATT1;
						delay = 1.2f;
					}
					else
					{
						m_state = playerState::STATE_ATT1;
						delay = 1.2f;
					}
				}

				m_fAniSpeed = 1.3f;
				m_fBattleCount = 5.f;
			}
		}
#pragma endregion
#pragma region ManaBladeAttack
		else if (isManaBlade == true)
		{
			if (delay <= 1.f)
			{
				if (m_state == playerState::STATE_MB_ATT5)
				{
					m_state = playerState::STATE_MB_ATT6;
					delay = 1.15f;
				}
				else if (m_state == playerState::STATE_MB_ATT4 && delay <= 0.8)
				{
					m_state = playerState::STATE_MB_ATT5;
					delay = 1.3f;
				}
				else if (m_state == playerState::STATE_MB_ATT3)
				{
					m_state = playerState::STATE_MB_ATT4;
					delay = 1.3f;
				}
				else if (m_state == playerState::STATE_MB_ATT2)
				{
					m_state = playerState::STATE_MB_ATT3;
					delay = 1.3f;
				}
				else if (m_state == playerState::STATE_MB_ATT1)
				{
					m_state = playerState::STATE_MB_ATT2;
					delay = 1.17f;
				}
				else
				{
					if (m_state == playerState::STATE_MB_ATT6 && delay <= 0.8)
					{
						m_state = playerState::STATE_MB_ATT1;
						delay = 1.3f;
					}
					else if (m_state != playerState::STATE_MB_ATT2 &&
						m_state != playerState::STATE_MB_ATT3 &&
						m_state != playerState::STATE_MB_ATT4 &&
						m_state != playerState::STATE_MB_ATT5 &&
						m_state != playerState::STATE_MB_ATT6
						)
					{
						m_state = playerState::STATE_MB_ATT1;
						delay = 1.3f;
					}
				}

				m_fBattleCount = 5.f;
			}
		}
#pragma endregion
	}


	if (Engine::Get_DIKeyState(DIK_2) & 0x80)
	{
		if (delay <= 0.f)
		{
			m_state = playerState::STATE_DOOMSAYER;
			delay = 3.7f;
			m_fBattleCount = 8.8f;
		}
	}
	if (Engine::Get_DIKeyState(DIK_3) & 0x80)
	{
		if (delay <= 0.f)
		{
			m_state = playerState::STATE_RUINBLADE;
			delay = 5.4f;//4.f
			m_fBattleCount = 13.1f;
			m_fAniSpeed = 1.5f;
		}
	}
	if (Engine::Get_DIKeyState(DIK_4) & 0x80)
	{
		if (delay <= 0.f)
		{
			m_state = playerState::STATE_MANA_IMAGE;
			//OK
			delay = 1.f;
			m_fBattleCount = 6.f;

		}
	}
	if (Engine::Get_DIKeyState(DIK_5) & 0x80)
	{
		if (delay <= 0.f)
		{
			m_state = playerState::STATE_LORDOFMANA;

			delay = 14.2f;
			m_fBattleCount = 19.f;
			isSkill = true;
		}
	}
	if (Engine::Get_DIKeyState(DIK_6) & 0x80)
	{
		if (delay <= 0.f)
		{

			m_state = playerState::STATE_DARKKNIGHT_TRANS1;
			//OK
			delay = 8.1f;
			m_fBattleCount = 13.1f;
			isSkill = true;
		}
	}
}

CPlayer* CPlayer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CPlayer*	pInstance = new CPlayer(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CPlayer::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CPlayer::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Scale(0.01f, 0.01f, 0.01f);
	m_pMeshCom->Set_AnimationSet(39);

	m_pNaviMeshCom->Set_NaviIndex(0);

	return S_OK;
}
Client::_int Client::CPlayer::Update_Object(const _float& fTimeDelta)
{

	//SetUp_OnTerrain();
	Key_Input(fTimeDelta);

	Engine::CGameObject::Update_Object(fTimeDelta);	
	_float fCamAngle;
	Engine::CCamera* pCamera = dynamic_cast<Engine::CCamera*>(Engine::Get_GameObject(L"UI", L"DynamicCamera"));
	fCamAngle = D3DXToDegree(pCamera->Get_Angle());
	//vCamPos = pCamera->Get_Eye();

	_vec3 vLook, vUp, vRight, vLeft, vDir, vPos, vScale, vRot, vMyPos;

	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vLook);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	m_pTransformCom->Get_Info(Engine::INFO_UP, &vUp);
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vMyPos);

	m_pMeshCom->Play_Animation(fTimeDelta * m_fAniSpeed * 1.5f);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CPlayer::Render_Object(void)
{
	LPD3DXEFFECT	 pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	_uint	iMaxPass = 0;

	pEffect->Begin(&iMaxPass, 0);	// 현재 쉐이더 파일이 갖고 있는 최대 패스의 개수를 리턴, 사용하는 방식
	pEffect->BeginPass(0);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );
		
	m_pMeshCom->Render_Meshes(pEffect);
	
	pEffect->EndPass();
	pEffect->End();

	m_pNaviMeshCom->Render_NaviMeshes();


	Engine::Safe_Release(pEffect);
}
void Client::CPlayer::SetUp_OnTerrain(void)
{
	_vec3	vPosition;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPosition);

	Engine::CTerrainTex*		pTerrainBufferCom = dynamic_cast<Engine::CTerrainTex*>(Engine::Get_Component(L"Environment", L"Terrain", L"Com_Buffer", Engine::ID_STATIC));
	NULL_CHECK(pTerrainBufferCom);

	_float fHeight = m_pCalculatorCom->Compute_HeightOnTerrain(&vPosition, pTerrainBufferCom->Get_VtxPos(), VTXCNTX, VTXCNTZ, VTXITV);

	m_pTransformCom->Move_Pos(vPosition.x, fHeight, vPosition.z);
}