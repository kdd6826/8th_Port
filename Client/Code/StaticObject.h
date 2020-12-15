#ifndef StaticObject_h__
#define StaticObject_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class COptimization;

END

BEGIN(Client)
class CStaticObject : public Engine::CGameObject
{
private:
	explicit CStaticObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStaticObject(void);

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

private:

	Engine::CStaticMesh*		m_pMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	Engine::COptimization*		m_pOptimizationCom = nullptr;
	_bool						m_bColl = false;
	_bool						m_bDraw = false;

public:
	static CStaticObject*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CStaticObject* Create(LPDIRECT3DDEVICE9 pGraphicDev,wstring _wstring);
private:
	virtual void Free(void) override;

};

END
#endif // StaticObject_h__
