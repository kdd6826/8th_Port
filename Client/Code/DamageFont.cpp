#include "stdafx.h"
#include "DamageFont.h"
#include "Export_Function.h"
#include "FontParent.h"
CDamageFont::CDamageFont(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CDamageFont::~CDamageFont(void)
{

}



HRESULT Client::CDamageFont::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;
	fScale = 2.f;
	count = 1.f;

	// buffer
	pComponent = m_pBufferCom = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// texture
	pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_DamageFont"));
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

	//// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_DamageFont"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	//int i = rand() % 10;
	//offsetX = -0.5f + 0.1 * i;

	// Shader
	/*pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Effect"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);*/
	return S_OK;
}

HRESULT CDamageFont::SetUp_ConstantTable(LPD3DXEFFECT & pEffect)
{
	_matrix		matWorld, matView, matProj,matParentWorld;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	

	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	pEffect->SetMatrix("g_matWorld", &matWorld);
	//
	D3DXMatrixInverse(&matWorld, NULL, &matWorld);
	pEffect->SetMatrix("g_matInv", &matWorld);


	int		iCnt=1;
	int		iMaxCnt=1;
	float	fTexCX=512.f;
	float	fTexCY=256.f;
	float	fDrawX;
	if (count != 9)
	{
		fDrawX = 40.f * count - 5.f;
	}
	else
		fDrawX = 40.f * count;
	float	fDrawY=0.f;
	float	fDrawCX=24.f;
	float	fDrawCY=24.f;


	pEffect->SetInt("iCnt", iCnt);
	pEffect->SetInt("iMaxCnt", iMaxCnt);
	pEffect->SetFloat("fAlpha", fAlpha);
	pEffect->SetFloat("fTexCX", fTexCX);
	pEffect->SetFloat("fTexCY", fTexCY);
	pEffect->SetFloat("fDrawX", fDrawX);
	pEffect->SetFloat("fDrawY", fDrawY);
	pEffect->SetFloat("fDrawCX", fDrawCX);
	pEffect->SetFloat("fDrawCY", fDrawCY);

	//m_pTransformCom->Set_Scale(0.3f, 0.3f, 0.3f);
	//
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	//m_pTransformCom->Set_Scale(fScale, fScale, fScale);
	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture"/*, _uint(m_fFrame)*/);
	//pEffect->SetFloat("g_fAlpha", 0);
	Engine::Throw_RenderTargetTexture(pEffect, L"Target_Depth", "g_DepthTexture");
	//Matrix		g_matInv;

	//int		iCnt;
	//int		iMaxCnt;
	//float	fTexCX;
	//float	fTexCY;
	//float	fDrawX;
	//float	fDrawY;
	//float	fDrawCX;
	//float	fDrawCY;
	//float	fAlpha;

	return S_OK;
}

CDamageFont* CDamageFont::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CDamageFont*	pInstance = new CDamageFont(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CDamageFont::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CDamageFont::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//m_pTransformCom->Set_Pos(&_vec3{ 23.f,2.f,23.f });

	return S_OK;
}
Client::_int Client::CDamageFont::Update_Object(const _float& fTimeDelta)
{
	//if (reverseLifeTime < 3.f)
	//{
	//	reverseLifeTime += fTimeDelta;
	//}
	//else
	//{
	//	return 1;
	//}
	if (fScale > 0.2f)
	{
		fScale -= fTimeDelta*15.f;
	}
	else
		fScale = 0.2f;
	if (fScale == 0.2f)
	{
		if (fAlpha > 0.f)
		{
			fAlpha -= fTimeDelta;
		}
		else
		{
			fAlpha = 0.f;

		}

		if (fAlpha < 0.9f)
		{
			m_pTransformCom->m_vInfo[Engine::INFO_POS].y += fTimeDelta;
		}
	}
	//count = 2.f;
	//if (Engine::Get_DIKeyState(DIK_SPACE) & 0x80)
	//{
	//	if (fScale < 2.f)
	//		fScale += 0.1f;
	//	else
	//		fScale = 0.f;
	//}

		//m_pTransformCom->Set_Scale(fScale, fScale, fScale);
	
	Engine::CGameObject::Update_Object(fTimeDelta);

	_vec3 vPos;
	m_pTransformCom->Get_Info(Engine::INFO_POS, &vPos);
	//CGameObject::Compute_ViewZ(&vPos);



	_matrix		matLocal,matWorld, matView, matBill, matScale, matParentWorld;

	if (nullptr != m_pFontParent)
	{
		D3DXMatrixIdentity(&matLocal);


		matLocal._41 = offsetX;
		dynamic_cast<CFontParent*>(m_pFontParent)->GetTransform()->Get_WorldMatrix(&matParentWorld);
		//matWorld = matParentWorld * matWorld;
	}

	D3DXMatrixIdentity(&matBill);
	D3DXMatrixIdentity(&matScale);
	/*D3DXMatrixScaling*/
	matScale._11 = fScale;
	matScale._22 = fScale;
	matScale._33 = fScale;
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);

	matBill._11 = matView._11;
	matBill._13 = matView._13;
	matBill._31 = matView._31;
	matBill._33 = matView._33;

	D3DXMatrixInverse(&matBill, NULL, &matBill);

	// 행렬의 곱셈순서를 주의할 것
	m_pTransformCom->Set_WorldMatrix(&(matScale* matLocal * matBill *matParentWorld));
	_matrix a = *m_pTransformCom->Get_WorldMatrix();
	m_pRendererCom->Add_RenderGroup(Engine::RENDER_ALPHA, this);

	return 0;
}
void Client::CDamageFont::Render_Object(void)
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
