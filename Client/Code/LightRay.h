#ifndef LightRay_h__
#define LightRay_h__

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
class CLightRay : public CMonster
{
private:
	explicit CLightRay(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLightRay(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	void SetDir(_vec3 dir) { m_vDir = dir; };
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	//Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	_float						lifeTime = 0.f;
	_float						m_fFrame = 0.f;
	_vec3						m_vDir = { 0.f,0.f,0.f };
public:
	static CLightRay*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	//vector<CSphereCollider*>	m_VecSphereCollider;
private:
	virtual void Free(void) override;

};

END
#endif // LightRay_h__
