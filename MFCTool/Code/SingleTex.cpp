#include "stdafx.h"
#include "SingleTex.h"


CSingleTex::CSingleTex()
{
}


CSingleTex::~CSingleTex()
{
	Release_Texture(); 
}

HRESULT CSingleTex::Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey /*= L""*/, const DWORD & rCount /*= 0*/)
{
	m_pTexInfo = new TEXINFO; 
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO)); 

	if (FAILED(D3DXGetImageInfoFromFile(wstrFilePath.c_str(), &m_pTexInfo->tImageInfo)))
	{
		ERR_MSG(L"이미지 정보 불러오기 실패"); 
		return E_FAIL; 
	}

	if (FAILED(D3DXCreateTextureFromFileEx(
		CGraphic_Device::Get_Instance()->Get_Device(),
		wstrFilePath.c_str(),
		m_pTexInfo->tImageInfo.Width,
		m_pTexInfo->tImageInfo.Height,
		m_pTexInfo->tImageInfo.MipLevels,
		0,
		m_pTexInfo->tImageInfo.Format,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		nullptr,
		nullptr,
		&m_pTexInfo->pTexture)))// 10분뒤에. ㅋ
	{
		wstring wstrErrMessage = wstrFilePath + L"Create Texture Failed";
		ERR_MSG(wstrErrMessage.c_str());
		return E_FAIL; 
	}
	return S_OK; 
}

void CSingleTex::Release_Texture()
{
	Safe_Delete(m_pTexInfo); 
}

const TEXINFO * CSingleTex::Get_Texture(const wstring & wstrStateKey /*= L""*/, const DWORD & rIndex /*= 0*/)
{
	return m_pTexInfo;
}
