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
	//TODO: ���߿� �ε������� �ʵ� ����
	// list<Engine::Index*> list_Index;
	list<CSphereMesh*> list_TotalSphere; //Sphere ���� ��Ƴ��
	list<CSphereMesh*> list_Sphere;  //3���� �����Ұ� SphereLockOn �̸� 1��
	bool SphereLockOn = false;

};

