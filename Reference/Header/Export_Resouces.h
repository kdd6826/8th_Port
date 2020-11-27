#ifndef Export_Resouces_h__
#define Export_Resouces_h__

#include "ResourcesMgr.h"

BEGIN(Engine)

// ResourcesMgr
// Get
inline CComponent*	Clone(const _ushort& wContainerIdx, const _tchar* pResourcesTag);
// Set
// General

inline HRESULT		Reserve_ContainerSize(const _ushort& wSize);
inline HRESULT		Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev,	const _ushort& wContainerIdx,	const _tchar* pBufferTag,	BUFFERID eID,	_ulong dwCntX = 1,	_ulong dwCntZ = 1,	_ulong dwItv = 1);
inline HRESULT		Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,	const _ushort& wContainerIdx,	const _tchar* pTextureTag,	TEXTURETYPE eType,	const _tchar* pFilePath, const _uint& iCnt = 1);
inline HRESULT		Ready_Meshes(LPDIRECT3DDEVICE9 pGraphicDev,	const _ushort& wContainerIdx,	const _tchar* pMeshTag,	MESHTYPE eType,	const _tchar* pFilePath,	const _tchar* pFileName);
inline HRESULT		Create_TerrainTri(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort& wContainerIdx, const _tchar* pBufferTag, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
	, D3DCOLOR VtxCol1 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol2 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f), D3DCOLOR VtxCol3 = D3DXCOLOR(1.f, 0.f, 0.f, 1.f));


inline void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag);
inline void		Render_Texture(const _ushort& wContainerIdx, const _tchar* pTextureTag, const _uint& iIndex);

// Release Resources
inline void Release_Resoures();

#include "Export_Resouces.inl"

END
#endif // Export_Resouces_h__
