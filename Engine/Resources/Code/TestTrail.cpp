#include "TestTrail.h"

USING(Engine)
Engine::CTestTrail::CTestTrail(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{
	createCount = 0;
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
	m_dwTriCnt = 20;
	m_dwVtxCnt =22;
	m_dwVtxSize = sizeof(VTXTEX);

	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;
	
	FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	VTXTEX*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	
	// 오른쪽 위
	
	pVertex[0].vTexUV  = _vec2(0.f,0.f);
	pVertex[1].vTexUV  = _vec2(0.1f,0.f);
	pVertex[2].vTexUV  = _vec2(0.2f,0.f);
	pVertex[3].vTexUV  = _vec2(0.3f,0.f);
	pVertex[4].vTexUV  = _vec2(0.4f,0.f);
	pVertex[5].vTexUV  = _vec2(0.5f,0.f);
	pVertex[6].vTexUV  = _vec2(0.6f,0.f);
	pVertex[7].vTexUV  = _vec2(0.7f,0.f);
	pVertex[8].vTexUV  = _vec2(0.8f,0.f);
	pVertex[9].vTexUV  = _vec2(0.9f,0.f);
	pVertex[10].vTexUV = _vec2(1.f,0.f);

	pVertex[11].vTexUV = _vec2(1.f, 1.f);
	pVertex[12].vTexUV = _vec2(0.9f, 1.f);
	pVertex[13].vTexUV = _vec2(0.8f, 1.f);
	pVertex[14].vTexUV = _vec2(0.7f, 1.f);
	pVertex[15].vTexUV = _vec2(0.6f, 1.f);
	pVertex[16].vTexUV = _vec2(0.5f, 1.f);
	pVertex[17].vTexUV = _vec2(0.4f, 1.f);
	pVertex[18].vTexUV = _vec2(0.3f, 1.f);
	pVertex[19].vTexUV = _vec2(0.2f, 1.f);
	pVertex[20].vTexUV = _vec2(0.1f, 1.f);
	pVertex[21].vTexUV = _vec2(0.f, 1.f);
	
	
	

	
	
	m_pVB->Unlock();
	

	INDEX16*		pIndex = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndex, 0);

	pIndex[0]._0 = 0;
	pIndex[0]._1 = 1;
	pIndex[0]._2 = 20;

	pIndex[1]._0 = 0;
	pIndex[1]._1 = 20;
	pIndex[1]._2 = 21;

	pIndex[2]._0 = 1;
	pIndex[2]._1 = 2;
	pIndex[2]._2 = 19;

	pIndex[3]._0 = 1;
	pIndex[3]._1 = 19;
	pIndex[3]._2 = 20;

	pIndex[4]._0 = 2;
	pIndex[4]._1 = 3;
	pIndex[4]._2 = 18;

	pIndex[5]._0 = 2;
	pIndex[5]._1 = 18;
	pIndex[5]._2 = 19;

	pIndex[6]._0 = 3;
	pIndex[6]._1 = 4;
	pIndex[6]._2 = 17;

	pIndex[7]._0 = 3;
	pIndex[7]._1 = 17;
	pIndex[7]._2 = 18;

	pIndex[8]._0 = 4;
	pIndex[8]._1 = 5;
	pIndex[8]._2 = 16;

	pIndex[9]._0 = 4;
	pIndex[9]._1 = 16;
	pIndex[9]._2 = 17;


	pIndex[10]._0 = 5;
	pIndex[10]._1 = 6;
	pIndex[10]._2 = 15;

	pIndex[11]._0 = 5;
	pIndex[11]._1 = 15;
	pIndex[11]._2 = 16;
		   
	pIndex[12]._0 = 6;
	pIndex[12]._1 = 7;
	pIndex[12]._2 = 14;
		   
	pIndex[13]._0 = 6;
	pIndex[13]._1 = 14;
	pIndex[13]._2 = 15;
		   
	pIndex[14]._0 = 7;
	pIndex[14]._1 = 8;
	pIndex[14]._2 = 13;
		   
	pIndex[15]._0 = 7;
	pIndex[15]._1 = 13;
	pIndex[15]._2 = 14;
		   
	pIndex[16]._0 = 8;
	pIndex[16]._1 = 9;
	pIndex[16]._2 = 12;
		   
	pIndex[17]._0 = 8;
	pIndex[17]._1 = 12;
	pIndex[17]._2 = 13;
		   
	pIndex[18]._0 = 9;
	pIndex[18]._1 = 10;
	pIndex[18]._2 = 11;
		   
	pIndex[19]._0 = 9;
	pIndex[19]._1 = 11;
	pIndex[19]._2 = 12;

	m_pIB->Unlock();

	return S_OK;
}

void CTestTrail::Update_Buffer(pair<_vec3, _vec3>* pPair, _float fTimedelta)
{
	m_dwFVF = FVF_TEX;
	m_dwTriCnt = 20;
	m_dwVtxCnt = 22;
	m_dwVtxSize = sizeof(VTXTEX);

	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;

	
	vecList[0].first = pPair->first;
	vecList[0].second = pPair->second;

	VTXTEX* pVertex = NULL;
	
	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	
	// 오른쪽 위
	for (int i = 0; i < 11; ++i)
	{
		//max
		pVertex[i].vPos = _vec3(vecList[i].first);
		//min
		pVertex[21 - i].vPos = _vec3(vecList[i].second);
	}
	
	m_pVB->Unlock();
	

	for (int i = 10; i > 0; --i)
	{
			
		vecList[i].first = vecList[i - 1].first;
		vecList[i].second = vecList[i - 1].second;
	}
	vecList[0].first = pPair->first;
	vecList[0].second = pPair->second;


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

