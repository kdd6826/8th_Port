#ifndef SwordTrail_h__
#define SwordTrail_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CSwordTrail : public CVIBuffer
{
protected:
	explicit CSwordTrail(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CSwordTrail(const CSwordTrail& rhs);
	virtual ~CSwordTrail(void);

public:
	virtual HRESULT	Ready_Buffer(void);

public:
	static CSwordTrail*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent*	Clone(void);
	virtual void Free(void);
};
END

#endif // SwordTrail_h__
