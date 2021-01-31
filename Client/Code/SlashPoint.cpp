#include "stdafx.h"
#include "SlashPoint.h"
#include "Export_Function.h"

CSlashPoint::CSlashPoint(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CSlashPoint::~CSlashPoint(void)
{

}



HRESULT Client::CSlashPoint::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_SlashPoint"));
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
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_HitEffect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	
	return S_OK;
}

HRESULT CSlashPoint::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture"/*, _uint(m_fFrame)*/);
	pEffect->SetFloat("g_fAlpha", reverseLifeTime * 2);
	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CSlashPoint* CSlashPoint::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSlashPoint*	pInstance = new CSlashPoint(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CSlashPoint::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CSlashPoint::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);
	
	int i = rand() % 45;
	fScale = 2.f;
	
	m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(45+i));
	//m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(-100.f));
	//m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 5.f;
	//m_pTransformCom->Set_Pos(1.f, 0.f, 1.f);

	return S_OK;
}
Client::_int Client::CSlashPoint::Update_Object(const _float& fTimeDelta)
{
	if (reverseLifeTime < 0.5f)
	{
		reverseLifeTime += fTimeDelta;
	}
	else
	{
		return 1;
	}
	if (fScale > 1.f)
	{
		fScale -= fTimeDelta;
		m_pTransformCom->Set_Scale(fScale, fScale, fScale);
	}
	Engine::CGameObject::Update_Object(fTimeDelta);

	_vec3 vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	CGameObject::Compute_ViewZ(&vPos);

	_matrix		matWorld, matView, matBill;

	D3DXMatrixIdentity(&matBill);
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	matBill._11 = matView._11;
	matBill._13 = matView._13;
	matBill._31 = matView._31;
	matBill._33 = matView._33;

	D3DXMatrixInverse(&matBill, NULL, &matBill);

	// ����� ���������� ������ ��
	m_pTransformCom->Set_WorldMatrix(&(matBill * matWorld));

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return 0;
}
void Client::CSlashPoint::Render_Object(void)
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
