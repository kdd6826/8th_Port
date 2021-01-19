#include "stdafx.h"
#include "CollisionEffect.h"
#include "Export_Function.h"

CCollisionEffect::CCollisionEffect(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CCollisionEffect::~CCollisionEffect(void)
{

}



HRESULT Client::CCollisionEffect::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_CollisionEffect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

HRESULT CCollisionEffect::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture"/*, _uint(m_fFrame)*/);

	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CCollisionEffect* CCollisionEffect::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CCollisionEffect*	pInstance = new CCollisionEffect(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CCollisionEffect::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CCollisionEffect::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	m_pTransformCom->Set_Scale(0.7, 0.7, 0.7);
	//m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(-100.f));
//	m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 5.f;
	//m_pTransformCom->Set_Pos(1.f, 0.f, 1.f);

	return S_OK;
}
Client::_int Client::CCollisionEffect::Update_Object(const _float& fTimeDelta)
{
	m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(0.5f));
	//m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(2.f));
	m_pTransformCom->Set_Scale(0.4, 0.4, 0.4);
	_vec3 playerPos, playerLook, playerDir, playerLook2;
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
	playerDir = playerLook * 24.f;
	////}

	m_pTransformCom->Set_Rotation(Engine::ROT_Y, radian /*+ D3DX_PI * 0.5f*/);

	Engine::CGameObject::Update_Object(fTimeDelta);

	m_pTransformCom->m_vInfo[Engine::INFO_LOOK] = playerLook;
	m_pTransformCom->Set_Pos(&(playerPos + playerDir + _vec3{ 0.f,0.5f,0.f }));
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return 0;
}
void Client::CCollisionEffect::Render_Object(void)
{

	float fTimeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerStateCom, );
	if (pPlayerStateCom->playerState != Engine::CPlayerState::STATE_CollisionEffect)
	{
		count = 0;
		return;
	}
	else
	{
		count += fTimeDelta;
	}
	if (count > 0.7f)
		return;
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