#ifndef Titan_h__
#define Titan_h__

#include "Monster.h"
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

BEGIN(Client)
class CTitan : public CMonster
{

	enum titanState
	{
		STATE_IDLE				,
		STATE_RUN				,
		STATE_DOWN				,
		STATE_DOWNDURING		,
		STATE_STANDUP			,
		STATE_DAMAGEPARRY		,
		STATE_TURNLEFT			,
		STATE_TURNRIGHT			,
		STATE_WALKRIGHT			,
		STATE_WALKUP			,
		STATE_WALKDOWN			,
		STATE_WALKLEFT			,
		STATE_DAMAGEWEAKPOINT	,
		STATE_ATTACKBALLISTA	,
		STATE_ATTACKHAMMER		,
		STATE_ATTACKKICK		,
		STATE_ATTACKRAGE		,
		STATE_ATTACKSTOMP		,
		STATE_ATTACKTURNLEFT	,
		STATE_ATTACKTURNRIGHT	,
		STATE_ATTACKTWOSTEP		,
		STATE_DYINGFRONT		,
		STATE_DYINGBACK			,
		STATE_DYINGLEFT			,
		STATE_DYINGRIGHT		

	};
private:
	explicit CTitan(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTitan(void);

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
	titanState m_state = titanState::STATE_IDLE;

	_vec3 oldPos;
	_vec3 newPos;
	_vec3 dirPos;
	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;

	_vec3						m_vDir;
	_float						m_fAniSpeed=1.f;
	_float						delay = 0.f;


public:
	static CTitan*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CTitan*	Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage);

private:
	virtual void Free(void) override;

};

END
#endif // Titan_h__
