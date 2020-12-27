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
	CollisionCheck(Engine::PLAYER,Engine::ENEMY);
}

void CColliderMgr::CollisionCheck(Engine::COLLID _srcType, Engine::COLLID _dstType)
{
	for (auto& srcElem : objectList[_srcType])
	{
		for (auto& dstElem : objectList[_dstType])
		{
			if (IsCollided(srcElem, dstElem))
			{
				srcElem->m_pDynamicMesh->OnCollision(dstElem->m_pDynamicMesh);
				dstElem->m_pDynamicMesh->OnCollision(srcElem->m_pDynamicMesh);
			}
		}
	}
}

void CColliderMgr::RegisterObject(Engine::COLLID colType, CSphereCollider* _pObj)
{
	if (FindObject(colType, _pObj))
	{
		return;
	}

	m_pInstance->objectList[colType].push_back(_pObj);
}

void CColliderMgr::DisregisterObject(CSphereCollider* obj)
{
	for (int i = 0; i < Engine::COLLID::NONE; ++i)
	{
		auto iter = find_if(objectList[i].begin(), objectList[i].end(), [obj](CSphereCollider* elem)
			{
				return elem == obj;
			});

		if (objectList[i].end() != iter) objectList[i].erase(iter);
	}
}

void CColliderMgr::DisregisterObject(Engine::COLLID colType, CSphereCollider* _pObj)
{
	if (_pObj == nullptr) return;

	auto iter = m_pInstance->objectList[colType].begin();
	auto end = m_pInstance->objectList[colType].end();

	for (; iter != end; ++iter)
	{
		if ((*iter) != _pObj) continue;

		m_pInstance->objectList[colType].erase(iter);
		return;
	}
}

bool CColliderMgr::IsCollided(CSphereCollider* _srcType, CSphereCollider* _dstType)
{
	_matrix temp1, temp2;
	_srcType->m_pTransformCom->Get_WorldMatrix(&temp1);
	_dstType->m_pTransformCom->Get_WorldMatrix(&temp2);
	_vec3 srcPos = { temp1._41,temp1._42,temp1._43 };
	_vec3 dstPos = { temp2._41,temp2._42,temp2._43 };

	_vec3 distance = srcPos- dstPos;
	float dist = sqrtf(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
	
	float radius1 = _dstType->m_pTransformCom->m_vScale.x * dynamic_cast<CUnit*>(_dstType->m_pDynamicMesh)->m_pTransformCom->m_vScale.x;
	float radius2 = _srcType->m_pTransformCom->m_vScale.x * dynamic_cast<CUnit*>(_srcType->m_pDynamicMesh)->m_pTransformCom->m_vScale.x;
	if (dist < (radius1 + radius2))
	{
		return true;
	}
	return false;
}

bool CColliderMgr::FindObject(Engine::COLLID colType, CSphereCollider* _pObj)
{
	if (_pObj == nullptr) return false;
	for (auto iter : m_pInstance->objectList[colType])
	{
		if (iter != _pObj) continue;

		return true;
	}
	return false;
}





void CColliderMgr::Free(void)
{
	for (int i = 0; i < Engine::COLLID::NONE; ++i) objectList[i].clear();
}