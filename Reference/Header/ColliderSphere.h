#ifndef ColliderSphere_h__
#define ColliderSphere_h__

#include "Component.h"
#include "CollSphere.h"
BEGIN(Engine)

class ENGINE_DLL CColliderSphere : public CComponent
{
private:
	explicit CColliderSphere(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CColliderSphere(const CColliderSphere& rhs);
	virtual ~CColliderSphere(void);


public:
	HRESULT		Ready_ColliderSphere();
	void		Render_ColliderSphere(COLLTYPE eType, const _matrix* pColliderSphereMatrix);
	_matrix		m_matCollMatrix;
#ifdef _DEBUG
	LPDIRECT3DDEVICE9			m_pGraphicDev;
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9		m_pIB;
	LPDIRECT3DTEXTURE9			m_pTexture[COL_END];
	
	/// ///
	LPD3DXMESH	pMesh;
	vector<Engine::CCollSphere*>	m_VecSphereCollider;
	_ulong						m_dwVtxCnt;
	_ulong						m_dwTriCnt;
	_ulong						m_dwVtxSize;
	_ulong						m_dwFVF;

	_ulong						m_dwIdxSize;
	D3DFORMAT					m_IdxFmt;
	//////
#endif

public:
	static CColliderSphere*			Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent*			Clone(void);
	virtual void				Free(void);
};
END
#endif // ColliderSphere_h__
