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
	if(isCreate)
	CColliderMgr::GetInstance()->DisregisterObject(this);
	
}

HRESULT CSphereCollider::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);


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
	Engine::CGameObject::Free();
}

HRESULT CSphereCollider::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);


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
	if (!isEnvironment)
	{
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
	}
	else
	{
		Engine::CTransform* pPlayerTransCom = dynamic_cast<CUnit*>(m_pDynamicMesh)->m_pTransformCom;
		NULL_CHECK_RETURN(pPlayerTransCom, 0);
		m_pParentWorldMatrix = pPlayerTransCom->Get_WorldMatrix();
		m_pTransformCom->Set_ParentMatrix(&*m_pParentWorldMatrix);
	}

	//m_bColl = Collision_ToObject(L"GameLogic", L"Player");
#ifdef _DEBUG
	/*m_pRendererCom->Add_RenderGroup(Engine::RENDER_NONALPHA, this);*/
#endif
	return 0;
}
void CSphereCollider::Render_Object(void)
{
#ifdef _DEBUG
	//m_pTransformCom->Set_Transform(m_pGraphicDev);
	//m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	//m_pBufferCom->Render_Buffer();
	////m_pTextureCom->Render_Texture(0);
	//m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	//m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
#endif
}
