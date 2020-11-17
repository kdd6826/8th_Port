#ifndef Calculator_h__
#define Calculator_h__

#include "Component.h"

BEGIN(Engine)

class CTerrainTex;
class CTransform;
class ENGINE_DLL CCalculator : public CComponent
{
private:
	explicit CCalculator(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CCalculator(const CCalculator& rhs);
	virtual ~CCalculator(void);

public:
	HRESULT			Ready_Calculator(void);

	_float			Compute_HeightOnTerrain(const _vec3* pPos, 
											const _vec3* pTerrainVtxPos, 
											const _ulong& dwCntX, 
											const _ulong& dwCntZ,
											const _ulong& dwVtxItv = 1);

	_vec3			Picking_OnTerrain(HWND hWnd, 	CTerrainTex* pTerrainBufferCom, 	CTransform* pTerrainTransformCom);
	_bool			Collision_AABB(const _vec3* pDestMin, const _vec3* pDestMax, const _matrix* pDestWorld, 
								   const _vec3* pSourMin, const _vec3* pSourMax, const _matrix* pSourWorld);

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev;
public:
	static CCalculator*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent*		Clone(void);
private:
	virtual void			Free(void);

};

END
#endif // Calculator_h__
