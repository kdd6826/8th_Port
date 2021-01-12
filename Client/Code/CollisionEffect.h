#ifndef CollisionEffect_h__
#define CollisionEffect_h__

#include "GameObject.h"
#include "Define.h"
#include "SphereCollider.h"
BEGIN(Engine)

class CTransform;


END

BEGIN(Client)
class CCollisionEffect : public Engine::CGameObject
{
private:
	explicit CCollisionEffect(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CCollisionEffect(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	Engine::CTransform*			m_pTransformCom = nullptr;

public:
	static CCollisionEffect*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	vector<CSphereCollider*>	m_VecSphereCollider;
private:
	virtual void Free(void) override;

};

END
#endif // CollisionEffect_h__
