#include "stdafx.h"
#include "Sword.h"
#include "Export_Function.h"
#include "DynamicCamera.h"
CSword::CSword(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CSword::~CSword(void)
{

}

HRESULT Client::CSword::Add_Component(void)
{
	Engine::CComponent*		pComponent = nullptr;
	
	// Mesh
	pComponent = m_pMeshCom = dynamic_cast<Engine::CStaticMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Sword2"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Mesh", pComponent);




	//// buffer
	//pComponent = m_pBufferCom2 = dynamic_cast<Engine::CRcTex*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_RcTex"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	//// texture
	//pComponent = m_pTextureCom = dynamic_cast<Engine::CTexture*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Texture_Player"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Texture", pComponent);

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
	pComponent = m_pColliderCom = Engine::CCollider::Create(m_pGraphicDev, m_pMeshCom->Get_VtxPos(), m_pMeshCom->Get_NumVtx(), m_pMeshCom->Get_Stride());
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Collider", pComponent);
	
	//// Shader
	//pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	// Shader
	pComponent = m_pShaderCom = dynamic_cast<Engine::CShader*>(Engine::Clone(L"Proto_Shader_Mesh"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Shader", pComponent);
	return S_OK;
}


CSword* CSword::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSword*	pInstance = new CSword(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CSword::Free(void)
{
	Engine::CGameObject::Free();
}


HRESULT Client::CSword::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	m_pTransformCom->Rotation(Engine::ROT_X, D3DXToRadian(-100.f));
	m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 5.f;
	//m_pTransformCom->Rotation(Engine::ROT_Z, D3DXToRadian(-45.f));
	return S_OK;
}
Client::_int Client::CSword::Update_Object(const _float& fTimeDelta)
{
	m_pTransformCom->Set_Scale(1.f, 1.f, 1.f);
	_vec3 a = *m_pColliderCom->Get_Min();
	if (nullptr == m_pParentBoneMatrix)
	{

		Engine::CDynamicMesh*	pPlayerMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Mesh", Engine::ID_STATIC));
		NULL_CHECK_RETURN(pPlayerMeshCom, 0);

		const Engine::D3DXFRAME_DERIVED* pFrame = pPlayerMeshCom->Get_FrameByName("ValveBiped_Bip01_R_Finger22"); //X -100
		//const Engine::D3DXFRAME_DERIVED* pFrame = pPlayerMeshCom->Get_FrameByName("ValveBiped_Bip01_R_Hand"); //X -100
		m_pParentBoneMatrix = &pFrame->CombinedTransformationMatrix;
		

		Engine::CTransform*		pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
		NULL_CHECK_RETURN(pPlayerTransCom, 0);
		m_pParentWorldMatrix = pPlayerTransCom->Get_WorldMatrix();
	}

	Engine::CGameObject::Update_Object(fTimeDelta);
		
	m_pTransformCom->Set_ParentMatrix(&(*m_pParentBoneMatrix * *m_pParentWorldMatrix));
	

	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");

	m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);

	return 0;
}
void Client::CSword::Render_Object(void)
{
	//m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//_matrix matWorld2;
	//D3DXMatrixIdentity(&matWorld2);
	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &matWorld2);
	//for (auto& pTex : m_vecTrailTex)
	//{
	//	if (pTex)
	//		pTex->Render_Buffer();
	//}

	//m_pTransformCom->Set_Transform(m_pGraphicDev);

	//m_pMeshCom->Render_Meshes();

	//_matrix matWorld;
	//m_pTransformCom->Get_WorldMatrix(&matWorld);


	//m_pColliderCom->Render_Collider(Engine::COLLTYPE(m_bColl), &matWorld);

	/////////////////////////////////////////////////////////////////////////////////////////////쉐이더
	//m_pTransformCom->Set_Transform(m_pGraphicDev);
	//m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	////m_pBufferCom2->Render_Buffer();
	////m_pTextureCom->Render_Texture(0);
	//m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	////
	Engine::CPlayerState* pPlayerStateCom = dynamic_cast<Engine::CPlayerState*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_PlayerState", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pPlayerStateCom, );
	if (pPlayerStateCom->playerMeshState != Engine::CPlayerState::MESH_NORMAL)
	{
		return;
	}
	//_matrix matWorld;
	//	m_pTransformCom->Get_WorldMatrix(&matWorld);
		//m_pTransformCom->Get_NRotWorldMatrix(&matWorld);

//	m_pColliderCom->Render_ColliderSphere(Engine::COLLTYPE(m_bColl), &matWorld);
	LPD3DXEFFECT	 pEffect = m_pShaderCom->Get_EffectHandle();
	NULL_CHECK(pEffect);
	Engine::Safe_AddRef(pEffect);

	_uint	iMaxPass = 0;

	pEffect->Begin(&iMaxPass, 0);	// 현재 쉐이더 파일이 갖고 있는 최대 패스의 개수를 리턴, 사용하는 방식
	pEffect->BeginPass(0);

	FAILED_CHECK_RETURN(SetUp_ConstantTable(pEffect), );

	m_pMeshCom->Render_Meshes(pEffect);

	pEffect->EndPass();
	pEffect->End();

	Engine::Safe_Release(pEffect);
}

HRESULT CSword::SetUp_ConstantTable(LPD3DXEFFECT& pEffect)
{
	/*_matrix		matWorld, matView, matProj;

	const D3DLIGHT9* pLightInfo = Engine::Get_Light(0);

	pEffect->SetVector("g_vLightDir", &_vec4(pLightInfo->Direction, 0.f));

	m_pTextureCom->Set_Texture(pEffect, "g_BaseTexture");
	m_pTextureCom2->Set_Texture(pEffect, "g_NormalTexture");
	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	*/
	
	/*
	pEffect->SetVector("g_vCamPos", &_vec4(pCamera->Get_Eye(), 0.f));
	pEffect->SetVector("g_vColorR", &_vec4(1.f,1.f,1.f,1.f));
	pEffect->SetVector("g_vColorG", &_vec4(1.f,1.f,1.f,1.f));
	pEffect->SetVector("g_vColorB", &_vec4(1.f,1.f,1.f,1.f));
		
	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;*/
	_matrix		matWorld, matView, matProj;

	m_pTransformCom->Get_WorldMatrix(&matWorld);
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);

	pEffect->SetMatrix("g_matWorld", &matWorld);
	pEffect->SetMatrix("g_matView", &matView);
	pEffect->SetMatrix("g_matProj", &matProj);

	return S_OK;
}


_bool CSword::Collision_ToObject(const _tchar * pLayerTag, const _tchar * pObjTag)
{
	Engine::CCollider*	pPlayerColliderCom = dynamic_cast<Engine::CCollider*>(Engine::Get_Component(pLayerTag, pObjTag, L"Com_Collider", Engine::ID_STATIC));
	NULL_CHECK_RETURN(pPlayerColliderCom, false);
	

	/*return m_pCalculatorCom->Collision_AABB(pPlayerColliderCom->Get_Min(),
											pPlayerColliderCom->Get_Max(),
											pPlayerColliderCom->Get_CollMatrix(),
											m_pColliderCom->Get_Min(), 
											m_pColliderCom->Get_Max(),
											m_pColliderCom->Get_CollMatrix());*/

	return true;/* m_pCalculatorCom->Collision_OBB(pPlayerColliderCom->Get_Min(),
		pPlayerColliderCom->Get_Max(),
		pPlayerColliderCom->Get_CollMatrix(),
		m_pColliderCom->Get_Min(),
		m_pColliderCom->Get_Max(),
		m_pColliderCom->Get_CollMatrix());*/
}
