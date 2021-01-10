#include "SwordTrail.h"

USING(Engine)
Engine::CSwordTrail::CSwordTrail(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

Engine::CSwordTrail::CSwordTrail(const CSwordTrail& rhs)
	: CVIBuffer(rhs)
{

}

Engine::CSwordTrail::~CSwordTrail(void)
{

}

HRESULT Engine::CSwordTrail::Ready_Buffer(void)
{
	m_dwFVF = FVF_TEX;
	m_dwTriCnt = 2;
	m_dwVtxCnt = 4;
	m_dwVtxSize = sizeof(VTXTEX);

	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;

	FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	VTXTEX*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	
	// 오른쪽 위
	pVertex[0].vPos = _vec3(-0.5f, 0.5f, 0.f);
	pVertex[0].vTexUV = _vec2(0.f, 0.f);

	pVertex[1].vPos = _vec3(0.5f, 0.5f, 0.f);
	pVertex[1].vTexUV = _vec2(1.f, 0.f);

	pVertex[2].vPos = _vec3(0.5f, -0.5f, 0.f);
	pVertex[2].vTexUV = _vec2(1.f, 1.f);

	pVertex[3].vPos = _vec3(-0.5f, -0.5f, 0.f);
	pVertex[3].vTexUV = _vec2(0.f, 1.f);

	m_pVB->Unlock();
	

	INDEX16*		pIndex = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndex, 0);

	pIndex[0]._0 = 0;
	pIndex[0]._1 = 1;
	pIndex[0]._2 = 2;

	pIndex[1]._0 = 0;
	pIndex[1]._1 = 2;
	pIndex[1]._2 = 3;


	m_pIB->Unlock();

	return S_OK;
}


Engine::CSwordTrail* Engine::CSwordTrail::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CSwordTrail*	pInstance = new CSwordTrail(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

CComponent * CSwordTrail::Clone(void)
{
	return new CSwordTrail(*this);
}

void Engine::CSwordTrail::Free(void)
{
	CVIBuffer::Free();
}

