#ifndef Line_h__
#define Line_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CLine : public CVIBuffer
{
protected:
	explicit CLine(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CLine(const CLine& rhs);
	virtual ~CLine(void);

public:
	virtual HRESULT	Ready_Buffer(void);


public:
	static CLine* Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent* Clone(void);
	virtual void Free(void);
	LPD3DXMESH	pMesh;

	bool colorGreenCheck = true;
	bool colorGreen = true;
};
END

#endif