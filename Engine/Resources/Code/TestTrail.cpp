#include "TestTrail.h"

USING(Engine)
Engine::CTestTrail::CTestTrail(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

Engine::CTestTrail::CTestTrail(const CTestTrail& rhs)
	: CVIBuffer(rhs)
{

}

Engine::CTestTrail::~CTestTrail(void)
{

}

HRESULT Engine::CTestTrail::Ready_Buffer(void)
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
	pVertex[0].vTexUV = _vec2(1.f, 0.f);

	pVertex[1].vPos = _vec3(0.5f, 0.5f, 0.f);
	pVertex[1].vTexUV = _vec2(0.f, 0.f);

	pVertex[2].vPos = _vec3(0.5f, -0.5f, 0.f);
	pVertex[2].vTexUV = _vec2(0.f, 1.f);

	pVertex[3].vPos = _vec3(-0.5f, -0.5f, 0.f);
	pVertex[3].vTexUV = _vec2(1.f, 1.f);


	
	

	
	

	
	

	
	
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

void CTestTrail::Update_Buffer(pair<_vec3, _vec3>* pPair, _float fTimedelta)
{
	m_dwFVF = FVF_TEX;
	m_dwTriCnt = 6;
	m_dwVtxCnt = 8;
	m_dwVtxSize = sizeof(VTXTEX);

	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;

	if (vecList.size() > 20)
	{
		pair<_vec3,_vec3> old =	vecList.front();
		vecList.pop_front();
		//max
		m_vOldMax = old.first;
		m_vOldMin = old.second;
	}
	createCount += fTimedelta;
	if (createCount > 1.f)
	{
		m_vMax = pPair->first;
		m_vMin = pPair->second;
		createCount = 0.f;
	}
	VTXTEX* pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);

	// 오른쪽 위
	pVertex[0].vPos = _vec3(m_vMax);
	
	pVertex[1].vPos = _vec3(m_vOldMax);
	
	pVertex[2].vPos = _vec3(m_vOldMin);
	
	pVertex[3].vPos = _vec3(m_vMin);
	
	pVertex[4].vPos = _vec3(m_vMax);

	pVertex[5].vPos = _vec3(m_vOldMax);

	pVertex[6].vPos = _vec3(m_vOldMin);

	pVertex[7].vPos = _vec3(m_vMin);
	m_pVB->Unlock();


	m_vOldMax = m_vMax;
	m_vOldMin = m_vMin;
	vecList.emplace_back(make_pair(m_vMax, m_vMin));

}


Engine::CTestTrail* Engine::CTestTrail::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CTestTrail*	pInstance = new CTestTrail(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

CComponent * CTestTrail::Clone(void)
{
	return new CTestTrail(*this);
}

void Engine::CTestTrail::Free(void)
{
	CVIBuffer::Free();
}

