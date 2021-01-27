#include "stdafx.h"
#include "DarkSwordTrail.h"
#include "Export_Function.h"

CDarkSwordTrail::CDarkSwordTrail(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CDarkSwordTrail::~CDarkSwordTrail(void)
{
	//for (auto& iterator = m_pTrailList.begin(); iterator != m_pTrailList.end(); ++iterator)
	//{
	//	//Engine::Safe_Delete_Array(*iterator);
	//	Engine::Safe_Release(*iterator);
	//}
}



HRESULT Client::CDarkSwordTrail::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;
	
	pComponent = m_pBufferCom = dynamic_cast<Engine::CTestTrail*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_Trail"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_SwordTrail3"));
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
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Trail"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

HRESULT CDarkSwordTrail::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
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

CDarkSwordTrail* CDarkSwordTrail::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CDarkSwordTrail*	pInstance = new CDarkSwordTrail(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CDarkSwordTrail::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CDarkSwordTrail::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}
Client::_int Client::CDarkSwordTrail::Update_Object(const _float& fTimeDelta)
{

	Engine::CGameObject::Update_Object(fTimeDelta);

	//m_pBufferCom->Add_Vertex();
	Engine::CStaticMesh*  m_pSwordMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Get_Component(L"GameLogic", L"Sword", L"Com_Mesh", Engine::ID_STATIC));
	NULL_CHECK_RETURN(m_pSwordMeshCom, 0);

	Engine::CTransform*   m_pSwordTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Sword", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(m_pSwordTransformCom, 0);
	//
	_matrix SwordWorld,matScale;
	D3DXMatrixIdentity(&matScale);
	matScale._11 = 100.f;
	matScale._22 = 100.f;
	matScale._33 = 100.f;
	//65~15
	matScale._43 = -65.f;

	m_pSwordTransformCom->Get_WorldMatrix(&SwordWorld);
	_matrix topSword = matScale* SwordWorld;
	const _vec3	topPos = { topSword._41,topSword._42,topSword._43 };
	matScale._43 = -15.f;
	_matrix bottomSword = matScale * SwordWorld;
	const _vec3	bottomPos = { bottomSword._41,bottomSword._42,bottomSword._43 };
	_vec3 SwordPos = { SwordWorld._41,SwordWorld._42,SwordWorld._43 };
	m_pVecpair = { topPos,bottomPos };
	m_pBufferCom->Update_Buffer(&m_pVecpair,fTimeDelta);
	count += fTimeDelta;
			
#ifdef _DEBUG
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);
#endif
	return 0;
}
void Client::CDarkSwordTrail::Render_Object(void)
{
	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(NULL, 0);
	pEffect->BeginPass(1);
	Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerStateCom, );
	if (pPlayerStateCom->isAttack==true&&pPlayerStateCom->playerMeshState==Engine::CPlayerState::MESH_DKKNIGHT2)
	{
		m_pBufferCom->Render_Buffer();
	}
	pEffect->EndPass();
	pEffect->End();

	Engine::Safe_Release(pEffect);


}
