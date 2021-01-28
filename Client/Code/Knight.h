#ifndef Knight_h__
#define Knight_h__

#include "Monster.h"
#include "Define.h"

BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;
class CShader;

END

BEGIN(Client)
class CKnight : public CMonster
{

	enum KnightState
	{
		STATE_Knight_Att,
		STATE_DMGBOTTOM,
		STATE_DMGUP,
		STATE_DOWNSTART,
		STATE_DOWNING,
		STATE_DOWNEND,
		STATE_DYING,
		STATE_STAND,
		STATE_STAPBACK,
		STATE_STAPLEFT,
		STATE_STAPRIGHT,
		STATE_STAPFRONT,
		STATE_KNOCKBACK,
	};
private:
	explicit CKnight(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CKnight(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	virtual void OnCollision(Engine::CGameObject* target)override;
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	void		Move(const _float& fTimeDelta);
	void		Attack(const _float& fTimeDelta)
	{
	}
	void		SetUp_OnTerrain(void);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	KnightState m_state = KnightState::STATE_STAND;

private:
	_vec3						m_vDir;
	_float						m_fAniSpeed=1.f;
	_float						delay = 0.f;
public:
	static CKnight*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CKnight*	Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage);

private:
	virtual void Free(void) override;

};

END
#endif // Knight_h__
