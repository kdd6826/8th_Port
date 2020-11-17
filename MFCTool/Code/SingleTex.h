#pragma once
#include "Texture.h"
class CSingleTex final:
	public CTexture
{
public:
	explicit CSingleTex();
	virtual ~CSingleTex();

public:
	// CTexture을(를) 통해 상속됨
	virtual HRESULT Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey = L"", const DWORD & rCount = 0) override;
	// CTexture을(를) 통해 상속됨
	virtual const TEXINFO * Get_Texture(const wstring & wstrStateKey = L"", const DWORD & rIndex = 0) override;

	virtual void Release_Texture();
private:
	TEXINFO* m_pTexInfo; 



};

