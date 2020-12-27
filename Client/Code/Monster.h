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
protected:
	bool PlayerSearch(_vec3 _MonsterPos);
	
private:

protected:

	_bool isSearch = false;
	_bool isAnimating = false;
	//�÷��̾������ �Ÿ�
	_float disPlayer = 0.f;
	_float m_fSpeed;

	virtual void Free(void) override;

};

END
#endif // Monster_h__
