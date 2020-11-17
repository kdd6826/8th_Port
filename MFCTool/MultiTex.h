#pragma once
#include "Texture.h"
class CMultiTex final :
	public CTexture
{
public:
	explicit CMultiTex();
	virtual ~CMultiTex();
public:
	// CTexture을(를) 통해 상속됨
	virtual HRESULT Insert_Texture(const wstring & wstrFilePath, const wstring & wstrStateKey = L"", const DWORD & rCount = 0) override;
	virtual const TEXINFO * Get_Texture(const wstring & wstrStateKey = L"", const DWORD & rIndex = 0) override;
	virtual void Release_Texture() override;

private:
	// StateKey 
	// 하나의 STateKey(행동)에 여러개의 그림이 들어갈 수 있기 때문. 
	// 예를 들어 공격이란 StateKey 값에 20장의 그림을 넣고 
	//추후 인덱스를 빠르게 증가시켜 마치 애니메이션 돌아가듯 출력 할 것. 
	map<wstring, vector<TEXINFO*>> m_mapMultiTex; 
};

