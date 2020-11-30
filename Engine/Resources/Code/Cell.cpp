#include "Cell.h"	

USING(Engine)

Engine::CCell::CCell(void)
	: m_pD3DXLine(nullptr)
{
	ZeroMemory(m_pLine, sizeof(CLine*) * LINE_END);
	ZeroMemory(m_pNeighbor, sizeof(CCell*) * NEIGHBOR_END);
}

Engine::CCell::~CCell(void)
{

}

HRESULT Engine::CCell::Ready_Cell(LPDIRECT3DDEVICE9 pGraphicDev, const _vec3* pPointA, const _vec3* pPointB, const _vec3* pPointC)
{
	m_vPoint[POINT_A] = *pPointA;
	m_vPoint[POINT_B] = *pPointB;
	m_vPoint[POINT_C] = *pPointC;

	m_pLine[LINE_AB] = CLine::Create(&_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z),
									 &_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z));

	m_pLine[LINE_BC] = CLine::Create(&_vec2(m_vPoint[POINT_B].x, m_vPoint[POINT_B].z),
									 &_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z));

	m_pLine[LINE_CA] = CLine::Create(&_vec2(m_vPoint[POINT_C].x, m_vPoint[POINT_C].z),
									 &_vec2(m_vPoint[POINT_A].x, m_vPoint[POINT_A].z));

#ifdef _DEBUG
	if (FAILED(D3DXCreateLine(pGraphicDev, &m_pD3DXLine)))
		return S_OK;
#endif

	return S_OK;
}

void Engine::CCell::Render_Cell(void)
{

}

Engine::CCell* Engine::CCell::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _vec3* pPointA, const _vec3* pPointB, const _vec3* pPointC)
{
	CCell*	pInstance = new CCell;

	if (FAILED(pInstance->Ready_Cell(pGraphicDev, pPointA, pPointB, pPointC)))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CCell::Free(void)
{
	for (_ulong i = 0; i < LINE_END; ++i)
	{
		Safe_Release(m_pLine[i]);
	}
	
	Safe_Release(m_pD3DXLine);
}

Engine::_bool Engine::CCell::Compare_Point(const _vec3* pFirstPoint, const _vec3* pSecondPoint, CCell* pCell)
{
	if (*pFirstPoint == m_vPoint[POINT_A])
	{
		if (*pSecondPoint == m_vPoint[POINT_B])
		{
			m_pNeighbor[NEIGHBOR_AB] = pCell;
			return true;
		}

		if (*pSecondPoint == m_vPoint[POINT_C])
		{
			m_pNeighbor[NEIGHBOR_CA] = pCell;
			return true;
		}
	}

	if (*pFirstPoint == m_vPoint[POINT_B])
	{
		if (*pSecondPoint == m_vPoint[POINT_A])
		{
			m_pNeighbor[NEIGHBOR_AB] = pCell;
			return true;
		}

		if (*pSecondPoint == m_vPoint[POINT_C])
		{
			m_pNeighbor[NEIGHBOR_BC] = pCell;
			return true;
		}
	}

	if (*pFirstPoint == m_vPoint[POINT_C])
	{
		if (*pSecondPoint == m_vPoint[POINT_B])
		{
			m_pNeighbor[NEIGHBOR_BC] = pCell;
			return true;
		}

		if (*pSecondPoint == m_vPoint[POINT_A])
		{
			m_pNeighbor[NEIGHBOR_CA] = pCell;
			return true;
		}
	}

	return false;
}

