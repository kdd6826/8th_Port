#pragma once
#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"
BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;

END

class CSphereMesh : public Engine::CGameObject
{
private:
	explicit CSphereMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSphereMesh(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	void Set_VtxPos();
private:
	HRESULT		Add_Component(void);
	//void		SetUp_OnTerrain(void);
	//void		Key_Input(const _float& fTimeDelta);
	//_vec3		PickUp_OnTerrain(void);

private:
	Engine::CSphere* m_pBufferCom = nullptr;
	Engine::CTexture* m_pTextureCom = nullptr;
	Engine::CTransform* m_pTransformCom = nullptr;
	Engine::CRenderer* m_pRendererCom = nullptr;
	Engine::CCalculator* m_pCalculatorCom = nullptr;

public:
	static CSphereMesh* Create(LPDIRECT3DDEVICE9 pGraphicDev);
	list<Engine::VTXCOL*> list_pVtx;
private:
	virtual void Free(void) override;

};