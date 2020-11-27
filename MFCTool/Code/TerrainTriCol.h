#include "Define.h"
#include "Base.h"
#include "VIBuffer.h"
#include "Engine_Define.h"
#include "Export_Function.h"


class ENGINE_DLL CTerrainTriCol// : public Engine::CVIBuffer
{
protected:
	explicit CTerrainTriCol(LPDIRECT3DDEVICE9 pGraphicDev);
	// explicit CTerrainTriCol(const CTerrainTriCol& rhs);
	virtual ~CTerrainTriCol(void);

//public:
//	virtual HRESULT	Ready_Buffer(_vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
//		, D3DXCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DXCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DXCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

//public:
	//static CTerrainTriCol*	Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
	//	, D3DXCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DXCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DXCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
	//virtual CComponent*	Clone(void);
//	virtual void Free(void);
};


