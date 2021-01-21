#ifndef PlayerState_h__
#define PlayerState_h__

#include "Component.h"
#include "Pipeline.h"

BEGIN(Engine)

class ENGINE_DLL CPlayerState : public CComponent
{
private:
	explicit CPlayerState(void);
	explicit CPlayerState(const CPlayerState& rhs);
	virtual ~CPlayerState(void);

public:
	enum playerMesh
	{
		MESH_NORMAL,
		MESH_DKKNIGHT,
		MESH_DKKNIGHT2
	};
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
		STATE_THROW_BALL,//마나리전, 디멘션홀
		STATE_RUINBLADE,
		STATE_LORDOFMANA,
		STATE_CONFUSIONHOLE,//가드
		STATE_DARKKNIGHT_TRANS1,
		STATE_DARKKNIGHT_TRANS2,
		STATE_DARKKNIGHT_END,
		STATE_DIFUSION,//회피
		STATE_MANABLADE,//TAB
		STATE_NORMAlBLADE,//TAB2
		STATE_MANA_IMAGE,//마나스톤 회수
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
	HRESULT			Ready_PlayerState(void);
	virtual _int	Update_Component(const _float& fTimeDelta);

public:
	STAT stat;
	playerMesh playerMeshState=MESH_NORMAL;
	playerState playerState = STATE_IDLE;
	bool		perfectGuard = false;
public:
	static		CPlayerState*		Create(void);
	virtual CComponent*		Clone(void);
private:	
	virtual		void		Free(void);

};

END
#endif // PlayerState_h__
