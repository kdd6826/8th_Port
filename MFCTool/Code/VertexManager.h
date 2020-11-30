#pragma once

#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"

class SphereMesh;
class CSphereMesh;

class VertexManager
{
public:
	DECLARE_SINGLETON(VertexManager)
private:
	VertexManager();
	~VertexManager();

public:
	void Update(float deltaTime);
	void Key_Input(float deltaTime);
	void DrawLine();
	CSphereMesh* Picking_Sphere(HWND hWnd, Engine::CTransform* pTerrainTransformCom);

	void Set_VtxColor(Engine::CSphere* Vtx, D3DCOLOR color);

	bool TerrainHaveCheck();
	void MouseLClick_NaviMesh();

private:
	

public:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

private:
	bool mouseLClick = false;
	bool mouseRClick = false;
	bool KeyC = false;

	//list<Engine::VTXCOL*> list_Vtx;
	//TODO: 나중에 인덱스버퍼 쪽도 저장
	// list<Engine::Index*> list_Index;
	list<CSphereMesh*> list_TotalSphere; //Sphere 전부 모아논곳
	list<CSphereMesh*> list_Sphere;  //3개씩 저장할곳 SphereLockOn 이면 1개
	bool sphereLockOn = false;
	bool sphereOverlap = false;

	D3DXVECTOR3 vertex[128];
	LPD3DXLINE line[128];
	int triCount = 0;
	int lineCount = 0;
};

