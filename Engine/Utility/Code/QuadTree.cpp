#include "QuadTree.h"

#include "Frustum.h"
USING(Engine)

Engine::CQuadTree::CQuadTree(void)
{
	ZeroMemory(m_pChild, sizeof(CQuadTree*) * CHILD_END);
}

Engine::CQuadTree::~CQuadTree(void)
{

}

HRESULT Engine::CQuadTree::Ready_QuadTree(const _ulong& dwCntX, const _ulong& dwCntZ)
{
	m_dwCorner[CORNER_LT] = dwCntX * dwCntZ - dwCntX;
	m_dwCorner[CORNER_RT] = dwCntX * dwCntZ - 1;
	m_dwCorner[CORNER_LB] = 0;
	m_dwCorner[CORNER_RB] = dwCntX - 1;

	m_dwCenter = (m_dwCorner[CORNER_LT] + m_dwCorner[CORNER_RT] + m_dwCorner[CORNER_LB] + m_dwCorner[CORNER_RB]) >> 2;

	//Make_ChildQuadTree();

	return S_OK;
}

void Engine::CQuadTree::Culling_ForTerrain(CFrustum* pFrustum,
											const _vec3* pVtxPos,
											INDEX32* pIndex, 
											_ulong* pTriCnt)
{
	m_fRadius = D3DXVec3Length(&(pVtxPos[m_dwCorner[CORNER_LT]] - pVtxPos[m_dwCenter]));

	pFrustum->Is_InFrustum(pVtxPos, m_fRadius);
}

void Engine::CQuadTree::Make_ChildCorner(CHILD eType, const _ulong& dwPLT, 
	const _ulong& dwPRT, const _ulong& dwPLB,
	const _ulong& dwPRB, const _ulong& dwPCenter,
	_ulong* pLT, _ulong* pRT, _ulong* pLB, _ulong* pRB)
{
	_ulong	dwLT, dwRT, dwLB, dwRB;
	_ulong	dwLC, dwRC, dwTC, dwBC;

	dwLC = (dwPLT + dwPLB) >> 1;
	dwRC = (dwPRT + dwPRB) >> 1;
	dwTC = (dwPLT + dwPRT) >> 1;
	dwBC = (dwPLB + dwPRB) >> 1;

	switch (eType)
	{
	case CHILD_LT:
		dwLT = dwPLT;
		dwRT = dwTC;
		dwLB = dwLC;
		dwRB = dwPCenter;
		break;

	case CHILD_RT:
		dwLT = dwTC;
		dwRT = dwPRT;
		dwLB = dwPCenter;
		dwRB = dwRC;
		break;

	case CHILD_LB:
		dwLT = dwLC;
		dwRT = dwPCenter;
		dwLB = dwPLB;
		dwRB = dwBC;
		break;

	case CHILD_RB:
		dwLT = dwPCenter;
		dwRT = dwRC;
		dwLB = dwBC;
		dwRB = dwPRB;
		break;

	}
		
	*pLT = dwLT;
	*pRT = dwRT;
	*pLB = dwLB;
	*pRB = dwRB;
}

void Engine::CQuadTree::Make_ChildQuadTree(void)
{
	if (1 == m_dwCorner[CORNER_RT] - m_dwCorner[CORNER_LT])
		return;

	for (_ulong i = 0; i < CHILD_END; ++i)
	{
		_ulong dwLT, dwRT, dwLB, dwRB;

		Make_ChildCorner(CHILD(i),
			m_dwCorner[CORNER_LT],  
			m_dwCorner[CORNER_RT], 
			m_dwCorner[CORNER_LB], 
			m_dwCorner[CORNER_RB],
			m_dwCenter, 
			&dwLT, &dwRT, &dwLB, &dwRB);

		m_pChild[i] = Create(dwLT, dwRT, dwLB, dwRB);

		if (nullptr != m_pChild[i])
			m_pChild[i]->Make_ChildQuadTree();
	}

}

void Engine::CQuadTree::Set_Corner(const _ulong& dwLT, const _ulong& dwRT, const _ulong& dwLB, const _ulong& dwRB)
{

}

Engine::CQuadTree* Engine::CQuadTree::Create(const _ulong& dwCntX, const _ulong& dwCntZ)
{
	CQuadTree*	pInstance = new CQuadTree;

	if (FAILED(pInstance->Ready_QuadTree(dwCntX, dwCntZ)))
		Safe_Release(pInstance);

	return pInstance;
}

Engine::CQuadTree* Engine::CQuadTree::Create(const _ulong& dwLT, const _ulong& dwRT, const _ulong& dwLB, const _ulong& dwRB)
{
	CQuadTree* pInstance = new CQuadTree;

	pInstance->Set_Corner(dwLT, dwRT, dwLB, dwRB);

	return pInstance;
}

void Engine::CQuadTree::Free(void)
{
	for (_ulong i = 0; i < CHILD_END; ++i)
		Safe_Release(m_pChild[i]);
}

