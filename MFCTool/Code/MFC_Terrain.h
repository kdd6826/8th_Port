#pragma once
#include "GameObject.h"
#include "Engine_Define.h"

BEGIN(Engine)
class CTerrainTex;
class CTexture;
class CTransform;
class CRenderer;
END

class CMFC_Terrain : public Engine::CGameObject
{
public:
	explicit CMFC_Terrain(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMFC_Terrain();
public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
private:
	HRESULT SetUpMaterial();
private:
	Engine::CTerrainTex*	m_pBufferCom = nullptr;
	Engine::CTexture*		m_pTextureCom = nullptr;
	Engine::CRenderer*		m_pRendererCom = nullptr;
	Engine::CTransform*		m_pTransformCom = nullptr;

public:
	static CMFC_Terrain* Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

