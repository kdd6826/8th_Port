#ifndef EndingScene_h__
#define EndingScene_h__

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
class CEndingScene : public Engine::CGameObject
{
private:
	explicit CEndingScene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CEndingScene(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	_bool GetEvent() { return isEvent; }
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CShader* m_pShaderCom = nullptr;
private:
	_matrix						m_matProj;
	_float						m_fX, m_fY;
	_float						m_fAlpha = 0.f;
	_float						m_fSizeX, m_fSizeY;
	_bool						isFadeIn = false;
	_bool						isEvent = false;
public:
	static CEndingScene*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

END
#endif // EndingScene_h__
