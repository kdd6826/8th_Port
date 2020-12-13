#include "stdafx.h"
#include "Player.h"
#include "Export_Function.h"
#include "DynamicCamera.h"
CPlayer::CPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
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

	// Collider 
	//pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);

	return S_OK;
}

void Client::CPlayer::Key_Input(const _float& fTimeDelta)
{
	if (delay > 0)
	{
		delay -= fTimeDelta;
	}
	if (delay <=0)
	{
		m_fAniSpeed = 1.f;
		m_state = playerState::STATE_IDLE;
		if (Engine::Get_DIKeyState(DIK_LSHIFT) & 0x80)
		{
			if (isRunning = true)
			{
				isRunning = false;
			}
			else if (isRunning = false)
			{
				isRunning = true;
			}
		}

		MovePlayer(fTimeDelta);

		if (Engine::Get_DIKeyState(DIK_TAB) & 0x80)
		{

			if (isManaBlade == true)
			{
				isManaBlade = false;
				m_state = STATE_NORMAlBLADE;
				delay += 0.8f;
				
			}
			else if (isManaBlade == false)
			{
					isManaBlade = true;
				m_state = STATE_MANABLADE;
				delay += 2.f;
				m_fAniSpeed = 1.1f;
			}
		}
	}
	

	if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	{
#pragma region NormalBladeAttack
		if (isManaBlade == false)
		{
			if (delay <= 0.3f)
			{
				if (m_state == playerState::STATE_ATT4)
				{
					m_state = playerState::STATE_ATT5;
				}
				else if (m_state == playerState::STATE_ATT3)
				{
					m_state = playerState::STATE_ATT4;
				}
				else if (m_state == playerState::STATE_ATT2)
				{
					m_state = playerState::STATE_ATT3;
				}
				else if (m_state == playerState::STATE_ATT1)
				{
					m_state = playerState::STATE_ATT2;
				}
				else
				{
					m_state = playerState::STATE_ATT1;
				}
				delay += 0.5f;
			}
		}
#pragma endregion
#pragma region ManaBladeAttack
		else if (isManaBlade == true)
		{
			if (delay <= 0.3f)
			{
				if (m_state == playerState::STATE_MB_ATT5)
				{
					m_state = playerState::STATE_MB_ATT6;
				}
				else if (m_state == playerState::STATE_MB_ATT4)
				{
					m_state = playerState::STATE_MB_ATT5;
				}
				else if (m_state == playerState::STATE_MB_ATT3)
				{
					m_state = playerState::STATE_MB_ATT4;
				}
				else if (m_state == playerState::STATE_MB_ATT2)
				{
					m_state = playerState::STATE_MB_ATT3;
				}
				else if (m_state == playerState::STATE_MB_ATT1)
				{
					m_state = playerState::STATE_MB_ATT2;
				}
				else
				{
					m_state = playerState::STATE_MB_ATT1;
				}
				delay += 0.4f;
				
			}
		}
#pragma endregion
	}
	

	m_pMeshCom->Set_AnimationSet(m_state);
	/*if(true == m_pMeshCom->Is_AnimationSetEnd())
		m_pMeshCom->Set_AnimationSet(39);*/


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

	Engine::CCamera* pCamera = dynamic_cast<Engine::CCamera*>(Engine::Get_GameObject(L"Environment", L"DynamicCamera"));
	vCamPos = pCamera->Get_Eye();
	fCamAngle = pCamera->Get_Angle();


	if (Engine::Get_DIKeyState(DIK_W) & 0x80)
	{
		if (isRunning)
		{
			m_state == playerState::STATE_FIELD_SPRINT;
			m_fSpeed = 5.f;
		}
		else if (!isRunning)
		{
			m_state = playerState::STATE_FIELD_RUN;
			m_fSpeed = 3.f;
		}
		vDir = (vMyPos - vCamPos);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle);

		if (Engine::Get_DIKeyState(DIK_A) & 0x80)
		{
			vDir = (vCamPos - vMyPos);
			_vec3 up;
			up = { 0.f,1.f,0.f };
			D3DXVec3Cross(&vDir, &up, &vDir);
			D3DXVec3Normalize(&vDir, &vDir);

			m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-45));
		}
		else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
		{

			vDir = (vCamPos - vMyPos);
			_vec3 up;
			up = { 0.f,1.f,0.f };
			D3DXVec3Cross(&vDir, &vDir, &up);
			D3DXVec3Normalize(&vDir, &vDir);

			m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(45));
		}

		//m_pTransformCom->Set_Pos(&m_pNaviMeshCom->Move_OnNaviMesh(&vPos, &(vDir * fTimeDelta * m_fSpeed)));
	}

	else if (Engine::Get_DIKeyState(DIK_S) & 0x80)
	{
		m_state = playerState::STATE_FIELD_RUN;
		vDir = (vCamPos - vMyPos);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(180));
		if (Engine::Get_DIKeyState(DIK_A) & 0x80)
		{
			vDir = (vCamPos - vMyPos);
			_vec3 up;
			up = { 0.f,1.f,0.f };
			D3DXVec3Cross(&vDir, &up, &vDir);
			D3DXVec3Normalize(&vDir, &vDir);

			m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-135));
		}
		else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
		{

			vDir = (vCamPos - vMyPos);
			_vec3 up;
			up = { 0.f,1.f,0.f };
			D3DXVec3Cross(&vDir, &vDir, &up);
			D3DXVec3Normalize(&vDir, &vDir);

			m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

			m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(135));
		}
	}

	else if (Engine::Get_DIKeyState(DIK_A) & 0x80)
	{
		m_state = playerState::STATE_FIELD_RUN;
		vDir = (vCamPos - vMyPos);
		_vec3 up;
		up = { 0.f,1.f,0.f };
		D3DXVec3Cross(&vDir, &up, &vDir);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(-90));
	}
	else if (Engine::Get_DIKeyState(DIK_D) & 0x80)
	{
		m_state = playerState::STATE_FIELD_RUN;
		vDir = (vCamPos - vMyPos);
		_vec3 up;
		up = { 0.f,1.f,0.f };
		D3DXVec3Cross(&vDir, &vDir, &up);
		D3DXVec3Normalize(&vDir, &vDir);

		m_pTransformCom->Move_Pos(&(vDir * m_fSpeed * fTimeDelta));

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, fCamAngle + D3DXToRadian(90));
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
	m_pTransformCom->Set_Pos(&_vec3{ 5.f,5.f,5.f });

	return S_OK;
}
Client::_int Client::CPlayer::Update_Object(const _float& fTimeDelta)
{

	SetUp_OnTerrain();
	Key_Input(fTimeDelta);

	Engine::CGameObject::Update_Object(fTimeDelta);
	_float fCamAngle;
	Engine::CCamera* pCamera = dynamic_cast<Engine::CCamera*>(Engine::Get_GameObject(L"Environment", L"DynamicCamera"));
	fCamAngle = D3DXToDegree(pCamera->Get_Angle());
	//vCamPos = pCamera->Get_Eye();

	_vec3 vLook, vUp, vRight, vLeft, vDir, vPos, vScale,vRot, vMyPos;
	
	m_pTransformCom->Get_Info(Engine::INFO_LOOK, &vLook);
	m_pTransformCom->Get_Info(Engine::INFO_RIGHT, &vRight);
	m_pTransformCom->Get_Info(Engine::INFO_UP, &vUp);
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vMyPos);


	//_matrix ani, rot;

	//vRot = m_pTransformCom->Get_Rotation();

	//D3DXMatrixRotationY(&rot, vRot.y);




	m_pMeshCom->Play_Animation(fTimeDelta*m_fAniSpeed*1.5f);

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CPlayer::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);
	
	m_pNaviMeshCom->Render_NaviMeshes();

	m_pMeshCom->Render_Meshes();
	/*_matrix matWorld;
	m_pTransformCom->Get_WorldMatrix(&matWorld);

	m_pColliderCom->Render_Collider(Engine::COL_TRUE, &matWorld);*/
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