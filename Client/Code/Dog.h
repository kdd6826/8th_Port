#ifndef Dog_h__
#define Dog_h__

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
class CDog : public CMonster
{

	enum dogState
	{
		STATE_DASHATT,
		STATE_DMGBOTTOM,
		STATE_DMGUP,
		STATE_DOWNSTART,
		STATE_DOWNING,
		STATE_DOWNEND,
		STATE_DYING,
		STATE_STAND,
		STATE_TURNLEFT,
		STATE_TURNRIGHT,
		STATE_DOWNDMG,
		STATE_AIRSTART,
		STATE_AIRING,
		STATE_AIREND,
		STATE_KNOCKBACK,
		STATE_ATT,
		STATE_FALLING,
		STATE_RUN,

	};
private:
	explicit CDog(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDog(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	virtual void OnCollision(Engine::CGameObject* target)override;
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	void		Move(const _float& fTimeDelta);
	void		Attack(const _float& fTimeDelta);
	void		SetUp_OnTerrain(void);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	dogState m_state = dogState::STATE_STAND;

private:
	_vec3						m_vDir;
	_float						m_fAniSpeed=1.f;
	_float						delay = 0.f;
public:
	static CDog*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CDog*	Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage);
private:
	virtual void Free(void) override;

};

END
#endif // Dog_h__
