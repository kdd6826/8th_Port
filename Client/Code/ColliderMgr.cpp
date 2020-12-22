#include "stdafx.h"
#include "ColliderMgr.h"
#include "Unit.h"
IMPLEMENT_SINGLETON(CColliderMgr)

CColliderMgr::CColliderMgr(void)

{

}

CColliderMgr::~CColliderMgr(void)
{
	Free();
}



HRESULT CColliderMgr::Ready_ColliderMgr(LPDIRECT3DDEVICE9& pGraphicDev)
{
	
	return S_OK;
}

void CColliderMgr::Update()
{
	int i = 0;
}

void CColliderMgr::CollisionCheck(Engine::COLLID _srcType, Engine::COLLID _dstType)
{
	for (auto& srcElem : objectList[_srcType])
	{
		for (auto& dstElem : objectList[_dstType])
		{
			int i = 0;
		}
	}
}

bool CColliderMgr::IsCollided(CSphereCollider* _srcType, CSphereCollider* _dstType)
{
	
	_vec3 distance = _srcType->m_pTransformCom->m_vInfo[Engine::INFO_POS] - _dstType->m_pTransformCom->m_vInfo[Engine::INFO_POS];
	float dist = sqrtf(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
	
	float radius1 = _dstType->m_pTransformCom->m_vScale.x * dynamic_cast<CUnit*>(_dstType->m_pDynamicMesh)->m_pTransformCom->m_vScale.x;
	float radius2 = _srcType->m_pTransformCom->m_vScale.x * dynamic_cast<CUnit*>(_srcType->m_pDynamicMesh)->m_pTransformCom->m_vScale.x;
	
	return false;
}





void CColliderMgr::Free(void)
{
	int i = 0;
}