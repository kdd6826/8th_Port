#pragma once
#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"
#include "Unit.h"
BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;

END
class CTerrainTri;
class CSphereCollider : public Engine::CGameObject
{
private:
	explicit CSphereCollider(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CSphereCollider(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual Engine::_int Update_Object(const Engine::_float& fTimeDelta) override;
	virtual void Render_Object(void) override;

private:
	HRESULT		Add_Component(void);
	//void		SetUp_OnTerrain(void);
	//void		Key_Input(const _float& fTimeDelta);
	//_vec3		PickUp_OnTerrain(void);
	virtual void  OnCollision();
public:
#ifdef _DEBUG
	/*Engine::CCollSphere* m_pBufferCom = nullptr;
	Engine::CRenderer* m_pRendererCom = nullptr;
	Engine::CCalculator* m_pCalculatorCom = nullptr;*/
#endif
	Engine::CTransform* m_pTransformCom = nullptr;

public:
	static CSphereCollider* Create(LPDIRECT3DDEVICE9 pGraphicDev);
	//list<Engine::VTXCOL*> list_pVtx;
	bool m_Dead = false;
	//자기자신
	Engine::CGameObject* m_pDynamicMesh;
	_bool						m_bColl = false;
	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;
	string m_FrameName;
	bool m_FrameNameCheck = false;
private:
	virtual void Free(void) override;

};