#ifndef BossHpBarOrange_h__
#define BossHpBarOrange_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CRenderer;
class CTransform;

END

BEGIN(Client)
class CBossHpBarOrange : public Engine::CGameObject
{
private:
	explicit CBossHpBarOrange(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CBossHpBarOrange(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);

private:
	Engine::CRcTex*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;

private:
	_matrix						m_matProj;
	_float						m_fX, m_fY;
	_float						m_fSizeX, m_fSizeY;

public:
	static CBossHpBarOrange*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

END
#endif // BossHpBarOrange_h__
