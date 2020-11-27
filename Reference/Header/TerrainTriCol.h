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
	virtual HRESULT	Ready_Buffer(_vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
		, D3DCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

public:
	static CTerrainTriCol*	Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
		, D3DCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
	virtual CComponent*	Clone(void);
	virtual void Free(void);
};
END

#endif // TriCol_h__
