#ifndef Sphere_h__
#define Sphere_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CSphere : public CVIBuffer
{
protected:
	explicit CSphere(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CSphere(const CSphere& rhs);
	virtual ~CSphere(void);

public:
	virtual HRESULT	Ready_Buffer(void);

	void Set_Color(D3DCOLOR color);

public:
	static CSphere* Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent* Clone(void);
	virtual void Free(void);
	LPD3DXMESH	pMesh;

	bool colorGreenCheck = true;
	bool colorGreen = true;
};
END

#endif