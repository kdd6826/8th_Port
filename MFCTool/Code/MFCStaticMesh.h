#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CStaticMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class COptimization;
class CObjSphere;

END

class CMFCStaticMesh : public Engine::CGameObject
{
private:
	explicit CMFCStaticMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CMFCStaticMesh(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);
	virtual ~CMFCStaticMesh(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual HRESULT Ready_Object(CString _mesh);
	virtual Engine::_int Update_Object(const Engine::_float& fTimeDelta) override;
	virtual void Render_Object(void) override;

	Engine::CTransform* GetTransform() { return m_pTransformCom; }
	bool isDead = false;
private:
	HRESULT		Add_Component(void);
	HRESULT		Add_Component(CString _mesh);
	void		SetUp_OnTerrain(void);
	Engine::_bool		Collision_ToObject(const Engine::_tchar* pLayerTag, const Engine::_tchar* pObjTag);
	
private:

	Engine::CStaticMesh*		m_pMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CObjSphere*			m_pColSphereCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	Engine::COptimization*		m_pOptimizationCom = nullptr;
	Engine::_bool						m_bColl = false;
	Engine::_bool						m_bDraw = false;

public:
	static CMFCStaticMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CMFCStaticMesh* Create(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);
	

private:
	virtual void Free(void) override;

};

