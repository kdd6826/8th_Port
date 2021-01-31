#include "stdafx.h"
#include "DashGuard2.h"
#include "Export_Function.h"

CDashGuard2::CDashGuard2(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
{

}

CDashGuard2::~CDashGuard2(void)
{

}



HRESULT Client::CDashGuard2::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;



	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	CMonster::Add_Component();

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_ConfusionHole2"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	ColliderSkill();
	return S_OK;
}

HRESULT CDashGuard2::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);
	pEffect->SetFloat("g_fAlpha", m_fAlpha);
	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture", _uint(m_fFrame));

	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CDashGuard2* CDashGuard2::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CDashGuard2*	pInstance = new CDashGuard2(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CDashGuard2::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CDashGuard2::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_fScale = 0.f;
	lifeTime = 0.7f;
	m_pTransformCom->Set_Scale(m_fScale, m_fScale, m_fScale);
	//m_pTransformCom->Set_Pos(20, 0.5f, 22);

	return S_OK;
}
Client::_int Client::CDashGuard2::Update_Object(const _float& fTimeDelta)
{
	CMonster::Update_Object(fTimeDelta);
	if (lifeTime <= 0.f)
		return 1;
	lifeTime -= fTimeDelta;
	m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(-0.5f));

	Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
	//°¡µå
	if (!isDash)
	{


		if (pPlayerStateCom->perfectGuard == false)
		{
			if (m_guardDir == DIR_DEFAULT)
			{
				m_pTransformCom->Set_Scale(m_fScale, m_fScale, m_fScale);

				if (m_fScale < 0.4f)
				{
					m_fScale += fTimeDelta*2.f;
				}
				else if (m_fScale >= 0.4f)
				{
					m_fScale = 0.4f;
				}
				if (m_fScale >= 0.35)
				{
					m_fAlpha += fTimeDelta*3.f;
				}

				_vec3 playerPos, playerLook, playerRight, playerRight2, playerDir, playerLook2;
				Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
				NULL_CHECK_RETURN(pPlayerTransCom, 0);
				pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
				pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
				pPlayerTransCom->Get_Info(Engine::INFO_RIGHT, &playerRight);
				pPlayerTransCom->Get_Info(Engine::INFO_RIGHT, &playerRight2);
				pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook2);
				D3DXVec3Normalize(&playerLook2, &playerLook2);
				D3DXVec3Normalize(&playerRight2, &playerRight2);


				playerDir = playerLook * 48.f;
				float radian = atan2f(playerLook2.x, playerLook2.z);
				m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian);

				m_pTransformCom->Set_Pos(&(playerPos + playerDir + _vec3{ 0.f,0.5f,0.f }));
			}
		}
		else if (pPlayerStateCom->perfectGuard == true)
		{
			m_pTransformCom->Set_Scale(0.7f, 0.7f, 0.7f);
			if (lifeTime < 0.5f)
			{
				m_fAlpha += fTimeDelta*2.f;
			}
			if (m_guardDir == DIR_DEFAULT)
			{
				return 1;
			}
			_vec3 playerPos, playerLook, playerRight, playerRight2, playerDir, playerLook2;
			Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
			NULL_CHECK_RETURN(pPlayerTransCom, 0);
			pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
			pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
			pPlayerTransCom->Get_Info(Engine::INFO_RIGHT, &playerRight);
			pPlayerTransCom->Get_Info(Engine::INFO_RIGHT, &playerRight2);
			pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook2);
			D3DXVec3Normalize(&playerLook2, &playerLook2);
			D3DXVec3Normalize(&playerRight2, &playerRight2);
			if (m_guardDir == DIR_FRONT)
			{

				playerDir = playerLook * 24.f;
				float radian = atan2f(playerLook2.x, playerLook2.z);
				m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian);
			}
			else if (m_guardDir == DIR_LEFT)
			{
				playerDir = playerRight * 48.f;
				float radian = atan2f(playerRight2.x, playerRight2.z);
				m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian /*+ D3DX_PI * 0.5f*/);

			}
			else if (m_guardDir == DIR_RIGHT)
			{
				playerDir = -playerRight * 48.f;
				float radian = atan2f(-playerRight2.x, playerRight2.z);
				m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian /*+ D3DX_PI * 0.5f*/);

			}
			m_pTransformCom->Set_Pos(&(playerPos + playerDir + _vec3{ 0.f,0.5f,0.f }));
		}
	}
	else if (isDash)
	{
		m_pTransformCom->Set_Scale(0.2f, 0.2f, 0.2f);
		if (lifeTime < 0.5f)
		{
			m_fAlpha += fTimeDelta*2.f;
		}
		_vec3 playerPos, playerLook, playerDir, playerLook2, myPos;
		m_pTransformCom->Get_Info(Engine::INFO_POS, &myPos);
		float playerAngle;
		_vec3 worldX = { 1.f,0.f,0.f };
		Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		NULL_CHECK_RETURN(pPlayerTransCom, 0);
		//m_pParentWorldMatrix = pPlayerTransCom->Get_WorldMatrix();
		pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
		pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
		pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook2);
		D3DXVec3Normalize(&playerLook2, &playerLook2);


		float radian = atan2f(playerLook2.x, playerLook2.z);
		playerDir = -playerLook * 24.f;
		////}

		m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian /*+ D3DX_PI * 0.5f*/);

		//	Engine::CGameObject::Update_Object(fTimeDelta);

		m_pTransformCom->m_vInfo[Engine::INFO_LOOK] = playerLook;
		if (lifeTime >= 0.65f)
		{
			m_pTransformCom->Set_Pos(&(playerPos + playerDir + _vec3{ 0.f,0.5f,0.f }));
		}
		else
		{
			m_pTransformCom->Move_Pos(&(playerDir * fTimeDelta));
		}
	}



	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);
	return 0;


}
void Client::CDashGuard2::Render_Object(void)
{
	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(NULL, 0);
	pEffect->BeginPass(1);

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();
	pEffect->End();

	Engine::Safe_Release(pEffect);
}
