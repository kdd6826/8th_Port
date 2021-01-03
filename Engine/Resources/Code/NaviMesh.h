#ifndef NaviMesh_h__
#define NaviMesh_h__

#include "Base.h"
#include "Mesh.h"
#include "Cell.h"

BEGIN(Engine)

class ENGINE_DLL CNaviMesh : public CMesh
{
private:
	explicit CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pFilePath);
	explicit CNaviMesh(const CNaviMesh& rhs);
	virtual ~CNaviMesh(void);

public:
	void		Set_NaviIndex(const _ulong& dwIndex) { m_dwIndex = dwIndex; }

public:
	HRESULT		Ready_NaviMeshes(void);
	HRESULT		Ready_NaviMeshes(const _tchar* pFilePath);
	void		Render_NaviMeshes(void);

	_vec3			Move_OnNaviMesh(const _vec3* pTargetPos, const _vec3* pTargetDir);

private:
	HRESULT		Link_Cell(void);

private:
	vector<CCell*>			m_vecCell;
	_ulong					m_dwIndex;

public:
	static CNaviMesh*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CNaviMesh*		Create(LPDIRECT3DDEVICE9 pGraphicDev,const _tchar* pFilePath);
	virtual CComponent*		Clone(void);
	virtual void			Free(void);

};

END
#endif // NaviMesh_h__
