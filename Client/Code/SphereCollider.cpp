#include "stdafx.h"
#include "SphereCollider.h"
#include "Export_Function.h"
#include "ColliderMgr.h"
CSphereCollider::CSphereCollider(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{
}

CSphereCollider::~CSphereCollider(void)
{
	//Engine::Safe_Release(m_pGraphicDev);
	CColliderMgr::GetInstance()->DisregisterObject(this);
	
}

HRESULT CSphereCollider::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;

	//// buffer
	//pComponent = m_pBufferCom = dynamic_cast<Engine::CCollSphere*>(Engine::Clone(Engine::RESOURCE_STATIC, L"Buffer_CollSphere"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Buffer", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	//// Renderer
	//pComponent = m_pRendererCom = Engine::Get_Renderer();
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//Safe_AddRef(pComponent);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Calculator
	//pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);
	////Safe_AddRef(pComponent);

	//m_pBufferCom->Set_Color(D3DCOLOR_ARGB(255, 148, 155, 0));
	//m_pTransformCom->m_vScale = { 30.f, 30.f, 30.f };
	return S_OK;
}

void CSphereCollider::OnCollision()
{
}

CSphereCollider* CSphereCollider::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSphereCollider* pInstance = new CSphereCollider(pGraphicDev);

	if (FAILED(pInstance->Ready_Object()))
		Engine::Safe_Release(pInstance);

	return pInstance;
}

void CSphereCollider::Free(void)
{
	//Safe_Release(m_pGraphicDev);
	
	Engine::CGameObject::Free();
}

HRESULT CSphereCollider::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	//for (_uint i = 0; i < 2; ++i)
	//{
	//	m_pGraphicDev->CreateTexture(1, 1, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &m_pTexture[i], NULL);

	//	D3DLOCKED_RECT		LockRect;
	//	ZeroMemory(&LockRect, sizeof(D3DLOCKED_RECT));

	//	m_pTexture[i]->LockRect(0, &LockRect, NULL, 0);

	//	*((_ulong*)LockRect.pBits) = D3DXCOLOR(1.f * i, 1.f * (1.f - i), 0.f, 1.f);

	//	m_pTexture[i]->UnlockRect(0);
	//}

	//Add_Vtx();

	return S_OK;
}

_int CSphereCollider::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);
	if (m_Dead)
		return 1;
	if (m_pDynamicMesh->isColl == false)
		isColl=false;
	else
		isColl = true;

	if (nullptr == m_pParentBoneMatrix)
	{
		if (m_pDynamicMesh == nullptr)
			return 0;
		if (!m_FrameNameCheck)
			return 0;

		const Engine::D3DXFRAME_DERIVED* pFrame = dynamic_cast<CUnit*>(m_pDynamicMesh)->m_pMeshCom->Get_FrameByName(m_FrameName.c_str());

		m_pParentBoneMatrix = &pFrame->CombinedTransformationMatrix;

		Engine::CTransform* pPlayerTransCom = dynamic_cast<CUnit*>(m_pDynamicMesh)->m_pTransformCom;
		NULL_CHECK_RETURN(pPlayerTransCom, 0);
		m_pParentWorldMatrix = pPlayerTransCom->Get_WorldMatrix();
	}



	m_pTransformCom->Set_ParentMatrix(&(*m_pParentBoneMatrix * *m_pParentWorldMatrix));


	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");
#ifdef _DEBUG
	/*m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);*/
#endif
	return 0;
}
void CSphereCollider::Render_Object(void)
{
	m_pTransformCom->Set_Transform(m_pGraphicDev);
#ifdef _DEBUG
	//LPD3DXMESH tmpMesh;
	//D3DXCreateSphere(m_pGraphicDev, 1, 10, 10, &tmpMesh, nullptr);
	//if (nullptr == tmpMesh)
	//	return;
	//_matrix tmpMatrix;
	//D3DXMatrixIdentity(&tmpMatrix);
	//tmpMatrix = *m_pTransformCom->Get_WorldMatrix();
	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &tmpMatrix);
	//m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	//m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	//m_pGraphicDev->SetTexture(0, m_pTexture[0]);
	//tmpMesh->DrawSubset(0);

	//m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
	//m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	//tmpMesh->Release();
	////m_pBufferCom->Render_Buffer();

	////m_pTextureCom->Render_Texture(0);
#endif
}