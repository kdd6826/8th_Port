#ifndef DashGuard2_h__
#define DashGuard2_h__

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
class CDashGuard2 : public CMonster
{
private:
	explicit CDashGuard2(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDashGuard2(void);

public:
	enum guardDir
	{
		DIR_DEFAULT,
		DIR_FRONT,
		DIR_LEFT,
		DIR_RIGHT
	};
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	void InitialLifetime(_float _time) { lifeTime = _time; }
	void SetGuardDir(guardDir _dir) { m_guardDir = _dir; }
	void SetDash() { isDash = true; }
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
	guardDir					m_guardDir = DIR_DEFAULT;
	_bool						isDash = false;
	_float						m_fAlpha = 0.f;
	_float						lifeTime = 0.f;
	_float						m_fFrame = 0.f;
	_vec3						m_vDir = { 0.f,0.f,0.f };
	_float						m_fScale = 0.f;
public:
	static CDashGuard2*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	//vector<CSphereCollider*>	m_VecSphereCollider;
private:
	virtual void Free(void) override;

};

END
#endif // DashGuard2_h__
