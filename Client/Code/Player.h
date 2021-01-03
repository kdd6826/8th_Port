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
	//enum playerMesh
	//{
	//	MESH_NORMAL,
	//	MESH_DKKNIGHT,
	//	MESH_DKKNIGHT2
	//};
	enum playerState
	{
		STATE_IDLE,
		STATE_ATT1,
		STATE_ATT2,
		STATE_ATT3,
		STATE_ATT4,
		STATE_ATT5,
		STATE_FIELD_RUN,
		STATE_FIELD_SPRINT,
		STATE_FIELD_SPRINTSTOP,
		STATE_DMG_BACK,
		STATE_DMG_FRONT,
		STATE_DMG_LEFT,
		STATE_DMG_RIGHT,
		STATE_LAUNCH_START,
		STATE_LAUNCH_ING,
		STATE_LAUNCH_END,
		STATE_DEAD,
		STATE_DOWN_RESIST,
		STATE_MB_ATT1,
		STATE_MB_ATT2,
		STATE_MB_ATT3,
		STATE_MB_ATT4,
		STATE_MB_ATT5,
		STATE_MB_ATT6,
		STATE_THROW_BALL,//¸¶³ª¸®Àü, µð¸à¼ÇÈ¦
		STATE_RUINBLADE,
		STATE_LORDOFMANA,
		STATE_CONFUSIONHOLE,//°¡µå
		STATE_DARKKNIGHT_TRANS1,
		STATE_DARKKNIGHT_TRANS2,
		STATE_DARKKNIGHT_END,
		STATE_DIFUSION,//È¸ÇÇ
		STATE_MANABLADE,//TAB
		STATE_NORMAlBLADE,//TAB2
		STATE_MANA_IMAGE,//¸¶³ª½ºÅæ È¸¼ö
		STATE_TIRED_START,
		STATE_TIRED_ING,
		STATE_TIRED_END,
		STATE_TIRED_RUN,
		STATE_BATTLE_IDLE,
		STATE_DOWN_IDLE,
		STATE_DOWN_STANDUP,
		STATE_DOWN_BACKROLL,
		STATE_DOWN_FRONTROLL,
		STATE_DOWN_LEFTROLL,
		STATE_DOWN_RIGHTROLL,
		STATE_SHARPENMANA,
		STATE_DASH,
		STATE_STRONG_DOWN,
		STATE_MANA_IDLE,//MB IDLE
		STATE_DOOMSAYER,
		STATE_BOMB_BEGIN,
		STATE_BOMB_ING,
		STATE_BOMB_END,
	};
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
	void		SetUp_OnTerrain(void);
	void		Key_Input(const _float& fTimeDelta);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	playerState m_state = playerState::STATE_IDLE;
	/*playerMesh	meshTransform = playerMesh::MESH_NORMAL;*/
	bool		isManaBlade = false;
	bool		isBattle = false;
	bool		isAttack = false;
	bool		isMove = false;
	bool		isHit = false;
	bool		isRunning = false;
	bool		isSkill = false;//trueÀÏ¶© ´Ù¸¥Å° ¸ø¾¸.
private:
	vector<CUnit*>				hitMonsters;
	_vec3						m_vDir;
	bool						isAnimating;
	_float						delay = 0.f;
	_float						m_fAniSpeed = 1.f;
	_float						m_fBattleCount=0.f;
public:
	static CPlayer*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

END
#endif // Player_h__
