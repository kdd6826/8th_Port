#ifndef MFCDynamicMesh_h__
#define MFCDynamicMesh_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;

END

class CMFCDynamicMesh : public Engine::CGameObject
{
private:
	explicit CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);
	virtual ~CMFCDynamicMesh(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual HRESULT Ready_Object(CString _mesh);
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	bool isDead = false;
private:
	HRESULT		Add_Component(void);
	HRESULT		Add_Component(CString _mesh);
	void		SetUp_OnTerrain(void);
	void		Key_Input(const _float& fTimeDelta);
	_vec3		PickUp_OnTerrain(void);

private:
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CNaviMesh*			m_pNaviMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	_vec3						m_vDir;
	_float						m_fSpeed = 5.f;

public:
	static CMFCDynamicMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CMFCDynamicMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);

private:
	virtual void Free(void) override;

};

#endif // MFCDynamicMesh_h__
