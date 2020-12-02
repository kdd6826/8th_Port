#ifndef Cell_h__
#define Cell_h__

#include "Engine_Define.h"
#include "Base.h"
#include "Line.h"

BEGIN(Engine)

class ENGINE_DLL CCell : public CBase
{
public:
	enum POINT {	POINT_A, POINT_B,POINT_C, POINT_END};
	enum LINE  { LINE_AB, LINE_BC, LINE_CA, LINE_END };
	enum NEIGHBOR {	NEIGHBOR_AB, NEIGHBOR_BC, NEIGHBOR_CA, NEIGHBOR_END };

private:
	explicit CCell(void);
	virtual ~CCell(void);

public:
	const _vec3*	Get_Point(POINT eType) const { return &m_vPoint[eType]; }
	CCell*			Get_Neighbor(NEIGHBOR eType) const { return m_pNeighbor[eType]; }
	void			Set_Neighbor(NEIGHBOR eType, CCell* pNeighbor) { m_pNeighbor[eType] = pNeighbor; }

	_vec3*			Get_pPoint(POINT eType)		 { return &m_vPoint[eType]; } //½ÂÇö

public:
	HRESULT				Ready_Cell(LPDIRECT3DDEVICE9 pGraphicDev,
									const _vec3* pPointA,
									const _vec3* pPointB,
									const _vec3* pPointC);

	_bool				Compare_Point(const _vec3* pFirstPoint, const _vec3* pSecondPoint, CCell* pCell);

	void				Render_Cell(void);

private:
	_vec3				m_vPoint[POINT_END];
	CCell*				m_pNeighbor[NEIGHBOR_END];
	CLine*				m_pLine[LINE_END];
	LPD3DXLINE			m_pD3DXLine;

public:
	static CCell*			Create(LPDIRECT3DDEVICE9 pGraphicDev, const _vec3* pPointA, const _vec3* pPointB, const _vec3* pPointC);
	virtual void			Free(void);

};

END
#endif // Cell_h__
