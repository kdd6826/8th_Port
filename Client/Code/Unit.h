#ifndef Unit_h__
#define Unit_h__

#include "GameObject.h"
#include "Define.h"
#include "SphereCollider.h"
#include "SoundManager.h"
//#include "ColliderMgr.h"
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
	enum StageNum
	{
		STAGE0,
		STAGE1,
		STAGE2,
		STAGE3
	};
	CUnit(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CUnit(void);
	virtual _int Update_Object(const _float& fTimeDelta);
	void SetSpawnPosition(_vec3 _pos) { spawnPosition =_pos; }
	void SetStageNum(StageNum _stage) { stageNum = _stage; }
	Engine::CDynamicMesh* m_pMeshCom = nullptr;
	Engine::CNaviMesh* m_pNaviMeshCom = nullptr;
	Engine::CTransform* m_pTransformCom = nullptr;
	Engine::CRenderer* m_pRendererCom = nullptr;
	Engine::CCalculator* m_pCalculatorCom = nullptr;
	Engine::CCollider* m_pColliderCom = nullptr;
	Engine::CShader* m_pShaderCom = nullptr;
	void NaviMeshChange(const _tchar* pFileKey);
private:

protected:
	bool Updateinitialize = false;
	HRESULT		Add_Component(void);
	_int Load_ColliderFile(_tchar* pFilePath, Engine::COLLID _collType, Engine::COLLID _collType2);
	HRESULT ColliderObject();
	HRESULT ColliderSkill();

	StageNum stageNum = STAGE0;
	vector<CSphereCollider*>	m_VecSphereCollider;
	_float						reverseDelay = 0.f;
	_bool isInvincible = false;
	_bool isAnimating = false;
	_bool isDie=false;
	_vec3 spawnPosition = {0.f,0.f,0.f};
	virtual void Free(void) override;

};

END
#endif // Unit_h__
