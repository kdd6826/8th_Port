#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class COptimization;
class CSphere;

END

class CMFCStone : public Engine::CGameObject
{
private:
	explicit CMFCStone(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMFCStone(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual Engine::_int Update_Object(const Engine::_float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);
	void		SetUp_OnTerrain(void);
	Engine::_bool		Collision_ToObject(const Engine::_tchar* pLayerTag, const Engine::_tchar* pObjTag);

private:

	Engine::CStaticMesh*		m_pMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CSphere*			m_pColSphereCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	Engine::COptimization*		m_pOptimizationCom = nullptr;
	Engine::_bool						m_bColl = false;
	Engine::_bool						m_bDraw = false;

public:
	static CMFCStone*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

