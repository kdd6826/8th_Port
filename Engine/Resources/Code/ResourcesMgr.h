#ifndef ResourcesMgr_h__
#define ResourcesMgr_h__

#include "Engine_Define.h"
#include "Base.h"

#include "TriCol.h"
#include "RcTex.h"
#include "TerrainTex.h"
#include "CubeTex.h"
#include "Sphere.h"
#include "TerrainTriCol.h"
#include "Texture.h"

#include "StaticMesh.h"
#include "DynamicMesh.h"

BEGIN(Engine)

class ENGINE_DLL CResourcesMgr : public CBase 
{
	DECLARE_SINGLETON(CResourcesMgr)

private:
	explicit CResourcesMgr(void);
	virtual ~CResourcesMgr(void);

public:
	HRESULT		Reserve_ContainerSize(const _ushort& wSize);
	HRESULT		Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev,
							const _ushort& wContainerIdx,
							const _tchar* pBufferTag, 
							BUFFERID eID, 
							_ulong dwCntX = 1, 
							_ulong dwCntZ = 1, 
							_ulong dwItv = 1);

	HRESULT		Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,
							const _ushort& wContainerIdx,
							const _tchar* pTextureTag,
							TEXTURETYPE eType, 
							const _tchar* pFilePath, 
							const _uint& iCnt = 0);

	HRESULT		Ready_Meshes(LPDIRECT3DDEVICE9 pGraphicDev,
							const _ushort& wContainerIdx,
							const _tchar* pMeshTag,
							MESHTYPE eType,
							const _tchar* pFilePath,
							const _tchar* pFileName);


	void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag);
	void		Render_Texture(const _ushort& wContainerIdx, const _tchar* pTextureTag, const _uint& iIndex);
	CComponent*	Clone(const _ushort& wContainerIdx, const _tchar* pResourcesTag);

	HRESULT		Create_TerrainTri(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort& wContainerIdx, const _tchar* pBufferTag, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
		, D3DCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

private:
	CResources*		Find_Resources(const _ushort& wContainerIdx, const _tchar* pResourcesTag);
	
private:
	map<const _tchar*, CResources*>*		m_pmapResource;
	_ushort									m_wSize = 0;

public:
	virtual void Free(void);
};


END
#endif // ResourcesMgr_h__
