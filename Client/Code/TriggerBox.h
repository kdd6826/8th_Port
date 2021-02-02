#ifndef TriggerBox_h__
#define TriggerBox_h__

#include "GameObject.h"
#include "Define.h"
#include "SphereCollider.h"
#include "ColliderMgr.h"
#include "Monster.h"
BEGIN(Engine)

class CRcTex;
class CTexture;
class CRenderer;
class CTransform;
class CShader;

END

BEGIN(Client)
class CTriggerBox : public CMonster
{
private:
	explicit CTriggerBox(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTriggerBox(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	void SetIsVisible() { isVisible = true; }
	_bool GetPortal() { return portal; }
	void SetPortal() { portal = true; }

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_bool						portal = false;
	_bool						isVisible = false;
	_float						m_fFrame = 0.f;
	_float						count = 0.f;
public:
	static CTriggerBox*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	//vector<CSphereCollider*>	m_VecSphereCollider;
private:
	virtual void Free(void) override;

};

END
#endif // TriggerBox_h__
