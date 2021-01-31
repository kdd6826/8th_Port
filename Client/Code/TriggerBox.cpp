#include "stdafx.h"
#include "TriggerBox.h"
#include "Export_Function.h"

CTriggerBox::CTriggerBox(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
{
	isTriggerBox = true;
}

CTriggerBox::~CTriggerBox(void)
{

}



HRESULT Client::CTriggerBox::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;



	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	CMonster::Add_Component();

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_TriggerBox"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	//// Transform
	//pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);
	
	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Gate"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	ColliderObject();
	return S_OK;
}

HRESULT CTriggerBox::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);
	pEffect->SetFloat("g_fAlpha", 0.2f);
	//pEffect->SetVector("g_color", &_vec4(161.f / 255.f, 145.f / 255.f, 215.f / 255.f, 1.f));
	//pEffect->SetVector("g_vGateEffectUV12", &_vec4(161.f / 255.f, 145.f / 255.f, 215.f / 255.f, 1.f));
	//pEffect->SetVector("g_vGateEffectUV34", &_vec4(161.f / 255.f, 145.f / 255.f, 215.f / 255.f, 1.f));

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture");

	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CTriggerBox* CTriggerBox::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CTriggerBox*	pInstance = new CTriggerBox(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CTriggerBox::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CTriggerBox::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//m_pTransformCom->Set_Pos(22, 0.f, 22);
	//m_pTransformCom->Set_Scale(0.4f, 2.f, 1.f);


	//sphereCol->m_pTransformCom->m_vScale = sphereScale;
	//CColliderMgr::GetInstance()->RegisterObject(Engine::COLLID::ENEMY, sphereCol);
	//CColliderMgr::GetInstance()->RegisterObject(_collType2, sphereCol);


	return S_OK;
}
Client::_int Client::CTriggerBox::Update_Object(const _float& fTimeDelta)
{
	CMonster::Update_Object(fTimeDelta);
	if (!initialize)
	{
		m_pTransformCom->Rotation(Engine::ROTATION::ROT_Z, D3DXToRadian(180.f));
		m_pTransformCom->Set_Pos(&spawnPosition);
		initialize = true;
		isColl = true;
	}
	spawnPosition.y = 1.f;
	m_pTransformCom->Set_Pos(&spawnPosition);
	

	//_vec3 vPos;
	//m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	//CGameObject::Compute_ViewZ(&vPos);

	_matrix		matScale, matWorld, matView, matBill;
	D3DXMatrixIdentity(&matScale);
	matScale._11 = 4.f;
	matScale._22 = 2.f;
	matScale._33 = 1.f;

	//D3DXMatrixIdentity(&matBill);
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	//m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	//matBill._11 = matView._11;
	//matBill._13 = matView._13;
	//matBill._31 = matView._31;
	//matBill._33 = matView._33;

	//D3DXMatrixInverse(&matBill, NULL, &matBill);

	//// 행렬의 곱셈순서를 주의할 것
	m_pTransformCom->Set_WorldMatrix(&(matScale*matWorld));

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);


	return 0;
}
void Client::CTriggerBox::Render_Object(void)
{
	CMonster::Render_Object();
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
