#pragma once


#include "GameObject.h"
#include "Engine_Define.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;

END

class CNaviMesh : public Engine::CGameObject
{
public:
	explicit CNaviMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CNaviMesh(void);

	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;

public:
	HRESULT		Add_Component(void);
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

	_vec3		PickUp_OnTerrain(void);
	HRESULT		SetUp_Material(void);
	static CNaviMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

