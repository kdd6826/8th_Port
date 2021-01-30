#ifndef TreeObject_h__
#define TreeObject_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
//class COptimization;
class CShader;

END

BEGIN(Client)
class CTreeObject : public Engine::CGameObject
{
private:
	explicit CTreeObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTreeObject(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual HRESULT Ready_Object(wstring _wstring);
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);
	HRESULT		Add_Component(wstring _wstring);
	void		SetUp_OnTerrain(void);
	_bool		Collision_ToObject(const _tchar* pLayerTag, const _tchar* pObjTag);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
private:

	Engine::CStaticMesh*		m_pMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	//Engine::COptimization*		m_pOptimizationCom = nullptr;
	Engine::CShader*			m_pShaderCom = nullptr;
	_bool						m_bColl = false;
	_bool						m_bDraw = false;

public:
	static CTreeObject*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CTreeObject* Create(LPDIRECT3DDEVICE9 pGraphicDev,wstring _wstring);
private:
	virtual void Free(void) override;

};

END
#endif // TreeObject_h__
