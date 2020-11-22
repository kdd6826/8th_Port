#pragma once
#include "GameObject.h"
#include "Engine_Define.h"

BEGIN(Engine)
class CTerrainTex;
class CTexture;
class CTransform;
END

class CTerrain : public Engine::CGameObject
{
public:
	explicit CTerrain(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTerrain();
public:
	HRESULT Ready();
	void	Render();
private:
	HRESULT SetUpMaterial();
private:
	Engine::CTerrainTex* m_pBufferCom = nullptr;
	Engine::CTexture* m_pTextureCom = nullptr;
	Engine::CTransform* m_pTransformCom = nullptr;
};

