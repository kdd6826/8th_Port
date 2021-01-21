#ifndef MonsterState_h__
#define MonsterState_h__

#include "Component.h"
#include "Pipeline.h"

BEGIN(Engine)

class ENGINE_DLL CMonsterState : public CComponent
{
private:
	explicit CMonsterState(void);
	explicit CMonsterState(const CMonsterState& rhs);
	virtual ~CMonsterState(void);

public:
	enum monsterState
	{
		STATE_IDLE,
		STATE_FINDPLAYER
	};
	HRESULT			Ready_MonsterState(void);
	virtual _int	Update_Component(const _float& fTimeDelta);

public:
	STAT stat;
	monsterState state = STATE_IDLE;
public:
	static		CMonsterState*		Create(void);
	virtual CComponent*		Clone(void);
private:	
	virtual		void		Free(void);

};

END
#endif // MonsterState_h__
