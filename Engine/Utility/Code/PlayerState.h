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
	HRESULT			Ready_PlayerState(void);
	virtual _int	Update_Component(const _float& fTimeDelta);

public:
	STAT stat;
	playerMesh playerMeshState=MESH_NORMAL;
public:
	static		CPlayerState*		Create(void);
	virtual CComponent*		Clone(void);
private:	
	virtual		void		Free(void);

};

END
#endif // PlayerState_h__
