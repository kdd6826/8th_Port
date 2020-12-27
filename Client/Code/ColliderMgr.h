#ifndef CColliderMgr_h__
#define CColliderMgr_h__
#include "SphereCollider.h"


BEGIN(Client)
class CColliderMgr
{
	DECLARE_SINGLETON(CColliderMgr)

private:
	explicit CColliderMgr(void);
	virtual ~CColliderMgr(void);

public:
	HRESULT	Ready_ColliderMgr(LPDIRECT3DDEVICE9& pGraphicDev);
public:
	void Update();
	void CollisionCheck(Engine::COLLID _srcType, Engine::COLLID _dstType);
	static void RegisterObject(Engine::COLLID colType, CSphereCollider* _pObj);
	void DisregisterObject(CSphereCollider* obj);
	static void DisregisterObject(Engine::COLLID colType, CSphereCollider* _pObj);
	static bool IsCollided(CSphereCollider* _srcType, CSphereCollider* _dstType);
	static bool FindObject(Engine::COLLID colType, CSphereCollider* _pObj);
public:
	list<CSphereCollider*>				objectList[Engine::COLLID::NONE];


private:
	virtual void Free(void);
};
END
#endif // CColliderMgr_h__
