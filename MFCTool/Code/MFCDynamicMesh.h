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

class CSphereCollider;

class CMFCDynamicMesh : public Engine::CGameObject
{
private:
	explicit CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CMFCDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);
	virtual ~CMFCDynamicMesh(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual HRESULT Ready_Object(CString _mesh);
	//뼈이름으로 인자를 받아서 그 뼈한테 원 콜라이더 생성
	Engine::CTransform* GetTransform() { return m_pTransformCom; }
	void			Create_BoneOfSphereCollier(CString boneName);
	void Load_BoneOfSphereCollier(_vec3 pos, _vec3 scale, CString boneName);
	void			Ready_VecFrameNameGet(Engine::D3DXFRAME_DERIVED* pFrame, const _matrix* pParentMatrix);
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	//해당 뼈 이름에 부착되어있는 CSPhereCollider* 반환
	CSphereCollider* Find_SphereCollider(string boneName);
	void Delete_SphereCollider(string boneName);
	void Delete_All_SphereCollider();
	bool isDead = false;
private:
	HRESULT		Add_Component(void);
	HRESULT		Add_Component(CString _mesh);
	void		SetUp_OnTerrain(void);
	void		Key_Input(const _float& fTimeDelta);
	_vec3		PickUp_OnTerrain(void);

public:
	_float currentFrame=0.f;
	_float endFrame=0.f;
	Engine::CDynamicMesh*		m_pMeshCom = nullptr;
	Engine::CNaviMesh*			m_pNaviMeshCom = nullptr;
	Engine::CTransform*			m_pTransformCom = nullptr;
	Engine::CRenderer*			m_pRendererCom = nullptr;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	Engine::CCollider*			m_pColliderCom = nullptr;
	_vec3						m_vDir;
	_float						m_fSpeed = 5.f;
	_bool						isColliderSample = false;
public:
	vector<CSphereCollider*>		m_VecSphereCollider;
	vector<LPSTR>					m_VecFrameName;
	CString							meshKey;
	int								m_AniClip;
public:
	static CMFCDynamicMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CMFCDynamicMesh*	Create(LPDIRECT3DDEVICE9 pGraphicDev,CString _mesh);

private:
	virtual void Free(void) override;

};

#endif // MFCDynamicMesh_h__
