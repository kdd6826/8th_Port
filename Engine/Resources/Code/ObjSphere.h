#ifndef ObjSphere_h__
#define ObjSphere_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CObjSphere : public CVIBuffer
{
protected:
	explicit CObjSphere(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CObjSphere(const CObjSphere& rhs);
	virtual ~CObjSphere(void);

public:
	virtual HRESULT	Ready_Buffer(void);

	void Set_Color(D3DCOLOR color);

public:
	static CObjSphere* Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent* Clone(void);
	virtual void Free(void);
	LPD3DXMESH	pMesh;

	bool colorGreenCheck = true;
	bool colorGreen = true;
};
END

#endif