#ifndef TrailBuffer_h__
#define TrailBuffer_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CTrailBuffer : public CVIBuffer
{
protected:
	explicit CTrailBuffer(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTrailBuffer(const CTrailBuffer& rhs);
	virtual ~CTrailBuffer(void);

	HRESULT Ready_Buffer(const _ulong& dwVtxMax);

public:
	//virtual HRESULT	Ready_Buffer(void);
public:
	static CTrailBuffer*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static Engine::CTrailBuffer* Create(LPDIRECT3DDEVICE9 pGraphicDev, const _ulong& dwVtxMax);
	virtual CComponent* Clone(void);
	virtual void Free(void);
	void Render_Buffer();
	void Render_Buffer(const list<pair<_vec3, _vec3>>* pTrailList);
	HRESULT Add_Vertex(const _vec3* pTopPos, const _vec3* pBottomPos);
	HRESULT Clear_Vertex();
	HRESULT Add_Vertex_CatmullRom(const list<pair<_vec3, _vec3>>* pTrailList);

	_ulong m_dwUsingVtxCnt;
	_ulong m_dwUsingTriCnt;
	_ulong m_dwVtxFVF;
	list<pair<_vec3, _vec3>>* m_pTrailList;
};
END

#endif // TrailBuffer_h__
