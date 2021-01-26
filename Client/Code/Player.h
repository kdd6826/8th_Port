#ifndef Player_h__
#define Player_h__

#include "Unit.h"
#include "Define.h"

BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;
class CShader;
class CPlayerState;

END

BEGIN(Client)
class CPlayer : public CUnit
{
private:
	explicit CPlayer(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CPlayer(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	virtual void OnCollision(Engine::CGameObject* target)override;
	Engine::CPlayerState* m_pStateCom = nullptr;
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	void		MovePlayer(const _float& fTimeDelta);
	void		Attack(const _float& fTimeDelta);
	void		AttackOnRotation();
	void		DownOnRotation();
	void		SetUp_OnTerrain(void);
	void		Key_Input(const _float& fTimeDelta);
	void		ConufusionHoleInit();
	void		StateEventFromDelay(float _fTimeDelta);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	//playerState m_state = playerState::STATE_IDLE;
	
	/*playerMesh	meshTransform = playerMesh::MESH_NORMAL;*/
	bool		isManaBlade = false;
	bool		isBattle = false;
	bool		isDown = false;
	bool		isAttack = false;
	bool		isMove = false;
	bool		isHit = false;
	bool		isRunning = false;
	bool		isSkill = false;//trueÀÏ¶© ´Ù¸¥Å° ¸ø¾¸.
	bool		isTired = false;
	bool		isShake = false;
private:
	vector<CUnit*>				hitMonsters;
	_vec3						m_vDir;
	bool						isAnimating;
	_float						delay = 0.f;
	_float						downDelay = 0.f;
	_float						m_fAniSpeed = 1.f;
	_float						m_fBattleCount=0.f;
	_vec3						hitDir;
public:
	static CPlayer*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

END
#endif // Player_h__
