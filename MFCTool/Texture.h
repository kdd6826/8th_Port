#pragma once
class CTexture abstract
{
public:
	explicit CTexture();
	virtual ~CTexture();
public:
	virtual HRESULT Insert_Texture(const wstring& wstrFilePath,
		const wstring& wstrStateKey = L"",
		const DWORD& rCount = 0)PURE;
	virtual const TEXINFO* Get_Texture(	const wstring& wstrStateKey = L"",
		const DWORD& rIndex = 0)PURE;
public:
	virtual void Release_Texture()PURE; 
};

