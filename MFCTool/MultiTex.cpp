#include "stdafx.h"
#include "MultiTex.h"


CMultiTex::CMultiTex()
{
}


CMultiTex::~CMultiTex()
{
	Release_Texture();
}
//D:\박병건\110C\4개월차\DefaultWinodows\Texture\Stage\Terrain\Tile\Tile%d.png
HRESULT CMultiTex::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey /*= L""*/, const DWORD & rCount /*= 0*/)
{
	auto& iter_find = m_mapMultiTex.find(wstrStateKey); 
	TCHAR szFilePath[MAX_PATH] = L"";
	if (m_mapMultiTex.end() == iter_find)
	{
		for (DWORD i = 0 ; i < rCount; ++i)
		{
			wsprintf(szFilePath, wstrFilePath.c_str(), i);
			TEXINFO* pTexInfo = new TEXINFO;
			ZeroMemory(pTexInfo, sizeof(TEXINFO));

			if (FAILED(D3DXGetImageInfoFromFile(szFilePath, &pTexInfo->tImageInfo)))
			{
				ERR_MSG(L"이미지 정보 불러오기 실패");
				Safe_Delete(pTexInfo); 
				return E_FAIL;
			}

			if (FAILED(D3DXCreateTextureFromFileEx(
				CGraphic_Device::Get_Instance()->Get_Device(),
				szFilePath,
				pTexInfo->tImageInfo.Width,
				pTexInfo->tImageInfo.Height,
				pTexInfo->tImageInfo.MipLevels,
				0,
				pTexInfo->tImageInfo.Format,
				D3DPOOL_MANAGED,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				0,
				nullptr,
				nullptr,
				&pTexInfo->pTexture)))// 10분뒤에. ㅋ
			{
				wstring wstrErrMessage = wstrFilePath + L"Create Texture Failed";
				ERR_MSG(wstrErrMessage.c_str());
				Safe_Delete(pTexInfo);
				return E_FAIL;
			}
			m_mapMultiTex[wstrStateKey].emplace_back(pTexInfo);
		}
	}
	return S_OK;
}

const TEXINFO * CMultiTex::Get_Texture(const wstring & wstrStateKey /*= L""*/, const DWORD & rIndex /*= 0*/)
{
	auto& iter_Find = m_mapMultiTex.find(wstrStateKey); 
	if(iter_Find == m_mapMultiTex.end())
		return nullptr;

	//return m_mapMultiTex[wstrStateKey][rIndex];
	return iter_Find->second[rIndex]; 
}

void CMultiTex::Release_Texture()
{
	for (auto& rPair : m_mapMultiTex)
	{
		for (auto& pTexInfo : rPair.second)
		{
			Safe_Delete(pTexInfo); 
		}
		rPair.second.clear(); 
		rPair.second.swap(vector<TEXINFO*>()); // 택 1 
		//rPair.second.shrink_to_fit(); 
	}
}
