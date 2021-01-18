#ifndef Monster_h__
#define Monster_h__

#include "Unit.h"
#include "Define.h"
#include "SphereCollider.h"
BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;
class CShader;

END
class CSphereCollider;
BEGIN(Client)
class CMonster : public CUnit
{
public:
	CMonster(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMonster(void);
	virtual _int Update_Object(const _float& fTimeDelta);
	virtual void OnCollision(Engine::CGameObject* target)override;
	HRESULT		Add_Component(void);
	Engine::CMonsterState* m_pStateCom = nullptr;
protected:
	bool PlayerSearch(_vec3 _MonsterPos);
	
private:
protected:

	_bool isSearch = false;
	//플레이어까지의 거리
	_float disPlayer = 0.f;

	virtual void Free(void) override;

};

END
#endif // Monster_h__
