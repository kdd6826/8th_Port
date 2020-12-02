#pragma once
#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"
BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;
class CCell;
END
class CSphereMesh;

class CTerrainTri : public Engine::CGameObject
{
private:
	explicit CTerrainTri(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTerrainTri(void);

public:
	virtual HRESULT Ready_Object(void) override;
	HRESULT			Ready_Object(_vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3);
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	// �ﰢ�� ��ġ �ٽ� �������ִ� �Լ� SphereMesh���� �̰� �ҷ����°Ŷ� ���� �ҷ����ʿ�X
	void Set_InitBuffer();
	// �ﰢ�� �����ϴ� �Լ�
	void DeleteWithSphere();
	//void Set_VtxPos();
private:
	HRESULT		Add_Component(_vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3);
	//void		SetUp_OnTerrain(void);
	//void		Key_Input(const _float& fTimeDelta);
	//_vec3		PickUp_OnTerrain(void);

public:
	Engine::CTerrainTriCol* m_pBufferCom = nullptr;
	Engine::CTexture* m_pTextureCom = nullptr;
	Engine::CTransform* m_pTransformCom = nullptr;
	Engine::CRenderer* m_pRendererCom = nullptr;
	Engine::CCalculator* m_pCalculatorCom = nullptr;
	Engine::CCell* m_Cell;
	list<CSphereMesh*> list_SphereMesh; // �ڱ⸦ �����ϴ� SphereMesh 3�� / ������
	bool m_Dead = false;
	int m_indexNumber = -1;
public:
	static CTerrainTri* Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 vtxPos1, _vec3 vtxPos2, _vec3 vtxPos3);
	//list<Engine::VTXCOL*> list_pVtx;
private:
	virtual void Free(void) override;

};