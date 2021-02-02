#include "stdafx.h"
#include "FadeInOut.h"
#include "Export_Function.h"
#include "TriggerBox.h"
CFadeInOut::CFadeInOut(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CFadeInOut::~CFadeInOut(void)
{

}


HRESULT Client::CFadeInOut::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_FadeInOut"));
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
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_FadeInOut"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);

	return S_OK;
}

HRESULT CFadeInOut::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	_vec3 vPos = { m_fX, m_fY, 0.f };
	_matrix matWorld, matView;

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matView);

	_matrix matScale, matRotZ, matTrans;
	D3DXMatrixScaling(&matScale, m_fSizeX, m_fSizeY, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(0));

	D3DXMatrixTranslation(&matTrans, vPos.x - WINCX * 0.5f, -vPos.y + WINCY * 0.5f, 0.f);

	matWorld = matScale * matRotZ * matTrans;
	pEffect->SetFloat("g_fAlpha", m_fAlpha);
	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &m_matProj);
	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture");

	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");

	return S_OK;
}

CFadeInOut* CFadeInOut::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CFadeInOut*	pInstance = new CFadeInOut(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CFadeInOut::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CFadeInOut::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_fX = WINCX/2;
	
	m_fY = WINCY/2;
	m_fSizeY = WINCY;
	
	m_fSizeX = WINCX;
	

	return S_OK;
}
Client::_int Client::CFadeInOut::Update_Object(const _float& fTimeDelta)
{
	if (!isFadeIn)
	{
		if (m_fAlpha < 1.f)
			m_fAlpha += fTimeDelta*0.5f;
	}
	else if (isFadeIn)
	{
		if (m_fAlpha > 0.f)
			m_fAlpha -= fTimeDelta*0.5f;
		else
			isEvent = true;
	}
	CTriggerBox* Portal = dynamic_cast<CTriggerBox*>(Engine::Get_GameObject(L"GameLogic", L"TriggerBox"));
	if (Portal != nullptr)
	{
		if (Portal->GetPortal())
		{
			isFadeIn = true;
		}
	}
	Engine::CGameObject::Update_Object(fTimeDelta);


	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	//D3DXMatrixOrthoLH(&m_matProj, WINCX, WINCY, 0.f, 1.f);

	return 0;
}
void Client::CFadeInOut::Render_Object(void)
{
	D3DXMatrixOrthoLH(&m_matProj, WINCX, WINCY, 0.f, 1.f);
	LPD3DXEFFECT    pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	pEffect->Begin(NULL, 0);
	pEffect->BeginPass(1);
	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	pEffect->CommitChanges();

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();
	pEffect->End();

	Engine::Safe_Release(pEffect);
}
