#ifndef Monster_h__
#define Monster_h__

#include "Unit.h"
#include "Define.h"
#include "SphereCollider.h"
#include "SlashPoint.h"
#include "DamageFont.h"
#include "FontParent.h"
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
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta);
	virtual void Render_Object(void) override;
	virtual void OnCollision(Engine::CGameObject* target)override;
	_bool GetKeyMonster() { return keyMonster; }
	void SetKeyMonster() { keyMonster = true; }
	_bool GetisTriggerBox() { return isTriggerBox; }
	HRESULT		Add_Component(void);
	Engine::CMonsterState* m_pStateCom = nullptr;
	Engine::COptimization* m_pOptimizationCom = nullptr;
protected:
	bool PlayerSearch(_vec3 _MonsterPos);
	
private:
protected:
	_bool keyMonster = false;
	_bool isTriggerBox = false;
	vector<CSlashPoint*>	m_vecSlashPoint;
	vector<CDamageFont*>	m_vecDamageFont;
	vector<CFontParent*>	m_vecFontParent;
	_bool isSearch = false;
	//플레이어까지의 거리
	_float disPlayer = 0.f;
	_bool isSound = false;
	_bool dieSound = false;
	bool initialize = false;
	virtual void Free(void) override;
	bool m_bDraw = false;
};

END
#endif // Monster_h__
