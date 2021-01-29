#include "stdafx.h"
#include "LightRay.h"
#include "Export_Function.h"

CLightRay::CLightRay(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMonster(pGraphicDev)
{

}

CLightRay::~CLightRay(void)
{

}



HRESULT Client::CLightRay::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;



	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	CMonster::Add_Component();

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_LightRay"));
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
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	ColliderSkill();
	return S_OK;
}

HRESULT CLightRay::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture", _uint(m_fFrame));

	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CLightRay* CLightRay::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLightRay*	pInstance = new CLightRay(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CLightRay::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CLightRay::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Set_Pos(20, 0.5f, 22);
	//m_pTransformCom->Set_Scale(0.4f, 2.f, 1.f);


	//sphereCol->m_pTransformCom->m_vScale = sphereScale;
	//CColliderMgr::GetInstance()->RegisterObject(Engine::COLLID::ENEMY, sphereCol);
	//CColliderMgr::GetInstance()->RegisterObject(_collType2, sphereCol);


	return S_OK;
}
Client::_int Client::CLightRay::Update_Object(const _float& fTimeDelta)
{
	CMonster::Update_Object(fTimeDelta);

	lifeTime += fTimeDelta;
	if (lifeTime > 3.f)
		return 1;
	m_pTransformCom->Move_Pos(&(m_vDir*10.f));
	m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(10.f));
	m_pTransformCom->Rotation(Engine::ROT_Y, D3DXToRadian(-10.f));
	m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(10.f));

	isColl = true;

	//m_fFrame += 50.f * fTimeDelta;
	//if (50.f < m_fFrame)
	//	m_fFrame = 0.f;


	_vec3 vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	CGameObject::Compute_ViewZ(&vPos);

	_matrix		matScale, matWorld, matView, matBill;
	D3DXMatrixIdentity(&matScale);
	matScale._11 = 0.5f;
	matScale._22 = 0.5f;
	matScale._33 = 0.5f;

	D3DXMatrixIdentity(&matBill);
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	matBill._11 = matView._11;
	matBill._13 = matView._13;
	matBill._31 = matView._31;
	matBill._33 = matView._33;

	D3DXMatrixInverse(&matBill, NULL, &matBill);

	// ����� ���������� ������ ��
	m_pTransformCom->Set_WorldMatrix(&(matScale*matBill * matWorld));

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);


	return 0;
}
void Client::CLightRay::Render_Object(void)
{
	LPD3DXEFFECT	pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->Begin(NULL, 0);
	pEffect->BeginPass(0);

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();
	pEffect->End();

	Engine::Safe_Release(pEffect);
}