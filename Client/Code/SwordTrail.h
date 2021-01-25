#ifndef SwordTrail_h__
#define SwordTrail_h__

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
class CSwordTrail : public Engine::CGameObject
{
private:
	explicit CSwordTrail(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSwordTrail(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);

private:
	
	Engine::CTrailBuffer*			m_pBufferCom = nullptr;
	//Engine::CTestTrail*			m_pBufferCom = nullptr;
	Engine::CTexture*			m_pTextureCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	Engine::CCollider*			m_pSwordColliderCom = nullptr;

	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;
public:
	static CSwordTrail*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	list<pair<_vec3, _vec3>> m_pTrailList;
	//pair<_vec3, _vec3> m_pVecpair;
	float count=0;
	float count2 = 0;
private:
	virtual void Free(void) override;

};

END
#endif // SwordTrail_h__
