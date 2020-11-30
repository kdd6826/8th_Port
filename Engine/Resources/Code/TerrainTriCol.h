#ifndef TerrainTriCol_h__
#define TerrainTriCol_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CTerrainTriCol : public CVIBuffer
{
protected:
	explicit CTerrainTriCol(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTerrainTriCol(const CTerrainTriCol& rhs);
	virtual ~CTerrainTriCol(void);

public:
	virtual HRESULT	Ready_Buffer(_vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3);

public:
	static CTerrainTriCol*	Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3);
	virtual CComponent*	Clone(void);
	virtual void Free(void);
};
END

#endif // TriCol_h__
