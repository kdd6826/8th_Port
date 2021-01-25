#ifndef TestTrail_h__
#define TestTrail_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CTestTrail : public CVIBuffer
{
protected:
	explicit CTestTrail(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTestTrail(const CTestTrail& rhs);
	virtual ~CTestTrail(void);

public:
	virtual HRESULT	Ready_Buffer(void);
	void		Update_Buffer(pair<_vec3,_vec3>* pPair);
public:
	static CTestTrail*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent*	Clone(void);
	virtual void Free(void);

	_vec3		m_vMin, m_vMax, m_vOldMin, m_vOldMax;
	list<pair<_vec3, _vec3>> vecList;
};
END

#endif // TestTrail_h__
