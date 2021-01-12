#ifndef Sword_h__
#define Sword_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CColliderSphere;
class CShader;
class CTexture;
END

BEGIN(Client)
class CSword : public Engine::CGameObject
{
private:
	explicit CSword(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSword(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
private:
	HRESULT		Add_Component(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);

private:
	//Engine::CTexture* m_pTextureCom = nullptr;
	//Engine::CTexture* m_pTextureCom2 = nullptr;
	Engine::CStaticMesh*		m_pMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider* m_pColliderCom = nullptr;
	//Engine::CColliderSphere*			m_pColliderCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;

	_bool						m_bColl = false;

	const	_matrix*			m_pParentBoneMatrix = nullptr;
	const	_matrix*			m_pParentWorldMatrix = nullptr;

public:
	static CSword*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void) override;

private:

};

END
#endif // Sword_h__
