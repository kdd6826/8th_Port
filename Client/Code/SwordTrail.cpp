#include "stdafx.h"
#include "SwordTrail.h"
#include "Export_Function.h"

CSwordTrail::CSwordTrail(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CSwordTrail::~CSwordTrail(void)
{

}



HRESULT Client::CSwordTrail::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	//// buffer
	//pComponent = m_pBufferCom = dynamic_cast<Engine::CTrailBuffer*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RealTrail"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	pComponent = m_pBufferCom = dynamic_cast<Engine::CTestTrail*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_Trail"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	//pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_SwordTrail0"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_Black"));
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

HRESULT CSwordTrail::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture"/*, _uint(m_fFrame)*/);
	pEffect->SetFloat("g_fAlpha", 0.f);
	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CSwordTrail* CSwordTrail::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSwordTrail*	pInstance = new CSwordTrail(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CSwordTrail::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CSwordTrail::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	//m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(-100.f));
	//m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 5.f;
	//m_pTransformCom->Set_Pos(1.f, 0.f, 1.f);

	return S_OK;
}
Client::_int Client::CSwordTrail::Update_Object(const _float& fTimeDelta)
{

	Engine::CGameObject::Update_Object(fTimeDelta);

	//m_pBufferCom->Add_Vertex();
	Engine::CStaticMesh*  m_pSwordMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Get_Component(L"GameLogic", L"Sword", L"Com_Mesh", Engine::ID_STATIC));
	NULL_CHECK_RETURN(m_pSwordMeshCom, 0);

	Engine::CTransform*   m_pSwordTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Sword", L"Com_Transform", Engine::ID_DYNAMIC));

	_matrix SwordWorld;
	m_pSwordTransformCom->Get_WorldMatrix(&SwordWorld);
	SwordWorld._11 = 1.f;
	SwordWorld._12 = 0.f;
	SwordWorld._13 = 0.f;
	SwordWorld._14 = 0.f;

	SwordWorld._21 = 0.f;
	SwordWorld._22 = 1.f;
	SwordWorld._23 = 0.f;
	SwordWorld._24 = 0.f;

	SwordWorld._31 = 0.f;
	SwordWorld._32 = 0.f;
	SwordWorld._33 = 1.f;
	SwordWorld._34 = 0.f;

	//SwordWorld._41 = 1.f;
	//SwordWorld._42 = 0.f;
	//SwordWorld._43 = 0.f;
	//SwordWorld._44 = 0.f;
	_vec3 SwordPos = { SwordWorld._41,SwordWorld._42,SwordWorld._43 };

	_matrix ao;
	m_pTransformCom->Get_WorldMatrix(&ao);
	m_pTransformCom->Set_WorldMatrix(&SwordPos);


	//m_pTransformCom->Set_ParentMatrix(&(*m_pParentBoneMatrix * *m_pParentWorldMatrix));


	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");
#ifdef _DEBUG
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);
#endif
	return 0;
}
void Client::CSwordTrail::Render_Object(void)
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


	//m_pTransformCom->Set_Transform(m_pGraphicDev);

	//LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	//NULL_CHECK(pEffect);
	//Engine::Safe_AddRef(pEffect);

	//FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	//pEffect->Begin(NULL, 0);
	//pEffect->BeginPass(1);

	//m_pBufferCom->Render_Buffer();

	//pEffect->EndPass();
	//pEffect->End();

	//Engine::Safe_Release(pEffect);
}
