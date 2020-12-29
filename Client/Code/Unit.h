#ifndef Unit_h__
#define Unit_h__

#include "GameObject.h"
#include "Define.h"
#include "SphereCollider.h"
BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;
class CShader;

END
class CSphereCollider;
BEGIN(Client)
class CUnit : public Engine::CGameObject
{
public:
	CUnit(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CUnit(void);
	virtual _int Update_Object(const _float& fTimeDelta);
	Engine::CDynamicMesh* m_pMeshCom = nullptr;
	Engine::CNaviMesh* m_pNaviMeshCom = nullptr;
	Engine::CTransform* m_pTransformCom = nullptr;
	Engine::CRenderer* m_pRendererCom = nullptr;
	Engine::CCalculator* m_pCalculatorCom = nullptr;
	Engine::CCollider* m_pColliderCom = nullptr;
	Engine::CShader* m_pShaderCom = nullptr;

private:

protected:
	HRESULT		Add_Component(void);
	_int Load_ColliderFile(_tchar* pFilePath, Engine::COLLID _collType);



	vector<CSphereCollider*>	m_VecSphereCollider;
	_bool isSearch = false;
	_bool isAnimating = false;
	_bool isDie=false;

	virtual void Free(void) override;

};

END
#endif // Unit_h__
