#include "stdafx.h"
#include "Texture_Manager.h"
#include "Texture.h"
#include "SingleTex.h"
#include "MultiTex.h"
IMPLEMENT_SINGLETON(CTexture_Manager)
CTexture_Manager::CTexture_Manager()
{
}


CTexture_Manager::~CTexture_Manager()
{
	Release_TextureManager(); 
}

const TEXINFO * CTexture_Manager::Get_TexInfo(const wstring & wstrObjectKey, const wstring & wstrStateKey, const DWORD & dwImgIndex)
{
	auto& iter_find = m_mapTexture.find(wstrObjectKey); 

	if (m_mapTexture.end() == iter_find)
		return nullptr; 
	return iter_find->second->Get_Texture(wstrStateKey, dwImgIndex);
}

HRESULT CTexture_Manager::Insert_Texture(const TEX_ID & eTexID, const wstring& wstrFilePath,  const wstring & wstrObjectKey, const wstring & wstrStateKey, const DWORD & dwImgIndex)
{
	map<wstring, CTexture*>::iterator iter_find = m_mapTexture.find(wstrObjectKey);

	if (iter_find == m_mapTexture.end())
	{
		CTexture* pTexture = nullptr; 
		switch (eTexID)
		{
		case CTexture_Manager::TEX_SINGLE:
			pTexture = new CSingleTex; 
			break;
		case CTexture_Manager::TEX_MULTI:
			 pTexture = new CMultiTex; 
			break;
		case CTexture_Manager::TEXEND:
			break;
		default:
			break;
		}
		if (FAILED(pTexture->Insert_Texture(wstrFilePath, wstrStateKey, dwImgIndex)))
		{
			ERR_MSG(L"Texture Creating Failed"); 
			return E_FAIL; 
		}
		m_mapTexture.emplace(wstrObjectKey, pTexture);
	}
	else if (TEX_MULTI == eTexID)
	{
		if (FAILED(m_mapTexture[wstrObjectKey]->Insert_Texture(wstrFilePath, wstrStateKey, dwImgIndex)))
		{
			ERR_MSG(L"MultiTexture Creating Failed");
			return E_FAIL;
		}
	}
	return S_OK;
}

void CTexture_Manager::Release_TextureManager()
{
	for (auto& rPair : m_mapTexture)
		Safe_Delete(rPair.second); 
	m_mapTexture.clear(); 
}
