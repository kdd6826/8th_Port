#pragma once
class CTexture;
class CTexture_Manager
{
	DECLARE_SINGLETON(CTexture_Manager)
public:
	enum TEX_ID {TEX_SINGLE, TEX_MULTI, TEXEND};
private:
	CTexture_Manager();
	~CTexture_Manager();

public:
	const TEXINFO* Get_TexInfo(const wstring& wstrObjectKey, const wstring& wstrStateKey = L"", const DWORD& dwImgIndex = 0);
	HRESULT Insert_Texture(const TEX_ID& eTexID, const wstring& wstrFilePath,const wstring& wstrObjectKey, const wstring& wstrStateKey = L"", const DWORD& dwImgIndex = 0);
	void Release_TextureManager();
private:
	// ObjectKey
	map<wstring, CTexture*> m_mapTexture; 
	
};

