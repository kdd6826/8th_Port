#ifndef PtTex_h__
#define PtTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CPtTex : public CVIBuffer
{
protected:
	explicit CPtTex(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CPtTex(const CPtTex& rhs);
	virtual ~CPtTex(void);

public:
	virtual HRESULT	Ready_Buffer(void);
	void			Render_Buffer(void);

private:
	LPDIRECT3DVERTEXBUFFER9			m_pVBTransform;
	LPDIRECT3DVERTEXDECLARATION9	m_pDecl;

public:
	static CPtTex*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual CComponent*	Clone(void);
	virtual void Free(void);
};
END

#endif // PtTex_h__
