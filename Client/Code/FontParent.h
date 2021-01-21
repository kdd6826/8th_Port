#ifndef FontParent_h__
#define FontParent_h__

#include "GameObject.h"
#include "Define.h"


BEGIN(Engine)

class CRcTex;
class CTexture;
class CRenderer;
class CTransform;
class CShader;

END

BEGIN(Client)
class CFontParent : public Engine::CGameObject
{
	/*class CDamageFont;*/
private:
	explicit CFontParent(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CFontParent(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	Engine::CTransform* GetTransform() { return m_pTransformCom; }
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	float reverseLifeTime = 0.f;;
	_float						m_fFrame = 0.f;
	int count = 0.f;
	float fScale;
	float	fAlpha=1.f;
public:
	static CFontParent*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

	vector<CGameObject*>	m_vecDamageFont;
private:
	virtual void Free(void) override;

};

END
#endif // FontParent_h__
