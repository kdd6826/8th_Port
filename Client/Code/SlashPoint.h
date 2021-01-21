#ifndef SlashPoint_h__
#define SlashPoint_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CRenderer;
class CTransform;
class CShader;
class CCollider;
class CTestTrail;
class CTrailBuffer;

END

BEGIN(Client)
class CSlashPoint : public Engine::CGameObject
{
private:
	explicit CSlashPoint(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSlashPoint(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	Engine::CTransform*			m_pTransformCom = nullptr;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTestTrail*				m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	Engine::CCollider*			m_pSwordColliderCom = nullptr;

	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;
public:
	static CSlashPoint*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	float fScale=0.f;
	virtual void Free(void) override;
	float reverseLifeTime = 0.f;;
};

END
#endif // SlashPoint_h__
