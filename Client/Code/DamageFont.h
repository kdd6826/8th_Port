#ifndef DamageFont_h__
#define DamageFont_h__

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
class CDamageFont : public Engine::CGameObject
{
private:
	explicit CDamageFont(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDamageFont(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	Engine::CTransform* GetTransform() { return m_pTransformCom; }
	float offsetX=0;
	int count = 0.f;
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
	float fScale;
	float	fAlpha=1.f;
public:
	static CDamageFont*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	CGameObject* m_pFontParent=nullptr;
private:
	virtual void Free(void) override;

};

END
#endif // DamageFont_h__
