#pragma once

#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"

class SphereMesh;
class CSphereMesh;
class CSphereAndVtxManager
{
public:
	DECLARE_SINGLETON(CSphereAndVtxManager)
private:
	CSphereAndVtxManager();
	~CSphereAndVtxManager();

public:
	void Key_Input(float deltaTime);


private:
	

public:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

private:
	bool mouseLClick = false;
	bool mouseRClick = false;

	list<Engine::VTXCOL*> list_Vtx;
	//TODO: 나중에 인덱스버퍼 쪽도 저장
	// list<Engine::Index*> list_Index;
	list<CSphereMesh*> list_TotalSphere; //Sphere 전부 모아논곳
	list<CSphereMesh*> list_Sphere;  //3개씩 저장할곳 SphereLockOn 이면 1개
	bool SphereLockOn = false;

};

